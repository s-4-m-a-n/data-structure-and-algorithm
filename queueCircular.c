//=%

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

struct Queue{
	int dataItems[MAX];
	int front;
	int rear;
};


void enqueue(struct Queue *);
void dequeue(struct Queue *);
void show(struct Queue);

void main(){
int choice;
struct Queue Q;
Q.front = 0;
Q.rear = 0;

while(true){
 printf("Enter your choice \n");
 printf("1.enqueue \n");
 printf("2.dequeue \n");
 printf("3.show \n");
 printf("4.EXIT \t\t");
 scanf("%d",&choice);

system("clear");
switch(choice){
  case 1: enqueue(&Q);
  			break;
  case 2: dequeue(&Q);
  			break;
  case 3: show(Q);
  			break;
  case 4: exit(0);
  	
  default : printf("invalid input\n");
}

}

}

void enqueue(struct Queue * Q){
	printf("front :%d  rear :%d ",Q->front,Q->rear);
if (((Q->rear)+1)%MAX == (Q->front)){
		printf("Queue is full\n");
	 }
	
else{
		Q->rear = ((Q->rear)+1) % MAX;
		printf("enter data to insert\n");
		scanf("%d",&Q->dataItems[Q->rear]);
		
	}
}


void dequeue (struct Queue * Q){
	if (Q->front == Q->rear)
		printf("queue is empty\n");
	else{

		Q->front = ((Q->front)+1) % MAX;		
		printf("%d is dequeued\n",Q->dataItems[Q->front]);
		
	}
}

void show(struct Queue Q){
   for (int i = (Q.front+1)%MAX ; i != (Q.rear+1)%MAX; i = (i+1)%MAX){
       printf("%d  ",Q.dataItems[i]);
   }
}
