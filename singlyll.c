#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nxt;
}*start=NULL;
struct node *nn;

void creat();
void insert_at_end();
void insert_at_beg();
void insert_at_spe();
void insert_after_pos();
void insert_after_data();
void insert_bf_pos();
void insert_bf_data();
void delete_at_end();
void delete_at_beg();
void delete_at_spe();
void delete_after_pos();
void delete_after_data();
void delete_bf_pos();
void delete_bf_data();
void display();
void main()
{
	int ch;
	while(1)
{
	printf("\n1.insert_at_end\n2.insert_at_beg\n3.insert_at_spe\n4.insert_after_pos\n5.insert_after_data\n6.insert_bf_pos\n7.insert_bf_data\n8.delete_at_end\n9.delete_at_beg\n10.delete_at_spe\n11.delete_after_pos\n12.delete_after_data\n13.delete_bf_pos\n14.delete_bf_data\n15.display\n16.exit");
	printf("\nEnter ur choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert_at_end();
			break;

		case 2: insert_at_beg();
			break;
		case 3:insert_at_spe();
			break;
		case 4:insert_after_pos();
			break;
		case 5:insert_after_data();
			break;
		case 6:insert_bf_pos();
			break;
		case 7:insert_bf_data();
			break;
		case 8:delete_at_end();
			break;
 		case 9:delete_at_beg();
			break;
		case 10:delete_at_spe();
			break;
		case 11:delete_after_pos();
			break;
		case 12:delete_after_data();
			break;
		case 13:delete_bf_pos();
			break;
		case 14:delete_bf_data();
			break;
		case 15:display();
			break;
		case 16:exit(0);
	default:printf("\nWrong choice.....");
	}
}
}
void creat()
{
	nn=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&nn->data);
	nn->nxt=NULL;
}
void insert_at_end()
{
	struct node *temp;
	creat();
	
  if(start==NULL)
  {
  start=nn;
  temp=start;
return;
  }
  temp=start;
	while(temp->nxt!=NULL)
	{
		temp=temp->nxt;
	}
  temp->nxt=nn;


}
void insert_at_beg()
{
	struct node *temp;
	creat();
	
  if(start==NULL)
  {
  start=nn;
 temp=start;
	return;
  }
  temp=start;
	
  	nn->nxt=temp;
	start=nn;
	

  }
void insert_at_spe()
{
	struct node *temp;
	int i=0,pos;
	creat();
	printf("\nEnter the position at which u want to insert:");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_at_beg();
		return;
	}
	else
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->nxt;
			if(temp==NULL)
			{
				printf("\ninvalid choice......");
				return;
			}
		}		
		nn->nxt=temp->nxt;
		temp->nxt=nn;
		printf("%d Element is inserted at %d position",nn->data,pos);
	}
	
}
void insert_after_pos()
{
	struct node *temp;
	int i=0,pos;
	temp=start;
	creat();
	printf("\nEnter a position after which u want to insert:");
	scanf("%d",&pos);
	for(i=1;i<pos;i++)
	{
		temp=temp->nxt;
		if(temp==NULL)
		{
			printf("invalid position....");
			return;
		}
	}
	nn->nxt=temp->nxt;
	temp->nxt=nn;
	printf("%d element is inserted after %d position",nn->data,pos);
}
void insert_after_data()
{
	struct node *temp;
	int i=0,data;
	temp=start;
	creat();
	printf("\nEnter the data after which u want to insert:");
	scanf("%d",&data);
	while((temp->data!=data)&&temp!=NULL)
	{
		temp=temp->nxt;
			
	}
	if(temp==NULL)
		{
			printf("invalid position....");
		}
	else
{

	nn->nxt=temp->nxt;
	temp->nxt=nn;
}
printf("%d element is inserted after %d data",nn->data,data);
}
void insert_bf_pos()
{
	struct node *temp,*ptemp;
	int i=0,pos;
	temp=start;
	
	printf("\nENter position before which u want to insert: ");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_at_beg();
		return;
	}
	else
	{
		for(i=1;i<pos;i++)
		{	
			ptemp=temp;
			temp=temp->nxt;
			if(temp==NULL)
			{
				printf("invalid position....");
				return;
			}
		}
		creat();
		ptemp->nxt=nn;
		nn->nxt=temp;
	}
