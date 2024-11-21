#ifndef ITERATOR_PART_A_H
#define ITERATOR_PART_A_H
#include "..\\..\\h\\Main.h"
namespace Extension {
	template <class T>
	Iterator<T>::Iterator() {
		this->objectPtr = nullptr;
	}
	template <class T>
	Iterator<T>::Iterator(Iterator& It) {
		this->objectPtr = It.objectPtr;
	}

	template <class T>
	Iterator<T>::Iterator(Iterator* It) {
		this->objectPtr = It->objectPtr;
	}
	template <class T>
	Iterator<T>::~Iterator() {
	}

	template <class T>
	void Iterator<T>::set(T* objectPtr) {
		this->objectPtr = objectPtr;
		object = *objectPtr;
	}

	template <class T>
	T& Iterator<T>::get() {
		return *objectPtr;
	}

	template <class T>
	int Iterator<T>::size() {
		return sizeof(void*);
	}
	
}
#endif