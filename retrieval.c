#include<stdio.h>

#define  NO -999

int Retrieval(int *Shell,int start,int end,int com);
int search(int *Shell,int sum,int com);

int Retrieval(int *Shell,int start,int end,int com){
	
	int temp = (start + end) /2;
	int result;

	if(start > end){
		return NO;
	}

	if(Shell[temp] < com){
		result = Retrieval(Shell,temp+1,end,com);
	}
	else if(Shell[temp] > com){
		result = Retrieval(Shell,start,temp-1,com);
	}
	else if(Shell[temp] == com){
		return temp;
	}
	return result;
}

int search(int *Shell,int sum,int com){
	int i;
	int flag;
    for(i=0;i<sum;i++){
    	if(Shell[i] == com){
    		return i;
    	}
    }
	return NO;
}

void main(){
	int array[200];
	int i;
	int input,output;
	for(i=0;i<100;i++){
		array[i] = i+1;
	}

	scanf("%d",&input);
	output = search(array,100,input);
//	output = Retrieval(array,0,100-1,input);
	if(output == NO){
		printf("the number isn't in the array!\n");

	}
	else{
		printf("the number is in the %d \n",output+1);
	}
	return;
}
