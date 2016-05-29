#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <stdio.h>
#include <cstring> // memset
#include <map> // map
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
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define F2(n) REP(j, n)
#define FT(m, n) FOR(k, m, n)
#define SCAN_INT(n) scanf("%d",&(n))
#define IN(n) int (n);scanf("%d",&(n))
#define PRINT_INT(n) printf("%d\n", (n))
#define PRINT_STR(str) printf("%s\n", ((string)(str)).c_str())
//////////////////////macros for local usage only///////////////////
#define LOCAL 
////////////////////////////////////////////////////////////////////
bool isIntervalsOverlapped(int x1, int x2, int y1, int y2)
{
    return (x1 >= y1 && x1 <= y2) ||
            (x2 >= y1 && x2 <= y2) ||
            (y1 >= x1 && y1 <= x2) ||
            (y2 >= x1 && y2 <= x2);
}


void printStringVector(const vector<string>& text){
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