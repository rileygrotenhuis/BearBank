// Specification file for the OfficialTree class
#ifndef OFFICIALTREE_H
#define OFFICIALTREE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class OfficialTree
{
private:
   struct TreeNode
   {
      BankOfficial value;
      TreeNode *left;  // Pointer to left child node
      TreeNode *right; // Pointer to right child node
   };

   TreeNode *root; // Pointer to the root node

   // Private member functions
   bool search(TreeNode *&, string);
   bool deleteNode(BankOfficial, TreeNode *&);
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

   TreeNode* createNode(BankOfficial key) {
      /* Utility function that simply creates a node */
      TreeNode* node = new TreeNode(); 
      node->value = key;  
      node->left = nullptr;  
      node->right = nullptr;  

      return(node);  
   }

   TreeNode* insert(TreeNode* node, BankOfficial value) {
      /* Recursively inserts a value into the BST using node as the root, then 
      returns the new root of the subtree */

      if (node == nullptr) // if it's the start to the BST
         return(createNode(value));
   
      if (value.getUsername() < node->value.getUsername()) // if node needs to be inserted on the left
         node->left = insert(node->left, value);

      else if (value.getUsername() > node->value.getUsername()) // if node needs to be inserted on the right
         node->right = insert(node->right, value);

      else // can't be equal
         return node;

      /****  BALANCING FUNCTIONALITY  ****/

      int balance = isBalanced(node);

      // If rotating right
      if (balance > 1 && value.getUsername() < node->left->value.getUsername())
         return rightRotation(node);
   
      // if rotating left
      if (balance < -1 && value.getUsername() > node->right->value.getUsername())
         return leftRotation(node);

      // if you need a left then right rotation
      if (balance > 1 && value.getUsername() > node->left->value.getUsername()) {
         node->left = leftRotation(node->left);
         return rightRotation(node);
      }

      // if you need a right then left rotation
      if (balance < -1 && value.getUsername() < node->right->value.getUsername()) {
         node->right = rightRotation(node->right);
         return leftRotation(node);
      }

      return node;
   }
    

public:
    int leafCount;

   // Constructor
   OfficialTree()
   {
      root = nullptr;
      leafCount = 0;
   }

   // Destructor
   ~OfficialTree()
   {
      // destroySubTree(root);
   }

   // Binary tree operations
   bool deleteN(BankOfficial);
   int height(TreeNode*);
   int isBalanced(TreeNode*);
   void getLeafs(TreeNode*);
   bool searchNode(string);
   
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

   void insertNode(string value) {
      vector <string> valueV;
      valueV = stringToVector(value);
      BankOfficial newOfficial;

      newOfficial.setUsername(valueV[0]);
      newOfficial.setPassword(valueV[1]);

      root = insert(root, newOfficial);
   }
};
#endif

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void OfficialTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value.getUsername() << endl; //Left then right
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via Preorder traversal.  *
//****************************************************************

void OfficialTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
        cout << nodePtr->value.getUsername() << endl; //Before left and right
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via Postorder traversal.  *
//****************************************************************

void OfficialTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value.getUsername() << endl; //After all subtrees
   }
}

bool OfficialTree::searchNode(string input){
   /* takes the input and gives it to search along with the root. Returns a bool if successful. */
   if (search(root, input)) {
      return true; //If search find the input
   }
   else {
      return false; //No input found
   }
}

//Used to search through the list
bool OfficialTree::search(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
        return false;
 
   if (nodePtr->value.getUsername() == input)
      return true;

   bool leftChild = search(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = search(nodePtr->right, input);

   return rightChild;
}

bool OfficialTree::deleteN(BankOfficial num) {
   /* takes in the input as num and calls deleteNode. Gives deleteNode the num
   and the root. */
   if (deleteNode(num, root)){
      return true;
   }

   return false;
}

bool OfficialTree::deleteNode(BankOfficial num, TreeNode *& node) {
   /* function to delete a given node with the matching num to value.
   This function checks whether the num is on the left or right side of the tree,
   or if num equals the node value. If it does, then it does operations based on if it
   has no children, 1 child, or 2 children. Return true if a successful deletion occured.
   Return false if num could not be found inside the tree. */
   TreeNode *root = nullptr;
   TreeNode *nodePtr = node;

   if (node == nullptr) // the node doesn't exist
      return false;

   if (node->value.getUsername() > num.getUsername()) { // if num is smaller, then left
      if (node->left == nullptr) {
         return false;
      }
      deleteNode(num, node->left);
   }

   else if (num.getUsername() > node->value.getUsername()) { // if num is bigger, then it's right
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

int OfficialTree::height(TreeNode* node) {
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

int OfficialTree::isBalanced(TreeNode* node) {
   /* checks if the tree is balanced, returns an integer of the left
   subtree minus the right. */
   int leftHeight, rightHeight;

   if (node == nullptr)
      return 0;
   leftHeight = height(node->left);
   rightHeight = height(node->right);

   return (leftHeight - rightHeight);
}

void OfficialTree::getLeafs(TreeNode *nodePtr){
    if(nodePtr){
        if(nodePtr->left == nullptr && nodePtr->right == nullptr){
            leafCount++;
        }
        getLeafs(nodePtr->right);
        getLeafs(nodePtr->left);
    }
}