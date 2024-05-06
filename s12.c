Q1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct city
{
char name[20];
int code;
}ct[10];
int readFile(struct city a[])
{
int i=0;
FILE *fp;
if((fp=fopen("city.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",&a[i].name,&a[i].code);
i++;
}
}
return i-1;
}
void linearsearch(struct city a[10],int n,char sr[20])
{ int i,p,cnt=0;
for(i=0;i<n;i++)
{
if(strcmp(a[i].name,sr)==0)
{ p=i; //store position
cnt++;
break;
}
}
if(cnt>=1)
printf("city is found and code is %d ",a[p].code);
else
printf("city NOT found ");
}
main()
{ int n;
char sr[20];
n=readFile(ct);
if(n==-1)
printf("File not found ");
else
{
printf("Enter city name to search ");
scanf("%s",sr);
linearsearch(ct,n,sr);
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
struct node *r;
void init()
{
r=NULL;
}
int isempty()
{
if(r==NULL)
return 1;
else
return 0;
}
void Add(int n)
{
struct node *nw;
nw=(struct node *)malloc(sizeof(struct node));
nw->data=n;
if(r==NULL)
{
r=nw;
r->next=r;
}
else
{
nw->next=r->next;
r->next=nw;
r=r->next;
}
}
int Delete()
{
int no;
struct node *temp;
temp=r->next;
if(r==temp->next)
{ r=NULL;
}
else
{
r->next=temp->next;
}
no=temp->data;
free(temp);
return (no);
}
int peek()
{
return r->next->data;
}
#include<stdio.h>
#include "cir_queue.h"
main()
{ int ch,no;
init();
do
{
printf("\n1.Add \n2.Delete \n0.Exit");
printf("Enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n Enter element");
scanf("%d",&no);
Add(no);
break;
case 2:if(isempty()==1)
printf("\n Queue is empty");
else
{
printf("deleted
element is %d",Delete());
break;
}
case 0:break;
case 4:printf("Elemenent at peek %d ",peek());
break;
default:printf("Invalid choice");
}
}while(ch!=0);
}
