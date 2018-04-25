#include<stdio.h>
#include<stdlib.h>


#ifdef _WIN32
#define SYSTEMPAUSE system("pause")
#endif


struct node{
	int value;
	struct node* next;

};

//stack
void push(struct node** head,int value) {


	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->value = value;
	
		newnode->next = *head;
		*head = newnode;
		
}



int pop(struct node** head) {
//read then delete
	if (*head == NULL)
		return 0;
	{
		int value = (*head)->value;
		struct node* p2;
		p2 = *head;
		*head = (*head)->next;
		free(p2);

		return value;
	}
}

//queue



void enqueue( struct node** head, struct node** tail , int value) {
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->value = value;
	if (*head == NULL && *tail == NULL) {
	
		*head = newnode;
		*tail = newnode;
		
	
	}
	else {
		
		(*tail)->next = newnode;
		*tail = newnode;
	
	
	}
	newnode->next = NULL;

}



int dequeue(struct node** head,struct node** tail){
	
	int value;
	if (*head == NULL || *tail == NULL) {
	
		value=-1;

	}
	else {
	
		struct node* p = *head;
		value = (*head)->value;
		*head = (*head)->next;
		free(p);			
	
	}
	return value;
	}

void printqueue(struct node* head, struct node* tail) {

	struct node* temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%d \t", temp->value);
		temp = temp->next;
	}
	printf("\n");

}

void printstack(struct node* head) {

	struct node* temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%d \t", temp->value);
		temp = temp->next;
	}
	printf("\n");

}


void main(void) {



	struct node* head = NULL;
	struct node* tail = NULL;
	

	//test stack linked list
	push(&head, 5);
	push(&head, 6);
	push(&head, 10);
	printf("%d \n",pop(&head));
	printstack(head,tail);
	printf("%d \n",pop(&head));
	printstack(head, tail);
	printf("%d \n", pop(&head));
	printstack(head, tail);
	
	//test queue linked list 
	enqueue(&head, &tail, 5);
	enqueue(&head, &tail, 6);
	enqueue(&head, &tail, 10);
	printf("%d \n",dequeue(&head, &tail));
	printqueue(head, tail);
	printf("%d \n", dequeue(&head, &tail));
	printqueue(head, tail);
	printf("%d \n", dequeue(&head, &tail));
	printqueue(head, tail);




	SYSTEMPAUSE;


}