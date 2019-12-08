#pragma once
#include "data_type.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <memory.h>
#include "func.h"
#include <conio.h>

int main_UI() {
	int i = 0;
	int x = 9, y = 2;
	char chrsel[ARSIZE] = { '\0' };
	//int numsize = 0;
	//int sel = 0;
	//double level = 0.0;
	int level = 0;

	setcolor(15, 0);
	gotoxy_menu(x, y);
	setcolor(12, 0);
	printf("��");
	for (i = 0; i < 29; i++) {
		setcolor(15, 0);
		printf("--");
	}
	setcolor(12, 0);
	printf("��");

	for (i = 1; i < 22; i++) {
		y++;
		setcolor(15, 0);
		gotoxy_menu(x, y);
		printf("|");
		if (i == 8) {
			setcolor(14, 0);
			gotoxy_menu(30, i);
			printf("\t�� ���ϸ��� �� \n\n\n\n\n\n\t\t\t\t 1. �����ϱ� \n\n\n\t\t\t\t 2. �̾��ϱ� \n  ");




		}

		x += 61;
		setcolor(15, 0);
		gotoxy_menu(x, y);
		printf("|");
		x = 9;
	}
	setcolor(12, 0);
	gotoxy_menu(x, y);
	printf("��");
	setcolor(15, 0);
	for (i = 0; i < 29; i++)
		printf("--");
	setcolor(12, 0);
	printf("�� \n\n");
	setcolor(15, 0);

	printf("\t\t ���ϴ� ��带 �Է��ϰ� ���͸� �����ּ��� : ");

	level = get_num('2'); //1,2�� �Է¹޴� �Լ�
	return level;
}

void init() {
	system("mode con cols=100 lines = 50 | title ��������");
}

void gotoxy(int x, int y) {
	COORD pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy_menu(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int getX()                    // Ŀ���� x ��ǥ�� ��������
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}
int getY()                    // Ŀ���� y��ǥ�� ��������
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

void moving(int huntfield[4][4],Player* player, Pokemon** pokemon_book)
{
	int y = 11;
	int x = 11;
	int SIZE = 1;
	int i = 0, j = 0;
	//while (huntfield[x][y] == 0) {
	while (1) {
		if (i == 3 && j == 3) {
			
		}
		if (GetAsyncKeyState(VK_UP)) {
			if (y != 0)y -= 1, j -= 1;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (y != 3)y += 1, j += 1;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (x != 3)x += 2, i += 1;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (x != 0)x -= 2, i -= 1;
		}
		if (GetAsyncKeyState(VK_TAB)) {
			Sleep(500);
			system("cls");
			printf("BATTLE !!!\n");
			Sleep(100);
			system("cls");
			Pokemon x = { 0 };
			x = random_pokemon(player, &pokemon_book); // ���ϸ� ���� ����

			
			printf("�÷��̾��� �������� : %d\n", player->badge);
			//printf("�������ϸ��� �̸� : %s\n", x.name_list[0]);
			printf("�������ϸ��� �̸� : %s\n", x.name);
			x.skill[0](x.skill_info[0].skill_name, 1, &x, player->battle_pokemon);
			/*Sleep(500);
			system("cls");
			printf("BTTLE\n");*/

		}
		gotoxy(x, y);
		Sleep(500);
		/*
		if (huntfield[i][j] == 1) {
			fighting();
		}*/
	}
}
/*
void moving_village(int village[VILLAGE_ROW][VILLAGE_COL]) {
	int SIZE = 1;
	int x = 0;
	int y = 0;
	while (village[x][y] == 0) {
		x = getX();
		y = getY();
		if (GetAsyncKeyState(VK_UP)) {
			if (y != 0)y -= 1;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (y != 3)y += 1;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (x != 3)x += 1;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (x != 0)x -= 1;
		}
		gotoxy(x, y);
		Sleep(500);
	}
}
*/
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

int get_only_num(char arr[ARSIZE])
{
	int numsize = 0;
	int i = 0;
	char c = '\0';
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n') break;
		else
			arr[numsize] = c;
		numsize++;

	}
	return numsize;
}

int str2num(char i[ARSIZE])
{
	int k = 0;
	k = i[0] - 48;
	return k;
}

int get_num(int n) {
	int i = 0;
	char num = '\0';
	char num1 = '\0';
	while (1) {
		while (1) {
			scanf("%c", &num1);

			if (num1 == '\n') break;
			else {
				num = num1;
				i++;
			}
			if (i == 1 && num >= '1'&&num <= n)
				return ((int)num - 48);
			else {
				printf("�߸��� �Է��Դϴ� 1,2 �� �ϳ��� �Է����ּ��� \n");
				i = 0;
			}

		}
	}
}

