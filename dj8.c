#include<stdio.h>
int main()
{
int a[10] = {1,2,5,5,5,3,4,4,5,6};
int i, j, count, max = 0, num;
    for(i = 0; i < 10; i++)
    {
        count = 0;
        for(j = 0; j < 10; j++)
        {
            if(a[i] == a[j])
                count++;
        }
        if(count > max)
        {
            max = count;
            num = a[i];
        }
    }
    printf("Most repeated number = %d", num);
    return 0;
}
