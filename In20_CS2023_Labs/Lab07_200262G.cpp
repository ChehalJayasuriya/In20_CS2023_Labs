#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
        // travel to unprinted leftmost leaf node
        traverseInOrder(root->left);
        // 
        cout << root->data << " ";
        traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) 
    return newNode(key);
  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}

// finding the smallest node.key value
struct node *minValueNode(root){
  while (root->left != NULL)
    root = root->left;
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // base case
  if (root == NULL)
    return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
  if (key < root->key)
    root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
  else {
        // root has no children
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation; // if operation==-1 end of input

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}