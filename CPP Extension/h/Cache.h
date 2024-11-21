#ifndef CACHE_H
#define CACHE_H
#pragma once
#include "Extension.h"
namespace Extension {
	namespace Json {
		class Cache {
		public:
			Value value;
			string str = "";
			Cache() {}
			Cache(Cache& cache) {}
			Cache(Cache* cache) {}
			~Cache() {}
			void copy() {
			}

			void setValue() {
				if (str != "") {
					/*
					反向解析Value
					[]包含起来的是一个Value数组
					""包含起来的是一个Value字符串
					true 和 false 是布尔值类型
					0~9是整数，0~9+.是浮点数
					{
						"data":[0,2,3,4,5,6]
					}
					*/
					Value theVal;
					return;
				}
				value = NULL;
				return;
			}

			Value& getValue() {
				return value;
			}

		private:
		};
	}
}
#endif
