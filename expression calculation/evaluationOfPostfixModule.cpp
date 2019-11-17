//=%

//input instance :  "12 13 + 45 -" //space must be provided as delimiter and avoid space at the beginning and end of the postfixExpression 
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include "stackModule.cpp"
#define QSize 5


using namespace std;



int check(char c){

   if ((int(c) >= 48 && int(c)<= 57 ) || (c== '.' ))  //checking for number
	return 1; 
  else if (int(c) == 32 )  //checking for space	
	return 2 ; 
  else if (c == '(')
	return 3;
  else if ( c == ')' )
	return 4;
  else
    return 0;  //return 0 for operators [ +,-,*,/,^]
}




float calculate( string infixExp){



int expLength;
string operand;
stack<string>  valueStack;

int flag;  // 1 if current character is a number , 2 if it is an empty char and 0 if it is an operator

for (int i = 0 ; i < infixExp.length(); i++){
flag = check(infixExp[i]);
if ( flag == 1 ){
    operand += infixExp[i];
}

else if (flag == 2){
   valueStack.push(operand);
    operand = ""; //clear 
}
else {
 
  operand = valueStack.pop();
   
	  switch(infixExp[i]){
	    case '+':  operand =to_string( stof( valueStack.pop() ) + stof(operand)  ); 
										// stof  (string to float ) , stoi (string to int) , to_string(num)
			break;
	    case '-':  operand =to_string( stof(valueStack.pop() ) - stof(operand) ); 
			break;
	    case '/': operand = to_string(stof(valueStack.pop()) / stof(operand)); 
			break;
	    case '*': operand = to_string(stof(valueStack.pop()) * stof(operand)); 
			break;
	    case '^': operand =to_string(pow(stof(valueStack.pop()) , stof(operand))); 
			break;
	    default :
		printf("invalid operator");
		exit(0);
	}

}


}
valueStack.push(operand);


float result = stof(valueStack.pop());
return result;
}
