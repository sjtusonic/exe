#include <stdio.h>
double myfract(int n)
{
	double res=1.0;
	printf("CPP:n=%d\n",n);
	int j;
	for (j=1;j<=n;j++)
	{
		printf("CPP:j=%d\n",j);
		res *= j;
	}
	printf("CPP:res=%f\n",res);
	return res;
	//return 9.9;
}
