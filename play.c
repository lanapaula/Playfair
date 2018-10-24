#include <stdio.h>
#include <string.h>
#define MAX 100

char matriz[5][5];  

void zerar_matriz()
{
	int i, j;
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
		{
			matriz[i][j] = 0; 
    	}
}

int existe_na_matriz(char c) 
{
	int i, j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(matriz[i][j] == c) 
			{
				return 1;
			}
		}	
	}
	return 0;	
}

void print_matriz()
{
	int i, j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}

void preenche_matriz(char chave[])
{
	zerar_matriz();
	int i, j, k;
	for(i = 0, j = 0, k=0; chave[i] != '\0'; i++) 
	{
		if(chave[i] == 'J') chave[i] = 'I';
		if(existe_na_matriz(chave[i])==0) 
		{
			matriz[j][k] = chave[i];
			k++;
			if(k > 4)
			{
				k=0;
				j++;
			}
		}
	}
	k = 65; 
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(matriz[i][j] == 0)
			{
				while(existe_na_matriz(k) == 1) k++;  
				if(k == 'J') k++;
				matriz[i][j] = k; 
			}
		}
	}
	print_matriz();
}

void cadastrar_frase(char frase[])
{	
	char aux[MAX];
	int i, j;
	printf("Digite uma frase: ");
	fgets(frase, MAX, stdin); 
	strupr(frase); 
	strtok(frase, "\n"); 
	for(i = 0, j = 0; frase[i] != '\0'; i++, j++)
	{
		if(frase[i] == 'J') frase[i] = 'I'; 
		while(frase[i] == ' ')i++; 
		aux[j] = frase[i]; 
	}
	aux[j] = '\0';
	strcpy(frase,aux); 
}

void cadastrar_chave(char chave[])
{
	char aux[26];
	int i, j;
	printf("Digite uma palavra ou frase para a chave: ");
	fgets(chave, 26, stdin); 
	strupr(chave); 
	strtok(chave, "\n"); 	
	for(i = 0, j = 0; chave[i] != '\0'; i++, j++)
	{
		while(chave[i] == ' ')i++;
		aux[j] = chave[i];
	}
	aux[j] = '\0';
	strcpy(chave,aux);
	preenche_matriz(chave); 
}

void criptografar(char frase[])
{
	int i = 0, i1, i2, j1, j2, flag; 
	while(1 == 1) 
	{
		flag=0;
		char A = frase[i], B = frase[i+1]; 
		if(A == B) 
		{
			B = 'X'; 
			int j;
			for(j = strlen(frase) + 1; j > i+1; j--) 
				frase[j] = frase[j-1]; 
			frase[j] = 'X';  
		}
		
		if(A == '\0') 
			break;
		if(B == '\0')
		{
			B = 'X';
			frase[i + 2] = '\0';
		}
		
		for(i1 = 0; i1 < 5; i1++)
		{
			for(j1 = 0; j1 < 5; j1++)
			{
				if(matriz[i1][j1] == A)
				{
					flag = 1; 
					break; 
				}
			}
			if(flag ==1) 
			break; 
		}
		flag = 0; 
		
		for(i2 = 0; i2 < 5; i2++)
		{
			for(j2 = 0; j2 < 5; j2++)
			{
				if(matriz[i2][j2] == B)
				{
					flag = 1; 
					break; 
				}
			}
			if(flag == 1) 
			break; 
		}
		
		
	
		if(j1 == j2) 
		{
			i1 = (i1 == 4? 0 : i1+1); 
			i2 = (i2 == 4? 0 : i2+1); 
		}
		else if(i1 == i2)
		{
			j1 = (j1 == 4? 0 : j1+1); 
			j2 = (j2 == 4? 0 : j2+1); 
		}
		else 
		{
			int aux = j1; 
			j1 = j2; 
			j2 = aux; 
		}
		frase[i] = matriz[i1][j1];
		frase[i+1] = matriz[i2][j2];
		i+=2; 
	}
}

void descriptografar(char frase[])
{
	int i = 0, i1, i2, j1, j2, flag; 
	while(1 == 1) 
	{
		flag=0;
		char A = frase[i], B = frase[i+1]; 
		
		if(A == '\0') 
			break;
		
		for(i1 = 0; i1 < 5; i1++)
		{
			for(j1 = 0; j1 < 5; j1++)
			{
				if(matriz[i1][j1] == A)
				{
					flag = 1; 
					break; 
				}
			}
			if(flag ==1) 
			break; 
		}
		flag = 0; 
		
		for(i2 = 0; i2 < 5; i2++)
		{
			for(j2 = 0; j2 < 5; j2++)
			{
				if(matriz[i2][j2] == B)
				{
					flag = 1; 
					break; 
				}
			}
			if(flag ==1) 
			break; 
		}
	
		
		
		if(j1 == j2) 
		{
			i1 =(i1 == 0? 4 : i1-1); 
			i2 = (i2 == 0? 4 : i2-1); 
		}
		else if(i1 == i2) 
		{
			j1 = (j1 == 0 ? 4 : j1-1); 
			j2 = (j2 == 0 ? 4 : j2-1); 
		}
		else 
		{
			int aux = j1; 
			j1 = j2; 
			j2 = aux; 
		}
		frase[i] = matriz[i1][j1];
		frase[i+1] = matriz[i2][j2];
		i+=2; 
	}
}

int main()
{
	int menu = 0;
	char frase[MAX]="", chave[26]="", mat[5][5]; 
	do
	{
		printf("\n\n-----------Menu-----------\n\n");
		printf("Frase: %s \nChave: %s\n", frase, chave);
		printf("Escolha uma opcao: \n");
		printf("1 - Inserir uma nova frase \n2 - Inserir uma nova chave \n3 - Criptografar \n4 - Descriptografar \n5 - Limpar todos os dados(frase e chave) \n6 - Sair do programa\n> ");
		scanf("%i", &menu);
		getchar(); 
		switch (menu)
		{
			case 1:
				cadastrar_frase(frase);
				x++;
				break;
			case 2:
				cadastrar_chave(chave);
				y++;
				break;
			case 3:
				if(frase[0] == '\0' || chave[0] == '\0')
				{
					printf("Invalido!\n");
				}
				else
				{
					criptografar(frase);
				}
				break;
			case 4:
				descriptografar(frase);
				break;
			case 5:
				frase[0] = '\0'; 
				chave[0] = '\0';
				zerar_matriz(); 
				break;
			default: 
			    if(menu!=6)
			    {
			    	printf("\n\nEscolha invalida!\n\n");
			        break;
				}
	    }
	}
	while(menu!=6);
	return 0;
}
