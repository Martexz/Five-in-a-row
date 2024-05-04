#include "rules.cpp"

using namespace std;

int main()
{
	initgraph(700, 700, NOMINIMIZE);
	setbkcolor(WHITE);
	cleardevice();
	setbkmode(TRANSPARENT);
	while (true)
	{
		init();
		MainGame();
		cleardevice();
	}
	return 0;
}