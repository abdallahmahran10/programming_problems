// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

void testCase0()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	int A, B,C,D;
	int squares =0, rectangles=0, others=0;
	while(SCAN_INT(A) != EOF){
		SCAN_INT(B);
		SCAN_INT(C);
		SCAN_INT(D);
		if(A == B && A== C && A == D )
			squares++;
		else if(A == C && B ==D && A>0 && B>0)
				rectangles++;
		else	
			others++;
	}
	printf("%d %d %d", squares, rectangles, others);
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}


class Hotel
{
private:
	int mReviewsCount;
public:
	int mId;
	Hotel(int id):mId(id)
	{
		mReviewsCount =0;
	}

	void incerHotelReviews()
	{
		mReviewsCount++;
	}
	
	void handleReview(string review, vector<string> &words)
	{
		istringstream ss(review);
		while (ss)
		{
			string s;
			if (!getline( ss, s, ' ' )) break;
			
			if (std::find(words.begin(), words.end(), s) != words.end())
			{
				mReviewsCount++;
			}
		}
	}

	bool operator<(const Hotel &rhs) const { 
		if(mReviewsCount  == rhs.mReviewsCount)
			return mId < rhs.mId;
		else
			return mReviewsCount < rhs.mReviewsCount; 
	}
	
	bool operator==(const Hotel &rhs) const { 
		return mId < rhs.mId; 
	}
};

void testCase1()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	//map<int , int> hotelIdsReviewsMap;
	vector<Hotel> hotels;
	vector<string> words;
	string wordsLine;
	if(!getline(cin, wordsLine) || wordsLine.length()<0) return;

	istringstream ss(wordsLine);
	while (ss)
	{
		string s;
		if (!getline( ss, s, ' ' )) break;
		words.push_back( s );
	}
	IN(tc);
	while(tc--)
	{
		IN(id);
		string dump;
		getline(cin, dump);
		string review;
		getline(cin, review);
		bool handled = false;
		for(vector<Hotel>::iterator iter = hotels.begin(); iter != hotels.end();iter++)
		{
			if(iter->mId == id)
			{
				iter->handleReview(review, words);
				handled = true;
				break;
			}
		}
		if(!handled)
		{
			Hotel hotel(id);
			hotel.handleReview(review, words);
			hotels.push_back(hotel);
		}
	}
	std::sort(hotels.rbegin(), hotels.rend());
	
    for (std::vector<Hotel>::const_iterator iter = hotels.begin(); iter != hotels.end(); iter++)
	{
		cout << iter->mId<< " ";
	}
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}

void testCase2()
{
	
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	const int ESCAPE_TOKEN =-128;
	IN(prevElement);
	PRINT_INT(prevElement);
	int n;
	while(SCAN_INT(n) != EOF)
	{
		int diff = n-prevElement;
		if(diff > 127 || diff < -127)
			PRINT_INT(ESCAPE_TOKEN);
		PRINT_INT(diff);
		prevElement = n;
	}
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}

bool checkPairs(vector<int> &A, int sum)
{
	int l, r;
    l = 0;
	r = A.size()-1; 
    while (l < r)
    {
		int tmp = A[l] + A[r];
         if(tmp  == sum)
              return 1; 
         else if(tmp < sum)
              l++;
         else 
              r--;
    }    
    return 0;
}

void testCase3()
{
	
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Your code is here //////////////////////////
	IN(sum);
	IN(N);
	int *A= new int[N];
	for(int i=0; i<N; i++)
	{
		SCAN_INT(A[i]);
	}
	std::sort(std::begin(A), std::end(A));
	//std::sort(A.begin(), A.end());
	printf("%d", checkPairs(A, sum));
		
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}