//=%
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

struct node {
int dataItem;
struct node * left;
struct node * right;
};

struct node * getNode(){
	struct node * np;
	np = (struct node *) malloc(sizeof(struct node));
	printf("enter data : \t " );
	scanf("%d",&np->dataItem);
	np->left = NULL;
	np->right = NULL;
	return np;
}


//function declaration --------------------

void addNewNode(struct node **);
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);
void search(struct node *,int);
//---------------------------------------



void main(){

struct node * root = NULL;
int choice;
int key;
system("clear");

while(true){
printf("enter your choice : \n");
printf("1.Add New node \n2.Traverse \n3.searching \n4.exit\n");
scanf("%d",&choice);

if (choice == 1)
	addNewNode(&root);
else if (choice == 2){
	system("clear");
	printf("1.preorder\n2.inorder\n3.postorder\n4.back\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: preOrder(root); 
				break;
		case 2: inOrder(root);
				break;
		case 3: postOrder(root);
				break;
		case 4: continue;		
	
		default: printf("\n invalid input \n");
		
		}

}
else if (choice == 3){
	system("clear");
	printf("\nenter key value : \t");
	scanf("%d",&key);	
	search(root,key);
}
else if (choice == 4)
	exit(0);
else 
	printf("\ninvalid input\n");

}



}


void addNewNode(struct node ** root){
	struct node * newptr;
	struct node * ptr;
	struct node * parent;

	newptr = getNode();

	if (*root == NULL)
		*root = newptr;
	else{
		ptr = *root;
		
		while(ptr != NULL){
			parent = ptr;
			if(newptr->dataItem > ptr->dataItem )
				ptr = ptr->right;
			else 
				ptr = ptr->left;

		}
		
		if ( parent->dataItem > newptr->dataItem)
			parent->left = newptr;
		else
			parent->right = newptr;		
	}
	printf("\nnew node is sucessfully added\n");
}


void preOrder(struct node * root){
	struct node * ptr = root;
	if (ptr != NULL){	
		printf(" %d ",ptr->dataItem);
		preOrder(root->left);
		preOrder(root->right);	
	}
}

void inOrder(struct node * root){
	struct node * ptr = root;
	if(ptr != NULL){
		inOrder(ptr->left);
		printf(" %d ",ptr->dataItem);
		inOrder(ptr->right);
	}
}

void postOrder(struct node * root){
	struct node * ptr = root;
	if(ptr != NULL){
		postOrder(ptr->left);	
		postOrder(ptr->right);
		printf(" %d ",ptr->dataItem);
	}

}

void search(struct node * root,int key){
	struct node * ptr = root;
	
	if (ptr == NULL)
		printf("\nsorry ! searched item doesnot exist\n ");
	else if (ptr->dataItem == key)
		printf("\n searched item exists \n");
	else if (ptr-> dataItem > key)
		search(ptr->left,key);
	else 	
		search(ptr->right,key);
	
}

//=%
