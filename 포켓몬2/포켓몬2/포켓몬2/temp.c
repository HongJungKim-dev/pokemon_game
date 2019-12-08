#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
//#include <unistd.h>
#include <Windows.h>

#pragma once
#define MAX_NAME 10
#define PLAYER_NUM 1
#define MONSTER_BALL 3
#define CASH 10000
#define BOOK_ROW 4
#define BOOK_COL 4

enum start_pokemon { ggobugi = 1, pichu, fire }; //꼬부기, 피츄, 파이리. switch문에서 가독성 높이기 위함

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
	int exp; // 필요 경험치 = level * 2
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
	Pokemon **pokemon_bag; //가지고 있는 포켓몬 보관
	int pres_level; // 체육관 레벨
}Player;



// 포켓몬 도감 column 만들기
int makeCol(Pokemon ***p_addr, int col) {
	*p_addr = (Pokemon **)malloc(sizeof(Pokemon *) * col);

	if (*p_addr == NULL) {
		printf("할당 실패\n");
		return 1;
	}
	memset(*p_addr, 0x0, sizeof(Pokemon *) * col);
	return 0;
}

// 포켓몬 도감 row 만들기
int makeRow(Pokemon **p_addr, int row) {
	*p_addr = (Pokemon *)malloc(sizeof(Pokemon) * row);

	if (*p_addr == NULL) {
		printf("할당 실패\n");
		return 1;
	}
	memset(*p_addr, 0x0, sizeof(Pokemon) * row);
	return 0;
}

// 포켓몬 도감 만들기
int make_pokemon_book(Pokemon ***p_addr) {
	int malloc_fail;
	int i=0, j=0, k = 0, l = 0;
	FILE *f1;

	malloc_fail = makeCol(p_addr, 4);
	if (malloc_fail == 1) {
		printf("공간 할당이 실패했습니다.\n");
		return malloc_fail;
	}
	for (i = 0; i < 4; i++) {
		malloc_fail = makeRow(*p_addr + i, 4);
		if (malloc_fail == 1) {
			printf("공간 할당이 실패했습니다.\n");
			return malloc_fail;
		}
		else for (j = 0; j<4; j++) {
			(*(*p_addr + i))[j].name_list = (char **)malloc(sizeof(char *) * 3);
			(*(*p_addr + i))[j].name_list[0] = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].name_list[1] = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].name_list[2] = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].skill_info[0].skill_name = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].skill_info[1].skill_name = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].skill_info[2].skill_name = (char *)malloc(sizeof(char) * 20);
		}
	}

	f1 = fopen("c:\\toy\\memo.txt", "r");
	//f1 = fopen("/Users/KDH/C_Programming/Pokemon/result.txt", "r");
	if (f1 == NULL) {
		printf("파일열기 실패\n");
		exit(1);
	}
		while (!feof(f1)) {
			for (k = 0; k < BOOK_ROW; k++) {
				for (l = 0; l < BOOK_COL; l++) {
					fscanf(f1, "%s", (*p_addr)[k][l].name_list[0]);
					fscanf(f1, "%s", (*p_addr)[k][l].name_list[1]);
					fscanf(f1, "%s", (*p_addr)[k][l].name_list[2]);
					fscanf(f1, "%d", &(*p_addr)[k][l].attribute);
					fscanf(f1, "%d", &(*p_addr)[k][l].power);
					fscanf(f1, "%d", &(*p_addr)[k][l].max_hp);
					fscanf(f1, "%s", (*p_addr)[k][l].skill_info[0].skill_name);
					fscanf(f1, "%d", &(*p_addr)[k][l].skill_info[0].type);
					fscanf(f1, "%s", (*p_addr)[k][l].skill_info[1].skill_name);
					fscanf(f1, "%d", &(*p_addr)[k][l].skill_info[1].type);
					fscanf(f1, "%s", (*p_addr)[k][l].skill_info[2].skill_name);
					fscanf(f1, "%d", &(*p_addr)[k][l].skill_info[2].type);
					printf("확인용%s\n", (*p_addr)[k][l].name_list[0]);
					printf("확인용%s\n", (*p_addr)[k][l].name_list[1]);
					printf("확인용%s\n", (*p_addr)[k][l].name_list[2]);
					printf("확인용%d\n", (*p_addr)[k][l].attribute);
					printf("확인용%d\n", (*p_addr)[k][l].power);
					printf("확인용%d\n", (*p_addr)[k][l].max_hp);
					printf("확인용%s\n", (*p_addr)[k][l].skill_info[0].skill_name);
					printf("확인용%d\n", (*p_addr)[k][l].skill_info[0].type);
					printf("확인용%s\n", (*p_addr)[k][l].skill_info[1].skill_name);
					printf("확인용%d\n", (*p_addr)[k][l].skill_info[1].type);
					printf("확인용%s\n", (*p_addr)[k][l].skill_info[2].skill_name);
					printf("확인용%d\n", (*p_addr)[k][l].skill_info[2].type);

					/*l++;
					if (l == 4) {
						k++;
						l = 0;
					}*/
				}
			}
			
		}
	
	fclose(f1);
	return 0;
}

