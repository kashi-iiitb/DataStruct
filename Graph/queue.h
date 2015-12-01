#include"graph.h"
struct Qnode{
 struct vertex* ver;
 struct Qnode *next;
};

struct Queue{
 struct Qnode *front,*rear;
};


int isEmpty(struct Queue **q);

void enqueue(struct Queue **q, struct vertex* ver);

struct vertex* dequeue(struct Queue **q);

