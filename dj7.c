#include<stdio.h>
int main()
{
char a[12] = {'a','b','c','d','f','e','s','a','a','f','f','g'};
int i, j ;
char last ;
for(i=0;i<12;i++)
{
for(j=i+1;j<12;j++)
{
if(a[i]==a[j])
last = a[i];
}
}
printf("last repeated character= %c",last);
return 0 ;
}
