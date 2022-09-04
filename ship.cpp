#include "ship.h"

string gunName(string str) {
	string s1 = str;
	if (str.find("auxCannon") != -1) {
		s1 = "";
		s1 = str.substr(10, str.length() - 1) + "����";
	} else if (str.find("aaa") != -1) {
		s1 = "";
		s1 = str.substr(4, str.length() - 1) + "������";
	} else if (str.find("mainCannon") != -1) {
		s1 = "";
		s1 = str.substr(11, str.length() - 1) + "����";
	} else if (str.find("torpedo") != -1) {
		s1 = "";
		s1 = str.substr(8, str.length() - 1) + "����";
	} else if (str.find("mine") != -1) {
		s1 = "ˮ��";
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
		fout1 << "��������: " << ship.name << endl;
		int wpcnt = 0;
		fout1 << "��������ֵ: " << ship.var.shipDurability<< std::endl
		          << "��Ա����(���ܸ���ճ����): " << ship.var.crewTotalCount << std::endl
		          << "����ٶ�: " << ship.var.maxSpeed << std::endl
		          << "��תʱ��: " << ship.var.turningTime << "s" << std::endl
		          << "֧Ԯ�ɻ�: " << ship.var.supportPlane << endl
		          << "֧Ԯ�ɻ�����: " << ship.var.supportPlaneCount << "��" << endl;
		while (ship.weapons[wpcnt].name.compare("null")) {
			fout1 << "��������: " << gunName(ship.weapons[wpcnt].name) << std::endl
		          << "�ھ�: " << ship.weapons[wpcnt].caliber << std::endl
		          << "����: " << ship.weapons[wpcnt].wtype << std::endl
		          << "���Ƶ��: " << ship.weapons[wpcnt].shotFreq << std::endl
		          << "�Զ���׼�����(AA������): " << ship.weapons[wpcnt].aimMaxDist << std::endl
		          << "�˺�: " << ship.weapons[wpcnt].damage << std::endl
		          << "����: " << ship.weapons[wpcnt].ammoCount << std::endl
		          << "����������: " << ship.weapons[wpcnt].gunsCount << std::endl << std::endl;
			wpcnt++;
		}
	return true;
}
