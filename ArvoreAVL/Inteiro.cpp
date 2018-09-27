#include "stdafx.h"
#include "Inteiro.h"


Inteiro::Inteiro()
{
}

Inteiro::Inteiro(int i)
{
	this->inteiro = i;
}


Inteiro::~Inteiro()
{
}

int Inteiro::compareTo(Info* i)
{
	return (this->inteiro - (((Inteiro*)(i))->inteiro));
}

ostream & Inteiro::print(ostream & os)
{
	os << inteiro << "\n";
	return os; 
}

int Inteiro::getInt()
{
	return inteiro;
}

void Inteiro::setInt(int i)
{
	this->inteiro = i;
}