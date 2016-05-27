#ifndef INSERT_INTERVAL
#define INSERT_INTERVAL

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> retVal;
    if(intervals.size() == 0){
        retVal.push_back(newInterval);
        return retVal;
    }
    //
    bool inserted =false;
    for(int i=0; i<intervals.size();  i++)
    {
        if(inserted)
        {
            retVal.push_back(intervals[i]);
            continue;
        }
        //
        if(intervals[i].end < newInterval.start)
        {
            retVal.push_back(intervals[i]);
            continue;
        }

        if(newInterval.end < intervals[i].start)
        {
            retVal.push_back(newInterval);
            retVal.push_back(intervals[i]);
            inserted = true;
            continue;
        }
        //
        if(intervals[i].end >= newInterval.end || newInterval.start >= intervals[i].start )
        {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            continue;
        }
        //
    }
    if(!inserted)
        retVal.push_back(newInterval);

    return  retVal;
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
//
#endif // INSERT_INTERVAL

