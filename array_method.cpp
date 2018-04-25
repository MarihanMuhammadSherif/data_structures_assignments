#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#ifdef _WIN32
#define WINPAUSE system("pause")
#endif
#define MAX 4


//stack using array
void push(int stack[], int* top, int value) {
	if (*top < MAX - 1) {
		
		stack[++(*top)] = value;
	}
}
int pop(int stack[], int* top) {


	if (*top < 0) {
		return -1;
	}
	else {
		--(*top);
		return stack[*top + 1];
	}


}



void enqueue(int* queue, int* top ,int value) {

	if(*top <MAX-1)
	{
		queue[++(*top)] = value;
			
	}


}

int dequeue(int* queue, int*top) {

	if (*top < 0)
	{
		return -1;
	}
	else {
		int value = queue[0];
		for (int i = 1; i < MAX; ++i) {
			queue[i - 1] = queue[i];

		}
		--(*top);

		return value;
	}
}

void circular_enqueue(int* queue, int *start ,int* top, int* circular_top, int value) {
	
	if(*top<MAX-1){
		queue[++(*top)] = value;
	}
	else if (*start>0 && *circular_top < (*start) - 1) {
	
		queue[++(*circular_top)] = value;
		
	}



}

int circular_dequeue(int* queue, int *start, int* top, int* circular_top) {
	
	if (*top < 0 )
	{
		return -1;
	}
	else {
		int value = queue[*start];
		if (*start < *top)
		{
			++(*start);
		}
		else {
			*start = 0;
			*top = *circular_top;
		}
	
		return value;
	
	}



}

void printqueue(int queue[], int top) {

	for (int i = 0; i <= top;++i) {
	
		printf("%d \t", queue[i]);
	}
	printf("\n");

}
void print_circularqueue(int queue[], int start,int top,int circular_top) {

	for (int i = start; i <= top; ++i) {

		printf("%d \t", queue[i]);
	
	
	}
	for (int i = 0; i <= circular_top; ++i) {
	
		printf("%d \t", queue[i]);
	}

	printf("\n");

}
void main(void) {

	//test stack with array implementation
	
	/*int stack[MAX];
	int topstack = -1;
	push(stack, &topstack, 5);
	push(stack, &topstack, 10);
	push(stack, &topstack, 20);
	push(stack, &topstack, 30);
	push(stack, &topstack, 15);
	printf("%d \n", pop(stack, &topstack));
	printf("%d \n", pop(stack, &topstack));
	printf("%d \n", pop(stack, &topstack));
	printf("%d \n", pop(stack, &topstack));
	printf("%d \n", pop(stack, &topstack));
	*/

	//test queue with array implementation
	
	/*int queue[MAX];
	int topqueue = -1;
	enqueue(queue, &topqueue, 10);
	enqueue(queue, &topqueue, 11);
	enqueue(queue, &topqueue, 12);
	
	printqueue(queue, topqueue);
	
	printf("%d \n", dequeue(queue, &topqueue));
	printqueue(queue, topqueue);
	
	printf("%d \n", dequeue(queue, &topqueue));
	printqueue(queue, topqueue);

	printf("%d \n", dequeue(queue, &topqueue));
	printqueue(queue, topqueue); 
	
	*/

	//test circular queue
	int queue[MAX];
	int start = 0;
	int top = -1;
	int circular_top = -1;
	circular_enqueue(queue, &start, &top, &circular_top, 1);
	printf("%d \n", circular_dequeue(queue, &start, &top, &circular_top));


	circular_enqueue(queue, &start, &top, &circular_top, 2);
	printf("%d \n", circular_dequeue(queue, &start, &top, &circular_top));

	circular_enqueue(queue, &start, &top, &circular_top, 3);
	circular_enqueue(queue, &start, &top, &circular_top, 4);
	circular_enqueue(queue, &start, &top, &circular_top, 5);
	circular_enqueue(queue, &start, &top, &circular_top, 6);
	print_circularqueue(queue, start, top, circular_top);


	WINPAUSE;
}