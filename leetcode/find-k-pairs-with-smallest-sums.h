/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
	Date: 9/18/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
// # Solution using priority queue (better time complixity)
class ComparePairsBySum
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
		return n1.first + n1.second > n2.first + n2.second;
    }
};
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,ComparePairsBySum> pq;

	int stored=0;
	for(int i=0; i< nums1.size(); i++)
		for(int j=0; j< nums2.size(); j++)
        {
			pq.push(make_pair(nums1[i], nums2[j]));			
            if(pq.size() > k)
                pq.
        }
	vector<pair<int, int>> res;
	while (k-- > 0 && !pq.empty()) 
	{
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}
// # Solution using multimap (better space complixity) 
vector<pair<int, int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
	multimap<int, pair<int, int>> om;
	int stored=0;
	for(int i=0; i< nums1.size(); i++)
	{
		for(int j=0; j< nums2.size(); j++)
		{
			om.emplace(nums1[i] + nums2[j], make_pair(nums1[i], nums2[j]));
			if(om.size() > k)
				om.erase(prev(om.end()));
		}
	}
	vector<pair<int, int>> res;
	for(map<int, pair<int, int>>::iterator it = om.begin(); it!=om.end(); it++)
		res.push_back(it->second);
	return res;
}
