#include "common.h" // my defined macros


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