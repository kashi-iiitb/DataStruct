#include <stdio.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
struct node {
  struct node *next[ALPHABET_SIZE];
  int eow;
};

struct node* create_node ()
{
  struct node * temp = malloc(sizeof(struct node));
  temp->eow = 0;
  for(int i=0; i<ALPHABET_SIZE; i++)
  {
	//printf("assigning null\n");
	temp->next[i] = NULL;
  }
  return temp;
}

void insert(struct node **head, char *str)
{
  struct node *cur = *head;
  char *ptr = str;
  while(*ptr!=NULL)
  {
	if(cur->next[*ptr-'a']==NULL)
	{
		printf("inserting %c \n",*ptr);
		cur->next[*ptr-'a'] = create_node();
	}
//	else
//		printf("char already present\n");
	cur = cur->next[*ptr-'a'];
	ptr++;
  }
  cur->eow = 1;
}

int search(struct node **head, char *str)
{
	char *ptr = str;
	struct node *cur = *head;
	while(*ptr!=NULL && cur->next[*ptr-'a']!=NULL)
	{
		cur = cur->next[*ptr-'a'];
		ptr++;
	} 
	if(*ptr!=NULL && cur->eow==1)
	{
		printf("%s is present\n",str);
		return 1;
	}
	else
	{
		printf("%s is not present\n",str);
		return 0;
	}
}

int main()
{
	struct node *head = create_node();
	char s1[32] = "kashi";
	char s2[32] = "kashinath";
	char s3[32] = "mallik";
	char s4[32] = "sneha";
	
	int i=0;
	char *ptr = s1;
	while((*ptr)!=NULL)
	{
		printf("%d ",*ptr-'a');
		ptr++;
		i++;
	}
	printf("length is %d\n",i);
	insert(&head,s1);
	insert(&head,s2);
	insert(&head,s3);
	insert(&head,s4);
	search(&head,"kashi");
	search(&head,"mallik");
	search(&head,"snehalata");
	
}
