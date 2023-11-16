// In class we have learned that binary search trees have good performance on
// average, but their heights may degenerate to . We have also learned that
// rotations can be used to alter the structure/height of binary trees while
// preserving the in-order key sequence.

// In this question, we explore a
//  process for "balancing" an arbitrary BST whose nodes also include height
//  information. The BSTHNode is defined as follows:

// class BSTHNode {
//     public:
//         int data;
//         int height;
//         BSTHNode* left;
//         BSTHNode* right;

//     // and a constructor - you do not need to know the details
// };
// The tree class in this question is a called BSTH, for a binary search tree
// with height. The BSTH class has a single private attribute, which is the root
// of the tree, and some important private functions which will be used to solve
// our balancing problem:

// class BSTH {
//     private:
//         BSTHNode* root;

//         // Tranforms the subtree rooted at nd into a right spine and returns
//         the root of the right spine
//         // nodes' height attributes are correct after rotation
//         BSTHNode* MakeRightSpine(BSTHNode* nd);

//         // Performs a right rotation around nd and returns the root of the
//         rotated subtree
//         // nodes' height attributes are correct after rotation
//         BSTHNode* RotateRight(BSTHNode* nd);

//         // Performs a left rotation around nd and returns the root of the
//         rotated subtree
//         // nodes' height attributes are correct after rotation
//         BSTHNode* RotateLeft(BSTHNode* nd);

//     // and other private and public member functions
// };
// Review - spine
// In a previous examlet, you were tasked with using rotations to transform an
// arbitrary binary tree into a spine. A right spine is a binary tree in which
// there is a single leaf node, and every non-leaf node has only one right
// child. In this question, the private BSTH function MakeRightSpine has already
// been implemented for you, and will be a crucial element of solving our
// balancing problem.

// An example demonstrating the effect of calling MakeRightSpine is shown in the
// diagram below:

// In addition to MakeRightSpine, you have at your disposal private BSTH member
// functions for basic rotation and a simple maximum function:

// // Performs a right rotation around nd and returns the root of the rotated
// subtree
// // nodes' height attributes are correct after rotation
// BSTHNode* RotateRight(BSTHNode* nd);

// // Performs a left rotation around nd and returns the root of the rotated
// subtree
// // nodes' height attributes are correct after rotation
// BSTHNode* RotateLeft(BSTHNode* nd);

// // Non-BSTH-member function.
// // Returns the larger of the two integer parameters.
// int max(int a, int b);
// The problem - Balance
// In this question, you will complete the recursive Balance function, which
// receives as a parameter a BSTHNode pointer representing the root of some
// subtree, and balances the subtree into an almost-perfect subtree, and returns
// the root of the transformed subtree. An example demonstrating the effect of
// calling Balance is shown in the diagram below:

// To solve this problem, think carefully of how you may use the MakeRightSpine
// function together with the height information which is stored in each node.

// Note that you may not allocate or deallocate any nodes in these functions;
// the transformations must be achieved entirely via rotations.

// If your test cases show "NO OUTPUT" or incomplete output, it is likely that
// your code is producing a segmentation fault. Trace your code on a very small
// tree to identify where your error may be occurring. The output for each node
// includes its key and its height.

/**
 * @file	bsth-balance.cpp
 * @description Student implementation of a function that balances a binary
 * search tree
 */

#include <cstdlib>  // for NULL, but prefer to use nullptr

#include "bsth.h"

/*** NO OTHER INCLUDES ARE ALLOWED ***/

/**
PARTIAL BSTH NODE DEFINITION:

class BSTHNode {
public:
    int data;
    int height;
    BSTHNode* left;
    BSTHNode* right;
};

PARTIAL BSTH CLASS DEFINITION:

class BSTH {
private:
    BSTHNode* root;
};

BSTH PRIVATE FUNCTIONS AVAILABLE FROM bsth.h

// Tranforms the subtree rooted at nd into a right spine and returns the root of
the right spine
// nodes' height attributes are correct after rotation
BSTHNode* MakeRightSpine(BSTHNode* nd);

// Performs a right rotation around nd and returns the root of the rotated
subtree
// nodes' height attributes are correct after rotation
BSTHNode* RotateRight(BSTHNode* nd);

// Performs a left rotation around nd and returns the root of the rotated
subtree
// nodes' height attributes are correct after rotation
BSTHNode* RotateLeft(BSTHNode* nd);

OTHER AVAILABLE FUNCTIONS:

// Returns the larger of the two integer parameters.
int max(int a, int b);

**/

/**
 * Recursively balances the subtree rooted at nd and returns the root of the
 * balanced subtree
 */
BSTHNode* BSTH::Balance(BSTHNode* nd) {
  if (nd != nullptr) {
    nd = MakeRightSpine(nd);
    if (nd->right && nd->right->height > 0) {
      nd = RotateLeft(nd);
    }
    while (nd->left && nd->right && nd->left->height - nd->right->height < -1) {
      nd = RotateLeft(nd);
    }
    nd->left = Balance(nd->left);
    nd->right = Balance(nd->right);
    int hl = nd->left ? nd->left->height : -1;
    int hr = nd->right ? nd->right->height : -1;
    nd->height = max(hl, hr) + 1;
  }
  return nd;
}