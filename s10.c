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
struct employee
{
char name[20];
int age;
}emp[10];
int readfile(struct employee a[10])
{
int i=0;
FILE*fp;
if((fp=fopen("empl.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",a[i].name ,&a[i].age);
i++;
}
}
return i-1;
}
void writefile(struct employee a[],int n)
{
int i;
FILE *fp;
if((fp=fopen("bsort.txt","w"))!=NULL)
{
for(i=0;i<n;i++)
{
fprintf(fp,"%s %d \n",a[i].name ,a[i].age);
}
}
}
void bubblesort(struct employee a[],int n)
{
int i,j;
struct employee temp;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1;j++)
{
if(strcmp(a[j].name,a[j+1].name)>0)
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
main()
{
int n;
n=readfile(emp);
if(n==-1)
printf("File is not found");
else
{
bubblesort(emp,n);
writefile(emp,n);
printf("File is found");
}
}
