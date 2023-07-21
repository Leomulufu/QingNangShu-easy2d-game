#pragma once
#include <string>
#include <fstream>
using namespace std;
class RenderInterface {
public:
	virtual void render(string word, string image, string voice) = 0;
};
class PlotRender : public RenderInterface {
public:

	string word;
	fstream image;
	fstream voice;

	PlotRender();
	void render(string word, string image, string voice);
};
class PlotOptionRender : public RenderInterface {
public:

	string word;
	fstream image;
	fstream voice;

	PlotOptionRender();
	void render(string word, string image, string voice);
};