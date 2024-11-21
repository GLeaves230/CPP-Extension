#ifndef VALUE_PART_D_CPP
#define VALUE_PART_D_CPP
#pragma once
#include "..\\..\\h\\Main.h"
using namespace std;
namespace Extension {
	namespace Json {
		Value& Value::operator[](const string& key) {
			return getMap(key);
		}
		Value& Value::operator[](const int& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const double& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const long double& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const float& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const long& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const short& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const long long& key) {
			string k = to_string(key);
			return getMap(k);
		}
		Value& Value::operator[](const char& key) {
			string k = to_string(key);
			return getMap(k);
		}
		//复制数据
		void Value::operator=(const string& key) {
			set(key);
		}
		void Value::operator=(const int& key) {
			set(to_string(key));
		}
		void Value::operator=(const double& key) {
			set(to_string(key));
		}
		void Value::operator=(const long double& key) {
			set(to_string(key));
		}
		void Value::operator=(const float& key) {
			set(to_string(key));
		}
		void Value::operator=(const long& key) {
			set(to_string(key));
		}
		void Value::operator=(const short& key) {
			set(to_string(key));
		}
		void Value::operator=(const long long& key) {
			set(to_string(key));
		}
		void Value::operator=(const char& key) {
			set(to_string(key));
		}
		void Value::operator=(Value& thatValue) {
			copy(thatValue);
		}
		//对比
		bool Value::operator==(const string& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == value;
		}
		bool Value::operator==(const int& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const double& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const long double& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const float& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const long& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const short& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const long long& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(const char& value) {
			if (this->isValueArray()) {
				return false;
			}
			return this->value[0] == to_string(value);
		}
		bool Value::operator==(Value& value) {
			return compare(value);
		}
		bool Value::operator==(vector<string>& value) {
			return (this->value == value);
		}


		bool Value::operator!=(const string& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != value;
		}
		bool Value::operator!=(const int& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const double& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const long double& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const float& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const long& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const short& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const long long& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(const char& value) {
			if (this->isValueArray()) {
				return true;
			}
			return this->value[0] != to_string(value);
		}
		bool Value::operator!=(Value& value) {
			return not compare(value);
		}
		bool Value::operator!=(vector<string>& value) {
			return (this->value != value);
		}

		//加
		Value Value::operator+(const string& key) {
			Value val;
			val.copy(*this);
			val.push_back(key);
			return val;
		}
		Value Value::operator+(const int& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const double& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const long double& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const float& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const long& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const short& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const long long& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const char& key) {
			Value val;
			val.copy(*this);
			val.push_back(to_string(key));
			return val;
		}
		Value Value::operator+(const Value& thatValue) {
			Value val;
			val.copy(*this);
			for (auto it = thatValue.value.begin(); it != thatValue.value.end(); it++) {
				val.push_back(*it);
			}
			return val;
		}
		Value Value::operator+(vector<string>& thatValue) {
			Value val;
			val.copy(*this);
			for (auto it = thatValue.begin(); it != thatValue.end(); it++) {
				val.push_back(*it);
			}
			return val;
		}
		//追加
		void Value::operator+=(const string& key) {
			push_back(key);
		}
		void Value::operator+=(const int& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const double& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const long double& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const float& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const long& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const short& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const long long& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(const char& key) {
			push_back(to_string(key));
		}
		void Value::operator+=(Value& thatValue) {
			Value val = thatValue;
			for (auto it = val.value.begin(); it != val.value.end(); it++) {
				string str;
				str += it->substr(0);
				push_back(str);
			}
		}
		void Value::operator+=(vector<string>& thatValue) {
			for (auto it = thatValue.begin(); it != thatValue.end(); it++) {
				push_back(*it);
			}
			
		}

		Value& Value::operator++() {
			*this += *this;
			return *this;
		}
		const Value Value::operator++(int) {
			Value old = *this;
			++*this;
			return old;
		}
	}
}
#endif
