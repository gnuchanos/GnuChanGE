#include <stdio.h>
#include <stdlib.h>
#include <string.h>







int main(){
    int number1 = 10;
    int number2 = 30;
    int math = number1 + number2;
    printf("%d + %d = %d\n", number1, number2, math);

    int numX = 10;
    int *pointX = &numX;
    printf("%d : %p\n", *pointX, &pointX);

    char longtext[17] = "This is long Text";
    int longtextsize = strlen(longtext);
    for (int i = 0; i < longtextsize; i++){
        printf(" %c |", longtext[i]); }
    
    printf("\n");
    
    int i = 0;
    while (i < 10) {
        printf(" %d |", i);
        i++;

    
    }




    return 0;
}