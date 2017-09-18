/*
   Author: Abdallah Mahran
   Ref: https://leetcode.com/problems/two-sum/
*/

#include "../common.h"

// generic solution 
vector<pair<int, int>> findPairs(vector<int> v, int s)
{
	vector<pair<int, int>> pairs;
	unordered_map<int, int> hm;
	for(int i=0; i < v.size(); i++)
		hm[v[i]] = i;
	for(int i=0; i < v.size(); i++)
	{
		unordered_map<int, int>::iterator it = hm.find(s-v[i]);
		if(it != hm.end() && it->second != i)
			pairs.push_back(make_pair(i, it->second));
	}
	return pairs;
}
vector<int> twoSum(vector<int>& nums, int target) {
	vector<pair<int, int>> pairs = findPairs(nums, target);
	vector<int> res;
	if(!pairs.empty())
	{
		res.push_back(pairs[0].first);
		res.push_back(pairs[0].second);
	}
	return res;
}
// basic solution
typedef unordered_map<int, int>::const_iterator cit;
vector<int> twoSum1(vector<int>& nums, int target) {
	vector<int> result; 
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); i++)
	{
		cit it = hash.find(target - nums[i]);
		if (it != hash.end())
		{
			result.push_back(it->second);
			result.push_back(i);
			break;
		}
		hash[nums[i]] = i;
	}
	return result;
}
void testCase0()
{
	int tmp[] = { 3, 4, 1, 4, 1 };
	std::vector<int> A(tmp, tmp + (sizeof(tmp) / sizeof(*tmp)));
	int target = 9;
	printVector(twoSum(A, target));
}

void testCase1()
{
	int tmp[] = { 2, 7, 11, 15 };
	std::vector<int> A(tmp, tmp + (sizeof(tmp) / sizeof(*tmp)));
	int target = 9;
	printVector(twoSum(A, target));
}

void testCase2()
{
	int tmp[] = { 3, 2, 4 };
	std::vector<int> A(tmp, tmp + 3);
	int target = 6;
	printVector(twoSum(A, target));
}
