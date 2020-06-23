#pragma once
#include <iostream>
#include <exception>
#include <cstring>

#pragma warning (disable:4996)
class IncompatibleDimException :public std::exception
{
private:
    // ЛУЧШЕ ИСПОЛЬЗОВАТЬ КЛАСС std::string, ТОГДА НЕ НАДО
    // СЛЕДИТЬ ЗА РАЗМЕРОМ СООБЩЕНИЯ, А ВДРУГ ОНО ОКАЖЕТСЯ БОЛЬШЕ 40 СИМВОЛОВ?
	std::string Data;
public:
	IncompatibleDimException()
	{}
	IncompatibleDimException(const char *msg, int N, int M)
	{
		char buff[10];
		Data.append(msg);
		Data + itoa(N, buff, 10) + " and ";
		Data + itoa(M, buff, 10);			
	}

	const char* what() const
	{
		return Data.c_str();
	}
};
