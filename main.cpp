#include <iostream>
#include "node.h"
#include "tree.h"
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

BST readData(string fileName)
{
    string data;
    BST b;
    ifstream fin(fileName + ".sp2020");
    if (fin.is_open())
    {
        if (fin.peek() == std::ifstream::traits_type::eof())
        {
            throw string("Error");
        }
        else
        {
            while (!fin.eof())
            {
                fin >> data;
                b.insert(data);
            }
        }
    }
    else
        cout << "Unable to open file\n";
    return b;
}

BST readData()
{
    string data, tok;
    BST b;
    getline(cin, data);
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = data.find(delimiter)) != std::string::npos)
    {
        token = data.substr(0, pos);
        b.insert(token);
        data.erase(0, pos + delimiter.length());
    }
    b.insert(data);
    return b;
}

int main(int argc, char const *argv[])
{
    BST b;
    if (argc > 1)
    {
        try
        {
            b = readData(argv[1]);
        }
        catch (string e)
        {
            cout << e << endl;
        }
        b.inOrder();
        b.postOrder();
        b.preOrder();
    }
    else
        try
        {
            b = readData(); // exceptie dupa b.getRoot trebuie sa fie nullptr si dau mesaj de eroare
            if (!b.iscreated())
                throw string("Error");
            b.inOrder();
            b.postOrder();
            b.preOrder();
        }
        catch (string e)
        {
            cout << e << endl;
        }
    return 0;
}
