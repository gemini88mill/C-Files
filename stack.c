//Stacks 

//Created by Raphael Miller for coding practice
//for foundation exam 

#include <stdlib.h>
#include <stdio.h>

struct stack{
	int top;
	int* contents;
	int maxSize;
	int size; //current size of stack
};

void stackInit(struct stack* myStack, int maxSize);
void push(int value, struct stack* myStack);
int pop(struct stack* myStack);
void display(struct stack* myStack);
int stackEmpty(struct stack* myStack);
int stackFull(struct stack* myStack);

int main(){
	
	struct stack* myStack = malloc(sizeof(struct stack));
	
	//push value to thee stack 
	stackInit(myStack, 10);
	
	printf("%d", myStack->top);
	push(4, myStack);
	//push(12, myStack);
	//push(7, myStack);
	//push(19, myStack);
	
	return 0;
}

void stackInit(struct stack* myStack, int maxSize){
//initializes the stack
	int* newContents = (int*)malloc(sizeof(struct stack) * maxSize);
	//myStack = malloc(sizeof(struct stack));
	
	myStack->contents = newContents;
	myStack->maxSize = maxSize;
	myStack->top = -1;
	

}

void push(int value, struct stack* myStack){
	if(stackFull(myStack)){
		printf("Stack is full");
	}
	
	myStack->top++;
	myStack->contents[myStack->top] = value;
}

int pop(struct stack* myStack){
	if(stackEmpty(myStack)){
		printf("Stack is empty");
	}
	
	return myStack->contents[myStack->top--];
}

int stackEmpty(struct stack* myStack){ 
	return myStack->top < 0;
}
int stackFull(struct stack* myStack){
	return myStack->top >= myStack->maxSize - 1;
}


