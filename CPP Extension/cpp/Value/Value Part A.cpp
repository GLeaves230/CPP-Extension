#ifndef VALUE_PART_A_CPP
#define VALUE_PART_A_CPP
#pragma once
#include "..\\..\\h\\Main.h"
using namespace std;
namespace Extension {
	namespace Json {
		Value::Value() {
			value.push_back("NULL");
		}
		Value::~Value() {
		
}
		auto Value::begin() {
			auto it = Map.begin();
			return it;
		}

		auto Value::end() {
			auto it = Map.end();
			return it;
		}

		auto Value::begin(Value theValue) {
			auto it = theValue.Map.begin();
			return it;
		}

		auto Value::end(Value theValue) {
			auto it = theValue.Map.end();
			return it;
		}

		Value::Value(Value& thatValue) {
			this->key = thatValue.key;
			this->value = thatValue.value;
			if (thatValue.isArray()) {
				for (auto it = thatValue.begin(); it != thatValue.end(); it++) {
					this->Map[it->first] = it->second;
				}
			}
		}
		Value::Value(Value* thatValue) {
			this->key = thatValue->key;
			this->value = thatValue->value;
			if (thatValue->isArray()) {
				for (auto it = thatValue->begin(); it != thatValue->end(); it++) {
					this->Map[it->first] = it->second;
				}
			}
		}

		void Value::append(string key, string value) {
			Map[key].value.push_back(value);
		}

		void Value::append(string value) {
			this->value.push_back(value);
		}
		//清除函数 用于清空map
		void Value::clear() {
			if (isArray()) {
				for (auto it = begin(); it != end(); it++) {
					it->second.clear();
				}
			}
			Map.clear();
		}
		//复制函数 用于复制Value
		void Value::copy(Value& thatValue,int mode) {
			if (mode == 1) {
				key = this->key;
				value = this->value;
				this->clear();
				this->key = key;
				this->value = value;
				if (thatValue.isArray()) {
					for (auto it = thatValue.begin(); it != thatValue.end(); it++) {
						this->Map[it->first] = it->second;
					}
				}
				return;
			}
			this->clear();
			this->key = thatValue.key;
			this->value = thatValue.value;
			if (thatValue.isArray()) {
				for (auto it = thatValue.begin(); it != thatValue.end(); it++) {
					this->Map[it->first] = it->second;
				}
			}
		}
		//比较函数 对比Value是否相等
		bool Value::compare(Value& thatValue) {
			bool is = true;
			bool key = this->key == thatValue.key;
			bool value = this->value == thatValue.value;
			bool map = true;
			if (this->isArray()) {
				if (thatValue.isArray() && this->size() == thatValue.size()) {
					//如果两边同时为数组的话...
					//双向对比，获取对比完成度。
					auto at = thatValue.begin();
					auto it = this->begin();
					while (at != thatValue.end() && it != this->end()) {
						if (map) {
							map = it->second.compare(at->second);
						}
						at++;
						it++;
					}
				}
				else {
					map = false;
				}
			}
			is = key && value && map;
			return is;
		}

		Value& Value::getMap(const string& key) {
			if (key == "") {
				return *this;
			}
			Map[key].key;
			if (Map[key].base == NULL) {
				Map[key].key = key;
				Map[key].base = this;
			}
			return Map[key];
		}
		void Value::set() {
			if (not isValueArray()) {
				value[0] = "NULL";
			}
		}

		void Value::set(string key) {
			if (not isValueArray(key)) {
				if (key == "") {
					key = "NULL";
				}
				value[0] = key;
			}
			else {
				if (key == "[]") {
					value[0] = "NULL";
				}
				string s = "";
				for (int index = 1; index < key.size()-1; index++) {
					if (key.substr(index, 1) == ",") {
						goto label;
					}
					s += key.substr(index,1);
					if (index + 2 >= key.size()) {
						label:
						*this += s;
						s = "";
						continue;
					}
				}
			}
		}
		bool Value::isString() {
			if (isValueArray()) {
				return false;
			}
			return value[0] == "" || isBool() == false && isInt() == false && isFloat() == false && isArray() == false;
		}
		bool Value::isInt() {
			bool number = false;
			if (value.size() > 1) {
				return false;
			}
			for (int i = 0; i < value.size(); i++) {
				int a = 0;
				if (value[0].substr(i, 1) == "0" or
					value[0].substr(i, 1) == "1" or
					value[0].substr(i, 1) == "2" or
					value[0].substr(i, 1) == "3" or
					value[0].substr(i, 1) == "4" or
					value[0].substr(i, 1) == "5" or
					value[0].substr(i, 1) == "6" or
					value[0].substr(i, 1) == "7" or
					value[0].substr(i, 1) == "8" or
					value[0].substr(i, 1) == "9") {
					number = true;
				}
				else {
					number = false;
					break;
				}
			}
			return number;
		}
		bool Value::isFloat() {
			bool number = true;
			if (value.size() > 1) {
				return false;
			}
			int a = 0;
			for (int i = 0; i < value.size(); i++) {
				if (value[0].substr(i, 1) == "0" or
					value[0].substr(i, 1) == "1" or
					value[0].substr(i, 1) == "2" or
					value[0].substr(i, 1) == "3" or
					value[0].substr(i, 1) == "4" or
					value[0].substr(i, 1) == "5" or
					value[0].substr(i, 1) == "6" or
					value[0].substr(i, 1) == "7" or
					value[0].substr(i, 1) == "8" or
					value[0].substr(i, 1) == "9") {
					number = true;
				}
				else if (value[0].substr(i, 1) == ".") {
					number = true;
					if (a++ > 0) {
						number = false;
						break;
					}
				}
				else {
					number = false;
					break;
				}
			}
			return number;
		}
		bool Value::isBool() {
			if (value.size() > 1) {
				return false;
			}
			return value[0] == "true" || value[0] == "false";
		}

