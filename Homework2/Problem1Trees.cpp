#include <iostream>

using namespace std;

class TreeNode
{
  public:
    TreeNode* leftChild;
    TreeNode* rightChild;
    char value;

    TreeNode(char v) : leftChild(nullptr), rightChild(nullptr), value(v) {}
    
};


//Recursively prints everything in this order
void postorder(TreeNode* curr)
{

  //Seeing if node has reached a nullptr
  if (curr != nullptr)
  {
    postorder(curr->leftChild);
    postorder(curr->rightChild);
    cout << curr -> value << endl;
  }
}

//Recursive Preorder Function that prints all the possible left values before right
void preorder(TreeNode* curr)
{
  //Check if node is a nullptr has reached the end
  if (curr != nullptr)
  {
    cout << curr -> value << endl;
    preorder(curr->leftChild);
    preorder(curr->rightChild);

  }
}

int main()
{
  TreeNode* root = new TreeNode('A');

  root->leftChild = new TreeNode('L');
  root->rightChild = new TreeNode('G');
  root->leftChild->leftChild = new TreeNode('O');
  root->leftChild->rightChild = new TreeNode('R');
  root->rightChild->leftChild = new TreeNode('I');
  root->rightChild->rightChild = new TreeNode('T');
  root->leftChild->leftChild->leftChild = new TreeNode('H');
  root->leftChild->leftChild->rightChild = new TreeNode('M');
  root->leftChild->rightChild->leftChild = new TreeNode('H');

  cout << "Preorder" << endl;
  preorder(root);

  cout << "Postorder" << endl;
  postorder(root);
  return 0;
}