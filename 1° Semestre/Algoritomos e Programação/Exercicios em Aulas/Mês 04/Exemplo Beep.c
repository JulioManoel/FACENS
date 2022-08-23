#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char t;
	do{
		system("cls");
		printf("\nPrecione as teclas A, S, D, F, G, H, J para tocar o piano\n");
		t = getch();
		t = toupper(t);
		if(t == 'A')
		{
			Beep(261, 700);
		}
		else if(t == 'S')
		{
			Beep(293, 700);
		}
		else if(t == 'D')
		{
			Beep(329, 700);
		}
		else if(t == 'F')
		{
			Beep(349, 700);
		}
		else if(t == 'G')
		{
			Beep(392, 700);
		}
		else if(t == 'H')
		{
			Beep(440, 700);
		}
		else if(t == 'J')
		{
			Beep(493, 700);
		}
	}while(t != 27);
	system("pause");
	return 0;
}
