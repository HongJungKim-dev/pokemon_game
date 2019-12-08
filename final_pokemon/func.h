#include "data_type.h"

//�÷��̾� ��������
Player *make_player(Player *player);

//���ϸ� ���� ����
Pokemon* make_pokemon(Pokemon* pokemon);

//�κ��丮 ���� ����
Inventory* make_inventory(Inventory* inventory);

//�÷��̾� ���� ����
void set_player_info(Player *player);

//���ϸ� ���� ����
void set_pokemon_info(Player *player);

//�κ��丮 ���� ����
void set_inventory_info(Player *player);

//�÷��̾� ���� ���� ���
void print_player(Player *player);

//ü���������� �ο�
void battle_gym(Player p1,Pokemon pokemon_dic);

//���
void hunt(Player p1,char hunt_field[4][4],Pokemon pokemon_dic);

void gotoxy(int x,int y);			//gotoxy �Լ� �⺻

int getX();                    // Ŀ���� x ��ǥ�� ��������


int getY();                    // Ŀ���� y��ǥ�� ��������

void moving(int huntfield[4][4]);	//�⺻������ ���������� �ϴ� �Լ�--huntfield������ ��밡��

void battle_gym(Player p1,Player *boss);	//ü���� ����--�̿�


int check_pokemon_hp(Player p1,int n);	//���ϸ��� �Ѹ����� ��������� 1, �� �׾����� 2�� ����.


int searching_monster(int hunt_field[4][4]);	//huntfield���� ����ִ� ���͸� �˻� �� �׾����� 0, �ϳ��� ���������� 1�� ����


int monster_ball_fail_or_success(Pokemon temp_pokemon);		//���ͺ��� ��������, ���͸� ���� Ȯ��. ������ 1. ���н� 0�� ����


void catch_pokemon(Player p1,Pokemon *temp_pokemon);		//���ϸ��� ����� ���, ���� ���ϸ��� ������ �̵���Ű�� �Լ�


rand_pokemon *random_pokemon(Pokemon **pokemon_dic,Pokemon *temp_pokemon);		
//�������� ���ϸ��� �����ϴ� �Լ�. 2������ �� �����Ͷ� rand_pokemon�̶�� ����ü�� ���� �������.

void fighting();		//�̿ϼ�


void hunt(Player p1,int hunt_field[4][4],Pokemon **pokemon_dic);		//���ϸ���--�̿ϼ�

