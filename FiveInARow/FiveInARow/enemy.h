#pragma once
#include "board.cpp"
#include <ctime>
#include <cstdlib>

int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { 0, 1, 1, -1 };

seat FindBestSeat(int color);