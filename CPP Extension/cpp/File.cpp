#ifndef FILE_CPP
#define FILE_CPP
#pragma once
#include "..\\h\\Main.h"
namespace Extension {
	namespace Json {
		File::File() {}
		File::File(File& file) {}
		File::File(File* file) {}
		File::~File() {}
		Cache File::getCache() {
				return cache;
		}
		string File::getPath() {
				return path;
		}
		void File::setPath(string path) {
				this->path = path;
		}
		void File::copy(File& file) {
				*this = file;
		}
		void File::operator=(File& file) {
				copy(file);
		}
		bool File::isJsonFile(string path = ".json") {
			string s = "";
			bool jsonFile = false;
			for (int i = path.size(); i > 0; i--) {
				s = path.substr(path.size() - i, path.size() - (path.size() - i));
				if (s.substr(0, 1) == ".") {
					break;
				}
			}
			if (s.substr(1, s.size() - 1) == "json") {
				jsonFile = true;
			}
			return jsonFile;
		}

		bool File::isGjsonFile(string path = ".Gjson") {
			string s = "";
			bool GjsonFile = false;
			for (int i = path.size(); i > 0; i--) {
				s = path.substr(path.size() - i, path.size() - (path.size() - i));
				if (s.substr(0, 1) == ".") {
					break;
				}
			}
			if (s.substr(1, s.size() - 1) == "Gjson") {
				GjsonFile = true;
			}
			return GjsonFile;
		}
		int File::loadFile(string path = ".json") {
			this->path = path;
			if (isJsonFile(path) || isGjsonFile(path)) {
			}
			else {
				path += ".json";
			}
			ifstream file(path);
			string file_str = "";
			if (!file.is_open()) {
				//无法打开文件:
				return 1;
			}
			string line = "";
			while (getline(file, line)) {
				file_str += line + "\n";
				//输出文件的每一行
			}
			file.close(); // 关闭文件
			cache.str = file_str;
			return 0;
		}

		int File::saveFile(string path = ".json") {
			this->path = path;
			if (isJsonFile(path) || isGjsonFile(path)) {

			}
			else {
				path += ".json";
			}
			ofstream  file(path);
			if (!file.is_open()) {
				//无法打开文件:
				return 1;
			}
			file << cache.str;
			file.close(); // 关闭文件
			return 0;
		}
		void File::setCacheStr(string str) {
			cache.str = str;
		}
		void File::claerCacheStr() {
			cache.str = "";
		}
		void File::appendCacheStr(string str) {
			cache.str += str;
		}
	}
}
#endif