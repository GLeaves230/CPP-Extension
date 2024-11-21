#ifndef REITERATOR_H
#define REITERATOR_H
#pragma once
#include "Extension.h"
namespace Extension {
	template <class T>
	class ReIterator{
	public:
		ReIterator();
		ReIterator(ReIterator& It);
		ReIterator(ReIterator* It);
		~ReIterator();
		void set(T* obj);
		T& get();
		ReIterator& operator++();
		ReIterator operator++(int);
		ReIterator& operator--();
		ReIterator operator--(int);
		bool operator==(ReIterator it);
		bool operator!=(ReIterator it);
		void operator=(ReIterator it);
		int size();
		friend std::ostream& operator<<(std::ostream& os, ReIterator& It) {

			return os << It.get();
		}
		T* operator->();
		T& operator*();
	private:
		T* objectPtr = NULL;
		T object;
	};
}
#include "..\\cpp\\ReIterator\\ReIterator Part A.cpp"
#include "..\\cpp\\ReIterator\\ReIterator Part B.cpp"
#endif
