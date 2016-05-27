// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using namespace std;

void printVector (const vector<int>& v){
  cout<<"[";
  for (int i=0; i<v.size();i++){
    cout << v[i] << ",";
  }
  cout<<"]"<<endl;
}



vector<int>& getSubVector(vector<int>& vec, int start, int end)
{
	//printVector(vec);
	//cout<< "s:"<<start<<" e:"<<end<<endl; 
	if(end<=start)
		return *new vector<int> ;
	vector<int>::const_iterator first = vec.begin() + start;
	vector<int>::const_iterator last = vec.begin() + end;
	vector<int>  *newVec=new vector<int> (first, last);
	//printVector(*newVec);
	return *newVec;
}
// TODO: reference additional headers your program requires here

