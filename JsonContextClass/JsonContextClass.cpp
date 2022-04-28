﻿// JsonContextClass.cpp: определяет точку входа для приложения.
//

#include "JsonContextClass.h"

using namespace std;

int main()
{
	json_tools::cContext Val(1);

	Val.SetInt(10);
	std::cout << "Int single Val " << Val.GetInt() << std::endl;

	Val.SetDouble(.101);
	std::cout << "Double single Val " << Val.GetDouble() << std::endl;

	Val.SetBool(true);
	std::cout << "Bool single Val " << Val.GetBool() << std::endl;

	return 0;
}