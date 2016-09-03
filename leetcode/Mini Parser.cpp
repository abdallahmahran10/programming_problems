
// https://leetcode.com/problems/mini-parser/

int getInt(const string &s, int idxStart, int idxEnd)
{
	
	string strInt = s.substr(idxStart,  idxEnd) ;
	return std::stoi(strInt );
}

int getFirstNumber(const string &s, int &idx)
{
	int digits=0;
	while(s[idx]!= ']' && s[idx]!= ',' && s[idx]!= '[' && idx<s.size())
	{
		digits++;
		idx++;
	}
	int x = getInt(s, idx - digits, idx);
	idx--;
	return x;
}

NestedInteger getFirstList(const string &s, int &idx)
{
    NestedInteger nestedInteger;
    stack<char> st;
    int digits = 0;
    for(; idx<s.length(); idx++)
    {
        if(s[idx] == '[')
        {
            nestedInteger.add(getFirstList(s, ++idx));
            continue;
        }
		//
        if(s[idx] == ',')        
            continue;        
		//
        if(s[idx] == ']')		
            break;		
		//
		nestedInteger.add(NestedInteger( getFirstNumber(s, idx)));
    }

    return nestedInteger;
}

NestedInteger deserialize(string s) {

    NestedInteger nestedInteger;
    int listIdx=-1;
    int digits = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '[')
        {
            nestedInteger.add(getFirstList(s, ++i));
            continue;
        }

        if(s[i] == ',')
            continue;

		nestedInteger.add(getFirstNumber(s, i));

    }
	return nestedInteger.getList().size()==1?nestedInteger.getList()[0]:nestedInteger;
}

int testCase0()
{
	 NestedInteger nestedInteger = deserialize("[123,[456,[789]]]"); 
	return 0;
}

int testCase1()
{
	NestedInteger nestedInteger = deserialize("324"); 
	return 0;
}
int testCase2()
{
	NestedInteger nestedInteger = deserialize("[324,45,13,31,4]"); 
	return 0;
}

int testCase3()
{
	NestedInteger nestedInteger = deserialize("[324,[5],1,[31],[4]]"); 
	return 0;
}
int testCase4()
{
	NestedInteger nestedInteger = deserialize("[[[324],[45],[13],[31],[4]],1]"); 
	return 0;
}