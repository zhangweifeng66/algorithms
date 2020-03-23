#include<stdio.h>




void merge(int start,int end, int *array);



void merge(int start,int end, int *array){
	int middle = (start+end)/2;
	int sum = end -start+1;
	
	int i,k,j;
	if(start >= end){
		return;
	}
	else{
		merge(start,middle,array);
		merge(middle+1,end,array);
	}
	
	int iArray[sum];
	
	i = start;
	j = middle+1;
	k = 0;
	while(i<=middle && j<=end){
		if(array[i] < array[j]){
			iArray[k++] = array[i++];
		}
		else{
			iArray[k++] = array[j++];
		}
	}
	if(i > middle && j <=end){
		while(j<=end){
			iArray[k++] = array[j++];
		}
	} 
	else if(j>end && i<=middle){
		while(i<=middle){
			iArray[k++] = array[i++];
		}
	}
	
	j = start;
	for(i=0;i<k;i++){
		array[j++] = iArray[i];
	}
	return;
}

void main(){
	int i;
	int array[200];
	for(i=0;i<200;i++){
		array[i] = 300-i;
	}
	merge(0,199,array);
	for(i=0;i<200;i++){
		printf("%d ",array[i]);
		if(i % 20 == 0){
			printf("\n");
		}
	}
	return;
}

