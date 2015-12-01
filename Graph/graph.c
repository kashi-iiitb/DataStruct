#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
/* struct vertex
{
	int data;
	int visited;
	struct edge *e;
	struct vertex *v;
};

struct edge
{
 	struct vertex *connect_to;
	struct edge *e;
};

struct Graph{
	struct vertex *g;
};*/

void add_vertex(struct vertex **graph,int vnum)
{
	struct vertex* v_temp=(struct vertex*)malloc(sizeof(struct vertex));
	v_temp->e=NULL;
	v_temp->v=NULL;
	v_temp->data=vnum;
	v_temp->visited=0;

	struct vertex *temp_ptr=*graph;
	if((*graph)==NULL)
	{
		(*graph)=v_temp;
		printf("first vertex %d\n",(*graph)->data);
	}
	else
	{
		//printf("I am in else %d\n", temp_ptr->data);
		while((temp_ptr->v)!=NULL)
		{
			printf("node %d\n",temp_ptr->data);
			temp_ptr=temp_ptr->v;
		}
		printf("temp_ptr->data is %d\n", temp_ptr->data);
		temp_ptr->v=v_temp;
		//printf("temp_ptr->data is %d\n", (temp_ptr->v)->data);
	}
}

void add_edge(struct vertex **graph,int src,int dest)
{
	struct edge *e_temp=(struct edge*)malloc(sizeof(struct edge));
	struct vertex *temp_ptr=*graph;
	while(temp_ptr->data!=src)
	{
		temp_ptr=temp_ptr->v;
	}
	printf("source is %d\n",temp_ptr->data);
	//we have reached the src vertex, need to add edge to it
	if(temp_ptr->e==NULL)
		temp_ptr->e=e_temp;
	else
	{
		struct edge *temp_e_ptr=temp_ptr->e;
		while(temp_e_ptr->e!=NULL)
		{
			temp_e_ptr = temp_e_ptr->e;
		}
		temp_e_ptr->e = e_temp;
	}
	//now find the destination for edge

	struct vertex *temp_dest_ptr = *graph;
	while(temp_dest_ptr->data!=dest)
		temp_dest_ptr=temp_dest_ptr->v;
	printf("destingatino is %d\n",temp_dest_ptr->data);
	e_temp->connect_to=temp_dest_ptr;
}

void display_edges(struct vertex **graph)
{
	struct vertex *v_ptr=*graph;
	int src=0;
	int dest=0;
	while(v_ptr!=NULL)
	{
		src=v_ptr->data;
		struct edge *e_ptr=v_ptr->e;
		while(e_ptr!=NULL)
		{
			dest=(e_ptr->connect_to)->data;
			printf("(%d,%d) \n",src,dest);
			e_ptr=e_ptr->e;
		}
		v_ptr=v_ptr->v;
	}
}

int RecIsReachable(struct vertex *src_ptr,int dest)
{
	struct edge *temp_edge=NULL;
	
	if(src_ptr->visited)
		return 0;

	if(src_ptr->data==dest)
		return 1;
	
	src_ptr->visited=1;

	for(temp_edge=src_ptr->e; temp_edge!=NULL; temp_edge=temp_edge->e)
		if(RecIsReachable(temp_edge->connect_to,dest))
			return 1;
}

int isReachable(struct vertex **graph,int src, int dest)
{
	struct vertex *temp=*graph;
	struct vertex *src_ptr=NULL;
	while(temp!=NULL)
	{
		if(temp->data==src)
			src_ptr=temp;
		temp->visited=0;
		temp=temp->v;	
	}
	if(RecIsReachable(src_ptr,dest))
		printf("Reachable\n");
	else
		printf("Not Reachable\n");
}

void bfs_traverse(struct vertex **graph)
{
 	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue*));
	q->front=NULL;
 	q->rear=NULL;
	struct vertex *temp_ver=*graph;
	temp_ver->visited=1;
	enqueue(&q,temp_ver);

	if(isEmpty(&q))
		printf("queue is empty\n");
	else
		printf("queue is not empty\n");
	while(!isEmpty(&q))
	{
		temp_ver=NULL;
		temp_ver=dequeue(&q);
		printf("node=%d visited=%d\t",(temp_ver->data),temp_ver->visited);
		//temp_ver->visited=1;
		struct edge* temp_edge=temp_ver->e;
		while(temp_edge!=NULL)
		{
			//printf("node=%d\t",(temp_edge->connect_to)->data);
			if((temp_edge->connect_to)->visited!=1)
			{
				(temp_edge->connect_to)->visited=1;
				
				enqueue(&q,temp_edge->connect_to);
			}
			temp_edge=temp_edge->e;
		}
	}

}

int main()
{
	//struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
	//printf("%d is size of int \n",sizeof(int));
	//graph->g=NULL;
	struct vertex *graph=NULL;
	add_vertex(&graph,3);
	add_vertex(&graph,4);
	add_vertex(&graph,5);
	add_vertex(&graph,6);
	add_vertex(&graph,7);
	add_vertex(&graph,8);
	add_edge(&graph,3,4);
	add_edge(&graph,3,5);
	add_edge(&graph,4,6);
	add_edge(&graph,4,7);
	add_edge(&graph,4,8);
	add_edge(&graph,5,6);
	add_edge(&graph,6,7);
	/*display_edges(&graph);
	isReachable(&graph,3,8);*/
	bfs_traverse(&graph);
}

