#include <stdio.h>
#include <math.h>

struct vect{
  double x;
  double y;
  double angle;
  double rad;
};

#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

struct vect fill_polar(struct vect a){
  a.angle = radToDeg(atan(a.y/a.x));
  a.rad = sqrt(a.x*a.x+a.y*a.y);
  return a;
};

struct vect fill_decart(struct vect a){
  a.x = a.rad*cos(degToRad(a.angle));
  a.y = a.rad*sin(degToRad(a.angle));
  return a;
}; 

void printVect(char m, struct vect a){
  if (m == 'a'){
    printf("%lf %lf %lf %lf \n",a.x,a.y,a.angle,a.rad);
  }
  if (m == 'p'){
    printf("%lf %lf \n",a.angle,a.rad);
  }
  if (m == 'd'){
    printf("%lf %lf \n",a.x,a.y);
  }
};

struct vect readVect(char m, double x, double y){
  struct vect a;
  if (m == 'p'){
    a.angle = x;
    a.rad = y;
    a = fill_decart(a);
  }
  if (m == 'd'){
    a.x = x;
    a.y = y;
    a = fill_polar(a);
  }
  return a;
};

struct vect readVect4(double x1, double y1, double x2, double y2){
  return readVect('d', x2-x1,y2-y1);
};

struct vect sumVect(struct vect a, struct vect b){
  return readVect('d', a.x+b.x, a.y+b.y);
}

struct vect multVect(struct vect a, double b){
  return readVect('d', a.x*b, a.y*b);
};

int isParallel(struct vect a, struct vect b){
  if (a.angle - b.angle < 0.001){
    return 1;
  }
  return 0;
};

int isPerpendicular(struct vect a, struct vect b){
  if (((a.angle - b.angle < 90.001) && (a.angle - b.angle > 89.999)) || ((a.angle - b.angle > -90.001) && (a.angle - b.angle < -89.999))){
    return 1;
  }
  return 0;
};


int main(void) {
  //task b
  struct vect A = readVect('d', 10,20);
  printVect('a', A);
  printVect('d', A);

  //task c
  struct vect B = readVect4(10,20,30,40);
  printVect('d', B);

  //task d
  printf("%lf\n", A.rad);

  //task e
  double a,b,c,d;
  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
  struct vect C = sumVect(readVect('d',a,b),readVect('d',c,d));
  printVect('a', C);

  //task f
  scanf("%lf %lf %lf",&a,&b,&c);
  struct vect D = readVect('d',a,b);
  printVect('a', multVect(D,c));

  //task g
  struct vect E = readVect('d', 10, 20);
  struct vect F = multVect(E, 10);
  struct vect G = readVect('d', 20, -10);
  printf("%d\n", isParallel(E,F));
  printf("%d\n", isParallel(E,G));
  printf("%d\n", isPerpendicular(E,F));
  printf("%d\n", isPerpendicular(E,G));
  

  return 0;
}
