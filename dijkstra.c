#include<stdio.h>
#include<stdlib.h>

#define Max 99

struct Node;
typedef struct Node *ProToNode;
typedef ProToNode List;
typedef ProToNode Position;

List create(List L, int P, int D);
void DeleteList( List L );
void input(int n);
void DijKstra(int n,int m);

struct Node
{
	int Point;
	int Distance;
	Position Next;
}; 

struct Node array[100];
int visited[100];
int S[100];

void main()
{
	int n,m;
	int i;

	printf("Please input the number of Vertex and Edge:");
	scanf("%d %d",&n,&m);
	input(m);

	printf("Please input the Vertex of Beginning \n");
	scanf("%d",&m);
	DijKstra(n,m);

	for(i=0;i<n;i++){
		if(visited[i] != 0){
			printf("%d -> %d  distance %d:\n",m,i,visited[i] );
		}
	}

	for(i=0;i<n;i++){
		DeleteList(&array[i]);
	}
	return;
}

List create(List L, int P, int D){
	Position PS = L;
	while(PS->Next != NULL){
		PS = PS->Next;
	}

	PS->Next = malloc(sizeof(struct Node));
	PS->Next->Point = P;
	PS->Next->Distance = D;
	PS->Next->Next = NULL;
	return L->Next;
}

void DeleteList( List L ){
	Position P,TmpCell;

	P = L -> Next;

	while( P != NULL )
	{
		TmpCell = P -> Next;
		free( P );
		P = TmpCell;
	}
	L -> Next = NULL;
}

void input(int m){
	int i; 
	int iInput1,iInput2,iInput3;
	for(i=0;i<m;i++){

		scanf("%d %d %d", &iInput1,&iInput2,&iInput3);

		array[iInput1].Next = create(&array[iInput1],iInput2,iInput3);
	}
}

void DijKstra(int n,int m){
	int com,i,j,k=0;
	Position PS;
	int iTemp ;

	for(i=0;i<n;i++){
		visited[i] = Max;
	}
	visited[m] = 0;
	com = m;
	S[k++] = m;
	for(i =0;i<n;i++){
		PS = array[com].Next;
		while(PS != NULL){

			if(visited[PS->Point] > visited[com] + PS->Distance){
				visited[PS->Point] = visited[com] + PS->Distance; 
			}

			PS=PS->Next;
		}
		iTemp = Max;
		for(j=0;j<n;j++){
			if(visited[j]!=0&&visited[j] < iTemp){
				iTemp = visited[j];
				com = j;
			}

		}
		S[k++] = com;
	}
}
