#include "contact_list.h"

static CONTACT_T *bucket_list[26];

void init_contact_list() {
    //initializes each list in the bucket list to null
    for (int i = 0; i < 26; ++i) {
        bucket_list[i] = NULL;
    }
}

void insert_contact(CONTACT_T *contact) {

}

void print_contact_list(char mode) {

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

