#include "common.h" // my defined macros

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