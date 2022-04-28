#include "contact_list.h"

static CONTACT_T *bucket_list[26];

void init_contact_list() {
    //initializes each list in the bucket list to null
    for (int i = 0; i < 26; ++i) {
        bucket_list[i] = NULL;
    }
}

void insert_contact(CONTACT_T *contact) {
    //finding the correct bucket
    char letter = contact->last_name[0];
    upper(&letter);
    int index = letter - 'A';

    //case for an empty bucket
    if (bucket_list[index] == NULL){
        bucket_list[index] = contact;
        return;
    }

    //initializing current to the first element in the bucket
    CONTACT_T *current = bucket_list[index];
    CONTACT_T *prev;

    //setting up the temporary uppercase last names for comparison
    NAME_T cont_temp;
    strcpy(cont_temp, contact->last_name);
    upper(cont_temp);

    NAME_T curr_temp;
    strcpy(curr_temp, current->last_name);
    upper(curr_temp);

    //if current > contact
    if (strcmp(curr_temp, cont_temp) > 0){
        //insert contact at the head of the bucket
        contact->next = current;
        bucket_list[index] = contact;
        return;
    }
    else {
        //advance current and previous while current < contact and while current is not NULL
        while ((strcmp(curr_temp, cont_temp) < 0) && current != NULL) {
            prev = current;
            current = current->next;
            //if current is still pointing to a contact, update the last name for comparison
            if (current != NULL){
                strcpy(curr_temp, current->last_name);
                upper(curr_temp);
            }
        }

        if (strcmp(curr_temp, cont_temp) == 0){
            //if the contacts have the same last name
            //check the first names
            strcpy(cont_temp, contact->first_name);
            upper(cont_temp);
            strcpy(curr_temp, current->first_name);
            upper(curr_temp);
            //advance current and previous while current < contact and while current is not NULL
            while ((strcmp(curr_temp, cont_temp) < 0) && current != NULL) {
                prev = current;
                current = current->next;
                //if current is still pointing to a contact, update the first name for comparison
                if (current != NULL){
                    strcpy(curr_temp, current->first_name);
                    upper(curr_temp);
                }
            }
        }

        //insert the contact in between prev and current
        contact->next = current;
        prev->next = contact;
    }
}

void print_contact_list(char mode) {
    //flag to check if the list is empty
    int print_flag = FALSE;
    CONTACT_T *contact;
    //loop through each bucket in the list
    for (int i = 0; i < 26; ++i) {
        contact = bucket_list[i];
        //traversing the buckets
        while (contact != NULL) {
            //printing each node and setting the print flag to true
            print_contact(contact, mode);
            print_flag = TRUE;
            contact = contact->next;
        }
    }
    //if no contacts were printed
    if (print_flag == FALSE){
        printf("Contact list is empty\n");
    }
}

CONTACT_T *find_contact(NAME_T last_name, NAME_T first_name) {
    //finding the correct bucket
    int index = last_name[0] - 'A';

    if (bucket_list[index] == NULL){
        //if the bucket is empty, the contact isn't there
        return NULL;
    }

    //initializing current to the first element in the bucket
    CONTACT_T *current = bucket_list[index];
    //setting up the uppercase last name for comparison
    NAME_T last_temp;
    strcpy(last_temp, current->last_name);
    upper(last_temp);

    //traverse the bucket based on last name until current is the correct node
    while ((strcmp(last_temp, last_name) != 0) && current != NULL) {
        current = current->next;
        //if current is still pointing to a contact, update the last name for comparison
        if (current != NULL){
            strcpy(last_temp, current->last_name);
            upper(last_temp);
        }
    }

    if (current == NULL){
        //reached the end of the bucket and the contact doesn't exist
        return NULL;
    }

    //setting up the uppercase first name for comparison
    NAME_T first_temp;
    strcpy(first_temp, current->first_name);
    upper(first_temp);

    //traverse the bucket based on first name until current is the correct node
    while ((strcmp(first_temp, first_name) != 0) && current != NULL) {
        current = current->next;
        //if current is still pointing to a contact, update the first name for comparison
        if (current != NULL){
            strcpy(first_temp, current->first_name);
            upper(first_temp);
        }
    }

    //check to make sure the current contact is the correct one and return it
    if (strcmp(last_temp, last_name) == 0 && strcmp(first_temp, first_name) == 0){
        return current;
    }
    else {
        //otherwise, you reached the end of the bucket and the contact doesn't exist
        return NULL;
    }
}

CONTACT_T *get_next_contact(char letter) {
    //using a static variable to hold the current contact pointer
    static CONTACT_T *current = NULL;

    if (current == NULL){
        //if the current pointer is NULL, it's set to the first element in the correct bucket
        current = bucket_list[letter - 'A'];
        return current;
    }
    else {
        //otherwise, advance the current pointer, and return the next contact
        current = current->next;
        return current;
    }
}

void print_state_contacts(char state[], char mode) {
    //flag to check if no people are from that state
    int print_flag = FALSE;
    CONTACT_T *contact;
    //loop through each bucket in the list
    for (int i = 0; i < 26; ++i) {
        contact = bucket_list[i];
        //traversing the buckets
        while (contact != NULL) {
            //printing the contacts from the correct state
            if (strcmp(contact->state, state) == 0){
                print_contact(contact, mode);
                //setting the print flag to true
                print_flag = TRUE;
            }
            contact = contact->next;
        }
    }
    //if no contacts were printed
    if (print_flag == FALSE){
        printf("No contacts found\n");
    }
}

void free_contact_list() {
    CONTACT_T *current;
    CONTACT_T *next_cont;

    //loop through each bucket in the list
    for (int i = 0; i < 26; ++i) {
        current = bucket_list[i];
        //traversing the buckets
        while (current != NULL) {
            //move the next pointer to the next contact
            next_cont = current->next;

            //free the current contact
            free(current);

            //move the current pointer to the next contact
            current = next_cont;
        }
    }
}

