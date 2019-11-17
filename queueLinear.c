//=%
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

struct Queue {

int dataItems[MAX];
int front;
int rear;
};


void enqueue(struct Queue *);
void dequeue(struct Queue *);
void dequeueWithShift(struct Queue *);
void show(struct Queue);

void main(){
int choice;

struct Queue Q;
Q.rear = -1;
Q.front = 0; 

while(true){


printf("enter your choice \n");
printf("1.enqueue \n");
printf("2.dequeue \n");
printf("3.dequeueWithShift \n");
printf("4.show \n");
printf("5.exit \t\t");

scanf("%d",&choice);

system("clear");
switch(choice){
	case 1 : enqueue(&Q); 
		 break;

	case 2 : dequeue(&Q);
		 break;

	case 3 : dequeueWithShift(&Q);
		break;

	case 4 : show(Q);
		break;

	case 5 : exit(0);
			
	default : printf("invalid input \n");
}



}


}

void enqueue(struct Queue * Q){
int data;

if (Q->rear == MAX-1)
	printf("queue is full \n");
else{
printf("enter data to be enqueued \n");
scanf ("%d",&data);

Q->dataItems[++(Q->rear)] = data;
 }

}

void dequeue(struct Queue *Q){
if (Q->rear < Q->front)
	printf("queue is empty \n");
else{
	printf("%d is dequeued \n",Q->dataItems[(Q->front)++]);

   }
}

void dequeueWithShift(struct Queue *Q){
if (Q->rear == -1)
	printf("queue is empty \n");
else{

printf("%d is dequeued \n",Q->dataItems[Q->front]);
//shifting
for (int i=0; i <= (Q->rear-1) ; i++ ){
	Q->dataItems[i] = Q->dataItems[i+1];
}

(Q->rear)--;
}

}


void show(struct Queue Q){
for(int i = Q.front ; i <= Q.rear ; i++){
printf("%d  ",Q.dataItems[i]);
}
printf("\n");

}
