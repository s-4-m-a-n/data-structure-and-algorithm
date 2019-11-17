//=%
#include <iostream>
#include <cstdlib>
#include <cstdbool>
#include <cstring>
#include <cmath>
#include "evaluationOfPostfixModule.cpp"

#define MAX 20

using namespace std;

int getPrecedence(char c){
	int a [6][2] = {{'+','1'},{'-','1'},{'*','2'},{'/','2'},{'^','3'},{'(','0'}};
	   
	 for (int i = 0 ; i < 6 ; i++ ){
		if (char(a[i][0]) == c)
		        return int(a[i][1]);
	    }
}





string convertToPostfix(string exp){
	
	stack<char> Operator;
	string postfixExp;
	string operand;
	int precedence;
	int count = 0 ;
	int flag;
	string temp;

for (int i = 0; i < exp.length() ; i++ ){
flag = check(exp[i]);


if (flag == 1 ){
	 operand += exp[i]; //for numbers
}

else{  

        if (operand != ""){
		temp = operand + " ";
		postfixExp += temp;

		operand = "";
	}

	switch(flag){
	    case 2 : break;  //for space 
	    case 3 : Operator.push(exp[i]) ; // for '('
			break;
	    case 4 :while( Operator.dataItems[Operator.top] != '(') // for ')'
			{ 
			   temp = Operator.pop() ;
			   postfixExp += temp + " ";
                          
			}
		      Operator.pop(); // popping '(' for Operator stack
			break; 
	    default :
		precedence = getPrecedence(exp[i]);
		if (precedence <= getPrecedence(Operator.dataItems[Operator.top]) && (Operator.top != -1)){			
			temp = Operator.pop();	
			postfixExp += temp + " ";
			Operator.push(exp[i]);
		}
	        else { 
 			Operator.push(exp[i]);
  			}

	}        	
}

}

if (operand != ""){  //for buffer's expression i.e end operand
	temp = operand + " ";
	postfixExp += temp;  
	operand = ""; 
}


while (Operator.top != -1)
 { 
 if (Operator.top == 0)
	{   
	    	temp =Operator.pop();	 
  		postfixExp += temp ;
	}
 else {
		 temp = Operator.pop();	
		postfixExp += temp + " ";
 }

}

return postfixExp;

}



float eval(string exp){
  exp = convertToPostfix(exp);
  return calculate(exp);
}







