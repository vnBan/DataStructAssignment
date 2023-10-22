typedef struct Contact{
	char name[20];
	char phoneNumber[15];
	char emailAddress[20];
	char birthDate[20];
} Contact;

// Function to add a new contact. Maintain that phoneNumber must be unique
void addContact(Contact contacts[], int *count, Contact newContact);

// Function to search for a contact by name
int searchByName(char name[], Contact contacts[], int count);

// Function to search for a contact by phone number
int searchByPhoneNumber(char phoneNumber[], Contact contacts[], int count);

// Function to update an existing contact, if not found display the message "<<phoneNumber>> not existing." Add ask the question "Do you wan to add the contact?[Y/N]", if the answer is yes add the contact.
void updateContact(Contact contacts[], int *count,Contact updatedContact);

// Function to delete all the name
void deleteContact(char name[], Contact contacts[], int *count);

// Function to calculate the average age of all contacts
float calculateAverageAge(Contact contacts[], int count);

// Function to find the oldest contact's age
int findOldestAge(Contact contacts[], int count);

// Function to find the youngest contact's age
int findYoungestAge(Contact contacts[], int count);

// Function to count the number of contacts with the same birthdate
int countContactsByBirthdate(char birthdate[],Contact contacts[], int count);
