#include<stdio.h>
#include<stdlib.h>

struct Qnode{
 int data;
 struct Qnode *next;
};

struct Queue{
 struct Qnode *front,*rear;
};


void enqueue(struct Queue **q, int num)
{
	printf("inside enqueue\n");
	struct Qnode *temp=(struct Qnode *)malloc(sizeof(struct Qnode *));
	temp->data = num;
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
}

void dequeue(struct Queue **q)
{
		if((*q)->front==NULL)
		{
			printf("Cant dequeue, Queue empty\n");
			return;
		}
		struct Qnode *temp = (*q)->front;
		if(((*q)->front)->next == NULL)
		{
			(*q)->front==NULL;
			(*q)->rear==NULL;
		}
		else
		{
			(*q)->front==((*q)->front)->next;
		}
		printf("deleted %d\n",temp->data);
		free(temp);
}


int main()
{
 struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue*));
 q->front=NULL;
 q->rear=NULL;
// dequeue(&q);
 enqueue(&q,10);
// dequeue(&q);
 enqueue(&q,20);
 dequeue(&q);
 enqueue(&q,30);
 dequeue(&q);
// enqueue(&q,40);

	printf(" enqueue dequeue program\n");
return 0;
}
