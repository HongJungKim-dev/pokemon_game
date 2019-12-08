#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <memory.h>
#include <conio.h>
#include <time.h>
#include <math.h>
//#include <unistd.h>

#define VILLAGE_ROW 3
#define VILLAGE_COL 3
#define BATTLE_ROW 4
#define BATTLE_COL 4
#define MIX 1000
#define MAX_NAME 10
#define PLAYER_NUM 1
#define MONSTER_BALL 3
#define CASH 10000
#define ARSIZE 100
#define BATTLE_POKEMON_COUNT 6
#define BAG_NUM 2
#define BAG_ROW 4
#define BOSS_NUM 5
#define BOOK_ROW 4
#define BOOK_COL 4

enum start_pokemon { ggobugi = 1, pichu, fire }; //���α�, ����, ���̸�. switch������ ������ ���̱� ����

typedef struct skill_info {
	char *skill_name;
	int type; // 0 = attack, 1 = heal
}SkillInfo;

typedef struct pokemon {
	char **name_list;
	char *name;
	int attribute;
	int power;
	int hp;
	int max_hp;
	int exp; // �ʿ� ����ġ = level * 2
	int level;
	int revolution;
	SkillInfo skill_info[3];
	void(*skill[3])(char skill_name[], int num, void *, void *);
}Pokemon;

typedef struct inventory {
	int monster_ball;
	int evolution_stone;
	int medicine;
}Inventory;

typedef struct player {
	char *name;
	int cash;
	int badge;
	Inventory *inventory;
	Pokemon *battle_pokemon;
	Pokemon **pokemon_bag; //������ �ִ� ���ϸ� ����
	int pres_level; // ü���� ����
}Player;