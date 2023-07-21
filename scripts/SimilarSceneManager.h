#pragma once
#include <easy2d/easy2d.h>
#include <string>
using namespace std;
using namespace easy2d;
class SimilarSceneAction {
public:
    virtual Scene* modify(Scene* scene, int action) = 0;
};

class StartSimilarScene : public SimilarSceneAction {
public:
    Scene* modify(Scene* scene, int action);
};
class SimilarSceneManager {
public:
    void static enter(Scene* scene, SimilarSceneAction* actionClass, int action);
};
