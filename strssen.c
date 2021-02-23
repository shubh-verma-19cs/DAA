/*C Program for matrix multiplication of 2x2 matrices
using Strassen's Algorithm*/
#include<stdio.h>
int main()
{
	int a[2][2],b[2][2],i,j;
	int p,q,r,s,t,u,v;
	printf("\nArray 1:");
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	printf("\nArray 2:");
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			scanf("%d",&b[i][j]);

	p=a[0][0]*(b[0][1]-b[1][1]);
	q=(a[0][0]+a[1][1])*b[1][1];
	r=(a[1][0]+a[1][1])*b[0][0];
	s=a[1][1]*(b[1][0]-b[0][0]);
	t=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	u=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	v=(a[0][0]-a[1][0])*(b[0][0]+b[0][1]);

	int c[2][2]={{t+s-q+u,p+q},{r+s,p+t-r-v}};
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
