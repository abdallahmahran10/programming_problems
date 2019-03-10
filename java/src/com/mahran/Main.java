package com.mahran;

import com.mahran.msc.Searchers;
import com.mahran.msc.Sorters;

public class Main {

	public static void main(String[] args) {
		int[] arr = new int[]{10, 19,  21, 1};
//		Sorters.quickSort(arr);
		for (int x: arr) {
			System.out.print(x + " ");
		}
		System.out.println();
		System.out.println(Searchers.countRotation0(arr));
		System.out.println(Searchers.countRotation1(arr));
	}

}
