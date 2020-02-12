# PID BOX
### By Julia and Mekhi

<General description of box with photos>
  
## Initial Planning
  
## Schedule
  

|   _Week_   |   _Goal_   |
|------------|------------|
| 11/18-11/22| Make schedule and CAD/code foundation |
| 11/25-11/26 | Make RPM code |
| 12/2-12/6 | Make 3D printed parts in CAD and PID Code|
| 12/9-12/13 | Finish CAD model and RGB code |
| 12/16 | Finalize Code, 3D print motor brackets, and laser cut sides |
| 1/6-1/10 | Assemble box |
| 1/13-1/16 | Add code, test, fix errors, repeat |
| 1/20-1/24 | Add code, test, fix errors, repeat |
| 1/27-1/31 | Add code, test, fix errors, repeat |
| 2/3-2/7 | Finish |

## Materials

* Acrylic
* Screws and nuts
* 3D printer
* Arduino Uno
* Breadboard
* Wires
* 6 AA batteries in battery case
* Solder and soldering iron
* DC Motor
* Photointerrupter
* LCD and backpack
* Toggle switch
* LED
* Potentiometer
* RGB LED
* Standoffs
* Washers


## Steps

* Come up with a rough plan and schedule 
* Design PID box in SolidWorks
* 3D print motor bracket
* Laser cut the sides and wheel
* Assemble box
* Wire box
* Write and upload code
* Test and perfect code
* Done!

  
## SolidWorks
  
<img src="https://lh5.googleusercontent.com/ko0ZzaRYsS60VzwcvmtYZz1dXzhi-cIChcwIn0WKOV0cGjvbj3YQOMQHjthIiS7hbEAcT2NGltuHlE3ObMgwg97l15nNKyLE6es6TlB_K2YmE9SA3uLjlSfl_dfC-FZGfTp83MRJ" alt="Isometric veiw of CAD" title="Peekaboo" width="300"/><img src="https://lh6.googleusercontent.com/nQ7kFiQPmNRSYxxomFNr3HzKWKpsSvVCGUgyPqlVAUktzVPIog4caLucMWMDJ2j6EJiOsI0e74UKFjdP-GgyBjGPkODNrYW9B6mN_Yol" alt="View of inside of CAD" title="HIIIIIIII" width="300"/>

## Code
  
## Wiring

<img src="https://lh5.googleusercontent.com/IIBsLStzbg81R4Nhm8Dx_YUrik1Uw3OV_AYxHcGhAlzaQN6azOS1izGOGvhrzifY95M6FRzwSaDeTrLZzHHyV-e7oSutYBQ6xdbmlON8SHnvucaAOn-GON9R0ge9R_8PIV4c0znC" alt="Fritzing Diagram"
	title="A cute kitten" width="500"/>
 
## Noteable Components
* RGB LED
  * We thought it would be fun the try our hand at something neither of us had used before. While fairly straightforward, the LED adds an interesting visual to our project. It turns red when the wheel is slower and fades to green as the wheel speeds up. 
* Motor Bracket
  * The motor bracket, inspired by the motor brackets used by the BACON FTC team, consists of two halves, which clamp the motor between them using screws. This allows for a better grip on the motor, which is essential for a more stable wheel. 
* Battery Mount
  * We wanted the battery case to mainly sit inside the box, with only the front sticking out. We drilled two holes in the top of the case so we could screw it to the wall. To prevent it from being pushed inwards on the bottom, we added two groves to the hole in the acrylic that fit the groves on the battery case.

## Encountered Issues

* Wobbly wheel
  * Problem - The wheel was wobbling so much that it was unable to turn in the slot.
  * Solution - We recut the slot in the acrylic to be wider and worked on adjusting the wheel so it would spin more fluidly.
* LCD
  * Problem - The LCD had trouble staying on. It would flicker and dim when any tension was put on it.
  * Solution - At first we thought it had something to do with the LCD backpack, but the problem persisted even after we replaced it. We replaced it again, and this time we replaced the LCD too, which seemed to work.
* Number of data points per rotation
  * Problem - When we originally designed the wheel, we only had one hole it it. This meant we could only get one reading per rotation and that it took two whole rotations to get any output. For a project that needs to be constantly outputting and updating data, that’s a pretty serious flaw.
  * Solution - We did a quick circular pattern and walk over to the laser cutter, and boom a wheel with 6 holes. The most time consuming part of this process was just attaching the wheel. We had to unwire the motor and photointerruper as well as take off an entire side of the box to get it on.


  
 
