#pragma once
#include <exception>
#include <iostream>
#pragma warning (disable:4996)
class OutOfRangeException :public std::exception
{
private:
	std::string Data;
public:
	OutOfRangeException(){}
	OutOfRangeException(const char* msg, int index) 
	{
<<<<<<< HEAD
		char buff[10];
		Data +msg+ itoa(index, buff, 10);
=======
		Data.append(msg);
        // ТАК ДЕЛАТЬ ОПАСНО
        // В ВЫРАЖЕНИИ Data.c_str() + Data.length() ТЫ ПЕРЕМЕЩАЕШЬ
        // УКАЗАТЕЛЬ НА КОНЕЦ СТРОКИ И ПОТОМ ЕЩЁ ЧТО ТО ТУДА ДОПИСЫВАЕШЬ,
        // НО ДЕЛО В ТОМ, ЧТО ОПЕРАЦИЯ ЗАПИСИ ПРОИЗВОДИТСЯ НЕ В КЛАССЕ
        // std::string, ПОЭТОМУ ЕСЛИ РАНЕЕ ВЫДЕЛЕННОЙ ПОД СТРОКУ ПАМЯТИ
        // НЕ ХВАТИТ, ТО НИКТО ЭТУ ПАМЯТЬ НЕ РАСШИРИТ И ПОВЕДЕНИЕ ПРОГРАММЫ
        // СТАНЕТ НЕОПРЕДЕЛЁННЫМ
        // САМЫЙ ПРОСТОЙ СПОСОБ СДЕЛАТЬ ТО, ЧТО ТЫ ХОЧЕШЬ - ОБЫЧНАЯ
        // КОНКАТЕНАЦИЯ СТРОК std::string:
        // Data = msg + std::to_string(index);
		sprintf(const_cast<char*>(Data.c_str() + Data.length()), "%d",index);
>>>>>>> 2c98a7d8a6e985caa10d4ae3a5c1921d226e0767
	}
	const char* what() const override
	{
		return Data.c_str();
	}
};
