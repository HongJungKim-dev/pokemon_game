#pragma once
#include "data_type.h"

int main_UI();
void init();
void gotoxy(int x, int y);
void gotoxy_menu(int x, int y);
int getX();
int getY();
void moving(int huntfield[4][4], Player* player, Pokemon** pokemon_book);
void setcolor(int color, int bgcolor);
int get_only_num(char arr[ARSIZE]);
int str2num(char i[ARSIZE]);
int get_num(int n);
void make_village(int village[VILLAGE_ROW][VILLAGE_COL], Player *player);
void make_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]);
void mix_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]);
void show_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]);
Player *make_boss(Player *player);
// �÷��̾� ���� ���� ���
int print_player(Player *player);
void skill(char skill_name[], int i, Pokemon *x, Pokemon *y);
void pokemon_center(Player *player);
// ���ϸ� hunt�� ������ ���� �Լ�
void store_pokemon(Player* player, Pokemon* stored_pokemon);
// ���濡 �ִ� ���ϸ� ���� �Լ�.
void print_bag(Pokemon*** group);
// ������ 3���� ���� ����.
void make_bag_group(Pokemon**** group_addr, int size);
// ���� 3������ �� �Ҵ�
void make_bag_row(Pokemon**** group_addr, int size);
// ���� 3���� �� �� �Ҵ�
void make_bag_col(Pokemon**** group_addr);
void healing(Player *p1);
void using_backpack(Player *p1, Pokemon *temp_pokemon);
void fighting(Player *p1, Pokemon *temp_pokemon);
int monster_ball_fail_or_success(Pokemon *temp_pokemon);
// �������� ����
void supermarket(Player *player);
// ä���� ������ ���� ����� ���
void using_backpack_gym(Player *p1);
//���ϸ� ���� ����ߴ��� ����
int check_pokemon_hp(Player *p1, int n);
// ü���� ���� ���� - �ο� ���� ���
void boss_healing(Player *boss, Player *p1);

int change_pokemon(Player *p1);
//�����̶� �ο��
void battle_gym(Player *p1, Player *boss);
int searching_monster(int hunt_field[4][4]);
void set_gym_pokemon(Player *boss);
// ���ϸ� ���� column �����
int make_book_row(Pokemon ***p_addr);
// ���ϸ� ���� row �����
int make_book_col(Pokemon ***p_addr);
// ���ϸ� ���� �����
int make_pokemon_book(Pokemon ***p_addr);
// ���ϸ� ������ �����ϴ� �����߿� �Ҵ��� �ʿ��� �͵� ����
void make_book_col_element(Pokemon ***pokemon_book_addr);

// show pokemon book
void show_pokemon_book(Pokemon ***p_addr);
// ���� ��ų
void attack_skill(char skill_name[], int i, Pokemon *x, Pokemon *y);
// �� ��ų
void heal_skill(char skill_name[], int i, Pokemon *x, void *y);
// skill setting
void skill_setting(Pokemon ***p_addr);
// pokemon setting(name, power, hp)
void pokemon_setting(Pokemon *p_addr);
Pokemon random_pokemon(Player *player_addr, Pokemon ***pokemon_book_addr);
//�÷��̾� ��������
Player *make_player(Player *player);
//���ϸ� ���� ����
Pokemon* make_pokemon(Pokemon* pokemon);
//���ϸ� ���� ����
void set_pokemon_info(Player* player, Pokemon ***pokemon_book_addr);
//�κ��丮 ���� ����
Inventory* make_inventory(Inventory* inventory);
//�κ��丮 ���� ����
void set_inventory_info(Player *player);
//�÷��̾� ���� ����
void set_player_info(Player *player, Pokemon ***pokemon_book_addr);



