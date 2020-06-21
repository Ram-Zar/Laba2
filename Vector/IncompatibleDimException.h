#pragma once
#include <iostream>
#include <exception>
#include "string.h"
#pragma warning (disable:4996)
class IncompatibleDimException :public std::exception
{
private:
    // ЛУЧШЕ ИСПОЛЬЗОВАТЬ КЛАСС std::string, ТОГДА НЕ НАДО
    // СЛЕДИТЬ ЗА РАЗМЕРОМ СООБЩЕНИЯ, А ВДРУГ ОНО ОКАЖЕТСЯ БОЛЬШЕ 40 СИМВОЛОВ?
	char Data[40]="\0";
public:
	IncompatibleDimException()
	{}
	IncompatibleDimException(const char *msg, int N, int M)
	{
		sprintf(Data, "%s%d%s%d", msg, N, " and ", M);
	}
	const char* what() const override
	{
		return Data;
	}
};
