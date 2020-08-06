#ifndef MYSTACK_H
#define MYSTACK_H

struct StackNode{
	 struct node* data;
	  struct StackNode *next;
};

struct Stack{
	 struct StackNode *top;
};
int push(struct Stack **stack1, struct node *num);
void pop(struct Stack **stack1, struct node **pop_elem);
#endif
