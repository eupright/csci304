#ifndef A6_CONTACT_LIST_H
#define A6_CONTACT_LIST_H

#include "contact.h"
#include "utils.h"

void init_contact_list();

void insert_contact(CONTACT_T *contact);

void print_contact_list(char mode);

CONTACT_T *find_contact(NAME_T last_name, NAME_T first_name);

CONTACT_T *get_next_contact(char letter);

void print_state_contacts(char state[], char mode);

void free_contact_list();

#endif //A6_CONTACT_LIST_H
