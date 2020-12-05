// Specification file for the BiTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include <iostream>
#include <vector>
#include <string>
#include "../users/BankUser.h"
using namespace std;

class BiTree
{
private:
   struct TreeNode
   {
      BankUser value;
      TreeNode *left;  // Pointer to left child node
      TreeNode *right; // Pointer to right child node
   };

   TreeNode *root; // Pointer to the root node

   // Private member functions
   bool searchUsername(TreeNode *&, string);
   bool searchPassword(TreeNode *&, string);
   bool searchFirst(TreeNode *&, string);
   bool searchLast(TreeNode *&, string);
   bool searchAddress(TreeNode *&, string);
   bool searchPhone(TreeNode *&, string);
   bool searchAccnt(TreeNode *&, string);
   bool deleteNode(BankUser, TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   void insert(TreeNode *&nodePtr, TreeNode *&newNode);
   BankUser* getUser(TreeNode *, string);
   BankUser* getUserWithAccnt(TreeNode *, string);
   BankUser* searchPhoneGetUser(TreeNode *&, string);
   BankUser* searchFirstGetUser(TreeNode *&, string);
   BankUser* searchLastGetUser(TreeNode *&, string);

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

   TreeNode* createNode(BankUser key) {
      /* Utility function that simply creates a node */
      TreeNode* node = new TreeNode(); 
      node->value = key;  
      node->left = nullptr;  
      node->right = nullptr;  

      return(node);  
   }

   TreeNode* insertL(TreeNode* node, BankUser value) {
      /* Recursively inserts a value into the BST using node as the root, then 
      returns the new root of the subtree */

      if (node == nullptr) // if it's the start to the BST
         return(createNode(value));
   
      if (value.getUsername() < node->value.getUsername()) // if node needs to be inserted on the left
         node->left = insertL(node->left, value);

      else if (value.getUsername() > node->value.getUsername()) // if node needs to be inserted on the right
         node->right = insertL(node->right, value);

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
   bool deleteN(BankUser);
   int height(TreeNode*);
   int isBalanced(TreeNode*);
   void getLeafs(TreeNode*);
   void insertNode(string);
   void insertNode2(BankUser);
   bool searchNode(string, bool, bool, bool, bool, bool);
   bool searchNode2(string);
   bool searchNode3(string);
   bool searchNode4(string);
   bool searchNode5(string);
   bool searchNode6(string);
   bool searchNode7(string);
   BankUser* searchNodePhone(string);
   BankUser* searchNodeFirst(string);
   BankUser* searchNodeLast(string);
   BankUser* getUserNode(string);
   BankUser* getUserNodeWithAccnt(string);
   
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

   void insertNodeL(string value) {
      vector <string> valueV;
      valueV = stringToVector(value);
      BankUser newUser;

      if (valueV.size() == 6) {
         newUser.setFirstName(valueV[0]);
         newUser.setLastName(valueV[1]);
         newUser.setPhoneNumber(valueV[2]);
         newUser.setAddress(valueV[3]);
         newUser.setUsername(valueV[4]);
         newUser.setPassword(valueV[5]);
      }
      else {
         newUser.setFirstName(valueV[0]);
         newUser.setLastName(valueV[1]);
         newUser.setPhoneNumber(valueV[2]);
         newUser.setAddress(valueV[3]);
         newUser.setUsername(valueV[4]);
         newUser.setPassword(valueV[5]);
         newUser.setLastLogin(valueV[6]);
      }
      root = insertL(root, newUser);
   }

   void insertNode2L(BankUser user) {
      root = insertL(root, user);
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
      cout << nodePtr->value.getUsername() << endl; //Left then right
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
        cout << nodePtr->value.getUsername() << endl; //Before left and right
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
        cout << nodePtr->value.getUsername() << endl; //After all subtrees
   }
}

bool BiTree::searchNode(string input, bool username, bool first, bool last, bool address, bool phone){
   /* takes the input and gives it to search along with the root. Returns a bool if successful. */
   if (username) {
      if (searchUsername(root, input)) {
         return true; //If search find the input
      }
      else {
         return false; //No input found
      }
   }

   else if (first) {
      if (searchFirst(root, input)) {
         return true; //If search find the input
      }
      else {
         return false; //No input found
      }
   }

   else if (last) {
      if (searchLast(root, input)) {
         return true; //If search find the input
      }
      else {
         return false; //No input found
      }
   }

   else if (address) {
      if (searchAddress(root, input)) {
         return true; //If search find the input
      }
      else {
         return false; //No input found
      }
   }

   else {
      if (searchPhone(root, input)) {
         return true; //If search find the input
      }
      else {
         return false; //No input found
      }
   }
}

bool BiTree::searchNode2(string input) {
   if (searchUsername(root, input)) {
      return true; //If search find the input
   } else {
      return false; //No input found
   }
}

bool BiTree::searchNode3(string input) {
   if (searchPassword(root, input)) {
      return true; //If search find the input
   } else {
      return false; //No input found
   }
}

bool BiTree::searchNode4(string input) {
   if (searchPhone(root, input)) {
      return true; //If search find the input
   } else {
      return false; //No input found
   }
}

bool BiTree::searchNode5(string input) {
   if (searchFirst(root, input)) {
      return true; //If search find the input
   } else {
      return false; //No input found
   }
}

bool BiTree::searchNode6(string input) {
   if (searchLast(root, input)) {
      return true; //If search find the input
   } else {
      return false; //No input found
   }
}

bool BiTree::searchNode7(string input) {
   if (searchAccnt(root, input)) {
      return true; //If search find the input
   } else {
      return false; //No input found
   }
}

//Used to search through the list
bool BiTree::searchUsername(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.getUsername() == input)
      return true;

   bool leftChild = searchUsername(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchUsername(nodePtr->right, input);

   return rightChild;
}

bool BiTree::searchPassword(TreeNode *&nodePtr, string input) {
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.getPassword() == input)
      return true;

   bool leftChild = searchPassword(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchPassword(nodePtr->right, input);

   return rightChild;
}

//Used to search through the list
bool BiTree::searchFirst(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.getFirstName() == input)
      return true;

   bool leftChild = searchFirst(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchFirst(nodePtr->right, input);

   return rightChild;
}

//Used to search through the list
bool BiTree::searchLast(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.getLastName() == input)
      return true;

   bool leftChild = searchLast(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchLast(nodePtr->right, input);

   return rightChild;
}

//Used to search through the list
bool BiTree::searchAddress(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.getAddress() == input)
      return true;

   bool leftChild = searchAddress(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchAddress(nodePtr->right, input);

   return rightChild;
}

//Used to search through the list
bool BiTree::searchPhone(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.getPhoneNumber() == input)
      return true;

   bool leftChild = searchPhone(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchPhone(nodePtr->right, input);

   return rightChild;
}

BankUser* BiTree::searchNodePhone(string phoneNum) {
   return searchPhoneGetUser(root, phoneNum);
}

BankUser* BiTree::searchNodeFirst(string firstName) {
   return searchFirstGetUser(root, firstName);
}

BankUser* BiTree::searchNodeLast(string lastName) {
   return searchLastGetUser(root, lastName);
}

//Used to search through the list
BankUser* BiTree::searchPhoneGetUser(TreeNode *&nodePtr, string input){
   if (nodePtr->value.getPhoneNumber() == input)
      return &nodePtr->value;

   bool leftChild = searchPhone(nodePtr->left, input);
   if(leftChild) 
      return searchPhoneGetUser(nodePtr->left, input); 

   return searchPhoneGetUser(nodePtr->right, input);
}

//Used to search through the list
BankUser* BiTree::searchFirstGetUser(TreeNode *&nodePtr, string input){
   if (nodePtr->value.getFirstName() == input)
      return &nodePtr->value;

   bool leftChild = searchPhone(nodePtr->left, input);
   if(leftChild) 
      return searchFirstGetUser(nodePtr->left, input); 

   return searchFirstGetUser(nodePtr->right, input);
}

//Used to search through the list
BankUser* BiTree::searchLastGetUser(TreeNode *&nodePtr, string input){
   if (nodePtr->value.getLastName() == input)
      return &nodePtr->value;

   bool leftChild = searchPhone(nodePtr->left, input);
   if(leftChild) 
      return searchLastGetUser(nodePtr->left, input); 

   return searchLastGetUser(nodePtr->right, input);
}

//Used to search through the list
bool BiTree::searchAccnt(TreeNode *&nodePtr, string input){
   if (nodePtr == NULL)
      return false;

   if (nodePtr->value.searchAccount(input))
      return true;

   bool leftChild = searchAccnt(nodePtr->left, input);
   if(leftChild) 
      return true; 

   bool rightChild = searchAccnt(nodePtr->right, input);

   return rightChild;
}

bool BiTree::deleteN(BankUser num) {
   /* takes in the input as num and calls deleteNode. Gives deleteNode the num
   and the root. */
   if (deleteNode(num, root)){
      return true;
   }

   return false;
}

bool BiTree::deleteNode(BankUser num, TreeNode *& node) {
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

BankUser* BiTree::getUserNode(string username) {
   return getUser(root, username);
}

BankUser* BiTree::getUserNodeWithAccnt(string accntNum) {
   return getUserWithAccnt(root, accntNum);
}

BankUser* BiTree::getUser(TreeNode *nodePtr, string input) {
   BankUser * user;
   if (nodePtr->value.getUsername() == input)
      return &nodePtr->value;

   else if (input <= nodePtr->left->value.getUsername()) {
      user = getUser(nodePtr->left, input);
   }

   else {
      user = getUser(nodePtr->right, input);
   }
   return user;
}

BankUser* BiTree::getUserWithAccnt(TreeNode *nodePtr, string input) {
   BankUser * user;
   if (nodePtr->value.searchAccount(input))
      return &nodePtr->value;

   else if (searchAccnt(nodePtr->left, input)) {
      user = getUserWithAccnt(nodePtr->left, input);
   }

   else { 
      user = getUserWithAccnt(nodePtr->right, input);
   }
   return user;
}

void BiTree::insertNode(string username)
{
   TreeNode *newNode = new TreeNode; // Pointer to a new node.

   vector <string> valueV;
   valueV = stringToVector(username);
   BankUser newUser;

   newUser.setUsername(valueV[0]);
   newUser.setPassword(valueV[1]);

   // Store num in new node.
   newNode->value = newUser;
   newNode->left = newNode->right = nullptr;

   // Insert the node.
   insert(root, newNode);
}

void BiTree::insertNode2(BankUser user)
{
   TreeNode *newNode = new TreeNode; // Pointer to a new node.
   // Store num in new node.
   newNode->value = user;
   newNode->left = newNode->right = nullptr;

   // Insert the node.
   insert(root, newNode);
}

void BiTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode; // Insert the node.
   else if (newNode->value.getUsername() < nodePtr->value.getUsername())
      insert(nodePtr->left, newNode); // Search the left branch
   else
      insert(nodePtr->right, newNode); // Search the right branch
}