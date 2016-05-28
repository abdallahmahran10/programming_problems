// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h"
#include <algorithm>    // std::sort

class Interval {
public:
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
	  bool operator<(const Interval &interval2) const { return start < interval2.start; }
};
//
bool isOverlapped(int x1, int x2, int y1, int y2)
{
    return (x1 > y1 && x1 < y2) ||
            (x2 > y1 && x2 < y2) ||
            (y1 > x1 && y1 < x2) ||
            (y2 > x1 && y2 < x2);
}
//
bool isOverlapped(Interval interval1, Interval interval2)
{
    return isOverlapped(interval1.start,interval1.end,interval2.start,interval2.end);
}
// 
int getMaximumMumberOfGuests(vector<Interval>& guestsTimes)
{
	int indexes[1001] = {0};
	for(vector<Interval>::iterator iter = guestsTimes.begin() ; iter != guestsTimes.end(); ++iter)
	{
		LOOP(i, iter->start, iter->end)
		{
			indexes[i]++;			
		}
	}	
	sort(indexes,indexes+1001);  
	return indexes[1000];
}
//
int getMaximumMumberOfGuests()
{
	int k, N, t;
	SCAN_INT(k);
	vector<Interval> guestsTimes;
	while(k--)
	{
		SCAN_INT(N);
		LOOP(i,0,N)
		{
			SCAN_INT(t);
			guestsTimes.push_back(Interval(t,0));
		}
		LOOP(i,0,N)
		{
			SCAN_INT(t);
			guestsTimes[i].end = t;
		}
		PRINT_INT(getMaximumMumberOfGuests(guestsTimes));
		guestsTimes.clear();
	}
	return 0;
}

void testCase0()
{
	vector<Interval> guestsTimes;
	guestsTimes.push_back(Interval(13,19));
	guestsTimes.push_back(Interval(6,18));
	guestsTimes.push_back(Interval(5,6));
	guestsTimes.push_back(Interval(8,9));
	guestsTimes.push_back(Interval(2,9));
	guestsTimes.push_back(Interval(10,11));
	guestsTimes.push_back(Interval(12,15));
	//
	PRINT_INT(getMaximumMumberOfGuests(guestsTimes));
}
//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	testCase0();
	//int result = getMaximumMumberOfGuests();
	//
	system("pause");
}

