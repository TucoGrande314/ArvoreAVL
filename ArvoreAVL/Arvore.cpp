#include "stdafx.h"
#include "Arvore.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


Arvore::Arvore()
{
	raiz = NULL;
}


Arvore::~Arvore()
{
}

void Arvore::incluir(Info * i)
{
	if (raiz == NULL)
		raiz = new NoArvore(i);
	else
	{
		NoArvore* atual = raiz;
		bool achou = false;
		while (!achou) 
		{
			if (i->compareTo(atual->getInfo()) < 0)
				if (atual->esquerdo == NULL)
				{
					atual->esquerdo = new NoArvore(i);
					achou = true;
				}
				else
					atual = atual->esquerdo;
			else
				if (i->compareTo(atual->getInfo()) > 0)
					if (atual->direito == NULL)
					{
						atual->direito = new NoArvore(i);
						achou = true;
					}
					else
						atual = atual->direito;
				else
				{
					cout << "\n\error: The tree does already contain this information";
					achou = true;
				}
		}
		achou = false;
		NoArvore* no = raiz;

		while (i->compareTo(no->getInfo()) != 0)
		{
			Balancear(no);
			if (i->compareTo(no->getInfo()) < 0)
				no = no->esquerdo;
			else
				no = no->direito;
		}
	}
}

void Arvore::preorder()
{
	preorder(raiz);
}

void Arvore::preorder(NoArvore * no, int indent)
{
	if (no != NULL) 
	{
		/*if (indent) 
			for (int i = 0; i < indent; i++)
				std::cout << " ";*/

		no->getInfo()->print(std::cout);
		std::cout << "(";
		if (no->esquerdo != NULL)
			preorder(no->esquerdo, indent + 1);
		else
			std::cout << " ";
		std::cout << ",";
		if (no->direito != NULL) 
			preorder(no->direito, indent + 1);
		else
			std::cout << " ";
		std::cout << ")";
	}
}

void Arvore::Balancear(NoArvore* no)
{
	if (Equilibrio(no) > 1)
	{
		if (Equilibrio(no->direito) < 0)
			rotacaoDuplaEsquerda(*no);
		else
			rotacaoEsquerda(*no);
	}	
	else
	if (Equilibrio(no) < -1)
	{
		if (Equilibrio(no->esquerdo) > 0)
			rotacaoDuplaDireita(*no);
		else
			rotacaoDireita(*no);
	}
}

void Arvore::rotacaoEsquerda(NoArvore& raiz)
{
	NoArvore* pivot = raiz.direito;
	raiz.direito = pivot->esquerdo;
	swap(raiz, *pivot);
	raiz.esquerdo = pivot;
	//raiz = *pivot;
}

void Arvore::rotacaoDuplaEsquerda(NoArvore& raiz)
{
	rotacaoDireita(*raiz.direito);
	rotacaoEsquerda(raiz);
}

void Arvore::rotacaoDireita(NoArvore& raiz)
{
	NoArvore* pivot = raiz.esquerdo;
	raiz.esquerdo = pivot->direito;
	swap(raiz, *pivot);
	raiz.direito = pivot;
	//raiz = *pivot;
}

void Arvore::rotacaoDuplaDireita(NoArvore& raiz)
{
	rotacaoEsquerda(*raiz.esquerdo);
	rotacaoDireita(raiz);
}

int Arvore::Altura(NoArvore* no)
{
	int hEsq, hDir;
	if (no == NULL) 
		return 0;
	else
	{
	if (no->esquerdo != NULL )
		hEsq = Altura(no->esquerdo);
	else
		hEsq = 0;

	if(no->direito != NULL)
		hDir = Altura(no->direito);
	else
		hDir = 0;
	
	if (hEsq > hDir)
		return hEsq + 1;
	else  
		return hDir + 1;
	}
}

int Arvore::Equilibrio(NoArvore* no)
{
	return Altura(no->direito) - Altura(no->esquerdo);
}
