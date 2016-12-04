#include <stdio.h>

/***********************************************************************\ 
	Author: Abdallah Mahran
    Desc: Problem 2 - Yandex application
	Date: 12/04/2016
	Ref: https://yandex.com/jobs/vacancies/global/devmaps_cpp
***********************************************************************/

/* 
	Function: sum1
	Complexity: N * N*log2(N)
	N: is the size of the vector
	Explanation: The sort function complexity is N*log2(N) and the loop complexity is N
*/
double sum1(std::vector<double>& v)
{    
    if (v.empty()) {
        return 0.0;
    }
    for(size_t i = 0; i < v.size() - 1; ++i) { // N
        std::sort(v.begin()+i, v.end()); //  N*log2(N)
        v[i+1] += v[i];
    }
    return v.back();
}
 
/* 
	Function: sum2
	Complexity: N * N*log2(M)
	N: is the size of the vector
	M: is the distance between the first element and the middle element in the vector
	Explanation: The partial sort function complexity is N*log(M) and it will be repeated N times (for loop)
*/
double sum2(std::vector<double>& v)
{    
    if (v.empty()) {
        return 0.0;
    }
    for(size_t i = 0; i < v.size() - 1; ++i) {
        std::partial_sort(v.begin() + i, v.begin() + i + 2, v.end());
        v[i+1] += v[i];
    }
    return v.back();
}
 
/* 
	Function: sum3
	Complexity: N*log(N)
	N: is the size of the vector
	Explanation: The multiset constructor complexity is N*log(N) for unsorted sequences,
				The loop complexity will be N, the erease function is a constant complexity 
				and the insert function is complexity will be LogN which lead to 2 * N * LogN
				we can ignore the 2	multiplication at very large input size.
	Note: argument list for class template multiset was missing
*/
double sum3(std::vector<double>& v)
{    
    std::multiset<double> set(v.begin(), v.end()); //  For unsorted sequences, linearithmic (N*logN)
    while (set.size() > 1) { // N
        std::multiset<double>::const_iterator itA = set.begin();
        std::multiset<double>::const_iterator itB = ++set.begin();
        double c = *itA + *itB;
        set.erase(itA, itB);  // amortized constant     
        set.insert(c); // Log(N)
    }
    return !set.empty() ? *set.begin() : 0.0;
}