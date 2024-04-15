/**
 * @file AVLtrees.h
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This file contains the binaryTree, BST, and balancedBST classes.
 * The binaryTree class is a base class for the BST and balancedBST classes.
 * This header file is used to generate an AVL balanced binary search tree.
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright MIT LICENSE (c) 2024
 * 
 */

/* --- IMPORTS --- */
#include <iostream>
/* --- End of IMPORTS --- */

/* --- NAMESPACE --- */
using namespace std;
/* --- End of NAMESPACE --- */

/* --- TYPEDEF --- */
typedef char elemType; // "placeholder" for data type	
/* --- End of TYPEDEF --- */

/* --- BINARY TREE CLASS --- */
/**
 * @brief This class generates a binary tree with insert, display, and traversal functions.
 */
class binaryTree { 

protected:  
	// binary tree node 
	struct TreeNode {					
		elemType data; 		// store data
		TreeNode * left; 	// link to left subtree 
		TreeNode * right;	// link to right subtree
	};
  	

private:	
	/* --- Helper Functions --- */
	/**
	 * @brief Inserts an element into the tree according to the binary search tree rules. 
	 * 
	 * @param key: (char) the element to be inserted
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return TreeNode*: the root of the tree
	 */
	TreeNode * insertItem (const elemType key, TreeNode *root);

	/**
	 * @brief Deletes an element from the tree according to the binary search tree rules. 
	 * 
	 * @param key: (char) the element to be deleted
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return TreeNode*: the root of the tree
	 */
	TreeNode * deleteItem (const elemType key, TreeNode *root);

	/**
	 * @brief Finds the size of the tree.
	 * In other words, finds the number of the nodes in the tree.
	 * 
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return int 
	 */
	int size (TreeNode *root) const;

	/**
	 * @brief Finds the height of the tree.
	 * 
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return int 
	 */
	int height (TreeNode *root) const;

	/**
	 * @brief Displays the tree in a tree-like structure.
	 * 
	 * @param TreeNode*: the root of the tree
	 * @param int: the layer of the tree
	 * 
	 * @return void
	 * 
	 */
	void display (TreeNode *root, int layer) const;

	/* --- End of Helper Functions --- */

	/* --- Traversal Helper Functions --- */

	/**
	 * @brief Traverses the tree in pre-order.
	 * Visit the root, then the left subtree, and finally the right subtree.
	 * 
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return void
	 * 
	 */
	void pre_order (TreeNode *root) const;

	/**
	 * @brief Traverses the tree in in-order.
	 * Visit the left subtree, then the root, and finally the right subtree.
	 * 
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return void
	 * 
	 */
	void in_order (TreeNode *root) const; 

	/**
	 * @brief Traverses the tree in post-order.
	 * Visit the left subtree, then the right subtree, and finally the root.
	 * 
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return void
	 * 
	 */
	void post_order (TreeNode *root) const; 

	/**
	 * @brief Traverses the tree in level-order.
	 * Visit the nodes level by level from left to right.
	 * 
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return void
	 * 
	 */
	void level_order (TreeNode *root) const;

	/* --- End of Traversal Helper Functions --- */
		
public:
	// constructor
	binaryTree () {root = nullptr;};

	// destructor
	~binaryTree () {delete root;};

	TreeNode * root;		// root of the tree
						
	/**
	 * @brief Inserts an element into the tree according to the binary search tree rules.
	 * This is a wrapper function for the private insertItem function.
	 * 
	 * @param key: (char) the element to be inserted
	 * 
	 * @return void
	 * 
	 */
	void insertItem (const elemType key) {root = insertItem(key, root);};

	/**
	 * @brief Deletes an element from the tree according to the binary search tree rules.
	 * This is a wrapper function for the private deleteItem function.
	 * 
	 * @param key: (char) the element to be deleted
	 * 
	 * @return void
	 * 
	 */
	void deleteItem (const elemType key) {root = deleteItem(key, root);};

	/**
	 * @brief Finds the number of nodes in the tree.
	 * This is a wrapper function for the private size function.
	 * 
	 * @return int 
	 */
	int treeNodeCount() const {return size(root);};

	/**
	 * @brief Finds the height of the tree.
	 * This is a wrapper function for the private height function.
	 * 
	 * @return int 
	 */
	int height() const {return height(root);};	

	/**
	 * @brief Finds the height of the tree.
	 * This is a wrapper function for the private height function.
	 * 
	 * @return int 
	 */
	int node_height(TreeNode *node) const {return height(node);};	

	/**
	 * @brief Displays the tree in a tree-like structure.
	 * This is a wrapper function for the private display function.
	 * 
	 */
	void display() const {display(root, 0);}; 		
						
	/* --- Traversal Functions --- */

	/**
	 * @brief Traverses the tree in pre-order.
	 * This is a wrapper function for the private pre_order function.
	 * 
	 */
	void pre_order_Traversal() const {pre_order(root); cout << endl;};

