#ifndef _NAME_
#define _NAME_

#include <map>
#include <string>
using namespace std;

//map<string, string> map;

enum {
	FIRST = 0,
	germ_battleship_helgoland = FIRST,
	germ_battleship_kaiser,
	germ_battleship_scharnhorst,
	germ_battleship_tirpitz_1944,
	germ_cruiser_admiral_hipper,
	germ_cruiser_nurnberg,
	germ_destroyer_class1934a_1940,
	germ_destroyer_class1936a_mob_z32,
	germ_sub_type_21,
	germ_sub_type_7,
	jp_aircraftcarrier_kaga,
	jp_aircraftcarrier_zuikaku,
	jp_battleship_fuso,
	jp_battleship_hyuga,
	jp_battleship_settsu,
	jp_battleship_yamato,
	jp_cruiser_furutaka,
	jp_cruiser_tone,
	jp_destroyer_akizuki,
	jp_destroyer_fubuki,
	uk_aircraftcarrier_illustrious,
	uk_aircraftcarrier_implacable,
	uk_battleship_dreadnought,
	uk_battleship_king_george_1945,
	uk_battleship_vanguard,
	uk_battleship_warspite,
	uk_cruiser_kent,
	uk_cruiser_southampton,
	uk_destroyer_hunt_4series,
	uk_destroyer_tribal,
	us_aircraftcarrier_essex,
	us_aircraftcarrier_forrestal,
	us_aircraftcarrier_lexington,
	us_battlecruiser_alaska_class,
	us_battleship_iowa,
	us_battleship_north_dakota,
	us_battleship_wyoming_class,
	us_cruiser_cleveland_class_cleveland,
	us_cruiser_new_orleans_class,
	us_destroyer_fletcher,
	us_destroyer_porter,
	us_sub_balao,
	us_sub_tang,
	ussr_battlecruiser_stalingrad,
	ussr_battleship_imperatritsa_mariya,
	ussr_battleship_parizhskaya_kommuna,
	ussr_battleship_pr23_sovetskij_soyuz,
	ussr_cruiser_kirov,
	ussr_cruiser_sverdlov,
	ussr_destroyer_7y,
	ussr_destroyer_pr56_spokoinyy,
	ussr_sub_pr613,
	ussr_sub_type_k,
	LAST = ussr_sub_type_k
};
#define NAMEMIN FIRST
#define NAMEMAX LAST
#define NAMELEN (NAMEMAX-NAMEMIN)


static struct NAME{
	const int key;
	string name;
}names[]={
	{germ_battleship_helgoland,""},
	{germ_battleship_kaiser,""},
	{germ_battleship_scharnhorst,""},
	{germ_battleship_tirpitz_1944,""},
	{germ_cruiser_admiral_hipper,""},
	{germ_cruiser_nurnberg,""},
	{germ_destroyer_class1934a_1940,""},
	{germ_destroyer_class1936a_mob_z32,""},
	{germ_sub_type_21,""},
	{germ_sub_type_7,""},
	{jp_aircraftcarrier_kaga,""},
	{jp_aircraftcarrier_zuikaku,""},
	{jp_battleship_fuso,""},
	{jp_battleship_hyuga,""},
	{jp_battleship_settsu,""},
	{jp_battleship_yamato,""},
	{jp_cruiser_furutaka,""},
	{jp_cruiser_tone,""},
	{jp_destroyer_akizuki,""},
	{jp_destroyer_fubuki,""},
	{uk_aircraftcarrier_illustrious,""},
	{uk_aircraftcarrier_implacable,""},
	{uk_battleship_dreadnought,""},
	{uk_battleship_king_george_1945,""},
	{uk_battleship_vanguard,""},
	{uk_battleship_warspite,""},
	{uk_cruiser_kent,""},
	{uk_cruiser_southampton,""},
	{uk_destroyer_hunt_4series,""},
	{uk_destroyer_tribal,""},
	{us_aircraftcarrier_essex,""},
	{us_aircraftcarrier_forrestal,""},
	{us_aircraftcarrier_lexington,""},
	{us_battlecruiser_alaska_class,""},
	{us_battleship_iowa,""},
	{us_battleship_north_dakota,""},
	{us_battleship_wyoming_class,""},
	{us_cruiser_cleveland_class_cleveland,""},
	{us_cruiser_new_orleans_class,""},
	{us_destroyer_fletcher,""},
	{us_destroyer_porter,""},
	{us_sub_balao,""},
	{us_sub_tang,""},
	{ussr_battlecruiser_stalingrad,""},
	{ussr_battleship_imperatritsa_mariya,""},
	{ussr_battleship_parizhskaya_kommuna,""},
	{ussr_battleship_pr23_sovetskij_soyuz,""},
	{ussr_cruiser_kirov,""},
	{ussr_cruiser_sverdlov,""},
	{ussr_destroyer_7y,""},
	{ussr_destroyer_pr56_spokoinyy,""},
	{ussr_sub_pr613,""},
	{ussr_sub_type_k,""}
};



void mapInit() {
	//map.insert("")
	for (int i = 0; i < NAMELEN; i++) {
		//map.insert()
	}
}


string getName(string str) {
	return "";
}



#endif
