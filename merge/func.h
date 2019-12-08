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
// 플레이어 정보 전부 출력
int print_player(Player *player);
void skill(char skill_name[], int i, Pokemon *x, Pokemon *y);
void pokemon_center(Player *player);
// 포켓몬 hunt시 잡을때 저장 함수
void store_pokemon(Player* player, Pokemon* stored_pokemon);
// 가방에 있는 포켓몬 보는 함수.
void print_bag(Pokemon*** group);
// 가방의 3차원 공간 생성.
void make_bag_group(Pokemon**** group_addr, int size);
// 가방 3차원중 행 할당
void make_bag_row(Pokemon**** group_addr, int size);
// 가방 3차원 중 열 할당
void make_bag_col(Pokemon**** group_addr);
void healing(Player *p1);
void using_backpack(Player *p1, Pokemon *temp_pokemon);
void fighting(Player *p1, Pokemon *temp_pokemon);
int monster_ball_fail_or_success(Pokemon *temp_pokemon);
// 마을에서 상점
void supermarket(Player *player);
// 채윢헌 ㄱ헌정 보존 어아탬 사용
void using_backpack_gym(Player *p1);
//포켓몬 전부 사망했는지 여부
int check_pokemon_hp(Player *p1, int n);
// 체육관 관장 힐링 - 싸움 전에 사용
void boss_healing(Player *boss, Player *p1);

int change_pokemon(Player *p1);
//관장이랑 싸우기
void battle_gym(Player *p1, Player *boss);
int searching_monster(int hunt_field[4][4]);
void set_gym_pokemon(Player *boss);
// 포켓몬 도감 column 만들기
int make_book_row(Pokemon ***p_addr);
// 포켓몬 도감 row 만들기
int make_book_col(Pokemon ***p_addr);
// 포켓몬 도감 만들기
int make_pokemon_book(Pokemon ***p_addr);
// 포켓몬 도감에 존해하는 변수중에 할당이 필요한 것들 세팅
void make_book_col_element(Pokemon ***pokemon_book_addr);

// show pokemon book
void show_pokemon_book(Pokemon ***p_addr);
// 공격 스킬
void attack_skill(char skill_name[], int i, Pokemon *x, Pokemon *y);
// 힐 스킬
void heal_skill(char skill_name[], int i, Pokemon *x, void *y);
// skill setting
void skill_setting(Pokemon ***p_addr);
// pokemon setting(name, power, hp)
void pokemon_setting(Pokemon *p_addr);
Pokemon random_pokemon(Player *player_addr, Pokemon ***pokemon_book_addr);
//플레이어 공간생성
Player *make_player(Player *player);
//포켓몬 공간 생성
Pokemon* make_pokemon(Pokemon* pokemon);
//포켓몬 정보 설정
void set_pokemon_info(Player* player, Pokemon ***pokemon_book_addr);
//인벤토리 공간 생성
Inventory* make_inventory(Inventory* inventory);
//인벤토리 정보 설정
void set_inventory_info(Player *player);
//플레이어 정보 설정
void set_player_info(Player *player, Pokemon ***pokemon_book_addr);



