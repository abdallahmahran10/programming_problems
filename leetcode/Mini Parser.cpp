
// https://leetcode.com/problems/mini-parser/

class NestedInteger {
public:
  // Constructor initializes an empty nested list.
  NestedInteger(){}

  // Constructor initializes a single integer.
  NestedInteger(int value){}

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const
  {return false;}

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const
  {return 0;}

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value)
  {}
  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni)
  {}
  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const
  {
      return vector<NestedInteger>();
  }
};

NestedInteger getFirstList(string s, int &idx)
{
    NestedInteger nestedInteger;
    stack<char> st;
    stack<int> integer;
    for(; idx<s.length(); idx++)
    {
        if(s[idx] == '[')
        {
            nestedInteger.add(getFirstList(s, idx));
            continue;
        }

        if(s[idx] == ',')
        {
            if(!integer.empty())
            {
                int x=0;
                int tens = pow(10, integer.size());
                while(!integer.empty())
                    x+=integer.top() * tens--;

                nestedInteger.add(NestedInteger(x));
            }
            continue;
        }

        if(s[idx] == ']')
            break;

        integer.push(s[idx]- '0');
    }
    return nestedInteger;
}

NestedInteger deserialize(string s) {

    NestedInteger nestedInteger;
    int listIdx=-1;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '[')
        {
            nestedInteger.add(getFirstList(s, idx));
            continue;
        }

        if(s[i] == ',')
            continue;
    }
    return nestedInteger;
}
