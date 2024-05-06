Q1
#include<stdio.h>
char s[20];
int top;
void init()
{
top=-1;
}
int isempty()
{ if(top==-1)
return 1;
else return 0;
}
int isfull()
{ if(top==19)
return 1;
else
return 0;
}
void push(char data)
{
if(isfull()==1)
printf("\nStack is full ");
else
{ top++;
s[top]=data;
}
}
char pop()
{ char data;
if(isempty()==1)
printf("\nStack is empty ");
else
{ data=s[top];
top--;
return data;
}
}
int peek()
{ return s[top];
}
#include<stdio.h>
#include<stdlib.h>
#include"sstack.h"
main()
{
int n,i=0,ch;
init();
do
{
printf("\n1.push \n2.pop \n3.chech stack is empty or not
\n4.chech stack is full or not \n5.Peek \n0.exit");
printf("\neneter your choice ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("enter elements");
scanf("%d",&n);
push(n);
break;
case 2:printf("\ndeleted elements :%d",pop());
break;
case 3:if(isempty()==1)
printf("stack is empty");
else
printf("stack is not empty");
break;
case 4:if(isfull()==1)
printf("stack is full");
else
printf("stack is not full");
break;
case 5:printf("\ntop of elements:%d",peek());
break;
case 0: break;
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
int readFile(struct employee a[])
{
int i=0;
FILE *fp;
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
void quicksort(struct employee a[10],int lb,int ub)
{ int i,j;
struct employee key,temp;
if(lb<ub)
{
i=lb+1;
key=a[lb];
j=ub;
while(i<=j)
{
while(a[i].age<=key.age && i<=ub)
i++;
while(a[j].age>key.age && j>=lb)
j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
//swap key and a[j]
temp=a[j];
a[j]=a[lb];
a[lb]=temp;
quicksort(a,lb,j-1);
quicksort(a,j+1,ub);
}
}
void writeFile(struct employee a[],int n)
{
int i=0;
FILE *fp;
if((fp=fopen("sortedemp_quick_age.txt","w"))!=NULL)
{
for(i=0;i<n;i++)
{ fprintf(fp,"%s %d\n",a[i].name,a[i].age);
}
}
}
main()
{ int n;
n=readFile(emp);
if(n==-1)
printf("File not found ");
else
{
quicksort(emp,0,n-1);
writeFile(emp,n);
printf("File Sorted ");
}
}