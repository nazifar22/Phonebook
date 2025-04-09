#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 30

typedef struct {
  char name[MAX_NAME_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} Entry;

typedef struct {
  Entry *entries;
  int num_entries;
  int max_entries;
} PhoneBook;

// Initialize the phone book with the given maximum number of entries
PhoneBook* init(int max_entries) {
  PhoneBook *pb = malloc(sizeof(PhoneBook));
  pb->entries = malloc(sizeof(Entry) * max_entries);
  pb->num_entries = 0;
  pb->max_entries = max_entries;
  return pb;
}

// Deallocate the memory used by the phone book
void destroy(PhoneBook *pb) {
  free(pb->entries);
  free(pb);
}

// Insert new entry or update existing entry in the phone book
bool insert(PhoneBook *pb, const char *name, const char *phone) {
  // Check if the entry already exists
  int index = -1;
  for (int i = 0; i < pb->num_entries; i++) {
    if (strcmp(pb->entries[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // Update the entry if it already exists
  if (index != -1) {
    strcpy(pb->entries[index].phone, phone);
    return true;
  }

  // Insert new entry if there is space in the phone book
  if (pb->num_entries < pb->max_entries) {
    strcpy(pb->entries[pb->num_entries].name, name);
    strcpy(pb->entries[pb->num_entries].phone, phone);
    pb->num_entries++;
    return true;
  }

  // Return false if the phone book is full
  return false;
}

// Return the phone number for the given name, or NULL if the name is not found in the phone book
const char* get(PhoneBook *pb, const char *name) {
  for (int i = 0; i < pb->num_entries; i++) {
    if (strcmp(pb->entries[i].name, name) == 0) {
      return pb->entries[i].phone;
    }
  }
  return NULL;
}

// Print all entries in the phone book
void print(PhoneBook *pb) {
  for (int i = 0; i < pb->num_entries; i++) {
    printf("%s: %s\n", pb->entries[i].name, pb->entries[i].phone);
  }
}

// Dump all entries in the phone book to a text file
void dump(PhoneBook *pb, const char *filename) {
FILE *fp = fopen(filename, "w");
if (fp == NULL) {
printf("Error opening file!\n");
return;
}

for (int i = 0; i < pb->num_entries; i++) {
fprintf(fp, "%s: %s\n", pb->entries[i].name, pb->entries[i].phone);
}

fclose(fp);
}

int main(int argc, char *argv[]) {
// Create a phone book with a maximum of 20 entries
PhoneBook *pb = init(20);

// Insert some entries into the phone book
insert(pb, "Tom", "123-456-7890");
insert(pb, "Mike", "234-567-8901");
insert(pb, "Betty", "345-678-9012");
insert(pb, "Lara", "999-999-9999");
insert(pb, "Alex", "567-119-2347");

// Update Lara's number for example
insert(pb, "Lara", "147-909-8294");

// Print the phone book to the screen
printf("Phone book:\n");
print(pb);

// Dump the phone book to a text file
dump(pb, "phonebook.txt");

// Clean up memory
destroy(pb);

return 0;
}
