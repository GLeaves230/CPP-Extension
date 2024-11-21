#ifndef VALUE_H
#define VALUE_H
#include "Extension.h"

using namespace std;
namespace Extension {
	namespace Json {
		class Value {
		public:
			Value();
			Value(Value& thatValue);
			Value(Value* thatValue);
			~Value();
			string data(string str);
			int size();
			auto begin();
			auto end();
			auto begin(Value theValue);
			auto end(Value theValue);
			void append(string key, string value);
			void append(string value);
			//清除函数 用于清空map
			void clear();
			//复制函数 用于复制Value
			void copy(Value& thatValue,int mode = 0);
			//比较函数 对比Value是否相等
			bool compare(Value& thatValue);

			Value& getMap(const string& key);
			void set();
			void set(string key);

			Value& operator[](const string& key);
			Value& operator[](const int& key);
			Value& operator[](const double& key);
			Value& operator[](const long double& key);
			Value& operator[](const float& key);
			Value& operator[](const long& key);
			Value& operator[](const short& key);
			Value& operator[](const long long& key);
			Value& operator[](const char& key);
			//复制数据
			void operator=(const string& key);
			void operator=(const int& key);
			void operator=(const double& key);
			void operator=(const long double& key);
			void operator=(const float& key);
			void operator=(const long& key);
			void operator=(const short& key);
			void operator=(const long long& key);
			void operator=(const char& key);
			void operator=(Value& thatValue);
			void operator=(vector<string>& thatValue);
			//加
			Value operator+(const string& key);
			Value operator+(const int& key);
			Value operator+(const double& key);
			Value operator+(const long double& key);
			Value operator+(const float& key);
			Value operator+(const long& key);
			Value operator+(const short& key);
			Value operator+(const long long& key);
			Value operator+(const char& key);
			Value operator+(const Value& thatValue);
			Value operator+(vector<string>& thatValue);
			//追加
			void operator+=(const string& key);
			void operator+=(const int& key);
			void operator+=(const double& key);
			void operator+=(const long double& key);
			void operator+=(const float& key);
			void operator+=(const long& key);
			void operator+=(const short& key);
			void operator+=(const long long& key);
			void operator+=(const char& key);
			void operator+=(Value& thatValue);
			void operator+=(vector<string>& thatValue);
			//自增
			Value& operator++();
			const Value operator++(int);
			//对比
			bool operator==(const string& value);
			bool operator==(const int& value);
			bool operator==(const double& value);
			bool operator==(const long double& value);
			bool operator==(const float& value);
			bool operator==(const long& value);
			bool operator==(const short& value);
			bool operator==(const long long& value);
			bool operator==(const char& value);
			bool operator==(Value& value);
			bool operator==(vector<string>& value);

			bool operator!=(const string& value);
			bool operator!=(const int& value);
			bool operator!=(const double& value);
			bool operator!=(const long double& value);
			bool operator!=(const float& value);
			bool operator!=(const long& value);
			bool operator!=(const short& value);
			bool operator!=(const long long& value);
			bool operator!=(const char& value);
			bool operator!=(Value& value);
			bool operator!=(vector<string>& value);

			friend std::ostream& operator<<(std::ostream& os, Value& val) {
				os << val.asString();
				return os;
			}

			friend std::istream& operator>>(std::istream& is, Value& val) {
				Value a;
				a.copy(val);
				is >> a;
				return is;
			}

			bool isString();
			bool isInt();
			bool isFloat();
			bool isBool();

			bool isArray();
			bool isArray(Value theValue);
			bool isArray(string theValue);
			int asInt();

			float asFloat();

			string asString();

			string asBool();

			string getKey();

			string asValueArray();
			string asValueArray(string str,bool defeat = false);

			bool isValueArray();
			bool isValueArray(string str);

			auto getValue();

			Value getBase();

			string toStyledString(int line = 0);

			string asString(Value& theValue, int line = 0, bool defeat = false);
			
			Value asValue(string str,bool deafet = false);

			Value asValue();

			string getValue(string str);

			bool isValue();

			bool isValue(string str);

			void push_back(string str);

			void pop_back();
			
		private:
			map<string, Value> Map;
			vector<string> value;
			string key = "data";
			Value* base = NULL;
		};
	}
}

#include "..\\cpp\\Value\\Value Part A.cpp"
#include "..\\cpp\\Value\\Value Part B.cpp"
#include "..\\cpp\\Value\\Value Part C.cpp"
#include "..\\cpp\\Value\\Value Part D.cpp"
#endif
