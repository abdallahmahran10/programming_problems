
/*
  Author: Abdallah Mahran
  Ref: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/


#include "common.h"

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> ret;
	//
	int l1 = nums1.size(), l2 = nums2.size();
	for (int i = 0, j=0; i < l1 && j < l2; )
	{
		if (nums1[i] == nums2[j])
		{
			ret.push_back(nums1[i++]);
			j++;
		}
		else if (nums1[i] < nums2[j])
			i++;
		else
			j++;
	}
	return ret;
}

void testCase0()
{
	int x[] = { 1, 2, 2, 1 };
	vector<int> v1(x, x + sizeof x / sizeof x[0]);
	int y[] = { 2, 2 };
	vector<int> v2(y, y + sizeof x / sizeof x[0]);
	printVector(intersect(v1, v2));
}

void testCase1()
{
	int x[] = { 1, 2, 2, 1,3,3 };
	vector<int> v1(x, x + sizeof x / sizeof x[0]);
	int y[] = { 2, 1,2, 1 };
	vector<int> v2(y, y + sizeof x / sizeof y[0]);
	printVector(intersect(v1, v2));
}