		bool Value::isArray() {
			bool is = false;
			auto it = begin();
			if (it != end()) {
				is = true;
			}
			return is;
		}
		bool Value::isArray(Value theValue) {
			bool is = false;
			auto it = theValue.begin();
			if (it != theValue.end()) {
				is = true;
			}
			return is;
		}

		bool Value::isArray(string theValue) {
			bool is = false;
			string s = theValue;
			if (s.substr(0, 1) == "[" && s.substr(s.size() - 1, 1) == "]") {
				is = true;
			}
			return is;
		}
		
		string Value::getValue(string str) {
			if (isValue(str)) {
				string theStr = data(str);
				string s = theStr.substr(2, theStr.size() - 2 - 1);
				for (int index = 0; index < s.size(); index++) {
					if (s.substr(index, 1) == ":") {
						return s.substr(index + 1);
						break;
					}
				}
			}
			return "";
		}

		int Value::asInt() {
			if (value.size() > 1) {
				return -1;
			}
			if (isInt()) {
				return stoi(value[0]);
			}
			else if (isFloat()) {
				string num;
				for (int i = 0; i < value.size(); i++) {
					if (value[0].substr(i, 1) == ".") {
						break;
					}
					num += value[0].substr(i, 1);
				}
				return stoi(num);
			}
			else {
				return NULL;
			}
		}

		float Value::asFloat() {
			if (value.size() > 1) {
				return -1;
			}
			if (isFloat()) {
				return stof(value[0]);
			}

			else {
				return NULL;
			}
		}

		string Value::asString() {
			return toStyledString();
		}

		string Value::asBool() {
			if (isBool()) {
				return value[0];
			}
			return "false";
		}
		int Value::size() {
			return Map.size();
		}

		string Value::getKey() {
			return key;
		}

		auto Value::getValue() {
			return value;
		}

		Value Value::getBase() {
			return *base;
		}

		string Value::toStyledString(int line) {
			return asString(*this, line);
		}

		string Value::data(string str) {
			string s;
			for (int index = 0; index < str.size(); index++) {
				if (str.substr(index, 1) == "\n" || str.substr(index, 1) == "\t") {
					continue;
				}
				s += str.substr(index, 1);
			}
			return s;
		}

		void Value::push_back(string str) {
			Value val;
			val = str;
			if (val.isString()) {

			}
			value.push_back(str);
		}

		void Value::pop_back() {
			value.pop_back();
		}

		string Value::asValueArray() {
			if (not isValueArray()) {
				return "NULL";
			}
			string theStr = "[";
			string s;
			for (auto it = value.begin(); it != value.end(); it++) {
				auto at = it;
				Value val;
				s = *it;
				if (isValueArray(s)) {
					theStr += asValueArray(s);
					continue;
				}
				else {
					val = s;
					if (val.isString()) {
						theStr += "\"";
					}
					theStr += s;
					if (val.isString()) {
						theStr += "\"";
					}
					at++;
					if (at != value.end()) {
						theStr += ",";
					}
				}
			}
			theStr += "]";
			return theStr;
		}

		string Value::asValueArray(string str,bool defeat) {
			if (not isValueArray(str)) {
				return "NULL";
			}
			string theStr;
			theStr = "[";
			string s;
			for (int i = 1; i < str.size()-1;i++) {
				if (str.substr(i, 1) == ",") { 
					//判断是否为字符串
					if (str.substr(i, 2) == ",,") {
						goto start1;
					}
					goto start2;
				}
				if (str.substr(i, 1) == "]") {
					//判断是否为字符串
					goto start2;
				}
				if (str.substr(i, 1) == "[") {
					//判断是否为字符串
					goto start2;
				}
				start1:
				s += str.substr(i, 1);
				start2:
				if (str.substr(i + 1, 1) == "," && str.substr(i, 2) != ",,") {
					goto label;
				}
				if (i + 2>=str.size()) {
					label:
					Value val;
					val = s;
					if (val.isString()) {
						theStr += "\"";
					}
					theStr += s;
					if (val.isString()) {
						theStr += "\"";
					}
					if (str.substr(i + 1, 1) == "," && str.substr(i - 1, 3) != "\",\"") {
						theStr += ",";
					}
					s = "";
				}
			}
			theStr += "]";
			return theStr;
		}

		bool Value::isValueArray() {
			return value.size() > 1;
		}

		bool Value::isValueArray(string str) {
			return str.substr(0, 1) == "[" && str.substr(str.size() - 1, 1) == "]";
		}
	}
}

#endif
