//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <memory.h>
//#include <math.h>
////#include <unistd.h>
//#include <Windows.h>
//
//#pragma once
//#define MAX_NAME 10
//#define PLAYER_NUM 1
//#define MONSTER_BALL 3
//#define CASH 10000
//
//
//#define VILLAGE_ROW 3
//#define VILLAGE_COL 3
//#define BATTLE_ROW 4
//#define BATTLE_COL 4
//#define MIX 1000
//#define ARSIZE 100
//#define BATTLE_POKEMON_COUNT 6
//#define BAG_NUM 2
//#define BAG_ROW 4
//#define BOSS_NUM 5
//enum start_pokemon { ggobugi = 1, pichu, fire }; //���α�, ����, ���̸�. switch������ ������ ���̱� ����
//
//												 //������ ����
//												 //typedef struct pokemon {
//												 //	char *name;
//												 //	int attribute;
//												 //	int power;
//												 //	int hp;
//												 //	int max_hp;
//												 //	int exp; // �ʿ� ����ġ = level * 2
//												 //	int level;
//												 //	int revolution; // �߰�, �⺻ 0
//												 //	void(*skill[3])(char skill_name[], int num, void *, void *);
//												 //}Pokemon;
//typedef struct skill_info {
//	char *skill_name;
//	int type; // 0 = attack, 1 = heal
//}SkillInfo;
//
//typedef struct pokemon {
//	char **name_list;
//	char *name;
//	int attribute;
//	int power;
//	int hp;
//	int max_hp;
//	int exp; // �ʿ� ����ġ = level * 2
//	int level;
//	int revolution;
//	SkillInfo skill_info[3];
//	void(*skill[3])(char skill_name[], int num, void *, void *);
//}Pokemon;
//typedef struct inventory {
//	int monster_ball;
//	int evolution_stone;
//	int medicine;
//}Inventory;
//
//typedef struct player {
//	char *name;
//	int cash;
//	int badge;
//	Inventory *inventory;
//	Pokemon *battle_pokemon;
//	Pokemon ***pokemon_bag; //������ �ִ� ���ϸ� ����
//	int pres_level; // ü���� ����
//}Player;
//
////����
////typedef struct pokemon_book {
////	char **name;
////	int attribute;
////	int power;
////	int max_hp;
////	char **skill;
////}Pokemon_book;
//
//typedef struct skill {
//	char *skill1;
//	char *skill2;
//	char *skill3;
//}Skill;
//
////
////enum start_pokemon { ggobugi = 1, pichu, fire }; //���α�, ����, ���̸�. switch������ ������ ���̱� ����
////
////typedef struct skill_info {
////	char *skill_name;
////	int type; // 0 = attack, 1 = heal
////}SkillInfo;
////
////typedef struct pokemon {
////	char **name_list;
////	char *name;
////	int attribute;
////	int power;
////	int hp;
////	int max_hp;
////	int exp; // �ʿ� ����ġ = level * 2
////	int level;
////	int revolution;
////	SkillInfo skill_info[3];
////	void(*skill[3])(char skill_name[], int num, void *, void *);
////}Pokemon;
////
////typedef struct inventory {
////	int monster_ball;
////	int evolution_stone;
////	int medicine;
////}Inventory;
////
////typedef struct player {
////	char *name;
////	int cash;
////	int badge;
////	Inventory *inventory;
////	Pokemon *battle_pokemon;
////	Pokemon **pokemon_bag; //������ �ִ� ���ϸ� ����
////	int pres_level; // ü���� ����
////}Player;
//
//
//
//// ���ϸ� ���� column �����
//int makeCol(Pokemon ***p_addr, int col) {
//	*p_addr = (Pokemon **)malloc(sizeof(Pokemon *) * col);
//
//	if (*p_addr == NULL) {
//		printf("�Ҵ� ����\n");
//		return 1;
//	}
//	memset(*p_addr, 0x0, sizeof(Pokemon *) * col);
//	return 0;
//}
//
//// ���ϸ� ���� row �����
//int makeRow(Pokemon **p_addr, int row) {
//	*p_addr = (Pokemon *)malloc(sizeof(Pokemon) * row);
//
//	if (*p_addr == NULL) {
//		printf("�Ҵ� ����\n");
//		return 1;
//	}
//	memset(*p_addr, 0x0, sizeof(Pokemon) * row);
//	return 0;
//}
//
//// ���ϸ� ���� �����
//int make_pokemon_book(Pokemon ***p_addr) {
//	int malloc_fail;
//	int i, j, k = 0, l = 0;
//	FILE *f1;
//
//	malloc_fail = makeCol(p_addr, 4);
//	if (malloc_fail == 1) {
//		printf("���� �Ҵ��� �����߽��ϴ�.\n");
//		return malloc_fail;
//	}
//	for (i = 0; i < 4; i++) {
//		malloc_fail = makeRow(*p_addr + i, 4);
//		if (malloc_fail == 1) {
//			printf("���� �Ҵ��� �����߽��ϴ�.\n");
//			return malloc_fail;
//		}
//		else for (j = 0; j<4; j++) {
//			(*(*p_addr + i))[j].name_list = (char **)malloc(sizeof(char *) * 3);
//			(*(*p_addr + i))[j].name_list[0] = (char *)malloc(sizeof(char) * 20);
//			(*(*p_addr + i))[j].name_list[1] = (char *)malloc(sizeof(char) * 20);
//			(*(*p_addr + i))[j].name_list[2] = (char *)malloc(sizeof(char) * 20);
//			(*(*p_addr + i))[j].skill_info[0].skill_name = (char *)malloc(sizeof(char) * 20);
//			(*(*p_addr + i))[j].skill_info[1].skill_name = (char *)malloc(sizeof(char) * 20);
//			(*(*p_addr + i))[j].skill_info[2].skill_name = (char *)malloc(sizeof(char) * 20);
//		}
//	}
//	f1 = fopen("/Users/KDH/C_Programming/Pokemon/result.txt", "r");
//	if (f1 != NULL) {
//		while (!feof(f1)) {
//			fscanf(f1, "%s", (*p_addr)[k][l].name_list[0]);
//			fscanf(f1, "%s", (*p_addr)[k][l].name_list[1]);
//			fscanf(f1, "%s", (*p_addr)[k][l].name_list[2]);
//			fscanf(f1, "%d", &(*p_addr)[k][l].attribute);
//			fscanf(f1, "%d", &(*p_addr)[k][l].power);
//			fscanf(f1, "%d", &(*p_addr)[k][l].max_hp);
//			fscanf(f1, "%s", (*p_addr)[k][l].skill_info[0].skill_name);
//			fscanf(f1, "%d", &(*p_addr)[k][l].skill_info[0].type);
//			fscanf(f1, "%s", (*p_addr)[k][l].skill_info[1].skill_name);
//			fscanf(f1, "%d", &(*p_addr)[k][l].skill_info[1].type);
//			fscanf(f1, "%s", (*p_addr)[k][l].skill_info[2].skill_name);
//			fscanf(f1, "%d", &(*p_addr)[k][l].skill_info[2].type);
//			l++;
//			if (l == 4) {
//				k++;
//				l = 0;
//			}
//		}
//	}
//	return 0;
//}
//
//// show pokemon book
//void show_pokemon_book(Pokemon ***p_addr) {
//	int i, j;
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			printf("%s %s %s %d %d %d %d %d %d %d %s %s %s\n", (*p_addr)[i][j].name_list[0], (*p_addr)[i][j].name_list[1], (*p_addr)[i][j].name_list[2],
//				(*p_addr)[i][j].attribute, (*p_addr)[i][j].power, (*p_addr)[i][j].hp, (*p_addr)[i][j].max_hp, (*p_addr)[i][j].exp,
//				(*p_addr)[i][j].level, (*p_addr)[i][j].revolution, (*p_addr)[i][j].skill_info[0].skill_name, (*p_addr)[i][j].skill_info[1].skill_name,
//				(*p_addr)[i][j].skill_info[0].skill_name);
//		}
//	}
//}
//
//// ���� ��ų
//void attack_skill(char skill_name[], int i, Pokemon *x, Pokemon *y) {
//	int damage;
//	if (i == 1) damage = x->power * 1.2;
//	else if (i == 2) damage = x->power * 1.4;
//	else if (i == 3) damage = x->power * 1.6;
//	if (x->attribute == 1) {
//		if (y->attribute == 2) damage *= 1.25;
//		else if (y->attribute == 4 || y->attribute == 5) damage *= 0.75;
//	}
//	else if (x->attribute == 2) {
//		if (y->attribute == 3) damage *= 1.25;
//		else if (y->attribute == 1 || y->attribute == 5) damage *= 0.75;
//	}
//	else if (x->attribute == 3) {
//		if (y->attribute == 4) damage *= 1.25;
//		else if (y->attribute == 2 || y->attribute == 5) damage *= 0.75;
//	}
//	else if (x->attribute == 4) {
//		if (y->attribute == 1) damage *= 1.25;
//		else if (y->attribute == 3 || y->attribute == 5) damage *= 0.75;
//	}
//
//	printf("%s�� %s!\n", x->name, skill_name);
//	y->hp -= damage;
//	printf("%s�� %d�� �������� �Ծ���.\n", y->name, damage);
//	printf("%s�� ���� hp�� %d!\n", y->name, y->hp);
//}
//
//// �� ��ų
//void heal_skill(char skill_name[], int i, Pokemon *x, void *y) {
//	int heal;
//	heal = x->power * 1.1;
//
//	printf("%s�� %s!\n", x->name, skill_name);
//	if (x->max_hp - x->hp <= heal) x->hp = x->max_hp;
//	else x->hp += heal;
//	printf("%s�� %d�� hp�� ȸ���ߴ�.\n", x->name, heal);
//}
//
//
//// skill setting
//void skill_setting(Pokemon ***p_addr) {
//	int i, j, k;
//	for (i = 0; i<4; i++) {
//		for (j = 0; j<4; j++) {
//			for (k = 0; k<3; k++) {
//				if ((*p_addr)[i][j].skill_info->type == 0) (*p_addr)[i][j].skill[k] = attack_skill;
//				else (*p_addr)[i][j].skill[k] = heal_skill;
//			}
//		}
//	}
//
//}
//
//// pokemon setting(name, power, hp)
//void pokemon_setting(Pokemon *p_addr) {
//	int tmp;
//	if ((*p_addr).level < 5) {
//		(*p_addr).name = p_addr->name_list[0];
//	}
//	else if ((*p_addr).level < 5) {
//		(*p_addr).name = p_addr->name_list[1];
//
//	}
//	else {
//		(*p_addr).name = p_addr->name_list[0];
//	}
//	tmp = pow(1.1, (*p_addr).level - 1);
//	(*p_addr).power *= tmp;
//	(*p_addr).max_hp *= tmp;
//	(*p_addr).hp = (*p_addr).max_hp;
//}
//
//
//Pokemon random_pokemon(Player *player_addr, Pokemon ***p_addr) {
//	int i, j;
//	Pokemon pokemon = { 0 };
//	srand((unsigned)time(NULL));
//	i = rand() % 5;
//	j = rand() % 5;
//	pokemon = (*p_addr)[i][j];
//	pokemon.level = ((*player_addr).badge) * 2 + 1;
//	pokemon_setting(&pokemon);
//	return pokemon;
//}
//
////�÷��̾� ��������
//Player *make_player(Player *player) {
//	player = malloc(sizeof(Player) * PLAYER_NUM);
//	if (player == NULL) {
//		//        printf("�Ҵ����");
//	}
//	else {
//		//        printf("�÷��̾���� �Ҵ缺��\n");
//		memset(player, 0x0, sizeof(Player)*PLAYER_NUM);
//	}
//	player->name = (char*)malloc(sizeof(char) * MAX_NAME);
//	if (player->name == NULL) {
//		//        printf("�̸����� �Ҵ� ����\n");
//	}
//	else {
//		//        printf("�̸����� �Ҵ缺��\n");
//		memset(player->name, 0x0, sizeof(char) * MAX_NAME);
//	}
//	return player;
//}
//
////���ϸ� ���� ����
//Pokemon* make_pokemon(Pokemon* pokemon) {
//	pokemon = (Pokemon*)malloc(sizeof(Pokemon) * 1);
//	if (pokemon == NULL) {
//		//        printf("���ϸ���� �Ҵ����");
//	}
//	else {
//		//        printf("���ϸ� ���� �Ҵ缺��\n");
//		memset(pokemon, 0x0, sizeof(Pokemon) * 1);
//	}
//	return pokemon;
//}
//
////���ϸ� ���� ����
//void set_pokemon_info(Player* player, Pokemon ***pokemon_book_addr) {
//	printf("1. ���α�, 2. ����, 3. ���̸�\n");
//	Sleep(200000);
//	printf("���ϸ��� �����Ͻÿ� : ");
//	scanf("%d", &(player->battle_pokemon->attribute));
//	//���Ͽ��� �о���� ������ ���α�, ����, ���̸��� ������ ����
//	switch (player->battle_pokemon->attribute) {
//	case ggobugi:
//		//�ƽ�Ű��Ʈ �ϼ��Ǹ� ���ϸ� ������ ���ϸ� �ƽ�Ű��Ʈ ���
//
//
//		//attribute
//		//player->pokemon->attribute = (*pokemon_book_addr)[0][0].attribute;
//
//		//name(*(*p_addr + i))[j]//(*(*pokemon_book_addr + 0))[0].//(*((*pokemon_book_addr)+0)+0)
//		player->battle_pokemon->name = (*pokemon_book_addr)[0][0].name_list[0];
//
//		//max_hp (�ʱ� hp�� ����)
//		player->battle_pokemon->max_hp = (*pokemon_book_addr)[0][0].max_hp;
//		//hp
//		player->battle_pokemon->hp = player->battle_pokemon->max_hp;
//
//		//power
//		player->battle_pokemon->power = (*pokemon_book_addr)[0][0].power;
//		//skill
//
//		break;
//	case pichu:
//		//attribute
//		//player->pokemon->attribute = (*pokemon_book_addr)[3][0].attribute;
//
//		//name
//		player->battle_pokemon->name = (*pokemon_book_addr)[3][0].name_list[0];
//		//max_hp (�ʱ� hp�� ����)
//		player->battle_pokemon->max_hp = (*pokemon_book_addr)[3][0].max_hp;
//		//hp
//		player->battle_pokemon->hp = player->battle_pokemon->max_hp;
//
//		//power
//		player->battle_pokemon->power = (*pokemon_book_addr)[3][0].power;
//		//skill
//		break;
//	case fire:
//		//attribute
//		//player->pokemon->attribute = (*pokemon_book_addr)[1][0].attribute;
//
//		//name
//		player->battle_pokemon->name = (*pokemon_book_addr)[1][0].name_list[0];
//		//max_hp (�ʱ� hp�� ����)
//		player->battle_pokemon->max_hp = (*pokemon_book_addr)[1][0].max_hp;
//		//hp
//		player->battle_pokemon->hp = player->battle_pokemon->max_hp;
//
//		//power
//		player->battle_pokemon->power = (*pokemon_book_addr)[1][0].power;
//		//skill
//		break;
//	}
//
//	// �������� �ϼ��Ǹ� �Ӽ����� �ƴ� �̸��� ����ϵ��� ��������
//	//    printf("���ϸ� �Ӽ��� : %d\n", player->battle_pokemon->attribute);
//	Sleep(200000);
//
//}
//
//
////�κ��丮 ���� ����
//Inventory* make_inventory(Inventory* inventory) {
//	inventory = (Inventory*)malloc(sizeof(Inventory) * 1);
//	if (inventory == NULL) {
//		//        printf("�κ��丮���� �Ҵ����");
//	}
//	else {
//		//        printf("�κ��丮���� �Ҵ缺��\n");
//		memset(inventory, 0x0, sizeof(Inventory) * 1);
//	}
//	return inventory;
//}
//
////�κ��丮 ���� ����
//void set_inventory_info(Player *player) {
//	player->inventory->monster_ball = MONSTER_BALL;
//	Sleep(200000);
//	//    printf("���Ϻ� %d���� ȹ���Ͽ����ϴ�.\n", player->inventory->monster_ball);
//	Sleep(200000);
//}
//
////�÷��̾� ���� ����
//void set_player_info(Player *player, Pokemon ***pokemon_book_addr) {
//	Pokemon* pokemon = { 0 };
//	Inventory* inventory = { 0 };
//
//	printf("(���ڻ�) �ڳ��� �̸��� �����ΰ�? ");
//	scanf("%s", player->name);
//	printf("(���ڻ�) �ݰ���, %s! �� ������ �Բ��� ���ϸ��� �����ϰ� ���ְڳ�\n", player->name);
//	Sleep(200000);
//
//	//���ϸ� ���� ����
//	pokemon = make_pokemon(player->battle_pokemon);
//
//	//���ϸ� ������ �÷��̾� ������ ����
//	player->battle_pokemon = pokemon;
//
//	//���ϸ� ���� ����
//	set_pokemon_info(player, pokemon_book_addr);
//
//	//    printf("(���ڻ�) ���� ������ �ʿ��� ĳ�ÿ� ���ͺ��� �ְڳ�\n");
//	player->cash = CASH;
//	//    printf("ĳ�� %d���� ȹ���Ͽ����ϴ�.\n", player->cash);
//	Sleep(200000);
//
//	//�κ��丮 ���� ����
//	inventory = make_inventory(inventory);
//	//�κ��丮 ������ �÷��̾� ������ ����
//	player->inventory = inventory;
//
//	//�κ��丮 ���� ����
//	set_inventory_info(player);
//}
//
//// battle pokemon ü�� Ȯ��
//int check_pokemon_hp(Player *p1, int n)   //���ϸ��� �Ѹ����� ��������� 1, �� �׾����� 2�� ����.
//{
//	int i;
//	for (i = 0; i<n; i++) {
//		if (p1->battle_pokemon[i].hp <= 0)
//		{
//			p1->battle_pokemon[i].hp = 0;
//			return 2;
//		}
//	}
//	return 1;
//}
//
//
//
////int main() {
////	int error;
////	Pokemon **pokemon_book = NULL; // ���ϸ� ����
////	Player *player = NULL; // �÷��̾�
////
////						   // ���ϸ� ���� �����
////	error = make_pokemon_book(&pokemon_book); // ���ϸ� ���� �����
////	skill_setting(&pokemon_book); // ���ϸ� ������ ��ų ���
////
////								  // �÷��̾� �����
////	player = make_player(player); // �÷��̾� ����
////	set_player_info(player, &pokemon_book); // �÷��̾� ���� �Է�
////
////	printf("==============���� �Ϸ�=============\n");
////
////	Pokemon x;
////	x = random_pokemon(player, &pokemon_book); // ���ϸ� ���� ����
////	printf("%d\n", player->badge);
////	printf("%s\n", x.name);
////	x.skill[0](x.skill_info[0].skill_name, 1, &x, player->battle_pokemon);
////	//    fighting(player, &x);
////}
//int main() {
//	int village[VILLAGE_ROW][VILLAGE_COL] = { 0 };
//	int hunt_field[BATTLE_ROW][BATTLE_COL];
//	int start = 0;
//	int start_point = 0;
//
//	Player *player = NULL;
//	Player *boss = NULL;
//	Pokemon **pokemon_book = NULL; // ���ϸ� ����
//	//Skill **skill_book = NULL; // ��ų ����
//	int error; // �Ҵ��� �ȵ� �� 1
//	int i = 0;
//	//Player player = { 0 };
//	//main_ui();
//	error = make_pokemon_book(&pokemon_book); 
//	skill_setting(&pokemon_book); // ���ϸ� ������ ��ų ���
//
//	start_point = main_UI();
//	system("cls");
//	if (start_point == 1) {
//		player = make_player(&player);
//
//		boss = make_boss(boss);
//
//		//random_pokemon(Player *player_addr, Pokemon ***p_addr)
//		//	pokemon_setting(boss->battle_pokemon);
//
//		make_bag_group(&(player->pokemon_bag), BAG_NUM);
//		make_bag_row(&(player->pokemon_bag), BAG_ROW);
//		make_bag_col(&player->pokemon_bag);
//		print_bag(player->pokemon_bag);
//		Sleep(1000);
//		system("cls");
//		Sleep(1000);
//		set_player_info(player, &pokemon_book);
//
//
//		printf("==============���� �Ϸ�=============\n");
//
//		Pokemon x;
//		x = random_pokemon(player, &pokemon_book); // ���ϸ� ���� ����
//		printf("%d\n", player->badge);
//		printf("%s\n", x.name);
//		x.skill[0](x.skill_info[0].skill_name, 1, &x, player->battle_pokemon);
//
//
//		start = print_player(player);
//
//	}
//	else if (start_point != 1) { exit(1); }
//
//	//error = make_pokemon_book(&pokemon_book);
//	/*
//	if (error == 1) exit(1);
//	printf("%s\n", pokemon_book[0][0].name1);
//	printf("%s\n", pokemon_book[0][0].name2);
//	printf("%s\n", pokemon_book[0][0].name3);
//
//	error = make_skill_book(&skill_book);
//	if (error == 1) exit(1);
//	printf("%s\n", skill_book[4][0].skill1);
//	printf("%s\n", skill_book[4][0].skill2);
//	printf("%s\n", skill_book[4][0].skill3);
//	*/
//	system("cls");
//
//	if (start == 1) make_village(village, player);
//	else exit(1);
//
//
//	make_hunt_field(hunt_field);
//	mix_hunt_field(hunt_field);
//	int x = 13, y = 13;
//	gotoxy(x, y);
//	while (1) {
//
//		if (GetAsyncKeyState(VK_UP)) {
//			if (y != 0)y -= 1;
//			pokemon_center(player);
//			make_village(village, player);
//			y += 1;
//		}
//		if (GetAsyncKeyState(VK_DOWN)) {
//			if (y != 3)y += 1;
//			system("cls");
//			supermarket(player);
//
//			make_village(village, player);
//			y -= 1;
//
//		}
//		if (GetAsyncKeyState(VK_RIGHT)) {
//			if (x != 3)x += 2;
//			system("cls");
//			//break;
//			show_hunt_field(hunt_field); // �����
//			moving(hunt_field);
//			system("cls");
//			make_village(village, player);
//			x -= 2;
//
//		}
//		if (GetAsyncKeyState(VK_LEFT)) {
//			if (x != 0)x -= 2;
//			system("cls");
//			//battle_gym(player, )
//		}
//		gotoxy(x, y);
//		Sleep(500);
//	}
//
//
//	/*
//	show_hunt_field(hunt_field);
//	x = 11, y = 11;
//	gotoxy(x, y);
//	int t;
//	while (1) {
//	//x = getX();
//	//y = getY();
//	int i = 0, j = 0;
//	if (GetAsyncKeyState(VK_UP)) {
//	if (y != 0)y -= 1, j-=1;
//
//	}
//	if (GetAsyncKeyState(VK_DOWN)) {
//	if (y != 3)y += 1, j+=1;
//
//	}
//	if (GetAsyncKeyState(VK_RIGHT)) {
//	if (x != 3)x += 2, i+=1;
//	}
//	if (GetAsyncKeyState(VK_LEFT)) {
//	if (x != 0)x -= 2, i-=1;
//	}
//	gotoxy(x, y);
//	if (hunt_field[i][j] == 1) {
//	system("cls");
//	printf("BATTLE\n");
//	if (t == 1) show_hunt_field(hunt_field);
//	}
//	Sleep(500);
//	}*/
//}
