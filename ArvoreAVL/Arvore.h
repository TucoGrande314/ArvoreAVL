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
	void preorder(NoArvore* p, int indent);
private:
	NoArvore* raiz;

	//------------------------------Métodos recursivos auxiliares---------------------------------------------------//
		int Altura(NoArvore*); //retorna altura de um nó (distancia entre esse nó e seu decendente mais distante)   //
		int Equilibrio(NoArvore*); //(altura do seu nó direito +1) - (altura do seu nó esquerdo +1) 	            //
	//--------------------------------------------------------------------------------------------------------------//

	//------------------------------Métodos para o balanceamento em si----------------------------------------------//
		void Balancear(NoArvore*);																					//
		void BalancearTudo(NoArvore*, Info*);
		void rotacaoEsquerda(NoArvore&);																			//
		void rotacaoDuplaEsquerda(NoArvore&);																		//
		void rotacaoDireita(NoArvore&);																				//
		void rotacaoDuplaDireita(NoArvore&);		
		//void excluir(Info*, NoArvore*);
	//--------------------------------------------------------------------------------------------------------------//
};
