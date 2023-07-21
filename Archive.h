#pragma once
#include <string>
#include "TmpData.h"

class Archive {
public:
	int archiveID;
	string getPlotFlag();
	int getID();
	void setPlotFlag(string plotFlags);

	static Archive& getInstance(int archiveID);
private:
	Archive() = default;
	Archive(int archiveID);
	static Archive instances[5];
	//string archiveID;
	TmpData dataArchive;
};