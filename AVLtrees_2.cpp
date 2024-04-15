/**
 * @file AVLtrees.cpp
 * @author Ozgur Tuna Ozturk (ozturk_ozgur@wheatoncollege.edu)
 * @brief This is the implementation file for the AVLtrees.h header file.
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 *
 */

/* --- IMPORTS --- */
#include "AVLtrees.h"
#include <stack>
#include <iostream>
#include <cmath>
#include <queue>
/* --- End of IMPORTS --- */

/* --- NAMESPACE --- */
using namespace std;
/* --- End of NAMESPACE --- */

/* --- BINARY TREE CLASS --- */

/* --- Helper Functions --- */

/**
 * @brief Inserts an element into the tree according to the binary search tree rules. 
 * 
 * This function inserts a new node with a given key into the binary search tree. 
 * If the key already exists in the tree, the function returns without inserting a new node.
 * If the root is null, a new node is created as the root. Otherwise, the function traverses 
 * the tree to find the correct location for the new node and inserts it as a child of the 
 * appropriate parent node.
 *
 * @param key The key of the node to be inserted.
 * @param root The root of the tree.
 * @return TreeNode* The root of the tree after insertion.
 */
binaryTree::TreeNode* binaryTree::insertItem(const elemType key, TreeNode* root) {

    // If the root is null, create a new node as root.
    if (root == nullptr) {
        root = new TreeNode;
        root->data = key;
        root->left = root->right = nullptr;
        return root;
    }

    // Initialize current node as root and parent as null.
    TreeNode* current = root;
    TreeNode* parent = nullptr;

    // Traverse the tree to find the correct location for the new node.
    while (current != nullptr) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            // Key already exists in the tree, so return without inserting.
            return root;
        }
    }

    // Create a new node.
    TreeNode* newNode = new TreeNode;
    newNode->data = key;
    newNode->left = newNode->right = nullptr;

    // Insert the new node as a child of the parent node.
    if (key < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // Return the root of the tree.
    return root;
}

/**
 * @brief Deletes an element from the tree according to the binary search tree rules. 
 * 
 * This function deletes a node from the binary search tree. If the node has two children, 
 * it finds the largest node in the left subtree, replaces the node's data with the replacement's 
 * data, updates the parent's child pointer, and deletes the replacement node. If the node has 
 * one or no children, it updates the parent's child pointer and deletes the node. If the node 
 * to be deleted is the root, it updates the root.
 *
 * @param key The key of the node to be deleted.
 * @param root The root of the tree.
 * @return TreeNode* The root of the tree after deletion.
 */
binaryTree::TreeNode* binaryTree::deleteItem(const elemType key, TreeNode* root) {
    // Initialize current node as root and parent as null.
    TreeNode* parent = nullptr;
    TreeNode* current = root;

    // Traverse the tree to find the node to be deleted and its parent.
    while (current != nullptr && current->data != key) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node is not found, return the original root.
    if (current == nullptr) {
        return root;
    }

    // If the node has two children...
    if (current->left != nullptr && current->right != nullptr) {
        // Find the largest node in the left subtree.
        TreeNode* replacement = current->left;
        TreeNode* replacementParent = current;

        while (replacement->right != nullptr) {
            replacementParent = replacement;
            replacement = replacement->right;
        }

        // Replace the node's data with the replacement's data.
        current->data = replacement->data;

        // Update the parent's child pointer.
        if (replacementParent->left == replacement) {
            replacementParent->left = replacement->left;
        } else {
            replacementParent->right = replacement->left;
        }

        // Delete the replacement node.
        delete replacement;
    }
    // If the node has one or no children...
    else {
        // Get the node's child (if it exists).
        TreeNode* child = (current->left != nullptr) ? current->left : current->right;

        // If the node to be deleted is the root, update the root.
        if (current == root) {
            root = child;
        }
        // If the node to be deleted is a left child, update the parent's left child.
        else if (current == parent->left) {
            parent->left = child;
        }
        // If the node to be deleted is a right child, update the parent's right child.
        else {
            parent->right = child;
        }

        // Delete the node.
        delete current;
    }

    // Return the root of the tree.
    return root;
}

