#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);


int main(void)
{
  gotoxy(2,4);
  printf("Hello");
  gotoxy(40, 20);
  printf("Hello");
  return 0;
}

//void 문이 f10으론 실행되는데 f11론 실행안되요. 
//void main()
//{
//gotoxy(2,4);
//printf("Hello");
//gotoxy(40, 20);
//printf("Hello");	
//}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