	/**
	 * @brief Traverses the tree in in-order.
	 * This is a wrapper function for the private in_order function.
	 * 
	 */
	void in_order_Traversal() const {in_order(root); cout << endl;}; 

	/**
	 * @brief Traverses the tree in post-order.
	 * This is a wrapper function for the private post_order function.
	 * 
	 */
	void post_orderTraversal() const {post_order(root); cout << endl;}; 	
	
	/**
	 * @brief Traverses the tree in level-order.
	 * This is a wrapper function for the private level_order function.
	 * 
	 */
	void level_order_Traversal() const {level_order(root); cout << endl;};
	/* --- End of Traversal Functions --- */
};	

/* --- BINARY SEARCH TREE (BST) CLASS --- */
class BST : public binaryTree {
 
private:
	/* --- Helper Functions --- */

	/**
	 * @brief Searches for an element in the tree.
	 * This is a helper function for the searchItem function.
	 * 
	 * @param key: (char) the element to be searched
	 * @param TreeNode*: the root of the tree
	 * 
	 * @return true 
	 * @return false 
	 */
  	bool search (const elemType key, TreeNode *root) const; 

	/* --- End of Helper Functions --- */

public:

	/**
	 * @brief Searches for an element in the tree.
	 * This is a wrapper function for the private search function.
	 * 
	 * @param key 
	 * @return true 
	 * @return false 
	 */
  	bool searchItem (const elemType key){return search(key, root);};

	/**
	 * @brief Inserts an element into the tree according to the binary search tree rules.
	 * 
	 * @param key: (char) the element to be inserted
	 * 
	 */
  	void insertItem (const elemType key) {binaryTree::insertItem(key);}; 

	/**
	 * @brief Deletes an element from the tree according to the binary search tree rules.
	 * 
	 * @param key: (char) the element to be deleted
	 * 
	 */
	void deleteItem (const elemType key) {binaryTree::deleteItem(key);}; 
}; 
/* --- End of BINARY SEARCH TREE (BST) CLASS --- */
			
/* --- AVL BALANCED BINARY SEARCH TREE (balancedBST) CLASS --- */
class balancedBST : public BST {

private:

	/* --- Helper Functions --- */

	/**
	 * @brief This function calculates the AVL Balance Factor for the given node
	 * 
	 * @param node: (TreeNode*) the node to calculate the balance factor
	 * @return int 
	 */
  	int node_balance(TreeNode *node);

	/**
	 * @brief This function does Right Rotation on the given node to
	 * balance the AVL tree.
	 * 
	 * @param node: (TreeNode*) the node to rotate 
	 * @return TreeNode* 
	 */
  	TreeNode* R_rotate(TreeNode *node);

	/**
	 * @brief This function does Left Rotation on the given node to
	 * balance the AVL tree.
	 * 
	 * @param node: (TreeNode*) the node to rotate
	 * @return TreeNode* 
	 */
  	TreeNode* L_rotate(TreeNode *node);

	/**
	 * @brief This function does Right-Left Rotation on the given node to
	 * balance the AVL tree.
	 * 
	 * @param node: (TreeNode*) the node to rotate
	 * @return TreeNode* 
	 */
	TreeNode* RL_rotate(TreeNode *node);

	/**
	 * @brief This function does Left-Right Rotation on the given node to
	 * balance the AVL tree.
	 * 
	 * @param node: (TreeNode*) the node to rotate
	 * @return TreeNode* 
	 */
	TreeNode* LR_rotate(TreeNode *node);

	/**
	 * @brief this function uses the balance factors to apply the
	 * appropriate rotation to an unbalanced node.
	 * A node is unbalanced if its balance factor is 
	 * greater than 1 or less than -1.
	 * 
	 * @param node: (TreeNode*) the node to balance
	 * @return TreeNode* 
	 */
	TreeNode* balanceTree(TreeNode *node);

	/**
	 * @brief This function traverses through all the nodes in the tree,
	 * and prints out all the balance factors
	 * 
	 * @param node 
	 */
	void balanceFactors(TreeNode *node); // helper function for balanceFactors

	/* --- End of Helper Functions --- */

	/**
	 * @brief Inserts an element into the tree according to the AVL rules.
	 * 
	 * @param key 
	 * @param root 
	 * @return TreeNode* 
	 */
	TreeNode* insertNode(const elemType key, TreeNode *root);

public:

	/**
	 * @brief Inserts an element into the tree according to the AVL rules.
	 * 
	 * @param key: (char) the element to be inserted
	 * 
	 */
	void insertNode(const elemType key) {cout << "Inserting: " << key << endl; root = balancedBST::insertNode(key, root);};

	/**
	 * @brief Deletes an element from the tree according to the AVL rules.
	 * 
	 * @param key: (char) the element to be deleted
	 * 
	 */
	void deleteNode(const elemType key) {cout << "Deleting: " << key << endl; binaryTree::deleteItem(key); root = balanceTree(root);};

	/**
	 * @brief Displays the balance factors of all the nodes in the tree.
	 * 
	 */
	void balanceFactors () {cout << "Balance Factors: " << endl; balanceFactors(root);};
};