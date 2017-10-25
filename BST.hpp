/**
 * Name: Rui Deng
 *       Dadong Jing
 * Data: Jan 12, 2016
 * Overview: this file is to implement a binary search tree and all the
 * methods are used to support its properties.
 * Assignment number: PA1
 */

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
    deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' or "==" operator when 
   *  comparing Data items. (should not use >, <=, >=)
   */ // TODO
  virtual bool insert(const Data& item) {
    //create two BSTNode 
    BSTNode<Data> *current = root;

    BSTNode<Data> *add = new BSTNode<Data>(item);
   

    //if BST is empty, add the node as root
    if(isize == 0)
    {
       root = add;
       isize++;
       iheight = 0;
       return true;
    }
    //set up a counter to keep track of what is the current height
    unsigned int counter = 0;
    //loop through the BST until current is null
    while((current == 0) == false)
    {
      //if item is less current node's data, go to left branch
      if(item < current->data)
        { 
           //go all the way down
           if((current->left == 0) == false)
           {
             current = current->left;
             counter++;
           }
           //insert the node
           else  
           {
             current->left = add;
             add->parent = current;
             isize++;
             //check if iheight need to be incremented
             if(counter == iheight)
             {
               iheight++;
             }
             return true;
           }
        }
      //if item is current node's data, return false
      else if(item == current->data)
        break;
      //else go to right branch
      else
      {
        //go all the way down
        if((current->right == 0) == false)
        {
          current = current->right;
          counter++;
        }
        //insert the node
        else
        {
          current->right = add;
          add->parent = current; 
          isize++; 
          //check if iheight need to be incremented
          if(counter == iheight)
          {
            iheight++;
          }
          return true;
        }
      }
    }
    return false;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' or "==" operator when 
   *  comparing Data items. (should not use >, <=, >=)
   */ // TODO
  iterator find(const Data& item) const {
    //initialize a current node
    BSTNode<Data> *current = root;

    //while current node is not null, keep finding
    while((current == 0) == false)
    {
      //go left or right depends on the item is larger or smaller than
      //the data inside current node, if the item is found, then break
      if(item < current->data)
        current = current->left;
      else if(item == current->data)
        break;
      else
        current = current->right;
    }

    //return an iterator pointing to the node containing the item, or
    //the last node
    return typename BST<Data>::iterator(current);
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize;
  }
  
  /** Return the height of the BST.
   */ // TODO
  unsigned int height() const {
    return iheight;
  }


  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    return isize == 0;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // TODO
  iterator begin() const {
    BSTNode<Data> *returnN = first(root);
    return returnN;
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** 
   * Inorder traverse BST, print out the data of each node in ascending order.
   * Implementing inorder and deleteAll base on the pseudo code is an easy way 
   * to get started.
   * @param BSTNode<Data> *n the head node to start printing
   */ // TODO
  void inorder(BSTNode<Data>* n) const {
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */

    //if current node is null: return;
    if(n == 0)
        return;

    //recursively traverse left sub-tree
    inorder(n->left);

    //print current node data
    std::cout << n->data << std::endl;

    //recursively traverse right sub-tree
    inorder(n->right);
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /**
   *  do a postorder traversal, deleting nodes
   *  @param BSTNode<Data> *n the head node to start the deletion
   */ // TODO
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
    
    //if current node is null: return
    if(n == 0)
        return;

    //recursively delete left sub-tree
    deleteAll(n->left);

    //recursively delte right sub-tree
    deleteAll(n->right);

    //delete current node
    delete n;
  }


 };


#endif //BST_HPP
