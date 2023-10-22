#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Contact cont[100];
	int count=0;
	int choice, searchChoice, statChoice;
	Contact newContact;
	char name[20];
	char phoneNumber[20];
	char birthDateComp[20];
	char updatedChoice;
	float aveAge;
	int oldestAgeIndex, youngestAgeIndex, similarCount;
	printf("Choose option: ");
	do{
		printf("\n1 - Add Contact\n");
		printf("2 - Search contact\n");
		printf("3 - Delete Contact\n");
		printf("4 - Contact Statistics\n");
		printf("5 - Display Contacts\n");
		printf("6 - Exit\n");
		printf("Input choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter name: ");
				scanf("%s", &newContact.name);
				printf("Enter phone number: ");
				scanf("%s", &newContact.phoneNumber);
				printf("Enter email address: ");
				scanf("%s", &newContact.emailAddress);
				printf("Enter date of birth (yyyy-mm-dd): ");
				scanf("%s", &newContact.birthDate);
				addContact(cont, &count, newContact);
				break;
			case 2:
				printf("Choose if you want to search for number or name (1/2): ");
				scanf("%d", &searchChoice);
				if(searchChoice==1){
					printf("Enter phone number to be searched: ");
					scanf("%s", &phoneNumber);
					if(searchByPhoneNumber(phoneNumber, cont, count)==1){
						printf("The number exist.");
					}else{
						printf("The number does not exist\n");
						printf("\nDo you want to add this contact? (y/n)");
						scanf(" %c", &updatedChoice);
						if(updatedChoice=='y'||updatedChoice=='Y'){
							printf("Enter the information of the new contact.\n");
							printf("Enter name: ");
							scanf("%s", &newContact.name);
							printf("Enter phone number: ");
							scanf("%s", &newContact.phoneNumber);
							printf("Enter email address: ");
							scanf("%s", &newContact.emailAddress);
							printf("Enter date of birth: ");
							scanf("%s", &newContact.birthDate);
							updateContact(cont, &count,  newContact);
						}else{
							printf("The contact is not added.\n");
						}
					}
				} else if(searchChoice==2){
					printf("Enter name to be searched: ");
					scanf("%s", &name);
					if(searchByName(name, cont, count)==1){
						printf("The name exist.");
					}else{
						printf("The name does not exist");
					}
				}
				break;
			case 3:
				printf("Enter the name of the contact to be deleted: ");
				scanf("%s", &name);
				deleteContact(name, cont, &count);
				break;
			case 4:
				printf("Please choose:\n");
				printf("1. Finding average age of contacts.\n");
				printf("2. Finding the oldest contact\n");
				printf("3. Finding the young contact\n");
				printf("4. Find how many contacts with similar birthdates\n");
				printf("Input choice: ");
				scanf("%d", &statChoice);
					switch(statChoice){
						case 1:
							aveAge = calculateAverageAge(cont, count);
							printf("The average age for all of the contacts is %.2f", aveAge);
							break;
						case 2:
							oldestAgeIndex = findOldestAge(cont, count);
							printf("The oldest in the contacts is %s with the age of %d", cont[oldestAgeIndex].name, calculateAge(cont[oldestAgeIndex].birthDate));
							printf("\n");
							break;
						case 3:
							youngestAgeIndex = findYoungestAge(cont, count);
							printf("The youngest in the contacts is %s with the age of %d", cont[youngestAgeIndex].name, calculateAge(cont[youngestAgeIndex].birthDate));
							printf("\n");
							break;
						case 4:
							printf("Enter a birthdate to compare (yyyy-mm-dd): ");
							scanf("%s", birthDateComp);
							similarCount = countContactsByBirthdate(birthDateComp, cont, count);
							if(similarCount==0){
								printf("There are zero contacts with similar birth dates\n");
							}else{
								printf("There are %d contacts with similar birth dates.\n", similarCount);
							}
							break;
						default:
							printf("Invalid input.");
							break;
					}
				break;
			case 5:
				displayContact(cont, count);
				break;
			default:
				printf("Invalid choice!");
				break;
			
		}
	}while(choice!=6);
	return 0;
}
