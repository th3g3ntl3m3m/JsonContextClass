// JsonContextClass.cpp: определяет точку входа для приложения.
//

#include "JsonContextClass.h"

using namespace std;

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

	Val.SetBool(true);
	std::cout << "Bool single Val " << Val.GetBool() << std::endl;



	return 0;
}