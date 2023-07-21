#pragma once
#include <string>

#include "TmpData.h"

using namespace std;

class PlotController {
public:
	string plotFlag;

	string findPlot(string plotFlag);
	void setPlot(string plotFlag, string path);
	// 这里本来想用单例模式，但是出现了奇怪的Bug，先不管封装性用一下
	
	PlotController(const PlotController&) = delete;//禁用拷贝构造函数
	PlotController& operator=(const PlotController&) = delete;//禁用赋值运算符
	static PlotController& getInstance();


private:
	PlotController();
	TmpData data;
	string path;
};
