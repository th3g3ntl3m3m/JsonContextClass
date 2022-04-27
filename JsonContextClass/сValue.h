#pragma once

namespace Context
{
	template<class T>
	class Value
	{
	public:
		Value();
		~Value();

		Value<T>& operator= (T val);

		template<class T>
		friend std::ostream& operator<< (std::ostream& out, const Value<T>& val);

	private:
		T data;
	};

	#include "cValue.inl"
}