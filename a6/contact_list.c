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
    //printf("index is: %d\n", index);

    //case for an empty bucket
    if (bucket_list[index] == NULL){
        bucket_list[index] = contact;
        //printf("in an empty bucket\n");
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
        //printf("inserting at head of bucket\n");
        contact->next = current;
        bucket_list[index] = contact;
        return;
    }
    else {
        //advance current and previous while current < contact
        //printf("in the else\n");
        while (current != NULL && (strcmp(curr_temp, cont_temp) < 0)) {
            //printf("in the while loop\n");
            prev = current;
            //printf("assigned prev\n");
            current = current->next;
            //printf("moved current\n");
            if (current != NULL){
                strcpy(curr_temp, current->last_name);
                upper(curr_temp);
            }
        }

        //insert the contact in between prev and current
        //printf("inserting in the list\n");
        contact->next = current;
        prev->next = contact;

        /*
        if (strcmp(curr_temp, cont_temp) == 0){
            //if the contacts have the same last name
            //check the first names
            strcpy(cont_temp, contact->first_name);
            upper(cont_temp);
            strcpy(curr_temp, current->first_name);
            upper(curr_temp);
            //advance current and previous while current < contact
            while (strcmp(curr_temp, cont_temp) < 0) {
                prev = current;
                current = current->next;
                strcpy(cont_temp, current->first_name);
                upper(cont_temp);
            }
            //insert the contact in between prev and current
            contact->next = current;
            prev->next = contact;
        }
        else {
            //when the last names are different
            //insert the contact in between prev and current
            contact->next = current;
            prev->next = contact;
        }
        return; */
    }
}

void print_contact_list(char mode) {
    //flag to check if the list is empty
    int print_flag = 0;
    CONTACT_T *contact;
    //loop through each bucket in the list
    for (int i = 0; i < 26; ++i) {
        contact = bucket_list[i];
        //traversing the buckets
        while (contact != NULL) {
            //printing each node and setting the print flag to true
            print_contact(contact, mode);
            print_flag = 1;
            contact = contact->next;
        }
    }
    //if no contacts were printed
    if (print_flag == 0){
        printf("Contact list is empty");
    }
}

CONTACT_T *find_contact(NAME_T last_name, NAME_T first_name) {
    return NULL;
}

CONTACT_T *get_next_contact(char letter) {
    return NULL;
}

void print_state_contacts(char state[], char mode) {

}

void free_contact_list() {

}

