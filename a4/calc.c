#include <stdio.h>
#include <string.h>
#include "calc.h"

unsigned short get_binary_op (char *bin){
    //returns the number represented by the binary string
    unsigned short acc = 0;
    int power = 1;
    //iterates over the string from right to left
    for (int i = strlen(bin)-1; i >= 0; i--) {
        //adds to the acc value when there's a one
        if(bin[i] == '1'){
            acc += power;
        }
        //increments the power of 2 as the bits get more significant
        power *= 2;
    }
    return acc;
}

void convert_to_binary (short acc, char *bin){
    //converts the value into a binary string
    //cast acc to an unsigned short
    unsigned short u_acc = acc;
    int power = 32768;
    int position = 1; //keeps track of the position in the string to add 1s,0s,and spaces
    while(power >= 1){
        //adding spaces where necessary, doesn't decrement the power
        if(position % 5 == 0){
            bin[position-1] = ' ';
        }
        //if you need a 2^x value, then append a 1 and subtract 2^x from u_acc
        else if(u_acc >= power){
            bin[position-1] = '1';
            u_acc -= power;
            power /= 2;
        }
        //otherwise, append a 0 and continue on
        else {
            bin[position-1] = '0';
            power /= 2;
        }
        position++;
    }
    bin[19] = '\0';
}


short get_operand(char mode){
    //asks the user for the value in the specified mode
    short acc;
    bin_str bin;
    switch (mode) {
        case 'B': case 'b':
            printf("Enter binary value: ");
            scanf("%s", bin);
            printf("%s", bin);
            //converting the user's binary string into the short acc value
            acc = get_binary_op(bin);
            break;
        case 'O': case 'o':
            printf("Enter octal value: ");
            scanf("%ho", &acc);
            printf("%ho", acc);
            break;
        case 'H': case 'h':
            printf("Enter hex value: ");
            scanf("%hx", &acc);
            printf("%hX", acc);
            break;
        default:
            printf("Enter decimal value: ");
            scanf("%hd", &acc);
            printf("%hd", acc);
            break;
    }
    printf("\n");
    return acc;
}

void add (short *acc, char mode){
    //get an operand in the specified mode to add to acc
    short operand;
    operand = get_operand(mode);
    //add acc and operand
    short result = (*acc + operand);
    //detect positive or negative overflow
    if(*acc > 0 && operand > 0 && result < 0){
        printf("Positive Overflow\n");
    }
    else if (*acc < 0 && operand < 0 && result > 0){
        printf("Negative Overflow\n");
    }
    //set acc to the new value
    *acc = result;
}

void subtract (short *acc, char mode){
    //get an operand in the specified mode to subtract from acc
    short operand;
    operand = get_operand(mode);
    //subtract the operand from acc
    short result = (*acc - operand);
    //detect positive or negative overflow
    if(*acc > 0 && (-1)*operand > 0 && result < 0){
        printf("Positive Overflow\n");
    }
    else if (*acc < 0 && (-1)*operand < 0 && result > 0){
        printf("Negative Overflow\n");
    }
    //set acc to the new value
    *acc = result;
}

void print_acc(short acc, char mode){
    bin_str bin;
    convert_to_binary(acc, bin);
    printf("\n****************************************\n");
    //prints out the current mode of the accumulator
    switch (mode) {
        case 'B': case 'b':
            printf("* Accumulator:         Input Mode: Bin *\n");
            break;
        case 'O': case 'o':
            printf("* Accumulator:         Input Mode: Oct *\n");
            break;
        case 'H': case 'h':
            printf("* Accumulator:         Input Mode: Hex *\n");
            break;
        default:
            printf("* Accumulator:         Input Mode: Dec *\n");
    }
    //prints out the current value of the accumulator in the different representations
    printf("*   Binary  :  %s     *\n", bin);
    printf("*   Hex     :  %04hX                    *\n", acc);
    printf("*   Octal   :  %06ho                  *\n", acc);
    printf("*   Decimal :  %-10hd              *\n", acc);
    printf("****************************************\n\n");
}

char print_menu(void){
    char mode[10];
    int menu_error;
    char valid_modes[] = "BbOoHhDdCcSsQq&|^~<>+-Nn";
    //prints out the menu until a valid menu option is selected
    do {
        printf("Please select one of the following options: \n\n");
        printf("B  Binary Mode             &  AND with Accumulator           +  Add to Accumulator\n");
        printf("O  Octal Mode              |  OR  with Accumulator           -  Subtract from Accumulator\n");
        printf("H  Hexadecimal Mode        ^  XOR with Accumulator           N  Negate Accumulator\n");
        printf("D  Decimal Mode            ~  Complement Accumulator\n\n");
        printf("C  Clear Accumulator       <  Shift Accumulator Left\n");
        printf("S  Set Accumulator         >  Shift Accumulator Right\n\n");
        printf("Q  Quit \n\n");

        scanf("%s", mode);
        printf("Option: %s\n", mode);

        if(strlen(mode) > 1) {
            printf("\nInvalid option: %s\n\n", mode);
            menu_error = 1;
        }
        else if(!strchr(valid_modes, mode[0])){
            printf("\nInvalid option: %s\n\n", mode);
            menu_error = 1;
        }
        else {
            menu_error = 0;
        }
    //menu_error is true when the user inputs an invalid menu option
    //menu_error is false when the user inputs a valid option which stops the loop
    } while (menu_error);
    //the valid menu option will be the first character in the string
    return mode[0];
}


int main() {

    //accumulator default settings for the start
    char mode = 'D';
    char menu_selection;
    short acc = 0;
    short operand = 0;
    //print accumulator
    print_acc(acc, mode);
    //print menu - return menu option - may not be the new mode!
    menu_selection = print_menu();
    //decide what to do with the menu option
    //q - quit out of the accumulator - stop the program
    while (menu_selection != 'Q' && menu_selection != 'q') {
        //menu_selection = print_menu();
        switch (menu_selection) {
            //b,o,h,d - assign the new mode - print out the new mode - print out the accumulator and menu
            case 'b': case 'B':
                mode = menu_selection;
                printf("Mode is Binary\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case 'o': case 'O':
                mode = menu_selection;
                printf("Mode is Octal\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case 'h': case 'H':
                mode = menu_selection;
                printf("Mode is Hexadecimal\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case 'd': case 'D':
                mode = menu_selection;
                printf("Mode is Decimal\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            //s - call get operand with the set mode - print accumulator and menu
            case 's': case 'S':
                acc = get_operand(mode);
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            //c - clear accumulator by setting acc = 0 - print accumulator and menu
            case 'c': case 'C':
                acc = 0;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            //&,|,^, - asks for an operand in the current mode and then performs the operation
            case '&':
                operand = get_operand(mode);
                acc = acc & operand;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case '|':
                operand = get_operand(mode);
                acc = acc | operand;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case '^':
                operand = get_operand(mode);
                acc = acc ^ operand;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            //-,+ - use the add and subtract functions to get the operand, overflow, and perform the operation
            case '+':
                add(&acc, mode);
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case '-':
                subtract(&acc, mode);
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            //<,> - asks for a decimal value for the number of bits to shift
            case '<':
                printf("Enter number of positions to left shift accumulator: ");
                scanf("%hd", &operand);
                printf("%hd\n", operand);
                acc = acc << operand;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case '>':
                printf("Enter number of positions to right shift accumulator: ");
                scanf("%hd", &operand);
                printf("%hd\n", operand);
                acc = acc >> operand;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            //~,n - just completes the operation
            case '~':
                acc = ~acc;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case 'n': case 'N':
                acc = (-1)*acc;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
        }
    }

    return 0;
}