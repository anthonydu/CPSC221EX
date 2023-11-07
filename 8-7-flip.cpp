// Consider a Binary Tree (not necessarily a BST) with a node definition as
// follows:

// struct TreeNode {
//   int data;
//   TreeNode* left;
//   TreeNode* right;
// };

// Two trees can be "mirror images" of one another; that is, two trees may
// contain the same keys placed such that one is the result of flipping the
// other horizontally (around a vertical axis). You will write a function to
// check whether two trees are mirror images of one another.

// Here are some examples of the IsFlip function called on the root of each
// tree.

// In the editor below, complete the IsFlip function. HINT: this function should
// be implemented recursively.

/*
 *  File: treeflip.cpp
 *  Description: Implementation of a binary tree manipulation for EX6
 */

#include <cstddef>  // For NULL

#include "tree.h"
#include "treeisflip.h"

// Test if two trees are flips of one another (structure and data)
// returns true if nd1 and nd2 are flipped, false otherwise
// See the PrairieLearn page for examples of operation
bool IsFlip(TreeNode* nd1, TreeNode* nd2) {
  if (!nd1 && !nd2) return true;
  if (!nd1) return false;
  if (!nd2) return false;
  if (nd1->data != nd2->data) return false;
  return IsFlip(nd1->left, nd2->right) && IsFlip(nd2->left, nd1->right);
}