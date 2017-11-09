#ifndef DYNAMICARRAY_
#define DYNAMICARRAY_
#pragma once

enum class retcode;
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
inline DynamicArray<T>::DynamicArray(const DynamicArray &)
{
}

template<class T>
inline DynamicArray & DynamicArray<T>::operator=(const DynamicArray &)
{
	// TODO: insert return statement here
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
}

template<class T>
inline const T & DynamicArray<T>::at(size_t pos) const
{
	if (pos < this->_size)
	{
		assert(this->_arr);
		return this->_arr[pos];
	}
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
	return retcode();
}

template<class T>
inline retcode DynamicArray<T>::push_back(const T & value)
{
	return retcode();
}

template<class T>
inline retcode DynamicArray<T>::pop_back()
{
	return retcode();
}
