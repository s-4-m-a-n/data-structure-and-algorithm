

#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include "stackModule.cpp"
#define MAX 20
using namespace std;

int a [6][2] = {{'+','1'},{'-','1'},{'*','2'},{'/','2'},{'^','3'},{'(','0'}};

int getPrecedence(char c){
    for (int i = 0 ; i < 6 ; i++ ){
        if (char(a[i][0]) == c)
                return int(a[i][1]);
    }
}


int main(){

string infix;
int lengthOfInfix;
stack<char> Operator;
char postfixArray[MAX];
int count =  0;
int precedence;

cout<<"enter infix expression"<<endl;
cin>>infix;

lengthOfInfix = infix.length();


for (int i = 0 ; i < lengthOfInfix ; i++){
    
	if ((int(infix[i]) >= 65 && int(infix[i])<= 90) ||(int(infix[i]) >= 97 && int(infix[i])<= 122))   //A = 65 and B = 90 || a = 97 && z =  122 
        {       
		postfixArray[count++] = infix[i]; 
	}
	else if (infix[i] == ')'){
              
		while (Operator.dataItems[Operator.top] != '(')
		    	postfixArray[count++] = Operator.pop();
		
		Operator.pop(); //to pop '(' from Operator stack;  
	}

	else if (infix[i] == '(' ){
           
		Operator.push(infix[i]);
 		
	}
	else {
         precedence = getPrecedence(infix[i]);
		
		if ((precedence <= getPrecedence(Operator.dataItems[Operator.top])) && (Operator.top != -1)  )
			{       
				postfixArray[count++] = Operator.pop();
				Operator.push(infix[i]);

				}  
		else{
			Operator.push(infix[i]);
				}
        }
}

while (Operator.top != -1 ) //until Operator stack is not empty
    postfixArray[count++] = Operator.pop(); 

cout<<"\n\n";
for (int i = 0 ; i < count; i++)
  cout<<postfixArray[i];

cout<<"\n\n";
return 0;
}
