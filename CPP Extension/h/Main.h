#ifndef MAIN_H
#define MAIN_H
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <map> 
#include <cctype>
#include <algorithm>
#include "Extension.h"
using namespace std;
namespace Extension {
	template <class T>
	class Iterator;
	template <class T>
	class ReIterator;
	template <class T>
	class Array;
	namespace Json {
		class Value;
		class File;
		class Cache;
	}
}
#include "Value.h"
#include "Cache.h"
#include "File.h"
#include "Array.h"
#include "Iterator.h"
#include "ReIterator.h"
#endif
