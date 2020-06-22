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
		Data.append(msg);
		sprintf(const_cast<char*>(Data.c_str() + Data.length()), "%d",index);
	}
	const char* what() const override
	{
		return Data.c_str();
	}
};