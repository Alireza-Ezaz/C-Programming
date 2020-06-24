// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
   long int n, exam_time;
   long int needed_time = 0;
   long int i = 1;
    scanf("%ld %ld", &n, &exam_time);

    for(i = 1;i<=n;i++)
    {
        needed_time = 15*(n*(n+1))/2;
    }
    i=1;
    while(exam_time>=0)
    {
        exam_time = exam_time - (15*i);
        i++;
        //printf("%d\n", exam_time);
    }
    //printf("%d\n", needed_time);
    if(i-2 > n)
    {
        printf("%ld\n",n);
    }
    else
    {
        printf("%ld\n", i-2);
    }

    return 0;
}
