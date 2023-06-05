#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    string name;
    vector<TreeNode*> children;

    TreeNode(string n) { name = n; }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    cout << root->name << endl;

    for (TreeNode* child : root->children) {
        printTree(child, level + 1);
    }
}

int main() {
    string bookName;
    cout << "Enter the name of the book: ";
    getline(cin, bookName);

    TreeNode* book = new TreeNode(bookName);

    while (true) {
        string chapterName;
        cout << "Enter the name of a chapter (or 'q' to quit): ";
        getline(cin, chapterName);

        if (chapterName == "q") {
            break;
        }

        TreeNode* chapter = new TreeNode(chapterName);

        while (true) {
            string sectionName;
            cout << "Enter the name of a section (or 'q' to quit): ";
            getline(cin, sectionName);

            if (sectionName == "q") {
                break;
            }

            TreeNode* section = new TreeNode(sectionName);

            while (true) {
                string subsectionName;
                cout << "Enter the name of a subsection (or 'q' to quit): ";
                getline(cin, subsectionName);

                if (subsectionName == "q") {
                    break;
                }

                TreeNode* subsection = new TreeNode(subsectionName);
                section->addChild(subsection);
            }

            chapter->addChild(section);
        }

        book->addChild(chapter);
    }

    cout << "\nBook structure:\n";
    printTree(book);

    return 0;
}
