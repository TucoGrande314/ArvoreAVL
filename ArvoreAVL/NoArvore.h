#pragma once
#include "Info.h"
class NoArvore
{
public:
	NoArvore();
	NoArvore(Info*);
	~NoArvore();
	
	NoArvore * esquerdo;
	NoArvore * direito;
	
	Info * getInfo();
	void setInfo(Info*);

private:
	Info * informacao;
};

