#ifndef ARRAY_PART_A_CPP
#define ARRAY_PART_A_CPP
#include "..\\..\\h\\Main.h"
#pragma once

namespace Extension {
	template <class T>
	Array<T>::Array() {
		data_init();
		updateData();
	}
	template <class T>
	Array<T>::Array(Array& ary) {
		dataSize = ary.dataSize;
		updateData();
		data_init();
		for (int index = 0; index < dataSize; index++) {
			data[index] = ary.data[index];
		}
	}
	template <class T>
	Array<T>::Array(Array* ary) {
		dataSize = ary->dataSize;
		data_init();
		updateData();
		for (int index = 0; index < dataSize; index++) {
			data[index] = ary->data[index];
		}
	}
	template <class T>
	Array<T>::~Array() {
		updateData();
	}
	template <class T>
	void Array<T>::copy(Array& ary) {
		this->dataSize = ary->dataSize;
		updateData();
		data_init();
		for (int index = 0; index < dataSize; index++) {
			data[index] = ary->data[index];
		}
	}
	template <class T>
	void Array<T>::copy(Array ary) {
		this->dataSize = ary.dataSize;
		updateData();
		data_init();
		for (int index = 0; index < dataSize; index++) {
			data[index] = ary.data[index];
		}
	}

	template <class T>
	Iterator<T>& Array<T>::begin() {
		Iterator<T> it;
		it.set(&data[0]);
		updateData();
		return it;
	}
	template <class T>
	Iterator<T>& Array<T>::end() {
		Iterator<T> it;
		it.set(&data[dataSize]);
		updateData();
		return it;
	}

	template <class T>
	ReIterator<T>& Array<T>::rbegin() {
		ReIterator<T> it;
		it.set(&data[dataSize-1]);
		updateData();
		return it;
	}
	template <class T>
	ReIterator<T>& Array<T>::rend() {
		ReIterator<T> it;
		it.set(&data[0-1]);
		updateData();
		return it;
	}

	template <class T>
	void Array<T>::swap() {
		Array<T> ary = this;
		updateData();
		for (int index = 0; index < dataSize; index++) {
			data[index] = ary.data[dataSize-index-1];
		}
	}

	template <class T>
	int Array<T>::size() {
		updateData();
		return this->dataSize;
	}
	template <class T>
	void Array<T>::push(T value) {
		int theSize = size() + 2;
		const int* atSize = &theSize;
		T* old_data = new T[*atSize];
		for (int i = 0; i < size(); i++) {
			old_data[i] = data[i];
		}
		delete[] data;
		data = NULL;
		dataSize++;
		data_init();
		for (int i = 0; i < size() - 1; i++) {
			data[i] = old_data[i];
		}
		data[size() - 1] = value;
		updateData();
	}

	template <class T>
	void Array<T>::pop() {
		int theSize = size() + 2;
		const int* atSize = &theSize;
		T* old_data = new T[*atSize];
		for (int i = 0; i < size(); i++) {
			old_data[i] = data[i];
		}
		delete[] data;
		data = NULL;
		dataSize--;
		data_init();
		for (int i = 0; i < size(); i++) {
			data[i] = old_data[i];
		}
		updateData();
	}

	template <class T>
	void Array<T>::push() {
		T value;
		push(value);
		updateData();
	}

	template <class T>
	void Array<T>::updateData() {
		if (dataSize < 0) { dataSize = 0; }
	}
	template <class T>
	void Array<T>::init() {
		dataSize = 0;
		int theSize = 2;
		const int* atSize = &theSize;
		if (data == NULL) {
			data = new T[*atSize];
		}
	}

	template <class T>
	void Array<T>::clear() {
		delete[] data;
		data = NULL;
		dataSize = 0;
	}

	template <class T>
	void Array<T>::data_init() {
		int theSize = size() + 2;
		const int* atSize = &theSize;
		if (data == NULL) {
			data = new T[*atSize];
		}
	}

	template <class T>
	void Array<T>::insert(T value, unsigned long index) {
		int theSize = size() + 2;
		const int* atSize = &theSize;
		T* old_data = new T[*atSize];
		for (int i = 0; i < size(); i++) {
			old_data[i] = data[i];
		}
		if (index > dataSize) { dataSize = index; }
		delete[] data;
		data = NULL;
		data_init();
		bool the_insert = false;
		for (int i = 0; i <= dataSize; i++) {
			if (i + 1 == index) {
				the_insert = true;
				data[i + 1] = value;
				i++;
				continue;
			}
			if (the_insert) {
				if (i < theSize) {
					data[i] = old_data[i - 1];
				}
			}
			else {
				if (i < theSize) {
					data[i] = old_data[i];
				}
			}
		}
	}

	template <class T>
	int Array<T>::find(T value) {
		for (int i = 0; i <= dataSize; i++) {
			if (data[i] == value) { return i; }
		}
		return -1;
	}
}
#endif