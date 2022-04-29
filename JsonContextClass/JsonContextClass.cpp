// JsonContextClass.cpp: определяет точку входа для приложения.
//

#include "JsonContextClass.h"

using namespace json_tools;

#define SIMPLE_DEMO 0

int main()
{
#if SIMPLE_DEMO
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
#else
	/*
	* Let's try to create a structure based on json
	* 
	* Json example:
	* 
	*	{
	*		"int_val": 1,
	*		"double_val": 0.01,
	*		"bool_val": false,
	*		"string_val": "Val in object!",
	*		"array_val": [
	*			1,
	*			0.1,
	*			false,
	*			"Val in object",
	*			{
	*				"int_val": 1,
	*				"double_val": 0.01,
	*				"bool_val": false,
	*				"string_val": "Val in object!",
	*				"array_val": [1,2,3,4,5,6,7,8,9,10]
	*			}
	*		]
	*	}
	* 
	*/

	cContext GlobalObj;

	cContext ScalarType;
	cContext LocArray;
	cContext LocObj;

	GlobalObj.SetObject();

	ScalarType.SetInt(1);
	GlobalObj.AddMember("int_val", ScalarType);
	ScalarType.SetDouble(0.01);
	GlobalObj.AddMember("double_val", ScalarType);
	ScalarType.SetBool(false);
	GlobalObj.AddMember("bool_val", ScalarType);
	ScalarType.SetString("Val in object!");
	GlobalObj.AddMember("string_val", ScalarType);

	LocArray.SetArray();

	ScalarType.SetInt(1);
	LocArray.PushBack(ScalarType);
	ScalarType.SetDouble(0.01);
	LocArray.PushBack(ScalarType);
	ScalarType.SetBool(false);
	LocArray.PushBack(ScalarType);
	ScalarType.SetString("Val in object!");
	LocArray.PushBack(ScalarType);

	LocObj.SetObject();
	
	ScalarType.SetInt(1);
	LocObj.AddMember("int_val", ScalarType);
	ScalarType.SetDouble(0.01);
	LocObj.AddMember("double_val", ScalarType);
	ScalarType.SetBool(false);
	LocObj.AddMember("bool_val", ScalarType);
	ScalarType.SetString("Val in object!");
	LocObj.AddMember("string_val", ScalarType);
	
	cContext LocArrayLvlObj;

	LocArrayLvlObj.SetArray();
	
	int ValInt = 0;

	for (int i = 0; i < 11; i++)
	{
		ScalarType.SetInt(ValInt);
		LocArrayLvlObj.PushBack(ScalarType);
		ValInt += 1;
	}

	LocObj.AddMember("array_val", LocArrayLvlObj);

	LocArray.PushBack(LocObj);

	GlobalObj.AddMember("array_val", LocArray);
#endif
	return 0;
}