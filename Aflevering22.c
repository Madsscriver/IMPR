#include <stdio.h>
#include <math.h>

int main(void) {

      int n, c;
    

    printf("Please Input a number that's positive: \n");
    scanf("%d", &n);
    printf("Input a digit (Between 0 and 9): \n");
    scanf("%d", &c);

    if (c <= 0 && c > 9 && n <= 0){
        break
        }else {
           printf("Wrong imput")
           return(1) 
        }
return(0)
}