void make_village(int village[VILLAGE_ROW][VILLAGE_COL], Player *player) {
	int i, j;
	gotoxy(10, 10);
	if (player->badge == 0) {
		printf("�巡�� ��Ƽ�� �°��� ȯ���մϴ�\n");
		printf("��: ���ϸ� ����, ��: �����,  ��: ����,  ��: ü����");
	}
	for (i = 0; i < VILLAGE_ROW; i++) {
		for (j = 0; j < VILLAGE_COL; j++) {
			gotoxy(11 + i * 2, 12 + j);
			if ((i == 0) && (j == 1)) {
				village[i][j] = 1;
				printf("��");
			}
			else if (i == 1 && j == 2) {
				village[i][j] = 2;
				printf("��");
			}
			else if (i == 1 && j == 0) {
				village[i][j] = 3;
				printf("��");
			}
			else if (i == 2 && j == 1) {
				village[i][j] = 4;
				printf("��");
			}
			else {
				village[i][j] = 5;
				printf("��");
			}
		}printf("\n");
	}

	int x = 0, y = 0;
	//moving_village(village[VILLAGE_ROW][VILLAGE_COL]);
}

void make_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]) {
	int i = 0, j = 0;
	int cnt = 0;
	for (i = 0; i < BATTLE_ROW; i++) {
		for (j = 0; j < BATTLE_COL; j++) {
			cnt++;
			if (i == 0 && j == 0) {
				hunt_field[i][j] = 0;
				cnt--;
			}
			else if (i == 3 && j == 3) {
				hunt_field[i][j] = 0;
				cnt--;
			}
			else if (cnt > 8) {
				hunt_field[i][j] = 0;
			}
			else {
				hunt_field[i][j] = 1;
			}
		}
	}
}

void mix_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]) {
	int i = 0, j = 0, k = 0, l = 0, m = 0;
	int temp = 0;
	for (k = 0; k < MIX; k++) {
		i = rand() % BATTLE_ROW;
		j = rand() % BATTLE_COL;
		l = rand() % BATTLE_ROW;
		m = rand() % BATTLE_COL;
		if ((i != 0 && j != 0 && l != 0 && m != 0) && (i != 3 && j != 3 && l != 3 && m != 3)) {
			temp = hunt_field[i][j];
			hunt_field[i][j] = hunt_field[l][m];
			hunt_field[l][m] = temp;
		}
	}
}

void show_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]) {
	int i, j;
	//gotoxy(10, 10);
	for (i = 0; i < BATTLE_ROW; i++) {
		for (j = 0; j < BATTLE_COL; j++) {
			//printf("%d", hunt_field[i][j]);
			gotoxy(11 + i * 2, 11 + j);
			if (hunt_field[i][j] == 1) printf("��");
			else if (hunt_field[i][j] == 0) printf("��");
		}
		printf("\n");
	}
}


Player *make_boss(Player *player) {
	player = (Player*)malloc(sizeof(Player) * BOSS_NUM);
	if (player == NULL) {
		printf("�������� �Ҵ����\n");
	}
	else {
		printf("�������� �Ҵ缺��\n");
		memset(player, 0x0, sizeof(Player)*BOSS_NUM);
	}
	//���߿� �÷��̾��� ��Ʋ���ϸ� �����Ǵ� �� ������ �Ȱ��Ƽ� �Լ� �и� �õ��غ���
	player->battle_pokemon = (Pokemon*)malloc(sizeof(Pokemon)*BATTLE_POKEMON_COUNT);
	if (player->battle_pokemon == NULL) {
		printf("��Ʋ���ϸ���� �Ҵ����\n");

	}
	else {
		printf("��Ʋ���ϸ���� �Ҵ缺��\n");
		memset(player->battle_pokemon, 0x0, sizeof(Pokemon)*BATTLE_POKEMON_COUNT);
	}

	player->name = (char*)malloc(sizeof(char) * MAX_NAME);
	if (player->name == NULL) {
		printf("�̸����� �Ҵ� ����\n");
	}
	else {
		printf("�̸����� �Ҵ缺��\n");
		memset(player->name, 0x0, sizeof(char) * MAX_NAME);
	}
	return player;
}

//
////���Ϸ� ���� �޾ƿ� ���ϸ� �Ͽ��� ���ϸ� ����
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

