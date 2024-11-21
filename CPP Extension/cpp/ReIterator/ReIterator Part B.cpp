#ifndef REITERATOR_PART_B_CPP
#define REITERATOR_PART_B_CPP
#include "..\\..\\h\\Main.h"
namespace Extension {
	template <class T>
	ReIterator<T> ReIterator<T>::operator++(int) {
		ReIterator<T> old = *this;
		objectPtr--;
		object = *objectPtr;
		return old;
	}
	template <class T>
	ReIterator<T>& ReIterator<T>::operator++() {
		objectPtr--;
		object = *objectPtr;
		return *this;
		
	}
	template <class T>
	ReIterator<T> ReIterator<T>::operator--(int) {
		ReIterator<T> old = *this;
		objectPtr++;
		object = *objectPtr;
		return old;
	}
	template <class T>
	ReIterator<T>& ReIterator<T>::operator--() {
		objectPtr++;
		object = *objectPtr;
		return *this;
	}
	template <class T>
	T* ReIterator<T>::operator->() {
		return this->objectPtr;
	}

	template <class T>
	T& ReIterator<T>::operator*() {
		return object;
	}

	template <class T>
	bool ReIterator<T>::operator==(ReIterator It) {
		return this->objectPtr == It.objectPtr;
	}

	template <class T>
	bool ReIterator<T>::operator!=(ReIterator It) {
		return this->objectPtr != It.objectPtr;
	}

	template <class T>
	void ReIterator<T>::operator=(ReIterator It) {
		this->objectPtr = It.objectPtr;
	}

}
#endif