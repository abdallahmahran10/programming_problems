#include "common.h" // my defined macros


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
