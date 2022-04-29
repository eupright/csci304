#include <stdio.h>

int abs(int n);

int mult(int x, int y);

int rfact(int n);


int main() {
    int input[] = {3, -5, -4, 7, 0};
    //initializing n to the first element in the input array
    int index = 0;
    int n = input[index];

    //while n doesn't equal zero
    while (n != 0){
        //print n
        printf("%d\n", n);

        //get the absolute value of n
        n = abs(n);
        //print the absolute value in hex
        printf("0x%08x\n", n);

        //if n is even
        if ((n & 1) == 0){
            //get the square of abs(n)
            int sqr = mult(n, n);
            //print out the square in hex
            printf("0x%08x\n", sqr);
        }
        //else if n is odd
        else {
            //get the factorial of abs(n)
            int fact = rfact(n);
            //print out the factorial in hex
            printf("0x%08x\n", fact);
        }
        //getting the next value in the input array
        index = index + 1;
        n = input[index];
    }

    return 0;
}

int abs(int n){
    //returns the absolute value of n
    if (n > 0){
        //if n is already positive, just return it
        return n;
    }
    else {
        //if n is negative
        int abs = 0;
        //0 - n will give the positive value of n
        abs = abs - n;
        return abs;
    }

}

int mult(int x, int y) {
    //computes the product of x and y by repeatedly adding y to itself x times
    //should be called with x < y when possible
    int product = 0;
    while (x > 0){
        product = product + y;

        //decrement x for the counter
        x = x - 1;
    }

    return product;
}

int rfact(int n) {
    //computes and returns the factorial value of n with recursion
    if (n == 1){
        //the base case is the factorial of 1
        return 1;
    }

    return mult(rfact(n - 1), n);
}
