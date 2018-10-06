#include"BreakBrick.h"
#include<time.h>
BreakBrick* g_game;
int main(int argc, char* argv[])
{
	srand(time(NULL));
	g_game = new BreakBrick();
	g_game->init("BreakBrick", 100, 100, 480, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}