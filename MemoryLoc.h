#include <cstdlib>

namespace json_tools
{
	class CLocateWrapper
	{
	public:
		static const bool IsNeedFree = true;
		void* WrpMalloc(size_t Size)
		{
			if (Size)
			{
				return std::malloc(Size);
			}
			else
			{
				return NULL;
			}
		}

		void* WrpRelloc(void* SrcPtr, size_t SrcSize, size_t DestSize)
		{
			(void)SrcPtr;
			if (DestSize == 0)
			{
				std::free(SrcPtr);
				return NULL;
			}
			return std::realloc(SrcPtr, DestSize);
		}

		static void WrpFree(void* Ptr)
		{
			std::free(Ptr);
		}
	};

	template <typename Locator = CLocateWrapper>
	class PoolLocateMemory
	{
	public:

	private:

		struct CellHeader
		{
			size_t Capacity;
			size_t Size;
			CellHeader* NextCell;
		};

		CellHeader* CellHead;
		size_t CellSize;
		void* DevBuffer;
		CLocateWrapper* DefLocator;
		CLocateWrapper* OwnDefLocator;

		static const int DefCellSize = 64 * 1024;
	}
}