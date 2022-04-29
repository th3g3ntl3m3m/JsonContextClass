#pragma once

#include "JsonContextClass.h"

namespace json_tools
{
    template<typename CharType>
    struct sStringRef {
        typedef CharType Ch;

        sStringRef(const CharType* str, unsigned len)
            : s(str ? str : emptyString), length(len) {
            ASSERT(str != 0 || len == 0u);
        }

        operator const Ch* () const { return s; }

        const Ch* const s;
        const unsigned length;

    private:

        static const Ch emptyString[];
    };

    template<typename CharType>
    inline sStringRef<CharType> StringRef(const CharType* str, size_t length)
    {
        return sStringRef<CharType>(str, unsigned(length));
    }
}