// show pokemon book
void show_pokemon_book(Pokemon ***p_addr) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%s %s %s %d %d %d %d %d %d %d %s %s %s\n", (*p_addr)[i][j].name_list[0], (*p_addr)[i][j].name_list[1], (*p_addr)[i][j].name_list[2],
				(*p_addr)[i][j].attribute, (*p_addr)[i][j].power, (*p_addr)[i][j].hp, (*p_addr)[i][j].max_hp, (*p_addr)[i][j].exp,
				(*p_addr)[i][j].level, (*p_addr)[i][j].revolution, (*p_addr)[i][j].skill_info[0].skill_name, (*p_addr)[i][j].skill_info[1].skill_name,
				(*p_addr)[i][j].skill_info[0].skill_name);
		}
	}
}

// 공격 스킬
void attack_skill(char skill_name[], int i, Pokemon *x, Pokemon *y) {
	int damage;
	if (i == 1) damage = x->power * 1.2;
	else if (i == 2) damage = x->power * 1.4;
	else if (i == 3) damage = x->power * 1.6;
	if (x->attribute == 1) {
		if (y->attribute == 2) damage *= 1.25;
		else if (y->attribute == 4 || y->attribute == 5) damage *= 0.75;
	}
	else if (x->attribute == 2) {
		if (y->attribute == 3) damage *= 1.25;
		else if (y->attribute == 1 || y->attribute == 5) damage *= 0.75;
	}
	else if (x->attribute == 3) {
		if (y->attribute == 4) damage *= 1.25;
		else if (y->attribute == 2 || y->attribute == 5) damage *= 0.75;
	}
	else if (x->attribute == 4) {
		if (y->attribute == 1) damage *= 1.25;
		else if (y->attribute == 3 || y->attribute == 5) damage *= 0.75;
	}

	printf("%s의 %s!\n", x->name, skill_name);
	y->hp -= damage;
	printf("%s는 %d의 데미지를 입었다.\n", y->name, damage);
	printf("%s의 남은 hp는 %d!\n", y->name, y->hp);
}

// 힐 스킬
void heal_skill(char skill_name[], int i, Pokemon *x, void *y) {
	int heal;
	heal = x->power * 1.1;

	printf("%s의 %s!\n", x->name, skill_name);
	if (x->max_hp - x->hp <= heal) x->hp = x->max_hp;
	else x->hp += heal;
	printf("%s는 %d의 hp를 회복했다.\n", x->name, heal);
}


// skill setting
void skill_setting(Pokemon ***p_addr) {
	int i, j, k;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			for (k = 0; k<3; k++) {
				if ((*p_addr)[i][j].skill_info->type == 0) (*p_addr)[i][j].skill[k] = attack_skill;
				else (*p_addr)[i][j].skill[k] = heal_skill;
			}
		}
	}

}

// pokemon setting(name, power, hp)
void pokemon_setting(Pokemon *p_addr) {
	int tmp;
	if ((*p_addr).level < 5) {
		(*p_addr).name = p_addr->name_list[0];
	}
	else if ((*p_addr).level < 5) {
		(*p_addr).name = p_addr->name_list[1];

	}
	else {
		(*p_addr).name = p_addr->name_list[0];
	}
	tmp = pow(1.1, (*p_addr).level - 1);
	(*p_addr).power *= tmp;
	(*p_addr).max_hp *= tmp;
	(*p_addr).hp = (*p_addr).max_hp;
}


Pokemon random_pokemon(Player *player_addr, Pokemon ***pokemon_book_addr) {
	int i=0, j=0;
	Pokemon pokemon = { 0 };
	srand((unsigned)time(NULL));
	i = rand() % BOOK_ROW;
	j = rand() % BOOK_COL;
	pokemon = (*pokemon_book_addr)[i][j];
	pokemon.name = "꼬부기";//pokemon.name_list[0];
	pokemon.level = ((*player_addr).badge) * 2 + 1;
	printf("세팅으로 갑시다.\n");
	pokemon_setting(&pokemon);
	return pokemon;
}

//플레이어 공간생성
Player *make_player(Player *player) {
	player = malloc(sizeof(Player) * PLAYER_NUM);
	if (player == NULL) {
		      printf("할당실패");
	}
	else {
		     printf("플레이어공간 할당성공\n");
		memset(player, 0x0, sizeof(Player)*PLAYER_NUM);
	}
	player->name = (char*)malloc(sizeof(char) * MAX_NAME);
	if (player->name == NULL) {
		        printf("이름공간 할당 실패\n");
	}
	else {
		        printf("이름공간 할당성공\n");
		memset(player->name, 0x0, sizeof(char) * MAX_NAME);
	}
	return player;
}

