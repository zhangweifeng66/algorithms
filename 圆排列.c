#include<stdio.h>
#include<math.h>

void swap(double* x,double* y);
void swap(double* x,double* y);
double backlength(int t,double* array,int num);
void judge(double* array,int num);


double min = 1000.0; //最短的圆排列长度

double center[100];  //用来存储第一个圆,圆心到当前圆的X轴上的距离
double localX[100];  //按照圆排列顺序,记录圆的半径长

double Array[100];  //用来储存圆的排列顺序

void main(){
	int i;
	int num = 5; 
	//数据
	double array[5] = {1,1,2,3,7};
	//主功能函数调用
	backlength(0,array,num);
	
	//输出
	for(i=0;i<num;i++)
	{
		printf("%lf ",Array[i]);
	}
	printf("\n");
	return;
}

//交换
void swap(double* x,double* y)
{
	double tmp;
	tmp = *y;
	*y  = *x;
	*x  = tmp;
}


//返回第一个圆圆心到当前圆X轴上的距离     因为在该次排列中第一个圆位置不变,不用加上第一个圆的半径
//因为相邻的圆不一定都是相切的,可能两个大圆相切,但他们中夹杂着许多小圆,这些小圆可能依次与前面的圆相切
//但当前排列长度是两个大圆之间的距离,且是当前圆排列顺序的最大长度

//用当前最后的圆假设与当前第i个圆相切,加上第i个圆圆心的X坐标
//找出其中最大长度的  就是正确的圆相切后排列的长度
double disX(int t,double y)
{
//t表示当前排到第几个圆,y表示t个圆的半径
	int i;
	int max = 0;
	int temp;

	//假设最后的圆与之前第i个圆相切,求出第i个圆的x坐标加两圆的距离
	for(i=0;i<t;i++)
	{
		temp = center[i] + 2.0*sqrt(localX[i] * y);   //
		if(max < temp)
		{
			max = temp;
		}
	}
	return max;
}


//所有的圆都排列完成了,求矩形长度,与min比较,如果小,min = 当前矩形长度,Array记录当前圆排列顺序
//找出最短矩形长
void judge(double* array,int num)
{
	int i;
	double Xmax,Xmin;
	double temp1,temp2,temp;
	//因为不是相邻的圆都相切,可能两个大圆相切,但他们中夹杂着许多小圆
	//所以不是最后一个圆的圆心X坐标加半径就是矩形排列长  -----  最后一个圆和矩形右边相切
	//所以遍历所有圆,找出最长的才是矩形长
	
	//同理,不是第一个圆就是和矩形左边相切
	//用当前圆的圆心X坐标减去圆的半径长 -- 也就是圆最左边端点距离矩形左边的距离
	//所以遍历所有圆,找出最短的,才是那个圆与矩形左边相切
	for(i=0;i<num;i++)
	{
		temp1 = center[i] + localX[i];
		temp2 = center[i] - localX[i];
		if(Xmax < temp1)
		{
			Xmax = temp1;
		}
		if(Xmin > temp2)
		{
			Xmin = temp2;
		}

	}
	temp = Xmax - Xmin;
	if(temp < min)
	{
		min = temp;
		for(i=0;i<num;i++)
		{
			Array[i] = array[i];
		//	printf("%lf ",Array[i]);
		}
		//printf("\n");
		 
	}
}

//主函数,用回溯法,求矩形的最短排列长
//第t个圆都有num - t种选择
double backlength(int t,double* array,int num)
{
	int i,j;
	double length;
	
	if( t == num)
	{
	//如果所有的圆已经排序好了,判断他们是不是比当前长度短,
	//是,就记录他们以及排列长度
		judge(array,num);

	}
	else
	{
		for(i=t;i<num;i++)
		{
		// 当前已经排列好了t-1个圆,找第t个圆,剩下的圆都有可能
			swap(&array[i],&array[t]);
			//将第t个圆 和 他本身以及后面剩下的圆依次进行交换
			//所以每次和第t个圆比较,其实就是和剩下的圆都比较
			//返回的是第一个圆和当前圆X的长度
			length = disX(t,array[t]);
			localX[t] = array[t];
			if(length + localX[0] + localX[t]  < min)
			{
			// 如果当前 第一个圆和当前圆X的长度 + 加上最后圆的半径和第一个圆的半径 
			// 比最短长度小,就不用进行,回溯
			// 这里不是严谨的计算,只是进行判断,不用苛求第一个圆和最后的圆与矩形左右两边相切
				center[t] = length;
				//记录第t个圆与第一个圆之间的长度
				backlength(t+1,array,num);
				//判断第t+1个的圆
			}
			swap(&array[i],&array[t]);
			//将第t个圆和他交换的圆交换, 恢复
			//恢复成原来的顺序, 方便第t个圆与后面进行交换,不会打乱,重复
		}
		
	}
}

