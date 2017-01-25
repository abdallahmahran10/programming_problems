/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/validate-ip-address/
	Date: 1/22/2017
*/
// Includes
// Types
// Functions
    typedef unsigned short  us8;
    const string IPV4 = "IPv4", IPV6 = "IPv6", NEITHER = "Neither";
    const us8 IPV4_MAX_SIZE = 3 + 3*4, IPV6_MAX_SIZE = 7 + 4*8;
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    
    //
    int toDec(string str)
    {
    	if(str.size() >1 && str[0] =='0' )
    		return -1;
    	int dec=0;
    	for(int i=0; i<str.size(); i++)
    	{
    if(str[i]>= '0' && str[i] <= '9')
      dec = dec * 10  + (int)(str[i] - '0');
    else
      return -1;
  }
  return dec;
}
//
bool isValidIPv4Block(string block)
{
  if(block.empty() || block.size()>3)
    return false;
  int dec = toDec(block);
  return dec > -1 && dec < 256;
}
//
string isValidateIPv4(string IP)
{
  stringstream ss(IP);
  string block;
  us8 blocksCount = 4;
  while(blocksCount && getline(ss,block,'.') && isValidIPv4Block(block)) blocksCount--;
  return ss.eof() && blocksCount == 0? IPV4 : NEITHER ;
}
bool isValidHex(char ch)
{
  return validIPv6Chars.find(ch) != string::npos;
}
//
bool isValidHex(string str)
{
  for(int i=0; i<str.size(); i++)
    if(!isValidHex(str[i]))
      return  false;
  return true;
}
//
bool isValidIPv6Block(string block)
{
  if(block.empty() || block.size()>4)
    return false;
  return isValidHex(block);
}
//
string isValidateIPv6(string IP)
{
  stringstream ss(IP);
  string block;
  us8 blocksCount = 8;
  while(blocksCount && getline(ss,block,':') && isValidIPv6Block(block)) blocksCount--;
  return ss.eof() && blocksCount == 0? IPV6 : NEITHER ;
}
string validIPAddress(string IP) {
  if(IP.empty())
    return NEITHER;
  if(IP.size()<=IPV4_MAX_SIZE && IP.substr(0,4).find_first_of('.') != string::npos)
    return isValidateIPv4(IP);
  else if(IP.size()<=IPV6_MAX_SIZE && IP.substr(0,5).find_first_of(':') != string::npos)
    return isValidateIPv6(IP);
  return NEITHER;
}
// Test cases
void testCase()
{
	cout<<validIPAddress("172.160.254.100")<<endl;
	cout<<validIPAddress("2:d:a:1:0:E:0:4")<<endl;
	cout<<validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:")<<endl;
}
