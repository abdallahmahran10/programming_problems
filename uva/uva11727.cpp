#include "common.h" // my defined macros

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