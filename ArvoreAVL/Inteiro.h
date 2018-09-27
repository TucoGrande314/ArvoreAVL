#pragma once
#include "Info.h"
#include <iostream>  
using namespace std;
class Inteiro : public Info
{
public:
	Inteiro();
	Inteiro(int);
	~Inteiro();
	int compareTo(Info*) override;
	ostream& print(ostream&);
	int getInt();
	void setInt(int);
private:
	int inteiro;
};