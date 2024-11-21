#ifndef ITERATOR_PART_B_H
#define ITERATOR_PART_B_H
#include "..\\..\\h\\Main.h"
namespace Extension {
	template <class T>
	Iterator<T> Iterator<T>::operator++(int) {
		Iterator<T> old = *this;
		objectPtr++;
		object = *objectPtr;
		return old;
	}
	template <class T>
	Iterator<T>& Iterator<T>::operator++() {
		objectPtr++;
		object = *objectPtr;
		return *this;
		
	}
	template <class T>
	Iterator<T> Iterator<T>::operator--(int) {
		Iterator<T> old = *this;
		objectPtr--;
		object = *objectPtr;
		return old;
	}
	template <class T>
	Iterator<T>& Iterator<T>::operator--() {
		objectPtr--;
		object = *objectPtr;
		return *this;
	}
	template <class T>
	T* Iterator<T>::operator->() {
		return this->objectPtr;
	}

	template <class T>
	T& Iterator<T>::operator*() {
		return object;
	}

	template <class T>
	bool Iterator<T>::operator==(Iterator It) {
		return this->objectPtr ==It.objectPtr;
	}

	template <class T>
	bool Iterator<T>::operator!=(Iterator It) {
		return this->objectPtr != It.objectPtr;
	}

	template <class T>
	void Iterator<T>::operator=(Iterator It) {
		this->objectPtr = It.objectPtr;
	}

}
#endif