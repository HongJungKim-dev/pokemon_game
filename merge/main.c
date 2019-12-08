#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main() {
	int village[VILLAGE_ROW][VILLAGE_COL] = { 0 };
	int hunt_field[BATTLE_ROW][BATTLE_COL];
	int start = 0;
	int start_point = 0;
	int j = 0;

	Player *player = NULL;
	Player *boss = NULL;
	Pokemon **pokemon_book = NULL; // 포켓몬 도감
	SkillInfo **skill_book = NULL; // 스킬 도감
	int error; // 할당이 안될 때 1
	int i = 0;
	//Player player = { 0 };
	//main_ui();

	//pokemon_book = make_pokemon_book(&pokemon_book);
	error = make_pokemon_book(&pokemon_book);
	for (i = 0; i < BOOK_ROW; i++) {
		for (j = 0; j < BOOK_COL; j++) {

			printf("기본 : %s, 진화1: %s, 진화2: %s\n", (pokemon_book)[i][j].name_list[0], (pokemon_book)[i][j].name_list[1], (pokemon_book)[i][j].name_list[2]);
			printf("스킬1 :%s, 스킬2: %s, 스킬3 : %s\n", (pokemon_book)[i][j].skill_info[0].skill_name, (pokemon_book)[i][j].skill_info[1].skill_name, (pokemon_book)[i][j].skill_info[1].skill_name);

		}
		printf("\n");
	}
	Sleep(5000);
	system("cls");
	/*for (i = 0; i < BOOK_ROW; i++) {
		for (j = 0; j < BOOK_COL; j++) {
			(pokemon_book)[i][j].name_list = (char **)malloc(sizeof(char *) * 3);
			(pokemon_book)[i][j].name_list[0] = (char *)malloc(sizeof(char) * 20);
			(pokemon_book)[i][j].name_list[1] = (char *)malloc(sizeof(char) * 20);
			(pokemon_book)[i][j].name_list[2] = (char *)malloc(sizeof(char) * 20);
			(pokemon_book)[i][j].skill_info[0].skill_name = (char *)malloc(sizeof(char) * 20);
			(pokemon_book)[i][j].skill_info[1].skill_name = (char *)malloc(sizeof(char) * 20);
			(pokemon_book)[i][j].skill_info[2].skill_name = (char *)malloc(sizeof(char) * 20);
			printf("기본 : %s, 진화1: %s, 진화2: %s\n", &(pokemon_book)[i][j].name_list[0], &(pokemon_book)[i][j].name_list[1], &(pokemon_book)[i][j].name_list[2]);
			printf("스킬1 :%s, 스킬2: %s, 스킬3 : %s\n", &(pokemon_book)[i][j].skill_info[0].skill_name, (pokemon_book)[i][j].skill_info[1].skill_name, (pokemon_book)[i][j].skill_info[1].skill_name);

		}
		printf("\n");
	}*/

	start_point = main_UI();
	system("cls");
	if (start_point == 1) {
		player = make_player(&player);

		boss = make_boss(boss);

		//random_pokemon(Player *player_addr, Pokemon ***p_addr);
		//pokemon_setting(boss->battle_pokemon);

		make_bag_group(&(player->pokemon_bag), BAG_NUM);
		make_bag_row(&(player->pokemon_bag), BAG_ROW);
		make_bag_col(&player->pokemon_bag);
		print_bag(player->pokemon_bag);
		Sleep(1000);
		system("cls");
		Sleep(1000);
		set_player_info(player, &pokemon_book);
		start = print_player(player);

	}
	else if (start_point != 1) { exit(1); }

	//error = make_pokemon_book(&pokemon_book);
	/*
	if (error == 1) exit(1);
	printf("%s\n", pokemon_book[0][0].name1);
	printf("%s\n", pokemon_book[0][0].name2);
	printf("%s\n", pokemon_book[0][0].name3);

	error = make_skill_book(&skill_book);
	if (error == 1) exit(1);
	printf("%s\n", skill_book[4][0].skill1);
	printf("%s\n", skill_book[4][0].skill2);
	printf("%s\n", skill_book[4][0].skill3);
	*/
	system("cls");

	if (start == 1) make_village(village, player);
	else exit(1);


	make_hunt_field(hunt_field);
	mix_hunt_field(hunt_field);
	int x = 13, y = 13;
	gotoxy(x, y);
	while (1) {

		if (GetAsyncKeyState(VK_UP)) {
			if (y != 0)y -= 1;
			pokemon_center(player);
			make_village(village, player);
			y += 1;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (y != 3)y += 1;
			system("cls");
			supermarket(player);

			make_village(village, player);
			y -= 1;

		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (x != 3)x += 2;
			system("cls");
			//break;
			show_hunt_field(hunt_field); // 사냥터
			moving(hunt_field, player, &pokemon_book);
			system("cls");
			make_village(village, player);
			x -= 2;

		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (x != 0)x -= 2;
			system("cls");
			//battle_gym(player, )
		}

		if (GetAsyncKeyState(VK_CONTROL)) {
			
		}

		gotoxy(x, y);
		Sleep(500);
	}
	

	/*
	show_hunt_field(hunt_field);
	x = 11, y = 11;
	gotoxy(x, y);
	int t;
	while (1) {
		//x = getX();
		//y = getY();
		int i = 0, j = 0;
		if (GetAsyncKeyState(VK_UP)) {
			if (y != 0)y -= 1, j-=1;

		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (y != 3)y += 1, j+=1;

		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (x != 3)x += 2, i+=1;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (x != 0)x -= 2, i-=1;
		}
		gotoxy(x, y);
		if (hunt_field[i][j] == 1) {
			system("cls");
			printf("BATTLE\n");
			if (t == 1) show_hunt_field(hunt_field);
		}
		Sleep(500);
	}*/
}
