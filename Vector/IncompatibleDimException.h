#pragma once
#include <iostream>
#include <exception>
#include "string.h"
#pragma warning (disable:4996)
class IncompatibleDimException :public std::exception
{
private:
	char Data[40]="\0";
public:
	IncompatibleDimException()
	{}
	IncompatibleDimException(const char *msg, int N, int M)
	{
        // ЭТИ ПАРАМЕТРЫ НАДО ВКЛЮЧИТЬ В СООБЩЕНИЕ msg, КОТОРОЕ ДОЛЖНО
        // ВОЗВРАЩАТЬ ФУНЦИЯ what()
		sprintf(Data, "%s%d%s%d", msg, N, " and ", M);
	}
    // В БАЗОВОМ КЛАССЕ std::exception ЕСТЬ ВИРТУАЛЬНАЯ ФУНКЦИЯ what(),
    // НАДО ПЕРЕГРУЗИТЬ ЕЁ И ПОЛЬЗОВАТЬСЯ ВМЕСТО getInfo()
	const char* what() const override
	{
		return Data;
	}
};
