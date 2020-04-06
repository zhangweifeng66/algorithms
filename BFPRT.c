#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int GetPivotIndex(int A[],int left,int right);
void InsertionSort(int A[],int left,int right);
int Partition(int A[],int left,int right,int pivot_index);
void swap(int A[],int a,int b);
int BFPRTs(int k,int A[],int left,int right);
//设置中位数,寻找中位数中的中位数
int GetPivotIndex(int A[],int left,int right){ 
  int i; 
  if(right-left<5){
    InsertionSort(A,left,right);
    return (left+right)/2;
  }

  int sub_right=left-1;

  for(i=left;i+4<=right;i+=5){
    InsertionSort(A,i,i+4);
    int index=i+2;
    swap(A,index,++sub_right);
  }

  int mid=sub_right/2;

  int pivot_index=BFPRTs(mid,A,0,sub_right);

  return pivot_index;
 }
 //插入排序
void InsertionSort(int A[],int left,int right){  
  int i;
  for(i=left+1;i<right;i++){
    int j=i-1;

    int cur=A[i];
    while(1){
      if(A[j]>cur&&j>=0){
        A[j+1]=A[j];
        j--;
      }
      if(j<0||A[j]<cur)
        break;
      }
      A[j+1]=cur;
    }
}
 //根据中位数分区
int Partition(int A[],int left,int right,int pivot_index){
  swap(A,pivot_index,right);  
  int pivot=A[right];
  int tail=left-1;
  int i;
  for(i=left;i<right;i++){
    if(A[i]<=pivot){
      swap(A,++tail,i);
    }
  }
  swap(A,tail+1,right);

  return tail+1;
 }

void swap(int A[],int a,int b){
  int temp=A[a];
  A[a]=A[b];
  A[b]=temp;
 }

int BFPRTs(int k,int A[],int left,int right){
  int pivot_index=GetPivotIndex(A,left,right);

  int divide_index=Partition(A,left,right,pivot_index);

  int num = divide_index - left;

  if(num==k){
    return num;   
  }  
  else if(num < k){
    return BFPRTs(k-num,A,divide_index,right);
  }
  else{
    return BFPRTs(k,A,left,divide_index);
  }
}

void main(){
  int k;
  int A[]={6,20,74,60,10,94,12,1,59,14,36};
  int length = sizeof(A) / sizeof(int);
  scanf("%d",&k);
  int right=length-1;
  int left=0;
  if(right<k){
  	printf("the number is above the array\n");
  }
  int index=BFPRTs(k-1,A,left,right);

  printf("the %d th smallest number is %d\n",k,A[k-1]);
}
