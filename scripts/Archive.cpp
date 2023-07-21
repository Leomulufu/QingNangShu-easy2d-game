#include "Archive.h"
#include <iostream>

using namespace std;

Archive Archive::instances[5];

string Archive::getPlotFlag() {
	//cout << "id: "+ to_string(this->archiveID) + "return " + this->dataArchive.get(to_string(this->archiveID)) << endl;
	this->dataArchive.setPath("./archive/");
	return this->dataArchive.get(to_string(this->archiveID));
}
int Archive::getID()
{
	return this->archiveID;
}
void Archive::setPlotFlag(string plotFlags) {
	this->dataArchive.setPath("./archive/");
	this->dataArchive.set(to_string(this->archiveID), plotFlags);
}
Archive::Archive(int archiveID) {
	this->archiveID = archiveID;
}
Archive& Archive::getInstance(int id){
	// 确保不同存档各自是单例
	if (!Archive::instances[id].getID()) {
		Archive instance(id);
		Archive::instances[id] = instance;
	}
	return 	Archive::instances[id];

}
