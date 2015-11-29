#include<stdio.h>
#include<stdlib.h>

struct node {
 int data;
 struct node *left;
 struct node *right;
};

void insert(struct node**root, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	struct node *ptr=NULL;
	if(*root==NULL)
		*root=temp;
	else
	{
		ptr=*root;
		while(ptr->left!=NULL && ptr->right!=NULL)
		{
			if(data<ptr->data)
				ptr=ptr->left;
			else
				ptr=ptr->right;
		}
		if(data<ptr->data)
			ptr->left=temp;
		else
			ptr->right=temp;
	}
}

void display_elem(struct node*ptr)
{
	//struct node* ptr=*root;
	if(ptr==NULL)
		return;
	else
		display_elem(ptr->left);
		printf("num is %d\n",ptr->data);	
		display_elem(ptr->right);
}

void delete(struct node **root,int num)
{
	struct node *ptr=*root;
	while(ptr->left!=NULL && ptr->right!=NULL)
	{
		if(data<ptr->data)
			ptr=ptr->left;
		else
			if(data>ptr->data)
				ptr=ptr->right;
			else
			{
				if(ptr->left==NULL)
					if(ptr==(ptr->parent)->left)
						(ptr->parent)->left=ptr->right;
					else
						(ptr->parent)->right=ptr->right;
				else
					if(ptr->right==NULL)
						if(ptr==(ptr->parent)->left)
							(ptr->parent)->left=ptr->left;
						else
							(ptr->parent)->right=ptr->left;
						
					else	//3rd case of deletion
						if((ptr->right)->left==NULL)
						{
							(ptr->right)->left=ptr->left;
							if(ptr==(ptr->parent)->left)
								(ptr->parent)->left=ptr->right;
							else
								(ptr->parent)->right=ptr->right;
						}
						else
						{	//4th case of deletion
							
							
						}
			}
	
	}
	
}

int main()
{
	struct node *root;//=(struct node*)malloc(sizeof(struct node*));
	//root->left = NULL;
	//root->right=NULL;
	insert(&root,10);
	insert(&root,8);
	insert(&root,6);
	insert(&root,15);
	insert(&root,4);
	insert(&root,9);
	insert(&root,3);
	display_elem(root);


return 0;
}
