Q1
/* Insertion sort on random nos */
#include<stdio.h>
int main()
{
 int a[10],i,j,n,key;
 printf("Enter how many numbers: ");
 scanf("%d",&n);

 for(i=0; i<n; i++)
 {
a[i]=rand()%100;
 }
 printf("\n Before sorting array is ");
 for(i=0;i<n;i++)
 {
printf("%d ",a[i]);
 }
 for(i=1; i<n; i++)
 {
 key = a[i];
 for(j=i-1; j>=0; j--)
 {
 if(a[j] > key)
 {
 a[j+1]=a[j];
 }
 else
 break;
 }
 a[j+1]=key;
 }

 printf("\nAfter sort array is: ");
 for(i=0; i<n; i++)
 {
 printf("%d ",a[i]);
 }
} 
Q2
#include<stdio.h>
#include<string.h>
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
void postfix_eval(char str[20])
{ int i,op1,op2,val;
for(i=0;str[i]!='\0';i++)
{ switch(str[i])
{
case '+': op2=pop();
op1=pop();
push(op1+op2);
break;
case '-': op2=pop();
op1=pop();
push(op1-op2);
break;
case '*': op2=pop();
op1=pop();
push(op1*op2);
break;
case '/': op2=pop();
op1=pop();
push(op1/op2);
break;
default:printf("Enter value of %c ",str[i]);
scanf("%d",&val);
push(val);
}
}
printf("Ans =%d ",pop());
}
main()
{ char str[20];
printf("Enter postfix string ");
scanf("%s",str);
postfix_eval(str);
} 