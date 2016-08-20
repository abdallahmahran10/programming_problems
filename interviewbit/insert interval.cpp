// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<Interval> result;
	bool inserted = false;
	for(vector<Interval>::const_iterator iter = intervals.begin(); iter != intervals.end(); iter++)
	{
		if(iter->end < newInterval.start)
		{
			result.push_back(*iter);
			continue;
		}
		// 
		if( iter->start > newInterval.end) 
		{
			if(!inserted)
			{
				result.push_back(newInterval);
				inserted = true;
			}
			result.push_back(*iter);
			continue;
		}
		//
		while(iter!= intervals.end() && isOverlapped(*iter, newInterval))
		{
			newInterval.start = min(iter->start, newInterval.start);
			newInterval.end = max(iter->end, newInterval.end);		 
			iter++;
		}
		//
		result.push_back(newInterval);
		inserted = true;
		//
		iter--;
	}
	if(!inserted)
		result.push_back(newInterval);
		
	return result;
}



// Implmentation 

vector<Interval> testCase0()
{
    /*
     * [[1,2],[3,5],[6,7],[8,10],[12,16]]
     * [4,9]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));
    //
    Interval newInterval(4,9);
    //
    return insert(intervals, newInterval);
}
vector<Interval> testCase1()
{
    /*
     * [[1,5]]
     * [0,3]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    //
    Interval newInterval(0,3);
    //
    return insert(intervals, newInterval);
}
vector<Interval> testCase2()
{
    /*
     *[[1,5]]
     *[0,0]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    //
    Interval newInterval(0,0);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase3()
{
    /*
     *[[0,0],[1,4],[6,8],[9,11]]
     *[0,9]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(0,0));
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(6,8));
    intervals.push_back(Interval(9,11));
    //
    Interval newInterval(0, 9);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase4()
{
    /*
     *[[1,5]]
     *[2,3]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    //
    Interval newInterval(2, 3);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase5()
{
    /*
     *[[1,5]]
     *[5,7]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    //
    Interval newInterval(5, 7);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase6()
{
    /*
     *[[1,5]]
     *[6,8]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    //
    Interval newInterval(6, 8);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase7()
{
    /*
     *[[1,5]]
     * [2,7]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    //
    Interval newInterval(2, 7);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase8()
{
    /*
     *[]
     *[5,7]
    */
    vector<Interval> intervals;
    //
    Interval newInterval(5, 7);
    //
    return insert(intervals, newInterval);
}
//
vector<Interval> testCase9()
{
    /*
     *[[1,5],[6,8]]
     *[5,6]
    */
    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    intervals.push_back(Interval(6,8));
    //
    Interval newInterval(5, 6);
    //
    return insert(intervals, newInterval);
}