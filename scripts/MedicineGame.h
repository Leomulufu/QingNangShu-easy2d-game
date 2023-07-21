#pragma once
#include <easy2d/easy2d.h>
#include <vector>
#include "Medicine.h"

using namespace std;
using namespace easy2d;

class InitButton
{
public:
	Sprite** medicineIcon = new Sprite * [34];


	InitButton();
	InitButton(PlayerMedicineData* player);

	void SetCount(int i, Point point, Menu* GameMenu, const string& countPrefix);

	void WarmCount(int i, Point point, Menu* GameMenu);
	void ColdCount(int i, Point point, Menu* GameMenu);
	void SoftCount(int i, Point point, Menu* GameMenu);
	void SpicyCount(int i, Point point, Menu* GameMenu);
	void BitterCount(int i, Point point, Menu* GameMenu);
	void SweetCount(int i, Point point, Menu* GameMenu);

	void TotalCount(int i, Point point, Menu* GameMenu);

	void MedicineChange(int i, Point point, Menu* GameMenu,Sprite* medicineIcon, Sprite* Bowl);
};
