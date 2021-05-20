#include <stdio.h>
int main ()
{
int i,j,n,N,P,d,t,k,count;
scanf ("%d",&t);
for (j=0;j<t;j++)
{
scanf ("%d",&N);
scanf ("%d",&P);
count=0;
int a[3651]={0};
for (i=0;i<P;i++)
{
scanf ("%d",&d);
n=d;
k=2;
while (d<=N)
{
if (d%7!=6&&d%7!=0)
{
if (a[d]!=1)
{
a[d]=1;
count++;
}
}
d=n*k++;
}
}
printf ("%d\n",count);
}
return 0;
}