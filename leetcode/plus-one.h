/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/plus-one/
	Date: 2/28/2017
*/

// Includes
#include "../common.h"

// Functions
vector<int> plusOne(vector<int>& digits) {
    size_t n = digits.size() ;
    char carry = (char)digits[n-1]>=9;
    digits[n-1] = (digits[n-1] + 1)%10;
    int tmp;
    for (int i = n-2; i >= 0; i--)
    {
      tmp = digits[i] + carry;
      carry = tmp / 10;
      digits[i] = tmp % 10;
    }
    if (carry)
      digits.insert(digits.begin(), 1);
    return digits;
}
    
// Test cases
void testCases()
{
	int a[] = { 9 };
	int a1[] = { 9, 9 };
	int a2[] = { 0 };
	int a3[] = { 1,8 };
	printVector(plusOne(TO_VECTOR(a)));
	printVector(plusOne(TO_VECTOR(a1)));
	printVector(plusOne(TO_VECTOR(a2)));
	printVector(plusOne(TO_VECTOR(a3)));
	cout << endl << "Done" << endl;
}
