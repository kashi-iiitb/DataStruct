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

void remove_dupl(struct node **head)
{
 struct node *item;
 struct node *ptr;
 item = *head;
 while(item->next!=NULL)
 {
  //data = item->data;
  ptr = item;
  while(ptr->next!=NULL)
  {
   //ptr = ptr->next;
   if((ptr->next)->data==item->data)
   {
    ptr->next = (ptr->next)->next;
   }
   else
   {
    ptr = ptr->next;
   }
  }
  item = item->next;
 }
}

int main()
{
 struct node *head=NULL;
 struct node *cur = NULL;
 int num;
 unsigned int choice;
 
 do{
  printf("Enter your choice: 1)add 2)delete 3)display 4)remove_dupl 5)exit: ");
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
	case 4: remove_dupl(&head);
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
