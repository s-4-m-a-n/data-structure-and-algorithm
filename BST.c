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
	printf("\nenter data : \t " );
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
void deleteItem(struct node **);
void displayRoot(struct node *);
struct node * search(struct node * ,int); //return the memory address of the searched item if exist else Null

struct node * getParentOfInOrderSuccessor(struct node *); //pass left sub-tree of the required node 
//---------------------------------------



void main(){

struct node * root = NULL;
int choice;
int key;
system("clear");

while(true){
printf("\nenter your choice : \n");
printf("1.Add New node \n2.display Root Node \n3.Traverse \n4.searching \n5.Delete Item \n6.exit\n");
scanf("%d",&choice);

if (choice == 1)
	addNewItem(&root);
else if (choice == 2)
	displayRoot(root);
else if (choice == 3){
	system("clear");
	printf("\n1.preorder\n2.inorder\n3.postorder\n4.back\n");
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
else if (choice == 4){
	system("clear");
	printf("\nenter key value : \t");
	scanf("%d",&key);	
struct node * status = search(root,key);
	if (status != NULL)
	  printf("\n searched item exists \n");
	else 
	  printf("\nsorry ! searched item doesnot exist\n ");
}
else if (choice == 5)
	deleteItem(&root);
else if (choice == 6)
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
		printf("\n");
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
	
	struct node * parent= NULL; //key value node's parent
	struct node * ptr;
	struct node * successorParent; // parent of key value node's successor
	struct node * inorderSuccessor;
	int key ;

ptr = (*root); //key value node

system("clear");
printf("\nenter value that you want to delete \n" );
scanf("%d",&key);



while( (ptr != NULL) && (ptr->dataItem) != key){   //ptr !=NULL  core dump
	parent = ptr;
	ptr = key < ptr->dataItem ? ptr->left : ptr->right;
/*
	if ( (ptr->dataItem) > key)
		ptr = ptr->left;
	else 
		ptr = ptr->right;
*/
}


if (ptr == NULL )
	printf("\noops !! searched value doesnot exist\n");
else if (parent == NULL ){  // searched value is of root node
		
	if (ptr->left == NULL && ptr->right == NULL){ //if leaf node
		*root = NULL;
		free(ptr);	
	}
	else if (ptr->left == NULL){ //if it has right child only
		*root = ptr->right;
		free(ptr);
	}
	else if (ptr->right == NULL){ //if it has left child only
		*root = ptr->left;
		free(ptr);
 	}
	else{
		successorParent = getParentOfInOrderSuccessor(ptr->right); 
		
		if(successorParent == NULL){
			 *root = ptr->right;
			 (*root)->left = ptr->left;
			free(ptr);
			}
		else{

		inorderSuccessor = successorParent -> left;
		successorParent->left = inorderSuccessor->right;
		
		inorderSuccessor->left = ptr->left;
		inorderSuccessor->right = ptr->right;
		*root =  inorderSuccessor; //ptr = inorderSuccessor
		free(ptr);
		}
	    }
     }
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
	
		if(successorParent == NULL){
			 parent->left = ptr->right;
			 (parent->left)->left = ptr->left;
			free(ptr);
			}
		else{
		inorderSuccessor = successorParent->left;
		parent->left = inorderSuccessor;
		
		successorParent->left = inorderSuccessor->right; //**
		inorderSuccessor->left = ptr->left;
		inorderSuccessor->right = ptr->right;
		free(ptr);

		}
		
	}
  }
	
else { // parent->right == ptr 
	
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
	else {	 	//if it has both left and right children 
		
		successorParent = getParentOfInOrderSuccessor(ptr->right);
		
		if(successorParent == NULL){
			 parent->right = ptr->right;
			 (parent->right)->left = ptr->left;
			free(ptr);
			}
		else{
		inorderSuccessor = successorParent->left;
		parent->right = inorderSuccessor;
		
		successorParent->left = inorderSuccessor->right; //**
		inorderSuccessor->left = ptr->left;
		inorderSuccessor->right = ptr->right;
		free(ptr);
		}	
	}
  }
	

}



struct node * getParentOfInOrderSuccessor(struct node * root ){ //pass right subs-tree	
	struct node * parent = NULL;
	while( root->left != NULL)
		{
			parent = root;
			root = root->left;
	}
	return parent;
}

void displayRoot(struct node * root){
	system("clear");
	printf("Root : %d\n",root->dataItem);
}

//=%
