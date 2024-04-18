#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node {
	int data;
	struct  node *left;
	struct node *right;
	struct node *prev;
};
struct node *ptr;
void preorder(struct node *p);
void postorder(struct node *p);
struct node *create(int data);
struct node *create();
void delete(int del,struct node *p);
void insert();
int main()
{	
	int x;
	int del;
	x=1;

	struct node *p;
	printf("press 1 for inserting elements\n");
	printf("Press 2 for preorder traversal\n");
	printf("Press 3 for postorder traversal\n");
	printf("press 4 for deleting node with particular data\n");
	while(x!=0)
	{
	printf("\nEnter command : ");
	scanf("%d",&x);
	if(x==1)
	{
		insert();
	}
	else if(x==2)
	{
		preorder(ptr);
		printf("END");
	}
	else if(x==3)
	{
		postorder(ptr);
		printf("END");
	}
	else if(x==4)
	{
		printf("Enter the data to delte that node : ");
		scanf("%d",&del);
	  delete(del,ptr);
	}
	}
	return 0;
}
struct node *create(int data)
{

	struct node *n;
	n= (struct node *)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	
	return n;
	
}

void preorder(struct node *root)
{
	
	if(root!=NULL)
	{
	printf("%d-->",root->data);
	preorder(root->left);
	preorder(root->right);
    }
	
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d-->",root->data);
	}
}

void insert()
{
	int x,data;
	x=1;
	printf("Enter data for root node : ");
	scanf("%d",&data);
	struct node *p=create(data);
	ptr=p;
	while(x!=0){
	printf("\nPress 1 for going back to parent node : ");
	printf("\nPress 2 for entering node in right : ");
	printf("\nPress 3 for entering node in left : \n");
	printf("\nPress 0 to exit");
	scanf("%d",&x);

	if(x==1)
	{
		ptr=ptr->prev;
	}
	else if(x==2)
	{
		printf("Enter data for right : ");
		scanf("%d",&data);
		struct node *newnode = create(data);
		ptr->right=newnode;
		newnode->prev=ptr;
		ptr=ptr->right;
	}
	else if(x==3)
	{
		printf("Enter data for left : ");
		scanf("%d",&data);
		struct node *newnode = create(data);
		ptr->left=newnode;
		newnode->prev=ptr;
		ptr=ptr->left;
	}
}
    ptr=p;
}

void delete(int del,struct node *d)
{
	if(d->right->data!=del||d->left->data!=del)
	{
		delete(del,d->left);
		delete(del,d->right);
	}
	else if(d->right->data==del)
	{
		d->right->data==0;
	}
	else
	{
		d->left->data==0;
	}
}
