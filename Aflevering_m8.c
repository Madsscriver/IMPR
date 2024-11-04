#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print_numbers(double array[], int length);
void print_points(double array_x[], double array_y[], int length);
double *calc_dist(double array_x[], double array_y[], int length);
void print_distance(double array[], int length);


int main(void){
    double xs[] = {0,7,3,8,1};
    double ys[] = {4,0,3,3,5};
    int length = 5;
    printf("xs:\n");
    print_numbers(xs, length);
    printf("\nys:\n");
    print_numbers(ys, length);
    printf("\nPoints:\n");
    print_points(xs, ys, length);
    double *dist = calc_dist(xs, ys, length);
    print_distance(dist, length-1);
    
    free(dist); 
return 0;
}
void print_numbers(double array[], int length){
    int i;
    for(i = 0; i < length; i++){
      printf("%lf\n", array[i]);
    }
}
void print_points(double array_x[], double array_y[], int length){
    int i;
    for(i = 0; i < length; i++){
      printf("(%lf,  %lf)\n", array_x[i], array_y[i]);
    }
}

void print_distance(double array[], int length){
    int i;
    printf("\nDistancen\n");
    for(i = 0; i < length; i++){
      printf("%lf\n", array[i]);
    }
}

double *calc_dist(double array_x[], double array_y[], int length){
    double *dist = (double *)malloc((length - 1) * sizeof(double));
    if (dist == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    int i;
    for(i = 0; i < length; i++){
         dist[i]= sqrt((array_x[i+1]-array_x[i])*(array_x[i+1]-array_x[i])+
                       (array_y[i+1]-array_y[i])*(array_y[i+1]-array_y[i]));

    }

    return dist;
}