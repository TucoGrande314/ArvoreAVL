#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
Arvore<T>::Arvore()
{
	raiz = NULL;
}

template <class T>
Arvore<T>::~Arvore()
{
    cls(raiz);
}

template <class T>
void Arvore<T>::incluir(T i)
{
	if (raiz == NULL)
		raiz = new NoArvore<T>(i);
	else
	{
		NoArvore<T>* atual = raiz;
		bool achou = false;
		while (!achou)
		{
			if (i < atual->getInfo())
				if (atual->esquerdo == NULL)
				{
					atual->esquerdo = new NoArvore<T>(i);
					achou = true;
				}
				else
					atual = atual->esquerdo;
			else
				if (i > atual->getInfo())
					if (atual->direito == NULL)
					{
						atual->direito = new NoArvore<T>(i);
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
		NoArvore<T>* no = raiz;

		while (i != no->getInfo())
		{
			Balancear(no);
			if (i < no->getInfo())
				no = no->esquerdo;
			else
			if(i > no->getInfo())
				no = no->direito;
		}
	}
}
template <class T>
void Arvore<T>::excluir(T i)
{
    if(this->raiz== NULL)
        throw "Is not possible to remove an item from an empty tree";
    else
    {
        NoArvore<T>* ant = NULL;
        NoArvore<T>* atual = raiz;
        bool achou = false;
        while(!achou)
            if(i == atual->getInfo())
            {
                if(atual == raiz)
                    raiz = excluir(atual);
                else
                {
                    if(ant->direito == atual)
                        ant->direito = excluir(atual);
                    else
                        ant->esquerdo = excluir(atual);
                }
                achou = true;
            }
            else
            {
                ant = atual;
                if(i < atual->getInfo())
                    atual = atual->esquerdo;
                else
                    atual = atual->direito;
            }

    }
    NoArvore<T>* no = raiz;
    while (no != NULL)
    {
			Balancear(no);
			if (i < no->getInfo())
				no = no->esquerdo;
			else
			if(i > no->getInfo())
				no = no->direito;
	}
}

template<class T>
NoArvore<T>* Arvore<T>::excluir(NoArvore<T>* no)
{
    NoArvore<T>* no1;
    NoArvore<T>* no2;

    if(no->esquerdo == NULL)
    {
        no2 = no->direito;
        delete no;
        return no2;
    }
    no1 = no;
    no2 = no->esquerdo;
    while(no2->direito != NULL)
    {
        no1 = no2;
        no2 = no2->direito;
    }
    if(no1 != no)
    {
        no1->direito = no2->esquerdo;
        no2->esquerdo = no->esquerdo;
    }
    no2->direito = no->direito;
    delete no;
    return no2;
}

template <class T>
void Arvore<T>::preorder()
{
	preorder(raiz);
}

template <class T>
void Arvore<T>::preorder(NoArvore<T>* no)
{
	if (no != NULL)
	{
		std::cout << no->getInfo();
		std::cout << "(";
		if (no->esquerdo != NULL)
			preorder(no->esquerdo);
		else
			std::cout << " ";
		std::cout << ",";
		if (no->direito != NULL)
			preorder(no->direito);
		else
			std::cout << " ";
		std::cout << ")";
	}
}

template <class T>
void Arvore<T>::Balancear(NoArvore<T>* no)
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

template <class T>
void Arvore<T>::rotacaoEsquerda(NoArvore<T>& raiz)
{
	NoArvore<T>* pivot = raiz.direito;
	raiz.direito = pivot->esquerdo;
	swap(raiz, *pivot);
	raiz.esquerdo = pivot;
}

template <class T>
void Arvore<T>::rotacaoDuplaEsquerda(NoArvore<T>& raiz)
{
	rotacaoDireita(*raiz.direito);
	rotacaoEsquerda(raiz);
}

template <class T>
void Arvore<T>::rotacaoDireita(NoArvore<T>& raiz)
{
	NoArvore<T>* pivot = raiz.esquerdo;
	raiz.esquerdo = pivot->direito;
	swap(raiz, *pivot);
	raiz.direito = pivot;
}

template <class T>
void Arvore<T>::rotacaoDuplaDireita(NoArvore<T>& raiz)
{
	rotacaoEsquerda(*raiz.esquerdo);
	rotacaoDireita(raiz);
}

template <class T>
int Arvore<T>::Altura(NoArvore<T>* no)
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

template <class T>
int Arvore<T>::Equilibrio(NoArvore<T>* no)
{
	return Altura(no->direito) - Altura(no->esquerdo);
}

template<class T>
void Arvore<T>::cls(NoArvore<T>* no)
{
    if(no->esquerdo != NULL)
        cls(no->esquerdo);
    if(no->direito != NULL)
        cls(no->direito);

    delete no;
}
