#pragma once

#include <cassert>

#define ASSERT(x) assert(x)

namespace json_tools
{
	class TmpValue
	{
	public:
		TmpValue();
		~TmpValue();

		explicit TmpValue(int i)
		{
			InternalData.Num.i.i = i;
			InternalData.Codes.Code = 1;
		}

		explicit TmpValue(double d)
		{
			InternalData.Num.dVal = d;
			InternalData.Codes.Code = 2;
		}

		explicit TmpValue(bool b)
		{
			InternalData.Codes.Code = b ? 3 : 4;
		}

		TmpValue& SetInt(int i)
		{
			this->~TmpValue();
			new (this) TmpValue(i);
			return *this;
		}

		TmpValue& SetDouble(double d)
		{
			this->~TmpValue();
			new (this) TmpValue(d);
			return *this;
		}

		TmpValue& SetBool(bool b)
		{
			this->~TmpValue();
			new (this) TmpValue(b);
			return *this;
		}

		int GetInt()
		{
			ASSERT(InternalData.Codes.Code & 1);
			return InternalData.Num.i.i;
		}

		double GetDouble()
		{
			ASSERT(InternalData.Codes.Code & 2);
			return InternalData.Num.dVal;
		}

		bool GetBool()
		{
			ASSERT(InternalData.Codes.Code & 3 || InternalData.Codes.Code & 4);
			return InternalData.Codes.Code == 3;
		}

		bool IsInt() { return (InternalData.Codes.Code & 1) != 0 };
		bool IsDouble() { return (InternalData.Codes.Code & 2) != 0 };
		bool IsBool() { return (InternalData.Codes.Code & 3 || InternalData.Codes.Code & 4) != 0 };
		bool IsTrue() { return InternalData.Codes.Code == 3 };
		bool IsFalse() { return InternalData.Codes.Code == 4 };

	private:

		struct String
		{
			unsigned int Length;
			const char* Stroke;
		};

		union Numbers
		{
			struct Int
			{
				int i;
			}i;
			struct UInt
			{
				unsigned ui;
			}ui;
			double dVal;
		};

		struct Codes
		{
			uint16_t Code;
		};

		union DataCell
		{
			String Stroke;
			Numbers Num;
			Codes Codes;
		};

		DataCell InternalData;
	};

	typedef TmpValue cContext;

	TmpValue::TmpValue()
	{
	}

	TmpValue::~TmpValue()
	{
	}
}