#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm> // sort
#include <stdio.h>
#include <cstring> // memset
#include<stack>
#include <map> // map
#include <set> 
#include <assert.h>     /* assert */
#include <stdio.h>

using namespace std;
///////////////////////////////////////////////////////////////////
#define PB push_back
#define ZERO (1e-10)
#define INF (1<<29)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define FOR_R(i, m, n) for (int i(m); i >= n; i--)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define F2(n) REP(j, n)
#define FT(m, n) FOR(k, m, n)
#define SCAN_INT(n) scanf("%d",&(n))
#define IN(n) int (n);scanf("%d",&(n))
#define PRINT_INT(n) printf("%d ", (n))
#define PRINT_STR(str) printf("%s\n", ((string)(str)).c_str())
#define PRINT_LINE_SEPARATOR(ch) for(int sepCount = 15; sepCount>0; sepCount--) putchar(ch); printf("\n") 
#define PRINT_LINE_SEPARATORS(ch,n) for(int sepCount = n; sepCount>0; sepCount--) putchar(ch) 
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) (sizeof (a)/ sizeof (a)[0])
#define ARRAY_END(a) ((a) + ARRAY_SIZE(a))
#define TO_VECTOR(a) vector<int>((a), ARRAY_END((a)))

#define SORT(V) sort(V.begin(), V.end())
#define R_SORT(V) sort(V.rbegin(), V.rend())
//////////////////////macros for local usage only///////////////////
#define LOCAL 
////////////////////////////////////////////////////////////////////
// some difintions
//
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
///
static bool isIntervalsOverlapped(int x1, int x2, int y1, int y2)
{
    return (x1 >= y1 && x1 <= y2) ||
            (x2 >= y1 && x2 <= y2) ||
            (y1 >= x1 && y1 <= x2) ||
            (y2 >= x1 && y2 <= x2);
}


static void printStringVector(const vector<string>& text){
	int iter;
	cout<<"Vector count = "<<text.size()<<endl;
	cout<<"content = [";
    for (std::vector<string>::const_iterator iter = text.begin(); iter != text.end(); )
	{
		cout << *iter  ;
		if(++iter != text.end())
			cout << ", ";
	}
	cout<<"]"<<endl;
}


static void printVector (const vector<int>& v){
	cout<<"[";
	if(v.empty())
	{
		cout<<"]"<<endl;
		return;
	}
	
	int i=0;
	for (; i<v.size()-1;i++){
		cout << v[i] << ",";
	}
	cout<<v[i]<<"]"<<endl;
}


static void printArray(int *a, int len)
{
	cout<<"[";
	int i=0;
	for(; i<len-1; i++)
	{
		cout << a[i] << ",";
	}
	cout<<a[i]<<"]"<<endl;
}

static void swap(int *a, int l, int r)
{
	int tmp =a[l];
	a[l]= a[r];
	a[r] = tmp;
}

static void swap(int *a1, int *a2)
{
	int tmp =*a1;
	*a1 = *a2;
	*a2 = tmp;
}

static vector<int>& getSubVector(vector<int>& vec, int start, int end)
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
//
static bool isOverlapped(int x1, int x2, int y1, int y2)
{
    return (x1 >= y1 && x1 <= y2) ||
            (x2 >= y1 && x2 <= y2) ||
            (y1 >= x1 && y1 <= x2) ||
            (y2 >= x1 && y2 <= x2);
}
//
static bool isOverlapped(Interval interval1, Interval interval2)
{
    return isOverlapped(interval1.start,interval1.end,interval2.start,interval2.end);
}

template<typename T> 
static void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

template<typename T> 
static vector<T> arrayToVector(T a[])
{
	return vector<T>(a, a + sizeof a / sizeof a[0]);
}

void printLL(ListNode *p)
{
	while(p)
	{
		cout<< p->val << " ";
		p = p->next;
	}
	cout<<endl;
}

void printLLReversed(ListNode *p)
{
	if(p == NULL)
	{
		cout<<endl;
		return;
	}
	printLLReversed(p->next);
	cout<< p->val << " ";
}
//
ListNode *toLL(int *a, int n)
{
	if(n<1)
		return NULL;
	ListNode *head = new ListNode(a[0]);
	ListNode *slider = head;
	for(int i=1; i<n; i++)
	{
		slider->next = new ListNode(a[i]);
		slider = slider->next;
	}
	return head;
}
//
void reverseLL(ListNode *p, ListNode **head)
{
	if(p->next == NULL)
	{
		*head = p;
		return;
	}
	printLLReversed(p->next);
	ListNode *tmp = p->next;
	tmp->next = p;
	p->next = NULL;
}
//
ListNode* reverseLL(ListNode *head)
{
	reverseLL(head, &head);
	return head;
}
#endif // COMMON_H