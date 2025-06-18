//CH.SC.U4CSE24102
// To find the sum of N natural numbers

#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("This program finds the sum of first N natural numbers.\n");
    printf("Done by CH.SC.U4CSE24102\n");
	int number;
	int sum = 0;
	printf("Please Enter the natural number upto which you wish to do addition: ");
	scanf("%d",&number);
	
	if(number<0){
		printf("Please enter a positive number greater than 0");
		return 1;
	}
	for(int i = 0;i<=number;i++){
		sum+= i;

	}
	printf("The result of first %d natural numbers is %d \n",number,sum);
	return 0;
}
