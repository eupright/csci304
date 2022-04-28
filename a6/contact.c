#include "contact.h"

CONTACT_T *create_contact(CONTACT_T *contact) {
    CONTACT_T *new_cont;
    //using malloc to allocate memory for the new contact node
    new_cont = malloc(sizeof(CONTACT_T));

    //copying all field data from contact to the new node
    strcpy(new_cont->first_name, contact->first_name);
    strcpy(new_cont->last_name, contact->last_name);
    strcpy(new_cont->co_name, contact->co_name);
    strcpy(new_cont->addr, contact->addr);
    strcpy(new_cont->city, contact->city);
    strcpy(new_cont->county, contact->county);
    strcpy(new_cont->state, contact->state);
    strcpy(new_cont->zip, contact->zip);
    strcpy(new_cont->phone1, contact->phone1);
    strcpy(new_cont->phone2, contact->phone2);
    strcpy(new_cont->email, contact->email);
    strcpy(new_cont->web, contact->web);

    //initializing the next pointer to null
    new_cont->next = NULL;

    //returning the pointer to the new contact
    return new_cont;
}

void print_contact(CONTACT_T *contact, char mode) {
    if (mode == 'F'){
        //printing in full mode
        printf("Name:    %s %s\n", contact->first_name, contact->last_name);
        printf("Address: %s, %s, %s %s  (%s County)\n", contact->addr, contact->city, contact->state, contact->zip, contact->county);
        printf("Phone:   %s (primary)  %s\n", contact->phone1, contact->phone2);
        printf("email:   %s\n", contact->email);
        printf("web:     %s\n\n", contact->web);
    } else if (mode == 'C') {
        //printing in condensed mode
        printf("%-15s   %-15s   %-12s   %s\n", contact->last_name, contact->first_name, contact->phone1, contact->email);
    }
}


