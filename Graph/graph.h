 struct vertex
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
};


