#pragma once
#include <string>

class PlotInterface {
public:
	virtual void setRender(RenderInterface *renderHandle) = 0;
	virtual void render(string path) = 0;
private:
	virtual string plotWord(string path) = 0;
	virtual string plotImage(string path) = 0;
	virtual string plotVoice(string path) = 0;

};
class Plot : public PlotInterface {
public:
	void setRender(RenderInterface *renderHandle);
	void render(string path);
private:
	RenderInterface* renderHandle;
	string word;
	fstream image;
	fstream voice;

	string plotWord(string path);
	string plotImage(string path);
	string plotVoice(string path);

};
