#include "PlotConfig.h"
#include "PlotController.h"
#include <vector>
#include <io.h>
#include <iostream>
using namespace std;
void getFiles(string path, vector <string>& files)
{
    long hFile = 0;
    struct _finddata_t fileinfo;
    string pathp;
    if ((hFile = _findfirst(pathp.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                {
                    continue;
                }
            }
            else
            {
                string filestr = fileinfo.name;
                files.push_back(pathp.assign(path).append("//").append(filestr));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void PlotConfig::init() {

    // 创建剧情控制器实例
    PlotController& controller = PlotController::getInstance();
    //controller.setPlot("start", "./plot/Act1/MainLine/1.txt");
    /*
    string basedir = "./plot/Act1/MainLine/";
    vector <string> files;
    getFiles(basedir, files);
    int filenum = files.size();
    */
    string status = "";
    int name = 0;
    
    for (int i = 0; i <= 78; i++)
    {
        name = i + 1;
        cout << "start" + status + "plot/Prelude/MainLine/" + to_string(name) + ".txt" + "\n";
        controller.setPlot("start" + status, "plot/Prelude/MainLine/"+ to_string(name) +".txt");
        status = status + "1";
    }

}
