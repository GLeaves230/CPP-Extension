#ifndef ITERATOR_H
#define ITERATOR_H
#pragma once
#include "Extension.h"
namespace Extension {
	template <class T>
	class Iterator {
	public:
		Iterator();
		Iterator(Iterator& It);
		Iterator(Iterator* It);
		~Iterator();
		void set(T* obj);
		T& get();
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		bool operator==(Iterator it);
		bool operator!=(Iterator it);
		void operator=(Iterator it);
		int size();
		friend std::ostream& operator<<(std::ostream& os, Iterator& It) {

			return os << It.get();
		}
		T* operator->();
		T& operator*();
	private:
		T* objectPtr = NULL;
		T object;
	};
}
#include "..\\cpp\\Iterator\\Iterator Part A.cpp"
#include "..\\cpp\\Iterator\\Iterator Part B.cpp"
#endif
