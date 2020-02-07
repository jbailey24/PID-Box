# include <Wire.h>
# include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD Backpack.ino

volatile int output = 0;
int targetspd = 0;
bool juston = 0;

const int potentiometer = A1;
const int pinterrupter = 3; //photo interrupter
const int motorpin = 6; // motor
const int wheeled = 13;

const int holenum = 6;
const int calcps = 3;
int wt = 1000 / calcps;

int rpmval1 = 0;
int rpmval2 = 0;
int rpmval3 = 0;
int realrpm = 0; // this is the PV, the process variable. Process variable is another name for the actual value of a variable.

long oldmillis = 0;
int test = 0;


const int maxrpmval = 1500;

const int red = 9;
const int green = 10;
const int blue = 11;

int error = 0;
int previous_error = 0;

int integral = 0;
int derivative = 0;
int drive = 0;

double kP = 1.4;
double kI = 0.004;
double kD = 100;


void setup()
{
  Serial.begin(9600);

  pinMode(pinterrupter, INPUT_PULLUP);
  pinMode(4, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinterrupter), RPMCalc, RISING);
  pinMode(wheeled, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.begin (16, 2); // for 16 x 2 LCD module]
  lcd.setCursor(0,0);
  lcd.print("Julia Bailey");
  lcd.setCursor(0,1);
  lcd.print(" Mekhi Hernandez");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("True Speed:      ");
  lcd.setCursor(0, 1);
  lcd.print("Set Speed:       ");
}


void loop()
{

  if (millis() >= oldmillis * wt)
  {
    detachInterrupt(digitalPinToInterrupt(pinterrupter)); //detach the interruptss

    targetspd = analogRead(potentiometer);

    // rpmval3 = rpmval2;
    // rpmval2 = rpmval1;
    // rpmval1 = output;
    realrpm = (output) * (60 * calcps) / holenum;

    lcd.setCursor(12, 0);
    lcd.print(realrpm);
    lcd.print("   ");
    lcd.setCursor(11, 1);
    lcd.print(map(analogRead(potentiometer), 0, 1023, 0, maxrpmval));
    lcd.print("   ");
    if (realrpm <= 5000 && targetspd <= 5000) {
      Serial.print(realrpm);
      Serial.print(",");
      Serial.println(map(analogRead(potentiometer), 0, 1023, 0, maxrpmval));
    }
    output = 0; //resets the output value so that we can calculate the next rpm

    if (digitalRead(4) == 1)
    {
      juston = false;
      drive = 0;
    }


    if (digitalRead(4) == 0)
    {

      if (juston == false)
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
    analogWrite(motorpin, constrain((map(targetspd, 0, 1023, 0, 150) + drive), 0, 255));
    oldmillis = oldmillis + (1);
    attachInterrupt(digitalPinToInterrupt(pinterrupter), RPMCalc, RISING);
  }


  analogWrite(red, (150-(map(constrain(realrpm, 0, 1500), 0, maxrpmval, 0, 150)))); // if rpm is zero, light is green; if rpm is maxed, no green
  analogWrite(green, map(constrain(realrpm, 0, 1500), 0, maxrpmval, 0, 150));


}

void RPMCalc() // the code to count the number of times the wheel has passed the photo interrupter
{

  output ++;
  digitalWrite(wheeled, HIGH);
  delay(1);
  digitalWrite(wheeled, LOW);
}
