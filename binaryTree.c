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

void addNewItem(struct node **);
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);

struct node * search(struct node * ,int); //return the memory address of the searched item if exist else Null
void deleteItem(struct node **);
struct node * getParentOfInOrderSuccessor(struct node *); //pass left sub-tree of the required node 
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
	addNewItem(&root);
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
struct node * status = search(root,key);
	if (status != NULL)
	  printf("\n searched item exists \n");
	else 
	  printf("\nsorry ! searched item doesnot exist\n ");
}
else if (choice == 4)
	exit(0);
else 
	printf("\ninvalid input\n");

}



}


void addNewItem(struct node ** root){
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


struct node * search(struct node * root , int key){
 struct node * ptr = root;
 
 if (ptr == NULL)
	return ptr;
 else if (ptr->dataItem > key )
	return search(ptr->left,key);
 else if (ptr->dataItem < key )
	return search(ptr->right,key);
 else 
	return ptr;


}


void deleteItem(struct node ** root){
	int key ;
	struct node* parent = NULL; //key value node's parent
	struct node * ptr = *root; //key value node
	struct node * successorParent; // parent of key value node's successor
system("clear");
printf("enter value that you want to delete \n" );
scanf("%d",&key);

while( ptr->dataItem != key && ptr == NULL){
	parent = ptr;
	if (key < ptr->dataItem)
		ptr = ptr->left;
	else 
		ptr = ptr->right;
}

if (ptr == NULL )
	printf("oops !! searched value doesnot exist");
	
else if (parent->left == ptr) {
	if (ptr->left == NULL && ptr->right == NULL){ //if leaf node
		parent->left = NULL;
		free(ptr);	
	}
	else if (ptr->left == NULL ){ //if it has right child only
		parent->left = ptr->right;
		free(ptr);
	}
	else if (ptr->right == NULL){ //if it has left child only
		parent->left = ptr->left;
		free(ptr);
 	}
	else {	 	//if it has both left and right children 
		
		successorParent = getParentOfInOrderSuccessor(ptr->right);
		parent->left = successorParent->left;

		(successorParent->left)->left = ptr->left;
		successorParent->left = (parent->left)->left;
		(parent->left)->left = ptr->left;
		free(ptr);
		
		
	}
	
else {
	
	if (ptr->left == NULL && ptr->right == NULL){
		parent->right = NULL;
		free(ptr);	
	}
	else if (ptr->left == NULL ){
		parent->right = ptr->right;
		free(ptr);
	}
	else if (ptr->right == NULL){
		parent->right = ptr->left;
		free(ptr);
 	}


}
	

}

}


struct node * getParentOfInorderSuccessor(struct node * root ){ //pass right subs-tree	
	struct node * parent = NULL;	
	while( root->left != NULL)
		{
			parent = root;
			root = root->left;
	}
	return parent;
}

//=%
