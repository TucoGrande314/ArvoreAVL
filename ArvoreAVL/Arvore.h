#pragma once
#include "NoArvore.h"
#include "Info.h"
class Arvore
{
public:
	Arvore();
	~Arvore();
	void incluir(Info*);
	void preorder();
	void Balancear(NoArvore*);

private:
	NoArvore* raiz;
	int Altura(NoArvore*);
	int Equilibrio(NoArvore*);											
	
	void rotacaoEsquerda(NoArvore&);
	void rotacaoDuplaEsquerda(NoArvore&);		
	void rotacaoDireita(NoArvore&);				
	void rotacaoDuplaDireita(NoArvore&);
	
	void preorder(NoArvore* p, int indent = 0);
};
