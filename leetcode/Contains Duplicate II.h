
#include "common.h"
/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

// Definition for undirected graph.
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if (nums.size()<2)
		return false;
	multimap<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		m.emplace(nums[i], i);
	}
	multimap<int, int>::iterator prev, it;
	for (prev = m.begin(), it = next(m.begin()); it != m.end(); ++it, ++prev)
		if (prev->first == it->first &&
			abs(prev->second - it->second) <= k)
			return true;
	return false;
}

////////////////////// TEST CASES ///////////////////////////////////

void testCase0()
{
	int a[] = { 99, 12, 23, 99, 45, 12, 23, 1 };
	cout << containsNearbyDuplicate(vector<int>(a, a + sizeof a / sizeof a[0]), 1)<<endl;
}
