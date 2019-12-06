#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>
#include "data_type.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>

void gotoxy(int x,int y)			//gotoxy �Լ� �⺻.
{
COORD pos={x,y};
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


void moving(int huntfield[4][4])
{
	int y=0;
	int x=0;
	int SIZE=1;
		while (huntfield[x][y]==0) {
			x=getX();
			y=getY();
			if (GetAsyncKeyState(VK_UP)) {
				if(y!=0)y -= 1;
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				if(y!=3)y += 1;
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				if(x!=3)x += 1;
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				if(x!=0)x -= 1;
			}
			gotoxy(x, y);
			Sleep(500);
		}
}

void moving_village(int village[3][3])
{
	int y=0;
	int x=0;
	int SIZE=1;
		while (village[x][y]==0) {
			x=getX();
			y=getY();
			if (GetAsyncKeyState(VK_UP)) {
				//����
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				//���ϼ���
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				//ü����
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				//����� ����
			}
			gotoxy(x, y);
			Sleep(500);
		}
}

//�÷��̾� ��������
Player *make_player(Player *player) {
	player =(Player *) malloc(sizeof(Player) * PLAYER_NUM);
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
	pokemon = (Pokemon*) malloc(sizeof(Pokemon) * 6);
	if (pokemon == NULL) {
		printf("���ϸ���� �Ҵ����");
	}
	else {
		printf("���ϸ� ���� �Ҵ缺��\n");
		memset(pokemon, 0x0, sizeof(Pokemon) * 1);
	}
	return pokemon;
}

//�κ��丮 ���� ����
Inventory* make_inventory(Inventory* inventory) {
	inventory = (Inventory*) malloc(sizeof(Inventory) * 1);
	if (inventory == NULL) {
		printf("�κ��丮���� �Ҵ����");
	}
	else {
		printf("�κ��丮���� �Ҵ缺��\n");
		memset(inventory, 0x0, sizeof(Inventory) * 1);
	}
	return inventory;
}

//�÷��̾� ���� ����
Player *set_player_info(Player *player) {
	Pokemon* pokemon = { 0 };
	Inventory* inventory = { 0 };

	printf("(���ڻ�) �ڳ��� �̸��� �����ΰ�? ");
	scanf("%s", player->name);
	printf("(���ڻ�) �ݰ���, %s! �� ������ �Բ��� ���ϸ��� �����ϰ� ���ְڳ�\n", player->name);
	Sleep(200);

	//���ϸ� ���� ����
	pokemon = make_pokemon(player->pokemon);

	//���ϸ� ������ �÷��̾� ������ ����
	player->pokemon = pokemon;

	//���ϸ� ���� ����
	set_pokemon_info(player);

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

	printf("(���ڻ�) ��ſ� ����Ǳ⸦ �ٶ�� �̸� ������߰ھ�!\n");
	return player;
}

//���ϸ� ���� ����
void set_pokemon_info(Player* player) {
	printf("1. ���α�, 2. ����, 3. ���̸�\n");
	Sleep(200);
	printf("���ϸ��� �����Ͻÿ� : ");
	scanf("%d", &(player->pokemon->attribute));

	//���Ͽ��� �о���� ������ ���α�, ����, ���̸��� ������ ����
	switch (player->pokemon->attribute) {
	case ggobugi:
		//�ƽ�Ű��Ʈ �ϼ��Ǹ� ���ϸ� ������ ���ϸ� �ƽ�Ű��Ʈ ���


		//attribute

		//name

		//hp

		//max_hp (�ʱ� hp�� ����)

		//power

		//skill

		break;
	case pichu:
		break;
	case fire:
		break;
	}

	// �������� �ϼ��Ǹ� �Ӽ����� �ƴ� �̸��� ����ϵ��� ��������
	printf("���ϸ� �Ӽ��� : %d\n", player->pokemon->attribute);
	Sleep(200);

}

//�κ��丮 ���� ����
void set_inventory_info(Player *player) {
	player->inventory->monster_ball = MONSTER_BALL;
	Sleep(200);
	printf("���Ϻ� %d���� ȹ���Ͽ����ϴ�.\n", player->inventory->monster_ball);
	Sleep(200);
	
}

//�÷��̾� ���� ���� ���
void print_player(Player *player) {
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
	printf("�̸� : %s\n", player->pokemon->name);
	Sleep(200);
	printf("HP : %d, POWER : %d,", player->pokemon->hp, player->pokemon->power);
	Sleep(200);
	printf("EXP : %d\n", player->pokemon->exp);
	Sleep(200);
}
//
//Pokemon **make_pokemon_bag_row(Pokemon ***bag_addr) {
//	//bag_addr = malloc(sizeof)
//}
//
//Pokemon **make_pokemon_bag_col(Pokemon ***bag_addr) {
//
//}
//void make_pokemon_room(Player *p1)
//{
//	p1->pokemon=(Pokemon*)malloc(sizeof(Pokemon)*6);
//}

void select_pokemon(Player *p1)
{
	int i=0;
	int j=0;
	int k=1;
	int a=0;
	printf("����� ���� ���ϸ�!\n");

	for(j=0;j<4;j++){
	for(i=0;i<_msize(p1->pokemon_bag+j)/sizeof(p1->pokemon_bag+j);i++)
	{
		printf("%d . �̸� :%s ���ݷ� : %d ü�� : %d �ִ�ü�� :%d",k,(*(p1->pokemon_bag+i)+j)->name,(*(p1->pokemon_bag+i)+j)->power,(*(p1->pokemon_bag+i)+j)->max_hp);
		k++;	
	}
	}
	printf("��� ���ϸ��� �����ðڽ��ϱ�? (�ִ� 6����)");
	scanf("%d",&a);		

}

int check_pokemon_hp(Player p1,int n)	//���ϸ��� �Ѹ����� ��������� 1, �� �׾����� 2�� ����.
{
	for(int i=0;i<n;i++)	{
		if(p1.pokemon[i].hp>0)
			return 1;
	}
	return 2;
}

void battle_gym(Player *p1,Player *boss)
{
	int i,j;
	int random;
	int p1_win_or_lose;
	int boss_win_or_lose;
	Player boss_temp;		//�÷��̾��� ���� ���� ����
	srand((unsigned)time(NULL));
	printf("�ο��� �����մϴ�.\n");
	while(p1_win_or_lose==1||boss_win_or_lose==1)	{
	while(p1->pokemon[j].hp>0){
	printf("�ൿ�� �����ϼ��� 1. ��Ÿ  2. ��ų  3.����\n");
	scanf("%d",&i);
	if(i==1){
		boss->pokemon->hp-=p1->pokemon->power;
	}
	if(i==2){
		boss->pokemon->hp-=p1->pokemon->skill(&p1,boss);//��ų�Լ��� power ����� ����� �մϴ�.
	}
	if(i==3){
		printf("�� ������ : 1.���Ϻ� %d �� 2.��ó�� %d ��",p1->inventory->monster_ball,p1->inventory->medicine);
		
	printf("���� �����մϴ�.\n");
	random = rand()%2+1;
	if(random==1)
		p1->pokemon->hp-=boss->pokemon->power;
	if(i==2)
		p1->pokemon->hp-=boss->pokemon->skill(&p1,boss);
	}
		p1_win_or_lose=check_pokemon_hp(p1,_msize(p1.pokemon_bag)/sizeof(p1.pokemon_bag));//���� �κ��� ���� �÷��̾ ������ �ִ� ���ϸ��� ������ �־�� ��.
		boss_win_or_lose=check_pokemon_hp(boss[1],_msize(boss[1].pokemon_bag)/sizeof(boss[1].pokemon_bag));

	}
	if(p1_win_or_lose==2)
		{
			printf("�÷��̾��� ���ϸ��� ��� �׾����ϴ�. ���ϸ� ���ͷ� �ڵ����� �̵��˴ϴ�,");
			//���ϸ� ���� �̵� �� �Լ� Ż��(return)
			return;
		}
	if(boss_win_or_lose==2)
		{
			printf("�¸�!");
			p1->badge+=1;
			return;
		}

	}
}

int searching_monster(int hunt_field[4][4]){
	int i,j;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++){
				if(hunt_field[i][j]==1)
					return 1;
				}
		}
		return 0;
}



