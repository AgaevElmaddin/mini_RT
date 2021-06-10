# miniRT
The goal of this project is to generate images using the Raytracing protocol. Those computer generated images will each represent a scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system.

Allowed built-in functions: **open**, **close**, **read**, **write**, **malloc**, **free**, **perror**, **strerror**, **exit**. **All the functions of the math library**. **All the functions of the MinilibX**.

The task is to implement 5 geometric objects: a plane, a sphere, a cylinder, a square and a triangle.

## How it looks

https://user-images.githubusercontent.com/84783740/121492654-b8305f80-c9df-11eb-9d76-b98dbfa573ef.mov

https://user-images.githubusercontent.com/84783740/120610889-4cd51380-c45c-11eb-9071-fb002979db26.mov

https://user-images.githubusercontent.com/84783740/120638622-0641e200-c479-11eb-822e-3c295823d912.mp4

https://user-images.githubusercontent.com/84783740/120640334-08a53b80-c47b-11eb-9743-341299564727.mp4


## About .rt file

<table>
  <tr>
    <td align="center">Example of .rt file</td>
    <td align="center">Notation</td>
    <td align="center">Parameters</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/84783740/120661441-f1714880-c490-11eb-85df-ebe3dd03dcdb.png"></td>
    <td>R - Resolution<br>A - Ambient<br>c - camera<br>l - light<br>pl - plane</td>
    <td>450 - width 450 - height<br>0.1 - intensity 255,255,0 - r,g,b<br>0,0,0 - x,y,z coordinates of the view point
        0,0,1 - 3d normalized orientation vector 90 - FOV<br>0,1,7 - x,y,z coordinates of the light point 
        0.6 - brightness, 255,255,255 - r,g,b<br>0,2,0 - x,y,z coordinates 0,1,0 - 3d normalized orientation vector 
        0,0,255 - r,g,b</td>
  </tr>
</table>

**.rt file has a specific structure:**

1) Resolution and ambient light can only be declared once in the scene.
2) Each element first's information is the type identifier (composed by one or two character(s)), followed by all specific information for each object in a strict order such as:

**Resolution** <br>
*Notation: R* <br>
*Screen width: integer between 1 and the limit of your screen resolution*<br>
*Screen height: integer between 1 and the limit of your screen resolution*<br>

**Ambient**<br>
*Notation: A*<br/>
*Intensity: double between 0.0 and 1.0*<br/>
*R,G,B colours: 3 integers between 0 and 255*<br/>

**Camera**<br>
*Notation: c*<br>
*View point: 3 doubles representing x,y,z coordinates*<br>
*3d normalized orientation vector: three doubles between -1.0 and 1.0*<br>
*FOV(horizontal field of view): integer between 0 and 180*<br>

**Light**<br>
*Notation: l*<br>
*Position: 3 doubles representing x,y,z coordinates*<br>
*Brightness: double between 0.0 and 1.0*<br>
*R,G,B colours: 3 integers between 0 and 255*<br>

**Sphere**<br>
*Notation: sp*<br>
*Center: 3 doubles representing x,y,z coordinates*<br>
*Diameter: double larger than 0.0*<br>
*R,G,B colours: 3 integers between 0 and 255*<br>

**Plane**<br>
*Notation: pl*<br>
*Origin point: 3 doubles representing x,y,z coordinates*<br>
*3d normalized orientation vector: three doubles between -1.0 and 1.0*<br>
*R,G,B colours: 3 integers between 0 and 255*<br>

**Square**<br>
*Notation: sq*<br>
*Center: 3 doubles representing x,y,z coordinates*<br>
*3d normalized orientation vector: three doubles between -1.0 and 1.0*<br>
*Side: double larger than 0.0*<br>
8R,G,B colours: 3 integers between 0 and 255*<br>

**Cylinder**<br>
*Notation: cy*<br>
*Center: 3 doubles representing x,y,z coordinates*<br>
*3d normalized orientation vector: three doubles between -1.0 and 1.0*<br>
*Diameter: double larger than 0.0*<br>
*Height: double larger than 0.0*<br>
*R,G,B colours: 3 integers between 0 and 255*<br>

**Triangle**<br>
*Notation: tr*<br>
*First point: 3 doubles representing x,y,z coordinates*<br>
*Second point: 3 doubles representing x,y,z coordinates*<br>
*Third point: 3 doubles representing x,y,z coordinates*<br>
*R,G,B colours: 3 integers between 0 and 255*<br>

## Usage
1) Do `make` to compile `miniRT`.
2) To execute the program on a window, run `./miniRT [scene].rt`. (**execute the binary with a .rt file**)
3) To generate a bmp image file, run `./miniRT [scene].rt --save`.
4) Press `space bar` to switch view point in case of several cameras in the .rt file.
5) Press `esc` key or :x: to exit the program. 

