#include <stdio.h>

struct node
{
	int value;
	struct node *next;
};

struct node *root=NULL;

void append(int num)
{
	struct node *newp;
	struct node *p;
	
	newp = (struct node*)malloc(sizeof(struct node));
	
	newp->value = num;
	newp->next = NULL;
	
	if(root == NULL)
	{
		root = newp;
	}
	else
	{
		p = root;
		while(p->next !=NULL)
		{
			p = p->next;
		}
		p->next = newp; 
	}
}

void display (void)
{
	struct node *p;
	p = root;
	while(p!= NULL)
	{
		printf("%d  ",p->value);
		p = p->next;
	}
}

void delete(int value)
{
 struct node *p,*q;
 p = root; 
 while(p!=NULL)
 {
	 
	 if(p->value == value)
	 {
		q->next = p->next;
		free(p);
		break;		  
	 }
	 else 
	 {
		q=p; 
		p =p->next;
	  }  
	
 } 
}

void addHead(int value)
{
	struct node *newp,*p;
	p =root;
	newp = (struct node*)malloc(sizeof(struct node));
	
	newp->value = value;
	
	newp->next = p->next;
	
	root = newp;
	
	root->next = p;
	
}

void insertAfterNode(int value, int pos)
{
	struct node *newp,*p,*q;
	int i=0;
	newp = (struct node*)malloc(sizeof (struct node));
	p=root;
	for(i=0;i<pos;i++)
	{
		p = p->next;
		i++;
		
	}
	q=p;	
	newp->value = value;
	newp->next = q->next;  
	p->next = newp; 
	 
	
}
int main (void)
{
	append (1);
	append (2);
	append (3);
	append (4);
	append (5);
	printf("\n print linklist\n");
	display();
	printf("\n delete link_list node\n");
	delete (2);
	printf("\n print linklist\n");
	display();
	addHead(0);
	printf("\n print linklist after adding node at root\n");
	display();
	insertAfterNode(8,2);
	printf("\n print linklist after insertting node at posisition 2 and valu 8\n");
	display();
	return 1;
	
}