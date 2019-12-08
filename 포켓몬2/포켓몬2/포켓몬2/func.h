#pragma once
#include "data_type.h"

int main_UI();
void init();
void gotoxy(int x, int y);
int getX();
int getY();
void moving(int huntfield[4][4]);
void gotoxy_menu(int x, int y);
void setcolor(int color, int bgcolor);
int get_only_num(char arr[ARSIZE]);
int str2num(char i[ARSIZE]);
int get_num(int n);
void make_village(int village[VILLAGE_ROW][VILLAGE_COL], Player *player);
void make_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]);
void mix_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]);
void show_hunt_field(int hunt_field[BATTLE_ROW][BATTLE_COL]);

//�÷��̾� ��������
Player* make_player(Player *player_addr);

//���ϸ� ���� ����
Pokemon* make_pokemon(Pokemon* pokemon);

//�κ��丮 ���� ����
Inventory* make_inventory(Inventory* inventory);

//�÷��̾� ���� ����
void set_player_info(Player *player, Pokemon ***pokemon_book_addr);

//���ϸ� ���� ����
void set_pokemon_info(Player *player, Pokemon ***pokemon_book_addr);

//�κ��丮 ���� ����
void set_inventory_info(Player *player);

//�÷��̾� ���� ���� ���
int print_player(Player *player);

// ���ϸ� ���� �����
//Pokemon **make_pokemon_dic();

int make_pokemon_book(Pokemon ***p_addr);

// ���ϸ� ���� row �����
int makeRow(Pokemon **p_addr, int row);

// ���ϸ� ���� column �����
int makeCol(Pokemon ***p_addr, int col);

//int make_skill_book(Skill ***p_addr);

void skill(char skill_name[], int i, Pokemon *x, Pokemon *y);
void pokemon_center(Player *player);
void store_pokemon(Player* player, Pokemon* stored_pokemon);

void print_bag(Pokemon*** group);
void make_bag_group(Pokemon**** group_addr, int size);

void using_backpack(Player *p1, Pokemon *temp_pokemon);
void fighting(Player *p1, Pokemon *temp_pokemon);
void healing(Player *p1);
int monster_ball_fail_or_success(Pokemon *temp_pokemon);
void supermarket(Player *player);
void using_backpack_gym(Player *p1);
int check_pokemon_hp(Player *p1, int n);
void boss_healing(Player *boss, Player *p1);

int change_pokemon(Player *p1);
void battle_gym(Player *p1, Player *boss);
void pokemon_setting(Pokemon **p_addr);
Pokemon random_pokemon(Player *player_addr, Pokemon ***p_addr);
Player *make_boss(Player *player);