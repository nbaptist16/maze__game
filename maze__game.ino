/*
Moving_Dot.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

// Global variables go here...
int x = 3;
int y = 4;
int z = 255;
int a = 1;

// obstacles

void drawW()
{
  DrawPx(0,7,Green);
  DrawPx(1,7,Green);
  DrawPx(2,7,Green);
  DrawPx(3,7,Green);
  DrawPx(5,7,Green);
  DrawPx(6,7,Green);
  DrawPx(7,7,Green);
  DrawPx(0,6,Green);
  DrawPx(5,6,Green);
  DrawPx(7,6,Green);
  DrawPx(0,5,Green);
  DrawPx(2,5,Green);
  DrawPx(3,5,Green);
  DrawPx(5,5,Green);
  DrawPx(7,5,Green);
  DrawPx(0,4,Green);
  DrawPx(1,4,Green);
  DrawPx(2,4,Green);
  DrawPx(5,4,Green);
  DrawPx(7,4,Green);
  DrawPx(2,3,Green);
  DrawPx(3,3,Green);
  DrawPx(4,3,Green);
  DrawPx(5,3,Green);
  DrawPx(7,3,Green);
  DrawPx(0,0,Green);
  DrawPx(0,1,Green);
  DrawPx(0,2,Green);
  DrawPx(2,1,Green);
  DrawPx(3,1,Green);
  DrawPx(4,1,Green);
  DrawPx(5,1,Green);
  DrawPx(6,1,Green);
  DrawPx(5,0,Green);
  DrawPx(6,0,Green);
}

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{ 
  DrawPx(x,y,Red);  //Draws dot
  DisplaySlate();
  delay(75);
  ClearSlate();
  drawW();
  
  SetAuxLEDs(z);
  
  // left and right
  CheckButtonsDown();
  if(Button_Right)
   {
     if (x < 7)
     {
       x = x + 1;  // Also x++;
     }
     else
     {
       x = 0;
     }
   }
   
  
   
   CheckButtonsDown();
   if (Button_Left)
   {
     if (x > 0)
     {
       x = x -1;
     }
     else
     {
       x = 7;
     }
   }
   // end
   
   
   // up and down
   CheckButtonsDown();
  if(Button_Up)
   {
     if (y < 7)
     {
       y = y + 1;  // Also x++;
     }
     else
     {
       y = 0;
     }
   }
   
  
   
   CheckButtonsDown();
   if (Button_Down)
   {
     if (y > 0)
     {
       y = y -1;
     }
     else
     {
       y = 7;
     }
   }
   // end
   
  if (ReadPx (x,y) == Green)
   {
     Tone_Start(ToneG3, 250);
     Tone_Start(ToneFs3, 250);
     (x=3);
     (y=4);
     (z-144/a);  // to decrease auxLEDs
     (a*2);
   }  
   
   
}


