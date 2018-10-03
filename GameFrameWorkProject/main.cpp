#include"BreakBrick.h"
BreakBrick* g_game;
int main(int argc, char* argv[])
{
	g_game = new BreakBrick();
	g_game->init("BreakBrick", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}