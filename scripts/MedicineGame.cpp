#pragma once
#include "MedicineGame.h"
#include "Medicine.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "TmpData.h"
#include "SceneInstance.h"

using namespace easy2d;
using namespace std;


InitButton::InitButton()
{
}  

InitButton::InitButton(PlayerMedicineData* player)
{
  player->HerbData.resize(8,0);

  MusicPlayer::preload("musics/PutMedicine.mp3");
  MusicPlayer::preload("musics/WaterMake.mp3");
  MusicPlayer::preload("musics/FireMake.mp3");
  MusicPlayer::preload("musics/WaterFireMake.mp3");


  float width = Window::getWidth();
  float height = Window::getHeight();
  
  auto GameNode = gcnew Node;
  auto GameScene = SceneInstance::getInstance(1).getScene();
  auto GameMenu = gcnew Menu;
  auto medicineIconMenu = gcnew Menu;
  
  GameNode->addChild(GameScene, 0);
  GameScene->addChild(GameMenu, 1);
  GameScene->addChild(medicineIconMenu, 1);
  SceneManager::enter(GameScene);
  /*
  别在这里换背景，去剧情模块换，因为每次人物不一样！
  auto BackGround02 = gcnew Sprite("images/BackGround01.png");
  GameScene->addChild(BackGround02, 0);
  */
  auto MedicineBackGround = gcnew Sprite("images/MedicineBackGround.png");
  GameScene->addChild(MedicineBackGround, 0.5);
  MedicineBackGround->setScaleX(0.51f); MedicineBackGround->setScaleY(0.51f);

  //性温                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  auto WarmBtn = gcnew Sprite("images/MedicineBtn01.png");
  WarmBtn->setPos(600, 60);
  Point pointWarmBtn = WarmBtn->getPos();
  WarmBtn->setScaleX(0.5f); WarmBtn->setScaleY(0.5f);
  GameMenu->addChild(WarmBtn, 2);
  WarmBtn->setOpacity(0.0f);
  InitButton::SetCount(player->HerbData[1], Point(pointWarmBtn.x + 80, pointWarmBtn.y + 40), GameMenu, "WarmCount");
  //性温抽屉
  auto WarmBtnDrawer = gcnew Sprite("images/Drawer.png");
  WarmBtnDrawer->setPos(pointWarmBtn);
  GameMenu->addChild(WarmBtnDrawer, 1);
  WarmBtnDrawer->setScaleX(0.4f); WarmBtnDrawer->setScaleY(0.4f);
  WarmBtnDrawer->setName("WarmBtnDrawer");
  //名字图标
  auto WarmName = gcnew Sprite("images/WarmName.png");
  WarmName->setPos(Point(pointWarmBtn.x + 75, pointWarmBtn.y+10));
  WarmName->setScaleX(0.6f); WarmName->setScaleY(0.6f);
  GameMenu->addChild(WarmName, 1);

  //性寒
  auto ColdBtn = gcnew Sprite("images/MedicineBtn01.png");
  ColdBtn->setPos(600, 140);
  Point pointColdBtn = ColdBtn->getPos();
  ColdBtn->setScaleX(0.5f); ColdBtn->setScaleY(0.5f);
  GameMenu->addChild(ColdBtn, 2);
  ColdBtn->setOpacity(0.0f);
  InitButton::SetCount(player->HerbData[2], Point(pointColdBtn.x + 80, pointColdBtn.y + 40), GameMenu, "ColdCount");
  //性寒抽屉
  auto ColdBtnDrawer = gcnew Sprite("images/Drawer.png");
  ColdBtnDrawer->setPos(pointColdBtn);
  GameMenu->addChild(ColdBtnDrawer, 1);
  ColdBtnDrawer->setScaleX(0.4f); ColdBtnDrawer->setScaleY(0.4f);
  ColdBtnDrawer->setName("ColdBtnDrawer");
  //名字图标
  auto ColdName = gcnew Sprite("images/ColdName.png");
  ColdName->setPos(Point(pointColdBtn.x + 75, pointColdBtn.y + 10));
  ColdName->setScaleX(0.6f); ColdName->setScaleY(0.6f);
  GameMenu->addChild(ColdName, 1);

  //性平
  auto SoftBtn = gcnew Sprite("images/MedicineBtn01.png");
  SoftBtn->setPos(600, 220);
  Point pointSoftBtn = SoftBtn->getPos();
  SoftBtn->setScaleX(0.5f); SoftBtn->setScaleY(0.5f);
  GameMenu->addChild(SoftBtn, 2);
  SoftBtn->setOpacity(0.0f);
  InitButton::SetCount(player->HerbData[3], Point(pointSoftBtn.x + 80, pointSoftBtn.y + 40), GameMenu, "SoftCount");
  //性平抽屉
  auto SoftBtnDrawer = gcnew Sprite("images/Drawer.png");
  SoftBtnDrawer->setPos(pointSoftBtn);
  GameMenu->addChild(SoftBtnDrawer, 1);
  SoftBtnDrawer->setScaleX(0.4f); SoftBtnDrawer->setScaleY(0.4f);
  SoftBtnDrawer->setName("SoftBtnDrawer");
  //名字图标
  auto SoftName = gcnew Sprite("images/SoftName.png");
  SoftName->setPos(Point(pointSoftBtn.x + 75, pointSoftBtn.y + 10));
  SoftName->setScaleX(0.6f); SoftName->setScaleY(0.6f);
  GameMenu->addChild(SoftName, 1);

  //味辛
  auto SpicyBtn = gcnew Sprite("images/MedicineBtn02.png");
  SpicyBtn->setPos(850, 60);
  Point pointSpicyBtn = SpicyBtn->getPos();
  SpicyBtn->setScaleX(0.5f); SpicyBtn->setScaleY(0.5f);
  GameMenu->addChild(SpicyBtn, 2);
  SpicyBtn->setOpacity(0.0f);
  InitButton::SetCount(player->HerbData[4], Point(pointSpicyBtn.x - 80, pointSpicyBtn.y + 40), GameMenu, "SpicyCount");
  //味辛抽屉
  auto SpicyBtnDrawer = gcnew Sprite("images/Drawer.png");
  SpicyBtnDrawer->setPos(pointSpicyBtn);
  GameMenu->addChild(SpicyBtnDrawer, 1);
  SpicyBtnDrawer->setScaleX(0.4f); SpicyBtnDrawer->setScaleY(0.4f);
  SpicyBtnDrawer->setName("SpicyBtnDrawer");
  //名字图标
  auto SpicyName = gcnew Sprite("images/SpicyName.png");
  SpicyName->setPos(Point(pointSpicyBtn.x - 85, pointSpicyBtn.y + 10));
  SpicyName->setScaleX(0.6f); SpicyName->setScaleY(0.6f);
  GameMenu->addChild(SpicyName, 1);

  //味苦
  auto BitterBtn = gcnew Sprite("images/MedicineBtn02.png");
  BitterBtn->setPos(850, 140);
  Point pointBitterBtn = BitterBtn->getPos();
  BitterBtn->setScaleX(0.5f); BitterBtn->setScaleY(0.5f);
  GameMenu->addChild(BitterBtn, 2);
  BitterBtn->setOpacity(0.0f);
  InitButton::SetCount(player->HerbData[5], Point(pointBitterBtn.x - 80, pointBitterBtn.y + 40), GameMenu, "BitterCount");
  //味苦抽屉
  auto BitterBtnDrawer = gcnew Sprite("images/Drawer.png");
  BitterBtnDrawer->setPos(pointBitterBtn);
  GameMenu->addChild(BitterBtnDrawer, 1);
  BitterBtnDrawer->setScaleX(0.4f); BitterBtnDrawer->setScaleY(0.4f);
  BitterBtnDrawer->setName("BitterBtnDrawer");
  //名字图标
  auto BitterName = gcnew Sprite("images/BitterName.png");
  BitterName->setPos(Point(pointBitterBtn.x - 85, pointBitterBtn.y + 10));
  BitterName->setScaleX(0.6f); BitterName->setScaleY(0.6f);
  GameMenu->addChild(BitterName, 1);

  //味甘
  auto SweetBtn = gcnew Sprite("images/MedicineBtn02.png");
  SweetBtn->setPos(850, 220);
  Point pointSweetBtn = SweetBtn->getPos();
  SweetBtn->setScaleX(0.5f); SweetBtn->setScaleY(0.5f);
  GameMenu->addChild(SweetBtn, 2);
  SweetBtn->setOpacity(0.0f);
  InitButton::SetCount(player->HerbData[6], Point(pointSweetBtn.x - 80, pointSweetBtn.y + 40), GameMenu, "SweetCount");
  //味甘抽屉
  auto SweetBtnDrawer = gcnew Sprite("images/Drawer.png");
  SweetBtnDrawer->setPos(pointSweetBtn);
  GameMenu->addChild(SweetBtnDrawer, 1);
  SweetBtnDrawer->setScaleX(0.4f); SweetBtnDrawer->setScaleY(0.4f);
  SweetBtnDrawer->setName("SweetBtnDrawer");
  //名字图标
  auto SweetName = gcnew Sprite("images/SweetName.png");
  SweetName->setPos(Point(pointSweetBtn.x - 85, pointSweetBtn.y + 10));
  SweetName->setScaleX(0.6f); SweetName->setScaleY(0.6f);
  GameMenu->addChild(SweetName, 1);


  //水制
  auto WaterBtn = gcnew Sprite("images/WaterBtn00.png");
  WaterBtn->setPos(600, 310);
  Point pointWaterBtn = WaterBtn->getPos();
  WaterBtn->setScaleX(0.5f); WaterBtn->setScaleY(0.5f);
  GameMenu->addChild(WaterBtn);
  //按过了一次的水制图标
  auto WaterBtnPressed = gcnew Sprite("images/WaterBtn01.png");
  WaterBtnPressed->setPos(pointWaterBtn);
  WaterBtnPressed->setScaleX(0.5f); WaterBtnPressed->setScaleY(0.5f);
  GameMenu->addChild(WaterBtnPressed,1);
  WaterBtnPressed->setOpacity(0.0f);

  //火制
  auto FireBtn = gcnew Sprite("images/FireBtn00.png");
  FireBtn->setPos(645, 310);
  Point pointFireBtn = FireBtn->getPos();
  FireBtn->setScaleX(0.5f); FireBtn->setScaleY(0.5f);
  GameMenu->addChild(FireBtn);
  //按过了一次的火制图标
  auto FireBtnPressed = gcnew Sprite("images/FireBtn01.png");
  FireBtnPressed->setPos(pointFireBtn);
  FireBtnPressed->setScaleX(0.5f); FireBtnPressed->setScaleY(0.5f);
  GameMenu->addChild(FireBtnPressed, 1);
  FireBtnPressed->setOpacity(0.0f);

  //重做
  auto RemakeBtn = gcnew Sprite("images/RemakeBtn.png");
  RemakeBtn->setPos(830, 320);
  RemakeBtn->setScaleX(0.7f); RemakeBtn->setScaleY(0.7f);
  GameMenu->addChild(RemakeBtn);
  //提交
  auto CommitBtn = gcnew Sprite("images/CommitBtn.png");
  CommitBtn->setPos(890, 320);
  CommitBtn->setScaleX(0.7f); CommitBtn->setScaleY(0.7f);
  GameMenu->addChild(CommitBtn);

  //钵
  auto Bowl = gcnew Sprite("images/Bowl.png");
  Bowl->setPos(695, 340);
  Bowl->setScaleX(0.4f); Bowl->setScaleY(0.4f);
  Point pointBowl = Bowl->getPos();
  GameMenu->addChild(Bowl);
  InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);

  
  //六大种草药的回调函数
 //性温
  auto callbackWarmBtn = [=](ButtonEvent evt)
  {
    // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
    TmpData data;
    data.setPath("./tmp");
    data.set("status", "0");
    // 判断事件类型是否是鼠标按下
    if (evt == ButtonEvent::Pressed)
    {
      WarmBtn->setOpacity(1.0f);
      GameMenu->removeChild(GameMenu->getChild("WarmBtnDrawer"));
      Logger::messageln("按了 %d", 123);
      auto callbackWarmBtnMoving = [=](Event* evt)
      {
        TmpData data;
        data.setPath("./tmp");
        // 判断事件类型是否移动
        if (evt->type == Event::MouseMove && data.get("status") != "1")
        {
          // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
          if (GameMenu->getChild("follow")) {
            GameMenu->removeChild(GameMenu->getChild("follow"));
          }
          Logger::messageln("难绷 %d", 123);
          // 避免药草五个后运动
          if (player->HerbData[1] > 4 || player->HerbData[0] > 9) {
            WarmBtn->removeListener("press");
            WarmBtn->removeListener("moving");
            Logger::messageln("禁用了player->HerbData[1]= %d，player->HerbData[0]= %d", player->HerbData[1], player->HerbData[0]);
          }
          else {
            Logger::messageln("移动中 %d", 123);
            Point mousePos = Input::getMousePos();
            auto WarmBtnMoved = gcnew Sprite("images/MedicineBtn01.png");
            WarmBtnMoved->setPos(mousePos.x, mousePos.y);
            WarmBtnMoved->setName("follow");
            WarmBtnMoved->setAnchor(0.5f, 0.5f);
            GameMenu->addChild(WarmBtnMoved, 3);
            WarmBtnMoved->setSize(70, 70);

            //碰撞判断
            auto box1 = WarmBtnMoved->getBoundingBox();
            auto box2 = Bowl->getBoundingBox();
            Logger::messageln("碰撞判断 %d", 123);
            if (box1.intersects(box2))
            {
              MusicPlayer::play("musics/PutMedicine.mp3");
              player->HerbData[1]++;
              player->HerbData[0]++;
              Logger::messageln("HerbData[1]= %d", player->HerbData[1]);
              GameMenu->removeChild(GameMenu->getChild("follow"));
              // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
              data.set("status", "1");
              WarmBtn->removeListener("moving");
              InitButton::SetCount(player->HerbData[1], Point(pointWarmBtn.x + 80, pointWarmBtn.y + 40), GameMenu, "WarmCount");
              InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x-10, pointBowl.y + 100), GameMenu);
              Logger::messageln("变了 %d", player->HerbData[1]);
            }
          }
        }
      };
      auto lisWarmBtnMoving = gcnew Listener(callbackWarmBtnMoving);
      lisWarmBtnMoving->setName("moving");
      WarmBtn->addListener(lisWarmBtnMoving);
    }
  };
  auto lisWarmBtn = gcnew ButtonListener(callbackWarmBtn);
  lisWarmBtn->setName("press");
  WarmBtn->addListener(lisWarmBtn);

  //性寒
  auto callbackColdBtn = [=](ButtonEvent evt)
  {
    // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
    TmpData data;
    data.setPath("./tmp");
    data.set("status", "0");
    // 判断事件类型是否是鼠标按下
    if (evt == ButtonEvent::Pressed)
    {
      ColdBtn->setOpacity(1.0f);
      GameMenu->removeChild(GameMenu->getChild("ColdBtnDrawer"));
      Logger::messageln("按了 %d", 123);
      auto callbackColdBtnMoving = [=](Event* evt)
      {
        TmpData data;
        data.setPath("./tmp");
        // 判断事件类型是否移动
        if (evt->type == Event::MouseMove && data.get("status") != "1")
        {
          // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
          if (GameMenu->getChild("follow")) {
            GameMenu->removeChild(GameMenu->getChild("follow"));
          }
          Logger::messageln("难绷 %d", 123);
          // 避免药草五个后运动
          if (player->HerbData[2] > 4 || player->HerbData[0] > 9) {
            ColdBtn->removeListener("press");
            ColdBtn->removeListener("moving");
            Logger::messageln("禁用了player->HerbData[2]= %d，player->HerbData[0]= %d", player->HerbData[2], player->HerbData[0]);
          }
          else {
            Logger::messageln("移动中 %d", 123);
            Point mousePos = Input::getMousePos();
            auto ColdBtnMoved = gcnew Sprite("images/MedicineBtn01.png");
            ColdBtnMoved->setPos(mousePos.x, mousePos.y);
            ColdBtnMoved->setName("follow");
            ColdBtnMoved->setAnchor(0.5f, 0.5f);
            GameMenu->addChild(ColdBtnMoved, 3);
            ColdBtnMoved->setSize(70, 70);

            //碰撞判断
            auto box1 = ColdBtnMoved->getBoundingBox();
            auto box2 = Bowl->getBoundingBox();
            Logger::messageln("碰撞判断 %d", 123);
            if (box1.intersects(box2))
            {
              MusicPlayer::play("musics/PutMedicine.mp3");
              player->HerbData[2]++;
              player->HerbData[0]++;
              Logger::messageln("HerbData[2]= %d", player->HerbData[2]);
              GameMenu->removeChild(GameMenu->getChild("follow"));
              // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
              data.set("status", "1");
              ColdBtn->removeListener("moving");
              InitButton::SetCount(player->HerbData[2], Point(pointColdBtn.x + 80, pointColdBtn.y + 40), GameMenu, "ColdCount");
              InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);
              Logger::messageln("变了 %d", player->HerbData[1]);
            }
          }
        }
      };
      auto lisColdBtnMoving = gcnew Listener(callbackColdBtnMoving);
      lisColdBtnMoving->setName("moving");
      ColdBtn->addListener(lisColdBtnMoving);
    }
  };
  auto lisColdBtn = gcnew ButtonListener(callbackColdBtn);
  lisColdBtn->setName("press");
  ColdBtn->addListener(lisColdBtn);

  //性平
  auto callbackSoftBtn = [=](ButtonEvent evt)
  {
    // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
    TmpData data;
    data.setPath("./tmp");
    data.set("status", "0");
    // 判断事件类型是否是鼠标按下
    if (evt == ButtonEvent::Pressed)
    {
      SoftBtn->setOpacity(1.0f);
      GameMenu->removeChild(GameMenu->getChild("SoftBtnDrawer"));
      Logger::messageln("按了 %d", 123);
      auto callbackSoftBtnMoving = [=](Event* evt)
      {
        TmpData data;
        data.setPath("./tmp");
        // 判断事件类型是否移动
        if (evt->type == Event::MouseMove && data.get("status") != "1")
        {
          // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
          if (GameMenu->getChild("follow")) {
            GameMenu->removeChild(GameMenu->getChild("follow"));
          }
          Logger::messageln("难绷 %d", 123);
          // 避免药草五个后运动
          if (player->HerbData[3] > 4 || player->HerbData[0] > 9) {
            SoftBtn->removeListener("press");
            SoftBtn->removeListener("moving");
            Logger::messageln("禁用了player->HerbData[2]= %d，player->HerbData[0]= %d", player->HerbData[2], player->HerbData[0]);
          }
          else {
            Logger::messageln("移动中 %d", 123);
            Point mousePos = Input::getMousePos();
            auto SoftBtnMoved = gcnew Sprite("images/MedicineBtn01.png");
            SoftBtnMoved->setPos(mousePos.x, mousePos.y);
            SoftBtnMoved->setName("follow");
            SoftBtnMoved->setAnchor(0.5f, 0.5f);
            GameMenu->addChild(SoftBtnMoved, 3);
            SoftBtnMoved->setSize(70, 70);

            //碰撞判断
            auto box1 = SoftBtnMoved->getBoundingBox();
            auto box2 = Bowl->getBoundingBox();
            Logger::messageln("碰撞判断 %d", 123);
            if (box1.intersects(box2))
            {
              MusicPlayer::play("musics/PutMedicine.mp3");
              player->HerbData[3]++;
              player->HerbData[0]++;
              Logger::messageln("HerbData[2]= %d", player->HerbData[2]);
              GameMenu->removeChild(GameMenu->getChild("follow"));
              // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
              data.set("status", "1");
              SoftBtn->removeListener("moving");
              InitButton::SetCount(player->HerbData[3], Point(pointSoftBtn.x + 80, pointSoftBtn.y + 40), GameMenu, "SoftCount");
              InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);
              Logger::messageln("变了 %d", player->HerbData[1]);
            }
          }
        }
      };
      auto lisSoftBtnMoving = gcnew Listener(callbackSoftBtnMoving);
      lisSoftBtnMoving->setName("moving");
      SoftBtn->addListener(lisSoftBtnMoving);
    }
  };
  auto lisSoftBtn = gcnew ButtonListener(callbackSoftBtn);
  lisSoftBtn->setName("press");
  SoftBtn->addListener(lisSoftBtn);

  //味辛
  auto callbackSpicyBtn = [=](ButtonEvent evt)
  {
    // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
    TmpData data;
    data.setPath("./tmp");
    data.set("status", "0");
    // 判断事件类型是否是鼠标按下
    if (evt == ButtonEvent::Pressed)
    {
      SpicyBtn->setOpacity(1.0f);
      GameMenu->removeChild(GameMenu->getChild("SpicyBtnDrawer"));
      Logger::messageln("按了 %d", 123);
      auto callbackSpicyBtnMoving = [=](Event* evt)
      {
        TmpData data;
        data.setPath("./tmp");
        // 判断事件类型是否移动
        if (evt->type == Event::MouseMove && data.get("status") != "1")
        {
          // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
          if (GameMenu->getChild("follow")) {
            GameMenu->removeChild(GameMenu->getChild("follow"));
          }
          Logger::messageln("难绷 %d", 123);
          // 避免药草五个后运动
          if (player->HerbData[4] > 4 || player->HerbData[0] > 9) {
            SpicyBtn->removeListener("press");
            SpicyBtn->removeListener("moving");
            Logger::messageln("禁用了player->HerbData[2]= %d，player->HerbData[0]= %d", player->HerbData[2], player->HerbData[0]);
          }
          else {
            Logger::messageln("移动中 %d", 123);
            Point mousePos = Input::getMousePos();
            auto SpicyBtnMoved = gcnew Sprite("images/MedicineBtn02.png");
            SpicyBtnMoved->setPos(mousePos.x, mousePos.y);
            SpicyBtnMoved->setName("follow");
            SpicyBtnMoved->setAnchor(0.5f, 0.5f);
            GameMenu->addChild(SpicyBtnMoved, 3);
            SpicyBtnMoved->setSize(70, 70);

            //碰撞判断
            auto box1 = SpicyBtnMoved->getBoundingBox();
            auto box2 = Bowl->getBoundingBox();
            Logger::messageln("碰撞判断 %d", 123);
            if (box1.intersects(box2))
            {
              MusicPlayer::play("musics/PutMedicine.mp3");
              player->HerbData[4]++;
              player->HerbData[0]++;
              Logger::messageln("HerbData[4]= %d", player->HerbData[2]);
              GameMenu->removeChild(GameMenu->getChild("follow"));
              // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
              data.set("status", "1");
              SpicyBtn->removeListener("moving");
              InitButton::SetCount(player->HerbData[4], Point(pointSpicyBtn.x - 80, pointSpicyBtn.y + 40), GameMenu, "SpicyCount");
              InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);
              Logger::messageln("变了 %d", player->HerbData[1]);
            }
          }
        }
      };
      auto lisSpicyBtnMoving = gcnew Listener(callbackSpicyBtnMoving);
      lisSpicyBtnMoving->setName("moving");
      SpicyBtn->addListener(lisSpicyBtnMoving);
    }
  };
  auto lisSpicyBtn = gcnew ButtonListener(callbackSpicyBtn);
  lisSpicyBtn->setName("press");
  SpicyBtn->addListener(lisSpicyBtn);

  //味苦
  auto callbackBitterBtn = [=](ButtonEvent evt)
  {
    // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
    TmpData data;
    data.setPath("./tmp");
    data.set("status", "0");
    // 判断事件类型是否是鼠标按下
    if (evt == ButtonEvent::Pressed)
    {
      BitterBtn->setOpacity(1.0f);
      GameMenu->removeChild(GameMenu->getChild("BitterBtnDrawer"));
      Logger::messageln("按了 %d", 123);
      auto callbackBitterBtnMoving = [=](Event* evt)
      {
        TmpData data;
        data.setPath("./tmp");
        // 判断事件类型是否移动
        if (evt->type == Event::MouseMove && data.get("status") != "1")
        {
          // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
          if (GameMenu->getChild("follow")) {
            GameMenu->removeChild(GameMenu->getChild("follow"));
          }
          Logger::messageln("难绷 %d", 123);
          // 避免药草五个后运动
          if (player->HerbData[5] > 4 || player->HerbData[0] > 9) {
            BitterBtn->removeListener("press");
            BitterBtn->removeListener("moving");
            Logger::messageln("禁用了player->HerbData[5]= %d，player->HerbData[0]= %d", player->HerbData[5], player->HerbData[0]);
          }
          else {
            Logger::messageln("移动中 %d", 123);
            Point mousePos = Input::getMousePos();
            auto BitterBtnMoved = gcnew Sprite("images/MedicineBtn02.png");
            BitterBtnMoved->setPos(mousePos.x, mousePos.y);
            BitterBtnMoved->setName("follow");
            BitterBtnMoved->setAnchor(0.5f, 0.5f);
            GameMenu->addChild(BitterBtnMoved, 3);
            BitterBtnMoved->setSize(70, 70);

            //碰撞判断
            auto box1 = BitterBtnMoved->getBoundingBox();
            auto box2 = Bowl->getBoundingBox();
            Logger::messageln("碰撞判断 %d", 123);
            if (box1.intersects(box2))
            {
              MusicPlayer::play("musics/PutMedicine.mp3");
              player->HerbData[5]++;
              player->HerbData[0]++;
              Logger::messageln("HerbData[5]= %d", player->HerbData[5]);
              GameMenu->removeChild(GameMenu->getChild("follow"));
              // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
              data.set("status", "1");
              BitterBtn->removeListener("moving");
              InitButton::SetCount(player->HerbData[5], Point(pointBitterBtn.x - 80, pointBitterBtn.y + 40), GameMenu, "BitterCount");
              InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);
              Logger::messageln("变了 %d", player->HerbData[5]);
            }
          }
        }
      };
      auto lisBitterBtnMoving = gcnew Listener(callbackBitterBtnMoving);
      lisBitterBtnMoving->setName("moving");
      BitterBtn->addListener(lisBitterBtnMoving);
    }
  };
  auto lisBitterBtn = gcnew ButtonListener(callbackBitterBtn);
  lisBitterBtn->setName("press");
  BitterBtn->addListener(lisBitterBtn);

  //味甘
  auto callbackSweetBtn = [=](ButtonEvent evt)
  {
    // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
    TmpData data;
    data.setPath("./tmp");
    data.set("status", "0");
    // 判断事件类型是否是鼠标按下
    if (evt == ButtonEvent::Pressed)
    {
      SweetBtn->setOpacity(1.0f);
      GameMenu->removeChild(GameMenu->getChild("SweetBtnDrawer"));
      Logger::messageln("按了 %d", 123);
      auto callbackSweetBtnMoving = [=](Event* evt)
      {
        TmpData data;
        data.setPath("./tmp");
        // 判断事件类型是否移动
        if (evt->type == Event::MouseMove && data.get("status") != "1")
        {
          // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
          if (GameMenu->getChild("follow")) {
            GameMenu->removeChild(GameMenu->getChild("follow"));
          }
          Logger::messageln("难绷 %d", 123);
          // 避免药草五个后运动
          if (player->HerbData[6] > 4 || player->HerbData[0] > 9) {
            SweetBtn->removeListener("press");
            SweetBtn->removeListener("moving");
            Logger::messageln("禁用了player->HerbData[6]= %d，player->HerbData[0]= %d", player->HerbData[6], player->HerbData[0]);
          }
          else {
            Logger::messageln("移动中 %d", 123);
            Point mousePos = Input::getMousePos();
            auto SweetBtnMoved = gcnew Sprite("images/MedicineBtn02.png");
            SweetBtnMoved->setPos(mousePos.x, mousePos.y);
            SweetBtnMoved->setName("follow");
            SweetBtnMoved->setAnchor(0.5f, 0.5f);
            GameMenu->addChild(SweetBtnMoved, 3);
            SweetBtnMoved->setSize(70, 70);

            //碰撞判断
            auto box1 = SweetBtnMoved->getBoundingBox();
            auto box2 = Bowl->getBoundingBox();
            Logger::messageln("碰撞判断 %d", 123);
            if (box1.intersects(box2))
            {
              MusicPlayer::play("musics/PutMedicine.mp3");
              player->HerbData[6]++;
              player->HerbData[0]++;
              Logger::messageln("HerbData[6]= %d", player->HerbData[6]);
              GameMenu->removeChild(GameMenu->getChild("follow"));
              // 状态0就是刚开始，为1后就是草药消失了，不执行逻辑
              data.set("status", "1");
              SweetBtn->removeListener("moving");
              InitButton::SetCount(player->HerbData[6], Point(pointSweetBtn.x - 80, pointSweetBtn.y + 40), GameMenu, "SweetCount");
              InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);
              Logger::messageln("变了 %d", player->HerbData[6]);
            }
          }
        }
      };
      auto lisSweetBtnMoving = gcnew Listener(callbackSweetBtnMoving);
      lisSweetBtnMoving->setName("moving");
      SweetBtn->addListener(lisSweetBtnMoving);
    }
  };
  auto lisSweetBtn = gcnew ButtonListener(callbackSweetBtn);
  lisSweetBtn->setName("press");
  SweetBtn->addListener(lisSweetBtn);


  medicineIcon[0] = gcnew Sprite("images/medicine00Icon.png");
  medicineIcon[0]->setPos(pointBowl.x, pointBowl.y - 20);
  medicineIcon[0]->setScaleX(0.18f); medicineIcon[0]->setScaleY(0.18f);
  medicineIconMenu->addChild(medicineIcon[0], 1);
  medicineIcon[0]->setOpacity(0.0f);

  medicineIcon[1] = gcnew Sprite("images/medicine01Icon.png");
  medicineIcon[1]->setPos(pointBowl.x, pointBowl.y - 20);
  medicineIcon[1]->setScaleX(0.18f); medicineIcon[1]->setScaleY(0.18f);
  medicineIconMenu->addChild(medicineIcon[1], 1);
  medicineIcon[1]->setOpacity(0.0f);

  vector<Sprite*> medicineIcon(10, nullptr); // 创建长度为10的指针数组，并初始化为nullptr

  for (int i = 2; i <= 33; ++i) //设置贴图
  {
    string imagePath = "images/medicine" + to_string(i) + "Icon.png";
    medicineIcon[i] = gcnew Sprite(imagePath);
  }



  //水制火制的回调函数
  auto callbackWaterBtn = [=](ButtonEvent evt)
  {
    if (evt == ButtonEvent::Clicked)
    {
      Logger::messageln("水制按了 %d", 123);
      player->Water = !player->Water;
      Logger::messageln("水制的值 %d", player->Water);
      if (player->Water)
      {
        WaterBtn->setOpacity(0.0f);
        WaterBtnPressed->setOpacity(1.0f);
      }
      else if (player->Water==0)
      {
        WaterBtn->setOpacity(1.0f);
        WaterBtnPressed->setOpacity(0.0f);
      }
    }
  };

  auto callbackFireBtn = [=](ButtonEvent evt)
  {
    if (evt == ButtonEvent::Clicked)
    {
      player->Fire = !player->Fire;
      if (player->Fire)
      {
        FireBtn->setOpacity(0.0f);
        FireBtnPressed->setOpacity(1.0f);
      }
      else if (player->Water == 0)
      {
        FireBtn->setOpacity(1.0f);
        FireBtnPressed->setOpacity(0.0f);
      }
    }
  };

  auto lisWaterBtn = gcnew ButtonListener(callbackWaterBtn);
  WaterBtn->addListener(lisWaterBtn);
  auto lisFireBtn = gcnew ButtonListener(callbackFireBtn);
  FireBtn->addListener(lisFireBtn);


  //重做提交的回调函数
  auto callbackRemakeBtn = [=](ButtonEvent evt)
  {
    if (evt == ButtonEvent::Pressed)
    {
      player->HerbData = { 0,0,0,0,0,0,0 };

      Logger::messageln("初始化player->HerbData= %d", player->HerbData);

      InitButton::SetCount(player->HerbData[1], Point(pointWarmBtn.x + 80, pointWarmBtn.y + 40), GameMenu, "WarmCount");
      InitButton::SetCount(player->HerbData[2], Point(pointColdBtn.x + 80, pointColdBtn.y + 40), GameMenu, "ColdCount");
      InitButton::SetCount(player->HerbData[3], Point(pointSoftBtn.x + 80, pointSoftBtn.y + 40), GameMenu, "SoftCount");
      InitButton::SetCount(player->HerbData[4], Point(pointSpicyBtn.x - 80, pointSpicyBtn.y + 40), GameMenu, "SpicyCount");
      InitButton::SetCount(player->HerbData[5], Point(pointBitterBtn.x - 80, pointBitterBtn.y + 40), GameMenu, "BitterCount");
      InitButton::SetCount(player->HerbData[6], Point(pointSweetBtn.x - 80, pointSweetBtn.y + 40), GameMenu, "SweetCount");

      InitButton::WarmCount(player->HerbData[1], Point(pointWarmBtn.x + 80, pointWarmBtn.y + 40), GameMenu);
      InitButton::ColdCount(player->HerbData[2], Point(pointColdBtn.x + 80, pointColdBtn.y + 40), GameMenu);
      InitButton::SoftCount(player->HerbData[3], Point(pointSoftBtn.x + 80, pointSoftBtn.y + 40), GameMenu);
      InitButton::SpicyCount(player->HerbData[4], Point(pointSpicyBtn.x - 80, pointSpicyBtn.y + 40), GameMenu);
      InitButton::BitterCount(player->HerbData[5], Point(pointBitterBtn.x - 80, pointBitterBtn.y + 40), GameMenu);
      InitButton::SweetCount(player->HerbData[6], Point(pointSweetBtn.x - 80, pointSweetBtn.y + 40), GameMenu);
      InitButton::TotalCount(player->HerbData[0], Point(pointBowl.x - 10, pointBowl.y + 100), GameMenu);

    }
  };
  auto callbackCommitBtn = [=](ButtonEvent evt)
  {
    if (evt == ButtonEvent::Clicked)
    {
      int medicineNum=player->PlayerMedicineData::Match(player->HerbData, player->Water, player->Fire);
      //音效
      if (player->Water && player->Fire)
      {
        MusicPlayer::play("musics/WaterFireMake.mp3");
      }
      else if (player->Water && player->Fire == 0)
      {
        MusicPlayer::play("musics/WaterMake.mp3");
      }
      else if (player->Water == 0 && player->Fire)
      {
        MusicPlayer::play("musics/FireMake.mp3");
      }
      Logger::messageln("判断出来是 %d", medicineNum);

      InitButton::MedicineChange(medicineNum, pointBowl, medicineIconMenu, medicineIcon[medicineNum], Bowl);

      //记得方剂图标，所有计数图标归零
    }
  };
  auto lisRemakeBtn = gcnew ButtonListener(callbackRemakeBtn);
  RemakeBtn->addListener(lisRemakeBtn);
  auto lisCommitBtn = gcnew ButtonListener(callbackCommitBtn);
  CommitBtn->addListener(lisCommitBtn);
}



