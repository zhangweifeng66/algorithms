#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct tree *PointTree;
typedef PointTree Tree;


void merge(int start,int end, int *array);
Tree createTree(int number);
Tree freeTree(Tree T);
Tree addTree(Tree left,Tree right,Tree T);
void PrintfHuffman(Tree T, char *array, int num);
void PrintHuffman(Tree T, char *array, int num, int flag);
Tree HUffman(int sum,int *array);


struct tree{
	int number;
	PointTree Left;
	PointTree Right;
};


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

Tree createTree(int number)
{
	Tree T;
	T =  malloc(sizeof(struct tree));
	T->number = number;
	T->Left = NULL;
	T->Right = NULL;
	return T;
}

Tree freeTree(Tree T)
{
	if(T ==NULL){
		return NULL;
	}
	T->Right = freeTree(T->Right);
	T->Left = freeTree(T->Left);

	if(T->Right == NULL && T->Left == NULL){
		free(T);
		return NULL;
	}
}

Tree addTree(Tree left,Tree right,Tree T)
{
	
	if(left == NULL || right == NULL)
	{
		return NULL;
	}
	T = malloc(sizeof(struct tree));
	T->number = left->number + right->number;
	T->Left = left;
	T->Right = right;
	return T;
}

void PrintfHuffman(Tree T, char *array, int num)
{
	PrintHuffman(T->Left,array,num,0);
	PrintHuffman(T->Right,array,num,1);
}

void PrintHuffman(Tree T, char *array, int num, int flag){
	char Array[40];
	int i;
	for(i=0;i<num;i++){
		Array[i] = array[i];
	}
	if(flag == 1)
	{	
		Array[num++] = '1';
		printf("%c\n",Array[num-1]);
	}
	else{
		Array[num++] = '0';
		printf("%c\n",Array[num-1]);
	}
	if(T->Left == NULL && T->Right ==NULL)
	{
		Array[num] = '\0';
		printf("%d:%s\n",T->number,Array);
	}
	else{
		PrintHuffman(T->Left,Array,num,0);
		PrintHuffman(T->Right,Array,num,1);
	}
}

Tree HUffman(int sum,int *array){
	int i;
	Tree T;
	int Flag=0;
	int sign1 =0,sign2=1;
	int data[10] = {10,10,20,20,40,60,80,90,30,50};
	sum = 10;
	Tree tree[10];
	merge(0,9,data);
	for(i=0;i<10;i++){
		tree[i] = createTree(data[i]);
		printf("%d\n",tree[i]->number);
	}
	while(sign2 < 10){
		if(Flag == 2)
		{
			if(tree[sign1] -> number <= tree[sign2] -> number && 
				tree[sign1+1] -> number <= tree[sign2] -> number)
			{
				T= addTree(tree[sign1],tree[sign1+1],T);
				Flag = 1;
				//freeTree(tree[sign1]);
				//freeTree(tree[sign1+1]);
				tree[0] = T;
				sign2--;
			}
			else if(tree[sign1] -> number <= tree[sign1+1] -> number)
			{
				T = addTree(tree[sign1],tree[sign2],T);
				//freeTree(tree[sign1]);
				//freeTree(tree[sign2]);
				tree[sign1]  = T;
			}
			else{
				sign1++;
				T = addTree(tree[sign1],tree[sign2],T);
				//freeTree(tree[sign1]);
				//freeTree(tree[sign2]);
				tree[sign1]  = T;
				sign1--;
			}
		}
		else{
			if(sign2+1 >= 10){
				break;
			}
			if(tree[sign2]->number <= tree[sign1] -> number && 
				tree[sign2+1] -> number <= tree[sign1] -> number){
				T = addTree(tree[sign2],tree[sign2+1],T);
				Flag = 2;
				//freeTree(tree[sign2]);
				//freeTree(tree[sign2+1]);
				tree[sign1+1] = T;
				sign2++;
			}
			else{
				T = addTree(tree[sign1],tree[sign2],T);
				//freeTree(tree[sign1]);
				//freeTree(tree[sign2]);
				tree[sign1] = T;
			}
		}
		sign2++;

	}
	if(Flag == 2){
		T= addTree(tree[sign1],tree[sign1+1],T);
		//freeTree(tree[sign1]);
		//freeTree(tree[sign1+1]);
		tree[0] = T;
	}
	else{
		T = addTree(tree[sign1],tree[sign2],T);
		//freeTree(tree[sign1]);
		//freeTree(tree[sign2]);
		tree[0] = T;
		sign2++;
	}
	char Array[40];
	printf("%d\n",tree[0]->Right->number);
	PrintfHuffman(tree[0],Array,0);

}

void main(){
	int sum;
	int array[10];
	HUffman(sum,array);
	return;
}

