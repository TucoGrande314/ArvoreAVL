#pragma once
#include <iostream>  
using namespace std;

class Info
{
public:
	Info();
	~Info();
	virtual int compareTo(Info*) = 0;
	virtual ostream& print(ostream&) = 0;
	//virtual ostream& operator<<(ostream&) = 0;
};