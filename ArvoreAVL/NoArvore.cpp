#include "stdafx.h"
#include "NoArvore.h"


NoArvore::NoArvore()
{
	informacao = NULL;
	esquerdo = NULL;
	direito = NULL;
}

NoArvore::NoArvore(Info * i )
{
	informacao = i;
	esquerdo = NULL;
	direito = NULL;
}


NoArvore::~NoArvore()
{
}

Info * NoArvore::getInfo()
{
	return informacao;
}

void NoArvore::setInfo(Info * i)
{
	this->informacao = i;
}
