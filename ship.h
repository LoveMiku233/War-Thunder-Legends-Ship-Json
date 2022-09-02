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
	string supportPlane = "��";
	int crewTotalCount = 0;
	int supportPlaneCount = 0;

	void printfShip() {
		std::cout << "��������ֵ: " << shipDurability << std::endl
		          << "��Ա����(���ܸ���ճ����): " << crewTotalCount << std::endl
		          << "����ٶ�: " << maxSpeed << std::endl
		          << "��תʱ��: " << turningTime << "s" << std::endl
		          << "֧Ԯ�ɻ�: " << supportPlane << endl
		          << "֧Ԯ�ɻ�����: " << supportPlaneCount << "��" << endl;
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
		std::cout << "��������: " << gunName(name) << std::endl
		          << "�ھ�: " << caliber << std::endl
		          << "����: " << wtype << std::endl
		          << "���Ƶ��: " << shotFreq << std::endl
		          << "�Զ���׼�����(AA������): " << aimMaxDist << std::endl
		          << "�˺�: " << damage << std::endl
		          << "����: " << ammoCount << std::endl
		          << "����������: " << gunsCount << std::endl << std::endl;
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
