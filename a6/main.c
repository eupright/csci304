#include <stdio.h>
#include <string.h>
#include "contact.h"
#include "contact_list.h"
#include "utils.h"


void process_file(char *filename);

char print_menu();

char print_format_menu();

void find_individual(char mode);

void print_tab(char mode);

void process_state_contacts(char mode);


int main() {
    //initializing the mode to condensed
    char mode = 'C';
    char menu_option;
    char filename[5];

    //check command line argument info to ensure a file is specified
    //if not a message is printed and exit is called wit a EXIT_FAILURE status

    init_contact_list();
    process_file(filename);
    print_contact_list(mode);

    do {
        menu_option = print_menu();

        switch (menu_option) {
            case 'C':
                mode = print_format_menu();
                break;
            case 'I':
                find_individual(mode);
                break;
            case 'T':
                print_tab(mode);
                break;
            case 'S':
                process_state_contacts(mode);
                break;
        }

    } while(menu_option != 'Q');

    free_contact_list();


    return 0;
}

void process_file(char *filename) {

}

char print_menu() {
    char menu_option[10];
    int menu_error;
    char valid_modes[] = "CITSQ";
    do {
        printf("\nPlease select one of the following:\n\n");
        printf(" c  Change output format\n");
        printf(" i  Search for individual\n");
        printf(" t  Print tab\n");
        printf(" s  Look up by state\n");
        printf(" q  Quit\n\n");

        scanf("%10s", menu_option);
        printf("Option: %s\n", menu_option);

        upper(menu_option);

        if(strlen(menu_option) > 1) {
            printf("\nInvalid option entered\n\n");
            menu_error = 1;
        }
        else if(!strchr(valid_modes, menu_option[0])){
            printf("\nInvalid option entered\n\n");
            menu_error = 1;
        }
        else {
            menu_error = 0;
        }
    } while (menu_error);

    return menu_option[0];
}

char print_format_menu() {
    char mode[2];

    printf("\nPlease select one of the following:\n\n");
    printf(" c  Condensed output information\n");
    printf(" f  Full output information\n");

    scanf("%2s", mode);
    printf("Option: %s\n", mode);

    upper(mode);

    return mode[0];
}

void find_individual(char mode) {
    NAME_T last_name;
    NAME_T first_name;

    //prompting for last and first names, and uppercasing them
    printf("\nPlease enter last name:");
    scanf("%15s", last_name);
    printf("%s\n", last_name);
    upper(last_name);

    printf("\nPlease enter first name:");
    scanf("%15s", first_name);
    printf("%s\n", first_name);
    upper(first_name);

    //calling find_contact
    //calling print_contact using the return pointer and mode
    //or printing a message that the contact wasn't found
}

void print_tab(char mode) {

}

void process_state_contacts(char mode) {

}
