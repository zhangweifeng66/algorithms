#include<stdio.h>
#include<stdlib.h>

#define Inf 999

// void Init(int **buffet,int **path,int n,int m);
// void quit(int **buffet,int n);
// void Floyd(int **buffet,int **path,int n);

void main()
{
	int n,m;
	int i,j,k,com,x,y;
	printf("Please input the number of Vertex and Edge:");
	scanf("%d %d",&n,&m);
	int **buffet;
	int **path;


	buffet = (int**)malloc(sizeof(int*)*(n+1));
	path = (int**)malloc(sizeof(int*)*(n+1));
	for(i=0;i<n+1;i++){
		buffet[i] = (int*)malloc(sizeof(int)*(n+1));
		path[i] = (int*)malloc(sizeof(int)*(n+1));
	}
	//矩阵的初始化
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			path[i][j] = j; //有边相连的两点,前一点指向后一点
			buffet[i][j] = Inf; 
		}
	}
	//矩阵的赋值
	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		scanf("%d",&buffet[x-1][y-1]);
	}


	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(buffet[i][k] + buffet[k][j] < buffet[i][j]){
					buffet[i][j] = buffet[i][k] + buffet[k][j];
					//递归调用,两块 和中间一点相连指向中间一点
					path[i][j] = path[i][k];
				}
			}
		}
	}


	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(buffet[i][j] != Inf && i!=j){
				printf("%d -> %d distance: %d\n",i+1,j+1,buffet[i][j]);
				com = i;
				while(com!=j){
					printf("%d -> " ,com+1);
					com = path[com][j];
				}
				printf("%d\n\n",j+1);
			}

		}
	}
	
				
	
	for(i=0;i<n;i++){
		free(buffet[i]);
	}
	free(buffet);
	for(i=0;i<n;i++){
		free(path[i]);
	}
	free(path);
	return;
}



// void Init(int **buffet,int **path,int n,int m){ //动态二维数组初始化
// 	int i,j,x,y;
// 	//赋予地址
// 		buffet = (int**)malloc(sizeof(int*)*n);
// 	path = (int**)malloc(sizeof(int*)*n);
// 	for(i=0;i<n;i++){
// 		buffet[i] = (int*)malloc(sizeof(int)*n);
// 		path[i] = (int*)malloc(sizeof(int)*n);
// 	}
// 	//矩阵的初始化
// 	for(i=0;i<n;i++){
// 		for(j=0;j<n;j++){
// 			path[i][j] = 0; //都没有路径
// 			if(i==j){
// 				buffet[i][j]  = 0;   //矩阵对角线为0,
// 			}
// 			else{
// 				buffet[i][j] = Inf;  //矩阵值无限大
// 			}
// 		}
// 	}
// 	//矩阵的赋值
// 	for(i=0;i<m;i++){
// 		scanf("%d %d %d",&x,&y,&buffet[x-1][y-1]);
// 		path[x][y] = y;  //有边相连的两点,前一点指向后一点
// 	}
// }

//释放空间
// void quit(int **buffet,int n){
// 	int i;
// 	for(i=0;i<n;i++){
// 		free(buffet[i]);
// 	}
// 	free(buffet);
// }

//Floyd函数主体
// void Floyd(int **buffet,int **path,int n){
// 	int i,j,k;
// 	for(k=0;k<n;k++){
// 		for(i=0;i<n;i++){
// 			for(j=0;j<n;j++){
// 				if(buffet[i][k] + buffet[k][j] < buffet[i][j]){
// 					buffet[i][j] = buffet[i][k] + buffet[k][j];
// 					//递归调用,两块 和中间一点相连指向中间一点
// 					path[i][j] = path[i][k];
// 				}
// 			}
// 		}
// 	}
// }
