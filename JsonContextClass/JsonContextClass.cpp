// JsonContextClass.cpp: определяет точку входа для приложения.
//

#include "JsonContextClass.h"

using namespace std;
//using namespace Context;

int main()
{
	Context::Value<int> IntVal;

	IntVal = 10;

	std::cout << IntVal << std::endl;

	return 0;
}