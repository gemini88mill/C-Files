//deck of cards.c

/*	By: Raphael Miller
	The concept of this program is to create a program that emulates a deck of cards
	the cards were put into a stack and distributed to players in groups of five. Once the
	deck is empty the discarded cards (players can only have 5 cards at a time) will be
	loaded up with the discarded card. */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 52 // deck of cards size

void push(int *top, int *stack, int data);	//function prototypes
int pop(int *top, int *stack);
int peek(int *top, int *stack);
int empty(int *top);
int full(int *top, int *stack);
void top(int *top);

void create_deck();
void distribute_cards();

int main(){

	int stack[MAXSIZE];
	int top;

	create_deck(&top, &stack);
	distribute_cards(&top, &stack);

	//cheater
	printf("next card = %d\n", peek(&top, &stack));
	printf("top test: %d", top);

	return 0;
}

void create_deck(int *top, int *stack){
	//set top to -1
	*top = -1;

	//fill deck
	int i;
	for(i = 0; i < MAXSIZE; i++){
		push(top, stack, i + 1);
	}
}

void distribute_cards(int *top, int *stack){
	//distribute the cards to players.
	int i, j, num_players = 5;
	for(i = 0; i < num_players; i++){
		printf("Distributing 5 cards to players\n");
		for(j = 0; j < 5; j++){
			pop(top, stack);
		}
	}
}

void push(int *top, int *stack, int data){
	//pushes data to the list, increases the list by 1
	//printf("top test: %d", *top);
	if(!full(top, stack)){
		//stack isnt full
		*top = *top + 1;
		int topVal = *top;
		stack[topVal] = data;

	}else{
		printf("Stack is full :(, to many cards");
	}
}

int pop(int *top, int *stack){
	if(empty(top)){
		printf("Stack empty!!!!");
	}else{
		int topVal = *top;
		*top = *top - 1;
		return stack[topVal];
	}
}
int peek(int *top, int *stack){
		//look at next card
		int topVal = *top;
		return stack[topVal];

}

int empty(int *top){
		if(*top == -1){
			return 1;
		}else return 0;
}

int full(int *top, int *stack){
	if(*top == MAXSIZE){
		return 1;
	}else {
		return 0;
	}
}

void top(int *top){
		printf("%d", *top);
}
