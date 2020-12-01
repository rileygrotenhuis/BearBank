// Specification file for the BiTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BiTree
{
private:
   struct TreeNode
   {
      int value;
      TreeNode *left;  // Pointer to left child node
      TreeNode *right; // Pointer to right child node
   };

   TreeNode *root; // Pointer to the root node

   // Private member functions
   bool search(TreeNode *&, int);
   bool deleteNode(int, TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;


   TreeNode* findMinNode(TreeNode* node) {
      // finds the min value of the tree it's given
      TreeNode* current = node;

      // loop down to find the leftmost leaf
      while (current && current->left != NULL)
         current = current->left;

      return current;
   }

   /**** Right and left rotation to shift the BST ****/

   TreeNode* rightRotation(TreeNode *oldRoot) {
      /* Rotates a tree to the right based on the given node (oldRoot). Returns the newRoot */
      TreeNode *newRoot = oldRoot->left;
      TreeNode *newRootNewChild = newRoot->right;

      // oldRoot now child of the new root, the right child of the new root changes
      // to the the left child of the oldRoot (now just the right child of the root)
      newRoot->right = oldRoot;
      oldRoot->left = newRootNewChild;

      return newRoot;
   }

   TreeNode* leftRotation(TreeNode *oldRoot) {
      /* Rotates a tree to the left based on the given node (oldRoot) Returns the newRoot */
      TreeNode *newRoot = oldRoot->right;
      TreeNode *newRootNewChild = newRoot->left;

      // Perform rotation
      newRoot->left = oldRoot;
      oldRoot->right = newRootNewChild;

      return newRoot;
   }

   bool balanceCheck() {
      /* Checks if BST is balanced by using the isBalanced function, and returns a boolean */
      if (isBalanced(root) < -1 || isBalanced(root) > 1)
         return false;
      return true;
   }

   TreeNode* createNode(int key) {
      /* Utility function that simply creates a node */
      TreeNode* node = new TreeNode(); 
      node->value = key;  
      node->left = NULL;  
      node->right = NULL;  

      return(node);  
   }

   TreeNode* insert(TreeNode* node, int value) {
      /* Recursively inserts a value into the BST using node as the root, then 
      returns the new root of the subtree */

      if (node == nullptr) // if it's the start to the BST
         return(createNode(value));
   
      if (value < node->value) // if node needs to be inserted on the left
         node->left = insert(node->left, value);

      else if (value > node->value) // if node needs to be inserted on the right
         node->right = insert(node->right, value);

      else // can't be equal
         return node;

      /****  BALANCING FUNCTIONALITY  ****/

      int balance = isBalanced(node);

      // If rotating right
      if (balance > 1 && value < node->left->value)
         return rightRotation(node);
   
      // if rotating left
      if (balance < -1 && value > node->right->value)
         return leftRotation(node);

      // if you need a left then right rotation
      if (balance > 1 && value > node->left->value) {
         node->left = leftRotation(node->left);
         return rightRotation(node);
      }

      // if you need a right then left rotation
      if (balance < -1 && value < node->right->value) {
         node->right = rightRotation(node->right);
         return leftRotation(node);
      }

      return node;
   }
    

public:
    int leafCount;

   // Constructor
   BiTree()
   {
      root = nullptr;
      leafCount = 0;
   }

   // Destructor
   ~BiTree()
   {
      // destroySubTree(root);
   }

   // Binary tree operations
   bool searchNode(int);
   bool deleteN(int);
   void remove(int);
   int height(TreeNode*);
   int isBalanced(TreeNode*);
   void getLeafs(TreeNode*);
   
   // Get Balance factor of node N  
   int getBalance(TreeNode *N)  
   {  
      if (N == NULL)  
         return 0;  
      return height(N->left) - height(N->right);  
   }  

   /* Displaying the tree in PreOrder, PostOrder, or InOrder. */

   void displayInOrder() const
   {
      displayInOrder(root);
   }

   void displayPreOrder() const
   {
      displayPreOrder(root);
   }

   void displayPostOrder() const
   {
      displayPostOrder(root);
   }

/* some extra utility functions */

   bool balanceCheckCall() {
      return balanceCheck();
   }

   int height(){
        return height(root);
   }

   void getLeafs() {
      getLeafs(root);
   }

   void destroySubTree(TreeNode*& root) {
      /* doesn't work so don't try */
      if (root) {
         destroySubTree(root->left);
         destroySubTree(root->right);
         delete root;
         root = nullptr;
      }
   }

   void insertNode(int value) {
      root = insert(root, value);
   }
};
#endif

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void BiTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl; //Left then right
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via Preorder traversal.  *
//****************************************************************

void BiTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
        cout << nodePtr->value << endl; //Before left and right
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via Postorder traversal.  *
//****************************************************************

void BiTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl; //After all subtrees
   }
}

