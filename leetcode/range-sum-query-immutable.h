/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/range-sum-query-immutable/?tab=Description
	Date: 2/22/2017
*/

// Includes
#include "../common.h"

class NumArray {
private:
	vector<int> mNums;
	unordered_map<int, long long> cache;
public:
	NumArray(vector<int> nums) :mNums(nums) {
		if (mNums.empty())
			return;
		int n = mNums.size();
		cache[n - 1] = mNums[n - 1];
		for (int i = n-2; i >= 0; i--)
		{
			cache[i] = mNums[i] + cache[i + 1];
		}
	}

	int sumRange(int i, int j) {
		if (i == j && i<mNums.size())
			return mNums[i];
		if (i > j || i>=mNums.size() || j>=mNums.size())
			return 0;
		return  mNums[j] + cache[i] - cache[j];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj(nums);
 * int param_1 = obj.sumRange(i,j);
 */
