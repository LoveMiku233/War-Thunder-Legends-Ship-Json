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
		//fout << "***********************************************************" << endl;
		fout1 << "舰船名称: " << ship.name << endl;
		int wpcnt = 0;
		fout1 << "舰船生命值: " << ship.var.shipDurability<< std::endl
		          << "船员总数(可能复制粘贴的): " << ship.var.crewTotalCount << std::endl
		          << "最大速度: " << ship.var.maxSpeed << std::endl
		          << "回转时间: " << ship.var.turningTime << "s" << std::endl
		          << "支援飞机: " << ship.var.supportPlane << endl
		          << "支援飞机个数: " << ship.var.supportPlaneCount << "架" << endl;
		while (ship.weapons[wpcnt].name.compare("null")) {
			fout1 << "武器名称: " << gunName(ship.weapons[wpcnt].name) << std::endl
		          << "口径: " << ship.weapons[wpcnt].caliber << std::endl
		          << "类型: " << ship.weapons[wpcnt].wtype << std::endl
		          << "射击频率: " << ship.weapons[wpcnt].shotFreq << std::endl
		          << "自动瞄准最大区(AA和鱼雷): " << ship.weapons[wpcnt].aimMaxDist << std::endl
		          << "伤害: " << ship.weapons[wpcnt].damage << std::endl
		          << "备弹: " << ship.weapons[wpcnt].ammoCount << std::endl
		          << "此武器数量: " << ship.weapons[wpcnt].gunsCount << std::endl << std::endl;
			wpcnt++;
		}
	return true;
}
