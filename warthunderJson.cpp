#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

#include "json/json.h"
#include "name.h"
#include "air.h"
#include "ship.h"

using namespace std;


Ship ship[100];
int shipcnt = 0;

void display(string str) {
	//MessageBox(NULL, "233", str.c_str(), MB_YESNO);
}

void printALLShipName() {
	for (int i = 0; i < shipcnt; i++) {
		//fout << "***********************************************************" << endl;
		//fout << "��������: " << ship[i].name << endl;
		ship[i].var.printfShip(); //
		int wpcnt = 0;
		while (ship[i].weapons[wpcnt].name.compare("null")) {
			ship[i].weapons[wpcnt++].printfWeapons();
		}
	}
}

void readFileJson() {
	Json::Reader reader;
	Json::Value root;

	ifstream in("test.json", ios::binary);

	if (!in.is_open()) {
		cout << "Error opening file\n";
		return;
	}

	if (reader.parse(in, root)) {
		Json::Value::Members mem = root.getMemberNames();
		for (auto i = mem.begin(); i != mem.end(); i++) {
			//��������
			if (!root[*i]["type"].asString().compare("ship")) {
				//���ִ���
				Ship temp;
				temp.name = *i;
				//�������ݴ���
				//fout << temp.name << endl;
				temp.var.crewTotalCount = root[*i]["shipDurability"].asInt();
				temp.var.maxSpeed = root[*i]["Shop"]["maxSpeed"].asFloat();
				temp.var.shipDurability = root[*i]["Shop"]["shipDurability"].asInt();
				temp.var.turningTime = root[*i]["Shop"]["turningTime"].asInt();
				if (root[*i]["Shop"]["supportPlane"]) {
					temp.var.supportPlane = root[*i]["Shop"]["supportPlane"].asString();
					temp.var.supportPlaneCount = root[*i]["Shop"]["supportPlaneCount"].asInt();
				}
				//ship[shipcnt]=temp;
				//�������ݴ���
				int wpcnt = 0;
				Json::Value::Members wp = root[*i]["Shop"]["weapons"].getMemberNames();
				for (auto j = wp.begin(); j != wp.end(); j++) {
					ShipWeapons wptemp;
					Json::Value wproot = root[*i]["Shop"]["weapons"][*j];
					string wptype = wproot["wtype"].asString();
					wptemp.name = *j;
					wptemp.wtype = wptype;
					wptemp.damage = wproot["damage"].asFloat();
					wptemp.shotFreq = wproot["shotFreq"].asFloat();
					wptemp.gunsCount = wproot["gunsCount"].asInt();
					wptemp.caliber = wproot["caliber"].asFloat();
					wptemp.ammoCount = wproot["ammoCount"].asInt();
					if (wptype.compare("aaa")) {
						wptemp.aimMaxDist = wproot["aimMaxDist"].asFloat();
					} else if (wptype.compare("torpedo")) {
						//todo ����
						wptemp.aimMaxDist = wproot["aimMaxDist"].asFloat();
					}
					temp.weapons[wpcnt++] = wptemp;
				}
				ship[shipcnt++] = temp;
			}
		}
	}
	system("pause");
}

int main() {
	mapInit();

	cout << "LoveMiku233 ����" << endl;
	cout << "Ŀǰ����52�Ҵ�,���ݴ󲿷��Ҷ��Ѿ�����" << endl;
	cout << "�д���֪�����ľ��������𣿿���˽�Ÿ�����" << endl;
	readFileJson();
	printALLShipName();
	//fout.close();
#ifndef PRINT
	cout << "�����data.txt" << endl;
	wtFile();
	//wtFile.outShip();
#endif
	cout<<"����������"<<endl;
	return 0;
}