/**
 * @brief Finds the size of the tree.
 * 
 * This function calculates the size of the tree, which is the number of nodes in the tree.
 * It uses a stack to traverse the tree in a depth-first manner. For each node, it increments
 * a count and pushes the node's children onto the stack. It continues until there are no more
 * nodes to visit (i.e., the stack is empty). The count of visited nodes is the size of the tree.
 *
 * @param root The root of the tree.
 * @return int The number of nodes in the tree.
 */
int binaryTree::size(TreeNode* root) const {
    // If the root is null, the tree is empty, so return 0.
    if (root == nullptr) {
        return 0;
    }

    // Initialize a stack and push the root onto it.
    stack<TreeNode*> stack;
    stack.push(root);

    // Initialize a count of nodes.
    int count = 0;

    // While there are nodes to visit...
    while (!stack.empty()) {
        // Pop a node from the stack and increment the count.
        TreeNode* node = stack.top();
        stack.pop();
        count++;

        // If the node has a left child, push it onto the stack.
        if (node->left != nullptr) {
            stack.push(node->left);
        }
        // If the node has a right child, push it onto the stack.
        if (node->right != nullptr) {
            stack.push(node->right);
        }
    }

    // Return the count of nodes.
    return count;
}

/**
 * @brief Finds the height of the tree.
 * 
 * This function calculates the height of the tree, which is the maximum depth of the tree.
 * It uses a stack to traverse the tree in a depth-first manner. For each node, it increments
 * a count and pushes the node's children onto the stack. It continues until there are no more
 * nodes to visit (i.e., the stack is empty). The maximum count of visited nodes is the height
 * of the tree.
 *
 * @param root The root of the tree.
 * @return int The height of the tree.
 */
int binaryTree::height(TreeNode* root) const {
    // If the root is null, the tree is empty, so return 0.
    if (root == nullptr) {
        return -1;
    }

    // Initialize a stack and push the root onto it.
    stack<TreeNode*> stack;
    stack.push(root);

    // Initialize a count of nodes.
    int count = -1;
    int maxCount = -1;

    // While there are nodes to visit...
    while (!stack.empty()) {
        // Pop a node from the stack and increment the count.
        TreeNode* node = stack.top();
        stack.pop();
        count++;

        // If the node has a left child, push it onto the stack.
        if (node->left != nullptr) {
            stack.push(node->left);
        }
        // If the node has a right child, push it onto the stack.
        if (node->right != nullptr) {
            stack.push(node->right);
        }

        // If the count is greater than the max count, update the max count.
        if (count > maxCount) {
            maxCount = count;
        }
    }

    // Return the max count.
    return maxCount;
}

/**
 * @brief Displays the tree in a breadth-first manner.
 * 
 * This function displays the tree in a breadth-first manner, also known as level order traversal. 
 * It uses a queue to traverse the tree. For each node, it prints the node's data and pushes the 
 * node's children onto the queue. It continues until there are no more nodes to visit 
 * (i.e., the queue is empty). The nodes are printed with spaces between them to represent the 
 * level of each node in the tree.
 *
 * @param root The root of the tree.
 * @return void
 */
/*void binaryTree::display(TreeNode *root, int layer) const {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> currentLevel, nextLevel;
    currentLevel.push(root);

    while (!currentLevel.empty()) {
        TreeNode* currentNode = currentLevel.front();
        currentLevel.pop();

        if (currentNode) {
            for (int j = 0; j < size(root->left) - layer; j++) {
                cout << " ";
            }
            cout << currentNode->data << " ";
            
            nextLevel.push(currentNode->left);
            nextLevel.push(currentNode->right);
        }

        if (currentLevel.empty()) {
            cout << endl;
            layer++;
            swap(currentLevel, nextLevel);
        }
    }
}*/

void binaryTree::display(TreeNode* node, int level) const {
    if (node == nullptr) {
        return;
    }

    // Recursively print the right subtree
    display(node->right, level + 1);

    // Print spaces for indentation based on the level
    for (int i = 0; i < level; ++i) {
        std::cout << "  ";
    }

    // Print the current node's data
    std::cout << node->data << std::endl;

    // Recursively print the left subtree
    display(node->left, level + 1);
}

/* --- End of Helper Functions --- */

