//=%

#include <stdio.h>
#include <stdlib.h>
#define MAX  5

struct stack{

int dataItems[MAX];
int top;

};


void push(struct stack * ,int);
int pop(struct stack * );
void traverse(struct stack);



void push(struct stack *st,int data){

if (st->top == MAX-1){
printf("stack is full");
}
else{
(st->top)++;
st->dataItems[st->top]= data;
}

}


int pop (struct stack *st){
if (st->top == -1){
 printf("stack is empty");
 return -100;
}
else{
return st->dataItems[(st->top)--];
}
}


void traverse(struct stack st){
system("clear");
while(st.top != -1)
  printf("%d\n",st.dataItems[(st.top)--]);
}

