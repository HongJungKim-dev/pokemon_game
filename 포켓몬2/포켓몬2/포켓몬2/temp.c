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



// ���ϸ� ���� column �����
int makeCol(Pokemon ***p_addr, int col) {
	*p_addr = (Pokemon **)malloc(sizeof(Pokemon *) * col);

	if (*p_addr == NULL) {
		printf("�Ҵ� ����\n");
		return 1;
	}
	memset(*p_addr, 0x0, sizeof(Pokemon *) * col);
	return 0;
}

// ���ϸ� ���� row �����
int makeRow(Pokemon **p_addr, int row) {
	*p_addr = (Pokemon *)malloc(sizeof(Pokemon) * row);

	if (*p_addr == NULL) {
		printf("�Ҵ� ����\n");
		return 1;
	}
	memset(*p_addr, 0x0, sizeof(Pokemon) * row);
	return 0;
}

// ���ϸ� ���� �����
int make_pokemon_book(Pokemon ***p_addr) {
	int malloc_fail;
	int i=0, j=0, k = 0, l = 0;
	FILE *f1;

	malloc_fail = makeCol(p_addr, 4);
	if (malloc_fail == 1) {
		printf("���� �Ҵ��� �����߽��ϴ�.\n");
		return malloc_fail;
	}
	for (i = 0; i < 4; i++) {
		malloc_fail = makeRow(*p_addr + i, 4);
		if (malloc_fail == 1) {
			printf("���� �Ҵ��� �����߽��ϴ�.\n");
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
		printf("���Ͽ��� ����\n");
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
					printf("Ȯ�ο�%s\n", (*p_addr)[k][l].name_list[0]);
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
					printf("Ȯ�ο�%d\n", (*p_addr)[k][l].skill_info[2].type);

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
	pokemon.name = "���α�";//pokemon.name_list[0];
	pokemon.level = ((*player_addr).badge) * 2 + 1;
	printf("�������� ���ô�.\n");
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
	int i=0;
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

// battle pokemon ü�� Ȯ��
int check_pokemon_hp(Player *p1, int n)   //���ϸ��� �Ѹ����� ��������� 1, �� �׾����� 2�� ����.
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
	Pokemon **pokemon_book = NULL; // ���ϸ� ����
	Player *player = NULL; // �÷��̾�

						   // ���ϸ� ���� �����
	error = make_pokemon_book(&pokemon_book); // ���ϸ� ���� �����
	if (error == 1) {
		exit(1);
	}
	
	skill_setting(&pokemon_book); // ���ϸ� ������ ��ų ���

								  // �÷��̾� �����
	player = make_player(player); // �÷��̾� ����
	set_player_info(player, &pokemon_book); // �÷��̾� ���� �Է�

	printf("==============���� �Ϸ�=============\n");

	Pokemon x = { 0 };
	x = random_pokemon(player, &pokemon_book); // ���ϸ� ���� ����
	printf("�־ȵǳ�\n");
	printf("�÷��̾��� �������� : %d\n", player->badge);
	printf("�������ϸ��� �̸� : %s\n", x.name_list[0]);
	x.skill[0](x.skill_info[0].skill_name, 1, &x, player->battle_pokemon);
	//    fighting(player, &x);
}