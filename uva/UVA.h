
#include<stdio.h>

int uva11799()
{
	int minSpeed ;
	int k, N, speed;
	scanf("%d", &k);
	for(int i=0; i<k; )
	{
		minSpeed = 1;
		scanf("%d", &N);
		while(N--)
		{
			scanf("%d", &speed);
			if(speed> minSpeed)
				minSpeed = speed;
		}
		printf("Case %d: %d\n",++i, minSpeed);
	}
	return 0;
}

int uva11559()
{
	int N, budget, H, w, k,bedPrice,bedCount,price;
	//scanf("%d", &k);
	const int max =  200 * 500000;
	int minCost;
	while (scanf("%d %d %d %d", &N, &budget, &H, &w) != EOF)
	{
		minCost = max;
		for(int hotelIdx=0; hotelIdx < H; hotelIdx++)
		{
			scanf("%d", &bedPrice );
			for(int weekIdx = 0; weekIdx < w; weekIdx++)
			{
				scanf("%d", &bedCount);
				if(bedCount>=N)
				{
					price = N*bedPrice;
					if(price< minCost)
						minCost = price;
				}
			}
		}
		if (minCost != max && minCost <= budget)
			printf("%d\n", minCost);
		else
			printf("stay home\n");
	}
	return 0;
}

int uva11727()
{
	int tc=1,k,s1,s2,s3;
	scanf("%d", &k);
	while(k--)
	{
		scanf("%d %d %d", &s1, &s2, &s3);
		if(s1>s2)
		{
			if(s1>s3 )
			{
				if(s2>s3)
					printf("Case %d: %d\n", tc++, s2);
				else 
					printf("Case %d: %d\n", tc++, s3);
			} else 
				printf("Case %d: %d\n", tc++, s1);
		} else
		{
			if(s2>s3)
			{
				if(s1>s3)
					printf("Case %d: %d\n", tc++, s1);
				else 
					printf("Case %d: %d\n", tc++, s3);
			} else 
				printf("Case %d: %d\n", tc++, s2);
		}
	}
	return 0;
}

void uva11498()
{
	int k=0;
	int dpx,dpy, x,y;
	scanf("%d",&k );
	while(k)
	{
		scanf("%d %d", &dpx, &dpy);
		while(k--)
		{
			scanf("%d %d", &x, &y);
			if(x==dpx || y == dpy )
				printf("divisa\n");
			else
			{
				if((x-dpx)>0)
				{
					if((y-dpy)<0)
						printf("SE\n");
					else
						printf("NE\n");
				} else
				{
					if((y-dpy)<0)
						printf("SO\n");
					else
						printf("NO\n");
				}
			}
		}
		scanf("%d",&k );
	}
}

void uva11172()
{
	int k=0;
	scanf("%d",&k );
	while(k--)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		if(a == b)
			printf("=\n");
		else
			a>b? printf(">\n"):printf("<\n");
	}
}
