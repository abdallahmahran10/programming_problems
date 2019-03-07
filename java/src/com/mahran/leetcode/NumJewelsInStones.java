package com.mahran.leetcode;

import java.util.Arrays;

public class NumJewelsInStones {
    public int numJewelsInStones(String J, String S) {
    	int nJewelsInStones = 0;
    	boolean jewels[] = new boolean[128];
    	Arrays.fill(jewels, false);
    	for (int i =0; i < J.length(); i++) {
    		jewels[J.charAt(i)] = true;
    	}
    	for (int i =0; i < S.length(); i++) {
    		if (jewels[J.charAt(i)]) {
    			nJewelsInStones++;
    		}
    	}
        return nJewelsInStones;
    }
}
