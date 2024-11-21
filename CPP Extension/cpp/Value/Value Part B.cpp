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
			strΪ���ص�json�ַ���ֵ
			lineΪ��ǰ�������µ�tabֵ��Ĭ��0+1
			sΪ����ֵ
			*/

			//jsonͷ

			/*
			�˴�Ϊ�������̣�����line���tab
			*/
			//theStrΪ��ʱ�ַ�������
			string theStr = "";
			//Ԫ��Ϊһ������������
			if (theValue.isArray()) {
				//��������
				//�����أ�Ԫ�����Ϊ1����ֻ�Ǹ���ͨjson�ļ�������[]������Ԫ��Ϊ1ʱȥ��
				if (theValue.size() > 1) {
					theStr += "[";
				}
				if (theValue.size() > 0) {
					for (auto it = theValue.begin(); it != theValue.end(); it++) {
						//valueΪ��ȡ��jsonԪ��
						Value value = it->second;
						theStr += asString(value, line + 1, true);
						//��atԪ��Ϊit++���ж��Ƿ�Ϊ����β����
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
				//�������
			}
			else if (theValue.isValueArray()){
				theStr += theValue.asValueArray();
			}
			//Ԫ��Ϊ����ֵ�������
			else if (theValue.isBool()) {
				theStr += theValue.asBool();
			}
			//Ԫ��Ϊ�����������
			else if (theValue.isInt()) {
				theStr += to_string(theValue.asInt());
			}
			//Ԫ��Ϊ����������
			else if (theValue.isFloat()) {
				theStr += to_string(theValue.asFloat());
			}
			//Ԫ�ز����ڵ������
			else if (theValue.value[0] == "") {
				theStr = "";
			}
			//Ԫ��Ϊ�ַ����������
			else if (theValue.isString()) {
				theStr += "\"" + theValue.value[0] + "\"";
			}
			//��ʼ����ַ���������������json��Ϊβ��������ӣ�����֮���
			//key������key�ַ��������
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
			//��json�ڲ���������

			//�������
			//jsonβ
			str = s;
			if (not defeat) {
				str = str.substr(1, str.size() - 1);
			}
			return str;
		}
	}
}
#endif
