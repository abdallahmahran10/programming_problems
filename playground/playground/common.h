#include <vector>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define LOOP(i, initial, end) for (int (i) = int(initial); (i) <int(end); (i)++)

#define SCAN_INT(n) scanf("%d", &(n))
#define PRINT_INT(n) printf("%d\n", (n))
//
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
