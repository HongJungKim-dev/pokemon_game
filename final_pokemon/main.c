#include <stdio.h>
#include "func.h"

int main() {
	Player *player = { NULL };
	Pokemon* pokemon = { 0 };

	player = make_player(player);
	player = set_player_info(player);
	print_player(player);
}