printf("%d element is inserted before %d position",nn->data,pos);
}
void insert_bf_data()
{
	struct node *ptemp,*temp;
	int data;
	temp=start;
	printf("\nEnter data before which u want to insert:");
	scanf("%d",&data);
	while(temp->data!=data&&temp!=NULL)
	{	
		ptemp=temp;
		temp=temp->nxt;
		
	}
	if(temp==NULL)
	{
		printf("Invalide data....");
		return;
	}
	if(temp==start)
	{
			insert_at_beg();
			return;
	}
	else
	{
		creat();
		ptemp->nxt=nn;
		nn->nxt=temp;
	}
	printf("%d element is inserted before %d data",nn->data,data);
}
void delete_at_end()
{
	struct node *ptemp,*temp;
	temp=start;
	if(start==NULL)
	{
		printf("\nll is empty....");
		return;
	}
	while(temp->nxt!=NULL)
	{
		ptemp=temp;
		temp=temp->nxt;
	}
	printf("%d element is deleted",temp->data);
	free(temp);
	ptemp->nxt=NULL;

}
void delete_at_beg()
{
 	struct node *ptemp,*temp;
	//temp=start;
	if(start==NULL)
	{
		printf("\nll is empty....");
		return;
	}
	else
	{	temp=start;
		start=start->nxt;
		printf("%d element is deleted",temp->data);
		free(temp);	
	}
			
	
	
}
void delete_at_spe()
{
	struct node *ptemp,*temp;
	int i=0,pos;
	printf("\nEnter the position at which u want to delete:");
	scanf("%d",&pos);
	if(pos==1)
	{
		delete_at_beg();
		return;
	}
	else
	{
		temp=start;
		for(i=1;i<=pos-1;i++)
		{
			ptemp=temp;
			temp=temp->nxt;
			if(temp==NULL)
			{
				printf("\ninvalid choice......");
				return;
			}
		}		
		ptemp->nxt=temp->nxt;
		printf("%d Element is deleted at %d position",temp->data,pos);
		free(temp);
	}
	
}
void delete_after_pos()
{
	struct node *ptemp,*temp;
	int i=0,pos;
	temp=start;
	printf("\nEnter a position after which u want to delete:");
	scanf("%d",&pos);
	for(i=1;i<=pos;i++)
	{
		ptemp=temp;		
		temp=temp->nxt;
		if(temp==NULL)
		{
			printf("invalid position....");
			return;
		}
	}
	ptemp->nxt=temp->nxt;
	printf("%d element is deleted after %d position",temp->data,pos);
	free(temp);
}
void delete_after_data()
{
	struct node *ntemp,*temp;
	int i=0,data;
	temp=start;
	printf("\nEnter the data after which u want to delete:");
	scanf("%d",&data);
	while((temp->data!=data)&&temp!=NULL)
	{
		temp=temp->nxt;
			
	}
	if(temp==NULL)
	{
			printf("invalid position....");
	}
	else
	{

		ntemp=temp->nxt;
		temp->nxt=ntemp->nxt;
		printf("%d element is deleted after %d data",ntemp->data,data);
		free(ntemp);

	}
}
void delete_bf_pos()
{
	struct node *temp,*ptemp;
	int i=0,pos;
	temp=start;
	
	printf("\nENter position before which u want to delete: ");
	scanf("%d",&pos);
	if(pos==2)
	{
		delete_at_beg();
		return;
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{	
			ptemp=temp;
			temp=temp->nxt;
			if(temp==NULL)
			{
				printf("invalid position....");
				return;
			}
		}
		ptemp->nxt=temp->nxt;
	printf("%d element is deleted before %d position",temp->data,pos);
	free(temp);	
	}

}

void delete_bf_data()
{
struct node *ptemp,*temp;
	int i=0,data;
	temp=start;
	printf("\nEnter the data after which u want to delete:");
	scanf("%d",&data);
	while((temp->data==data)&&(temp!=NULL))
	{	ptemp=temp;
		
		temp=temp->nxt;
			
	}
	if(temp==NULL)
	{
			printf("invalid position....");
	}
	else
	{

		ptemp->nxt=temp->nxt;
		printf("%d element is deleted  before %d data",ptemp->data,data);
		free(temp);

	}
	
}
void display()
{
	struct node *t;
		
	if(start==NULL)
	{
		printf("list is empty!!!!");
		return;
	}
	t=start;
	while(t!=NULL)
	{
		printf("\n%d",t->data);
		t=t->nxt;
	}
}
