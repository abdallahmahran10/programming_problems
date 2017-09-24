/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/encode-and-decode-tinyurl/description/
	Date: 9/24/2017
  my run time beats 74.9% of other cpp submissions 
*/

// Includes
#include "../common.h"
// Types
class Solution {
private:
    vector<int> BASE62_ALPHABET;
	unordered_map<string, string> hm;

public:
	Solution()
	{
		char a[] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		BASE62_ALPHABET = vector<int>(a, a + sizeof a / sizeof a[0]);
	}

	
	string getHash(string str)
	{
		string id="";
		for(int i=str.size()-1; i>=0 && i>=str.size()-7; i--)
			id.push_back(BASE62_ALPHABET[str[i]% 62]);
		return id;
	}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string id = getHash(longUrl);
		hm[id] = longUrl;
		string baseUrl="http://tinyurl.com/";
		string res=baseUrl+id;
		return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string id= "";
		int i=shortUrl.size()-7;
		while(i <shortUrl.size() )
		{
			id.push_back(shortUrl[i++]);
		}

		return hm[id];
    }
};
