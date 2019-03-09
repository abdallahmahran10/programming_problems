package com.mahran;

import com.mahran.msc.Sorters;

public class Main {

	public static void main(String[] args) {
		int[] arr = new int[]{9, 1, 4, 7, 2, 0, 10};
		Sorters.selectionSort(arr);
		for (int x: arr) {
			System.out.print(x + " ");
		}
	}

}
