#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define INF 999

struct point;
typedef struct point Point;

int EXabs(int a,int b,int c);
void swap(Point a,Point b);
double min(double a,double b);
double Distance(Point a,Point b);
void Merge(Point *P,int start,int end,int sign);
double DistanceOnlyTwo(Point *P,int start,int end);
double DistanceOnlyThree(Point *P,int start,int end);
double EfficientClosePair(Point *Px,Point *Py,int start,int end);

struct point{
 	int x;
 	int y;
};

void main(){
	Point *P,*Px,*Py;
	int num;
	int i;
	printf("Please input the number of Point\n");
	scanf("%d",&num);
	P = malloc(sizeof(struct point) * num);
	Px = malloc(sizeof(struct point) * num);
	Py = malloc(sizeof(struct point) * num);
	for(i=0;i<num;i++){
		scanf("%d",&P[i].x);
		scanf("%d",&P[i].y);
	}
	Merge(P,0,num-1,0);
	for(i=0;i<num;i++){
		Px[i].x = P[i].x;
		Px[i].y = P[i].y;
		printf("%d\n",Px[i].x);
	}
	Merge(P,0,num-1,1);
	for(i=0;i<num;i++){
		Py[i].x = P[i].x;
		Py[i].y = P[i].y;
	}

	printf("the min Distance is %lf\n",EfficientClosePair(Px,Py,0,num-1));
	free(P);
	free(Px);
	free(Py);

}


int EXabs(int a,int b,int c){
	return (a-b) * (a-b) > c ? 0: 1;  
}

void swap(Point a,Point b){
	int tmpX;
	int tmpY;
	tmpX = a.x;
	tmpY = a.y;
	a.x = b.x;
	a.y = b.y;
	b.x = tmpX;
	b.y = tmpY;
}

double min(double a,double b){
	return a>b?b:a;
}

double Distance(Point a,Point b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ;
}

void Merge(Point *P,int start,int end,int sign){
	int middle = (start+end)/2;
	int sum = end -start+1;
	
	int i,k,j;
	if(start >= end){
		return;
	}
	else{
		Merge(P,start,middle,sign);
		Merge(P,middle+1,end,sign);
	}
	
	Point iArray[sum];
	
	i = start;
	j = middle+1;
	k = 0;
	while(i<=middle && j<=end){
		if(sign == 0){
			if(P[i].x < P[j].x){
				iArray[k].y = P[i].y;
				iArray[k++].x = P[i++].x;
			}
			else{
				iArray[k].y = P[j].y;
				iArray[k++].x = P[j++].x;
			}
		}
		else{
			if(P[i].y < P[j].y){
				iArray[k].x = P[i].x;
				iArray[k++].y = P[i++].y;
			}
			else{
				iArray[k].x = P[j].x;
				iArray[k++].y = P[j++].y;
			}
		}
	}
	if(i > middle && j <=end){
		if(sign == 0){
			while(j<=end){
				iArray[k].y = P[j].y;
				iArray[k++].x = P[j++].x;
			}
		}
		else{
			while(j<=end){
				iArray[k].x = P[j].x;
			 	iArray[k++].y = P[j++].y;
			}
		}
	} 
	else if(j>end && i<=middle){
		if(sign == 0){
			while(i<=middle){
				iArray[k].y = P[i].y;
				iArray[k++].x = P[i++].x;
			}
		}
		else{
			while(i<=middle){
				iArray[k].x = P[i].x;
				iArray[k++].y = P[i++].y;
			}
		}
	}
	
	j = start;
	for(i=0;i<k;i++){
		P[j].x = iArray[i].x;
		P[j++].y = iArray[i].y;
	}
	return;
}

double DistanceOnlyTwo(Point *P,int start,int end){
	return sqrt(Distance(P[start],P[end]));
}

double DistanceOnlyThree(Point *P,int start,int end){
	int middle = (start + end)/2;
	if(Distance(P[start],P[end]) <= Distance(P[start],P[middle])){
		if(Distance(P[start],P[end]) <= Distance(P[middle],P[end])){
			return sqrt(Distance(P[start],P[end]));
		}
		else{
			return sqrt(Distance(P[middle],P[end]));
		}
	}
	else{
		if(Distance(P[middle],P[end]) <= Distance(P[start],P[middle])){
			return sqrt(Distance(P[middle],P[end]));
		}
		else{
			return sqrt(Distance(P[middle],P[start]));
		}
	}
}

double EfficientClosePair(Point *Px,Point *Py,int start,int end){

	
	if(end - start == 1){
		return DistanceOnlyTwo(Px,start,end);
	}
	else if(end - start == 2){
		return DistanceOnlyThree(Px,start,end);
	}
	else if(end - start == 0){
		return INF;
	}
	else{
		int middle = (start+end)/2;
		int i,j,k;
		int distance,Tmp;
		double d1,d2,d;
		Point Ptmp[end -start + 2];

		d1 = EfficientClosePair(Px,Py,start,middle);
		d2 = EfficientClosePair(Px,Py,middle+1,end);
		d = min(d1,d2);
		distance = (int)(d * d + 0.5);
		Tmp = Px[middle].x;
		j=0;
		for(i=start;i<=end;i++){
			if(EXabs(Py[i].x,Tmp,distance)){
				Ptmp[j].x = Py[i].x;
				Ptmp[j++].y = Py[i].y;
			}
		}
		for(i=0;i<j-1;i++){
			k = i+1;
			while(((Ptmp[i].y - Ptmp[k].y) * (Ptmp[i].y - Ptmp[k].y) <= distance) && k<j){
				if(Distance(Ptmp[i],Ptmp[k]) < distance){
				    distance = Distance(Ptmp[i],Ptmp[k]);
				}
				k++;
			}
		}
		return sqrt(distance);
	}
}


