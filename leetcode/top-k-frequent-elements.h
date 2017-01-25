/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/top-k-frequent-elements/
	Date: 1/24/2017
*/
// Includes
#include "../common.h"
// Types
// Functions
vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> res;
	if (nums.empty())
		return res;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
		m[nums[i]]++;

	while (k--)
	{
		int key, max=0;
		for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
		{
			if (it->second > max)
			{
				max = it->second;
				key = it->first;
			}
		}
		res.push_back(key);
		m.erase(key);
	}
	return res;
}
// Test cases
