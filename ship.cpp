#include "ship.h"

string gunName(string str) {
	string s1 = str;
	if (str.find("auxCannon") != -1) {
		s1 = "";
		s1 = str.substr(10, str.length() - 1) + "副炮";
	} else if (str.find("aaa") != -1) {
		s1 = "";
		s1 = str.substr(4, str.length() - 1) + "防空炮";
	} else if (str.find("mainCannon") != -1) {
		s1 = "";
		s1 = str.substr(11, str.length() - 1) + "主炮";
	} else if (str.find("torpedo") != -1) {
		s1 = "";
		s1 = str.substr(8, str.length() - 1) + "鱼雷";
	} else if (str.find("mine") != -1) {
		s1 = "水雷";
	}
	return s1;
}

wtFile::wtFile() {
	fout1.open("data.txt");
	if (fout1.is_open()) {
		file_is_open = true;
	}
}

wtFile::~wtFile() {
	if (file_is_open) {
		fout1.close();
	}
}

bool wtFile::outShip(const Ship &ship) {
	if (!file_is_open) {
		return false;
	}
	/*
	//船数据
	fout1 	<< "舰船生命值: " << ship.shipDurability << std::endl
	        << "船员总数(可能复制粘贴的): " << ship.crewTotalCount << std::endl
	        << "最大速度: " << ship.maxSpeed << std::endl
	        << "回转时间: " << ship.turningTime << "s" << std::endl
	        << "支援飞机: "  << ship.supportPlane << endl
	        << "支援飞机个数: " << ship.supportPlaneCount << "架" << endl;
	//武器数据
	fout1 << "武器名称: " << gunName(weapon.name) << std::endl
	      << "口径: " << weapon.caliber << std::endl
	      << "类型: " << weapon.wtype << std::endl
	      << "射击频率: " << weapon.shotFreq << std::endl
	      << "自动瞄准最大区(AA和鱼雷): " << weapon.aimMaxDist << std::endl
	      << "伤害: " << weapon.damage << std::endl
	      << "备弹: " << weapon.ammoCount << std::endl
	      << "此武器数量: " << weapon.gunsCount << std::endl << std::endl;
	*/
	return true;
}
