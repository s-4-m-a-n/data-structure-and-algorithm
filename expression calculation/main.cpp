#include <iostream>
#include <cstring>
#include "evaluationOfInfixExp.cpp"  //includes functions :  eval( <string>) && convertToPostfix( <string> )

using namespace std;

int main(){

string exp;

cout<<"\n\nenter any expression : \t ";
cin>>exp;

cout <<" \n The result is : " << eval(exp)<<endl; 

return 0;
}
