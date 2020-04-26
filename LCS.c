#include<stdio.h>
#include<stdlib.h>

int SideMax(int x,int y);
void LCSoutput(int n, int m,int* A1,int* A2,int * B);
void LCS(int n, int m,int* A1,int* A2);



void main()
{
	int n,m;
	int i;
	int *A1,*A2;
	printf("the length of array is %d",&n);
	A1 = malloc(sizeof(int) * n);
	for(i=0;i<n;i++){
		scnaf("%c",&A1[i]);
	}
	printf("the length of array is %d",&m);
	A2 = malloc(sizeof(int) * m);
	for(i=0;i<m;i++){
		scnaf("%c",&A2[i]);
	}
	LCS(n,m,A1,A2);
	return 0;
}




int SideMax(int x,int y)
{
	if(x > y)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void LCSoutput(int n, int m,int* A1,int* A2,int * B)
{
	int i = n-1;
	int j = m-1;
	while(j!=0&&i!=0)
	{
		if(B(i*m+j) == 3)
		{
			printf("%d ", A1[i]);
			i--;j--;
		}
		else if(B(i*m+j) == 2)
		{
			j--;
		}
		else
		{
			i--;
		}

	}
}

void LCS(int n, int m,int* A1,int* A2)
{
	//int *C,*B;
	int i,j;
	int tmp;
	//C = malloc(sizeof(int) * m * n);
	//B = malloc(sizeof(int) * m * n);
	int C[n][m],B[n][m];
	/*
	B = 1 删除x
	B = 2 删除y
	B = 3 删除x,y
	 */
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0||j==0){
				C[i][j] = 0;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(A1[i] == A2[j])
			{
				C[i][j] = C[i-1][j-1] + 1;
				B[i][j] = 3;
			}
			else
			{
				tmp = SideMax(C[i-1][j],C[i][j-1]);
				if(tmp == 0){
					C[i][j] = C[i-1][j];
				}
				else{
					C[i][j] = C[i][j-1];
				}
				B[i][j] = 1 + tmp;
			}

		}
	}
	LCSoutput(n,m,A1,A2,B);

}



