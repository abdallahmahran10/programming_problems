#include <stdio.h>
#include "../common.h"
#include <numeric>

/***********************************************************************\ 
	Author: Abdallah Mahran
    Desc: Problem 3 - Yandex application
	Date: 12/04/2016
	Ref: https://yandex.com/jobs/vacancies/global/devmaps_cpp
***********************************************************************/


/* 
	Function: sum4	
		genric sum method using accumlate	
*/
template<typename T> T sum(std::vector<T>& v)
{    
    return std::accumulate(v.begin(), v.end(), 0);
}

/* 
	Function: sum4	
		Sum all double values in vector using accumlate	
*/
double sum4(std::vector<double>& v)
{    
    return sum<double>(v);
}
 