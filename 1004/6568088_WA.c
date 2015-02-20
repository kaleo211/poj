#include<stdio.h>
int main()
{
	double k,a=0;
	int i=12;
	while(i--)
	{
	 scanf("%lf",&k);
	  a=a+k;
	}
	printf("$%0.2lf\n",a/12);
 return 0;
}