int monster_ball_fail_or_success(Pokemon *temp_pokemon)
{
	int percentage=0;
	int a;
	float i;
	a=100*(float)temp_pokemon->hp/(float)temp_pokemon->max_hp;
		percentage=rand()%(100-a) + (1+a);
		i=percentage/100;
	if(i>0.7) return 1;
	else return 0;
}


//void catch_pokemon(Player* p1,Pokemon *temp_pokemon)		//�̰��� ����ؼ� 1, 2, 3 �÷����� �ϴµ�, ���⼭ realloc �Լ��� �ʿ��մϴ�.
//{
	
		//����� ��� catch �Լ�
//		p1->pokemon_bag[1]->name=temp_pokemon->name;
//		p1->pokemon_bag[1]->power=temp_pokemon->power;
//		p1->pokemon_bag[1]->hp=temp_pokemon->hp;
//		p1->pokemon_bag[1]->max_hp=temp_pokemon->max_hp;
//		p1->pokemon_bag[1]->skill=temp_pokemon->skill;

//

rand_pokemon *random_pokemon(Pokemon **pokemon_dic,Pokemon *temp_pokemon)
{
	int i,j;
	rand_pokemon *a;
	i=rand()%0 +4;
	j=rand()%0 +4;
	a->i=i;
	a->j=j;
	(*(pokemon_dic+i)+j)->hp=temp_pokemon->hp;
	(*(pokemon_dic+i)+j)->max_hp=temp_pokemon->max_hp;
	(*(pokemon_dic+i)+j)->name=temp_pokemon->name;
	(*(pokemon_dic+i)+j)->power=temp_pokemon->power;
	(*(pokemon_dic+i)+j)->skill=temp_pokemon->skill;
	return a;
}

