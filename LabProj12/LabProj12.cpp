/*
 * LabProj12
 *
 * @Author: Chris Pham
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


struct TreeNode
{
    string word;
    int count;
    TreeNode * left;
    TreeNode * right;
};


void Insert(TreeNode* &, string);
void PrintTree(TreeNode*, ofstream &);
bool isWord(string);

int main()
{
    string inputFileName, outputFileName;
    cout << "Please type the text file name: ";
    cin >> inputFileName;
    cout << "Please give the output text file name: ";
    cin >> outputFileName;


    ifstream inputFile(inputFileName);
    if (!inputFile)
    {
        cerr << "Error: Could not open file " << inputFileName << endl;
        return 1;
    }


    ofstream outputFile(outputFileName);
    if (!outputFile)
    {
        cerr << "Error: Could not create file " << outputFileName << endl;
        return 1;
    }


    TreeNode* root = nullptr;


    string word;
    while (inputFile >> word)
    {

        word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });


        if (isWord(word))
        {

            Insert(root, word);
        }
    }


    PrintTree(root, outputFile);


    inputFile.close();
    outputFile.close();

    cout << "You are done! You can open the file \"" << outputFileName << "\" to check." << endl;
    cin.get();
    return 0;
}


void Insert(TreeNode* &root, string word)
{
    if (!root)
    {
        root = new TreeNode;
        root->word = word;
        root->count = 1;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (word < root->word)
    {
        Insert(root->left, word);
    }
    else if (word > root->word)
    {
        Insert(root->right, word);
    }
    else
    {
        root->count++;
    }
}


void PrintTree(TreeNode* root, ofstream &outputFile)
{
    if (root)
    {
        PrintTree(root->left, outputFile);
        outputFile << root->word << " " << root->count << endl;
        PrintTree(root->right, outputFile);
    }
}


bool isWord(string word)
{
    for (char c : word)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return word.length() >= 3;
}
