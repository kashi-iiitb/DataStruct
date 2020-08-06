#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "bstnew.h"
/*
struct StackNode{
 struct node* data;
 struct StackNode *next;
};

struct Stack{
 struct StackNode *top;
};
*/
int push(struct Stack **stack1, struct node *num)
{
	struct StackNode *temp=(struct StackNode *)malloc(sizeof(struct StackNode *));
	if(!temp){
		printf("malloc failure\n");
		return 1;
	}
	temp->data = num;
	temp->next = (*stack1)->top;
	(*stack1)->top = temp;
	printf("pushed %p temp->data=%p\n",num,temp->data);
	return 0;
}

void pop(struct Stack **stack1, struct node **pop_elem)
{
		if((*stack1)->top==NULL)
		{
			printf("Cant Pop, the Stack is empty\n");
			return ;
		}
		struct StackNode *temp = (*stack1)->top;
		//struct node *prev = NULL;
		(*stack1)->top = ((*stack1)->top)->next;
		*pop_elem = temp->data;
		printf("popped element=%p temp->data=%p both should be same\n",*pop_elem,temp->data);
		free(temp);
}

/*void display(struct node**head)
{
	struct node *cur = *head; 
	while(cur!=NULL)
	{
		printf(" %d",cur->data);
		cur=cur->next;
	}
	printf("\n");
}*/
#if 0
int main()
{

struct Stack *stack1= (struct Stack *)malloc(sizeof(struct Stack *));
stack1->top=NULL;
int num=0;
push(&stack1,10);
push(&stack1,20);
push(&stack1,30);
push(&stack1,40);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);
pop(&stack1,&num);
printf("Popped element is %d\n",num);


 /*struct node *top=NULL;
 struct node *cur = NULL;
 int num;
 unsigned int choice;
 
 do{
  printf("Enter your choice: 1)push 2)pop 3)display 4)exit: ");
  scanf("%u",&choice);
  switch(choice)
  {
	case 1: printf("Enter the numer to push: ");
		scanf("%d",&num);
		push(&, num);
		break;
  
	case 2: printf("Enter the numer to delete: ");
		scanf("%d",&num);
		//struct node *temp=(struct node *)malloc(sizeof(struct node *));
		delete(&head, num);
		break;
	case 3:
		display(&head);
		break;
	case 4:
		break;
	default:
		printf("Enter proper choice\n"); 
		break;
 }
 }while(choice!=4);
 */
 return 0;
}
#endif
