Q1
#include<stdio.h>
main()
{ int i,a[10],n,min,pos,j,temp;
printf("Enter how many elements ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
printf("\nBefore array sorting ");
for(i=0;i<n;i++)
{ printf("%d ",a[i]);
}
for(j=0;j<n-1;j++)
{
min=a[j];
pos=j;
for(i=j+1;i<n;i++)
{ if(a[i]<=min)
{ min=a[i];
pos=i;
}
}
temp=a[j];
a[j]=min;
a[pos]=temp;
}
printf("\nSorted array is ");
for(i=0;i<n;i++)
{ printf("%d ",a[i]);
}
} 
Q2
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *f,*r;
void init()
{
f=NULL;
r=NULL;
}
int isempty()
{
if(f==NULL)
 return 1;
else
 return 0;
}
void enqueue()
{
struct node*nw;
int n;
nw=(struct node*)malloc(sizeof(struct node));
nw->data=n;
nw->next=NULL;
if(f==NULL)
{
f=nw;
r=nw;
}
else
{
r->next=nw;
r=r->next;
}
}
int dequeue()
{
int n;
struct node *temp;
if(isempty()==1)
printf("queue is empty");
else
{
temp=f;
f=f->next;
n=temp->data;
free(temp);
}
}
int peek()
{
return f->data;
}
#include<stdio.h>
#include" dyqueue.h "
main()
{
int ch,no;
init();
do
{
printf("\n1.enqueue \n2.dequeue \n3.peek \n0.exit");
printf("enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter data:");
 scanf("%d",&no);
 enqueue(no);
 break;
case 2:if(isempty()==1)
 printf("\n queue is empty");
 else
 printf("dequeue element=%d",dequeue());
 break;
 case 3:printf("top element =%d",peek());
 break;
case 0:break;
}
}while(ch!=0);
} 

