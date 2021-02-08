#include "tree.h"
#include <iostream>
#include <fstream>
using namespace std;
ofstream iout("file.inorder");
ofstream prout("file.preorder");
ofstream pout("file.postorder");
BST::BST()
{
    _root = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::insert(node *treeNode, std::string key)
{
    if (!treeNode)
    {
        treeNode = new node(key);
        _root = treeNode;
    }
    else
    {
        if (key.substr(0, 2) == treeNode->key)
        {
            treeNode->data.push_back(key);
        }
        else if (key < treeNode->key)
        {
            if (!treeNode->left)
            {
                node *treeTemp = new node(key);
                treeNode->left = treeTemp;
            }
            else
                insert(treeNode->left, key);
        }
        else
        {
            if (!treeNode->right)
            {
                node *treeTemp = new node(key);
                treeNode->right = treeTemp;
            }
            else
                insert(treeNode->right, key);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
int BST::getHeight(node *treeNode)
{
    if (!treeNode)
        return 0;
    return 1 + max(getHeight(treeNode->left), getHeight(treeNode->right));
}

/////////////////////////////////////////////////////////////////////////////////////////
bool BST::isBalanced(node *treeNode)
{
    if (!treeNode)
        return false;
    int leftHeight = getHeight(treeNode->left);
    int rightHeight = getHeight(treeNode->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
node *BST::getMaxNode()
{
    if (!_root)
    {
        cout << " the BST is empty!" << endl;
        return NULL;
    }
    node *treeNode = _root;
    while (treeNode->right)
        treeNode = treeNode->right;
    return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
node *BST::getMinNode()
{
    if (!_root)
    {
        cout << " the BST is empty!" << endl;
        return NULL;
    }
    node *treeNode = _root;
    while (treeNode->left)
        treeNode = treeNode->left;
    return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::deleteBST(node *treeNode)
{
    if (!treeNode)
        return;

    node *curTreeNode = treeNode;
    node *leftTreeNode = treeNode->left;
    node *rightTreeNode = treeNode->right;
    deleteBST(leftTreeNode);
    deleteBST(rightTreeNode);
    delete (curTreeNode);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::inOrder(node *treeNode)
{
    if (!treeNode)
        return;
    inOrder(treeNode->left);
    iout << treeNode->key << "-> ";
    iout << "[ ";
    string x;
    for (auto i : treeNode->data)
        if (i != treeNode->data[treeNode->data.size() - 1])
            iout << i << ",";
        else
            x = i;
    iout << x;
    iout << " ] ";
    inOrder(treeNode->right);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::preOrder(node *treeNode)
{
    if (!treeNode)
        return;
    prout << treeNode->key << "-> ";
    prout << "[ ";
    string x;
    for (auto i : treeNode->data)
        if (i != treeNode->data[treeNode->data.size() - 1])
            prout << i << ",";
        else
            x = i;
    prout << x;
    prout << " ] ";
    preOrder(treeNode->left);
    preOrder(treeNode->right);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::postOrder(node *treeNode)
{
    if (!treeNode)
        return;
    postOrder(treeNode->left);
    postOrder(treeNode->right);
    pout << treeNode->key << "-> ";
    pout << "[ ";
    string x;
    for (auto i : treeNode->data)
        if (i != treeNode->data[treeNode->data.size() - 1])
            pout << i << ",";
        else
            x = i;
    pout << x;
    pout << " ] ";
}
