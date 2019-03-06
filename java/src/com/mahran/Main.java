package com.mahran;

public class Main {

	public static void main(String[] args) {
		Trie trie = new Trie();
		System.out.println(trie.search("oba7"));
		//trie.add("oba7");
		trie.add("oba7a");
		System.out.println(trie.search("oba7"));
		System.out.println(trie.search("oba7a"));
	}

}
