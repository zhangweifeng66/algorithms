#include<stdio.h>
#include<stdlib.h>
#define Nan  9999;

typedef struct Matrix *matrix; 
typedef matrix AP;
typedef struct div_Matrix *division; 
typedef division DP;


struct Matrix
{
	int Point; //第几个矩阵
	int colum;
	int row;
};

struct div_Matrix
{
	long int num;
	int division;
};

AP createAP(AP AP_Matrix, int num);
DP createDP(DP Num_Matrix,int num);
long int Ap_run(AP AP_Matrix,DP Num_Matrix,int num);
void printf_division(DP Num_Matrix,int front,int rear,int num);

int main(){
    AP AP_Matrix;
    DP Num_Matrix; 
    int array[100];
    int i=0;
    int num;
	long int end;
    scanf("%d",&num);
    if(num > 100){
    	printf("the Matrix is too many\n");
    	return 0;
    } 
    for(i=0;i<num;i++){
    	scanf("%d",&array[i]);
	}
    AP_Matrix= createAP(AP_Matrix,num);
    num = num-1;
    for(i=0;i<num;i++){

    	AP_Matrix[i].Point = i+1;
    	AP_Matrix[i].colum = array[i];
    	AP_Matrix[i].row = array[i+1];

    }
    Num_Matrix =  createDP(Num_Matrix,num*num);
	for(i=0;i<num;i++){
		Num_Matrix[i*num+i].num =0;
		Num_Matrix[i*num+i].division = i;
	}
    end = Ap_run(AP_Matrix,Num_Matrix,num);
    printf("the min of matrix is %d\n",end);
    printf_division(Num_Matrix,0,num-1,num);
    free(AP_Matrix);
    free(Num_Matrix);

}

AP createAP(AP AP_Matrix,int num){
	AP_Matrix = malloc(sizeof(struct Matrix)*num);
	if(AP_Matrix == NULL){
		return NULL;
	}
	return AP_Matrix;
}

DP createDP(DP Num_Matrix,int num){
	int i;
	Num_Matrix = malloc(sizeof(struct div_Matrix)*num);
	if(Num_Matrix == NULL){
		return NULL;
	}

	return Num_Matrix;
}

long int Ap_run(AP AP_Matrix,DP Num_Matrix,int num){
	int i,j,k,r;
	int min;

	for(r=2;r<=num;r++)
	{
		for(i=0;i<=num-r;i++)
		{
			j = i+r-1;
			min = AP_Matrix[i].colum * AP_Matrix[i+1].colum * AP_Matrix[j].row 
			    +Num_Matrix[(i+1)*num + j].num;
			Num_Matrix[i*num+j].division = i;
			for(k=i+1;k<=j-1;k++)
			{
				if(min > AP_Matrix[i].colum * AP_Matrix[k].row * AP_Matrix[j].row
				        + Num_Matrix[i*num + k].num + Num_Matrix[(k+1)*num + j].num)
				{
					min = AP_Matrix[i].colum * AP_Matrix[k].row * AP_Matrix[j].row
				        + Num_Matrix[i*num + k].num + Num_Matrix[(k+1)*num + j].num; 
		            Num_Matrix[i*num+j].division = k;
				}
			}
			Num_Matrix[i*num+j].num = min;
		}
	}
	return Num_Matrix[num-1].num;
}

void printf_division(DP Num_Matrix,int front,int rear,int num){
	int division;
	division = Num_Matrix[front*num+rear].division;
	if(front == rear){
		printf("%d",front+1);
		return;
	}
	printf("(");
	printf_division(Num_Matrix,front,division,num);
	printf_division(Num_Matrix,division+1,rear,num);
	printf(")");
}









