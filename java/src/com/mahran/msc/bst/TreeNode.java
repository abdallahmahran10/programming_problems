package com.mahran.msc.bst;

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

    public  boolean hasRightNode() {
        return right != null;
    }

    public  boolean hasLeftNode() {
        return left != null;
    }

    public  boolean isLeaf() {
        return right == null && left == null;
    }

    public  boolean hasTwoChildren() {
        return right != null && left != null;
    }
}