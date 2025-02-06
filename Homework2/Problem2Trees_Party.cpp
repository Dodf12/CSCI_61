#include <iostream>
using namespace std;

//TreeNode class.
class TreeNode 
{
  public:
      TreeNode(int v) : value(v)
       {
          leftChild = nullptr;
          rightChild = nullptr;
       }


      int value;
      TreeNode* leftChild;
      TreeNode* rightChild;
};

bool searchValue(TreeNode* root, int val) 
{
  //Goes here if value has never been found
    if (root == nullptr) 
    {
        return false; 
    }

    //Returns true if the value is found
    if (root->value == val) 
    {
        return true;
    }

    //Goes to left node if value is less than root
    if (val < root->value) 
    {
        return searchValue(root->leftChild, val); 
    }

    //Goes to right node if value is greater than root
    else
    {
        return searchValue(root->rightChild, val);
    }
}


TreeNode* insertNode(TreeNode* root, int value) 
{
    
    // Checking if tree exists. Makes a new tree from scratch otherwise
    if (root == nullptr) 
    {
        return new TreeNode(value);
    }
    
    // Goes to the left node if the current value is less than root value
    if (value < root->value) 
    {
        root->leftChild= insertNode(root-> leftChild, value);
    }
    
    // Goes into right node if current value is more than root value
    else if (value > root->value) 
    {
        root->rightChild= insertNode(root->rightChild, value);
    }
    
    // Returning root.
    return root;
}



int main() 
{

    int Number;
    TreeNode* root = nullptr;

    // Reading inputs from first line & inserting to root.
    cout << "Enter the numbers that are assigned to the guests: ";
    while (cin >> Number) 
    {
        root = insertNode(root, Number);
        
        // Checking if newline is encountered.
        if (cin.peek() == '\n') {break;}
    }

    // Reading inputs from second line & outputting search status for each.
    cout << "Enter placard # to search: ";
    while (cin >> Number) 
    {
      bool temp = searchValue(root, Number);
      
      if (temp == false) { cout << "No ";}
      else if(temp == true) { cout << "Yes ";}
      
      // Checking if newline is encountered.
      if (cin.peek() == '\n'){break;}
    }
    
    // Ending program with newline.
    cout << endl;
    
    return 0;
}