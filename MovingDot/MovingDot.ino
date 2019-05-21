/*
 * movingdot.ino
 * etch-a-sketch
 * by: Taiyo Endo
 * -use right,left,up,down buttons to move around
 * -press right circle button to change colors
 * -hold right circle button to cycle through colors
 * -press left circle button to clear
 * -use dark color to erase specific dots
 */

#include <MeggyJrSimple.h>

int x;
int y;
int color;

void setup()
{
  MeggyJrSimpleSetup();
  x = 0;
  y = 3;
  color = 1;
}

void loop() 
{
  drawdot();
  DisplaySlate();
  movedot();
  colordot();
}

void drawdot()
{
  DrawPx(x,y,color);  
}

void colordot()
{
  CheckButtonsDown();
  if (Button_A)
  {
    color++;
    delay(200);
  }
  if (Button_B)
  {
    ClearSlate();
  }
  if (color > 15)
  {
    color = 0;
  }  
}

void movedot()
{
  CheckButtonsPress();
  if (Button_Left)
  {
    x--;
  }
  if (Button_Right)
  {
    x++;
  }
  if (Button_Up)
  {
    y++;
  }
  if (Button_Down)
  {
    y--;
  }
    if (x<0)
  {
    x=7;
  }
  if (x>7)
  {
    x=0;
  }
   if (y<0)
  {
    y=7;
  }
  if (y>7)
  {
    y=0;
  }
}
