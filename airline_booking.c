//airline booking
//Raphael Miller

#include <stdio.h>
#include <stdlib.h>

struct linked_node{
	char *name;
	struct linked_node* next;
};

//operation 1 - ticket booking
struct linked_node* ticket_booking(struct linked_node* head, char *name);
//operation 2 - cancel booking
struct linked_node* cancel_booking();
//operation 3 - confirm booking
int confirm_booking();
//operation 4 - display booking
void display_booking(struct linked_node* current);
//operation 5 - quit
void quit();



int main(){

	//read file
	struct linked_node* root = malloc(sizeof(struct linked_node));
	root->name = "head";
	root->next = NULL;
	
	struct linked_node* current = root;
	
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
}

/*	line will contain first name and last name of passenger (last name, first name)
		less then 30 chars long
		creates a node for passenger with relevant information
		append to the end of a linked list*/
struct linked_node* ticket_booking(struct linked_node* head, char *name){
	struct linked_node* current = head;
	if(current->next != NULL){
		ticket_booking(current->next, name);
	}
	else{
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












