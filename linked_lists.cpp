#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#ifdef _WIN32
#define WINPAUSE system("pause")
#endif

//craete a linked list

struct node {

	int value;
	struct node* next;
	

	};


void insertlist(struct node **head ,int pos, int value) {

	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->value = value;
	if (pos == 0) {
		newnode->next = *head;
		*head = newnode;
		
	
	
	}
	else {
		struct node* p = *head;
		for (int i = 0; i < pos - 1; ++i) {
			p = p->next;

		}
		newnode->next = p->next;
		p->next = newnode;
	
	}
	
}

void deletelist(struct node** head, int pos){
	struct node* p2;
	if (pos == 0) {
		p2 = *head;
		*head = (*head)->next;
		free(p2);
	}
	else {
		struct node* p = *head;
		for (int i = 0; i < pos - 1; ++i)
		{
			p = p->next;
		}
		p2 = p->next;
		p->next = p->next->next;
		free(p2);
		
	}
	
}

int readlist(struct  node** head, int pos) {


	struct node* p = *head;
	for (int i = 0; i < pos; ++i) {
	
		p = p->next;
	
	
	}
	return p->value;

}



void updatelist(struct  node** head, int pos ,int value) {


	struct node* p = *head;
	for (int i = 0; i < pos && p->next!=NULL ; ++i) {

		p = p->next;


	}
	if(p!=NULL)
		p->value = value;
	
	

}


struct doublenode {


	int value;
	struct doublenode* prev;
	struct doublenode* next;


};




//dir=0 from left to right
//dir=1 from right to left
void double_insertlist(struct doublenode **head, struct doublenode **tail ,int pos, int value , int dir) {
	struct doublenode* newnode = (struct doublenode*)malloc(sizeof(struct doublenode));
	newnode->value = value;
	
	
	if (dir == 0) {
		if (pos == 0) {

			newnode->next = *head;
			*head = newnode;
			newnode->prev = NULL;
			/*
			if(*tail==null)
*tail=newnode;
*/


		}

		else {
			struct doublenode* p = *head;
			for (int i = 0; i < pos - 1; ++i) {
				p = p->next;

			}
			newnode->next = p->next;
			if(p->next!=NULL) p->next->prev = newnode; //kind of creepy if p->next=null
			p->next = newnode;
			newnode->prev = p;

		}
		struct doublenode* temp = *head;
		while (temp->next != NULL)temp = temp->next;
		*tail = temp;
	
	
	}
	else if (dir == 1) {

		if (pos == 0) {

			newnode->prev = *tail;
			(*tail)->next = newnode;
			*tail = newnode;
			newnode->next = NULL;
			/*
			if(*head==null)
			*head
			
			
			
			=newnode;
			*/


		}

		else {
			struct doublenode* p = *tail;
			for (int i = 0; i < pos - 1; ++i) {
				p = p->prev;

			}
			newnode->prev = p->prev;
			if (p->prev != NULL) p->prev->next = newnode; //kind of creepy if p->next=null
			p->prev = newnode;
			newnode->next = p;

		}
		struct doublenode* temp = *tail;
		while (temp->prev != NULL)temp = temp->prev;
		*head = temp;




	}

	

}

void double_deletelist(struct doublenode** head,struct doublenode** tail,int pos ,int dir) {
	struct doublenode* p2;
	if (dir == 0) {
		if (pos == 0) {
			p2 = *head;
				*head = (*head)->next;
				(*head)->prev = NULL;

			free(p2);
		}
		else {
			struct doublenode* p = *head;
			for (int i = 0; i < pos - 1; ++i)
			{
				p = p->next;
			}
			p2 = p->next;
			p->next = p->next->next;
			p->next->prev = p2->prev;
			free(p2);
		}
	}
	else if (dir == 1) {

		if (pos == 0) {
			p2 = *tail;
			*tail = (*tail)->prev;
			(*tail)->next = NULL;

			free(p2);
		}
		else {
			struct doublenode* p = *tail;
			for (int i = 0; i < pos - 1; ++i)
			{
				p = p->prev;
			}
			p2 = p->prev;
			p->prev = p->prev->prev;
			p->prev->next = p2->next;
			free(p2);
		}





	}

}

int double_readlist(struct  doublenode** head, int pos) {


	struct doublenode* p = *head;
	for (int i = 0; i < pos; ++i) {

		p = p->next;


	}
	return p->value;

}



void double_updatelist(struct  doublenode** head,struct doublenode** tail, int pos, int value , int dir) {

	if (dir == 0) {
		struct doublenode* p = *head;
		for (int i = 0; i < pos&& p->next != NULL; ++i) {

			p = p->next;


		}
		if (p!= NULL) {
			p->value = value;

		}
	}
	else if (dir == 1) {

		struct doublenode* p = *tail;
		for (int i = 0; i < pos && p->next != NULL; ++i) {

			p = p->prev;


		}
		if (p!= NULL) {
			p->value = value;

		}
	}



	}







void main(void)
{
	
	struct node* head=NULL;
	
	
	insertlist(&head, 0, 10);
	insertlist(&head, 1, 20);
	insertlist(&head, 2, 30);
	updatelist(&head, 1, 23);
	deletelist(&head, 0);
	struct node* t = head;
	while (t != NULL) {
	
		printf("%d \n", t->value);
		t = t->next;
	}
	
	//initialization
	struct doublenode* head2=NULL;
	struct doublenode* tail=NULL;

/*	

	double_insertlist(&head2,&tail, 0, 10,0);
	double_insertlist(&head2,&tail, 1, 20,0);	
	double_insertlist(&head2, &tail,0, 30, 1);
	double_updatelist(&head2,&tail, 1, 23,0);
	double_deletelist(&head2,&tail, 0,0);
	
	*/
	double_insertlist(&head2, &tail, 0, 3, 0);
	double_insertlist(&head2, &tail, 1, 4, 0);
	double_insertlist(&head2, &tail, 0, 5, 1);
	double_insertlist(&head2, &tail, 0, 6, 1);
	double_insertlist(&head2, &tail, 2, 10, 1);
	double_insertlist(&head2, &tail, 1, 33, 0);
	double_insertlist(&head2, &tail, 4, 8, 1);

	for (int i = 0; i<7; ++i)
		printf("%d \n", double_readlist(&head2, i));
	
	


	WINPAUSE;

}