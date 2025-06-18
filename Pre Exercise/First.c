//CH.SC.U4CSE24102
//To print the first N natural numbers
#include<stdio.h>

int main(){
    printf("This program prints the first N natural numbers.\n");
    printf("Done by CH.SC.U4CSE24102\n");
	int N;
	printf("Enter any positive integer");
	scanf("%d",&N);
	if(N<=0){
		printf("Please enter any positive integer greater than 0. \n");
		return 1; // exit program with a error code
	}

	printf("The first %d natural numbers are: \n",N);
	for(int i = 1;i<=N;i++){
		printf("%d ",i);
	}
	printf("\n");
	return 0;
	
}
