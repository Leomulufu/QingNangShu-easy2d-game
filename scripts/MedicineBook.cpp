#pragma once
#include "MedicineGame.h"
#include "Medicine.h"
#include "MedicineBook.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "TmpData.h"
#include "SceneInstance.h"

MedicineBook::MedicineBook()
{

  auto MedicineBook01 = gcnew Sprite("images/MedicineBook01.png");
  MedicineBook01->setScaleX(0.50f); MedicineBook01->setScaleY(0.50f);


  auto MedicineBook02 = gcnew Sprite("images/MedicineBook02.png");
  MedicineBook02->setScaleX(0.50f); MedicineBook02->setScaleY(0.50f);
}