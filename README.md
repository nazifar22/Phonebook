# Phonebook
This project is a simple command-line phone book application written in C. It allows users to store, update, retrieve, and export contact information efficiently using dynamic memory allocation.
Each contact is stored as a (name, phone number) pair, with both fields limited to 30 characters. The phone book uses a dynamically allocated array of entries, managed via a custom structure that tracks the number of inserted entries and the total capacity.

Features:
Add new contacts
Update phone numbers for existing contacts
Retrieve a phone number by contact name
Print all contacts to the console
Export all contacts to a text file
Clean up memory with proper allocation and deallocation
The project demonstrates good practices in dynamic memory management, struct usage, and modular design in C.

How to Use
Run the program (compiled binary: main.exe).
The application will:
Create a phone book with space for 20 entries.
Insert 5 example contacts: Tom, Mike, Betty, Lara, and Alex.
Update Lara's phone number to a new one.
Print the list of contacts to the terminal.
Save the list of contacts to a file named phonebook.txt
