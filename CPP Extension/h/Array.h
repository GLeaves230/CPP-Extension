#ifndef ARRAY_H
#define ARRAY_H
#include "Main.h"
#pragma once
namespace Extension {
	template <class T>
	class Array {
	public:
		Array();
		Array(Array& ary);
		Array(Array* ary);
		~Array();
		Iterator<T>& begin();
		Iterator<T>& end();
		ReIterator<T>& rbegin();
		ReIterator<T>& rend();
		void swap();
		int size();
		void push();
		void push(T value);
		void pop();
		void init();
		void clear();
		void copy(Array ary);
		void copy(Array& ary);
		void data_init();
		void insert(T value, unsigned long index = 0);
		int find(T value);
		T& operator[](const unsigned long index);
		void operator=(Array& ary);
		void operator=(Array ary);

	private:
		T* data = NULL;
		int dataSize = 0;
		void updateData();
	};
}
#include "..\\cpp\\Array\\Array Part A.cpp"
#include "..\\cpp\\Array\\Array Part B.cpp"
#endif
