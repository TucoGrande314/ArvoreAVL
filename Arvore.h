#ifndef ARVORE_H
#define ARVORE_H
#include "NoArvore.h"

template <class T>
class Arvore
{
public:
	Arvore();
	~Arvore();
	void incluir(T);
	void excluir(T);
	void preorder();
	void Balancear(NoArvore<T>*);

private:
	NoArvore<T>* raiz;
	int Altura(NoArvore<T>*);
	int Equilibrio(NoArvore<T>*);
    void cls(NoArvore<T>*);

	void rotacaoEsquerda(NoArvore<T>&);
	void rotacaoDuplaEsquerda(NoArvore<T>&);
	void rotacaoDireita(NoArvore<T>&);
	void rotacaoDuplaDireita(NoArvore<T>&);

    NoArvore<T>* excluir(NoArvore<T>*);
	void preorder(NoArvore<T>* p);
};

#include "Arvore.inl"
#endif // ARVORE_H
