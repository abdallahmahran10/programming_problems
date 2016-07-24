// https://www.interviewbit.com/problems/max-non-negative-subarray/
class SubArray
{
public :
	vector<int> mSubArray;
	unsigned long long  mTotal;
	bool flag;
	SubArray()
	{
		mTotal = 0;
		flag = false;
	}
	void addElement(int elm)
	{
		mSubArray.push_back(elm);
		if(!flag)
		{
			if( mTotal + elm < 0 || mTotal + elm >= std::numeric_limits<unsigned long long>::max() )
			{
				mTotal = std::numeric_limits<unsigned long long>::max();
				flag = true;
			}
			else 
				mTotal += elm;
		}
	}
		
};


vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<SubArray> subArrays;
	for(int i=0; i<A.size(); i++)
	{
		SubArray subArray;
		while (i<A.size()&& A[i]>=0 )
		{
			subArray.addElement(A[i]);
			i++;
		}
		if(subArray.mSubArray.size()>0)
			subArrays.push_back(subArray);
	}
	if(subArrays.size()<1)
		return vector<int>();
	int idx= 0;
	unsigned long long max= subArrays[0].mTotal;
	for(int i=1; i<subArrays.size(); i++)
	{
		if(max<subArrays[i].mTotal)
		{
			max = subArrays[i].mTotal;
			idx = i;
		} else if(max == subArrays[i].mTotal)
		{
			idx = subArrays[i].mSubArray.size() > subArrays[idx].mSubArray.size()? i : idx;
		//	if(subArrays[i].mSubArray.size() == subArrays[idx].mSubArray.size())
			//	idx = subArrays[i].mSubArray[0] < subArrays[idx].mSubArray[0]? i : idx;
		}
	}
	return subArrays[idx].mSubArray;
}
