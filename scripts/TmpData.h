#pragma once
#include <string>

using namespace std;

class TmpData {
public:
	TmpData();
	void setPath(string savePath);
	void set(string key, string value);
	string get(string key);

private:

	string savePath;

};