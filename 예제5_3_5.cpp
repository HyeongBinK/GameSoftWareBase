#include <math.h>
#include <conio.h>
#include <windows.h>
#include<iostream>
using namespace std;

int calc_frequency(int octave, int inx);
void practice_piano(void);
void Play_SchoolBellDengDengDeng(void);
void StartMenu(void);

void StartMenu(void)
{
	cout << "1.학교종이떙떙떙출력" << endl;
	cout << "2.키보드값 입력받아 소리  출력" << endl;
	cout << "3.종료" << endl; 
	cout << "입력 : "; 
}

void Play_SchoolBellDengDengDeng(void)
{
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8], code, i;
	int abc[24] = {5,5, 6,6,5,5,3,5, 5,3, 3, 2,5, 5, 6, 6, 5, 5,3, 5, 3, 2, 3, 1};
	for(i=0;i<8;i++)
		freq[i]=calc_frequency(4, index[i]);
	
		for(i=0;i<24;i++)
		{
			Beep(freq[abc[i]], 300);
		}
} 

void practice_piano(void)
{
	system("cls");
	printf("1부터 8까지 숫자 키를 누르면\n");
	printf("각 음의 소리가 출력됩니다.\n\n");
	printf("1:도 2:레 3:미 4:파 5:솔 6:라 7:시 8:도\n");
	printf("프로그램 종료는 Esc키 \n");
	
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8], code, i;
	for(i=0;i<8;i++)
		freq[i]=calc_frequency(4, index[i]);
	do
	{
		code=getch();
		if ('1'<=code && code<='8')
		{
			code-=49;
			Beep(freq[code],300);
		}
	}while(code!=27);
}

int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}

int main(void)
{

while(1)
{
	system("cls");
	StartMenu();
	int iSelect;
	
	cin >> iSelect;
	switch(iSelect)
	{
		case 1:
			Play_SchoolBellDengDengDeng();
			break;
		case 2:
			practice_piano();
			break;
		case 3:
			return 0;
		default:
			break;
					
	 } 

}
return 0;
}

