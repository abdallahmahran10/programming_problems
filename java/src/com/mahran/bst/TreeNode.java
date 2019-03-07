package com.mahran.bst;

import lombok.Builder;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Builder
public class TreeNode {
    private TreeNode left;
    private TreeNode right;
    private int value;
}
