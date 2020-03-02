clude<stdio.h>
#include<stdlib.h>

#define MAX 999
#define PNUMBER 20
#define ENUMBER 200

struct Node;
typedef struct Node *ProToNode;
typedef ProToNode List;
typedef ProToNode Position;
typedef struct node *ProTonode;
typedef ProTonode Egle;

struct Node
{
	int Point;
	int Distance;
	Position Next;
}; 

struct node
{
	int V1;
	int V2;
	int Distance;
};

List create(List L, int P, int D);
void DeleteList( List L );
void swap(Egle *v1, Egle *v2);
int  source(int x);
void unionn(int x, int y);
void Kruskal(int num);


int fat[ENUMBER];
int V[PNUMBER];
int Vnumber,Enumber;
struct Node array[PNUMBER];
int visited[PNUMBER];
struct node E[ENUMBER];
struct node Etrue[PNUMBER];

void main(int argc, char const *argv[])
{
	FILE *fp1 = fopen("in.txt","r");
	FILE *fp2 = fopen("out.txt","w");

	int i; 
	int iInput1,iInput2,iInput3;

	int c=0;
	fscanf(fp1, "%d %d", &Vnumber, &Enumber);

	for(i=0;i<Vnumber;i++){
		visited[i] = 0;
		array[i].Next = NULL;
		fat[i] = i;
	}
	for(i=0;i<Enumber;i++){

		fscanf(fp1, "%d %d %d", &iInput1,&iInput2,&iInput3);

		array[iInput1].Next = create(&array[iInput1],iInput2,iInput3);
	}

	printf("%d ",array[1].Next->Next->Point); 

	for(i=0;i<Vnumber;i++){
		V[i] = array[i].Point ;
	}

	Kruskal(Vnumber);

	for(i=0;i<Vnumber;i++){
		DeleteList(&array[i]);
	}


	return 0;
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

void swap(Egle *v1, Egle *v2){
	int a,b,c;
	a = v1->V1;
	b = v1->V2;
	d = v1->Distance;
	v1->V1 = v2->V1;
	v1->V2 = v2->V2;
	v1->Distance = v2->Distance;
	v2->V1 = a;
	v2->V2 = b;
	v2->Distance = c;
}

int source(int x){
	if( fat(x) != x){
		return source(fat(x));
	}
	else{
		return x;
	}
} 

void unionn(int x, int y){
	fat(source(x)) = source(y);
}

void Kruskal(int num){
	int i,j,k,P;
	Position PS;
	Position Ptmp;

	P=0;

	for(i=0;i<num;i++){
		PS = array[i].Next;
		while(PS!=NULL){
			E[P].V1 = i;
			E[P].V2 = PS->Point;
			E[P++].Distance = PS->Distance;
			PS= PS->Next;
		}
	}
	for(i=0;i<P;i++){
		for(j=i;j<P;j++){
			if(E[i].Distance > E[j].Distance){
				swap(&E[i],&E[j]);
			}
		}
	}
	j=0;
	for(i=0;i<P;i++){
		if(k == num-1){
			break;
		}
		if(source(E[i].V1) != source(E[i].V2)){
			Etrue[j].V1 = E[i].V1;
			Etrue[j].V2 = E[i].V2;
			Etrue[j++].Distance = E[i].Distance;
			unionn(E[i].V1,E[i].V2);
			k++;
		}

	}
	
}



