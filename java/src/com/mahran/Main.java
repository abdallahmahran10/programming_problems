package com.mahran;

import com.mahran.geeksforgeeks.FindSubsets;

import java.util.Comparator;
import java.util.List;

public class Main {

	public static void main(String[] args) {

		new FindSubsets().findSubsets(List.of(1, 2, 3, 4))
				.stream()
				.sorted(Comparator.comparingInt(List::size))
				.forEach(System.out::println);
		System.out.println("---------------------------------------------------");
		new FindSubsets().findSubsets(List.of(4, 3, 2, 1))
				.stream()
				.sorted(Comparator.comparingInt(List::size))
				.forEach(System.out::println);
//		for (int i = 0; i < subsets.size(); i++) {
//			System.out.println(subsets.get(i).toString());
//		}
	}
}
