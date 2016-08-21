// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
/*
Source: Interviewbit
Category: Programming/Arrays/Min Steps In Infinite Grid
https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
*/

class point
{
public:
	int x,y;
	point(int X, int Y):x(X),y(Y)
	{}
	
	void advance(int direction)
	{
		switch (direction)
		{
			case 0:
				x++;
				break;
			case 1:
				x--;
				break;
			case 2:
				y++;
				break;
			case 3:
				y--;
				break;
			case 4:
				x--;
				y--;
				break;
			case 5:
				x++;
				y++;
				break;
			case 6:
				x--;
				y++;
				break;
			case 7:
				x++;
				y--;
				break;
			default:
				break;
		}
	}
	//
	int findDirectionToPoint(point p2)
	{
		if(x == p2.x)
		{
			if(y == p2.y)
				return -1;
			else if(y<p2.y)
				return 2;
			else
				return 3;
		} 
		//
		if(y == p2.y)
		{
			if(x<p2.x)
				return 0;
			else
				return 1;
		}
		//
		if(x > p2.x)
		{
			if(y>p2.y)
				return 4; 
			else
				return 6; 
		}
		else
		{
			if(y<p2.y)
				return 5;
			else
				return 7;
		}
	}
};


// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int coverPoints(vector<int> &X, vector<int> &Y) {
	int steps=0;
	for(int i=0; i<X.size()-1; i++)
	{
		steps += max(abs(X[i] - X[i+1]), abs(Y[i] - Y[i+1]));
		/*
		point p1(X[i], Y[i]), p2(X[i+1], Y[i+1]);
		int dir =-1;
		while (true)
		{
			dir = p1.findDirectionToPoint(p2);
			if(dir ==-1)
				break;
			else
			{
				p1.advance(dir);
				steps++;
			}
		}
		*/
	}
	return steps;
}

//
int testCase0()
{
	// 3 0 1 1
	// 3 0 1 2
	int x[] = {0,1,1};
	int y[] = {0,1,2};
	vector<int> X(x, x + sizeof x / sizeof x[0]);
	vector<int> Y(y, y + sizeof y / sizeof y[0]);
	return coverPoints(X, Y);
}

int testCase1()
{
	// 3 0 1 5
	// 3 1 3 2
	int x[] = {0,1,5};
	int y[] = {1,3,2};
	vector<int> X(x, x + sizeof x / sizeof x[0]);
	vector<int> Y(y, y + sizeof y / sizeof y[0]);
	return coverPoints(X, Y);
}

int testCase2()
{
	// 2 -7 -13
	// 2  1 -5
	int x[] = {-7,-13};
	int y[] = {1,-5};
	vector<int> X(x, x + sizeof x / sizeof x[0]);
	vector<int> Y(y, y + sizeof y / sizeof y[0]);
	return coverPoints(X, Y);
}