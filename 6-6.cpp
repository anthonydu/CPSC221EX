// Consider this binary tree Node structure:

// struct Node {
//   int key;
//   int value;
//   Node *left, *right;
//   Node(int key_, int value_ = 0, Node *left_ = nullptr, Node *right_ =
//   nullptr) :
//     key(key_), value(value_), left(left_), right(right_) {}
// };

// Complete the function void smurf(Node *&node) below. node is part of (and
// maybe the overall root of) a binary tree in which there are no duplicate keys
// and no duplicate values. smurf performs pre-order traversal of node's
// subtree, where the action in the traversal is: Check if the current node's
// left and right children are non-null and the left child's key is smaller than
// the right child's key and, if so, swap the positions of the two nodes in the
// tree.

// NOTE:

// "Swapping the positions" of two nodes has a similar effect to just swapping
// the keys/values within the nodes, in that it leaves the overall shape of the
// tree unchanged after the swap. HOWEVER, you must accomplish the swap by
// manipulating the two nodes' left and right pointers and the left/right
// pointers of their parents (if any) and NOT by directly swapping the
// keys/values within the nodes. We urge you to sketch an example of the swap on
// paper before implementing! node is passed by reference. If it ends up being
// reassigned, be sure to update the reference! For each recursive call in the
// traversal, use the current node's most up-to-date child pointers (even if the
// swapping process might cause some nodes to be visited multiple times or not
// visited at all).

// Partially correct: 6.5/10

// #include <cstdlib> // in case you need the absolute value function abs
// #include <cstddef> // for NULL

// #include "problem.h"

// void smurf(Node *&node) {
//     while (node != NULL) {
//         if (node->left != NULL && node->right != NULL) {
//             if (node->left->key < node->right->key) {
//                 Node *temp = node->left;
//                 node->left = node->right;
//                 node->right = temp;
//             }

//         }
//         smurf(node->left);
//         smurf(node->right);
//     }
// }