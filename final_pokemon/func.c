#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "func.h"

//플레이어 공간생성
Player *make_player(Player *player) {
	player = malloc(sizeof(Player) * PLAYER_NUM);
	if (player == NULL) {
		printf("할당실패");
	}
	else {
		printf("플레이어공간 할당성공\n");
		memset(player, 0x0, sizeof(Player)*PLAYER_NUM);
	}
	player->name = (char*)malloc(sizeof(char) * MAX_NAME);
	if (player->name == NULL) {
		printf("이름공간 할당 실패\n");
	}
	else {
		printf("이름공간 할당성공\n");
		memset(player->name, 0x0, sizeof(char) * MAX_NAME);
	}
	return player;
}

//포켓몬 공간 생성
Pokemon* make_pokemon(Pokemon* pokemon) {
	pokemon = (Pokemon*) malloc(sizeof(Pokemon) * 1);
	if (pokemon == NULL) {
		printf("포켓몬공간 할당실패");
	}
	else {
		printf("포켓몬 공간 할당성공\n");
		memset(pokemon, 0x0, sizeof(Pokemon) * 1);
	}
	return pokemon;
}

//인벤토리 공간 생성
Inventory* make_inventory(Inventory* inventory) {
	inventory = (Inventory*) malloc(sizeof(Inventory) * 1);
	if (inventory == NULL) {
		printf("인벤토리공간 할당실패");
	}
	else {
		printf("인벤토리공간 할당성공\n");
		memset(inventory, 0x0, sizeof(Inventory) * 1);
	}
	return inventory;
}

//플레이어 정보 설정
void set_player_info(Player *player) {
	Pokemon* pokemon = { 0 };
	Inventory* inventory = { 0 };

	printf("(오박사) 자네의 이름은 무엇인가? ");
	scanf("%s", player->name);
	printf("(오박사) 반갑네, %s! 이 여정에 함께할 포켓몬을 선택하게 해주겠네\n", player->name);
	Sleep(200);

	//포켓몬 공간 생성
	pokemon = make_pokemon(player->pokemon);

	//포켓몬 공간을 플레이어 공간에 연결
	player->pokemon = pokemon;

	//포켓몬 정보 설정
	set_pokemon_info(player);

	printf("(오박사) 이제 여정에 필요한 캐시와 몬스터볼을 주겠네\n");
	player->cash = CASH;
	printf("캐시 %d원을 획득하였습니다.\n", player->cash);
	Sleep(200);

	//인벤토리 공간 설정
	inventory = make_inventory(inventory);
	//인벤토리 공간을 플레이어 공간에 연결
	player->inventory = inventory;

	//인벤토리 정보 설정
	set_inventory_info(player);

	printf("(오박사) 즐거운 여행되기를 바라고 이만 헤어져야겠어!\n");
	return player;
}

//포켓몬 정보 설정
void set_pokemon_info(Player* player) {
	printf("1. 꼬부기, 2. 피츄, 3. 파이리\n");
	Sleep(200);
	printf("포켓몬을 선택하시오 : ");
	scanf("%d", &(player->pokemon->attribute));

	//파일에서 읽어오는 정보로 꼬부기, 피츄, 파이리의 종족값 설정
	switch (player->pokemon->attribute) {
	case ggobugi:
		//아스키아트 완성되면 포켓몬 선택후 포켓몬 아스키아트 출력


		//attribute

		//name

		//hp

		//max_hp (초기 hp와 동일)

		//power

		//skill

		break;
	case pichu:
		break;
	case fire:
		break;
	}

	// 파일정보 완성되면 속성값이 아닌 이름을 출력하도록 수정예정
	printf("포켓몬 속성값 : %d\n", player->pokemon->attribute);
	Sleep(200);

}

//인벤토리 정보 설정
void set_inventory_info(Player *player) {
	player->inventory->monster_ball = MONSTER_BALL;
	Sleep(200);
	printf("포켓볼 %d개를 획득하였습니다.\n", player->inventory->monster_ball);
	Sleep(200);
	
}

//플레이어 정보 전부 출력
void print_player(Player *player) {
	//플레이어 정보
	printf("===================플레이어 정보===================\n");
	Sleep(200);
	printf("플레이어 이름 : %s, 플레이어 캐시 : %d\n", player->name, player->cash);
	Sleep(200);
	printf("뱃지 개수 : %d, 몬스터볼 개수 : %d\n", player->badge, player->inventory->monster_ball);
	Sleep(200);
	printf("진화의 돌 개수 : %d, HP물약 개수 : %d\n", player->inventory->evolution_stone, player->inventory->medicine);
	Sleep(200);
	if (player->pokemon_bag == NULL) {
		printf("포켓가방에는 아직 포켓몬이 없습니다.\n");
	}
	else {
		printf("포켓가방에는 ()마리의 포켓몬이 있습니다\n");
	}
	Sleep(200);
	printf("Level : %d\n", player->pres_level);
	Sleep(200);

	//포켓몬 정보
	printf("===================동행 포켓몬 정보===================\n");
	Sleep(200);
	printf("이름 : %s\n", player->pokemon->name);
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

