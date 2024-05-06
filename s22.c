Q1
#include<stdio.h>
int Q[20];
int f,R;
void init()
{ f=R=-1;
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
{
if(isfull()==1)
printf("Queue is Full ");
else
{
R++;
Q[R]=no;
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
#include "st_queue.h"
main()
{ int n,ch;
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
void sentinelsearch(struct city a[10],int n,int sr)
{ int i,cnt=0;
a[n]=sr;
while(strcmp(sr,a[i].name)!=0)
{ i++;
}
if(i<n)
printf("city is found and STD code is %d ",a[i].code);
else
printf("city is not found ");
}
main()
{ int n;
char sr[20];
n=readFile(ct);
if(n==-1)
printf("File not found ");
else
{
printf("Enter city name to search");
scanf("%s",sr);
SentinelSearch(ct,n,sr);
}
} 
