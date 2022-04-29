# CMakeList.txt: проект CMake для JsonContextClass; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (JsonContextClass "JsonContextClass.cpp" "JsonContextClass.h"  "сValue.h"  "cContext.h" "sStringRef.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
