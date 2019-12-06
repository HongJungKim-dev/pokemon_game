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

void gotoxy(int x,int y)			//gotoxy 함수 기본.
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int getX()                    // 커서의 x 좌표를 가져오기
{
   CONSOLE_SCREEN_BUFFER_INFO BufInfo;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
   return BufInfo.dwCursorPosition.X;
}
int getY()                    // 커서의 y좌표를 가져오기
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


//플레이어 공간생성
Player *make_player(Player *player) {
	player =(Player *) malloc(sizeof(Player) * PLAYER_NUM);
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
Player *set_player_info(Player *player) {
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


int check_pokemon_hp(Player p1,int n)	//포켓몬이 한마리라도 살아있으면 1, 다 죽었으면 2를 리턴.
{
	for(int i=0;i<n;i++)	{
		if(p1.pokemon[i].hp>0)
			return 1;
	}
	return 2;
}

void battle_gym(Player p1,Player *boss)
{
	int i,j;
	int random;
	int p1_win_or_lose;
	int boss_win_or_lose;

	srand((unsigned)time(NULL));
	printf("싸움을 시작합니다.\n");
	while(p1_win_or_lose==1||boss_win_or_lose==1)	{
	while(p1.pokemon[j].hp>0){
	printf("행동을 선택하세요 1. 평타  2. 스킬  3.가방\n");
	scanf("%d",&i);
	if(i==1){
		boss->pokemon->hp-=p1.pokemon->power;
	}
	if(i==2){
		boss->pokemon->hp-=p1.pokemon->skill(&p1,boss);//스킬함수에 power 배수를 해줘야 합니다.
	}
	if(i==3){
		printf("쓸 아이템 : 1.포켓볼 %d 개 2.상처약 %d 개",p1.inventory->monster_ball,p1.inventory->medicine);
		
	printf("적이 공격합니다.\n");
	random = rand()%2+1;
	if(random==1)
		p1.pokemon->hp-=boss->pokemon->power;
	if(i==2)
		p1.pokemon->hp-=boss->pokemon->skill(&p1,boss);
	}
		p1_win_or_lose=check_pokemon_hp(p1,_msize(p1.pokemon_bag)/sizeof(p1.pokemon_bag));//정수 부분은 현재 플레이어가 가지고 있는 포켓몬의 갯수를 넣어야 함.
		boss_win_or_lose=check_pokemon_hp(boss[1],_msize(boss[1].pokemon_bag)/sizeof(boss[1].pokemon_bag));

	}
	if(p1_win_or_lose==2)
		{
			printf("플레이어의 포켓몬이 모두 죽었습니다. 포켓몬 센터로 자동으로 이동됩니다,");
			//포켓몬 센터 이동 및 함수 탈출(return)
			return;
		}
	if(boss_win_or_lose==2)
		{
			printf("승리!");
			p1.badge+=1;
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



int monster_ball_fail_or_success(Pokemon temp_pokemon)
{
	int percentage=0;
	int a;
	float i;
	a=100*(float)temp_pokemon.hp/(float)temp_pokemon.max_hp;
		percentage=rand()%(100-a) + (1+a);
		i=percentage/100;
	if(i>0.7) return 1;
	else return 0;
}


void catch_pokemon(Player p1,Pokemon *temp_pokemon)
{
	
		//잡았을 경우 catch 함수
		p1.pokemon_bag[1]->name=pokemon_dic.name;
		p1.pokemon_bag[1]->power=pokemon_dic.power;
		p1.pokemon_bag[1]->hp=pokemon_dic.hp;
		p1.pokemon_bag[1]->max_hp=pokemon_dic.max_hp;
		p1.pokemon_bag[1]->skill=pokemon_dic.skill;

}

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

void fighting();

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
		// fighting  함수.

	i=searching_monster(hunt_field);		//hunt_field에서 남아있는 포켓몬을 찾는 함수
	if(i==0)	{
		printf("필드에 있는 모든 몬스터를 사냥했습니다. 마을로 돌아갑니다.");
	return;
	}



			}

}
