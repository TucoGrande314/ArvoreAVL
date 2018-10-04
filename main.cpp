#include <iostream>
#include "Arvore.h"
using namespace std;

int main()
{
    Arvore<int>* tree = new Arvore<int>();

	int tmp;

	while (1)
	{

		cout << "\n\nType a number to include it in the tree: ";
		cin >> tmp;
		tree->incluir(tmp);

		cout << "\n\n\nTree:\n\n";
		tree->preorder();
		cout << "\n\n";
	}
}
