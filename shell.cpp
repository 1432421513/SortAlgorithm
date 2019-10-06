#include "afx.h"
#include <iostream.h>
#define MAXSIZE 10
//#define N 9

typedef struct
{
	int r[MAXSIZE+1];
	
	int length;
}SqList;

/*******************************************/
/****************冒泡算法*******************/
/****************BubbleSort*****************/
/*******************************************/
/* 

void swap(SqList *L,int i,int j)
{
int temp=L->r[i];
L->r[i]=L->r[j];
L->r[j]=temp;
}

void BubbleSort(SqList *L)
{ 
	for(int i=0;i<L->length;i++)
	{
		for(int j=L->length-1;j>=i;j--)
		{
			if (L->r[j]>L->r[j+1])
			{
			swap(L,j,j+1);
			}
		}
	}
}
*/


/*******************************************/
/****************希尔排序*******************/
/****************ShellSort******************/
/*******************************************/
/*
void ShellSort(SqList *L)
{
	int i,j;
	int increment=L->length;
	do
	{
		increment=increment/3+1;
		for(i=increment+1;i<=L->length;i++)
		{
			if(L->r[i]<L->r[i-increment])
			{
			L->r[0]=L->r[i];
			for(j=i-increment;j>0&&L->r[0]<L->r[j];j-=increment)
				L->r[j+increment]=L->r[j];
			L->r[j+increment]=L->r[0];
			}
		}
	}
	while(increment>1);
}
*/
/*******************************************/
/****************归并排序*******************/
/****************MergingSort****************/
/*******************************************/
/*
void Merge(int SR[],int TR[], int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m&&j<=n;k++)
	{
		if  (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if  (i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];
	}
	if  (j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];
	}
}

void MSort(int SR[],int TR1[],int s,int t)
{
	int  m;
	int TR2[MAXSIZE+1];
	if(s==t)
	{
		TR1[s]=SR[s];
	}
	else
	{
		m=(s+t)/2;
		MSort(SR,TR2,s,m);
		MSort(SR,TR2,m+1,t);
		Merge(TR2,TR1,s,m,t);
	}
}
void MergeSort(SqList *L)
{
	MSort(L->r,L->r,1,L->length);
}
*/
/*******************************************/
/****************快速排序*******************/
/******************QSort********************/
/*******************************************/
void swap(SqList *L,int i,int j)
{
int temp=L->r[i];
L->r[i]=L->r[j];
L->r[j]=temp;
}
int Partition(SqList *L,int low,int high)
{
	int pivotkey;
	pivotkey=L->r[low];
	while(low<high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);
		while(low<high && L->r[low]<=pivotkey)
			low++;
		swap(L,low,high);
	}
	return low;
}
void QSort(SqList *L,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=Partition(L,low,high);
		QSort(L,low,pivot-1);
		QSort(L,pivot+1,high);
	}
}
void QuickSort(SqList *L)
{
	QSort(L,1,L->length);
}
#define N 9
int main()
{
	int d[N] = {50,10,90,30,70,40,80,60,20};
	SqList L0;
	for (int i = 0; i <N; i++) {
		L0.r[i + 1] = d[i];
	}
	L0.length = N;
	cout<< "排序前:";
	for (int j = 1; j <= L0.length; j++) 
	{
		cout<< L0.r[j]<<" ";
	}
	//MergeSort(&L0);
	QSort(&L0,1,L0.length);
	cout << "\n排序后:";
	for (int k = 1; k <= L0.length; k++) 
	{
		cout << L0.r[k]<<" ";
	}
	cout << endl;
	return 0;
}
