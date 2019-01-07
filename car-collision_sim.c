#include <stdio.h>
#include <math.h>
//global variables - condições iniciais
float Vo, a, dist;
float v = 0;
float Xo = 0;
float delta_t = 0.1;

float position(float time) {
  float x = Xo + Vo*time - (a*pow(time, 2))/2;
  return x;
}

int main () {
  printf("Choose the initial velocity of the car: ");
  scanf("%f", &Vo);
  printf("\nChoose de aceleration(don't need to put the minus sign): ");
  scanf("\n%f", &a);
  printf("Choose the distance between the car and the wall: ");
  scanf("%float", &dist);
  if (a < 0 ) {
    a = fabs(a);
  }
  float x_max = (pow(Vo, 2))/(2*a);
  float tmax = Vo/a;
  float t;
  float x_t;
  for (t = 0; t <= tmax; ) {
    x_t = position(t);
    t = t + delta_t;
    if (x_t >= dist) {
      printf("\nCOLISSION");
      break;
    }
  }
  if (x_t < dist) {
    float dist_missing = dist - x_t;
    printf("\n%f meters between the car and the bar\n", dist_missing);
  }
  return 0;
}
