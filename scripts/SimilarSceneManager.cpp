#include "SimilarSceneManager.h"
#include "StartScene.h"
#include "StartScene.h"
#include <easy2d/easy2d.h>
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include <string>
#include<iostream>
#include "SimilarSceneManager.h"
void SimilarSceneManager::enter(Scene* sceneInit, SimilarSceneAction* actionClass, int action) {
    // 避免场景变化
    static auto scene = sceneInit;
	Scene* similarScene = actionClass->modify(scene, action);
	SceneManager::enter(similarScene);
};
Scene* StartSimilarScene::modify(Scene* scene, int actionID) {
    auto callbackStart = [&](ButtonEvent evt)
    {
        if (evt == ButtonEvent::Clicked)
        {
           
            // 创建剧情控制器实例
            PlotController& controller = PlotController::getInstance();
            //controller.setPlot("start", "./plot/1/1.txt");
            // 获取存档实例，这里必须使用单例模式
            Archive& archive = Archive::getInstance(0);
            string path = "";
            int flagError = 0;
            
            try {
                //cout << "start: " << archive.archiveID << endl;
                // 查找0号存档的进度对应的剧情资源路径
                path = controller.findPlot(archive.getPlotFlag());
                if ("" == path) {
                    // 输出当前存档内容
                    cout << "存档内容 " + archive.getPlotFlag() + " 存档id " + to_string(archive.getID());
                    throw "没有找到开幕剧情文件";
                }
            }
            catch (const char* msg) {
                cerr << msg << endl;
                flagError = -1;
            }
            
            if (flagError == 0) {
                // 创建剧情实例
                Plot plot;

                // 创建剧情渲染器实例
                RenderInterface* render = new PlotRender;

                // 设置剧情实例的渲染器
                plot.setRender(render);

                // 渲染剧情
                plot.render(path);
            }
        }
    };
    auto callbackButtonStatus = [&](ButtonEvent evt)
    {
        if (evt == ButtonEvent::Clicked)
        {
            SimilarSceneManager::enter(scene, this, 1);
        }
    };
    auto lisStart = gcnew ButtonListener(callbackStart);
    auto lisButtonStatus = gcnew ButtonListener(callbackButtonStatus);
    switch (actionID)
    {
      // 比如我可以把一个节点删了，替换成其他的
    case 1:
    {
      // 移除按钮1

      scene->removeChild(scene->getChild("StartBtn01"));
      // 创建一个精灵，按钮按下状态显示
      auto StartBtn02 = gcnew Sprite("images/StartBtn02.png");
      StartBtn02->setName("StartBtn02");
      StartBtn02->setScaleX(0.5f);
      StartBtn02->setScaleY(0.5f);
      StartBtn02->setPos(0, 450);
      StartBtn02->addListener(lisStart);
      scene->addChild(StartBtn02);
      break;
    }
    default:
    {
      //创建一个精灵，按钮普通状态显示
      auto StartBtn01 = gcnew Sprite("images/StartBtn01.png");
      StartBtn01->setName("StartBtn01");
      StartBtn01->setScaleX(0.5f);
      StartBtn01->setScaleY(0.5f);
      StartBtn01->setPos(0, 450);
      StartBtn01->addListener(lisButtonStatus);
      scene->addChild(StartBtn01);
      break;
    }
    }
	return scene;
}