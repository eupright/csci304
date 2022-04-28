#include "utils.h"

void upper(char *str) {
    int i = 0;
    //iterating over the string until you reach the delimiting character
    while(str[i] != '\0') {
        //if the character is a lowercase letter
        if(str[i] >= 'a' && str[i] <= 'z'){
            //change it to uppercase using character arithmetic
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}