/* --- Traversal Helper Functions --- */

/**
 * @brief Traverses the tree in pre-order.
 * 
 * This function traverses the tree in pre-order, which means it visits the root, then the left 
 * subtree, and finally the right subtree. It uses a stack to traverse the tree. For each node, 
 * it prints the node's data and pushes the node's right child onto the stack, then moves to the 
 * left child. It continues until there are no more nodes to visit (i.e., the stack is empty).
 *
 * @param root The root of the tree.
 * @return void
 */
void binaryTree::pre_order(TreeNode* root) const {
    // If the root is null, the tree is empty, so return.
    if (root == nullptr) {
        return;
    }

    // Initialize a stack and push the root onto it.
    stack<TreeNode*> stack;
    stack.push(root);

    // While there are nodes to visit...
    while (!stack.empty()) {
        // Pop a node from the stack.
        TreeNode* node = stack.top();
        stack.pop();

        // Print the node's data.
        cout << node->data << " ";

        // If the node has a right child, push it onto the stack.
        if (node->right != nullptr) {
            stack.push(node->right);
        }

        // If the node has a left child, push it onto the stack.
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }
}

/**
 * @brief Traverses the tree in in-order.
 * 
 * This function traverses the tree in in-order, which means it visits the left subtree, then the 
 * root, and finally the right subtree. It uses a stack to traverse the tree. For each node, it 
 * pushes the node onto the stack and moves to the left child. It continues until there are no 
 * more nodes to visit (i.e., the stack is empty). The nodes are printed in order when they are 
 * popped from the stack.
 *
 * @param root The root of the tree.
 * @return void
 */
void binaryTree::in_order(TreeNode* root) const {
    // If the root is null, the tree is empty, so return.
    if (root == nullptr) {
        return;
    }

    // Initialize a stack and a current node.
    stack<TreeNode*> stack;
    TreeNode* current = root;

    // While there are nodes to visit...
    while (current != nullptr || !stack.empty()) {
        // Push the current node onto the stack and move to the left child.
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // Pop a node from the stack.
        current = stack.top();
        stack.pop();

        // Print the node's data.
        cout << current->data << " ";

        // Move to the right child.
        current = current->right;
    }
}

/**
 * @brief Traverses the tree in post-order.
 * 
 * This function traverses the tree in post-order, which means it visits the left subtree, then the 
 * right subtree, and finally the root. It uses a stack to traverse the tree. For each node, it 
 * pushes the node onto the stack and moves to the left child. It continues until there are no 
 * more nodes to visit (i.e., the stack is empty). The nodes are printed in reverse order when 
 * they are popped from the stack.
 *
 * @param root The root of the tree.
 * @return void
 */
void binaryTree::post_order(TreeNode* root) const {
    // If the root is null, the tree is empty, so return.
    if (root == nullptr) {
        return;
    }

    // Initialize two stacks.
    stack<TreeNode*> stack1;
    stack<TreeNode*> stack2;

    // Push the root onto the first stack.
    stack1.push(root);

    // While there are nodes to visit...
    while (!stack1.empty()) {
        // Pop a node from the first stack.
        TreeNode* node = stack1.top();
        stack1.pop();

        // Push the node onto the second stack.
        stack2.push(node);

        // If the node has a left child, push it onto the first stack.
        if (node->left != nullptr) {
            stack1.push(node->left);
        }

        // If the node has a right child, push it onto the first stack.
        if (node->right != nullptr) {
            stack1.push(node->right);
        }
    }

    // Print the nodes in reverse order.
    while (!stack2.empty()) {
        TreeNode* node = stack2.top();
        stack2.pop();
        cout << node->data << " ";
    }
}

/**
 * @brief Traverses the tree in level-order.
 * 
 * This function traverses the tree in level-order, which means it visits the nodes level by level 
 * from left to right. It uses a queue to traverse the tree. For each node, it prints the node's 
 * data and pushes the node's children onto the queue. It continues until there are no more nodes 
 * to visit (i.e., the queue is empty).
 *
 * @param root The root of the tree.
 * @return void
 */
