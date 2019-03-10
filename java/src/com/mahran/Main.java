package com.mahran;

import com.mahran.leetcode.KSmallestPairs;

public class Main {

	public static void main(String[] args) {
		testCase0();
		testCase1();
		testCase2();
		testCase3();
		testCase4();
	}

	private static void testCase0() {
		int[] a1 = new int[]{1, 7, 11};
		int[] a2 = new int[]{2, 4 ,6};
		System.out.print("[");
		new KSmallestPairs().kSmallestPairs(a1, a2, 3)
				.forEach(pairs -> System.out.print("(" + pairs[0] + ", " + pairs[1] + ")"));
		System.out.println("]");
	}

	private static void testCase1() {
		int[] a1 = new int[]{1,1,2};
		int[] a2 = new int[]{1,2,3};
		System.out.print("[");
		new KSmallestPairs().kSmallestPairs(a1, a2, 2)
				.forEach(pairs -> System.out.print("(" + pairs[0] + ", " + pairs[1] + ")"));
		System.out.println("]");
	}

	private static void testCase2() {
		int[] a1 = new int[]{1,2};
		int[] a2 = new int[]{3};
		System.out.print("[");
		new KSmallestPairs().kSmallestPairs(a1, a2, 3)
				.forEach(pairs -> System.out.print("(" + pairs[0] + ", " + pairs[1] + ")"));
		System.out.println("]");
	}


	private static void testCase3() {
		int[] a1 = new int[]{1,5,5,5};
		int[] a2 = new int[]{3,3,3};
		System.out.print("[");
		new KSmallestPairs().kSmallestPairs(a1, a2, 4)
				.forEach(pairs -> System.out.print("(" + pairs[0] + ", " + pairs[1] + ")"));
		System.out.println("]");
	}

	private static void testCase4() {
		int[] a1 = new int[]{1, 1, 2};
		int[] a2 = new int[]{1, 2, 3};
		System.out.print("[");
		new KSmallestPairs().kSmallestPairs(a1, a2, 10)
				.forEach(pairs -> System.out.print("(" + pairs[0] + ", " + pairs[1] + ")"));
		System.out.println("]");
	}

}
