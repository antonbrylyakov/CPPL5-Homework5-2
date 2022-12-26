#include <iostream>
#include "table.hpp"


int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		Table<int> t(2, 3);
		t[0][0] = 4;
		std::cout << t[0][0];
	}
	catch (std::exception& e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}