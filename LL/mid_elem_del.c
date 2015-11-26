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

void del_mid_elem(struct node **head)
{
 struct node *mid_ptr;
 struct node *runner;
 mid_ptr = *head;
 runner = *head;

 while(runner->next!=NULL)
 {
  runner = (runner->next)->next;
  mid_ptr = mid_ptr->next;
 }

 printf("middle element of the list is %d",mid_ptr->data);
 int temp=mid_ptr->data;
 mid_ptr->data=(mid_ptr->next)->data;
 (mid_ptr->next)->data=temp;
 mid_ptr->next=(mid_ptr->next)->next;


}

int main()
{
 struct node *head=NULL;
 struct node *cur = NULL;
 int num=0,k=0;
 unsigned int choice;
 
 do{
  printf("Enter your choice: 1)add 2)delete 3)display 4)del_mid_elem 5)exit: ");
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
	case 4: //printf("Enter the value of k: ");
		//scanf("%d",&k);
		del_mid_elem(&head);
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
