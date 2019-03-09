package com.mahran;

import com.mahran.msc.Sorters;

public class Main {

	public static void main(String[] args) {
		//int[] arr = new int[]{10, 3, 1, 2,0, 9, -1, 7, -22};
		int[] arr = new int[]{1, 1 ,1 ,2, 2, 3, 3, 3 ,2 };
		Sorters.quickSort(arr);
		for (int x: arr) {
			System.out.print(x + " ");
		}
	}

}
