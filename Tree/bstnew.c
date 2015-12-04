#include<stdio.h>
#include<stdlib.h>

struct node {
 int data;
 struct node *left;
 struct node *right;
 struct node *parent;
};

void insert(struct node**root, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	struct node *ptr=NULL;
	if(*root==NULL)
	{
		*root=temp;
	//	((*root)->parent=NULL);
	}
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
		{
			ptr->left=temp;
			temp->parent=ptr;
		}
		else
		{
			ptr->right=temp;
			temp->parent=ptr;
		}
	}
}

struct node* tree_minimum(struct node*x)
{
	while(x->left!=NULL)
		x=x->left;
	return x;
}

struct node* successor(struct node*x)
{
	struct node *y=NULL;
	if(x->right!=NULL)
		return tree_minimum(x->right);
	y=x->parent;
	while(y!=NULL && x==(y->right))
	{
		x=y;
		y=y->parent;
	}
	return y;
}

void transplant(struct node *root,struct node*u,struct node*v)
{
	if(u->parent==NULL)
		root=v;
	else
		if(u==(u->parent)->left)
			(u->parent)->left=v;
		else
			(u->parent)->right=u;

}

void tree_delete(struct node **root,int data)
{
	struct node *y=NULL;
	struct node *root_temp=*root;
	struct node *z=*root;
	while(z->left!=NULL&& z->right!=NULL)
	{
		if(data==z->data)
			break;
		else
			if(data<z->data)
				z=z->left;
			else
				z=z->right;
	}
	if(z->left==NULL)
		transplant(root_temp,z,z->right);
	else 
		if(z->right==NULL)
			transplant(root_temp,z,z->left);
		else
			y=tree_minimum(z->right);
			if(y->parent!=z)
			{	transplant(root_temp,y,y->right);
				y->right = z->right;
				(z->right)->parent=y;
			}
			transplant(root_temp,z,y);
			y->left=z->left;
			(y->left)->parent=y;
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
/*
struct node* s=successor(ptr);
printf("successor of %d is %d\n",ptr->data,s->data);
*/
}

/*struct node* tree_minimum(struct node*x)
{
	while(x->left!=NULL)
		x=x->left;
	return x;
}
*/
int main()
{
	struct node *root=NULL;//=(struct node*)malloc(sizeof(struct node*));
	//root->left = NULL;
	//root->right=NULL;
	insert(&root,20);
	insert(&root,22);
	insert(&root,6);
	insert(&root,3);
	insert(&root,15);
	insert(&root,13);
	insert(&root,11);
	insert(&root,12);
	insert(&root,14);
	insert(&root,18);
	insert(&root,17);
	insert(&root,19);
	display_elem(root);
	tree_delete(&root,6);
	display_elem(root);
return 0;
}
