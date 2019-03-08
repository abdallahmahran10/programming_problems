package com.mahran.leetcode;

/*
   Author: Abdallah Mahran
   Ref: https://leetcode.com/problems/binary-tree-tilt/description/
   Date: 3/6/2019
*/
public class FindTilt {
    class Tilt {
        int tilt = 0;
    }

    public int findTilt(TreeNode root) {
        Tilt tilt = new Tilt();
        tilt(root, tilt);
        return tilt.tilt;
    }

    private int tilt(TreeNode node, Tilt tilt) {
        if(node == null) {
            return 0;
        }
        int lSum = tilt(node.left, tilt);
        int rSum = tilt(node.right, tilt);
        tilt.tilt += Math.abs(lSum - rSum);
        return node.val + lSum + rSum;
    }
}
