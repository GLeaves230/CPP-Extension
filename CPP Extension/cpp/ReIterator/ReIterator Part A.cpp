#ifndef REITERATOR_PART_A_H
#define REITERATOR_PART_A_H
#include "..\\..\\h\\Main.h"
namespace Extension {
	template <class T>
	ReIterator<T>::ReIterator() {
		this->objectPtr = nullptr;
	}
	template <class T>
	ReIterator<T>::ReIterator(ReIterator& It) {
		this->objectPtr = It.objectPtr;
	}

	template <class T>
	ReIterator<T>::ReIterator(ReIterator* It) {
		this->objectPtr = It->objectPtr;
	}
	template <class T>
	ReIterator<T>::~ReIterator() {
	}

	template <class T>
	void ReIterator<T>::set(T* objectPtr) {
		this->objectPtr = objectPtr;
		object = *objectPtr;
	}

	template <class T>
	T& ReIterator<T>::get() {
		return *objectPtr;
	}

	template <class T>
	int ReIterator<T>::size() {
		return sizeof(void*);
	}

}
#endif