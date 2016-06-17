#include <stdio.h>
#define SIZE 8

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
void quicksort(int a[],int start,int end)
{
  int pivot;
  int i,j;
  //int mid = (start + end )/2;
  if(start >= end)
	return;
  pivot = start;
  i = start;
  j = end;
  while(i<j)
  {
  while(a[i]<=a[pivot])
 	i++;
  while(a[j]>a[pivot])
 	j--;
  if(i<j)
	swap(&a[i],&a[j]);
  }
  swap(&a[j],&a[pivot]);
  quicksort(a,start, j-1);
  quicksort(a,j+1,end);
}
int main()
{
int a[] = {10,25,12,15,36,14,7,18};
display(a,SIZE);
quicksort(a,0,SIZE-1);
display(a,SIZE);

}
