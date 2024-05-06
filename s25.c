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
#include "stack.h"
int priority(char ch)
{ switch(ch)
{
case '(':return 0;
case '+':
case '-':return 1;
case '*':
case '/':return 2;
case '^':
case '$':return 3;
}
return 0;
}
void convert(char str[20])
{
int i,j=0;
char post[20],ch,ch1;
init();
for(i=0;str[i]!='\0';i++)
{ ch=str[i];
switch(ch)
{
case '(':push(ch);
break;
case '+':
case '-':
case '*':
case '/':
case '$':
case '^':
while(!isempty() && (priority(peek())>=priority(ch)))
{
post[j]= pop();
j++;
}
push(ch);
break;
case ')':while((ch1=pop())!='(')
{ post[j]=ch1;
j++;
}
break;
default:post[j]=ch;
j++;
}
}
while(!isempty())
{ post[j]=pop();
j++;
}
post[j]='\0';
printf("\n Postfix string = %s ",post);
}
main()
{
char infix[20];
printf("\nEnter the infix expression ");
scanf("%s",infix);
convert(infix);
}
