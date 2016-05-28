#include "common.h" // my defined macros

//10038 - Jolly Jumpers
int uva10038()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, elm, prevElm, diff;
	bool arr[3001];
	bool notJolly = false;
	while(SCAN_INT(n) != EOF)
	{
		SCAN_INT(prevElm);
		F(n-1)
		{
			SCAN_INT(elm);
			if(notJolly)
				continue;
			diff = abs(elm - prevElm);
			notJolly = diff<1 || diff>=n;
			arr[diff] = true;
			prevElm = elm;
		}
		if(!notJolly)
		{
			FT(1,n)
			{
				if(notJolly  = notJolly || !arr[k])
					break;
			}
		}
		notJolly ? PRINT_STR("Not jolly") : PRINT_STR("Jolly");
		memset(arr, 0, 1001 * sizeof(bool));
		notJolly = false;
	}
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}