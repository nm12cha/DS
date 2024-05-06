Q1
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
mergesort(struct employee a[10],int lb,int ub)
{ int mid;
if(lb<ub)
{
mid=(lb+ub)/2;
mergesort(a,lb,mid);
mergesort(a,mid+1,ub);
merge(a,lb,mid,ub);
}
}
merge(struct employee a[10],int lb,int mid,int ub)
{
struct employee b[20];
int k,i,j;
k=0;
i=lb;
j=mid+1;
while(i<=mid && j<=ub)
{
//if(a[i]<=a[j])
if(strcmp(a[i].name,a[j].name)<0)
{ b[k]=a[i];
i++;
k++;
}
else
{ b[k]=a[j];
j++;
k++;
}
}
while(i<=mid)
{
b[k]=a[i];
i++;
k++;
}
while(j<=ub)
{
b[k]=a[j];
j++;
k++;
}
for(i=lb,k=0;i<=ub;k++,i++)
{
a[i]=b[k];
}
}
void writeFile(struct employee a[],int n)
{
int i=0;
FILE *fp;
if((fp=fopen("sortedemp_merge.txt","w"))!=NULL)
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
mergesort(emp,0,n-1);
writeFile(emp,n);
printf("File Sorted ");
}
} 
Q2
#include<stdio.h>
#include<stdlib.h>
struct node
{ int coeff,exp;
 struct node *next;
};
struct node* create(struct node *f)
{
 int i,n;
 struct node *s;
 printf("\nEnter no of terms ");
 scanf("%d",&n);
 printf("Enter term in descending order of power ");
 f=(struct node *)malloc(sizeof(struct node));
 printf("\n Enter coeff");
 scanf("%d",&f->coeff);
 printf("\n Enter power ");
 scanf("%d",&f->exp);
 s=f;
 for(i=1;i<n;i++)
 {
s->next=(struct node *)malloc(sizeof(struct node));
s=s->next;
printf("\n Enter coeff");
 scanf("%d",&s->coeff);
 printf("\n Enter power ");
 scanf("%d",&s->exp);
}
s->next=NULL;
return f;
}
void display(struct node *f)
{ struct node *s;
 for(s=f;s!=NULL;s=s->next)
 { printf("%dx^%d ->",s->coeff,s->exp);
 }
}
struct node *Add(struct node *p1,struct node *p2)
{
struct node *t1,*t2,*t3=NULL,*nw;
struct node *p3;
t1=p1;t2=p2;
printf("\n%d %d",t1->exp,t2->exp);
while(t1!=NULL && t2!=NULL)
{ nw=(struct node*)malloc(sizeof(struct node));
nw->next=NULL;
if(t1->exp > t2->exp)
{
nw->exp=t1->exp;
nw->coeff=t1->coeff;
t1=t1->next;
}
else if(t2->exp > t1->exp)
{
nw->exp=t2->exp;
nw->coeff=t2->coeff;
t2=t2->next;
}
else
{ nw->exp=t1->exp;
nw->coeff=t1->coeff+t2->coeff;
t1=t1->next;
t2=t2->next;
}
if(t3==NULL)
{ p3=nw;
t3=nw;
}
else
{ t3->next=nw;
t3=t3->next;
}
}
while(t1!=NULL)
{
nw=(struct node*)malloc(sizeof(struct node));
nw->next=NULL;
nw->exp=t1->exp;
nw->coeff=t1->coeff;
t1=t1->next;
t3->next=nw;;
t3=t3->next;
}
while(t2!=NULL)
{
nw=(struct node*)malloc(sizeof(struct node));
nw->next=NULL;
nw->exp=t2->exp;
nw->coeff=t2->coeff;
t2=t2->next;
t3->next=nw;
t3=t3->next;
}
return p3;
}
main()
{ struct node *p1=NULL,*p2=NULL,*p3=NULL;
 p1=create(p1);
 p2=create(p2);

printf("\n 1st Polynomial is : ");
 display(p1);
 printf("\n 2nd Polynomial is : ");
 display(p2);
 p3=Add(p1,p2);
printf("\n Addition of 2 Polynomial is ");
display(p3);

} 
