
/*movingdot.ino
 * by: Taiyo Endo
 */

#include <MeggyJrSimple.h>

int x;
int y;
int color;
boolean touch=false;
int xwall;
int ywall;

struct Point
{
  int x;
  int y;
  int color;
};

Point p1={3,2,Red};
Point p2={3,3,Red};
Point p3={3,4,Red};
Point p4={3,5,Red};
Point p5={5,2,Red};
Point p6={5,3,Red};
Point p7={5,4,Red};
Point p8={5,5,Red};

Point points[]={p1,p2,p3,p4,p5,p6,p7,p8};

void setup()
{
  MeggyJrSimpleSetup();
  x=0;
  y=3;
  color=1;
  touch=false;
}


void loop() 
{
  drawplayer();
  moveplayer();
  obstacles();
  goal();
  DisplaySlate();
  ClearSlate();
}

void drawplayer()
{
  DrawPx(x,y,Blue);
}


void obstacles()
{
  for (int i=0; i<8; i++)
  {
    DrawPx(points[i].x,points[i].y++,points[i].color);
    delay(100);
    if (points[i].x>7)
    {
      points[i].x=1;
    }
  }

  for (int i=2; i<6; i++)
  {
    if (x=3)
    {
      if (y=i)
      {
        touch=true;        
      }
    }

    if (x=5)
    {
      if (y=i)
      {
        touch=true;
      }
    }
  }
  if (touch==true);
  {
   x=0;
   y=3;
   Tone_Start(00000,100);
   touch=false;
  }
}


void moveplayer()
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


void goal()
{
  for (int i=2; i<6; i++)
  {
   DrawPx(7,i,Green); 
  }
}



/*
void moveenemy()
{
 delay(200);
 if (x>enemyX)
 {
  enemyX++;
 }
 if (x<enemyX)
 {
  enemyX--;
 }
 if (y>enemyY)
 {
  enemyY++;
 }
 if (y<enemyY)
 {
  enemyY--;
 }
}
*/



/*
 * void obstacles()
 * {
 * for (int i=3; i)
 *  {
 *  DrawPx(2,i,Red);
 *  DrawPx(5,i,Red);
 *  {
 * 
 */
