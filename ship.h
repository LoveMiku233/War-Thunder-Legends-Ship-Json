#ifndef _SHIP_
#define _SHIP_

#include <iostream>
#include <string>
#include <fstream>
#include "json/json.h"

using  namespace std;



//#define PRINT


string gunName(string str);

struct ShipVar {
	int shipDurability;
	float maxSpeed;
	int turningTime;
	string supportPlane = "无";
	int crewTotalCount = 0;
	int supportPlaneCount = 0;

	void printfShip() {
		std::cout << "舰船生命值: " << shipDurability << std::endl
		          << "船员总数(可能复制粘贴的): " << crewTotalCount << std::endl
		          << "最大速度: " << maxSpeed << std::endl
		          << "回转时间: " << turningTime << "s" << std::endl
		          << "支援飞机: " << supportPlane << endl
		          << "支援飞机个数: " << supportPlaneCount << "架" << endl;
	};
};

struct ShipWeapons {
	string name = "null";
	string wtype = "";
	float damage = 0;
	float shotFreq = 0;
	float aimMaxDist = 0;
	float distToLive = 0;
	int gunsCount = 0;
	float caliber = 0;
	int ammoCount = 0;

	void printfWeapons() {
		std::cout << "武器名称: " << gunName(name) << std::endl
		          << "口径: " << caliber << std::endl
		          << "类型: " << wtype << std::endl
		          << "射击频率: " << shotFreq << std::endl
		          << "自动瞄准最大区(AA和鱼雷): " << aimMaxDist << std::endl
		          << "伤害: " << damage << std::endl
		          << "备弹: " << ammoCount << std::endl
		          << "此武器数量: " << gunsCount << std::endl << std::endl;
	};
};

struct Ship {
	string name = "null";

	ShipWeapons weapons[10] = {};
	ShipVar var;
};

bool weaponsProc(Json::Value &root);

class wtFile {
	private:
		ofstream fout1;
		void outShipVar(const ShipVar &);
		void outShipWeapons(const ShipWeapons &);
	public:
		bool file_is_open = false;
		wtFile();
		bool outShip(const Ship &);
		~wtFile();
};


#endif
