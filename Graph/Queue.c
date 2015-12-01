#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
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
