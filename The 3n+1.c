#include<stdlib.h>
#include<stdio.h>
int fun(int a, int b);
int main()
{
    int a, b,x;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        x=fun(a,b);
        printf("%d %d %d\n",a,b,x);
    }
  
    return 0;
}
int fun(int a, int b)
{
    int x, count=1, max=0;
    if(a>b){
        int temp=a;
        a=b;
        b=temp;
    }
     while(a<=b)
    {
        x=a;
        while(x!=1)
        {
            if(x%2==0)
            {
                x=x/2;
            }
            else
            {
                x=(3*x)+1;
            }
            count=count+1; 
            if(x==1)
            {
                break;
            }
        }
        if(count>max)
        {
            max=count;
        }
        count=1;
        a++;
    }
    return max;
}