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
Q2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
 char name[20];
 int age;
}emp[10];
int readfile(struct employee a[])
{
 int i=0;
 FILE*fp;
 if((fp=fopen("emp.txt","r"))!=NULL)
 {
 while(!feof(fp))
 {
 fscanf(fp,"%s%d",&a[i].name,&a[i].age);
 i++;
 }
 }
 return i-1;
}
void InsertionSort(struct employee a[],int n)
{ int i,j;
 struct employee key;
 for(i=1; i<n; i++)
 {
 key=a[i];
 for(j=i-1; j>=0; j--)
 {
 if(strcmp(a[j].name,key.name)>0)
 {
 a[j+1]=a[j];
 }
 else
 break;
 }
 a[j+1]=key;
 }
}
void writefile(struct employee a[],int n)
{
 int i=0;
 FILE*fp;
 if((fp=fopen("insertionsort.txt","w"))!=NULL)
 {
 for(i=0;i<n;i++)
 {
 fprintf(fp,"%s %d\n",a[i].name,a[i].age);
 }
 }
}
int main()
{
 int n;
 n=readfile(emp);
 if(n==-1)
 printf("File Not Found");
 else
 {
 InsertionSort(emp,n);
 writefile(emp,n);
 printf("File Sorted");
 }
} 
