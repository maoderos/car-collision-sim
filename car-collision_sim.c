#include <stdio.h>
#include <stdlib.h>
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
void w_plot(float x, float y, FILE *p) {
  fprintf(p, "%f %f\n", y, x);
}
void plot() {
 system("gnuplot -p -e \"plot 'gnuplot.txt'\"");
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
  FILE *p = fopen("gnuplot.txt", "w");
  for (t = 0; t <= tmax; ) {
    x_t = position(t);
    w_plot(x_t, t, p);
    t = t + delta_t;
    if (x_t >= dist) {
      printf("\nCOLISSION");
      fclose(p);
      plot();
      break;
    }
  }
  if (x_t < dist) {
    float dist_missing = dist - x_t;
    printf("\n%f meters between the car and the bar\n", dist_missing);
    fclose(p);
    plot();
  }
  return 0;
}
