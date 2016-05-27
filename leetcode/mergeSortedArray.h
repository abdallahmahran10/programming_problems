#include "stdafx.h"
//using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int nums1Size = m+n;
    int k;
    for(int i=0; i<n && m<nums1Size; i++)
    {
        int j =0;
        while(j < m && nums1[j] < nums2[i]) j++;
        for(k= nums1Size-1; k>j; k--)
        {
            nums1[k]=nums1[k-1];
        }
        nums1[j] = nums2[i];
        m++;
    }
}

void mergeSortedArray()
{
	int ints1[] = {0};
	int ints2[] = {1};
	vector<int>nums1 (ints1, ints1 + sizeof(ints1) / sizeof(int) );	
	vector<int>nums2 (ints2, ints2 + sizeof(ints2) / sizeof(int) );
	merge(nums1, 0, nums2, 1);
	for (std::vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
    std::cout << ' ' << *it;
	int a;
	cin >>a;
}