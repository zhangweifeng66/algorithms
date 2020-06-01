#include<stdio.h>
#include<stdlib.h>

#define false 0
#define true 1
#define kind 4

struct Node;
typedef struct Node *ProToNode;
typedef ProToNode List;
typedef ProToNode Position;

List insertList(List L,int id);
List create(List L,int num);
void createList(List* array,int num);
void FreeList(List* L,int num);
int JudgeColor(List L);
void inputColor(List* L,int num);


struct Node{
	int number;
	int color;
	int visited;
	Position Next;
};

int ColorNUm[50];
int result[50];


void main()
{
	int i; 
	List array[50];
	createList(array,7);
	printf("%d\n",array[3]->number); 
	array[1]->Next = insertList(array[1],2);
	array[1]->Next = insertList(array[1],6);
	array[1]->Next = insertList(array[1],3);
	array[2]->Next = insertList(array[2],3);
	array[2]->Next = insertList(array[2],1);
	array[2]->Next = insertList(array[2],4);
	array[2]->Next = insertList(array[2],7);
	array[3]->Next = insertList(array[3],1);
	array[3]->Next = insertList(array[3],2);
	array[3]->Next = insertList(array[3],4);
	array[4]->Next = insertList(array[4],3);
	array[4]->Next = insertList(array[4],2);
	array[5]->Next = insertList(array[5],6);
	array[5]->Next = insertList(array[5],7);
	array[6]->Next = insertList(array[6],1);
	array[6]->Next = insertList(array[6],5);
	array[7]->Next = insertList(array[7],2);
	array[7]->Next = insertList(array[7],5);
	for(i=1;i<=7;i++)
	{
		printf("%d\n",array[i]->Next->number);
		ColorNUm[i] = 0;
	}
	inputColor(array,7);
	FreeList(array,7);
}

List insertList(List L,int id){
	Position Point;
	Point = L;
	while(Point->Next != NULL)
	{
		Point = Point->Next;
	}
	Point->Next = malloc(sizeof(struct Node));
	Point->Next->number = id;
	Point->Next->color = 0;
	Point->Next->Next = NULL;
	printf("2\n");
	return L->Next;
}

List create(List L,int num)
{
	L = malloc(sizeof(struct Node));
	L->number = num;
	L->Next   = NULL;
	L->color  = 0;
	L->visited = 0;
	return L;
}

void createList(List* array,int num)
{
	int i;
	for(i=1;i<=num;i++)
	{
		array[i] = create(array[i],i);
	}
}

void FreeList(List* array,int num)
{
	int i;
	Position P,Tmp;
	for(i=1;i<=num;i++)
	{
		P = array[i]->Next;
		while(P!=NULL)
		{
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
		free(array[i]);
	}
}

int JudgeColor(List L)
{
	int i;
	int id,flag;
	Position P;
	Position tmp;
	P = L->Next;


	flag = L->color;
	while(P!=NULL)
	{
		id = P->number;
		if(ColorNUm[id] == 0)
		{
			P = P->Next;
			continue;
		}
		else
		{
			
			if(ColorNUm[id] == flag)
			{
				return false;
			}
			P = P->Next;
		}
	}
	return true;

}

void inputColor(List* L,int num)
{
	int tmp = 0;
	int i,j;
	int Flag;
	int id;
	for(i=1;i<=num;i++)
	{
		if(L[i]->visited != 1){
			tmp  = 1 ;
			break;
		}
	}
	if(tmp == 0)
	{
		for(i=1;i<=num;i++)
		{
			printf("%d:%d  ",i,ColorNUm[i]);
		}
		printf("\n");
	}

	for(i=1;i<=num;i++)
	{

		if(L[i]->visited == 1)
		{
			continue;
		}
		
		Flag = 0;
		for(j=1;j<=kind;j++)
		{
			L[i]->color = j;
			if(JudgeColor(L[i]) == true)
			{
				L[i]->visited = 1;
				id = L[i]->number;
				ColorNUm[id] = j;
				
				inputColor(L,num);
				ColorNUm[id] = 0;
				L[i]->visited = 0;
			}
			else{
				L[i]->color = 0;
				Flag++;
			}
			if(Flag == 4)
			{
				return;
			}
		}
		
	}
}

