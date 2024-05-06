Q1
#include<stdio.h>
int Q[20];
int f,R;
void init()
{
f=R=-1;
}
int isempty()
{
if(f==R)
return 1;
else
return 0;
}
int isfull()
{
if(R==19)
return 1;
else return 0;
}
void Add(int no)
{ int i;
if(isfull()==1)
printf("Queue is Full ");
else
{
for(i=R;i>f;i--)
{ if(no<Q[i])
Q[i+1]=Q[i];
else
break;
}
Q[i+1]=no;
R++;
}
}
int Delete()
{ int no;
if(isempty()==1)
printf("Queue is empty ");
else
{
f++;
no=Q[f];
}
return no;
}
void display()
{
int i;
for(i=f+1;i<=R;i++)
{ printf("%d ",Q[i]);
}
}
#include<stdio.h>
#include "PriorityQ.h"
main()
{
int n,ch;
init();
do
{
printf("\n\n1.Add \n2.Delete \n3.Display \n0.EXit");
printf("\nEnter choice ");
scanf("%d",&ch);
switch(ch)
{ case 1:printf("\nEnter element ");
scanf("%d",&n);
Add(n);
break;
case 2:if(isempty()==1)
printf("\nQueue is empty ");
else
printf("deleted elemet =%d
",Delete());
break;
case 3:display();
break;
case 0:break;
default:printf("\nInvalid choice ");
}
}while(ch!=0);
}    
Q2
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
if((fp=fopen("sortedfile.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",&a[i].name,&a[i].code);
i++;
}
}
return i-1;
}
int binarysearch(struct city a[10],int lb,int ub,char sr[20])
{
int mid=0;
while(lb<=ub)
{
mid=(lb+ub)/2;
if(strcmp(a[mid].name,sr)==0)
return mid;
else if(strcmp(sr,a[mid].name)<0)
ub=mid-1;
else
lb=mid+1;
}
return -1;
}
main()
{ int n,p;
char sr[20];
n=readFile(ct);
if(n==-1)
printf("File not found ");
else
{
printf("Enter city name to search ");
scanf("%s",sr);
p=binarysearch(ct,0,n,sr);
if(p>=0)
printf("\nCity is found and code =%d ",ct[p].code);
else
printf("\nCity not found ");
}
} 
