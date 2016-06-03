#include "common.h" // my defined macros


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
class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {		
        map<int, int>::iterator it = _intervals.upper_bound(val);
        int start = val, end = val;
        if (it != _intervals.begin() && prev(it)->second + 1 >= val) {
            --it;
        }
        while (it != _intervals.end() && end + 1 >= it->first) {
            start = min(start, it->first);
            end = max(end, it->second);
            it = _intervals.erase(it);
        }
        _intervals[start] = end;
    }
    vector<Interval> getIntervals() {
		vector<Interval> ret;
		map<int, int>::iterator it = _intervals.begin();
        while (it != _intervals.end() ) 
		{
			ret.push_back(Interval(it->first, it->second));
			it ++;
		}
        return ret;
    }
	
private:
    /** Initialize your data structure here. */
	map<int, int> _intervals;
};

/////////////////////// TEST CASES ///////////////////////////////////


vector<Interval> testCase0() {
	SummaryRanges obj;
	obj.addNum(1);
	obj.addNum(3);
	obj.addNum(7);
	obj.addNum(2);
	obj.addNum(6);
	return obj.getIntervals();
}
vector<Interval> testCase1() {
	SummaryRanges obj;
	obj.addNum(1);
	obj.addNum(4);
	obj.addNum(6);
	obj.addNum(3);
	obj.addNum(2);
	return obj.getIntervals();
}
vector<Interval> testCase2() {
	SummaryRanges obj;
	obj.addNum(1);
	obj.addNum(2);
	obj.addNum(3);
	obj.addNum(4);
	obj.addNum(5);
	obj.addNum(6);
	obj.addNum(7);
	return obj.getIntervals();
}
vector<Interval> testCase3() {
	SummaryRanges obj;
	obj.addNum(1);
	obj.addNum(4);
	obj.addNum(3);
	return obj.getIntervals();
}
vector<Interval> testCase4() {
	SummaryRanges obj;
	obj.addNum(1);
	obj.addNum(0);
	obj.addNum(0);
	return obj.getIntervals();
}
vector<Interval> testCase5() {
	SummaryRanges obj;
	obj.addNum(0);
	obj.addNum(0);
	obj.addNum(0);
	obj.addNum(0);
	obj.addNum(1);
	obj.addNum(9);
	return obj.getIntervals();
}
vector<Interval> testCase6() {
	SummaryRanges obj;
	obj.addNum(6);
	obj.addNum(1);
	obj.addNum(3);
	obj.addNum(0);
	obj.addNum(2);
	obj.addNum(5);
	obj.addNum(4);
	return obj.getIntervals();
}

