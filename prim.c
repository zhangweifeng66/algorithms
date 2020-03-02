#include<stdio.h>
#include<stdlib.h>

#define MAX 999
#define PNUMBER 20
#define ENUMBER 200

struct Node;
typedef struct Node *ProToNode;
typedef ProToNode List;
typedef ProToNode Position;

List create(List L, int P, int D);
void DeleteList( List L );
void Prim(int i);
void lower(List L, int V,int *P, int *D,int S);

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

int V[PNUMBER];
int Vnumber,Enumber;
struct Node array[PNUMBER];
int visited[PNUMBER];
struct node E[ENUMBER];

void main(){
	FILE *fp1 = fopen("in.txt","r");
	FILE *fp2 = fopen("out.txt","w");

	int i; 
	int iInput1,iInput2,iInput3;

	int c=0;
	fscanf(fp1, "%d %d", &Vnumber, &Enumber);

	for(i=0;i<Vnumber;i++){
		visited[i] = 0;
		array[i].Next = NULL;
	}
	for(i=0;i<Enumber;i++){

		fscanf(fp1, "%d %d %d", &iInput1,&iInput2,&iInput3);

		array[iInput1].Next = create(&array[iInput1],iInput2,iInput3);
	}

	printf("%d ",array[1].Next->Next->Point); 

	fscanf(fp1,"%d",&iInput1); 

	for(i=0;i<Vnumber;i++){
		V[i] = array[i].Point ;
		if(V[i] == iInput1){
			visited[0] = iInput1;
		}
	}

	Prim(1);
	
		
	for(i=0;i<Vnumber;i++){
		DeleteList(&array[i]);
	}
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

void lower(List L, int V,int *P, int *D,int S){
	if( L == NULL){
		return;
	}
	else{
		if(L->Distance < *D){
			*D = L->Distance;
			*P = L -> Point;
			E[S].V1 = V;
			E[S].V2 = *P;
			E[S].Distance = *D;
		}
		else{
			return;
		}
	}
}

void Prim( int num){
	Position PS;
	int min, i,j;
	int sign;

	// PS=array[ visited[num] ].Next;
	
	// while(1){
	// 	min = MAX;

	// 	for(i=0;i<PNUMBER;i++){
	// 		if(visited[i] == 0){
	// 			break;
	// 		}
	// 		if(PS->Point == visited[i]){
	// 			break;
	// 		}
	// 		else{
	// 			continue;
	// 		}
	// 	}

	// 	lower(PS,&V[j],&min);
	// 	PS = PS->Next;
	// 	if(PS == NULL && visited[++num] != 0){
	// 		PS = array[ visited[num] ].Next;
	// 	}
	// 	else if(PS == NULL && visited[++num] == 0){
	// 		visited[num] = V[j];
	// 		j++;
	// 		break;
	// 	}


	// }


	for(i=0;i<num;i++){
		PS=array[ visited[num] ].Next;
		min = MAX;
		sign = 0;
		while(PS!=NULL){
			for(j=0;j<num;j++){
				if(visited[j] == 0){
					break;
				}
				if(PS->Point == visited[j]){
					sign = 1;
					break;
				}

			}

			if(sign == 1){
				sign = 0;
				PS = PS -> Next;
				continue;
			}
			lower(PS,visited[i],&visited[num],&min,num);
			PS = PS->Next;
		}
	}

	num++;
	if(Vnumber == num){
		return;
	}else{
		Prim(num);
	}
}

