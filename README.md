# miniRT
The goal of this project is to generate images using the Raytracing protocol. Those computer generated images will each represent a scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system.

Allowed built-in functions: **open**, **close**, **read**, **write**, **malloc**, **free**, **perror**, **strerror**, **exit**. **All functions of the math library**. **All functions of the MinilibX**.

The task is to, implement 5 geometric objects: plane, sphere, cylinder, square and triangle.

## How it looks

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
    <td>450 - width 450 - height<br>0.1 - lighting 255,255,0 - r,g,b<br>0,0,0 - x,y,z coordinates of the view point
        0,0,1 - 3d normalized orientation vector 90 - FOV<br> 0,1,7 - x,y,z coordinates of the light point 
        0.6 - brightness, 255,255,255 - r,g,b<br>0,2,0 - x,y,z coordinates 0,1,0 - 3d normalized orientation vector 
        0,0,255 - r,g,b</td>
  </tr>
</table>

## Usage
1) Do `make` to compile `miniRT`.
2) To execute the program on a window, run `./miniRT [scene].rt`. (**execute the binary with a .rt file**)
3) To generate a bmp image file, run `./miniRT [scene].rt} --save`. 

