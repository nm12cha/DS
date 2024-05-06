Q1
#include<stdio.h>
void quicksort(int a[10],int lb,int ub);
main()
{ int n ,a[10],i,sr,j,temp;
printf("\n enter no of elements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
//printf("Enter no ");
a[i]=rand()%100;
}
printf("\n Before sorted array is ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
quicksort(a,0,n-1);
printf("\n Sorted array is ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
void quicksort(int a[10],int lb,int ub)
{ int key,temp,i,j;
if(lb<ub)
{
i=lb+1;
key=a[lb];
j=ub;
while(i<=j)
{
while(a[i]<=key && i<=ub)
i++;
while(a[j]>key && j>=lb)
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
Q2
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
#include"cststack.h"
void main()
{
char str[20];
int count=0,i;
char ch;
printf("enter string");
scanf("%s",str);
init();
for(i=0;i<=str[i]!='\0';i++)
{
push(str[i]);
}
for (i=0;i<=strlen(str)/2;i++)
{
ch = pop();
if(ch!=str[i])
{
count++;
break;
}
}
if(count==0)
{
printf("The string is palindrome");
}
else
{
printf("The string is not palindrome");
}
}
