#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double run_calculator(double akumulation,char *operator,double  *ny_tal);
double do_next_op(double akumulation, double ny_tal, char operator);
void scan_data (char *operator, double *ny_tal, double akumulation);
char type(char operator);

int main(void) {
    char operator;
    double akumulation, ny_tal;

    run_calculator(akumulation, &operator, &ny_tal);
   
return 0;
}

double run_calculator(double akumulation,char *operator,double *ny_tal){
    
    printf("\nThe Acumulator starts at 0.0\n"
           "\nIf you want to stop the program, press q \n");
    
    while ((*operator != 'q')){
        scan_data(operator, ny_tal, akumulation);
        akumulation = do_next_op(akumulation, *ny_tal, *operator);
        printf("\nResultatet so far is %lf\n", akumulation);

    }
    return akumulation;
}

double do_next_op(double akumulation, double ny_tal, char operator){

    if (operator == '+'){
        akumulation = akumulation + ny_tal;
    }else if (operator == '-'){
        akumulation = akumulation - ny_tal;
    }else if (operator == '*'){
        akumulation = akumulation * ny_tal;
    }else if (operator == '/'){
        akumulation = akumulation / ny_tal;
    }else if (operator == '^'){
        akumulation = pow(akumulation, ny_tal);
    }else if (operator == '#'){
        akumulation = sqrt (akumulation);
    }else if (operator== '%'){
        akumulation = -akumulation;
    }else if (operator== '!'){
        akumulation = 1/akumulation;
    }
    return akumulation;
}

void scan_data (char *operator, double *ny_tal, double akumulation){
    *operator = 0;
    while(*operator != '+' && *operator != '-' && *operator != '*' && *operator != '/' &&
          *operator != '^' && *operator != '#' && *operator != '%' && *operator != '!'){
           printf("\nEnter operator\n\n+   -   *   /   ^   #   %%   !\n");
           scanf( " %c", operator);
        
        if (*operator == '+' || *operator == '-' || *operator == '*' || *operator == '/' ||
            *operator == '^' || *operator == '#' || *operator == '%' || *operator == '!'){
             break;
        
        }else if (*operator == 'q'){
            printf("\nFinal Result\n %lf", akumulation);
            exit(0);
        
        }else {printf("\nFalse Input\n");}
        }
        char o_type = type(*operator);
        
        if (o_type == 'b'){
            printf("\nHvilket tal ønsker du at bruge ?\n");
            scanf("%lf",ny_tal);
        }
}

char type(char operator){

    char o_type;
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^'){
        o_type = 'b';
    }else {
        o_type = 'u';
    }
return o_type;


}