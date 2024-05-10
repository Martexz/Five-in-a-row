#include "rules.cpp"

using namespace std;

int main()
{
	initgraph(700, 700, NOMINIMIZE);
	setbkcolor(WHITE);
	cleardevice();
	setbkmode(TRANSPARENT);
	HWND head = GetHWnd();
	SetWindowText(head, "五子棋人机对战");

	while (true)
	{
		init();
		MainGame();
		cleardevice();
	}
	return 0;
}