# PID BOX
### By Julia and Mekhi

<General description of box with photos>
	
<img src="https://lh4.googleusercontent.com/gDNd8Uj2McP20h7n0FmXF1Jae3AAxSxt0gf9NqAtlsq5hXcMqK8Dyw1Shi411xebMMFmEU4zaIeBZ1U2KNmwBney4gEWtoRwQ55IGOcduBfPTk9QjD4M_q20I7u6qXjS7PBoHkfW" alt="Isometric view of box" width="290" /><img src="https://lh6.googleusercontent.com/PQClWiQvRrxgx5BHZCClSvPoExAJhqsbDhGFwCgj2b2Ya9UvBj7xvgEiXWWRNBsDAs6vtYMTez5CO152USk24UpD6eG430XHX1BEeFfnOIdFGkzQjGppcXdNeMVFZV8PYDWmMJXP" alt="PID box side view" width="290"/><img src="https://lh3.googleusercontent.com/UR5WCdrqodOnzkZJy-jg-YqGKLcGFy8hQntHNdq0dgSDRwIcCVzXFZQ6qcKHicticSQ4naidrd77ynHQaxT9Pf3cD9iMZ8GWH6GbCQfHFCRk8S8MdmzBzsTxfn6bLnNd1uNd5PVH" alt="PID box running" width="290"/>



  
## Initial Planning
 
<img src="https://lh3.googleusercontent.com/SLg_KaX7GMfZ3DgxHvSeXM7V1ZLy65XAEDrLOYFUcGWuOvYyesOBaRBfgmpVPb3aS0lDhASPck9iT1I744Z9b6UUJ3m3Ezh9x3Xl8aAo7pGeqRN9bHbzDUedd4AGd0nbuO10POkV" alt="Digital sketch" width="400"/><img src="https://lh4.googleusercontent.com/npHgFCw1L05GnVFdic3DeSmy4hk62jzOa5bGj_xyJ5jBABTR6TltoCR9qVLn4V4MHVzhf682pFS12IlCjpcujiPuXVH6yCV5tgXLinCIHQv2OJkN7uu_Ob14TECh0DnLoBeUXE8v" alt="Sketch" width="200"/>
 
 
The first thing we did when confronted by this new project, is pull out pencils and paper (well, also iPad and stylus). While our initial sketches stayed fairly close to our final product, there were a few major differences, the most notable of which being the shape change. We found that in the end that having it be a cube was better for optimizing space usage. Another thing we changed was the position of the photointerrupter. Originally we had it level with the motor, but because of the shape change, we placed it below the motor in the final design.

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

  
## CAD
  
<img src="https://lh5.googleusercontent.com/ko0ZzaRYsS60VzwcvmtYZz1dXzhi-cIChcwIn0WKOV0cGjvbj3YQOMQHjthIiS7hbEAcT2NGltuHlE3ObMgwg97l15nNKyLE6es6TlB_K2YmE9SA3uLjlSfl_dfC-FZGfTp83MRJ" alt="Isometric view of CAD" width="300"/> <img src="https://lh6.googleusercontent.com/nQ7kFiQPmNRSYxxomFNr3HzKWKpsSvVCGUgyPqlVAUktzVPIog4caLucMWMDJ2j6EJiOsI0e74UKFjdP-GgyBjGPkODNrYW9B6mN_Yol" alt="View of inside of CAD" width="300"/>

For this project, we used SolidWorks as our CAD platform. Making a full digital version of our box really helped lay out how we wanted our box to fit together, before wasting any materials. Because we weren't sure of the exact dimensions of the sides, we assigned equations to the box which made it possible to change the sizes of the walls without convoluting any of the other features. This proved very useful, as we changed the dimensions several times before settling on one that worked. In the end, we found that a perfect cube accommodated the different parts most efficiently. 

## Code
  
###### [Link to Code](https://github.com/jbailey24/PID-Box/blob/master/PID-Box_Final/PID-Box_Final.ino)
## Wiring

###### [Link to Fritzing](https://github.com/jbailey24/PID-Box/blob/master/PID_Fritzing.fzz)
<img src="https://lh5.googleusercontent.com/IIBsLStzbg81R4Nhm8Dx_YUrik1Uw3OV_AYxHcGhAlzaQN6azOS1izGOGvhrzifY95M6FRzwSaDeTrLZzHHyV-e7oSutYBQ6xdbmlON8SHnvucaAOn-GON9R0ge9R_8PIV4c0znC" alt="Fritzing Diagram" width="500"/>
 
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


  
 
