#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

double  xm,xM,ym,yM,dx, dy, sx, sy;
double x, y, r, s, t, z;
unsigned i, max_iter=512, jari=100, u, V, H;

void gam(double, double, unsigned);
void julia(double, double);
void mandelbrot(); //number of iteration
void gasket(int[8]);
void fungsi();
void garis(float,float,float,float);

int main() {
    //xm=-.8; xM=-.2; ym=-.3; yM=.3; sx=1; sy=1; u=1200;//Julia 
    //xm=-.8; xM=-.6; ym=0; yM=.3; sx=1; sy=1; u=3000;//Julia zoom 
    //xm=-2; xM=1; ym=-1.2; yM=1.2; sx=1; sy=1; u=250;//Mandelbrot
    //xm=-2; xM=-1.9; ym=-1; yM=1; sx=1; sy=1; u=5000;//Mandelbrot
    dx=xM-xm; dy=yM-ym; H=dx*u/sx; V=dy*u/sy; z=1.0/u;
    
    // Initialize the graphics window
    //initwindow(H, V,"Kanvas Himpunan Julia dan Mandelbrot");

    //Gasket
    int a[8]={10,10, 990,10, 500,990, 400,400}; srand(time(0)); //Gasket segitiga sama sisi
    //int a[8]={10,10, 450,650, 780,100, 100,100}; srand(time(0));// Gasket segitiga sembarang
    initwindow(900, 900,"Kanvas Gasket"); gasket(a); getch();

    //Julia
    julia(-0.7488,0.107421);//for c=-0.7488+0.107421i great
    //julia(-.54,.54);//for c=-0.54+0.54i
    //julia(-0.9, 0.2);//forc=-0.9+0.2i aprove
    //julia(-1,0);//for c=-1+0*i aprove

    //Mandelbrot
    //mandelbrot();
    

    getch(); closegraph(); return 0;
}

void gam(double x, double y, unsigned w){ putpixel((x-xm)*H/dx, (yM-y)*V/dy, w);}

void julia(double a, double b){
  for (x=xm; x<xM; x+=z)
    for (y=ym; y<yM; y+=z){
      i=0; r=x; s=y;
      while (i++<max_iter && r*r+s*s<jari){
        t=r; r=r*r-s*s+a; s=2*t*s+b;}
         if (i<max_iter) {
            t=powf((360*1.0*i/max_iter),1.5);
            //putpixel((x-xm)*H/dx, (yM-y)*V/dy,RGB((int)t%360,i%256,256*sin(i)));
            //putpixel((x-xm)*H/dx, (yM-y)*V/dy,RGB(56*sin(i),256*(cos(i)),sin(i)));
            putpixel((x-xm)*H/dx, (yM-y)*V/dy,RGB(256*sin(i),i%256,256*(cos(i)+sin(i))));
            //putpixel((x-xm)*H/dx, (yM-y)*V/dy,i%16);
         }
        //if (i<max_iter) putpixel((x-xm)*H/dx, (yM-y)*V/dy,RGB(256*sin(i),log(i)*37,256*(cos(3*i)+sin(i)))); // if (i>max_iter) gam(x,y,4);
    }
}

void mandelbrot(){
  for (x=xm; x<xM; x+=z)
    for (y=ym; y<yM; y+=z){
      i=0; r=s=0;
      while (i++<max_iter && r*r+s*s<jari){
        t=r; r=r*r-s*s+x; s=2*t*s+y;}
      if (i<max_iter) putpixel((x-xm)*H/dx, (yM-y)*V/dy, RGB(256*sin(i),i%256,256*(cos(i)+sin(i))));
      //putpixel((x-xm)*H/dx, (yM-y)*V/dy, i%16); // if (i>max_iter) gam(x,y,4);
      
    }
}

void gasket(int a[8]){
  int k;
  while (!kbhit()){
    putpixel(a[6],a[7],rand()%16); k=rand()%3;
    a[6]=(a[6]+a[2*k])/2; a[7]=(a[7]+a[2*k+1])/2; 
    //delay(10) ;
  }
}




