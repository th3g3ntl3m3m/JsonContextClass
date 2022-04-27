#pragma once

namespace Context
{
	class Value
	{
	public:
		Value();
		~Value();

		Value& operator= (int val);
		friend std::ostream& operator<< (std::ostream& out, const Value& val);

	private:
		int data;
	};
}

#include "cValue.inl"