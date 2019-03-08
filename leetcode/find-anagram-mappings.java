/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/find-anagram-mappings/description/
	Date: 29.01.2018
*/
package playground;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Main {

	static public int[] anagramMappings(int[] A, int[] B) {
    	// TQueue<Integer> q = new LinkedList<>();
    	Map<Integer, Queue<Integer>> map = new HashMap<>();
    	for(int i=0; i<B.length; i++)
    	{
    		int k =B[i];
    		if(!map.containsKey(k))
    			map.put(k, new LinkedList<>());    		
			map.get(k).add(i);    		
    	}
    	int[] indexMpping = new int[A.length];
    	for(int i=0; i<A.length; i++)
    	{
    		indexMpping[i] = map.get(A[i]).peek();
    		map.get(A[i]).remove();
    	}
    	
        return indexMpping;
    }
	
	static public void test1()
	{
		int[] a = {12,28,46,32,50};
		int[] b = {50,12,32,46,28};
		System.out.println("Elements of Array:- "+anagramMappings(a,b));
	}
	
	public static void main(String[] args) {
		test1();
	}

}
