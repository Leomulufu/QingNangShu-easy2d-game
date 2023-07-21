#include "SceneInstance.h"
using namespace std;
using namespace easy2d;
// 共享的全局单例变量
SceneInstance SceneInstance::instances[5];
SceneInstance::SceneInstance(int id) {
	this->id = id;
	this->scene = gcnew Scene;
};

SceneInstance& SceneInstance::getInstance(int id) {

	if (!SceneInstance::instances[id].getID()) {
		SceneInstance instance(id);
		SceneInstance::instances[id] = instance;
	}
	return 	SceneInstance::instances[id];
};

int SceneInstance::getID() {
	return this->id;
};
Scene* SceneInstance::getScene() {
	return this->scene;
};
