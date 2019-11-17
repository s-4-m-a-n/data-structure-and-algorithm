//=%

#include <stdio.h>
#include <stdlib.h>
#define MAX  5

struct stack{

int dataItems[MAX];
int top;

};


void push(struct stack *);
void pop(struct stack * );
void traverse(struct stack);


void main(){
int choice;
struct stack st;
st.top = -1;

while(1){
// system("clear");
 printf("Choose option\n");
 printf("1.push\n");
 printf("2.pop\n");
 printf("3.show \t");

 scanf("%d",&choice);

switch(choice){
	case 1: push(&st);
		break;
	case 2: pop(&st);
		break;
	case 3: traverse(st);
		break;
	default: printf("\ninvalid input \n");
	}

     }

}




void push(struct stack *st){


if (st->top == MAX-1){
printf("stack is full");
}
else{
(st->top)++;
printf("enter item to be pushed \n");
scanf("%d",&(st->dataItems[st->top]));
}

}


void pop (struct stack *st){
if (st->top == -1){
 printf("stack is empty");
}
else{
printf("%d is poped",st->dataItems[(st->top)--]);
}

}


void traverse(struct stack st){
system("clear");
while(st.top != -1)
  printf("%d\n",st.dataItems[(st.top)--]);


}