void using_fist(Player *p1,Pokemon temp_pokemon)
{
	
	

}

void using_skill(Player *p1,Pokemon temp_pokemon)
{

}

void healing(Player *p1)
{
	int i;

	printf("���� ü�� : %d",(p1->pokemon+i)->hp);
	if(((p1->pokemon+i)->hp)+50>=(p1->pokemon+i)->max_hp)
		((p1->pokemon+i)->hp)=((p1->pokemon+i)->max_hp);
	else
		((p1->pokemon+i)->hp)+=50;
}
	


void using_backpack(Player *p1,Pokemon *temp_pokemon)
{
	int choosen;
	int success_or_fail;
	printf("1.���Ϻ� %d ��  2.��ó�� %d ��  3. ��ȭ�� �� %d ��",p1->inventory->monster_ball,p1->inventory->medicine,p1->inventory->evolution_stone);
	scanf("%d",&choosen);

	switch(choosen)
	{
	case 1:
		p1->inventory->monster_ball-=1;
		success_or_fail=monster_ball_fail_or_success(temp_pokemon);
		if(success_or_fail==1)
			catch_pokemon(p1,temp_pokemon);
			break;
	case 2:
		p1->inventory->medicine-=1;
		printf("ġ�Ḧ �մϴ�,\n");
		healing(p1);
		break;
	case 3:
		printf("����� �Ұ��� �մϴ�,");
		break;
}
}
}

void fighting(Player *p1,Pokemon temp_pokemon)
{
	int manu;
	while(1)	{
	printf("� �ൿ�� �Ͻðڽ��ϱ�?\n");
	printf("1.���� ���� 2.��ų 3.�������");
	scanf("%d",&manu);
	switch(manu)	{
	case 1:
		using_fist(p1,temp_pokemon);
		continue;
	case 2:
		using_skill(p1,temp_pokemon);
			continue;
	case 3:
		using_backpack(p1,temp_pokemon);
		continue;
	}
	}
}



void hunt(Player p1,int hunt_field[4][4],Pokemon **pokemon_dic)
{
	int i,j;
	rand_pokemon rand;
	Pokemon *temp_pokemon;
		i=0,j=0;
	while(1)	{
		while(hunt_field[i][j]!=0)
	{
		moving(hunt_field);
	}
		// fighting  �Լ�.

	i=searching_monster(hunt_field);		//hunt_field���� �����ִ� ���ϸ��� ã�� �Լ�
	if(i==0)	{
		printf("�ʵ忡 �ִ� ��� ���͸� ����߽��ϴ�. ������ ���ư��ϴ�.");
	return;
	}



			}

}
