#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

int main()
{
    unsigned char tecla; //de 0 a 255
    
    for (tecla = 0; tecla < 255; tecla++)
    {
       printf("\t %i-%c", tecla, tecla);	
    }

	system("pause");
	return 0;
	
}

