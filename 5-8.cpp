// Consider this Node structure:

// struct Node {
//   int data;
//   Node *next, *prev;
//   Node(int data_, Node *next_ = nullptr, Node *prev_ = nullptr) :
//     data(data_), next(next_), prev(prev_) {}
// };

// Complete the function shoop(Node *tail, int p) below that operates on a
// doubly-linked list of these Nodes, accessed via a pointer to its last node.
// (That pointer is null if the list is empty.)

// The function:

// Finds the pth node (where p >= 0)—which we'll call target—by traversing
// backward from the tail. For example, if the list contained [15, -46, 28, 6]
// and p == 2, the node found would be the one containing -46. (If p == 0, it
// stops immediately.) Then traverses forward through the list from
// target—including inspecting target itself—and finds the first node containing
// a positive number. For example, if the list contained [15, -46, 28, 6] and p
// == 2, the node found would be the one containing 28. (If the first number
// checked is positive, it stops immediately.) Returns a pointer to the node on
// which the previous step finishes. If at any point following these
// instructions leads the function off of either end of the list, it immediately
// returns nullptr. (So, it also returns nullptr for an empty list.)

// We have begun the signature of the function below. You should complete it.

#include <stdlib.h>  // in case you need the absolute value function abs

#include "problem.h"

Node *shoop(Node *tail, int p) {
  Node *ptr = tail;
  while (true) {
    if (ptr == NULL) return nullptr;
    if (p <= 0) break;
    ptr = ptr->prev;
    p -= 1;
  }
  while (true) {
    if (ptr == NULL) return nullptr;
    if (ptr->data > 0) break;
    ptr = ptr->next;
  }
  return ptr;
}