//포켓몬 공간 생성
Pokemon* make_pokemon(Pokemon* pokemon) {
	pokemon = (Pokemon*)malloc(sizeof(Pokemon) * 1);
	if (pokemon == NULL) {
		     printf("포켓몬공간 할당실패\n");
	}
	else {
		      printf("포켓몬 공간 할당성공\n");
		memset(pokemon, 0x0, sizeof(Pokemon) * 1);
	}
	return pokemon;
}
//포켓몬 정보 설정
void set_pokemon_info(Player* player, Pokemon ***pokemon_book_addr) {
	int i=0;
	printf("1. 피츄 2. 꼬부기 3. 파이리\n");
	Sleep(200);
	printf("포켓몬을 선택하시오 : ");
	scanf("%d", &i);

	switch (i) {
	case 1:
		(*player).battle_pokemon[0] = (*pokemon_book_addr)[3][0];
	
		(*player).battle_pokemon[0].level = 1;
		pokemon_setting(&(*player).battle_pokemon[0]);
		
		break;
	case 2:
		(*player).battle_pokemon[0] = (*pokemon_book_addr)[0][0];
		(*player).battle_pokemon[0].level = 1;
		pokemon_setting(&(*player).battle_pokemon[0]);
		break;
	case 3:
		(*player).battle_pokemon[0] = (*pokemon_book_addr)[1][0];
		(*player).battle_pokemon[0].level = 1;
		pokemon_setting(&(*player).battle_pokemon[0]);
		break;
	}
}


//인벤토리 공간 생성
Inventory* make_inventory(Inventory* inventory) {
	inventory = (Inventory*)malloc(sizeof(Inventory) * 1);
	if (inventory == NULL) {
		//        printf("인벤토리공간 할당실패");
	}
	else {
		//        printf("인벤토리공간 할당성공\n");
		memset(inventory, 0x0, sizeof(Inventory) * 1);
	}
	return inventory;
}

//인벤토리 정보 설정
void set_inventory_info(Player *player) {
	player->inventory->monster_ball = MONSTER_BALL;
	Sleep(200);
	//    printf("포켓볼 %d개를 획득하였습니다.\n", player->inventory->monster_ball);
	Sleep(200);
}

//플레이어 정보 설정
void set_player_info(Player *player, Pokemon ***pokemon_book_addr) {
	Pokemon* pokemon = { 0 };
	Inventory* inventory = { 0 };

	printf("(오박사) 자네의 이름은 무엇인가? ");
	scanf("%s", player->name);
	printf("(오박사) 반갑네, %s! 이 여정에 함께할 포켓몬을 선택하게 해주겠네\n", player->name);
	Sleep(200);

	//포켓몬 공간 생성
	pokemon = make_pokemon(player->battle_pokemon);

	//포켓몬 공간을 플레이어 공간에 연결
	player->battle_pokemon = pokemon;

	//포켓몬 정보 설정
	set_pokemon_info(player, pokemon_book_addr);

	    printf("(오박사) 이제 여정에 필요한 캐시와 몬스터볼을 주겠네\n");
	player->cash = CASH;
	    printf("캐시 %d원을 획득하였습니다.\n", player->cash);
	Sleep(200);

	//인벤토리 공간 설정
	inventory = make_inventory(inventory);
	//인벤토리 공간을 플레이어 공간에 연결
	player->inventory = inventory;

	//인벤토리 정보 설정
	set_inventory_info(player);
}

// battle pokemon 체력 확인
int check_pokemon_hp(Player *p1, int n)   //포켓몬이 한마리라도 살아있으면 1, 다 죽었으면 2를 리턴.
{
	int i;
	for (i = 0; i<n; i++) {
		if (p1->battle_pokemon[i].hp <= 0)
		{
			p1->battle_pokemon[i].hp = 0;
			return 2;
		}
	}
	return 1;
}



int main() {
	int error;
	Pokemon **pokemon_book = NULL; // 포켓몬 도감
	Player *player = NULL; // 플레이어

						   // 포켓몬 도감 만들기
	error = make_pokemon_book(&pokemon_book); // 포켓몬 도감 만들기
	if (error == 1) {
		exit(1);
	}
	
	skill_setting(&pokemon_book); // 포켓몬 도감에 스킬 배당

								  // 플레이어 만들기
	player = make_player(player); // 플레이어 생성
	set_player_info(player, &pokemon_book); // 플레이어 정보 입력

	printf("==============설정 완료=============\n");

	Pokemon x = { 0 };
	x = random_pokemon(player, &pokemon_book); // 포켓몬 랜덤 생성
	printf("왜안되네\n");
	printf("플레이어의 뱃지개수 : %d\n", player->badge);
	printf("랜덤포켓몬의 이름 : %s\n", x.name_list[0]);
	x.skill[0](x.skill_info[0].skill_name, 1, &x, player->battle_pokemon);
	//    fighting(player, &x);
}