bool BiTree::searchNode(int num){
   /* takes the num and gives it to search along with the root. Returns a bool if successful. */
    if(search(root, num)){
        return true; //If search find the input
    }
    else{
        return false; //No input found
    }
}

//Used to search through the list
bool BiTree::search(TreeNode *&nodePtr, int num){
    if (nodePtr == nullptr){
      return false; //If the root does not exist
    }
    else if(num == nodePtr -> value){
        return true; //If the value is equal to the input return true
    }
    else if (num < nodePtr->value){
      search(nodePtr->left, num); // Search the left branch
    }

    return search(nodePtr->right, num); // Search the right branch
}

bool BiTree::deleteN(int num) {
   /* takes in the input as num and calls deleteNode. Gives deleteNode the num
   and the root. */
   if (deleteNode(num, root)){
      return true;
   }

   return false;
}

bool BiTree::deleteNode(int num, TreeNode *& node) {
   /* function to delete a given node with the matching num to value.
   This function checks whether the num is on the left or right side of the tree,
   or if num equals the node value. If it does, then it does operations based on if it
   has no children, 1 child, or 2 children. Return true if a successful deletion occured.
   Return false if num could not be found inside the tree. */
   TreeNode *root = nullptr;
   TreeNode *nodePtr = node;

   if (node == nullptr) // the node doesn't exist
      return false;

   if (node->value > num) { // if num is smaller, then left
      if (node->left == nullptr) {
         return false;
      }
      deleteNode(num, node->left);
   }

   else if (num > node->value) { // if num is bigger, then it's right
      if (node->right == nullptr) {
         return false;
      }
      deleteNode(num, node->right);
   }

   else { // if num is same
      if (node->left == nullptr && node->right == nullptr) { // node has no children
         delete node; // delete its existence
         node = nullptr;
         return true;
      }

      else if (node->left && node->right) { // if node has 2 children

         // get smallest value in right subtree
         TreeNode *temp = findMinNode(node->right);

         node->value = temp->value; // give that temp value to the node we're replacing

         deleteNode(temp->value, node->right); // delete the temp value
         return true;
      }

      else { // if node has one child
         TreeNode *child;

         if (node->left)
            child = node->left;
         else
            child = node->right;

         TreeNode* nodePtr = node;
         node = child;
         delete nodePtr;
         return true;
      }
   }

   return false;
}

int BiTree::height(TreeNode* node) {
   /* recursively calls itself to traverse through the tree until it arrives
   at 0. then it goes back through and adds 1 until you get the height. */
   int leftHeight, rightHeight;

   if (node == nullptr)
      return 0;
   else {
      leftHeight = height(node->left);
      rightHeight = height(node->right);

      if (leftHeight > rightHeight) {
         return leftHeight +1;
      }
      else
         return rightHeight +1;
   }
}

int BiTree::isBalanced(TreeNode* node) {
   /* checks if the tree is balanced, returns an integer of the left
   subtree minus the right. */
   int leftHeight, rightHeight;

   if (node == nullptr)
      return 0;
   leftHeight = height(node->left);
   rightHeight = height(node->right);

   return (leftHeight - rightHeight);
}

void BiTree::getLeafs(TreeNode *nodePtr){
    if(nodePtr){
        if(nodePtr->left == nullptr && nodePtr->right == nullptr){
            leafCount++;
        }
        getLeafs(nodePtr->right);
        getLeafs(nodePtr->left);
    }
}