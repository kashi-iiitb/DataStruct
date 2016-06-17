#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void merge(int a[],int start, int mid, int end);

void display(int a[],int size)
{
  for(int i=0; i<size; i++)
  {
	printf("%d ",a[i]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void mergesort(int a[],int start, int end)
{
  	if(start>=end)
		return;
	int mid=(start+end)/2;
	mergesort(a,start,mid);
	mergesort(a,mid+1,end);
	merge(a,start,mid,end);
}

void merge(int a[],int start, int mid, int end)
{
	int i = 0;
	int j = 0;
	int len_a = mid-start+1;
	int len_b = end-mid;
	int *temp_a = malloc(sizeof(int)*(mid-start+1));
	int *temp_b = malloc(sizeof(int)*(end-mid));
	for(i = 0; i<len_a; i++)
		temp_a[i] = a[start+i];
	for( j = 0; j<len_b; j++)
		temp_b[j] = a[mid+1+j];
	
	int k = start;
	i = 0;
	j = 0;
	while(i<len_a && j < len_b)
	{
		if(*(temp_a+i)<*(temp_b+j))
		{
			a[k] = *(temp_a+i);
			i++;
		}
		else
		{
			a[k] = *(temp_b+j);
			j++;
		}
		k++;
	}
	while(i<len_a)
	{
			a[k] = *(temp_a+i);
			i++;
			k++;
	}
	while(j<len_b)
	{
			a[k] = *(temp_b+j);
			j++;
			k++;
	}
	//free(temp_a);
	//free(temp_b);
}

int main()
{
int a[] = {10,25,12,15,36,14,7,18};
display(a,SIZE);
mergesort(a,0,SIZE-1);
display(a,SIZE);

}
