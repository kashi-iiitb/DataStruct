#include<stdio.h>
#include<stdlib.h>
//#ifndef _GRAPH_
//#include"graph.h"
#include"queue.h"
int isEmpty(struct Queue **q)
{
	if((*q)->rear==NULL)
		return 1;
	else
		return 0;
}

void enqueue(struct Queue **q, struct vertex* ver)
{
	struct Qnode *temp=(struct Qnode *)malloc(sizeof(struct Qnode *));
	temp->ver = ver;
	temp->next = NULL;
	if((*q)->rear==NULL)
	{
		(*q)->front = temp;
		(*q)->rear = temp;
	}
	else
	{
		((*q)->rear)->next = temp;
		(*q)->rear = temp;
	}
		printf("enqued %d\n",(temp->ver)->data);
}

struct vertex* dequeue(struct Queue **q)
{
		if((*q)->front==NULL)
		{
			printf("Cant dequeue, Queue empty\n");
			return;
		}
		struct Qnode *temp = (*q)->front;
		printf("deleted %d visited =%d\n",(temp->ver)->data,(temp->ver)->visited);
		struct vertex* ret_ver=NULL;

		if(((*q)->front)->next == NULL)
		{
			printf("Deleting last element\n");
			(*q)->front=NULL;
			(*q)->rear=NULL;
		}
		else
		{
			printf("inside else of dequeue\n");
			(*q)->front=((*q)->front)->next;
		}
		ret_ver=temp->ver;
		free(temp);
		return ret_ver;
}


