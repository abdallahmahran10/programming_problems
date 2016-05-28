#include "common.h" // my defined macros


//11340 - Newspaper
int uva11340()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
        
#endif
	// Your code is here //////////////////////////
	map<char , int> charsValues;
	int v, linesCount;
	char ch;
	IN(tc);
	string line;
	double total;
	while(tc--)
	{
		total = 0;
		IN(n);
		getline(cin, line);
		F(n)
		{
			ch = getchar() ;
			SCAN_INT(v);
			charsValues[ch] = v;
			getline(cin, line);
		}
		SCAN_INT(linesCount);
		getline(cin, line);		
		F(linesCount)
		{
			getline(cin, line);
			F2(line.length())
				total += charsValues[line[j]]; // map return default value(0) in case key does not exist
			
		}
		printf("%.2f$\n",total/100);
		charsValues.clear();
	}
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}