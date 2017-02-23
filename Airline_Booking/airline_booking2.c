//airline booking
//Raphael Miller

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1000

struct linked_node{
	char *name;
	struct linked_node* next;
};

//operation 1 - ticket booking
struct linked_node* ticket_booking(struct linked_node* head, char *name);
//operation 2 - cancel booking
struct linked_node* cancel_booking(struct linked_node** list, char* name);
//operation 3 - confirm booking
int confirm_booking(struct linked_node* root, char* name);
//operation 4 - display booking
void display_booking(struct linked_node* current);
//operation 5 - quit
void quit();



int main(int argc, char **argv){

	//printf("Hello World");

	struct linked_node* root = malloc(sizeof(struct linked_node));
	root->name = "head";
	root->next = NULL;
	
	struct linked_node* current = root;

	//read file
	
	FILE *fp = fopen(argv[1], "r");

	char buff[BUFSIZE];
	char *line;

	//ticket_booking(root, "Joe Montana");

	while(fgets(buff, BUFSIZE - 1, fp) != NULL){
		//reads in file one line at a time, must parse 
		//format "[operation no] [name of customer]"
		char *token;
		char *delim = " ";

		token = strtok(buff, delim);
		int operation = atoi(token);
		
		token = strtok(NULL, delim);
		char *name = token;

		//printf("%s\t", name);
		//printf("%d\n", operation);
		
		switch(operation){
			case 1:
				printf("1\n");
				ticket_booking(root, name);
				break;
			case 2:
				printf("2\n");
				cancel_booking(&root, name);
				break;
			case 3:
				printf("3\n");
				confirm_booking(root, name);
				break;
			case 4:
				printf("4\n");
				display_booking(root);
				break;
			case 5:
				printf("5\n");
				quit();
				break;
			default:
				printf("undocumented operation detected...");		
		}
				
	
	} 

	

	/*
	
	ticket_booking(current, "Joe Montana");
	ticket_booking(current, "Billy Joel");
	ticket_booking(current, "Jim Jimmes");
	ticket_booking(current, "Maui Wowi");
	ticket_booking(current, "Spring Jumper");
	
	cancel_booking(&current, "Spring Jumper");
	
	confirm_booking(current, "Jim Jimmes");
	
	display_booking(current);
	
	confirm_booking(current, "Joe Montana");
	
	quit();
	*/

	
}

/*	line will contain first name and last name of passenger (last name, first name)
		less then 30 chars long
		creates a node for passenger with relevant information
		append to the end of a linked list*/
struct linked_node* ticket_booking(struct linked_node* head, char *name){
	struct linked_node* current = head;
	//printf("name: %s\n", name);
	if(current->next != NULL){
		ticket_booking(current->next, name);
	}
	else{
		printf("selected booking for: %s", current->name);
		current->next = malloc(sizeof(struct linked_node));
		current->next->name = name;
		current->next->next = NULL;
	}
	
	return current->next;

}

/*	delete node from list
	search using name char
	return deleted node 
	free said node*/
struct linked_node* cancel_booking(struct linked_node** list, char* name){
	struct linked_node *temp, *prev;
	
	temp = (*list);
	
	if(temp != NULL && temp->name == name){
		(*list) = temp->next;
		free(temp);
		return (*list);	
	} 

	while(temp != NULL && temp->name != name){
		prev = temp;
		temp = temp->next;	
	}

	if(temp == NULL){
		printf("Booking not found for %s\n", name);
		return NULL;	
	}
	
	printf("Cancel confirmed for %s\n", temp->name);
	prev->next = temp->next;

	free(temp);
}

/*Confirm Booking - finds name of ticketer and 'confirms' said booking*/
int confirm_booking(struct linked_node* root, char* name){
	struct linked_node* current = root;
	
	while(current != NULL){
		if(current->name == name){
			printf("booking confirmed for %s\n", current->name);
			return 1;
		}else{
			current = current->next;
		}
		
	}
	printf("%s booking information not found", name);
	

	return 0;
}

/*Display booking - Prints out passenger list*/
void display_booking(struct linked_node* current){
	while(current != NULL){
		printf("%s\n", current->name);
		current = current->next;
	}
}

void quit(){
	printf("\nThank you.\n");
	exit(0);
}












