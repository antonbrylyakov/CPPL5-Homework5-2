#pragma once
#include <stdexcept>

struct Size
{
	size_t width;
	size_t height;
};

template <typename T>
class Table
{
public:
	Table(size_t width, size_t height) : m_size{ .width = width, .height = height }
	{
		m_values = new T * [m_size.height];
		for (auto i = 0; i < m_size.height; ++i)
		{
			m_values[i] = new T[m_size.width];
		}
	}

	Table(const Size& size) : Table(size.width, size.height)
	{

	}

	// для простоты задачи запрещаем копирование
	Table(const Table&&) = delete;
	Table& operator=(const Table&) = delete;

	~Table()
	{
		for (auto i = 0; i < m_size.height; i++)
		{
			delete[] m_values[i];
		}

		delete[] m_values;
	}

	// не возвращаем как ссылку T*&, т.к. не планируем присваивать целые строки таблицы
	T* operator[] (size_t y)
	{
		checkY(y);
		return m_values[y];
	}

	const T* operator[](size_t y) const
	{
		checkY(y);
		return m_values[y];
	}

private:
	Size m_size;
	T** m_values;
	void checkY(size_t y)
	{
		if (y > m_size.height)
		{
			throw std::out_of_range("Индекс строки таблицы вне диапазона");
		}
	}
};
