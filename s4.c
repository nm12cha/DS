Q1
#include <stdio.h>
void main(){
 int a[20],i,n,temp;
 printf("enter number of elements :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("enter number :");
 scanf("%d",&a[i]);
 }
 printf("/n before sorting :");
 for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
 printf("/n after sorting :");
 for(i=0;i<n;i++)
 {
 if(a[i]>a[i+1])
 {
 temp=a[i];
 a[i]=a[i+1];
 a[i+1]=temp;
 }
 }
 for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
} 
