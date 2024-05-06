Q1
#include<stdio.h>
struct node
{
int data;
struct node *next;
};
struct node *f;
void create()
{ int n,i;
struct node *s;
printf("Enter how many nodes ");
scanf("%d",&n);
f= (struct node *)malloc(sizeof(struct node));
printf("Enter data ");
scanf("%d",&f->data);
s=f;
for(i=1;i<n;i++)
{
s->next=(struct node*)malloc(sizeof(struct node));
s=s->next;
printf("Enter data ");
scanf("%d",&s->data);
}
s->next=NULL;
}
void display()
{ struct node *s;
for(s=f;s!=NULL;s=s->next)
{
printf("| %d |-> ",s->data);
}
}
void Delete()
{ int p,cnt=0,i;
struct node *temp,*s;
printf("Enter position to delete a node ");
scanf("%d",&p);
for(s=f;s!=NULL;s=s->next)
{ cnt++;
}
if(p==1)
{
temp=f;
f=f->next;
free(temp);
}
else if(p==cnt)
{
for(i=1,s=f;i<p-1;i++)
{ s=s->next;
}
temp=s->next;
s->next=NULL;
free(temp);
}
else if(p>1 && p<cnt)
{
for(i=1,s=f;i<p-1;i++)
{ s=s->next;
}
temp=s->next;
s->next=temp->next;
free(temp);
}
else
printf("Invalid Position ");
}
#include<stdio.h>
#include” singlylist.h”
main()
{ int ch;
do
{
printf("\n1.Create\n2.Display\n3.Delete \n0.Exit");
printf("Enter choice ");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:display();
break;
case 3:Delete();
break;
case 0:break;
default:printf("\nInvalid choice");
}
}while(ch!=0);
}
Q2
#include <stdio.h>
char s[20];
int top;
void init()
{
 top=-1;
}
int isempty(){
 if(top==-1)
 return 1;
 else
 return 0;
}
int isfull()
{
 if(top==19)
 return 1;
 else
 return 0;
}
void push(char ch)
{
 if(isfull()==1)
 printf("stack is full");
 else
 {
 top++;
 s[top]=ch;
 }
}
char pop()
{
 char ch;
 if(isempty()==1)
 printf("stack is empty");
 else
 {
 ch=s[top];
 top--;
 }
 return ch;
}
main()
{
 int i,k=0;
 char temp[20];
 init();
 char str[20];
 printf("enter string ");
 scanf("%s",str);
 for(i=0;str[i]!='\0';i++)
 {
 push(str[i]);
 }

 while(!isempty())
 {
 temp[k]=pop();
 k++;
 }

 temp[k]='\0';

 //Again String push into stack
 printf("second string :");
 for(i=0;temp[i]!='\0';i++)
 {
 push(temp[i]);
 }

 while(!isempty())
 {
 printf("%c",pop());
 }
}
