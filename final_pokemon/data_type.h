#pragma once
#define MAX_NAME 10
#define PLAYER_NUM 1
#define MONSTER_BALL 3
#define CASH 10000

enum start_pokemon {ggobugi=1, pichu, fire}; //꼬부기, 피츄, 파이리. switch문에서 가독성 높이기 위함

typedef struct pokemon{
	int attribute;
	char *name;
	int hp;
	int max_hp;
	int power;
	int exp;
	int(*skill)(void *, void *); // 적과 나의 player struct 가져옴.
}Pokemon;

typedef struct inventory{
	int monster_ball;
	int evolution_stone;
	int medicine;
}Inventory;

typedef struct player{
	char *name;
	int cash;
	int badge;
	Inventory *inventory;
	Pokemon *pokemon;
	Pokemon **pokemon_bag; //가지고 있는 포켓몬 보관
	int pres_level; // 체육관 레벨
}Player;

typedef struct rand_pokemon{
	int i;
	int j;
}rand_pokemon;