#include <iostream>
using namespace std;

class TreeNode
{public:
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree
{private:
        TreeNode *root;
        TreeNode *insertNode(TreeNode *node, int value)
        {   if (node == nullptr)
            { node = new TreeNode(value);
            }
            else
            {   if (value < node->data)
                { node->left = insertNode(node->left, value);
                }
                else
                { node->right = insertNode(node->right, value);
                }
            }
            return node;
        }

        int findLongestPath(TreeNode *node)
        {   if (node == nullptr)
            { return 0;}
            int leftPath = findLongestPath(node->left);
            int rightPath = findLongestPath(node->right);
            return max(leftPath, rightPath) + 1;
        }

        int findMinimumValue(TreeNode *node)
        {   if (node == nullptr)
            {   return -1; }
            while (node->left != nullptr)
            {
                node = node->left;
            }
            return node->data;
        }

        void swapPointers(TreeNode *node)
        {   if (node == nullptr)
            {   return;
            }
            swap(node->left, node->right);
            swapPointers(node->left);
            swapPointers(node->right);
        }

        TreeNode *searchValue(TreeNode *node, int value)
        {   if (node == nullptr || node->data == value)
            {   return node;
            }
            if (value < node->data)
            {
                return searchValue(node->left, value);
            }
            else
            {
                return searchValue(node->right, value);
            }
        }

    public:
        BinarySearchTree()
        {   root = nullptr; }

        void insert(int value)
        {   root = insertNode(root, value); }

        int longestPathFromRoot()
        {   return findLongestPath(root);  }

        int minimumValue()
        {   return findMinimumValue(root);  }

        void swapPointers()
        {   swapPointers(root); }

        bool search(int value)
        {   return searchValue(root, value) != nullptr; }

        void display()
        {   displayHelper(root, 0); }

        void displayHelper(TreeNode *node, int level)
        {   if (node == nullptr)
            {   return; }
            displayHelper(node->right, level + 1);
            for (int i = 0; i < level; i++)
            {
                cout << "\t";
            }
            cout << node->data << endl;
            displayHelper(node->left, level + 1);
        }
};

int main()
{
    BinarySearchTree bst;
    while (true)
    {
        int value;
        cout << "Enter a value to insert (or -1 to stop): ";
        cin >> value;

        if (value == -1)
        {
            break;
        }

        bst.insert(value);
    }
    
    cout << "\nBinary Search Tree:" << endl;
    bst.display();
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a new node\n";
        cout << "2. Find the number of nodes in the longest path from the root\n";
        cout << "3. Find the minimum data value in the tree\n";
        cout << "4. Change the tree by swapping left and right pointers\n";
        cout << "5. Search for a value\n";
        cout << "6. Display the tree\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            bst.insert(value);
            cout << "Node inserted successfully!\n";
        } else if (choice == 2) {
            cout << "Number of nodes in the longest path from the root: " << bst.longestPathFromRoot() << endl;
        } else if (choice == 3) {
            cout << "Minimum value in the tree: " << bst.minimumValue() << endl;
        } else if (choice == 4) {
            bst.display();
            bst.swapPointers();
            cout << "\nBinary Search Tree after swapping pointers:" << endl;
            bst.display();
        } else if (choice == 5) {
            int value;
            cout << "Enter the value to search: ";
            cin >> value;
            bool found = bst.search(value);
            if (found) {
                cout << "Value found in the tree!\n";
            } else {
                cout << "Value not found in the tree!\n";
            }
        } else if (choice == 6) {
            cout << "\nBinary Search Tree:\n";
            bst.display();
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
