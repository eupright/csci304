#include <stdio.h>
#include <string.h>
#include "bin_str.h"

unsigned short get_binary_op (char *bin){

}

void convert_to_binary (short acc, char *bin){

}

void add (short *acc, char mode){

}

void subtract (short *acc, char mode){

}

short get_operand(char mode){
    short acc;
    switch (mode) {
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

void print_acc(short acc, char mode){
    printf("\n****************************************\n");
    switch (mode) {
        case 'O': case 'o':
            printf("* Accumulator:         Input Mode: Oct *\n");
            break;
        case 'H': case 'h':
            printf("* Accumulator:         Input Mode: Hex *\n");
            break;
        default:
            printf("* Accumulator:         Input Mode: Dec *\n");
    }
    printf("*   Binary  :  %016hx      *\n", acc);
    printf("*   Hex     :  %04hX                    *\n", acc);
    printf("*   Octal   :  %06ho                  *\n", acc);
    printf("*   Decimal :  %-10hd              *\n", acc);
    printf("****************************************\n\n");
}

char print_menu(void){
    char mode[10];
    int menu_error;
    char valid_modes[] = "OoHhDdCcSsQq&|^~<>+-Nn";
    do {
        printf("Please select one of the following options: \n\n");
        printf("B  Binary Mode             & AND with Accumulator           + Add to Accumulator\n");
        printf("O  Octal Mode              | OR  with Accumulator           - Subtract from Accumulator\n");
        printf("H  Hexadecimal Mode        ^ XOR with Accumulator           N Negate Accumulator\n");
        printf("D  Decimal Mode            ~ Complement Accumulator\n\n");
        printf("C  Clear Accumulator       < Shift Accumulator Left\n");
        printf("S  Set Accumulator         > Shift Accumulator Right\n\n");
        printf("Q  Quit\n\n");

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

    } while (menu_error);

    return mode[0];
}


int main() {

    char mode = 'D';
    char menu_selection;
    short acc = 0;
    // print accumulator
    print_acc(acc, mode);
    // print menu - return menu option - may not be the new mode!
    menu_selection = print_menu();
    // decide what to do with the menu option
    // q - quit out of the accumulator - stop the program
    while (menu_selection != 'Q' && menu_selection != 'q') {
        //menu_selection = print_menu();
        switch (menu_selection) {
            //o,h,d - assign the new mode - print out the new mode - print out the accumulator and menu
            case 'o':
            case 'O':
                mode = menu_selection;
                printf("Mode is Octal\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case 'h':
            case 'H':
                mode = menu_selection;
                printf("Mode is Hexadecimal\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
            case 'd':
            case 'D':
                mode = menu_selection;
                printf("Mode is Decimal\n");
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
                //s - call get operand with the set mode - print accumulator and menu
            case 's':
            case 'S':
                acc = get_operand(mode);
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
                //c - clear accumulator by setting acc = 0 - print accumulator and menu
            case 'c':
            case 'C':
                acc = 0;
                print_acc(acc, mode);
                menu_selection = print_menu();
                break;
        }
    }

    return 0;
}