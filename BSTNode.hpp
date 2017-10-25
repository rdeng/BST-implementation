/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Jan 12, 2016
 * Overview: this file is to implement a node class for binary search tree
 * and all the methods are used to support the node's properties.
 * Assignment number: PA1
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    //initialize the current node
    BSTNode<Data> *current = this;

    //traverse down the tree when the node has a right child
    if( current->right != NULL )
    {
      current = current->right;

      //find the very left node after go right
      while(current->left != NULL)
      {
        current = current->left;
      }
      return current;
    }

    //when the current node has no right child, make another current
    //node and parent node for traverse up
    BSTNode<Data> *curr = this;
    BSTNode<Data> *par = curr->parent;

    //go up until find the successor
    while(par != NULL && curr == par->right)
    {
      curr = par;
      par = par->parent;
    }

    return par;
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
