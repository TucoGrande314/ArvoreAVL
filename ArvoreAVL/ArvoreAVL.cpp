// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Arvore.h"
#include <iostream>
#include <cstdlib>
#include "Inteiro.h"

int main()
{
	Arvore* tree = new Arvore();

	int tmp;

	while (1)
	{
		
		cout << "\n\nType a number to include it in the tree: ";
		cin >> tmp;
		Inteiro* inteiro = new Inteiro(tmp);
		tree->incluir(inteiro);

		cout << "\n\n\nTree:\n\n";
		tree->print();
		cout << "\n\n\n\n";
	}
}