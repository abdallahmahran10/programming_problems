class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {		
		_nums.emplace(val);
    }

    vector<Interval> getIntervals() {
		vector<Interval> ret;	
		int k=0;
		set<int>::iterator it = _nums.begin();
		ret.push_back(Interval(*it, *it));
		//
		for(++it; it != _nums.end(); it++)
		{
			if(*prev(it) +1 == *it)
			{
				ret[k].end = *it;
				continue;
			}
			ret.push_back(Interval(*it, *it));
			k++;
		}
        return ret;
    }
	
private:
    set<int> _nums;
};


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