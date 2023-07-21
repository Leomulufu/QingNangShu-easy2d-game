#include "TmpData.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void TmpData::set(string key, string value) {
	ofstream tmp;
	tmp.open(savePath + key + ".txt", ios::out);
	tmp << value;
	tmp.close();
}

string TmpData::get(string key) {
	string value;
	ifstream tmp;
	tmp.open(savePath + key + ".txt", ios::in);
	tmp >> value;
	tmp.close();
	//cout << "savepath: " << this->savePath << endl;
	return value;
}
void TmpData::setPath(string savePath) {
	this->savePath = savePath;
	//cout << "setSavepath: " << this->savePath << endl;
}
TmpData::TmpData() {

}