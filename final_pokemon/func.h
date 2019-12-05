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
