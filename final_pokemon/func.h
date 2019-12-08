#include "data_type.h"

//플레이어 공간생성
Player *make_player(Player *player);

//포켓몬 공간 생성
Pokemon* make_pokemon(Pokemon* pokemon);

//인벤토리 공간 생성
Inventory* make_inventory(Inventory* inventory);

//플레이어 정보 설정
void set_player_info(Player *player);

//포켓몬 정보 설정
void set_pokemon_info(Player *player);

//인벤토리 정보 설정
void set_inventory_info(Player *player);

//플레이어 정보 전부 출력
void print_player(Player *player);

//체육관에서의 싸움
void battle_gym(Player p1,Pokemon pokemon_dic);

//사냥
void hunt(Player p1,char hunt_field[4][4],Pokemon pokemon_dic);

void gotoxy(int x,int y);			//gotoxy 함수 기본

int getX();                    // 커서의 x 좌표를 가져오기


int getY();                    // 커서의 y좌표를 가져오기

void moving(int huntfield[4][4]);	//기본적으로 움직여지게 하는 함수--huntfield에서만 사용가능

void battle_gym(Player p1,Player *boss);	//체육관 전투--미완


int check_pokemon_hp(Player p1,int n);	//포켓몬이 한마리라도 살아있으면 1, 다 죽었으면 2를 리턴.


int searching_monster(int hunt_field[4][4]);	//huntfield에서 살아있는 몬스터를 검색 다 죽었으면 0, 하나라도 남아있으면 1을 리턴


int monster_ball_fail_or_success(Pokemon temp_pokemon);		//몬스터볼을 던졌을때, 몬스터를 잡을 확률. 성공시 1. 실패시 0을 리턴


void catch_pokemon(Player p1,Pokemon *temp_pokemon);		//포켓몬을 잡았을 경우, 잡은 포켓몬의 정보를 이동시키는 함수


rand_pokemon *random_pokemon(Pokemon **pokemon_dic,Pokemon *temp_pokemon);		
//랜덤으로 포켓몬을 생성하는 함수. 2중으로 된 포인터라서 rand_pokemon이라는 구조체를 따로 만들었다.

void fighting();		//미완성


void hunt(Player p1,int hunt_field[4][4],Pokemon **pokemon_dic);		//포켓몬사냥--미완성

