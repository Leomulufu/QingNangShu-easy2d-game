#pragma once
#include <easy2d/easy2d.h>
#include <iostream>
#include <string>
#include <vector>

#include "StartScene.h"
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include "Medicine.h"
#include "MedicineGame.h"
#include "PlotConfig.h"
#include "SimilarSceneManager.h"

using namespace easy2d;
using namespace std;

int main() {
	/* 初始化 */
	if (Game::init())
	{
		/* 窗口设置 */
		Window::setTitle("青囊书");
		Window::setSize(960, 540);

		//剧情初始化
		 
		PlotConfig::init();

		// 存档初始化
		Archive& archive = Archive::getInstance(0);
		archive.setPlotFlag("start");

		//  配药游戏页面初始化
		// 我放到剧情模块初始化了
		//InitButton(new PlayerMedicineData);
		
		//开始界面
		StartScene::StartScene();

		/* 开始游戏 */
		Game::start();

	}

};