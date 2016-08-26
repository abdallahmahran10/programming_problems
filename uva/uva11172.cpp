#include "common.h" // my defined macros


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
