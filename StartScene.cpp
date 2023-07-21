#include "StartScene.h"
#include <easy2d/easy2d.h>
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include "SimilarSceneManager.h"
#include <string>
#include<iostream>
#include "SimilarSceneManager.h"
#include "SceneInstance.h"

using namespace easy2d;
using namespace std;


StartScene::StartScene() {
      auto StartScene = SceneInstance::getInstance(0).getScene();
      auto StartMenu = gcnew Menu;


      // 先不进入场景
      // SceneManager::enter(StartScene);
      //bgm
      MusicPlayer::preload("musics/StartGame.mp3");
      MusicPlayer::play("musics/StartGame.mp3");
      
     

      auto BackGround01 = gcnew Sprite("images/BackGround01.png");
      auto profile01 = gcnew Sprite("images/profile01.png");
 
      StartScene->addChild(BackGround01);
      BackGround01->setScaleX(0.52f); BackGround01->setScaleY(0.52f);
      StartScene->addChild(StartMenu,1);
      

      // 找到你的小修改的地方
      // 把你的小小修改写在 StartSimilarScene里，或者其他继承的类
      StartSimilarScene* actionClass = new StartSimilarScene;
      // 这里的0会触发deafult，随便写的
      SimilarSceneManager::enter(StartScene, actionClass, 0);
      // 在回调函数里，变成case 1
      
      
      //创建一个精灵，按钮普通状态显示
      auto StartBtn01 = gcnew Sprite("images/StartBtn01.png"); 
      StartBtn01->setScaleX(0.5f); 
      StartBtn01->setScaleY(0.5f);
      StartBtn01->setPos(0, 450);
      StartMenu->addChild(StartBtn01);
      // 创建一个精灵，按钮按下状态显示
      auto StartBtn02 = gcnew Sprite("images/StartBtn02.png");
      

      //继续游戏按钮
      auto ResumeBtn = gcnew Sprite("images/ResumeBtn01.png");
      StartMenu->addChild(ResumeBtn);
      ResumeBtn->setScaleX(0.5f); ResumeBtn->setScaleY(0.5f);
      ResumeBtn->setPos(192, 450);

      //游戏设置按钮
      auto SetBtn = gcnew Sprite("images/SetBtn01.png");
      StartMenu->addChild(SetBtn);
      SetBtn->setScaleX(0.5f); SetBtn->setScaleY(0.5f);
      SetBtn->setPos(384, 450);

      //制作人员按钮
      auto StaffBtn = gcnew Sprite("images/StaffBtn01.png");
      StartMenu->addChild(StaffBtn);
      StaffBtn->setScaleX(0.5f); StaffBtn->setScaleY(0.5f);
      StaffBtn->setPos(576, 450);

      //退出游戏按钮
      auto ExitBtn = gcnew Sprite("images/ExitBtn01.png");
      StartMenu->addChild(ExitBtn);
      ExitBtn->setScaleX(0.5f); ExitBtn->setScaleY(0.5f);
      ExitBtn->setPos(768, 450);
      
      //auto callbackStart = [](ButtonEvent evt)
      //{
      //    if (evt == ButtonEvent::Clicked)
      //    {

      //        // 创建剧情控制器实例
      //        PlotController& controller = PlotController::getInstance();
      //        //controller.setPlot("start", "./plot/1/1.txt");
      //        // 获取存档实例，这里必须使用单例模式
      //        Archive& archive = Archive::getInstance("0");
      //        archive.setPlotFlag("start");
      //        string path = "";
      //        int flagError = 0;
      //        try {
      //            //cout << "start: " << archive.archiveID << endl;
      //            // 查找0号存档的进度对应的剧情资源路径
      //            path = controller.findPlot(archive.getPlotFlag());
      //            if ("" == path) {
      //                throw "没有找到开幕剧情文件";
      //            }
      //        }
      //        catch (const char* msg) {
      //            cerr << msg << endl;
      //            flagError = -1;
      //        }
      //        if (flagError == 0) {
      //            // 创建剧情实例
      //            Plot plot;

      //            // 创建剧情渲染器实例
      //            RenderInterface* render = new PlotRender;

      //            // 设置剧情实例的渲染器
      //            plot.setRender(render);

      //            // 渲染剧情
      //            plot.render(path);
      //        }
      //    }
      //};
      
      auto callbackContinue = [](ButtonEvent evt)
      {
          if (evt == ButtonEvent::Clicked)
          {

              // 创建剧情控制器实例
              PlotController& controller = PlotController::getInstance();

              // 获取存档实例，这里必须使用单例模式
              Archive& archive = Archive::getInstance(0);
              string path = "";
              int flagError = 0;
              try {
                  // 查找0号存档的进度对应的剧情资源路径
                  path = controller.findPlot(archive.getPlotFlag());
                  if ("" == path) {
                      throw "没有找到存档的进度";
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
      auto callbackQuit = [](ButtonEvent evt)
      {
          if (evt == ButtonEvent::Clicked)
          {
              Game::quit();
          }
      };

      //auto lisStart = gcnew ButtonListener(callbackStart);
      auto lisQuit = gcnew ButtonListener(callbackQuit);
      auto lisContinue = gcnew ButtonListener(callbackContinue);

    
      //StartBtn01->addListener(lisStart);
      ExitBtn->addListener(lisQuit);
      ResumeBtn->addListener(lisContinue);
    }

