Q1
#include<stdio.h>
void linearsearch(int a[10],int n,int sr)
{ int i,p,cnt=0;
for(i=0;i<n;i++)
{
if(a[i]==sr)
{ p=i; //store position
cnt++;
break;
}
}
if(cnt>=1)
printf("element found at %d position",p);
else
printf("element NOT found ");
}
main()
{
int n,i,sr,a[10];
printf("enter how many values");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter values");
scanf("%d",&a[i]);
}
printf("\n enter search element");
scanf("%d",&sr);
linearsearch(a,n,sr);
} 




