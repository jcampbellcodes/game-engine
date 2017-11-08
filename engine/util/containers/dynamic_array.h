#ifndef DYNAMICARRAY_
#define DYNAMICARRAY_
#pragma once

enum class retcode;

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
inline DynamicArray<T>::DynamicArray()
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
}

template<class T>
inline T & DynamicArray<T>::at(size_t pos)
{
	// TODO: insert return statement here
}

template<class T>
inline const T & DynamicArray<T>::at(size_t pos) const
{
	// TODO: insert return statement here
}

template<class T>
inline T & DynamicArray<T>::operator[](size_t pos)
{
	// TODO: insert return statement here
}

template<class T>
inline const T & DynamicArray<T>::operator[](size_t pos) const
{
	// TODO: insert return statement here
}

template<class T>
inline T & DynamicArray<T>::front()
{
	// TODO: insert return statement here
}

template<class T>
inline const T & DynamicArray<T>::front() const
{
	// TODO: insert return statement here
}

template<class T>
inline bool DynamicArray<T>::empty() const
{
	return false;
}

template<class T>
inline int DynamicArray<T>::size() const
{
	return 0;
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
