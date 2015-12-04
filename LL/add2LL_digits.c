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

void add2LL_digits( struct node **head1, struct node **head2, struct node **head3)
{
 struct node *l1=*head1;
 struct node *l2=*head2;
 struct node *l3=NULL;
 int data=0,carry = 0;
 int num=0;
 while(l1!=NULL && l2!=NULL)
 {
	num = l1->data+l2->data+carry;
	if(num>=10)
	{
		printf("\nnum is %d",num);
		data = num%10;
		carry = num/10;
	}
	else
	{
		printf("\nnum is %d",num);
		//data = num%10;
		data = num;
		carry = 0;
	}
		struct node *temp=(struct node *)malloc(sizeof(struct node *));
		temp->data = data;
		temp->next = NULL;
	if(l3!=NULL)
	{
		//printf("l3!=NULL: inserted %d", l3->data);
		l3->next = temp;
		l3 = l3->next;
		printf("l3!=NULL: inserted %d", l3->data);
	}
	else
	{
		//printf("l3==NULL: inserted %d", data);
		l3 = temp;
		*head3 = l3;
		printf("l3==NULL: inserted %d", l3->data);
	}
	l1 = l1->next;
	l2 = l2->next;
 }
 if(l1==NULL&&l2==NULL)
	return;
 else
	if(l1==NULL)
	{	
		while(l2!=NULL)
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node *));
			temp->data = l2->data;
			temp->next = NULL;
			l3->next = temp;
		}
	}
	else
	{
		while(l1!=NULL)
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node *));
			temp->data = l1->data;
			temp->next = NULL;
			l3->next = temp;
		}
		
	}

}

int main()
{
 struct node *head1=NULL;
 struct node *head2= NULL;
 int num=0,x=0;
 struct node *head3= NULL;
 unsigned int choice;

 insert_front(&head1,2);
 insert_front(&head1,3);
 insert_front(&head1,4);
 insert_front(&head1,5);
 
 insert_front(&head2,1);
 insert_front(&head2,2);
 insert_front(&head2,3);
 insert_front(&head2,4);

 add2LL_digits(&head1,&head2,&head3);
 display(&head1);
 display(&head2);
 display(&head3);
/*
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
 */
 return 0;
}
