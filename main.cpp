/**
 * @file main.cpp
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This file contains the main function that tests the balancedBST class in ACLtrees lib.
 * This file tests the insert, delete, search, display, and traversal functions of the balancedBST class.
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright MIT LICENSE (c) 2024
 * 
 */

/* --- IMPORTS --- */
#include <iostream>
#include "AVLtrees.h"
/* --- End of IMPORTS --- */

/* --- NAMESPACE --- */
using namespace std;
/* --- End of NAMESPACE --- */

/* --- MAIN --- */
/**
 * @brief In this function we test the AVL tree class by inserting the alphabet into the tree,
 * then we test the number of nodes, height, balance factors, and traversals of the tree.
 * After inserting nodes we display the tree and then delete some nodes and display the tree again.
 * 
 * @return int: 0 represents normal process termination.
 */
int main() {

    balancedBST* tree = new balancedBST();

    // Insert a single letter in to the tree
    for (int i = 0; i < 26; i++) {
        tree->insertNode((char)i+97);
    }

    // Show the size of the tree
    cout << "Size of the tree: " << tree->treeNodeCount() << endl;

    // Show the height of the tree
    cout << "Height of the tree: " << tree->height() << endl;

    // Display the tree
    cout << "Displaying the tree: " << endl;
    tree->display();
    cout << endl;

    // Test Traversal functions
    cout << "Traversals: " << endl;
    cout << endl << "Pre-order: ";
    tree->pre_order_Traversal();
    cout << endl << "In-order: ";
    tree->in_order_Traversal();
    cout << endl << "Post-order: ";
    tree->post_orderTraversal();
    cout << endl << "Level-order: ";
    tree->level_order_Traversal();
    cout << endl;

    // Test balance Factors function
    cout << "Balance Factors: " << endl;
    tree->balanceFactors();

    // Delete the single letter from the tree
    tree->deleteNode('a');
    tree->deleteNode('a');

    // Display the tree
    cout << "Displaying the tree: " << endl;
    tree->display();
    cout << endl;

    // Show the size of the tree
    cout << "Size of the tree: " << tree->treeNodeCount() << endl;

    // Test search function
    cout << "Searching for 'a': " << tree->searchItem('a') << endl;

}

/* --- End of MAIN --- */