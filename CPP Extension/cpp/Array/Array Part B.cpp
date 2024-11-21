#ifndef ARRAY_PART_B_CPP
#define ARRAY_PART_B_CPP
#include "..\\..\\h\\Main.h"
#pragma once

namespace Extension {
	template <class T>
	T& Array<T>::operator[](const unsigned long index) {
		if (dataSize < index) {
			int theSize = size() + 2;
			const int* atSize = &theSize;
			T* old_data = new T[*atSize];
			for (int i = 0; i < size(); i++) {
				old_data[i] = data[i];
			}
			dataSize = index;
			delete[] data;
			data = NULL;
			data_init();
			for (int i = 0; i < theSize - 2 - 1; i++) {
				data[i] = old_data[i];
			}
			delete[] old_data;
			old_data = NULL;
		}
		if (data != NULL) {
			return data[index];
		}
	}
	template <class T>
	void Array<T>::operator=(Array& ary) {
		copy(ary);
	}
	template <class T>
	void Array<T>::operator=(Array ary) {
		copy(ary);
	}

}
#endif