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
					�������Value
					[]������������һ��Value����
					""������������һ��Value�ַ���
					true �� false �ǲ���ֵ����
					0~9��������0~9+.�Ǹ�����
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
