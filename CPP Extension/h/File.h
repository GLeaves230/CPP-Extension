#ifndef FILE_H
#define FILE_H
#pragma once
#include "Extension.h"
namespace Extension {
	namespace Json {
		class File {
		public:
			File();
			File(File& file);
			File(File* file);
			~File();
			Cache getCache();
			string getPath();
			void setPath(string path);
			void copy(File& file);
			void operator=(File& file);
			bool isJsonFile(string path);
			bool isGjsonFile(string path);
			int loadFile(string path);
			int saveFile(string path);
			void setCacheStr(string str);
			void claerCacheStr();
			void appendCacheStr(string str);
		private:
			Cache cache;
			string path;
		};
	}
}
#include "..\\cpp\\File.cpp"
#endif