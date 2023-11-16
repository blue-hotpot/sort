#include<stdio.h>
#define N 6

int main(int argc, char const *argv[])
{
    int a[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    int ret=0;
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(a[j]>a[j+1])
            {
                ret=a[j];
                a[j]=a[j+1];
                a[j+1]=ret;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