void binaryTree::level_order(TreeNode* root) const {
    // If the root is null, the tree is empty, so return.
    if (root == nullptr) {
        return;
    }

    // Initialize a queue and push the root onto it.
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    // While there are nodes to visit...
    while (!nodesQueue.empty()) {
        // Pop a node from the queue.
        TreeNode* node = nodesQueue.front();
        nodesQueue.pop();

        // Print the node's data.
        cout << node->data << " ";

        // If the node has a left child, push it onto the queue.
        if (node->left != nullptr) {
            nodesQueue.push(node->left);
        }

        // If the node has a right child, push it onto the queue.
        if (node->right != nullptr) {
            nodesQueue.push(node->right);
        }
    }
}

/* --- End of Traversal Helper Functions --- */

/* --- End of BINARY TREE CLASS --- */

/* --- BINARY SEARCH TREE (BST) --- */

/* --- HELPER FUNCTIONS --- */

/**
 * @brief Searches for an element in the tree.
 * 
 * This function searches for an element in the binary search tree. It uses a stack to traverse the 
 * tree. For each node, it compares the node's data with the key. If the key is less than the node's 
 * data, it moves to the left child. If the key is greater than the node's data, it moves to the right 
 * child. If the key is equal to the node's data, it returns true. If the key is not found, it returns 
 * false.
 *
 * @param key The key to search for.
 * @param root The root of the tree.
 * @return bool True if the key is found, false otherwise.
 */
bool BST::search(const elemType key, TreeNode* root) const {
    // If the root is null, the tree is empty, so return false.
    if (root == nullptr) {
        return false;
    }

    // Initialize a stack and push the root onto it.
    stack<TreeNode*> stack;
    stack.push(root);

    // While there are nodes to visit...
    while (!stack.empty()) {
        // Pop a node from the stack.
        TreeNode* node = stack.top();
        stack.pop();

        // If the key is equal to the node's data, return true.
        if (key == node->data) {
            return true;
        }

        // If the key is less than the node's data, push the left child onto the stack.
        if (key < node->data && node->left != nullptr) {
            stack.push(node->left);
        }
        // If the key is greater than the node's data, push the right child onto the stack.
        else if (key > node->data && node->right != nullptr) {
            stack.push(node->right);
        }
    }

    // If the key is not found, return false.
    return false;
}

/* --- End of HELPER FUNCTIONS --- */

/* --- End of BINARY SEARCH TREE (BST) --- */

/* --- BALANCED BST --- */

/* --- HELPER FUNCTIONS --- */

/**
 * @brief Calculates the balance factor of a node.
 * 
 * This function calculates the balance factor of a node in the AVL tree. The balance factor is 
 * the height of the left subtree minus the height of the right subtree. It uses the height function 
 * to calculate the height of the left and right subtrees and returns the difference.
 *
 * @param node The node for which to calculate the balance factor.
 * @return int The balance factor of the node.
 */
int balancedBST::node_balance(TreeNode* node) {
    // Calculate the height of the left and right subtrees.
    int leftHeight = node_height(node->left);
    int rightHeight = node_height(node->right);

    // Return the balance factor.
    return leftHeight - rightHeight;
}

/**
 * @brief Rotates the tree to the right.
 * 
 * This function rotates the tree to the right. It takes the left child of the node as the pivot, 
 * moves the pivot to the node's position, and moves the node to the pivot's right child. It updates 
 * the parent's child pointer and returns the new root of the subtree.
 *
 * @param node The node to rotate.
 * @return TreeNode* The new root of the subtree.
 */
binaryTree::TreeNode* balancedBST::R_rotate(TreeNode* node) {
    // Get the left child of the node.
    TreeNode* pivot = node->left;

    // Move the pivot to the node's position.
    node->left = pivot->right;
    pivot->right = node;

    // Return the new root of the subtree.
    return pivot;
}

/**
 * @brief Rotates the tree to the left.
 * 
 * This function rotates the tree to the left. It takes the right child of the node as the pivot, 
 * moves the pivot to the node's position, and moves the node to the pivot's left child. It updates 
 * the parent's child pointer and returns the new root of the subtree.
 *
 * @param node The node to rotate.
 * @return TreeNode* The new root of the subtree.
 */
