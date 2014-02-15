/*
source : HDU 1005
language : C
author : ahm0011994
*/


#include<stdio.h>
#include<string.h>
int main()
{
int f[1000],d[10][10];
int a,b,n,now,o,l;
while (scanf("%d%d%d",&a,&b,&n)!=EOF)
{
if (a==0&&b==0&&n==0) break;
memset(d,0,sizeof(d));
f[1]=f[2]=1;
d[1][1]=1;
now=3;
for (;;now++)
    {
    f[now]=(a*f[now-1]+b*f[now-2])%7;
    if (d[f[now-1]][f[now]]!=0)break;
    d[f[now-1]][f[now]]=now-1;
    }
if (n<=now) printf("%d\n",f[n]);
else {
    l=(now-2)-d[f[now-1]][f[now]]+1;
    o=(n-d[f[now-1]][f[now]]+1)%l;
    if (o==0) o=l;
    printf("%d\n",f[d[f[now-1]][f[now]]-1+o]);
}
}
return 0;
}
