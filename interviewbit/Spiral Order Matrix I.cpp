// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros


// Spiral Order Matrix I
// https://www.interviewbit.com/problems/spiral-order-matrix-i/

enum DIRECTION {RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3} ;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	if(A.size()<1)
		return result;
	int m = A.size();
	int n = A[0].size();
	int L = 0, R= n-1, T = 0, B = m-1;
	int dir = 0;

	while(T<=B && L <= R)
	{
		switch (dir)
		{
			case RIGHT: 
				FOR(i,L,R+1){
					result.push_back(A[T][i]);
				}
				T++;
				break;
			case DOWN:  
				FOR(i,T,B+1){
					result.push_back(A[i][R]);
				}
				R--;
				break;
			case LEFT: 
				FOR_R(i,R,L){
					result.push_back(A[B][i]);
				}
				B--; 
				break;
			case UP:  
				FOR_R(i,B,T){
					result.push_back(A[i][L]);
				}
				L++;
				break;
			default:
				break;
		}
		dir = (dir +1)%4;
	}
	return result;
}


vector<int > testCase0()
{
	int a[] = {1, 2, 3};
	int b[] = {4, 5, 6};
	int c[] = {7, 8, 9};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
	vector<int> B(b, b + sizeof b / sizeof b[0]);
	vector<int> C(c, c + sizeof c / sizeof c[0]);
    //
	vector<vector<int>> matrix;
	matrix.push_back(A);
	matrix.push_back(B);
	matrix.push_back(C);
    return spiralOrder(matrix);
}