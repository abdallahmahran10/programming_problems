/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/jewels-and-stones/description/
	Date: 29.01.2018
*/
package playground;

import java.util.Arrays;

public class Main {
	static public int numJewelsInStones(String J, String S) {
		short stones[]=new short[256];
		Arrays.fill(stones, 0, 255, (short)0);
		for (short i=0; i<S.length(); i++)
			stones[S.charAt(i) - '0']++;
		int jewelsCount =0;
		for (short i=0; i<J.length(); i++) 		
			jewelsCount += stones[J.charAt(i) - '0'];
		
		return jewelsCount;
	}
	
	static public void test1()
	{
		String j ="aA", s = "aAAbbbb";
		System.out.println(numJewelsInStones(j, s));
	}
	
	public static void main(String[] args) {
		test1();
	}

}
