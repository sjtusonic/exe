double myfract(int n)
{
	double res=1.0;
	int j;
	for (j=1;j<=n;j++)
	{
		res *= j;
	}
	return(res);
}
