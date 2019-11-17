//=%
#include <stdio.h>
#include <stdlib.h>
#define MAX 5 
struct node{
int dataItem;
struct node * next; 
};

struct node * getNode(){
struct node * np;
np = (struct node *) malloc(sizeof(struct node)); //malloc() returns address of void type allocated memory. so (struct node *) is required to typecast

printf("enter the data :\t");
scanf("%d",&np->dataItem);
np->next = NULL;
system("clear");
return np;
}

//------function declaration------------  

void insertionAtFirst(struct node **);
void insertionAtLast(struct node **);
void insertionAtAnywhere(struct node **);
void deletionFromFirst(struct node **);
void deletionFromLast(struct node **);
void deletionFromAnywhere(struct node **);
void traversing(struct node *);
void merge(int , int , struct node * heads[], int * );
//**********************************

void main(){
int choice;
int firstList,secondList;
struct node * heads[MAX]; // store the starting address of different linked list 
int count = 0;
int selected = 0; // default selected linked list is first created 

//initializing heads with NULL
for (int i = 0 ; i < MAX ; i++)
	heads[i] = NULL;
system("clear");
while(1){
	printf("\n\nenter your choice : \n");
	printf("1.create New Linked List \n2.select Linked List \n 3.Insertion \n 4.Deletion \n 5.traversing\n6.Merging\n 7.exit\n");
	scanf("%d",&choice);
	system("clear");
	
	
 	if (choice == 1){
	   heads[count++] = getNode();
	}
	else if (choice == 2){
		printf("enter your choice : \n");
		for (int i = 0 ; i < count ; i++)
			printf("%d.%p \n",i,heads[i]);
		scanf("%d",&selected);
	}

	else if (choice == 3){
		
		printf("enter your choice : \n");
		printf("1.At first \n 2.At last \n 3.At anywhere \n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insertionAtFirst(&heads[selected]);
				break;
			case 2: insertionAtLast(&heads[selected]);
				break;
			case 3: insertionAtAnywhere(&heads[selected]);
				break;
			default : printf("\n\tinvalid input\n");
		}

	}
	else if (choice == 4 ){
		printf("enter your choice : \n");
		printf("1.from first \n 2.from last \n 3.from anywhere \n");
		scanf("%d",&choice);	

		switch(choice){
			case 1: deletionFromFirst(&heads[selected]);
				break;
			case 2: deletionFromLast(&heads[selected]);
				break;
			case 3: deletionFromAnywhere(&heads[selected]);
				break;
			default : printf("\n\tinvalid input\n");

		}

	}
	else if (choice == 5){
		traversing(heads[selected]);
	}
	else if (choice == 6){
		for (int i = 0; i < count ; i++)
			printf(" %d.%p \n",i,heads[i]);	
		printf("\nselect two Linked List to be merged\n");
		printf("enter first choice : \t");
		scanf("%d",&firstList);
		printf("enter second choice : \t");
		scanf("%d",&secondList);
		if ( (firstList < count && firstList >= 0 ) && (secondList < count && secondList >= 0 ) )
			merge(firstList,secondList,heads,&count);
	}
	else if (choice == 7){
		exit(0);	
	}
	else {
	 printf("\ninvalid input\n");
	}
	
	
}

}




void insertionAtFirst(struct node ** head){
struct node *newptr;
if ( (*head) == NULL ){
	printf("\nerror to insert at first\n");
	}
else{
	newptr = getNode();
	newptr->next = *head;
	*head = newptr;
}
}

void insertionAtLast(struct node ** head){
struct node * newptr;
struct node * ptr;
if ((*head) == NULL){
   printf("\nerror to insert at last\n");
}
else{
	newptr = getNode();
	ptr = *head;	
	while(ptr->next != NULL)
		ptr = ptr->next;	
	ptr->next = newptr;
}

}


void insertionAtAnywhere(struct node ** head){
int key;
struct node * ptr;
struct node * newptr;

if ((*head)== NULL )
	printf("\nerror to insert at anywhere\n");

else {
	printf("\nenter key value : \t ");
	scanf("%d",&key);
	ptr = (*head);
	while((ptr != NULL) && ptr->dataItem != key)
		ptr = ptr->next;
	if (ptr == NULL)
		printf("\nsorry! no key found\n");
	else {
		newptr = getNode();
		newptr->next = ptr->next;
		ptr->next = newptr; 
	}
}
}


void deletionFromFirst(struct node ** head){
	struct node * ptr;	
	if ((*head)== NULL)
		printf("you haven't selected any linked list \n");
	else{
		printf("%d is removed",(*head)->dataItem);
		ptr = *head;		
		*head = (*head)->next;
		free(ptr);  //memory deallocation 	
	}
}

void deletionFromLast(struct node ** head){
	struct node * ptr;
	struct node * prevptr; //previous pointer
	if ((*head)== NULL)
		printf("you haven't selected any linked list \n");
	else{
		ptr = *head;
		while(ptr->next != NULL){
			prevptr = ptr;
			ptr = ptr->next;		
		}
		printf("%d is removed from the linked list\n",(ptr->dataItem));
		prevptr->next = NULL;
		free(ptr);
	}
}


void deletionFromAnywhere(struct node ** head){
	struct node *ptr;
	struct node * prevptr = NULL;
	
	int key;
	if ((*head)== NULL)
		printf("you haven't selected any linked list \n");
	else{
		printf("\nenter key value : \t");
		scanf("%d",&key);
		ptr = *head;
		while(ptr != NULL && ptr->dataItem != key)
			{	prevptr = ptr;
				ptr = ptr->next;
			}
		if (ptr == NULL)
			printf("\nsorry! NO key value found\n");
		else if ( prevptr == NULL){
			printf("\n%d is removed for the linked list\n",ptr->dataItem);
			*head  = ptr->next;
			free(ptr);
		}
		else{
			printf("\n%d is removed for the linked list\n",ptr->dataItem);
			prevptr->next = ptr->next;
			free(ptr); 			
		}
		
	}

}

void traversing(struct node * head){
	struct node * ptr;
	ptr = head;
	while(ptr->next != NULL){
		printf("  %d -->",ptr->dataItem);
		ptr = ptr->next;
	}
	printf("  %d",ptr->dataItem);
}


void merge(int firstHead,int secondHead, struct node * heads[],int * count){
	struct node * ptr;
	ptr = heads[firstHead];
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = heads[secondHead];
	
	for (int i = secondHead ; i < *count ; i++ )
		heads[i] = heads[i++];	
	(*count)--;
}

//=%
