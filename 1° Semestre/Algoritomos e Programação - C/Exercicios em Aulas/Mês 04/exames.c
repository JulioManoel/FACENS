/*
	Diz qual exame realizar
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
	char cod;
	int Pac, qtdAt, ocViroce, ocDorDeCabeca, ocGripe, ocExames;
	printf("\nDigite o numero de pacientes que o medico ira realizar: ");
	scanf("%d", &qtdAt);
	for (Pac = 1; Pac <= qtdAt; Pac++)
	{
		system("cls");
		printf("\nAtendimento %d° paciente: ", Pac);
		printf("\nCodigo: ");
		cod = getche();
		switch (cod)
		{
		case '1':
		case '2':
			printf("\nVirose - Descanso");
			ocViroce++;
			break;
		case '3':
		case '5':
			printf("\nDor de cabeca - Analgesico");
			ocDorDeCabeca++;
			break;
		case '4':
			printf("\nGripe - Vitamina C");
			ocGripe++;
			break;
		case '6':
			printf("\nNao definida - Exames");
			ocExames++;
			break;
		default:
			printf("\nCodigo Invalido");
			Pac--;
		}
	}
	printf("\nRelatorios");
	printf("\nVirose %d, Dor de Cabeca %d, Gripe %d, Nao Definido %d", ocViroce, ocDorDeCabeca, ocGripe, ocExames);
	system("pause");
}