// 通用函数根据给定名称删除子项
void RemoveChildByName(Menu* menu, const std::string& name)
{
  auto child = menu->getChild(name);
  if (child != nullptr)
    menu->removeChild(child);
}

//草药计数
void InitButton::SetCount(int i, Point point, Menu* GameMenu, const std::string& countPrefix)
{
  // 移除之前的计数，如果存在的话
  RemoveChildByName(GameMenu, countPrefix + std::to_string(i - 1));

  // 添加新的计数
  auto countSprite = gcnew Sprite("images/MedicineCount" + to_string(i) + ".png");
  countSprite->setPos(point);
  countSprite->setScaleX(0.6f);
  countSprite->setScaleY(0.6f);
  GameMenu->addChild(countSprite, 1);
  countSprite->setName(countPrefix + std::to_string(i));
}




//六大种草药计数


void InitButton::WarmCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0: 
  {
    auto Count00 = gcnew Sprite("images/MedicineCount00.png");
    Count00->setPos(point);
    Count00->setScaleX(0.6f); Count00->setScaleY(0.6f);
    GameMenu->addChild(Count00, 1);
    Count00->setName("WarmCount00");
  }
  break;
  case 1: 
  {
    GameMenu->removeChild(GameMenu->getChild("WarmCount00"));
    auto Count01 = gcnew Sprite("images/MedicineCount01.png");
    Count01->setPos(point);
    Count01->setScaleX(0.6f); Count01->setScaleY(0.6f);
    GameMenu->addChild(Count01, 1);
    Count01->setName("WarmCount01");
  }
  break;
  case 2:  
  {
    GameMenu->removeChild(GameMenu->getChild("WarmCount01"));
    auto Count02 = gcnew Sprite("images/MedicineCount02.png");
    Count02->setPos(point);
    Count02->setScaleX(0.6f); Count02->setScaleY(0.6f);
    GameMenu->addChild(Count02, 1);
    Count02->setName("WarmCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("WarmCount02"));
    auto Count03 = gcnew Sprite("images/MedicineCount03.png");
    Count03->setPos(point);
    Count03->setScaleX(0.6f); Count03->setScaleY(0.6f);
    GameMenu->addChild(Count03, 1);
    Count03->setName("WarmCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("WarmCount03"));
    auto Count04 = gcnew Sprite("images/MedicineCount04.png");
    Count04->setPos(point);
    Count04->setScaleX(0.6f); Count04->setScaleY(0.6f);
    GameMenu->addChild(Count04, 1);
    Count04->setName("WarmCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("WarmCount04"));
    auto Count05 = gcnew Sprite("images/MedicineCount05.png");
    Count05->setPos(point);
    Count05->setScaleX(0.6f); Count05->setScaleY(0.6f);
    GameMenu->addChild(Count05, 1);
    Count05->setName("WarmCount05");
  }
  break;
  }
}
void InitButton::ColdCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0:
  {
    auto Count00 = gcnew Sprite("images/MedicineCount00.png");
    Count00->setPos(point);
    Count00->setScaleX(0.6f); Count00->setScaleY(0.6f);
    GameMenu->addChild(Count00, 1);
    Count00->setName("ColdCount00");
  }
  break;
  case 1:
  {
    GameMenu->removeChild(GameMenu->getChild("ColdCount00"));
    auto Count01 = gcnew Sprite("images/MedicineCount01.png");
    Count01->setPos(point);
    Count01->setScaleX(0.6f); Count01->setScaleY(0.6f);
    GameMenu->addChild(Count01, 1);
    Count01->setName("ColdCount01");
  }
  break;
  case 2:
  {
    GameMenu->removeChild(GameMenu->getChild("ColdCount01"));
    auto Count02 = gcnew Sprite("images/MedicineCount02.png");
    Count02->setPos(point);
    Count02->setScaleX(0.6f); Count02->setScaleY(0.6f);
    GameMenu->addChild(Count02, 1);
    Count02->setName("ColdCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("ColdCount02"));
    auto Count03 = gcnew Sprite("images/MedicineCount03.png");
    Count03->setPos(point);
    Count03->setScaleX(0.6f); Count03->setScaleY(0.6f);
    GameMenu->addChild(Count03, 1);
    Count03->setName("ColdCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("ColdCount03"));
    auto Count04 = gcnew Sprite("images/MedicineCount04.png");
    Count04->setPos(point);
    Count04->setScaleX(0.6f); Count04->setScaleY(0.6f);
    GameMenu->addChild(Count04, 1);
    Count04->setName("ColdCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("ColdCount04"));
    auto Count05 = gcnew Sprite("images/MedicineCount05.png");
    Count05->setPos(point);
    Count05->setScaleX(0.6f); Count05->setScaleY(0.6f);
    GameMenu->addChild(Count05, 1);
    Count05->setName("ColdCount05");
  }
  break;
  }
}

void InitButton::SoftCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0:
  {
    auto Count00 = gcnew Sprite("images/MedicineCount00.png");
    Count00->setPos(point);
    Count00->setScaleX(0.6f); Count00->setScaleY(0.6f);
    GameMenu->addChild(Count00, 1);
    Count00->setName("SoftCount00");
  }
  break;
  case 1:
  {
    GameMenu->removeChild(GameMenu->getChild("SoftCount00"));
    auto Count01 = gcnew Sprite("images/MedicineCount01.png");
    Count01->setPos(point);
    Count01->setScaleX(0.6f); Count01->setScaleY(0.6f);
    GameMenu->addChild(Count01, 1);
    Count01->setName("SoftCount01");
  }
  break;
  case 2:
  {
    GameMenu->removeChild(GameMenu->getChild("SoftCount01"));
    auto Count02 = gcnew Sprite("images/MedicineCount02.png");
    Count02->setPos(point);
    Count02->setScaleX(0.6f); Count02->setScaleY(0.6f);
    GameMenu->addChild(Count02, 1);
    Count02->setName("SoftCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("SoftCount02"));
    auto Count03 = gcnew Sprite("images/MedicineCount03.png");
    Count03->setPos(point);
    Count03->setScaleX(0.6f); Count03->setScaleY(0.6f);
    GameMenu->addChild(Count03, 1);
    Count03->setName("SoftCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("SoftCount03"));
    auto Count04 = gcnew Sprite("images/MedicineCount04.png");
    Count04->setPos(point);
    Count04->setScaleX(0.6f); Count04->setScaleY(0.6f);
    GameMenu->addChild(Count04, 1);
    Count04->setName("SoftCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("SoftCount04"));
    auto Count05 = gcnew Sprite("images/MedicineCount05.png");
    Count05->setPos(point);
    Count05->setScaleX(0.6f); Count05->setScaleY(0.6f);
    GameMenu->addChild(Count05, 1);
    Count05->setName("SoftCount05");
  }
  break;
  }
}

void InitButton::SpicyCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0:
  {
    auto Count00 = gcnew Sprite("images/MedicineCount00.png");
    Count00->setPos(point);
    Count00->setScaleX(0.6f); Count00->setScaleY(0.6f);
    GameMenu->addChild(Count00, 1);
    Count00->setName("SpicyCount00");
  }
  break;
  case 1:
  {
    GameMenu->removeChild(GameMenu->getChild("SpicyCount00"));
    auto Count01 = gcnew Sprite("images/MedicineCount01.png");
    Count01->setPos(point);
    Count01->setScaleX(0.6f); Count01->setScaleY(0.6f);
    GameMenu->addChild(Count01, 1);
    Count01->setName("SpicyCount01");
  }
  break;
  case 2:
  {
    GameMenu->removeChild(GameMenu->getChild("SpicyCount01"));
    auto Count02 = gcnew Sprite("images/MedicineCount02.png");
    Count02->setPos(point);
    Count02->setScaleX(0.6f); Count02->setScaleY(0.6f);
    GameMenu->addChild(Count02, 1);
    Count02->setName("SpicyCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("SpicyCount02"));
    auto Count03 = gcnew Sprite("images/MedicineCount03.png");
    Count03->setPos(point);
    Count03->setScaleX(0.6f); Count03->setScaleY(0.6f);
    GameMenu->addChild(Count03, 1);
    Count03->setName("SpicyCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("SpicyCount03"));
    auto Count04 = gcnew Sprite("images/MedicineCount04.png");
    Count04->setPos(point);
    Count04->setScaleX(0.6f); Count04->setScaleY(0.6f);
    GameMenu->addChild(Count04, 1);
    Count04->setName("SpicyCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("SpicyCount04"));
    auto Count05 = gcnew Sprite("images/MedicineCount05.png");
    Count05->setPos(point);
    Count05->setScaleX(0.6f); Count05->setScaleY(0.6f);
    GameMenu->addChild(Count05, 1);
    Count05->setName("SpicyCount05");
  }
  break;
  }
}

void InitButton::BitterCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0:
  {
    auto Count00 = gcnew Sprite("images/MedicineCount00.png");
    Count00->setPos(point);
    Count00->setScaleX(0.6f); Count00->setScaleY(0.6f);
    GameMenu->addChild(Count00, 1);
    Count00->setName("BitterCount00");
  }
  break;
  case 1:
  {
    GameMenu->removeChild(GameMenu->getChild("BitterCount00"));
    auto Count01 = gcnew Sprite("images/MedicineCount01.png");
    Count01->setPos(point);
    Count01->setScaleX(0.6f); Count01->setScaleY(0.6f);
    GameMenu->addChild(Count01, 1);
    Count01->setName("BitterCount01");
  }
  break;
  case 2:
  {
    GameMenu->removeChild(GameMenu->getChild("BitterCount01"));
    auto Count02 = gcnew Sprite("images/MedicineCount02.png");
    Count02->setPos(point);
    Count02->setScaleX(0.6f); Count02->setScaleY(0.6f);
    GameMenu->addChild(Count02, 1);
    Count02->setName("BitterCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("BitterCount02"));
    auto Count03 = gcnew Sprite("images/MedicineCount03.png");
    Count03->setPos(point);
    Count03->setScaleX(0.6f); Count03->setScaleY(0.6f);
    GameMenu->addChild(Count03, 1);
    Count03->setName("BitterCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("BitterCount03"));
    auto Count04 = gcnew Sprite("images/MedicineCount04.png");
    Count04->setPos(point);
    Count04->setScaleX(0.6f); Count04->setScaleY(0.6f);
    GameMenu->addChild(Count04, 1);
    Count04->setName("BitterCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("BitterCount04"));
    auto Count05 = gcnew Sprite("images/MedicineCount05.png");
    Count05->setPos(point);
    Count05->setScaleX(0.6f); Count05->setScaleY(0.6f);
    GameMenu->addChild(Count05, 1);
    Count05->setName("BitterCount05");
  }
  break;
  }
}

void InitButton::SweetCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0:
  {
    auto Count00 = gcnew Sprite("images/MedicineCount00.png");
    Count00->setPos(point);
    Count00->setScaleX(0.6f); Count00->setScaleY(0.6f);
    GameMenu->addChild(Count00, 1);
    Count00->setName("SweetCount00");
  }
  break;
  case 1:
  {
    GameMenu->removeChild(GameMenu->getChild("SweetCount00"));
    auto Count01 = gcnew Sprite("images/MedicineCount01.png");
    Count01->setPos(point);
    Count01->setScaleX(0.6f); Count01->setScaleY(0.6f);
    GameMenu->addChild(Count01, 1);
    Count01->setName("SweetCount01");
  }
  break;
  case 2:
  {
    GameMenu->removeChild(GameMenu->getChild("SweetCount01"));
    auto Count02 = gcnew Sprite("images/MedicineCount02.png");
    Count02->setPos(point);
    Count02->setScaleX(0.6f); Count02->setScaleY(0.6f);
    GameMenu->addChild(Count02, 1);
    Count02->setName("SweetCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("SweetCount02"));
    auto Count03 = gcnew Sprite("images/MedicineCount03.png");
    Count03->setPos(point);
    Count03->setScaleX(0.6f); Count03->setScaleY(0.6f);
    GameMenu->addChild(Count03, 1);
    Count03->setName("SweetCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("SweetCount03"));
    auto Count04 = gcnew Sprite("images/MedicineCount04.png");
    Count04->setPos(point);
    Count04->setScaleX(0.6f); Count04->setScaleY(0.6f);
    GameMenu->addChild(Count04, 1);
    Count04->setName("SweetCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("SweetCount04"));
    auto Count05 = gcnew Sprite("images/MedicineCount05.png");
    Count05->setPos(point);
    Count05->setScaleX(0.6f); Count05->setScaleY(0.6f);
    GameMenu->addChild(Count05, 1);
    Count05->setName("SweetCount05");
  }
  break;
  }
}



//总数计数
void InitButton::TotalCount(int i, Point point, Menu* GameMenu)
{
  switch (i)
  {
  case 0:
  {
    auto TotalCount00 = gcnew Sprite("images/TotalCount00.png");
    TotalCount00->setPos(point);
    TotalCount00->setScaleX(0.55f); TotalCount00->setScaleY(0.55f);
    GameMenu->addChild(TotalCount00, 1);
    TotalCount00->setName("TotalCount00");
  }
  break;
  case 1:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount00"));
    auto TotalCount01 = gcnew Sprite("images/TotalCount01.png");
    TotalCount01->setPos(point);
    TotalCount01->setScaleX(0.55f); TotalCount01->setScaleY(0.55f);
    GameMenu->addChild(TotalCount01, 1);
    TotalCount01->setName("TotalCount01");
  }
  break;
  case 2:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount01"));
    auto TotalCount02 = gcnew Sprite("images/TotalCount02.png");
    TotalCount02->setPos(point);
    TotalCount02->setScaleX(0.55f); TotalCount02->setScaleY(0.55f);
    GameMenu->addChild(TotalCount02, 1);
    TotalCount02->setName("TotalCount02");
  }
  break;
  case 3:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount02"));
    auto TotalCount03 = gcnew Sprite("images/TotalCount03.png");
    TotalCount03->setPos(point);
    TotalCount03->setScaleX(0.55f); TotalCount03->setScaleY(0.55f);
    GameMenu->addChild(TotalCount03, 1);
    TotalCount03->setName("TotalCount03");
  }
  break;
  case 4:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount04"));
    auto TotalCount04 = gcnew Sprite("images/TotalCount04.png");
    TotalCount04->setPos(point);
    TotalCount04->setScaleX(0.55f); TotalCount04->setScaleY(0.55f);
    GameMenu->addChild(TotalCount04, 1);
    TotalCount04->setName("TotalCount04");
  }
  break;
  case 5:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount04"));
    auto TotalCount05 = gcnew Sprite("images/TotalCount05.png");
    TotalCount05->setPos(point);
    TotalCount05->setScaleX(0.55f); TotalCount05->setScaleY(0.55f);
    GameMenu->addChild(TotalCount05, 1);
    TotalCount05->setName("Count05");
  }
  break;
  case 6:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount05"));
    auto TotalCount06 = gcnew Sprite("images/TotalCount06.png");
    TotalCount06->setPos(point);
    TotalCount06->setScaleX(0.55f); TotalCount06->setScaleY(0.55f);
    GameMenu->addChild(TotalCount06, 1);
    TotalCount06->setName("TotalCount06");
  }
  break;
  case 7:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount06"));
    auto TotalCount07 = gcnew Sprite("images/TotalCount07.png");
    TotalCount07->setPos(point);
    TotalCount07->setScaleX(0.55f); TotalCount07->setScaleY(0.55f);
    GameMenu->addChild(TotalCount07, 1);
    TotalCount07->setName("TotalCount07");
  }
  break;
  case 8:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount07"));
    auto TotalCount08 = gcnew Sprite("images/TotalCount08.png");
    TotalCount08->setPos(point);
    TotalCount08->setScaleX(0.55f); TotalCount08->setScaleY(0.55f);
    GameMenu->addChild(TotalCount08, 1);
    TotalCount08->setName("TotalCount08");
  }
  break;
  case 9:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount08"));
    auto TotalCount09 = gcnew Sprite("images/TotalCount09.png");
    TotalCount09->setPos(point);
    TotalCount09->setScaleX(0.55f); TotalCount09->setScaleY(0.55f);
    GameMenu->addChild(TotalCount09, 1);
    TotalCount09->setName("TotalCount09");
  }
  break;
  case 10:
  {
    GameMenu->removeChild(GameMenu->getChild("TotalCount09"));
    auto TotalCount10 = gcnew Sprite("images/TotalCount10.png");
    TotalCount10->setPos(point);
    TotalCount10->setScaleX(0.55f); TotalCount10->setScaleY(0.55f);
    GameMenu->addChild(TotalCount10, 1);
    TotalCount10->setName("TotalCount10");
  }
  break;
  }
}


void InitButton::MedicineChange(int i, Point point, Menu* medicineIconMenu, Sprite* medicineIcon, Sprite* Bowl)
{
  Bowl->setOpacity(0.0f);

  medicineIcon->setOpacity(0.0f);

 /* medicineIcon->setPos(point.x, point.y - 20);
  medicineIcon->setScaleX(0.18f); medicineIcon->setScaleY(0.18f);
  medicineIconMenu->addChild(medicineIcon, 1);*/
}