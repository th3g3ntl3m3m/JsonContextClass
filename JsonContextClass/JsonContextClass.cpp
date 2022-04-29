// JsonContextClass.cpp: определяет точку входа для приложения.
//

#include "JsonContextClass.h"

using namespace json_tools;

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

	std::string SS = "Hello world!";
	
	cContext ValSS(SS.c_str());
	cContext ValSSS;

	ValSSS.SetString(SS.c_str());

	std::cout << ValSS.GetString() << " " << ValSS.GetLenght() << std::endl;

	cContext ValArray;

	ValArray.SetArray();
	std::cout << ValArray.GetCode() << " " << std::endl;

	ValArray.PushBack(ValSSS);

	std::cout << "Array " << ValArray.GetElement().GetString() << std::endl;

	ValArray.ArrayClear();

	//======================================================================

	int sValInt = 0;

	for (int i = 0; i < 10; i++)
	{
		sValInt += 1;
		cContext TempVal;
		TempVal.SetInt(sValInt);
		ValArray.PushBack(TempVal);
	}

	std::cout << "Size is " << ValArray.GetArraySize() << std::endl;

	cContext ValCell;

	ValCell = ValArray.ArrayExtract();

	std::cout << ValCell.GetInt() << " " << ValArray.GetArraySize() << std::endl;

	//======================================================================



	return 0;
}