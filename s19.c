Q1
#include<stdio.h>
main()
{ int i,a[10],n,min,pos,j,temp;
printf("Enter how many elements ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
printf("\nBefore array sorting ");
for(i=0;i<n;i++)
{ printf("%d ",a[i]);
}
for(j=0;j<n-1;j++)
{
min=a[j];
pos=j;
for(i=j+1;i<n;i++)
{ if(a[i]<=min)
{ min=a[i];
pos=i;
}
}
temp=a[j];
a[j]=min;
a[pos]=temp;
}
printf("\nSorted array is ");
for(i=0;i<n;i++)
{ printf("%d ",a[i]);
}
}