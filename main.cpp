#include <iostream>
#include "Arvore.h"
using namespace std;

int main()
{
    Arvore<int>* tree = new Arvore<int>();

	int tmp, opt;

    while(1)
    {
        cout << "\n\nWich operation do you wanna realize";
        cout << "\n1- Include a number in the tree";
        cout << "\n2- Remove a number from the tree";
        cout << "\n3- Exit the program\n";
		cin >> opt;
		switch(opt)
		{
            case 1:
                cout << "\n\nType a number to include it in the tree: ";
                cin >> tmp;
                tree->incluir(tmp);
                break;
            case 2:
                cout << "\n\nType a number to remove it from the tree: ";
                cin >> tmp;
                tree->excluir(tmp);
                break;
            case 3:
                return 0;
                break;
            default:
                break;
		}
		cout << "\nTree:\n";
        tree->preorder();
        cout << "\n\n";
    }
}
