#include <string>
#include <iostream>
#include "TmpData.h"
#include "plotController.h"
using namespace std;

string PlotController::findPlot(string plotFlag) {
	//cout << "plotFlag: " << plotFlag << endl;
	return this->data.get(plotFlag);
}
void PlotController::setPlot(string plotFlag, string path) {
	//cout << "work: " << plotFlag << endl;
	this->data.setPath("./tmp/");
	this->data.set(plotFlag, path);
}
PlotController::PlotController() {

}
PlotController& PlotController::getInstance() {
	// 确保不同剧情控制器是单例
	static PlotController instance;
	//cout << "Instance address: " << &instance << endl; 
	// 打印对象地址
	return instance;

}
