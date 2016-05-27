#include <iostream>
//#include "merge_two_sorted_arrays.h"
#include <vector>
using namespace std;


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

vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.size() < 2)
        return intervals;

	for(vector<Interval>::iterator iter = intervals.begin() ; iter != intervals.end(); ++iter)
	{
		for(vector<Interval>::iterator iter2 = intervals.begin() ; iter2 != intervals.end(); ++iter2)
		{
			if(iter == iter2)
				continue;
			if(isOverlapped(*iter, *iter2)) 
			{
				// merge and start over
				iter->start = min(iter->start , iter2->start);
				iter->end = max(iter->end, iter2->end);		
				intervals.erase(iter2);
				iter = intervals.begin();
				break;
			}
		}
	}
    return intervals;
}
/////////////////////// TEST CASES ///////////////////////////////////
void testOverlappingFunction()
{

    cout << isOverlapped(Interval(2,5),Interval(3,6))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(1,4))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(3,4))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(2,5))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(1,2))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(0,5))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(0,10))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(2,4))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(4,5))<<endl;
    cout << isOverlapped(Interval(2,5),Interval(0,0))<<endl;
}
vector<Interval> testCase0()
{
   // Given [1,3],[2,6],[8,10],[15,18],
    //return [1,6],[8,10],[15,18].
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));
    //
    return merge(intervals);
}
vector<Interval> testCase1()
{
    /*
     * I: [[2,3],[4,5],[6,7],[8,9],[1,10]]
     * O: [[1,10]]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(4,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,9));
    intervals.push_back(Interval(1,10));
    //
    return merge(intervals);
}
vector<Interval> testCase2()
{
    /*
     *[[2,3],[3,4],[5,5],[4,5],[5,6],[2,3],[4,6],[0,0]]
     *
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(3,4));
    intervals.push_back(Interval(5,5));
    intervals.push_back(Interval(4,5));
    intervals.push_back(Interval(5,6));
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(4,6));
    intervals.push_back(Interval(0,0));
    //
    return merge(intervals);
}
vector<Interval> testCase3()
{
    /*
     * Input: [[2,3],[2,2],[3,3],[1,3],[5,7],[2,2],[4,6]]
     * Output: [[1,3],[4,7]]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(2,2));
    intervals.push_back(Interval(3,3));
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(5,7));
    intervals.push_back(Interval(2,2));
    intervals.push_back(Interval(4,6));
    //
    Interval newInterval(0,0);
    //
    return merge(intervals);
}

