// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Arvore.h"
#include <iostream>
#include <cstdlib>
#include "Inteiro.h"

void incluir(Arvore* tree)
{
	int tmp;
	cout << "\n\nType a number to include it in the tree: ";
	cin >> tmp;
	Inteiro* inteiro = new Inteiro(tmp);
	tree->incluir(inteiro);

	cout << "\n\n\nTree:\n\n";
	tree->preorder();
	cout << "\n\n\n\n";
}

void excluir(Arvore* tree)
{
	int tmp;
	cout << "\n\nType a number to exclude it in the tree:";
	cin >> tmp;
	Inteiro* inteiro = new Inteiro(tmp);
	cout << "\n\n\nTree:\n\n";
	//tree->excluir(inteiro);

	tree->preorder();
	cout << "\n\n\n\n";
}
int main()
{
	Arvore* tree = new Arvore();

	char opt;

	while (1)
	{
		cout << "Type the number of the procedure you want to do:\n\n";
		cout << "1- Include an information \n";
		cout << "2- Exclude an information \n\n";
		cin >> opt;
		switch (opt)
		{
		case '1':
			incluir(tree);
			break;
		case '2':
			excluir(tree);
		default:
			break;
		}
	}
}