#pragma once

#include <iostream>



char** CreateMas(int w, int h);
void WriteIn(int w, int h, int **mas);
void PrintOnScreen(int w, int h, int ** mas);
int * Counter(int w, int h, int **mas);
void FreeMas(int w, int ** mas);