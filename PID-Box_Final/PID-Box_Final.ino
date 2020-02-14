# include <Wire.h>
# include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD Backpack.ino

volatile int output = 0; //an integer increased in the interrupt
int targetspd = 0; //the set speed of the motor; going to be changed based off of potentiometer value
bool juston = 0; // used for PID initiation sequence timings

const int potentiometer = A1; //the potentiometer pin
const int pinterrupter = 3; //photo interrupter
const int motorpin = 6; // motor
const int wheeled = 13;// LED pin which triggers in the interrupt

const int holenum = 6; // number of holes in the wheel
const int calcps = 3; // how many times the RPM and PID are being calculated in a second
int wt = 1000 / calcps; // wait time; used in PID calculations

int realrpm = 0; // this is the PV, the process variable. Process variable is another name for the actual value of a variable.

long oldmillis = 0; //used for timing instead of delays

const int maxrpmval = 1500;//the supposed max rpm value

const int red = 9;// the three RGB LED pins
const int green = 10;
const int blue = 11;

int error = 0; // both used for Proportional calculations
int previous_error = 0;

int integral = 0; //PID variables
int derivative = 0;
int drive = 0;

double kP = 1.4; //PID tuning variables; note: kI is small because it is divided by 333 for wait time, kD is large because it is multiplied by 333
double kI = 0.004;
double kD = 100;


void setup()
{
  Serial.begin(9600);

  pinMode(pinterrupter, INPUT_PULLUP); //setup for photointerrupter
  pinMode(4, INPUT); //setup for the PID switch
  attachInterrupt(digitalPinToInterrupt(pinterrupter), RPMCalc, RISING);
  pinMode(wheeled, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.begin (16, 2); // for 16 x 2 LCD module]
  lcd.setCursor(0, 0);
  lcd.print("Julia Bailey");
  lcd.setCursor(0, 1);
  lcd.print(" Mekhi Hernandez");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("True Speed:      ");
  lcd.setCursor(0, 1);
  lcd.print("Set Speed:       ");
}


void loop()
{

  if (millis() >= oldmillis * wt) //if a certain number(333 currently) of milliseconds have passed since last activation, run this code
  {
    detachInterrupt(digitalPinToInterrupt(pinterrupter)); //detach the interruptss

    targetspd = analogRead(potentiometer);

    realrpm = (output) * (60 * calcps) / holenum; //the RPM is equal to the number of times the photo interrupter has been triggered, times 30. This number is the number of seconds, times the calculations per second, divided by the number of holes

    lcd.setCursor(12, 0); //these 6 lines print the RPM and the set speed
    lcd.print(realrpm);
    lcd.print("   ");
    lcd.setCursor(11, 1);
    lcd.print(map(analogRead(potentiometer), 0, 1023, 0, maxrpmval));
    lcd.print("   ");


    Serial.print(constrain(realrpm, 0, maxrpmval + 1000)); //print the real rpm and the set speed to the serial monitor for graphing
    Serial.print(",");
    Serial.println(map(analogRead(potentiometer), 0, 1023, 0, maxrpmval));

    output = 0; //resets the output value so that we can calculate the next rpm

    if (digitalRead(4) == 1) // if the PID is off, set the adjustment value to 0
    {
      juston = false;
      drive = 0;
    }


    if (digitalRead(4) == 0)
    {

      if (juston == false) //If PID switch is on and it previously wasn't, start initialization sequence
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PID is on"); //start with this message then wait a second and move to the usual message
        delay(1000);
        lcd.setCursor(0, 0);
        lcd.print("True Speed:      ");
        lcd.setCursor(0, 1);
        lcd.print("Set Speed:       ");
      }

      error = map(targetspd, 0, 1023, 0, 150) - map(realrpm, 0, maxrpmval, 0, 150);//set the error equal to the targetspeed (as a motor usable value) minus the actual rpm mapped as a motor usable value
      integral = integral + (error * wt); // integral is set to the previous integral plus the error
      derivative = (error - previous_error) / wt; // the derivative is the error minus the previous error divided by the amount of time in which it gets calculated
      drive = (error * kP) + (integral * kI) + (derivative * kD); // all of the different adjusting mechanisms are combined
      previous_error = error;

      juston = true;
    }
    analogWrite(motorpin, constrain((map(targetspd, 0, 1023, 0, 150) + drive), 0, 255)); //write to the motor the potentiometer value plus PID stuff
    oldmillis = oldmillis + (1);
    attachInterrupt(digitalPinToInterrupt(pinterrupter), RPMCalc, RISING);
  }


  analogWrite(red, (150 - (map(constrain(realrpm, 0, 1500), 0, maxrpmval, 0, 150)))); // if rpm is zero, light is green; if rpm is maxed, no green
  analogWrite(green, map(constrain(realrpm, 0, 1500), 0, maxrpmval, 0, 150));// print to the green part of the RGBLED the speed of the motor


}

void RPMCalc() // the code to count the number of times the wheel has passed the photo interrupter and to switch the led on momentarily
{

  output ++;
  digitalWrite(wheeled, HIGH);
  delay(1);
  digitalWrite(wheeled, LOW);
}
