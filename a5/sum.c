#include <stdio.h>

//global variables
int a = 8;
int b = -3;
int m = 10;

//computes the summation of ai+b using repeated adds
int summation(int n) {
    int sum = 0;
    int i = n;
    //loops from n to 0 in order to compute the sum
    do {
        sum += b;
        if (i > 0){
            //computes a*i with addition instead of multiplication
            do {
                sum += a;
                i--;
            } while (i > 0);
        }
        n--;
        i = n;
    } while (n >= 0);
    return sum;
}




int main() {
    int sum;
    int j = 0;
    //loops through j from 0 to m
    do {
        //call summation on j
        sum = summation(j);
        //prints out j and its summation in both decimal and hex
        printf("%2d  %x : %5d   %08x\n", j, j, sum, sum);
        //increment j
        j++;
    } while(j <= m);
    return 0;
}
