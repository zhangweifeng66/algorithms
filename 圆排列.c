#include<stdio.h>
#include<math.h>

void swap(double* x,double* y);
void swap(double* x,double* y);
double backlength(int t,double* array,int num);
void judge(double* array,int num);


double min = 1000.0; //��̵�Բ���г���

double center[100];  //�����洢��һ��Բ,Բ�ĵ���ǰԲ��X���ϵľ���
double localX[100];  //����Բ����˳��,��¼Բ�İ뾶��

double Array[100];  //��������Բ������˳��

void main(){
	int i;
	int num = 5; 
	//����
	double array[5] = {1,1,2,3,7};
	//�����ܺ�������
	backlength(0,array,num);
	
	//���
	for(i=0;i<num;i++)
	{
		printf("%lf ",Array[i]);
	}
	printf("\n");
	return;
}

//����
void swap(double* x,double* y)
{
	double tmp;
	tmp = *y;
	*y  = *x;
	*x  = tmp;
}


//���ص�һ��ԲԲ�ĵ���ǰԲX���ϵľ���     ��Ϊ�ڸô������е�һ��Բλ�ò���,���ü��ϵ�һ��Բ�İ뾶
//��Ϊ���ڵ�Բ��һ���������е�,����������Բ����,�������м��������СԲ,��ЩСԲ����������ǰ���Բ����
//����ǰ���г�����������Բ֮��ľ���,���ǵ�ǰԲ����˳�����󳤶�

//�õ�ǰ����Բ�����뵱ǰ��i��Բ����,���ϵ�i��ԲԲ�ĵ�X����
//�ҳ�������󳤶ȵ�  ������ȷ��Բ���к����еĳ���
double disX(int t,double y)
{
//t��ʾ��ǰ�ŵ��ڼ���Բ,y��ʾt��Բ�İ뾶
	int i;
	int max = 0;
	int temp;

	//��������Բ��֮ǰ��i��Բ����,�����i��Բ��x�������Բ�ľ���
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


//���е�Բ�����������,����γ���,��min�Ƚ�,���С,min = ��ǰ���γ���,Array��¼��ǰԲ����˳��
//�ҳ���̾��γ�
void judge(double* array,int num)
{
	int i;
	double Xmax,Xmin;
	double temp1,temp2,temp;
	//��Ϊ�������ڵ�Բ������,����������Բ����,�������м��������СԲ
	//���Բ������һ��Բ��Բ��X����Ӱ뾶���Ǿ������г�  -----  ���һ��Բ�;����ұ�����
	//���Ա�������Բ,�ҳ���Ĳ��Ǿ��γ�
	
	//ͬ��,���ǵ�һ��Բ���Ǻ;����������
	//�õ�ǰԲ��Բ��X�����ȥԲ�İ뾶�� -- Ҳ����Բ����߶˵���������ߵľ���
	//���Ա�������Բ,�ҳ���̵�,�����Ǹ�Բ������������
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

//������,�û��ݷ�,����ε�������г�
//��t��Բ����num - t��ѡ��
double backlength(int t,double* array,int num)
{
	int i,j;
	double length;
	
	if( t == num)
	{
	//������е�Բ�Ѿ��������,�ж������ǲ��Ǳȵ�ǰ���ȶ�,
	//��,�ͼ�¼�����Լ����г���
		judge(array,num);

	}
	else
	{
		for(i=t;i<num;i++)
		{
		// ��ǰ�Ѿ����к���t-1��Բ,�ҵ�t��Բ,ʣ�µ�Բ���п���
			swap(&array[i],&array[t]);
			//����t��Բ �� �������Լ�����ʣ�µ�Բ���ν��н���
			//����ÿ�κ͵�t��Բ�Ƚ�,��ʵ���Ǻ�ʣ�µ�Բ���Ƚ�
			//���ص��ǵ�һ��Բ�͵�ǰԲX�ĳ���
			length = disX(t,array[t]);
			localX[t] = array[t];
			if(length + localX[0] + localX[t]  < min)
			{
			// �����ǰ ��һ��Բ�͵�ǰԲX�ĳ��� + �������Բ�İ뾶�͵�һ��Բ�İ뾶 
			// ����̳���С,�Ͳ��ý���,����
			// ���ﲻ���Ͻ��ļ���,ֻ�ǽ����ж�,���ÿ����һ��Բ������Բ�����������������
				center[t] = length;
				//��¼��t��Բ���һ��Բ֮��ĳ���
				backlength(t+1,array,num);
				//�жϵ�t+1����Բ
			}
			swap(&array[i],&array[t]);
			//����t��Բ����������Բ����, �ָ�
			//�ָ���ԭ����˳��, �����t��Բ�������н���,�������,�ظ�
		}
		
	}
}

