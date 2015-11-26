#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

void insert_front(struct node **head, int num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data = num;
	temp->next = *head;
	*head = temp;
}

void delete(struct node **head, int num)
{
		if(*head==NULL)
		{
			printf("Cant delete, list empty\n");
			return;
		}
		struct node *cur = *head;
		struct node *prev = NULL;
		if(cur->data == num)
		{
			(*head) = (*head)->next;
			free(cur);
		}
		else
		{
			while(((cur->data)!=num) && (cur!=NULL))
			{	
				prev=cur;
				cur=cur->next;
			}
			if(cur==NULL)
				printf("Number not present in list\n");
			else
			{
				prev->next = cur->next;
				free(cur);
			}
		}
}

void display(struct node**head)
{
	struct node *cur = *head; 
	while(cur!=NULL)
	{
		printf(" %d",cur->data);
		cur=cur->next;
	}
	printf("\n");
}

void add_end(struct node **head, int num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data = num;
	temp->next = NULL;
	if(*head!=NULL)
	{
		struct node *ptr;
		ptr=*head;
		while(ptr->next!=NULL)
		{
		  printf("parsing l1/l2 %d \n",ptr->data);
		  sleep(1);
		  ptr=ptr->next;
		}
		ptr->next = temp;
	}
	else
	*head = temp;
}

void mergeLL(struct node **head1, struct node **head2)
{
	struct node *ptr;
	ptr=*head1;
	while(ptr->next!=NULL)
	  ptr=ptr->next;
	ptr->next = *head2;
}

void xpartition(struct node **head,int x)
{
 struct node *l1=NULL;
 struct node *l2=NULL;
 struct node *ptr=*head;

 while(ptr!=NULL)
 {
  if(ptr->data<x)
  {
	printf("in while %d \n",ptr->data);
	insert_front(&l1,ptr->data);
  }
  else
  {
	printf("inwhile %d \n",ptr->data);
	insert_front(&l2,ptr->data);
  } 
  ptr=ptr->next;
}
printf("the lists are: \n");
 display(&l1);
 display(&l2);
 mergeLL(&l1,&l2);
 *head = l1;
}

int main()
{
 struct node *head=NULL;
 struct node *cur = NULL;
 int num=0,x=0;
 unsigned int choice;
 
 do{
  printf("Enter your choice: 1)add 2)delete 3)display 4)partition 5)exit: ");
  scanf("%u",&choice);
  switch(choice)
  {
	case 1: printf("Enter the numer to insert: ");
		scanf("%d",&num);
		insert_front(&head, num);
		break;
  
	case 2: printf("Enter the numer to delete: ");
		scanf("%d",&num);
		//struct node *temp=(struct node *)malloc(sizeof(struct node *));
		delete(&head, num);
		break;
	case 3:
		display(&head);
		break;
	case 4: printf("Enter the value of x around which the list will be partitioned: ");
		scanf("%d",&x);
		xpartition(&head,x);
		break;
	case 5: 
		break;
	default:
		printf("Enter proper choice\n"); 
		break;
 }
 }while(choice!=5);
 
 return 0;
}
