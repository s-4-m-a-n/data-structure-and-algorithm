
//=%
#include <stdio.h>

void move(char s , char t , char d , int n ){
	if ( n == 1){
		printf("MOVE disk %d from %c to %c\n",n,s,d);
	}
	else if ( n > 1){
			move(s,d,t,n-1);
			printf("MOvE disk %d from %c to %c\n",n,s,d);
			move(t,s,d,n-1);		
			}
}


void main(){

int n;
char sourcePeg = 'A';
char temporaryPeg = 'B';
char destinationPeg = 'C';

printf("enter the number of disks");
scanf("%d",&n);

move(sourcePeg,temporaryPeg,destinationPeg,n);

}
