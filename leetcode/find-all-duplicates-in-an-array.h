/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/find-all-duplicates-in-an-array/
	Date: 1/23/2017
*/

// Functions
vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	if (nums.empty())
		return res;
	for (int i = 0; i < nums.size(); i++)	
		nums[abs(nums[i]) - 1] *= -1;
	//
	for (int i = 0; i < nums.size(); i++)
		if (nums[abs(nums[i]) - 1]>0)
		{
			res.push_back(abs(nums[i]));
			nums[abs(nums[i]) - 1] *= -1;
		}
	return res;
}
