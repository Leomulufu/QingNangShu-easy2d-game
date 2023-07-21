#pragma once
#include <easy2d/easy2d.h>
#include <vector>

using namespace std;
using namespace easy2d;

class MedicineData
{
public:
	//六大种草药数据
	vector<int> HerbData;
	//是否水制
	bool Water = 0;
	//是否火制
	bool Fire = 0;
};

class SavedMedicineData :public MedicineData	 //储存既有数据
{
public:
	SavedMedicineData();
	string Name;
	//方剂所需草药
	string Medicine;
	//方剂解释
	string Prepare;
	//炮制方法
	string Explain;
	//方剂标签
	string Tag;
};

class PlayerMedicineData :public MedicineData		//将既有数据与玩家数据对比
{
public:
	PlayerMedicineData();
	SavedMedicineData medicine[35];
	//QTE是否成功
	bool QTE;
	//判断QTE，QTE接口

	//判断玩家方剂是否与即有方剂匹配
	int Match(vector<int> HerbData,bool Water, bool Fire);
};
