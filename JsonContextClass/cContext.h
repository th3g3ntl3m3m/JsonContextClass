#pragma once

#include "JsonContextClass.h"

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

		/*TmpValue(const char* s, size_t len)
		{
			StringRef(s, len);
		}*/

		explicit TmpValue(const char* str)
		{
			InternalData.Stroke.Stroke = str;
			InternalData.Stroke.Length = static_cast<int>(strlen(str));
			InternalData.Codes.Code = 5;
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

		TmpValue& SetString(const char* str)
		{
			this->~TmpValue();
			new (this) TmpValue(str);
			return *this;
		}

		TmpValue& SetArray()
		{
			this->~TmpValue();
			new (this) TmpValue();
			this->InternalData.Codes.Code = 6;
			return *this;
		}

		int GetInt()
		{
			ASSERT(IsInt());
			return InternalData.Num.i.i;
		}

		double GetDouble()
		{
			ASSERT(IsDouble());
			return InternalData.Num.dVal;
		}

		bool GetBool()
		{
			ASSERT(IsBool());
			return InternalData.Codes.Code == 3;
		}

		const char* GetString()
		{
			ASSERT(IsString());
			return InternalData.Stroke.Stroke;
		}

		int GetLenght()
		{
			ASSERT(IsString());
			return InternalData.Stroke.Length;
		}

		int GetCode()
		{
			return InternalData.Codes.Code;
		}

		TmpValue GetElement()
		{
			ASSERT(IsArray() && (InternalData.Array.Elements.size() >= 1));
			return InternalData.Array.Elements.back();
		}

		void PushBack(TmpValue Val)
		{
			ASSERT(IsArray());
			InternalData.Array.Elements.push_back(Val);
		}

		int GetArraySize()
		{
			ASSERT(IsArray());
			return static_cast<int>(InternalData.Array.Elements.size());
		}

		void ArrayClear()
		{
			ASSERT(IsArray());
			InternalData.Array.Elements.clear();
			SetArray();
		}

		TmpValue ArrayExtract()
		{
			TmpValue Val = InternalData.Array.Elements.back();
			InternalData.Array.Elements.pop_back();
			return Val;
		}

		bool IsInt() { return (InternalData.Codes.Code & 1) != 0; }
		bool IsDouble() { return (InternalData.Codes.Code & 2) != 0; }
		bool IsBool() { return (InternalData.Codes.Code == 3 || InternalData.Codes.Code == 4); }
		bool IsTrue() { return InternalData.Codes.Code == 3; }
		bool IsFalse() { return InternalData.Codes.Code == 4; }
		bool IsString() { return InternalData.Codes.Code == 5; }
		bool IsArray() { return InternalData.Codes.Code == 6; }

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

		struct ArrayData
		{
			int Size;
			std::vector<TmpValue> Elements;
		};

		typedef struct _DataCell
		{
			String Stroke;
			Numbers Num;
			Codes Codes;
			ArrayData Array;
		} DataCell, * pDataCell;

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