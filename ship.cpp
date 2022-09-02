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
	/*
	//������
	fout1 	<< "��������ֵ: " << ship.shipDurability << std::endl
	        << "��Ա����(���ܸ���ճ����): " << ship.crewTotalCount << std::endl
	        << "����ٶ�: " << ship.maxSpeed << std::endl
	        << "��תʱ��: " << ship.turningTime << "s" << std::endl
	        << "֧Ԯ�ɻ�: "  << ship.supportPlane << endl
	        << "֧Ԯ�ɻ�����: " << ship.supportPlaneCount << "��" << endl;
	//��������
	fout1 << "��������: " << gunName(weapon.name) << std::endl
	      << "�ھ�: " << weapon.caliber << std::endl
	      << "����: " << weapon.wtype << std::endl
	      << "���Ƶ��: " << weapon.shotFreq << std::endl
	      << "�Զ���׼�����(AA������): " << weapon.aimMaxDist << std::endl
	      << "�˺�: " << weapon.damage << std::endl
	      << "����: " << weapon.ammoCount << std::endl
	      << "����������: " << weapon.gunsCount << std::endl << std::endl;
	*/
	return true;
}
