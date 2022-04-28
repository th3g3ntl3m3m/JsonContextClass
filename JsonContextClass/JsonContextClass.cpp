// JsonContextClass.cpp: определяет точку входа для приложения.
//

#include "JsonContextClass.h"

int main()
{
	json_tools::cContext Val;

	Val.SetInt(10);
	std::cout << "Int single Val " << Val.GetInt() << std::endl;
	std::cout << Val.IsInt() << " "
		<< Val.IsDouble() << " "
		<< Val.IsBool() << " "
		<< Val.IsTrue() << " "
		<< Val.IsFalse() << " " << std::endl;


	Val.SetDouble(.101);
	std::cout << "Double single Val " << Val.GetDouble() << std::endl;
	std::cout << Val.IsDouble() << std::endl;

	Val.SetBool(true);
	std::cout << "Bool single Val " << Val.GetBool() << std::endl;
	std::cout << Val.IsBool() << " "
		<< Val.IsTrue() << " "
		<< Val.IsFalse() << " " << std::endl;



	return 0;
}