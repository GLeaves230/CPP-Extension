#ifndef VALUE_PART_C_CPP
#define VALUE_PART_C_CPP
#pragma once
#include "..\\..\\h\\Main.h"
using namespace std;
namespace Extension {
	namespace Json {

		bool Value::isValue() {
			return true;
		}

		bool Value::isValue(string str) {
			string s = data(str);
			if (s.substr(0, 1) == "{" && s.substr(s.size() - 1, 1) == "}"){
				return true;
			}
			return false;
		}

		Value Value::asValue() {
			Value val;
			val.asValue(this->asString());
			this->copy(val);
			return val;
		}

		Value Value::asValue(string str, bool deafet) {
			Value val;
			return val;
		}
	}
}
#endif
