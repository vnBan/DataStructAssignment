#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "contact.h"

void displayContact(Contact contacts[], int count){
	int i;
	printf("\nCONTACTS:");
	for(i=0;i<count;i++){
		printf("\n");
		printf("Name: %s\n", contacts[i].name);
		printf("Phone number: %s\n", contacts[i].phoneNumber);
		printf("Email: %s\n", contacts[i].emailAddress);
		printf("Date of birth: %s\n", contacts[i].birthDate);
		printf("\n");
	}
}
void addContact(Contact contacts[], int *count, Contact newContact){
	contacts[(*count)]=newContact;
	(*count)++;
}
int searchByName(char name[], Contact contacts[], int count){
	int i = 0;
	for(i=0;i<count;i++){
		if(strcmp(contacts[i].name, name)==0){
			return 1;
		}
	}
	return 0;
}
int searchByPhoneNumber(char phoneNumber[], Contact contacts[], int count){
	int i = 0;
	for(i=0;i<count;i++){
		if(strcmp(contacts[i].phoneNumber, phoneNumber)==0){
			return 1;
		}
	}
	return 0;
}

void updateContact(Contact contacts[], int *count, Contact updatedContact){
	contacts[(*count)]=updatedContact;
	(*count)++;
}

void deleteContact(char name[], Contact contacts[], int *count){
	int i, index = 0;
	
	for(i=0;i<*count;i++){
		if(strcmp(contacts[i].name, name)==0){
			index = i;
		}
	}
	
	if(*count==0){
		printf("Contacts is empty.");
	}
	else if(index==0){
		printf("%s does not exists.", name);
	}else{
		for(i=index;i<*count;i++){
			contacts[i] = contacts[i+1];
			(*count)--;
		}
		printf("Contact deleted.");
	}
}

int calculateAge(const char* birthDate){
	int year, month, day;
	sscanf(birthDate, "%d-%d-%d", &year, &month, &day);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int currentYear = tm.tm_year + 1900;
	int currentMonth = tm.tm_mon + 1;
	int currentDay = tm.tm_mday;
	
	int age = currentYear - year;
	if(currentMonth<month||(currentMonth==month&&currentDay<day)){
		age--;
	}
	return age;
}

float calculateAverageAge(Contact contacts[], int count){
	int i;
	float sum = 0;
	for(i=0;i<count;i++){
		int age = calculateAge(contacts[i].birthDate);
		sum = sum + age;
	}
	float average = sum / count;
	return average;
}

int findOldestAge(Contact contacts[], int count){
	int i;
	int oldestAge = calculateAge(contacts[0].birthDate);
	for(i=0;i<count;i++){
		int age = calculateAge(contacts[i].birthDate);
		if(oldestAge<age){
			oldestAge = age;
			return i;
		}
	}
}

int findYoungestAge(Contact contacts[], int count){
	int i;
	int youngestAge = calculateAge(contacts[0].birthDate);
	for(i=0;i<count;i++){
		int age = calculateAge(contacts[i].birthDate);
		if(age<youngestAge){
			youngestAge = age;
			return i;
		}
	}
}

int countContactsByBirthdate(char birthdate[],Contact contacts[], int count){
	int countSimilar = 0;
	int i;
	for(i=0;i<count;i++){
		if(strcmp(birthdate, contacts[i].birthDate)==0){
			countSimilar++;
		}
	}
	return countSimilar;
}
