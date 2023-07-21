#pragma once
#include "Medicine.h"
#include <easy2d/easy2d.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace easy2d;
using namespace std;

//HerbData,从0-6，分别是总数，性温，性寒，性平，味辛，味苦，味甘

SavedMedicineData::SavedMedicineData()
{
	//省略以下方剂
}

PlayerMedicineData::PlayerMedicineData()
{
	Sprite** medicineIcon = new Sprite * [34];

	medicine[0].Name = "无名无形的汤药";
	medicine[0].HerbData = { 0,0,0,0,0,0,0 };
	medicine[0].Water = 0;
	medicine[0].Fire = 0;
	medicine[0].Medicine = "";
	medicine[0].Prepare = "";
	medicine[0].Explain = "";
	medicine[0].Tag = "";

	medicine[1].Name = "人参败毒散";
	medicine[1].HerbData = { 7,2,0,0,2,3,0 };
	medicine[1].Water = 1;
	medicine[1].Fire = 0;
	medicine[1].Medicine = "二份性温草药，二份味辛草药，三份味苦草药 。";
	medicine[1].Prepare = "水制。";
	medicine[1].Explain = "“人参败毒草苓芎，羌独柴前枳桔同；生姜薄荷煎汤服，祛寒除湿功效宏。”";
	medicine[1].Tag = "解表药，解热护肝，治瘟疫。";

	medicine[2].Name = "麻黄汤";
	medicine[2].HerbData = { 9,4,0,0,3,2,0 };
	medicine[2].Water = 1;
	medicine[2].Fire = 1;
	medicine[2].Medicine = "二份性温草药，二份味辛草药，三份味苦草药 。";
	medicine[2].Prepare = "水火共制。";
	medicine[2].Explain = "“麻黄汤中用桂枝，杏仁甘草四般施， 发热恶寒头项痛，无汗而喘服之宜。”";
	medicine[2].Tag = "解表药，宣肺平喘，治风寒。";

	medicine[3].Name = "苇茎汤";
	medicine[3].HerbData = { 8,0,3,1,0,0,4 };
	medicine[3].Water = 1;
	medicine[3].Fire = 0;
	medicine[3].Medicine = " 三份性寒草药，一份性平草药，四份味甘草药。";
	medicine[3].Prepare = "水制。";
	medicine[3].Explain = "“苇茎瓜瓣苡桃仁，清肺化痰逐瘀能，热毒痰瘀致肺痈，脓成未成均胜任。”";
	medicine[3].Tag = "清热剂，清肺化痰，治肺痈。";

	medicine[4].Name = "贝母瓜蒌散";
	medicine[4].HerbData = { 10,1,1,1,1,3,3 };
	medicine[4].Water = 1;
	medicine[4].Fire = 0;
	medicine[4].Medicine = " 一份性温草药，一份性寒草药，一份性平草药，一份味辛草药，三份味苦草药 ，三份味甘草药。";
	medicine[4].Prepare = "水制。";
	medicine[4].Explain = "“贝母瓜蒌散茯苓，陈皮桔梗花粉增，咳嗽咽干痰难咯，润燥化痰病自清。”";
	medicine[4].Tag = "祛痰剂，润肺化痰，治咳嗽。";

	medicine[5].Name = "白虎汤";
	medicine[5].HerbData = { 8,0,3,1,0,1,3 };
	medicine[5].Water = 1;
	medicine[5].Fire = 0;
	medicine[5].Medicine = " 三份性寒草药，一份性平草药， 一份味苦草药 ，三份味甘草药。";
	medicine[5].Prepare = "水制。";
	medicine[5].Explain = "“白虎膏知粳米甘，清热生津止渴烦，气分热盛四大证，益气生津人参添。”";
	medicine[5].Tag = "清热剂，清热生津，治上火。";

	medicine[6].Name = "六一散";
	medicine[6].HerbData = { 9,0,4,1,0,0,4 };
	medicine[6].Water = 1;
	medicine[6].Fire = 0;
	medicine[6].Medicine = " 四份性寒草药，一份性平草药， 四份味甘草药。";
	medicine[6].Prepare = "水制。";
	medicine[6].Explain = "“六一散用滑石草，清暑利湿有功效，益元碧玉与鸡苏，砂黛薄荷加之好。”";
	medicine[6].Tag = "祛暑剂，清暑利湿，治暑湿症。";

	medicine[7].Name = "桂苓甘露飲";
	medicine[7].HerbData = { 10,0,3,2,1,0,4 };
	medicine[7].Water = 1;
	medicine[7].Fire = 0;
	medicine[7].Medicine = " 三份性寒草药，两份性平草药，一份味辛草药， 四份味甘草药。";
	medicine[7].Prepare = "水制。";
	medicine[7].Explain = "“桂苓甘露猪苓膏，术泽寒水滑石草，祛暑清热以利湿，发热烦渴吐泻消。”";
	medicine[7].Tag = "祛暑剂，解热利湿，治暑湿症。";

	medicine[8].Name = "血府逐瘀汤";
	medicine[8].HerbData = { 8,1,1,2,1,2,1 };
	medicine[8].Water = 1;
	medicine[8].Fire = 0;
	medicine[8].Medicine = " 一份性温草药，一份性寒草药，两份性平草药，一份味辛草药，两份味苦草药 ，一份味甘草药。";
	medicine[8].Prepare = "水制。";
	medicine[8].Explain = "“血府当归生地桃，红花甘草壳赤芍，柴胡芎桔牛膝等，血化下行不作劳。”";
	medicine[8].Tag = "活血剂，活血化瘀，治胸中血瘀症。";

	medicine[9].Name = "狗皮膏";
	medicine[9].HerbData = { 10,2,1,1,1,2,3 };
	medicine[9].Water = 1;
	medicine[9].Fire = 1;
	medicine[9].Medicine = " 两份性温草药，一份性寒草药，一份性平草药，一份味辛草药，两份味苦草药 ，三份味甘草药。";
	medicine[9].Prepare = "水火共制。";
	medicine[9].Explain = "“其形黑似漆，热则软，凉则硬，贴之即粘，拔之即起。”";
	medicine[9].Tag = "活血生肌剂，活血止痛，治跌打损伤。";

	medicine[10].Name = "固经丸";
	medicine[10].HerbData = { 9,0,3,0,0,3,3 };
	medicine[10].Water = 1;
	medicine[10].Fire = 1;
	medicine[10].Medicine = " 四份性寒草药，四份味苦草药 ，四份味甘草药。";
	medicine[10].Prepare = "水火共制。";
	medicine[10].Explain = "“固经丸用龟版君，黄柏椿皮香附芩，更加芍药糊丸服，漏下崩中均可宁。”";
	medicine[10].Tag = "固涩剂，止经固血，治月经过多。";

	medicine[11].Name = "千金鲤鱼汤";
	medicine[11].HerbData = { 8,1,0,3,0,0,4 };
	medicine[11].Water = 1;
	medicine[11].Fire = 0;
	medicine[11].Medicine = " 一份性温草药， 三份性平草药，四份味甘草药 。";
	medicine[11].Prepare = "水制。";
	medicine[11].Explain = "“千金鲤鱼水肿方，归芍苓术陈皮姜，健脾理气兼行水，养血安胎正不伤。”";
	medicine[11].Tag = "补益剂，安血养胎，治妊娠水肿。";

	medicine[12].Name = "玉屏风散";
	medicine[12].HerbData = { 10,3,0,0,1,2,4 };
	medicine[12].Water = 1;
	medicine[12].Fire = 1;
	medicine[12].Medicine = " 三份性温草药， 一份味辛草药，两份味苦草药 ，四份味甘草药。";
	medicine[12].Prepare = "水火共制。";
	medicine[12].Explain = "“玉屏风散最有灵，芪术防风鼎足形，表虚汗多易感冒，益气固表止汗神。”";
	medicine[12].Tag = "补益固涩剂，益气固表止汗，治鼻炎肾病。";

	medicine[13].Name = "二陈汤";
	medicine[13].HerbData = { 10,4,0,2,3,0,1 };
	medicine[13].Water = 1;
	medicine[13].Fire = 1;
	medicine[13].Medicine = " 四份性温草药， 两份性平草药，三份味辛草药， 一份味甘草药。";
	medicine[13].Prepare = "水火共制。";
	medicine[13].Explain = "“二陈汤用半夏陈，益以茯苓甘草成，理气和中兼燥湿，一切痰饮此方珍。”";
	medicine[13].Tag = "祛痰剂，燥湿化痰，治湿痰症。";

	medicine[14].Name = "清气化痰丸";
	medicine[14].HerbData = { 7,2,1,0,1,2,1 };
	medicine[14].Water = 0;
	medicine[14].Fire = 1;
	medicine[14].Medicine = " 两份性温草药，一份性寒草药，一份味辛草药，两份味苦草药 ，一份味甘草药。";
	medicine[14].Prepare = "火制。";
	medicine[14].Explain = "“贝母瓜蒌散茯苓，陈皮桔梗花粉增，咳嗽咽干痰难咯，润燥化痰病自清。”";
	medicine[14].Tag = "祛痰剂，理气止咳，治痰热咳嗽。";

	medicine[15].Name = "枳术汤";
	medicine[15].HerbData = { 8,2,2,0,0,2,2 };
	medicine[15].Water = 1;
	medicine[15].Fire = 0;
	medicine[15].Medicine = " 两份性温草药，两份性寒草药，两份味苦草药 ，两份味甘草药。";
	medicine[15].Prepare = "水制。";
	medicine[15].Explain = "“用枳实以破结气，白术以除水湿，温服三服，则腹软结开而硬消矣。”";
	medicine[15].Tag = "消食剂，健脾利水，治消化不良。";

	medicine[16].Name = "藿香正气散";
	medicine[16].HerbData = { 10,3,0,1,4,1,1 };
	medicine[16].Water = 1;
	medicine[16].Fire = 1;
	medicine[16].Medicine = " 三份性温草药，一份性平草药，四份味辛草药，一份味苦草药 ，一份味甘草药。";
	medicine[16].Prepare = "水火共制。";
	medicine[16].Explain = "“藿香正气大腹苏，甘桔陈苓术朴俱，夏曲白芷加姜枣，感伤岚瘴并能驱。”";
	medicine[16].Tag = "祛湿剂，理气和中，治风寒湿滞。";

	medicine[17].Name = "瓜蒂散";
	medicine[17].HerbData = { 4,0,1,1,0,1,1 };
	medicine[17].Water = 1;
	medicine[17].Fire = 0;
	medicine[17].Medicine = " 一份性寒草药，一份性平草药，一份味苦草药 ，一份味甘草药。";
	medicine[17].Prepare = "水制。";
	medicine[17].Explain = "“瓜蒂散中赤小豆，豆豉汁调酸苦凑，逐邪涌吐功最捷，胸脘痰食服之瘳。”";
	medicine[17].Tag = "涌吐剂，涌吐痰涎宿食，治痰涎宿食。";

	medicine[18].Name = "救急稀涎散";
	medicine[18].HerbData = { 10,5,1,0,4,0,0 };
	medicine[18].Water = 1;
	medicine[18].Fire = 0;
	medicine[18].Medicine = " 五份性温草药，一份性寒草药，四份味辛草药。";
	medicine[18].Prepare = "水制。";
	medicine[18].Explain = "“稀涎皂角与白矾，急救可祛膈上痰，中风昏迷属闭证，功能开窍又通关。”";
	medicine[18].Tag = "开窍剂，开窍醒神，治中风不省人事。";

	medicine[19].Name = "大黄附子汤";
	medicine[19].HerbData = { 10,1,2,0,3,0,4 };
	medicine[19].Water = 1;
	medicine[19].Fire = 0;
	medicine[19].Medicine = " 一份性温草药，两份性寒草药，三份味辛草药，四份味甘草药。";
	medicine[19].Prepare = "水制。";
	medicine[19].Explain = "“金匮大黄附子汤，细辛散寒止痛良，冷积内结成实证，功专温下妙非常。”";
	medicine[19].Tag = "泻下剂，通便止痛，治腹痛便秘。";

	medicine[20].Name = "保和丸";
	medicine[20].HerbData = { 9,3,0,1,2,0,3 };
	medicine[20].Water = 0;
	medicine[20].Fire = 1;
	medicine[20].Medicine = " 三份性温草药，一份性平草药，两份味辛草药，三份味甘草药。";
	medicine[20].Prepare = "火制。";
	medicine[20].Explain = "“保和神曲与山楂，陈翘莱菔苓半夏，炊饼为丸白汤下，消食和胃效堪夸。”";
	medicine[20].Tag = "消食剂，和胃导滞，治食滞胃脘。";

	medicine[21].Name = "四神丸";
	medicine[21].HerbData = { 10,5,0,0,3,1,1 };
	medicine[21].Water = 1;
	medicine[21].Fire = 1;
	medicine[21].Medicine = " 五份性温草药，三份味辛草药，一份味苦草药 ，一份味甘草药。";
	medicine[21].Prepare = "水火兼制。";
	medicine[21].Explain = "“四神骨脂吴茱萸，肉蔻除油五味具，大枣生姜同煎合，五更肾泄最相宜。”";
	medicine[21].Tag = "固涩剂，温脾暖肾，治脾肾阳虚之肾泻。";

	medicine[22].Name = "朱砂安神丸";
	medicine[22].HerbData = { 10,1,2,1,1,2,3 };
	medicine[22].Water = 1;
	medicine[22].Fire = 1;
	medicine[22].Medicine = " 一份性温草药，两份性寒草药，一份性平草药，一份味辛草药，两份味苦草药 ，三份味甘草药。";
	medicine[22].Prepare = "水火兼制。";
	medicine[22].Explain = "“朱砂安神东垣方，归连甘草合地黄，怔忡不寐心烦乱，养阴清热可复康。”";
	medicine[22].Tag = "安神剂，镇心安神，治失眠多梦。";

	medicine[23].Name = "酸枣仁汤";
	medicine[23].HerbData = { 10,1,1,3,1,1,3 };
	medicine[23].Water = 1;
	medicine[23].Fire = 1;
	medicine[23].Medicine = " 一份性温草药，一份性寒草药，三份性平草药，一份味辛草药，一份味苦草药 ，三份味甘草药。";
	medicine[23].Prepare = "水火兼制。";
	medicine[23].Explain = "“酸枣仁汤治失眠，川芎知草茯苓煎，养血除烦清虚热，安然入睡梦香甜。”";
	medicine[23].Tag = "安神剂，养血安神，足肝血治失眠。";

	medicine[24].Name = "平胃散";
	medicine[24].HerbData = { 9,3,0,0,3,3,0 };
	medicine[24].Water = 1;
	medicine[24].Fire = 1;
	medicine[24].Medicine = " 三份性温草药，三份味辛草药，三份味苦草药 。";
	medicine[24].Prepare = "水火兼制。";
	medicine[24].Explain = "“平胃散内君苍术，厚朴陈草姜枣煮，燥湿运脾又和胃，湿滞脾胃胀满除。”";
	medicine[24].Tag = "祛湿剂，燥湿运脾，治湿滞脾胃。";

	medicine[25].Name = "乌梅丸";
	medicine[25].HerbData = { 10,1,1,1,3,3,1 };
	medicine[25].Water = 0;
	medicine[25].Fire = 1;
	medicine[25].Medicine = "一份性温草药，一份性寒草药，一份性平草药，三份味辛草药，三份味苦草药 ，三份味甘草药。";
	medicine[25].Prepare = "火制。";
	medicine[25].Explain = "“乌梅丸用细辛桂，黄连黄柏及当归，人参椒姜及附子，温中寓清在安蛔。”";
	medicine[25].Tag = "驱虫剂，安蛔止痛，治蛔虫。";

	medicine[26].Name = "六味地黄丸";
	medicine[26].HerbData = { 7,1,0,2,0,0,4 };
	medicine[26].Water = 0;
	medicine[26].Fire = 1;
	medicine[26].Medicine = " 一份性温草药，两份性平草药，四份味甘草药。";
	medicine[26].Prepare = "火制。";
	medicine[26].Explain = "“棕褐色至黑褐色的大蜜丸，味甜而酸。”";
	medicine[26].Tag = "补益剂，治肝脾肾，治体虚，眼炎。";

	medicine[27].Name = "桃核承气汤";
	medicine[27].HerbData = { 10,0,2,2,0,3,3 };
	medicine[27].Water = 1;
	medicine[27].Fire = 1;
	medicine[27].Medicine = " 两份性寒草药，两份性平草药，三份味苦草药，三份味甘草药。";
	medicine[27].Prepare = "水火共制。";
	medicine[27].Explain = "“桃核承气五般施，甘草硝黄并桂枝，淤热互结小腹胀，蓄血如狂最相宜。”";
	medicine[27].Tag = "补益剂，治肝脾肾，治体虚。";

	medicine[28].Name = "玉真散";
	medicine[28].HerbData = { 10,3,0,0,3,2,2 };
	medicine[28].Water = 1;
	medicine[28].Fire = 1;
	medicine[28].Medicine = " 三份性温草药，三份味辛草药，两份味苦草药，两份味甘草药。";
	medicine[28].Prepare = "水火共制。";
	medicine[28].Explain = "“玉真散治破伤风，牙关紧急反张弓，星麻白附羌防芷，外敷内服一方通。”";
	medicine[28].Tag = "祛风药，祛风化痰，治破伤风。";

	medicine[29].Name = "真武汤";
	medicine[29].HerbData = { 10,4,0,1,2,1,2 };
	medicine[29].Water = 1;
	medicine[29].Fire = 1;
	medicine[29].Medicine = "四份性温草药，一份味平草药，两份味辛草药，一份味苦草药，两份味甘草药。";
	medicine[29].Prepare = "水火共制。";
	medicine[29].Explain = "“真武汤壮肾中阳，茯苓术芍附生姜，少阴腹痛有水气，悸眩瞤(shùn)惕(tì)保安康。”";
	medicine[29].Tag = "祛湿药，温阳利水，治风心病。";

	medicine[30].Name = "川芎茶调散";
	medicine[30].HerbData = { 8,3,0,0,4,0,1 };
	medicine[30].Water = 1;
	medicine[30].Fire = 0;
	medicine[30].Medicine = " 三份性温草药，一份味平草药，四份味辛草药，一份味苦草药，一份味甘草药。";
	medicine[30].Prepare = "水制。";
	medicine[30].Explain = "“川芎茶调有荆防，辛芷薄荷甘草羌，目昏鼻塞风攻上，偏正头痛悉能康。”";
	medicine[30].Tag = "祛风药，疏风止痛，治正偏头痛。";

	medicine[31].Name = "华佗";
	medicine[31].HerbData = { 0,0,0,0,0,0,0 };
	medicine[31].Water = 0;
	medicine[31].Fire = 0;
	medicine[31].Medicine = "";
	medicine[31].Prepare = "";
	medicine[31].Explain = "“三国时期的神医。华门——”";
	medicine[31].Tag = "神医，治疑难杂症。";

	medicine[32].Name = "红糖水";
	medicine[32].HerbData = { 0,0,0,0,0,0,0 };
	medicine[32].Water = 0;
	medicine[32].Fire = 0;
	medicine[32].Medicine = "";
	medicine[32].Prepare = "";
	medicine[32].Explain = "“普通补品，能让人心情愉悦。喝了的人都说好。”";
	medicine[32].Tag = "补益品，补气血，治气血不足。";

	medicine[33].Name = "断肠草";
	medicine[33].HerbData = { 0,0,0,0,0,0,0 };
	medicine[33].Water = 0;
	medicine[33].Fire = 0;
	medicine[33].Medicine = "";
	medicine[33].Prepare = "";
	medicine[33].Explain = "“一类有毒植物的简称。外敷止痛，内服剧毒。身为医者，用途如何取决本心。”";
	medicine[33].Tag = "祛风药，毒药，散结消肿，止痛。";
}

int PlayerMedicineData::Match(vector<int> HerbData, bool Water, bool Fire)
{
	int p = 0;
	for (int i = 1; i <= 33; i++)
	{
		if (HerbData == medicine[i].HerbData && Water == medicine[i].Water && Fire == medicine[i].Fire) 
		{
			p = i;
			break;
		}
	}

	return p;
}






