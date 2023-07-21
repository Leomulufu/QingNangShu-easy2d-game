#pragma once
#include <string>
#include <easy2d/easy2d.h>
using namespace std;
using namespace easy2d;

class SceneInstance {
public:
	static SceneInstance& getInstance(int number);
	int getID();
	Scene* getScene();
private:
	/*
	    0号场景是开始界面；
		1号场景是游戏及剧情页面；
	*/
	int id;
	Scene* scene;
	static SceneInstance instances[5];
	SceneInstance() = default;
	SceneInstance(int id);
};
