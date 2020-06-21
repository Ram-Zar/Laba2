#pragma once
#include <iostream>
#include <exception>
#include <cstring>
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
		Data.append(msg);
		Data.push_back(N);
		Data.append(" and ");
		Data.push_back(M);
			
	}

	const char* what() const
	{
		return Data.c_str();
	}
};
