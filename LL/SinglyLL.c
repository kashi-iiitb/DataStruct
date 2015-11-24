#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

int main()
{
 struct node *head=NULL;
 struct node *cur = NULL;
 int num;
 unsigned int choice;
 
 do{
  printf("Enter your choice: 1)add 2)delete 3)display 4)exit: ");
  scanf("%u",&choice);
  switch(choice)
  {
	case 1: printf("Enter the numer to insert: ");
		scanf("%d",&num);
		struct node *temp=(struct node *)malloc(sizeof(struct node *));
		temp->data = num;
		temp->next = head;
		head = temp;
		break;
  
	case 2: printf("Enter the numer to delete: ");
		scanf("%d",&num);
		//struct node *temp=(struct node *)malloc(sizeof(struct node *));
		if(head==NULL)
		{
			printf("Cant delete, list empty\n");
			break;
		}
		cur = head;
		struct node *prev = NULL;
		if(cur->data == num)
		{
			head = head->next;
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
		break;
	case 3:
		cur=head;
		while(cur!=NULL)
		{
			printf(" %d",cur->data);
			cur=cur->next;
		}
		printf("\n");
		break;
	case 4:
		break;
	default:
		printf("Enter proper choice\n"); 
		break;
 }
 }while(choice!=4);
 
 return 0;
}
