#include<stdio.h>
#include<stdlib.h>

typedef struct Step *StepP;
typedef StepP StepPoint;

StepPoint create(StepPoint step,int num);
StepPoint Data(StepPoint step);
void investment(StepPoint step,StepPoint data, int money,int num);


struct Step{
	int step;
	int num;
	int profit;
};

void main()
{
	StepPoint step;
	StepPoint data;
	printf("1\n"); 
	investment(step,data,5,4);
	printf("the max profit is %d\n", (step+4*6-1)->profit);
	free(step); 
	return;
}

StepPoint create(StepPoint step,int num){
	int i;
	step = malloc(sizeof(struct Step) * num);
	for(i=0;i<num;i++){
		(step+i)->step = 0;
		(step+i)->num = 0;
		(step+i)->profit = 0;
	}
	printf("%d\n",(step+23)->profit);
	return step;
}

StepPoint Data(StepPoint Step){
	int i,j;
	printf("2\n");
	Step = malloc(sizeof(struct Step) * 25);
	printf("3\n");
	Step[0].profit = 0;Step[1].profit = 11;Step[2].profit = 12;Step[3].profit = 13;
	Step[4].profit = 14;Step[5].profit = 15; 
	Step[6].profit = 0;Step[7].profit = 0;Step[8].profit= 5;Step[9].profit = 10;
	Step[10].profit = 15;Step[11].profit = 20;
	Step[12].profit = 0;Step[13].profit = 2;Step[14].profit = 10;Step[15].profit = 30;
	Step[16].profit = 32;Step[17].profit = 40;
	Step[18].profit = 0;Step[19].profit = 20;Step[20].profit = 21;Step[21].profit = 22;
	Step[22].profit = 23;Step[23].profit = 24;
	(Step+23)->profit = 24;
	printf("3\n");
	printf("%d\n",(Step+23)->profit);
	for(i=0;i<4;i++){
		for(j=0;j<6;j++){
			(Step+i*6+j)->step = i;
			(Step+i*6+j)->num = j;
		}
	}
	printf("%d\n",(Step+23)->profit);
	return Step;
}

void investment(StepPoint array,StepPoint data,int money,int num){
	int i,k,j;
	int max,basis;

	money++;
	array = create(array,num*money+1);
	printf("%d\n",(array+23)->profit);
	data = Data(data);
	printf("%d\n",(data+23)->profit);
	for(k=0;k<num;k++){
		for(j=0;j<money;j++){
		   	(array + k*money + j)->step = k;
			max = 0;
			for(i=0;i<= j;i++){
				if(k==0){
					basis = 0;
				}
				else{
					basis = (array+(k-1)*money+j-i)->profit;
				}
			    if(max < (data+k*money + i)->profit + basis){
			    	max = (data+k*money + i)->profit + basis;
			        (array + k*money + j)->num = i;
			    }
			}
			(array + k*money + j)->profit = max;
		}
	}
	printf("the max profit is %d\n", (array+4*6-1)->profit);
	free(data);
}

