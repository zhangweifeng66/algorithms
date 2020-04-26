#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Bag *bag;
typedef bag bagPoint;

void BagValue(int n,bag basis);

struct bag
{
	int weight;
	int value;
};


void main()
{
	struct Bag array[4];
	array[1].weight = 2;array[1].value = 1;
	array[2].weight = 3;array[2].value = 3;
	array[3].weight = 4;array[3].value = 5;
	array[4].weight = 7;array[4].value = 9;
	BagValue(4,array,10);
}

void BagValue(int n,bag basis,int request)
{
	n = n+1;
	request = request +1;
	int F[n][request];
	int I[n][request];
	int i,j;
	int Value;
	for(i=0;i<n;i++)
	{
		F[i][0] = 0;
		I[i][0] = 0;
	}
	for(j=0;j<request;j++)
	{
		F[0][j] = 0;
		I[0][j] = 0;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<request;j++)
		{
			if(j < basis[i].weight) 
			{
				F[i][j] = F[i-1][j];
				I[i][j] = I[i-1][j];
				continue;
			}
			Value = F[i][j-basis[i].weight] + basis[i].value
			if(F[i-1][j] < Value)
			{
				F[i][j] = Value;
				I[i][j] = i;

			}
			else
			{
				F[i][j] = F[i-1][j];
				I[i][j] = I[i-1][j];
			}
		}
	}
	printf("%d\n",F[n-1][request-1]);
    j = request-1;
    i = n-1;
    while(j>=1){
    	pritnf("%d ",I[i][j]);
    	
    	j = j - basis[i].weight;
    	i = I[i][j];
    }
}