//�÷��̾� ���� ���� ���
int print_player(Player *player) {
	int i = 0;
	//�÷��̾� ����
	printf("===================�÷��̾� ����===================\n");
	Sleep(200);
	printf("�÷��̾� �̸� : %s, �÷��̾� ĳ�� : %d\n", player->name, player->cash);
	Sleep(200);
	printf("���� ���� : %d, ���ͺ� ���� : %d\n", player->badge, player->inventory->monster_ball);
	Sleep(200);
	printf("��ȭ�� �� ���� : %d, HP���� ���� : %d\n", player->inventory->evolution_stone, player->inventory->medicine);
	Sleep(200);
	if (player->pokemon_bag == NULL) {
		printf("���ϰ��濡�� ���� ���ϸ��� �����ϴ�.\n");
	}
	else {
		printf("���ϰ��濡�� ()������ ���ϸ��� �ֽ��ϴ�\n");
	}
	Sleep(200);
	printf("Level : %d\n", player->pres_level);
	Sleep(200);

	//���ϸ� ����
	printf("===================���� ���ϸ� ����===================\n");
	Sleep(200);
	printf("�̸� : %s\n", player->battle_pokemon->name);
	Sleep(200);
	printf("HP : %d, POWER : %d,", player->battle_pokemon->hp, player->battle_pokemon->power);
	Sleep(200);
	printf("EXP : %d\n", player->battle_pokemon->exp);
	printf("(���ڻ�) ��ſ� ����Ǳ⸦ �ٶ�� �̸� ������߰ھ�!\n");
	Sleep(200);

	printf("������ �̵��Ͻðڽ��ϱ�?: 1. yes    2. no   : "); scanf("%d", &i);
	return i;

}
void skill(char skill_name[], int i, Pokemon *x, Pokemon *y) {
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

	printf("%s�� %s!\n", x->name, skill_name);
	y->hp -= damage;
	printf("%s�� %d�� �������� �Ծ���.\n", y->name, damage);
	printf("%s�� ���� hp�� %d!\n", y->name, y->hp);
}


void pokemon_center(Player *player) {
	int center = 0, i = 0, j = 0, k = 0;
	system("cls");
	printf("������ ���͵帱���?\n");
	printf("1. ���ϸ� ġ�� 2. ������  \n");
	printf("�����Ͻÿ�: "); scanf("%d", &center);
	while (1) {
		if (center == 1) {
			/*
			while (player->battle_pokemon[i].name != NULL) {
				player->battle_pokemon[i].hp = player->battle_pokemon[i].max_hp;
				printf("���ϸ�: %s�� ġ���߽��ϴ�\n", player->battle_pokemon[i].name);
				i++;
			}*/
			for (i = 0; i < BATTLE_POKEMON_COUNT; i++) {
				if (player->battle_pokemon[i].name != NULL) {
					player->battle_pokemon[i].hp = player->battle_pokemon[i].max_hp;
					printf("���ϸ�: %s�� %d���� ġ���߽��ϴ�\n", player->battle_pokemon[i].name, player->battle_pokemon[i].hp);

				}
				else { break; }
			}
			Sleep(1000);

			system("cls");
			return 0;
		}
		else if (center == 2) {
			Sleep(700);
			system("cls");
			return 0;
		}
	}
}

// ���ϸ� hunt�� ������ ���� �Լ�
void store_pokemon(Player* player, Pokemon* stored_pokemon) {
	int col_size = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	Pokemon**** group_addr = &(player->pokemon_bag);
	int bag_group_size = _msize(*group_addr) / sizeof(Pokemon**);
	int row_size = _msize(**group_addr) / sizeof(Pokemon*);

	for (i = 0; i < bag_group_size; i++) {
		for (j = 0; j < row_size; j++) {
			col_size = _msize(*(*((*group_addr) + i)) + j) / sizeof(Pokemon);
			for (k = 0; k < col_size; k++) {
				if ((*group_addr)[i][j][k].attribute == NULL) {
					(*group_addr)[i][j][k] = *(stored_pokemon);
					printf("%��° ������ %d �࿡ %d���� %s�� �����Ͽ����ϴ� : %d bytes.\n", i + 1, j, k, *(stored_pokemon)->name);
					break;
				}
			}
		}
	}
}

