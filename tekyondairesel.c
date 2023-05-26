#include <stdlib.h>
#include <stdio.h>

struct node 
{
	int data;
	struct node *next;
};

struct node * start=NULL;
struct node * temp=NULL;
struct node * temp2=NULL;

void addbeg()
{
	int sayi;
	printf("basa eklenecek sayiyi giriniz:");
	scanf("%d",&sayi);
	struct node * eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data=sayi;
	
	if(start==NULL)
	{
		start=eklenecek;
		start->next=start;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=eklenecek;
		eklenecek->next=start;
		start=eklenecek;	
	}
}

void addbefore()
{
	int sayi , bef;
	printf("eklenecek sayiyi giriniz ve hangi sayidan once eklemek istediginizi giriniz:");
	scanf("%d %d",&sayi , &bef);
	struct node * eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data=sayi;
	
	if(start==NULL || start->data == bef) 
	{
		addbeg();
	}

	else
	{
		temp=start;
		while(temp->next->data !=bef)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		eklenecek->next=temp2;
		temp->next=eklenecek;
	
	}
}

void addend()
{
	int sayi;
	printf("sona eklenecek sayiyi giriniz:");
	scanf("%d",&sayi);
	struct node * eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data=sayi;
	
	if(start==NULL)
	{
		start=eklenecek;
		start->next=start;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=eklenecek;
		eklenecek->next=start;
	}
}

void delbeg()
{
	if(start==NULL)
	{
		printf("silinecek bir eleman yok");
	}
	else
	{
		if(start->next==start)
		{
			free(start);
			start=NULL;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp2=start->next;
			free(start);
			temp->next=temp2;
			start=temp2;
		}
	}
}
void delend()
{
	if(start==NULL)
	{
		printf("silinecek bir eleman yok");
	}
	
	else
	{
		if(start->next==start)
		{
			free(start);
			start=NULL;
		}
		else
		{
			temp=start;
			while(temp->next->next!=start)
			{
				temp=temp->next;
			}
			temp2=temp->next;
			temp->next=start;
			free(temp2);
					
		}
	}
}

void del()
{	
	int n;
	printf("silmek istediginiz sayiyi giriniz:");
	scanf("%d", &n);
	

	if(start==NULL)
	{
		printf("silinecek bir eleman yok.");
	}
	
	else
	{
		
		
		if(start->next==start && start->data==n)
		{
			free(start);
			start=NULL;
		}
		else if (start->data==n)
		{
			delbeg();
		}
		
		else 
		{
			temp=start;
			while(temp->next->data!=n)
			{
				temp=temp->next;
			}
			temp2=temp->next->next;
			free(temp->next);
			temp->next=temp2;	
		}
	}
}

void display()
{
	if(start==NULL)
	{
		printf("yazdirilacak bir eleman yok.");
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d ",temp->data);
	}
	printf("\n");
}

int main()
{
	addbeg();
	addend();
	addend();
	addend();
	addend();
	addend();
	display();
	delbeg();
	delend();
	display();
	del();
	display();
	del();
	display();
	del();
	display();
	del();
	display();
}

