// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

/////////////////////uva problems template /////////////////////
//12356 - Army Buddies
int uva12356()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Your code is here //////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}
///////////////////////
void Main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}

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


//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	printVector(testCase0()); 
	//printVector(testCase1()); 
	//printVector(testCase2()); 
	//printVector(testCase3()); 
	//printVector(testCase4()); 
	//printVector(testCase5()); 
	//printVector(testCase6()); 
	//printVector(testCase7()); 
	system("pause");
}
