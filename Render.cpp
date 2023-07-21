#include <easy2d/easy2d.h>
#include <string>
#include<iostream>

#include "Render.h"
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include "SceneInstance.h"
#include "Medicine.h"
#include "MedicineGame.h"

using namespace easy2d;
using namespace std;

PlotRender::PlotRender() {
    // 初始化页面
    /*
    auto scene = new Scene;
    SceneManager::enter(scene);
    auto text = new Text("青囊书");
    scene->addChild(text);
   */
    // 游戏模块初始化 
    auto static game = InitButton(new PlayerMedicineData);
}

void PlotRender::render(string word, string image, string voice) {
    // 剧情页面渲染
    auto scene = SceneInstance::getInstance(1).getScene();
    //auto scene = gcnew Scene;
    SceneManager::enter(scene);
    auto imagePlot = gcnew Sprite(image);
    auto wordPlot = new Text(word);
    imagePlot->setName("plot");
    wordPlot->setName("plot");
    wordPlot->setPos(40,370);
    // 开启自动换行,设置文字自动换行的宽度
    wordPlot->setWrapping(true); 
    wordPlot->setWrappingWidth(500);
    // 创建文字绘图样式
    DrawingStyle style;
    style.fillColor = Color(50, 52, 46);         // 文字填充色
    style.strokeColor = Color::Black;       // 文字描边色
    style.strokeWidth = 1.1;                // 文字描边宽度

    // 设置绘图样式
    wordPlot->setDrawingStyle(style);
    //文本框
    auto TextBox = gcnew Sprite("images/TextBox.png");
    scene->addChild(TextBox,1);
    TextBox->setScale(0.51f, 0.51f);
    TextBox->setPos(-10, -10);
    //大背景
    auto BackGround = gcnew Sprite("images/ClassBackGround.png");
    BackGround->setScale(0.8f, 0.8f);
    scene->addChild(BackGround, -1);
    
    scene->addChild(imagePlot,0);
    imagePlot->setScale(0.15f, 0.15f); 
    imagePlot->setPos(-20, 0);
    scene->addChild(wordPlot,2);
    auto music = MusicPlayer::preload(voice);
    // 判断指针是否为空
    if (music)
    {
        // 播放音乐
        music->play();
    }
    auto callback = [=](Event* evt)
    {
        // 递归条件，让玩家可以一直看剧情
        // 在文字区域点击触发
        if (evt->type == Event::MouseDown && wordPlot->containsPoint(Input::getMousePos()))
        {
            // 创建剧情控制器实例
            PlotController& controller = PlotController::getInstance();

            // 获取存档实例，这里必须使用单例模式
            Archive& archive = Archive::getInstance(0);
            // 将当前进度改变存入0号存档
            archive.setPlotFlag(archive.getPlotFlag() + "1");
            string path = "";
            int flagError = 0;
            try{
                // 查找0号存档的进度对应的剧情资源路径
                path = controller.findPlot(archive.getPlotFlag());
                if ("" == path) {
                    // 输出当前存档内容
                    cout << "存档内容 " + archive.getPlotFlag() + " 存档id " + to_string(archive.getID());
                    throw "没有找到剧情进度";
                }
            }
            catch (const char* msg) {
                cout << msg << endl;
                flagError = -1;
            }
            if (flagError == 0) {
                // 创建剧情实例
                Plot plot;
                if (path == "option") {
                    // 创建剧情选项渲染器实例
                    RenderInterface* render = new PlotOptionRender;
                    plot.setRender(render);
                }
                else {
                    // 剧情渲染器实例
                    RenderInterface* render = new PlotRender;
                    plot.setRender(render);
                }
                // 初始化场景
                scene->removeChildren("plot");
                // 渲染剧情
                plot.render(path);
            }

        }
    };
    auto lis = gcnew Listener(callback);
    //imagePlot->addListener(lis);
    // 文字被点击
    wordPlot->addListener(lis);
}
PlotOptionRender::PlotOptionRender() {
    // 初始化页面
    /*
    auto scene = new Scene;
    SceneManager::enter(scene);
    auto text = new Text("青囊书");
    scene->addChild(text);
    */
}

void PlotOptionRender::render(string word, string image, string voice) {
    // 剧情选项渲染
    auto scene = SceneInstance::getInstance(1).getScene();
    SceneManager::enter(scene);
    auto imagePlot = gcnew Sprite(image);
    auto wordPlot = new Text(word);
    imagePlot->setName("plot");
    wordPlot->setName("plot");
    // 创建文字绘图样式
    DrawingStyle style;
    style.mode = DrawingStyle::Mode::Solid; // 绘图模式为填充
    style.fillColor = Color(50, 52, 46);         // 文字填充色
    style.strokeColor = Color::Blue;       // 文字描边色
    style.strokeWidth = 2.0;                // 文字描边宽度为 2.0
    style.lineJoin = LineJoin::Miter;       // 线条相交样式

    // 设置绘图样式
    wordPlot->setDrawingStyle(style);
    scene->addChild(imagePlot);
    scene->addChild(wordPlot);
    auto music = MusicPlayer::preload(voice);

    // 判断指针是否为空
    if (music)
    {
        // 播放音乐
        music->play();
    }

    // 传入选项节点
    auto callback = [&](Event* evt)
    {
        if (evt->type == Event::MouseDown)
        {
            String option = imagePlot->getName();  // 获取选项名称
            Archive& archive = Archive::getInstance(0); // 获取0号存档
 
            // 渲染选项后的剧情
            
            // 创建剧情控制器实例
            PlotController& controller = PlotController::getInstance();

            string path = "";
            int flagError = 0;
            try {
                // 查找0号存档的进度对应的剧情资源路径
                path = controller.findPlot(archive.getPlotFlag());
                if ("" == path) {
                    // 输出当前存档内容
                    cout << archive.getPlotFlag() + " test" + to_string(archive.getID());
                    throw "没有找到剧情选项的进度" + archive.getPlotFlag();
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
                // 初始化场景
                scene->removeChildren("plot");
                // 渲染剧情
                plot.render(path);
            }
        }
    };
    auto lis = gcnew Listener(callback);
    //imagePlot->addListener(lis);
     // 文字被点击
    wordPlot->addListener(lis);
    imagePlot->setName("C");    // 设置选项名称
}