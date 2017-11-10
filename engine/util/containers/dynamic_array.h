#ifndef DYNAMICARRAY_
#define DYNAMICARRAY_
#pragma once

#include "../ret/codes.h"
#include <assert.h>
////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	DynamicArray
///
/// \brief	A container for an array of elements in contiguous memory that is resizable on overflow.
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DynamicArray
{
public:
	// big four
	DynamicArray();
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);
	~DynamicArray();

	/* accesors (const and non-const) */
	// at
	T& at(size_t pos);
	const T& at(size_t pos) const;
	// [] operator
	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;
	// front
	T& front();
	// back
	const T& front() const;

	// front
	T& back();
	// back
	const T& back() const;
	
	/* state */
	// empty
	bool empty() const;
	// size
	int size() const;
	
	/* operations */
	// clear
	retcode clear();
	// push_back
	retcode push_back(const T& value);
	// pop_back
	retcode pop_back();
	// insert
	// erase


private:
	int _capacity;
	int _size;
	T* _arr;
};


#endif // !DYNAMICARRAY_

template<class T>
inline DynamicArray<T>::DynamicArray() : _capacity(0), _size(0), _arr(nullptr)
{
}

template<class T>
inline DynamicArray<T>::DynamicArray(const DynamicArray & other)
{
	this->_capacity = other._capacity;
	this->_size = other._size;
	size_t sz = this->_capacity * sizeof(T);
	this->_arr = new T[sz];
	assert(this->_arr);
	for (int iter = 0; iter < this->_size; iter++)
	{
		this->_arr[i] = other._arr[i];
	}
}

template<class T>
inline DynamicArray<T> & DynamicArray<T>::operator=(const DynamicArray & other)
{
	this->_capacity = other._capacity;
	this->_size = other._size;
	size_t sz = this->_capacity * sizeof(T);
	this->_arr = new T[sz];
	assert(this->_arr);
	for (int iter = 0; iter < this->_size; iter++)
	{
		this->_arr[i] = other._arr[i];
	}
	return *this;
}

template<class T>
inline DynamicArray<T>::~DynamicArray()
{
	if (this->_arr)
	{
		delete[] this->_arr;
	}
}

template<class T>
inline T & DynamicArray<T>::at(size_t pos)
{
	if (pos < this->_size)
	{
		assert(this->_arr);
		return this->_arr[pos];
	}
	assert(false);
	return this->_arr[0];
}

template<class T>
inline const T & DynamicArray<T>::at(size_t pos) const
{
	if (pos < this->_size)
	{
		assert(this->_arr);
		return this->_arr[pos];
	}
	assert(false);
	return this->_arr[0];
}

template<class T>
inline T & DynamicArray<T>::operator[](size_t pos)
{
	if (pos < this->_size)
	{
		assert(this->_arr);
		return this->_arr[pos];
	}
}

template<class T>
inline const T & DynamicArray<T>::operator[](size_t pos) const
{
	if (pos < this->_size)
	{
		assert(this->_arr);
		return this->_arr[pos];
	}
}

template<class T>
inline T & DynamicArray<T>::front()
{
	if (this->_size)
	{
		assert(this->_arr);
		return *this->_arr;
	}
}

template<class T>
inline const T & DynamicArray<T>::front() const
{
	if (this->_size)
	{
		assert(this->_arr);
		return *this->_arr;
	}
}

template<class T>
inline T & DynamicArray<T>::back()
{
	if (this->_size)
	{
		assert(this->_arr);
		return this->_arr[this->_size - 1];
	}
}

template<class T>
inline const T & DynamicArray<T>::back() const
{
	if (this->_size)
	{
		assert(this->_arr);
		return this->_arr[this->_size - 1];
	}
}

template<class T>
inline bool DynamicArray<T>::empty() const
{
	return this->_size == 0;
}

template<class T>
inline int DynamicArray<T>::size() const
{
	return this->_size;
}

template<class T>
inline retcode DynamicArray<T>::clear()
{
	// delete all elements
	return retcode();
}

template<class T>
inline retcode DynamicArray<T>::push_back(const T & value)
{
	if (this->_size >= this->_capacity)
	{
		// allocate array double in size
		this->_capacity = (this->_capacity) ? this->_capacity * 2 : 1; // can't double capacity if it is zero :)
		T* nArr = new T[this->_capacity];
		assert(nArr);
		// deep copy _arr to new array
		for (int iter = 0; iter < this->_size; iter++)
		{
			nArr[iter] = this->_arr[iter];
		}
		// clean up old array
		if (this->_arr)
		{
			delete[] this->_arr;
		}
		this->_arr = nArr;
	}
	assert(this->_arr);
	this->_arr[this->_size] = value;
	this->_size++;
	return retcode::success;
}

template<class T>
inline retcode DynamicArray<T>::pop_back()
{
	if (!this->_size)
	{
		return retcode::empty;
	}
	// i saw some talk that this method should also call the destructor on the object
	// that seems real smelly
	// but i can see why it might be a thing?
	this->_size--;
	return retcode::success;
}
