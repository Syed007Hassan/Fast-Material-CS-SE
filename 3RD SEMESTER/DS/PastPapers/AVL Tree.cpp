#include <iostream>
using namespace std;

class Node {
  public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int height(Node *N) 
{
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) 
{
  if(a>b)
  return a;
  
  else
  return b;
}

Node *newNode(int key)
{
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

Node *rightRotate(Node *y) 
{
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

Node *leftRotate(Node *y) 
{
  Node *x = y->right;
  Node *T2 = x->left;
  x->left = y;
  y->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return x;
}

int getBalanceFactor(Node *N) 
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

Node *insertNode(Node *node, int key) 
{
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left), height(node->right));
  
  int balanceFactor = getBalanceFactor(node);
  
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
     }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->key<<endl;
		inorder(root->right);
	}
}

Node *nodeWithMimumValue(Node *node) 
{
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *deleteNode(Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      delete(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}



int main() 
{
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  inorder(root);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  inorder(root);
  getchar();
}


