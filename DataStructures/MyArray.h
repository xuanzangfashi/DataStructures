#pragma once
#include <stdlib.h>
template <class T>
class MyArray
{
private:
	T* data;
	int count;
	int size;
public:
	MyArray<T>(int stackSize)
	{
		this->data = (T*)malloc(stackSize * sizeof(T));
		size = stackSize;
		count = 0;
	}
public:
	int Add(const T& element);
	int IndexOf(const T element);
	int Remove(const T element);
	int RemoveAt(int index);
	T ReplaceAt(int index, T& element);
	int Insert(int index, const T& element);
public:
	const int GetCount();
	const T* GetCppArray();

public:
	const T operator[](int index)
	{
		return data[index];
	}
protected:

};

template <class T>
const T* MyArray<T>::GetCppArray()
{
	return data;
}

template <class T>
const int MyArray<T>::GetCount()
{
	return count;
}

template <class T>
int MyArray<T>::Insert(int index, const T& element)
{
	this->data = (T*)realloc(this->data, (count + 1) * sizeof(T));
	for (int i = count; i >= index; i--)
	{
		this->data[i + 1] = this->data[i];
	}
	this->data[i] = element;
	count++;
	return count;
}

template <class T>
T MyArray<T>::ReplaceAt(int index, T& element)
{
	T tmp = this->data[index];
	this->data[index] = element;
	return tmp;
}

template <class T>
int MyArray<T>::IndexOf(const T element)
{
	for (int i = 0; i < count; i++)
	{
		if (this->data[i] == element)
		{
			return i;
		}
	}
}

template <class T>
int MyArray<T>::RemoveAt(int index)
{
	for (int i = index; i < count; i++)
	{
		this->data[i] = this->data[i + 1];
	}

	this->data = (T*)realloc(this->data, (count - 1) * sizeof(T));
	return count--;
}

template <class T>
int MyArray<T>::Remove(const T element)
{
	int index = IndexOf(element);
	return RemoveAt(index);
}

template <class T>
int MyArray<T>::Add(const T& element)
{
	if (count < size)
	{
		this->data[count] = element;
	}
	else
	{
		this->data = (T*)realloc(this->data, (count + 1) * sizeof(T));
		this->data[count] = element;
		size++;
	}
	count++;
	return count - 1;
}

