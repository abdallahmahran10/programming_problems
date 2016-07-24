// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

/////////////////////uva problems template /////////////////////
//12356 - Army Buddies
int uva12356()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Your code is here //////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}
/////////////////////////////// LEETCODE ////////////////////////////////
// Definitions
namespace a{
	class aa{};
};
class SubArray
{
public :
	vector<int> mSubArray;
	unsigned long long mTotal;
	bool flag;
 	SubArray()
	{
		mTotal = 0;
		flag = false;
	}
	void addElement(int elm)
	{
		mSubArray.push_back(elm);
		if(!flag)
		{
			if( mTotal + elm < 0 || mTotal + elm >= std::numeric_limits<unsigned long long>::max() )
			{
				mTotal = std::numeric_limits<unsigned long long>::max();
				flag = true;
			}
			else 
				mTotal += elm;
		}
	}
};

vector<int> maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<SubArray> subArrays;
	for(int i=0; i<A.size(); i++)
	{
		SubArray subArray;
		while (i<A.size()&& A[i]>=0 )
		{
			subArray.addElement(A[i]);
			i++;
		}
		if(subArray.mSubArray.size()>0)
			subArrays.push_back(subArray);
	}
	if(subArrays.size()<1)
		return vector<int>();
	int idx= 0;
	unsigned long long max= subArrays[0].mTotal;
	for(int i=1; i<subArrays.size(); i++)
	{
		if(max<subArrays[i].mTotal)
		{
			max = subArrays[i].mTotal;
			idx = i;
		} else if(max == subArrays[i].mTotal)
		{
			idx = subArrays[i].mSubArray.size() > subArrays[idx].mSubArray.size()? i : idx;
		//	if(subArrays[i].mSubArray.size() == subArrays[idx].mSubArray.size())
			//	idx = subArrays[i].mSubArray[0] < subArrays[idx].mSubArray[0]? i : idx;
		}
	}
	return subArrays[idx].mSubArray;
}

// Implmentation 
/*
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
*/
//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> A;
	//A : [ 336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421 ]
	//A : [ 1889947178, -709393584, 1918502651, 1474612399, 1264095060, -1843993368, 1984210012]
	A.push_back(1889947178);
	A.push_back(-709393584);
	A.push_back(1918502651);
	A.push_back(1474612399);
	A.push_back(1264095060);
	A.push_back(-1843993368);
	A.push_back(1984210012);
	vector<int> sol = maxset(A);
	printVector(sol);
	system("pause");
}
//  map<int, int> intervals_;
// set<int> nums_;
