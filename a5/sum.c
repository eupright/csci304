#include <stdio.h>

//global variables
int a = 8;
int b = -3;
int m = 10;

//computes the summation of ai+b, from 0 to n, using repeated adds
int summation(int n) {
    int sum = 0;
    int a_count = a; //holds the value of a so the nested do-while loop can run a times
    //loops from n to 0 in order to compute the sum
    do {
        sum += b;
        //computes a*i (which is the same as a*n) with addition instead of multiplication
        //adds i (or n) to the sum a times
        do {
            sum += n;
            a_count--;
        } while (a_count > 0);
        a_count = a;
        n--;
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
        printf("%2d  %x : %5d   0x%08x\n", j, j, sum, sum);
        //increment j
        j++;
    } while(j <= m);
    return 0;
}