binaryTree::TreeNode* balancedBST::L_rotate(TreeNode* node) {
    // Get the right child of the node.
    TreeNode* pivot = node->right;

    // Move the pivot to the node's position.
    node->right = pivot->left;
    pivot->left = node;

    // Return the new root of the subtree.
    return pivot;
}

/**
 * @brief Rotates the tree to the right and then to the left.
 * 
 * This function rotates the tree to the right and then to the left. It takes the right child of the 
 * node as the pivot, rotates the pivot to the right, and rotates the node to the left. It updates the 
 * parent's child pointer and returns the new root of the subtree.
 *
 * @param node The node to rotate.
 * @return TreeNode* The new root of the subtree.
 */
binaryTree::TreeNode* balancedBST::RL_rotate(TreeNode* node) {
    // Rotate the right child to the right.
    node->right = R_rotate(node->right);

    // Rotate the node to the left.
    return L_rotate(node);
}

/**
 * @brief Rotates the tree to the left and then to the right.
 * 
 * This function rotates the tree to the left and then to the right. It takes the left child of the 
 * node as the pivot, rotates the pivot to the left, and rotates the node to the right. It updates the 
 * parent's child pointer and returns the new root of the subtree.
 *
 * @param node The node to rotate.
 * @return TreeNode* The new root of the subtree.
 */
binaryTree::TreeNode* balancedBST::LR_rotate(TreeNode* node) {
    // Rotate the left child to the left.
    node->left = L_rotate(node->left);

    // Rotate the node to the right.
    return R_rotate(node);
}

/**
 * @brief Balances the tree at the given node.
 * 
 * This function checks the balance factor of the given node and performs the appropriate rotation(s) 
 * to balance the tree. If the balance factor is greater than 1, it means the left subtree is heavier, 
 * so it performs a right rotation. If the balance factor is less than -1, it means the right subtree 
 * is heavier, so it performs a left rotation. If the balance factor is within the range [-1, 1], it 
 * means the tree is already balanced, so it does nothing.
 *
 * @param node The node to balance.
 * @return TreeNode* The new root of the subtree.
 */
binaryTree::TreeNode* balancedBST::balanceTree(TreeNode* node) {
    // Calculate the balance factor of the node.
    int balanceFactor = node_balance(node);

    // If the left subtree is heavier...
    if (balanceFactor > 1) {
        // If the left child is left-heavy or balanced, perform a right rotation.
        if (node_balance(node->left) >= 0) {
            node = R_rotate(node);
        }
        // If the left child is right-heavy, perform a left-right rotation.
        else {
            node = LR_rotate(node);
        }
    }
    // If the right subtree is heavier...
    else if (balanceFactor < -1) {
        // If the right child is right-heavy or balanced, perform a left rotation.
        if (node_balance(node->right) <= 0) {
            node = L_rotate(node);
        }
        // If the right child is left-heavy, perform a right-left rotation.
        else {
            node = RL_rotate(node);
        }
    }

    // Return the new root of the subtree.
    return node;
}

/**
 * @brief Prints the balance factors of all nodes in the tree.
 * 
 * This function performs an in-order traversal of the tree and prints the balance factor of each node. 
 * It uses a stack to keep track of the nodes to visit. For each node, it pushes the node onto the stack 
 * and moves to its left child. When it reaches a null child, it pops a node from the stack, prints the 
 * node's data and balance factor, and moves to its right child. It continues until the stack is empty 
 * and the current node is null.
 *
 * @param root The root of the tree.
 * @return void
 */
void balancedBST::balanceFactors(TreeNode* root) {
    stack<TreeNode*> nodesStack;
    TreeNode* currentNode = root;

    while (currentNode != nullptr || !nodesStack.empty()) {
        // Reach the left most Node of the currentNode
        while (currentNode != nullptr) {
            nodesStack.push(currentNode);
            currentNode = currentNode->left;
        }

        // BackTrack from the empty subtree and visit the Node at the top of the stack; however, if the stack is empty you are done
        currentNode = nodesStack.top();
        nodesStack.pop();

        int balanceFactor = node_balance(currentNode);
        cout << currentNode->data << ":" << balanceFactor << " ";

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        currentNode = currentNode->right; 
    }

    cout << endl;
}

/* --- End of HELPER FUNCTIONS --- */

/* --- End of BALANCED BST --- */