// In class we have learned that rotation can be applied to binary (search)
// trees to change their structure while preserving the in-order key sequence.

// In this question, we explore a way to transform any binary search tree into a
// very specific shape that we call a spine.

// Consider a binary search tree with a node definition below:

// class BSTNode {
//   public:
//     int data;
//     BSTNode* left;
//     BSTNode* right;

//     // and a constructor - you do not need to know the details
// };
// A BST class using the node definition above has a single private member
// attribute: root.

// class BST {
//   private:
//     BSTNode* root;

//   // and private and public member functions
// };
// A left spine is a binary tree in which there is a single leaf node, and every
// non-leaf node has only one left child. In this part of the question, complete
// the MakeLeftSpine function, which receives as a parameter a BSTNode pointer
// representing the root of some subtree, and transforms the subtree rooted at
// the parameter node into a left spine and returns the root of the transformed
// subtree.

// An example demonstrating the effect of calling MakeLeftSpine is shown in the
// diagram below:

// To support your implementation, you have at your disposal the following
// private BST member functions:

// // Performs a right rotation around nd and returns the root of the rotated
// subtree BSTNode* RotateRight(BSTNode* nd);

// // Performs a left rotation around nd and returns the root of the rotated
// subtree BSTNode* RotateLeft(BSTNode* nd); Both recursive and iterative
// solutions exist without additional helper functions. You are free to choose
// either implementation.

// If your test cases show "NO OUTPUT" or incomplete output, it is likely that
// your code is producing a segmentation fault. Trace your code on a very small
// tree to identify where your error may be occurring.

// How to read the tree output
// The entire tree is rotated counter-clockwise by 90 degrees, so that the root
// is on the left, and its left subtree is towards the bottom and its right
// subtree is towards the top. There is one key printed on each line, and each
// key's amount of indentation indicates the key's depth. A diagram describing
// how to read the tree is shown below:

// Once again, significant partial credit can be obtained by passing the first
// test cases: empty, one node, two nodes, three nodes.

// For interest (but don't waste too much time reading this) - Since any binary
// search tree containing
//  nodes can be transformed using only rotations into a left spine, and any
//  sequence of rotations can be reversed, proves that any binary search tree
//  containing nodes can be transformed into any other binary search tree
//  structure containing the same keys. Furthermore, the number of rotations
//  needed to achieve this is bounded by
// .

/**
 *  File: makeleftspine.cpp
 *  Description: Contains student-implemented functions for transforming
 *               a BST into a left spine
 */

#include <cstddef>  // for NULL, if needed

#include "bst.h"
/*** NO OTHER INCLUDES ARE ALLOWED ***/

// Transforms the subtree rooted at nd into a left spine and returns the root of
// the left spine
BSTNode* BST::MakeLeftSpine(BSTNode* nd) {
  // replace the line below with your implementation
  BSTNode* p = nd;
  bool isRoot = 1;
  BSTNode* root = nd;
  BSTNode* prev;
  while (p) {
    auto temp = p;
    if (p->right) {
      p = RotateLeft(p);
      if (prev) prev->left = p;
      if (isRoot) root = p;
    } else {
      isRoot = 0;
      p = p->left;
      prev = temp;
    }
  }
  return root;
}