// ���濡 �ִ� ���ϸ� ���� �Լ�.
void print_bag(Pokemon*** group) {
	int i = 0, j = 0, k = 0;
	int col_size = 0;
	int bag_group_size = _msize(group) / sizeof(Pokemon**);
	int row_size = _msize(*group) / sizeof(Pokemon*);

	for (i = 0; i < bag_group_size; i++) {
		for (j = 0; j < row_size; j++) {
			col_size = _msize(*(*(group + i) + j)) / sizeof(Pokemon);
			for (k = 0; k < col_size; k++) {
				printf("%d ", group[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}
// ������ 3���� ���� ����.
void make_bag_group(Pokemon**** group_addr, int size) {
	*group_addr = (Pokemon***)malloc(sizeof(Pokemon**) * size);
	if (*group_addr == NULL) {
		printf("���ϸ󰡹� �Ҵ����");
		exit(1);
	}
	else {
		printf("���ϸ󰡹� �Ҵ缺��\n");
		memset(*group_addr, 0x0, sizeof(Pokemon ***)*size);
	}
	int bag_group_size = _msize(*group_addr) / sizeof(Pokemon**);
}
// ���� 3������ �� �Ҵ�
void make_bag_row(Pokemon**** group_addr, int size) {
	int i = 0;
	int j = 0;
	int bag_group_size = _msize(*group_addr) / sizeof(Pokemon**);
	for (i = 0; i < bag_group_size; i++) {
		*((*group_addr) + i) = (Pokemon**)malloc(sizeof(Pokemon*) * size);
		if (*((*group_addr) + i) == NULL) {
			printf("���ϸ󰡹� ����� �Ҵ����");
			exit(1);
		}
		else {
			printf("���ϸ󰡹� ����� �Ҵ缺��\n");
			memset(*((*group_addr) + i), 0x0, sizeof(Pokemon **)*size);
		}
	}
}
// ���� 3���� �� �� �Ҵ�
void make_bag_col(Pokemon**** group_addr) {
	int i = 0;
	int j = 0;
	int col_size = 0;
	int bag_group_size = _msize(*group_addr) / sizeof(Pokemon**);
	int row_size = _msize(**group_addr) / sizeof(Pokemon*);

	for (i = 0; i < bag_group_size; i++) {
		for (j = 0; j < row_size; j++) {
			printf("���ϸ� %d��° ������ %d��° ��\n", i + 1, j);
			printf("���ϸ� ���濡 ������ ���� ������ �Է��Ͻÿ� : ");
			scanf("%d", &col_size);
			*(*((*group_addr) + i) + j) = (Pokemon*)malloc(sizeof(Pokemon) * col_size);
			memset(*(*((*group_addr) + i) + j), 0x0, sizeof(Pokemon)*col_size);
			printf("%d��° ������ %d �࿡ %d���� �����Ͽ����ϴ� : %d bytes.\n", i + 1, j, _msize(*(*((*group_addr) + i) + j)) / sizeof(Pokemon), _msize(*(*((*group_addr) + i) + j)));
		}
		printf("\n");
	}
}


void healing(Player *p1)
{
	int i=0;

	printf("���� ü�� : %d", (p1->battle_pokemon + i)->hp);
	if (((p1->battle_pokemon + i)->hp) + 50 >= (p1->battle_pokemon + i)->max_hp)
		((p1->battle_pokemon + i)->hp) = ((p1->battle_pokemon + i)->max_hp);
	else
		((p1->battle_pokemon + i)->hp) += 50;
}


void using_backpack(Player *p1, Pokemon *temp_pokemon)
{
	int choosen;
	int success_or_fail;
	srand((unsigned)time(NULL));
	printf("1.���Ϻ� %d ��  2.��ó�� %d ��  3. ��ȭ�� �� %d ��", p1->inventory->monster_ball, p1->inventory->medicine, p1->inventory->evolution_stone);
	scanf("%d", &choosen);

	switch (choosen)
	{
	case 1:
		p1->inventory->monster_ball -= 1;
		success_or_fail = monster_ball_fail_or_success(temp_pokemon);
		if (success_or_fail == 1) { //������
			printf("����");
			break;
		}
		else {
			printf("����");
			break;
		}
	case 2:
		p1->inventory->medicine -= 1;
		printf("ġ�Ḧ �մϴ�,\n");
		healing(p1);
		break;
	case 3:
		printf("����� �Ұ��� �մϴ�,");
		break;
	}
}


void fighting(Player *p1, Pokemon *temp_pokemon)
{
	int manu = 0;
	int random = 0;
	int p1_win_or_lose = 0;
	int monster_win_or_lose = 0;
	while (p1_win_or_lose == 1 || monster_win_or_lose == 1) {
		printf("� �ൿ�� �Ͻðڽ��ϱ�?\n");
		printf("1.���� ���� 2.��ų 3.�������");
		scanf("%d", &manu);
		switch (manu) {
		case 1:
			printf("���� �����մϴ�. !");
			temp_pokemon->hp -= p1->battle_pokemon->power;
			printf("���� �����մϴ�.\n");
			random = rand() % 2 + 1;
			if (random == 1)
				p1->battle_pokemon->hp -= temp_pokemon->power;
			if (random == 2)
				//p1->pokemon->hp-=temp_pokemon->skill(&p1,boss);
				continue;
		case 2:
			//using_skill(p1,temp_pokemon);   //��ų ���°� �� �𸣰ڳ׿�!!      
			printf("���� �����մϴ�.\n");
			random = rand() % 2 + 1;
			if (random == 1)
				p1->battle_pokemon->hp -= temp_pokemon->power;
			if (random == 2)
				//p1->pokemon->hp-=boss->pokemon->skill(&p1,boss);
				continue;
		case 3:
			using_backpack(p1, temp_pokemon);
			printf("���� �����մϴ�.\n");
			random = rand() % 2 + 1;
			if (random == 1)
				p1->battle_pokemon->hp -= temp_pokemon->power;
			if (random == 2)
				//p1->pokemon->hp-=temp_pokemon->skill(&p1,boss);
				continue;
		}
	}
}


int monster_ball_fail_or_success(Pokemon *temp_pokemon)
{
	int percentage = 0;
	int a;
	a = 100 * (float)temp_pokemon->hp / (float)temp_pokemon->max_hp;
	printf("�ۼ�Ƽ�� %d", a);
	if (a < 30) return 1;
	else return 0;
}
// �������� ����
void supermarket(Player *player) {

	int select = 0;

	while (1) {
		if (select == 4) {
			Sleep(1000);
			system("cls");
			return 0;
		}
		printf("������ ���ðڽ��ϴ�.\n");
		printf("�� �κ��丮: ���Ϻ�: %d, HP����: %d, ��ȭ�ǵ�: %d,  �ܾ�: %d\n", player->inventory->monster_ball, player->inventory->medicine, player->inventory->evolution_stone, player->cash);
		printf("1. ���Ϻ� 3��: 1000��,  2. HP���� 3��: 1000�� , 3. ��ȭ�ǵ� 1��: 30,000  , 4.������    ����: ");
		scanf("%d", &select);

		switch (select) {
		case 1:
			if (player->cash - 1000 < 0) {
				printf("�ܾ��� �����մϴ�.");
				printf("�ڵ����� ������ �����ϴ�.");
				Sleep(1000);
				system("cls");
				return 0;
			}
			else {
				player->inventory->monster_ball += 3;
				player->cash -= 1000;
			}
			break;
		case 2:
			if (player->cash - 1000 < 0) {
				printf("�ܾ��� �����մϴ�.");
				printf("�ڵ����� ������ �����ϴ�.");
				Sleep(1000);
				system("cls");
				return 0;
			}
			else {
				player->inventory->medicine += 3;
				player->cash -= 1000;
			}
			break;
		case 3:
			if (player->cash - 30000 < 0) {
				printf("�ܾ��� �����մϴ�.");
				printf("�ڵ����� ������ �����ϴ�.");
				Sleep(500);
				system("cls");
				return 0;
			}
			else {
				player->inventory->evolution_stone += 1;
				player->cash -= 30000;
			}
			break;
		case 4:
			break;
		default:
			break;
		}

	}
}

// ä���� ������ ���� ����� ���
void using_backpack_gym(Player *p1)
{
	int choosen;
	int success_or_fail;
	srand((unsigned)time(NULL));
	printf("1.���Ϻ� %d ��  2.��ó�� %d ��  3. ��ȭ�� �� %d ��", p1->inventory->monster_ball, p1->inventory->medicine, p1->inventory->evolution_stone);
	scanf("%d", &choosen);

	switch (choosen)
	{
	case 1:
		printf("����� �Ұ��� �մϴ�,");
		break;
	case 2:
		p1->inventory->medicine -= 1;
		printf("ġ�Ḧ �մϴ�,\n");
		healing(p1);
		break;
	case 3:
		printf("����� �Ұ��� �մϴ�,");
		break;
	}
}

//���ϸ� ���� ����ߴ��� ����
int check_pokemon_hp(Player *p1, int n)   //���ϸ��� �Ѹ����� ��������� 1, �� �׾����� 2�� ����.
{
	int i;
	for (i = 0; i < n; i++) {
		if (p1->battle_pokemon[i].hp <= 0)
		{
			p1->battle_pokemon[i].hp = 0;
			return 2;
		}
	}
	return 1;
}

// ü���� ���� ���� - �ο� ���� ���
void boss_healing(Player *boss, Player *p1)
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		(boss + p1->badge)->battle_pokemon[i].hp = (boss + p1->badge)->battle_pokemon[i].max_hp;
	}
}

int change_pokemon(Player *p1)
{
	int a;
	while (1) {
		printf("�� �� �� �� �� ��ȣ�� �Է��ϼ���");
		scanf("%d", &a);
		a -= 1;
		if (p1->battle_pokemon[a].hp <= 0)
			printf("�� ���ϸ��� �����߽��ϴ�! �ٸ� ���ϸ��� �������ּ���\n");
		else
		{
			printf("���ϸ��� �ٲ�����ϴ�.\n");
			break;
		}

	}
	return a;
}

//�����̶� �ο��
void battle_gym(Player *p1, Player *boss)
{
	int manu, j, k;            //j�� ���� ���ǰ� �ִ� ���ϸ��� ��ȣ��(1~6����)
	int random;
	int p1_win_or_lose = 1;
	int boss_win_or_lose = 1;
	boss_healing(boss, p1);
	srand((unsigned)time(NULL));
	j = 0;
	k = 0;
	printf("�ο��� �����մϴ�.\n");
	while (p1_win_or_lose == 1 && boss_win_or_lose == 1) {
		printf("�ൿ�� �����ϼ��� 1. ��Ÿ  2. ��ų  3.����  4.���ϸ� ��ü\n");
		scanf("%d", &manu);

		if (manu == 1) {
			boss->battle_pokemon[k].hp -= p1->battle_pokemon[j].power;
			printf("���� �����մϴ�.\n");
			random = rand() % 2 + 1;
			if (random == 1)
				p1->battle_pokemon[j].hp -= boss->battle_pokemon[j].power;
			if (random == 2)

			{
			}//p1->battle_pokemon->hp-=boss->battle_pokemon->skill(&p1,boss);      ��ų�Լ� ��Ʈ�Դϴ�.
		}


		if (manu == 2) {
			//boss->battle_pokemon->hp-=p1->battle_pokemon->skill(&p1,boss);   ��ų�Լ� ��Ʈ�Դϴ�.
		}

		if (manu == 3) {
			using_backpack_gym(p1);
			printf("���� �����մϴ�.\n");
			random = rand() % 2 + 1;
			if (random == 1)
				p1->battle_pokemon[j].hp -= boss->battle_pokemon[j].power;
			if (random == 2)

			{
			}//p1->battle_pokemon->hp-=boss->battle_pokemon->skill(&p1,boss);      ��ų�Լ� ��Ʈ�Դϴ�.
		}

		if (manu == 4) {
			j = change_pokemon(p1);
			printf("���� �����մϴ�.\n");
			random = rand() % 2 + 1;
			if (random == 1)
				p1->battle_pokemon[j].hp -= boss->battle_pokemon[j].power;
			if (random == 2)

			{
			}//p1->battle_pokemon->hp-=boss->battle_pokemon->skill(&p1,boss);      ��ų�Լ� ��Ʈ�Դϴ�.
		}
		p1_win_or_lose = check_pokemon_hp(p1, 6);//���� �κ��� ���� �÷��̾ ������ �ִ� ���ϸ��� ������ �־�� ��.
		boss_win_or_lose = check_pokemon_hp(boss, 6);
		if (boss->battle_pokemon[k].hp <= 0)   //������ �ڽ��� 0������ ���ʷ� ���ϸ��� �����ϴ�.
			k += 1;
		if (p1->battle_pokemon[j].hp <= 0)
			change_pokemon(p1);
	}

	if (p1_win_or_lose == 2)
	{
		printf("�÷��̾��� ���ϸ��� ��� �׾����ϴ�. ���ϸ� ���ͷ� �ڵ����� �̵��˴ϴ�,");
		//���ϸ� ���� �̵� �� �Լ� Ż��(return)
		return;
	}
	if (boss_win_or_lose == 2)
	{
		printf("�¸�!");
		p1->badge += 1;
		return;
	}

}

int searching_monster(int hunt_field[4][4]) {
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++) {
			if (hunt_field[i][j] == 1)
				return 1;
		}
	}
	return 0;
}

void set_gym_pokemon(Player *boss) {

}


// ���ϸ� ���� �� �����
int make_book_row(Pokemon ***p_addr) {
	*p_addr = (Pokemon **)malloc(sizeof(Pokemon *) * BOOK_ROW);

	if (*p_addr == NULL) {
		printf("�Ҵ� ����\n");
		return 1;
	}
	memset(*p_addr, 0x0, sizeof(Pokemon *) * BOOK_ROW);
	return 0;
}

// ���ϸ� ���� �� �����
int make_book_col(Pokemon ***p_addr) {
	int i = 0, j=0;
	for (i = 0; i < BOOK_ROW; i++) {
		*((*p_addr)+i) = (Pokemon *)malloc(sizeof(Pokemon) * BOOK_COL);

		if ((*p_addr)[i] == NULL) {
			printf("�Ҵ� ����\n");
			return 1;
		}
		memset(*((*p_addr) + i), 0x0, sizeof(Pokemon) * BOOK_COL);
		

	}
}
// ���ϸ� ������ �����ϴ� �����߿� �Ҵ��� �ʿ��� �͵� ����
void make_book_col_element(Pokemon ***p_addr) {
	int i = 0, j = 0;
	for (i = 0; i < BOOK_ROW; i++) {
		for (j = 0; j < BOOK_COL; j++) {
			(*p_addr)[i][j].name_list = (char **)malloc(sizeof(char *) * 3);
			(*p_addr)[i][j].name_list[0] = (char *)malloc(sizeof(char) * 20);
			(*p_addr)[i][j].name_list[1] = (char *)malloc(sizeof(char) * 20);
			(*p_addr)[i][j].name_list[2] = (char *)malloc(sizeof(char) * 20);
			(*p_addr)[i][j].skill_info[0].skill_name = (char *)malloc(sizeof(char) * 20);
			(*p_addr)[i][j].skill_info[1].skill_name = (char *)malloc(sizeof(char) * 20);
			(*p_addr)[i][j].skill_info[2].skill_name = (char *)malloc(sizeof(char) * 20);
			//printf("����1\n");
			//(*(*((*p_addr)+i)+j)).name_list[0] = (char *)malloc(sizeof(char) * 20);
			//printf("����2\n");
			//(*(*((*p_addr) + i) + j)).name_list[1] = (char *)malloc(sizeof(char) * 20);
			////(*p_addr)[i][j].name_list[1] = (char *)malloc(sizeof(char) * 20);
			//printf("����3\n");
			//(*(*((*p_addr) + i) + j)).name_list[2] = (char *)malloc(sizeof(char) * 20);
			//printf("����4\n");
		/*	(*(*p_addr + i))[j].name_list[1] = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].name_list[2] = (char *)malloc(sizeof(char) * 20);*/
		/*	(*(*p_addr + i))[j].skill_info[0].skill_name = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].skill_info[1].skill_name = (char *)malloc(sizeof(char) * 20);
			(*(*p_addr + i))[j].skill_info[2].skill_name = (char *)malloc(sizeof(char) * 20);*/
		}
	}
	
}
// ���ϸ� ���� �����
int make_pokemon_book(Pokemon ***p_addr) {
	int malloc_fail=0;
	int i = 0, j = 0, k = 0, l = 0;
	FILE *f1=0;

	malloc_fail = make_book_row(p_addr);

	if (malloc_fail == 1) {
		printf("���� �Ҵ��� �����߽��ϴ�.\n");
		return malloc_fail;
	}


	malloc_fail = make_book_col(p_addr);
	
	if (malloc_fail == 1) {
		printf("���� �Ҵ��� �����߽��ϴ�.\n");
		return malloc_fail;
	}

	/*for (i = 0; i < BOOK_ROW; i++) {
		for (j = 0; j < BOOK_COL; j++) {
			printf("%p ",(*p_addr)[i][j]);
		}
		printf("\n");
	}*/
	make_book_col_element(p_addr);

	
	f1 = fopen("c:\\toy\\result.txt", "r");
	if (f1 == NULL) {
		printf("���Ͽ��� ����\n");
		exit(1);
	}
	while (!feof(f1)) {
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
			/*printf("Ȯ�ο�%s\n", (*p_addr)[k][l].name_list[0]);
			printf("Ȯ�ο�%s\n", (*p_addr)[k][l].name_list[1]);
			printf("Ȯ�ο�%s\n", (*p_addr)[k][l].name_list[2]);
			printf("Ȯ�ο�%d\n", (*p_addr)[k][l].attribute);
			printf("Ȯ�ο�%d\n", (*p_addr)[k][l].power);
			printf("Ȯ�ο�%d\n", (*p_addr)[k][l].max_hp);
			printf("Ȯ�ο�%s\n", (*p_addr)[k][l].skill_info[0].skill_name);
			printf("Ȯ�ο�%d\n", (*p_addr)[k][l].skill_info[0].type);
			printf("Ȯ�ο�%s\n", (*p_addr)[k][l].skill_info[1].skill_name);
			printf("Ȯ�ο�%d\n", (*p_addr)[k][l].skill_info[1].type);
			printf("Ȯ�ο�%s\n", (*p_addr)[k][l].skill_info[2].skill_name);
			printf("Ȯ�ο�%d\n", (*p_addr)[k][l].skill_info[2].type);*/
		l++;
		if (l == 4) {
			k++;
			l = 0;
		}

	}

	fclose(f1);
	return 0;
	//return *p_addr;
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

// ���� ��ų
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

	printf("%s�� %s!\n", x->name, skill_name);
	y->hp -= damage;
	printf("%s�� %d�� �������� �Ծ���.\n", y->name, damage);
	printf("%s�� ���� hp�� %d!\n", y->name, y->hp);
}

// �� ��ų
void heal_skill(char skill_name[], int i, Pokemon *x, void *y) {
	int heal;
	heal = x->power * 1.1;

	printf("%s�� %s!\n", x->name, skill_name);
	if (x->max_hp - x->hp <= heal) x->hp = x->max_hp;
	else x->hp += heal;
	printf("%s�� %d�� hp�� ȸ���ߴ�.\n", x->name, heal);
}


// skill setting
void skill_setting(Pokemon ***p_addr) {
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 3; k++) {
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
	int i = 0, j = 0;
	Pokemon pokemon = { 0 };
	srand((unsigned)time(NULL));
	i = rand() % BOOK_ROW;
	j = rand() % BOOK_COL;

	pokemon = (*pokemon_book_addr)[i][j];

	//pokemon.name = "���α�";//pokemon.name_list[0];
	pokemon.level = ((*player_addr).badge) * 2 + 1;

	pokemon_setting(&pokemon);

	return pokemon;
}

//�÷��̾� ��������
Player *make_player(Player *player) {
	player = malloc(sizeof(Player) * PLAYER_NUM);
	if (player == NULL) {
		printf("�Ҵ����");
	}
	else {
		printf("�÷��̾���� �Ҵ缺��\n");
		memset(player, 0x0, sizeof(Player)*PLAYER_NUM);
	}
	player->name = (char*)malloc(sizeof(char) * MAX_NAME);
	if (player->name == NULL) {
		printf("�̸����� �Ҵ� ����\n");
	}
	else {
		printf("�̸����� �Ҵ缺��\n");
		memset(player->name, 0x0, sizeof(char) * MAX_NAME);
	}
	return player;
}

//���ϸ� ���� ����
Pokemon* make_pokemon(Pokemon* pokemon) {
	pokemon = (Pokemon*)malloc(sizeof(Pokemon) * 1);
	if (pokemon == NULL) {
		printf("���ϸ���� �Ҵ����\n");
	}
	else {
		printf("���ϸ� ���� �Ҵ缺��\n");
		memset(pokemon, 0x0, sizeof(Pokemon) * 1);
	}
	return pokemon;
}

//���ϸ� ���� ����
void set_pokemon_info(Player* player, Pokemon ***pokemon_book_addr) {
	int i = 0;
	printf("1. ���� 2. ���α� 3. ���̸�\n");
	Sleep(200);
	printf("���ϸ��� �����Ͻÿ� : ");
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


//�κ��丮 ���� ����
Inventory* make_inventory(Inventory* inventory) {
	inventory = (Inventory*)malloc(sizeof(Inventory) * 1);
	if (inventory == NULL) {
		//        printf("�κ��丮���� �Ҵ����");
	}
	else {
		//        printf("�κ��丮���� �Ҵ缺��\n");
		memset(inventory, 0x0, sizeof(Inventory) * 1);
	}
	return inventory;
}

//�κ��丮 ���� ����
void set_inventory_info(Player *player) {
	player->inventory->monster_ball = MONSTER_BALL;
	Sleep(200);
	//    printf("���Ϻ� %d���� ȹ���Ͽ����ϴ�.\n", player->inventory->monster_ball);
	Sleep(200);
}

//�÷��̾� ���� ����
void set_player_info(Player *player, Pokemon ***pokemon_book_addr) {
	Pokemon* pokemon = { 0 };
	Inventory* inventory = { 0 };

	printf("(���ڻ�) �ڳ��� �̸��� �����ΰ�? ");
	scanf("%s", player->name);
	printf("(���ڻ�) �ݰ���, %s! �� ������ �Բ��� ���ϸ��� �����ϰ� ���ְڳ�\n", player->name);
	Sleep(200);

	//���ϸ� ���� ����
	pokemon = make_pokemon(player->battle_pokemon);

	//���ϸ� ������ �÷��̾� ������ ����
	player->battle_pokemon = pokemon;

	//���ϸ� ���� ����
	set_pokemon_info(player, pokemon_book_addr);

	printf("(���ڻ�) ���� ������ �ʿ��� ĳ�ÿ� ���ͺ��� �ְڳ�\n");
	player->cash = CASH;
	printf("ĳ�� %d���� ȹ���Ͽ����ϴ�.\n", player->cash);
	Sleep(200);

	//�κ��丮 ���� ����
	inventory = make_inventory(inventory);
	//�κ��丮 ������ �÷��̾� ������ ����
	player->inventory = inventory;

	//�κ��丮 ���� ����
	set_inventory_info(player);
}
