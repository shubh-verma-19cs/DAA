/*C Program to find the product of two large numbers
using Divide-and-Conquer Algorithm*/
#include<stdio.h>
#include<math.h>
long max(long,long);
long multi(long,long);
int main()
{
    long num1,num2;
    printf("Enter the 2 numbers:");
    scanf("%ld %ld",&num1,&num2);
    printf("The product is: %ld",multi(num1,num2));
    return 0;
}
long max(long a, long b)
{
    long i=0;
    long j=0;
    while(a!=0)
    {
        i++;
        a/=10;
    }
    while(b!=0)
    {
        j++;
        b/=10;
    }
    if(i>=j)
        return i;
    else
        return j;
}
long multi(long a, long b)
{
    long i,j,k,l;
    long x,y,z,w,r;
    long n = max(a,b);
    if(a==0 || b==0)
        return 0;
    else if(n<=2)
        return (a*b);
    else
    {
        x = n/2;
        
        //Dividing both numbers in 2 parts
        y = a/pow(10,x);
        z = a%(int)pow(10,x);
        w = b/pow(10,x);
        r = b%(int)pow(10,x);
        
        //Applying recursion until the numbers are 2 digits or less
        i = multi(y,w);
        j = multi(z,r);
        k = multi(y+z,w+r);
        
        //Returning the complete calculated result
        return(i*pow(10,2*x)+(k-i-j)*pow(10,x)+j);
    }
}
