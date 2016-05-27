// playground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void printStringVector(const vector<string>& text){
	int iter;
	cout<<"Vector count = "<<text.size()<<endl;
	cout<<"content = [";
    for (vector<string>::const_iterator iter = text.begin(); iter != text.end(); )
	{
		cout << *iter  ;
		if(++iter != text.end())
			cout << ", ";
	}
	cout<<"]"<<endl;
}

/**
 * Definition for an interval.
*/ 
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
//
bool isOverlapped(int x1, int x2, int y1, int y2)
{
    return (x1 >= y1 && x1 <= y2) ||
            (x2 >= y1 && x2 <= y2) ||
            (y1 >= x1 && y1 <= x2) ||
            (y2 >= x1 && y2 <= x2);
}
//
bool isOverlapped(Interval interval1, Interval interval2)
{
    return isOverlapped(interval1.start,interval1.end,interval2.start,interval2.end);
}
//
#define REP(i, a, b) for (int i = int(a); i <=int(b); i++) 
int getMaximumMumberOfGuests()
{
	int k, N;
	scanf("%d", &k);
	vector<Interval> guestsTimes;
	while(k--)
	{
		scanf("%d", &N);

		for(int i)
		{
			//scanf("%d", &speed);
		}
		//printf("Case %d: %d\n",++i, minSpeed);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	int result = getMaximumMumberOfGuests();
	result = testCase2();
	//
	system("pause");
}

