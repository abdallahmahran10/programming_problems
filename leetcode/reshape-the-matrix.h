/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/reshape-the-matrix/submissions/1
	Date: 9/24/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int n= nums.size();
        int m = nums[0].size();
        if(r*c != n*m)
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int k=0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                res[k/c][k%c] = nums[i][j];
                ++k;
            }
        }
        return res;
    }
