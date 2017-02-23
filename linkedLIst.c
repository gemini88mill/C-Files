//Linked lists in c 

#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node* next;
};

void insert(struct node* node, int data);
void delete(struct node* node);
void print_list(struct node* node);
void search(struct node* node, int data);

int main(){
	//linked list main 
	
	struct node* head;
	struct node* current;
	
	head = malloc(sizeof(struct node));
	head->data = 1;
	head->next = NULL;
	
	current = head;
	
	insert(current, 34);
	insert(current, 23);
	insert(current, 1);
	insert(current, 56);
	insert(current, 2);
	print_list(current);
}

void insert(struct node* node, int data){
	struct node* current = node;
	
	while(current->next != NULL){
		current = current->next;	
	}
	
	current->next = malloc(sizeof(struct node));
	current->next->data = data;
	current->next->next = NULL;
	
}

void print_list(struct node* node){
	struct node* current = node;
	
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;	
	}
}


