#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *left, *right;
};
//inserting nodes
struct Node* newNode(int n) {
   struct Node* root = new Node();
   root->data = n;
   root->left = root->right = NULL;
   return root;
}
int maxSum(struct Node* root) {
   if (root == NULL)
      return 0;
   int res = maxSum(root->left);
   if (root->left != NULL && root->right != NULL) {
      int sum = root->data + root->left->data + root->right->data;
      res = max(res, sum);
   }
   return max(res, maxSum(root->right));
}
int main() {
   struct Node* root = newNode(15);
   root->left = newNode(16);
   root->left->left = newNode(8);
   root->left->left->left = newNode(55);
   root->left->right = newNode(67);
   root->left->right->left = newNode(44);
   root->right = newNode(17);
   root->right->left = newNode(7);
   root->right->left->right = newNode(11);
   root->right->right = newNode(41);
   cout << maxSum(root);
   return 0;
}
