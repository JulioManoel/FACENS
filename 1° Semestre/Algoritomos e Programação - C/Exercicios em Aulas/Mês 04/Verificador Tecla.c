#include <stdio.h>
#include <stdlib.h>

int main()
{
	while (1)
	{
		char tecla;
		tecla = getche();
		if (tecla >= 65 && tecla <= 90)
		{
			printf("\nAlfabeto em Maiusculo\n");	
		}
		else if (tecla >= 97 && tecla <= 122)
		{
			printf("\nAlfabeto em Minusculo\n");
		}
		else if (tecla >= 48 && tecla <= 57)
		{
			printf("\nNumeral\n");
		}
		else
		{
			printf("\nCaractere Especial\n");
		}
		if (tecla == 27)
		{
			break;
		}
	}
	system("pause");
	return 0;
}
