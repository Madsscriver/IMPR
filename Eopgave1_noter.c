#include <stdio.h>  // Inkluderer standard input/output bibliotek
#include <math.h>   // Inkluderer matematikbiblioteket for at kunne bruge funktioner som pow() og sqrt()
#include <stdlib.h> // Inkluderer standardbiblioteket for funktioner som exit()

// Deklarerer funktioner
double run_calculator(double akumulation, char *operator, double *ny_tal);  // Håndterer hele beregningsprocessen
double do_next_op(double akumulation, double ny_tal, char operator);  // Udfører næste operation baseret på operatoren
void scan_data(char *operator, double *ny_tal, double akumulation);  // Scanner data fra brugeren
char type(char operator);  // Bestemmer om operatoren er binær (kræver to tal) eller unær (kræver kun et tal)

int main(void) {
    char operator;
    double akumulation, ny_tal;

    run_calculator(akumulation, &operator, &ny_tal);  // Kører lommeregneren og starter processen

    return 0;
}

// Funktion der kører lommeregneren
double run_calculator(double akumulation, char *operator, double *ny_tal) {
    
    printf("\nThe Acumulator starts at 0.0\n"
           "\nIf you want to stop the program, press q \n");

    // Kører løkke indtil brugeren trykker 'q' for at afslutte
    while ((*operator != 'q')) {
        scan_data(operator, ny_tal, akumulation);  // Henter operator og tal fra brugeren
        akumulation = do_next_op(akumulation, *ny_tal, *operator);  // Udfører den næste operation og opdaterer akkumulatoren
        printf("\nResultatet so far is %lf\n", akumulation);  // Udskriver det nuværende resultat

    }
    return akumulation;  // Returnerer det endelige resultat
}

// Funktion der udfører den matematiske operation baseret på operatoren
double do_next_op(double akumulation, double ny_tal, char operator) {
    // Tjekker hvilken operator der blev indtastet og udfører den tilsvarende operation
    if (operator == '+') {
        akumulation = akumulation + ny_tal;
    } else if (operator == '-') {
        akumulation = akumulation - ny_tal;
    } else if (operator == '*') {
        akumulation = akumulation * ny_tal;
    } else if (operator == '/') {
        akumulation = akumulation / ny_tal;
    } else if (operator == '^') {
        akumulation = pow(akumulation, ny_tal);  // Eksponentiel beregning
    } else if (operator == '#') {
        akumulation = sqrt(akumulation);  // Kvadratrodsberegning
    } else if (operator == '%') {
        akumulation = -akumulation;  // Skifter fortegn
    } else if (operator == '!') {
        akumulation = 1 / akumulation;  // Reciproktal beregning
    }
    return akumulation;  // Returnerer det opdaterede resultat
}

// Funktion der scanner data (operator og tal) fra brugeren
void scan_data(char *operator, double *ny_tal, double akumulation) {
    *operator = 0;  // Initialiserer operatoren
    // Loop indtil gyldig operator er indtastet
    while (*operator != '+' && *operator != '-' && *operator != '*' && *operator != '/' &&
           *operator != '^' && *operator != '#' && *operator != '%' && *operator != '!' ) {
        printf("\nEnter operator\n\n+   -   *   /   ^   #   %%   !\n");  // Beder brugeren indtaste en operator
        scanf(" %c", operator);  // Læser operatoren ind

        if (*operator == '+' || *operator == '-' || *operator == '*' || *operator == '/' ||
            *operator == '^' || *operator == '#' || *operator == '%' || *operator == '!') {
            break;  // Hvis gyldig operator er indtastet, brydes løkken
        } else if (*operator == 'q') {  // Hvis brugeren trykker 'q', afsluttes programmet
            printf("\nFinal Result\n %lf", akumulation);
            exit(0);
        } else {
            printf("\nFalse Input\n");  // Hvis ugyldig input, print fejlmeddelelse
        }
    }
    
    // Bestemmer typen af operator (binær/unær)
    char o_type = type(*operator);

    // Hvis operatoren er binær, beder om at få det næste tal
    if (o_type == 'b') {
        printf("\nHvilket tal ønsker du at bruge ?\n");
        scanf("%lf", ny_tal);  // Læser tallet ind
    }
}

// Funktion der bestemmer om operatoren er binær eller unær
char type(char operator) {
    char o_type;
    // Hvis operatoren er en af de binære (+, -, *, /, ^), sættes o_type til 'b'
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^') {
        o_type = 'b';  // Binær operator
    } else {
        o_type = 'u';  // Unær operator
    }
    return o_type;
}