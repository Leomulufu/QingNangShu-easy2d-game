#include "Render.h"
#include "Plot.h"

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <iostream>
#include <vector>

using namespace std;

void Plot::setRender(RenderInterface *renderhandle) {
	this->renderHandle = renderhandle;
}

void Plot::render(string path) {
	this->renderHandle->render(plotWord(path), plotImage(path), plotVoice(path));
}

string Plot::plotWord(string path) {
	string value;
	fstream wordPlot;
	try {
		wordPlot.open(path, ios::in);
		while (!wordPlot.eof()) {
			string line = "";
			getline(wordPlot, line);
			value += line + "\n";
		}
		wordPlot.close();
	}catch (exception) {
		throw exception("没找到文字资源");
	}
	return value;
}

string Plot::plotImage(string path) {
	string image = "";
	
	string name;
	fstream wordPlot;
	string line = "";
	try {
		wordPlot.open(path, ios::in);
		getline(wordPlot, line);
		//std::cout << "具体内容 " + line << std::endl;
	}
	catch (exception) {
		throw exception("没找到文字资源");
	}

	// 匹配说话的人，注意这里是中文引号
	std::regex pattern("/?([^/]+)：");
	std::smatch match1;
	if (std::regex_search(line, match1, pattern)) {
		std::cout << match1[1] << std::endl;
		if ("" != match1[1].str()) {
			image = "images/" + match1[1].str() + ".png";
		}else {
			// 如果没有人物开头对话，就认为是默认场景
			image = "images/ClassBackGround.png";
		}
	}
	try {
		std::ifstream file(image);
		if (!file.good()) {
			throw exception("没找到图片资源");
		}
	}
	catch(exception){
		image = "images/ClassBackGround.png";
	}
	std::cout << image << std::endl;
	return image;
}
string Plot::plotVoice(string path) {
	string voice = "./musics/Speak.mp3";
	return voice;
}
