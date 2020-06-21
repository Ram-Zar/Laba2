#pragma once
#include <exception>
#include <iostream>

class OutOfRangeException :public std::exception
{
private:
	std::string Data;
public:
	OutOfRangeException(){}
	OutOfRangeException(const char* msg, int index) 
	{
		Data.append(msg);
		Data.push_back(index);
	}
	const char* what() const override
	{
		return Data.c_str();
	}
};