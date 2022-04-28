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
    //char filename[20] = "/addrcsv_short.txt";

    //check command line argument info to ensure a file is specified
    //if not a message is printed and exit is called with a EXIT_FAILURE status

    init_contact_list();
    //process_file(filename);
    //print_contact_list(mode);

    CONTACT_T temp_cont;
    strcpy(temp_cont.first_name, "Elizabeth");
    strcpy(temp_cont.last_name, "Upright");
    strcpy(temp_cont.co_name, "Fannie Mae");
    strcpy(temp_cont.addr, "12007 Wandabury Road");
    strcpy(temp_cont.city, "Oakton");
    strcpy(temp_cont.county, "Fairfax");
    strcpy(temp_cont.state, "VA");
    strcpy(temp_cont.zip, "22124");
    strcpy(temp_cont.phone1, "703-508-4084");
    strcpy(temp_cont.phone2, "703-620-3556");
    strcpy(temp_cont.email, "upright02@gmail.com");
    strcpy(temp_cont.web, "eaupright.com");
    CONTACT_T *contact;
    contact = create_contact(&temp_cont);
    print_contact(contact, 'F');
    print_contact(contact, 'C');

    insert_contact(contact);
    printf("inserted contact\n");
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
    FILE *fp;
    CONTACT_T temp_cont;
    CONTACT_T *contact;
    printf("in process_file");

    //opening the contact file
    fp = fopen(filename, 'r');
    printf("file is open");
    //discarding the first line
    fscanf(fp, "%*s\n");
    //reading each line and assigning the fields of the temporary contact
    while (fscanf(fp,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%s ",
                  temp_cont.first_name, temp_cont.last_name, temp_cont.co_name, temp_cont.addr, temp_cont.city, temp_cont.county,
                  temp_cont.state, temp_cont.zip, temp_cont.phone1, temp_cont.phone2, temp_cont.email, temp_cont.web) == 12) {
        //creates a contact node and inserts it into the bucket list
        contact = create_contact(&temp_cont);
        insert_contact(contact);
    }
    //closing the contact file
    fclose(fp);
}

char print_menu() {
    char menu_option[10];
    int menu_error;
    char valid_modes[] = "CITSQ";
    do {
        //printing the menu
        printf("\nPlease select one of the following:\n\n");
        printf(" c  Change output format\n");
        printf(" i  Search for individual\n");
        printf(" t  Print tab\n");
        printf(" s  Look up by state\n");
        printf(" q  Quit\n\n");

        //prompting for a menu option and uppercasing it
        scanf("%10s", menu_option);
        printf("Option: %s\n", menu_option);
        upper(menu_option);

        //checking for a valid option
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
        //continue printing the menu until a valid option is selected
    } while (menu_error);

    //return the valid menu option
    return menu_option[0];
}

char print_format_menu() {
    char mode[2];

    printf("\nPlease select one of the following:\n\n");
    printf(" c  Condensed output information\n");
    printf(" f  Full output information\n");

    //prompting for and uppercasing the format mode
    scanf("%2s", mode);
    printf("Option: %s\n", mode);
    upper(mode);

    //returning the format mode
    return mode[0];
}

void find_individual(char mode) {
    NAME_T last_name;
    NAME_T first_name;
    CONTACT_T *contact;

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
    contact = find_contact(last_name, first_name);
    //calling print_contact using the return pointer and mode
    if (contact != NULL){
        print_contact(contact, mode);
    } else {
        //or printing a message that the contact wasn't found
        printf("Contact not found\n");
    }
}

void print_tab(char mode) {
    char tab;
    CONTACT_T *contact;

    //prompt for tab letter and uppercasing it
    printf("\nPlease enter last name tab letter:");
    scanf(" %c", &tab);
    printf("%c\n", tab);
    upper(&tab);

    //calls get_next_contact using tab letter
    contact = get_next_contact(tab);
    if (contact == NULL){
        //if no contacts are in that tab, prints that no contacts were found
        printf("No contacts found\n");
    } else {
        //otherwise, loop through and print all the contacts in the tab
        while (contact != NULL){
            print_contact(contact, mode);
            contact = get_next_contact(tab);
        }
    }
}

void process_state_contacts(char mode) {
    char state[3];

    //prompts for state and uppercases it
    printf("\nPlease enter two-letter state abbreviation:");
    scanf("%2s", state);
    printf("%s\n", state);
    upper(state);

    //calls print_state_contacts
    print_state_contacts(state, mode);
}
