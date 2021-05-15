#ifndef LIBTABLES_H
#define LIBTABLES_H
#include <iomanip>
#include <iostream>
#include "libErrors.h"


/*
Delete duplicates existing in array
@param arr - delete duplicates in this array
@param size - size of an array
@return new size of an array 
*/
int DeleteDuplicates(long long* arr, int size);

/*
Show contents of array
@param arr - show contents of this array
@param size - size of this array
*/
template <class T> void ShowArray(T* arr, int size, int spacing = 2) {
	for (int i = 0; i < size; i++)
		std::cout << std::setw(spacing) << arr[i] << std::setw(spacing) << " ";
	std::cout << std::endl;
}

template <class T> void ShowArray(T** arr, int rows, int cols, int spacing = 2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			std::cout << std::setw(spacing) << arr[i][j] << std::setw(spacing) << " ";
		std::cout << std::endl;
	}
}

/*
Function creates dynamic array of wanted type
@param size size
@return array of wanted type
*/
template <class T> T* CreateArray(int size){
	T* arr = nullptr;
	try {
		arr = new T[size];
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}

	return arr;
}
/*
Function creates 2D dynamic array of wanted type
@param rows number of rows
@param cols number of columns
@return 2D array of wanted type
*/
template <class T> T** CreateArray(int rows, int cols) {
	//pointer to created table
	T** createdArray;
	try {
		createdArray = new T * [rows];
		for (T i = 0; i < rows; i++)
			try {
			createdArray[i] = new T[cols];

		}
		catch (std::bad_alloc) {
			throw EXCEPTION_CODE::allocationError;
			return nullptr;
		}
		//return array if memory allocation was succesful 
		return createdArray;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
	return nullptr;

}
/*
Function deletes array
@param arr array that will be deleted
*/
template <class T> void DeleteArray(T* arr) {
	try {
		delete[]arr;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
};

/*
Function deletes two dimensional array
@param arr array that will be deleted
@param rowCount number of rows of the array that will be deleted
*/
template <class T> void DeleteArray(T** arr, int rowCount) {
	try {
		for (int i = 0; i < rowCount; i++)
			delete[]arr[i];
		delete[]arr;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
};

/*
Copy array values
@param arr1 - copy to this array
@param arr2 - copy from this array
@param size - size of arrays
*/
template <class T> void CopyArray(T* arr1, T* arr2, int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = arr2[i];
	}
}

/*
Reverse values in array 
@param arr - flip this array
@param size - size of an array
*/
template <class T> void FlipArray(T* arr, int size) {
	T* temp = CreateArray<T>(size);
	CopyArray(temp, arr, size);
	for (int i = 0; i < size; i++) {
		arr[i] = temp[size - i - 1];
	}
}

template <class T> void SetDefaultValues(T** arr, T value, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		memset(arr[i], value, sizeof(T) * cols);
}

#endif // !LIBTABLES_H
