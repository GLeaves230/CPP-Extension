#ifndef VALUE_PART_B_CPP
#define VALUE_PART_B_CPP
#pragma once
#include "..\\..\\h\\Main.h"
using namespace std;
namespace Extension {
	namespace Json {
		string Value::asString(Value& theValue, int line, bool defeat) {
			string str = "";
			string s = "";
			string tab = "";
			for (int i = 0; i < line; i++) {
				tab += "	";
			}
			/*
			str为返回的json字符串值
			line为当前作用域下的tab值，默认0+1
			s为计算值
			*/

			//json头

			/*
			此处为解析过程，按照line填充tab
			*/
			//theStr为临时字符串计算
			string theStr = "";
			//元素为一个数组的情况：
			if (theValue.isArray()) {
				//解析数组
				//但是呢，元素如果为1，则只是个普通json文件，所以[]可以在元素为1时去掉
				if (theValue.size() > 1) {
					theStr += "[";
				}
				if (theValue.size() > 0) {
					for (auto it = theValue.begin(); it != theValue.end(); it++) {
						//value为获取的json元素
						Value value = it->second;
						theStr += asString(value, line + 1, true);
						//令at元素为it++，判断是否为数组尾部：
						auto at = it;
						at++;
						if (at != theValue.end()) {
							theStr = theStr.substr(0, theStr.size() - 1) + ",\n";
						}
					}
				}
				theStr += tab;
				if (theValue.size() > 1) {
					theStr += "]";
				}
				//解析完毕
			}
			else if (theValue.isValueArray()){
				theStr += theValue.asValueArray();
			}
			//元素为布尔值的情况：
			else if (theValue.isBool()) {
				theStr += theValue.asBool();
			}
			//元素为整数的情况：
			else if (theValue.isInt()) {
				theStr += to_string(theValue.asInt());
			}
			//元素为浮点的情况：
			else if (theValue.isFloat()) {
				theStr += to_string(theValue.asFloat());
			}
			//元素不存在的情况：
			else if (theValue.value[0] == "") {
				theStr = "";
			}
			//元素为字符串的情况：
			else if (theValue.isString()) {
				theStr += "\"" + theValue.value[0] + "\"";
			}
			//开始结合字符串：若此数据在json里为尾部，则不添加，；反之添加
			//key存在且key字符的情况：
			if (theValue.isArray()) {
				s += tab + "\"" + theValue.key + "\":" + theStr;
			}
			else if (theValue.value[0] != "") {
				if (theValue.key != "") {
					s += tab + "\"" + theValue.key + "\":" + theStr;
				}
				else {
					s += tab + theStr;
				}
			}
			else {
				s += tab + theStr;
			}
			s = "\n" + tab + "{\n" + s + "\n" + tab + "}\n";
			//本json内部解析结束

			//解析完毕
			//json尾
			str = s;
			if (not defeat) {
				str = str.substr(1, str.size() - 1);
			}
			return str;
		}
	}
}
#endif
