#include <stdio.h>

#define LIN 4
#define COL 5
#define NITMAX 2

void printmat(float matriz[][COL]);

int main(void)
{
    /* Declaracao de variaveis decisorias*/
    float matriz[LIN][COL] =
    {
        {2, 2, 1, 1, 7},
        {1, -1, 2, -1, 1},
        {3, 2, -3, -2, 4},
        {4, 3, 2, 1, 12},
    };
    /*indices*/
    int i,j,k,w,x,y,z;
    float soma=0.0;

    /*matrizes*/
    float mult[LIN][COL-1];
    float matriz00[LIN][COL];
    float s[NITMAX+1][LIN];
    float aux;
	float b[LIN]; 

    //Solucoes
    s[0][0] = 1;
    s[0][1] = 0;
    s[0][2] = 0;
    s[0][3] = 1;

    printf("===Matriz dada=== \n");
    printmat(matriz);
	
    printf("\n\n\n");
	//prenncher matriz b
	printf("\nmatriz unitaria b\n");
	for(i=0; i<LIN; i++)
	{
		b[i]=matriz[i][COL];
	}
	for(i=0; i<LIN; i++)
		printf("%f\n", b[i]);
    for(i=0;i<LIN; i++)
    {
        for(j=0;j<COL;j++)
        {
            matriz00[i][j] = matriz[i][j];
        }
    }
    for(i=0;i<LIN-1; i++)
    {
        printf("=== Elementos da etapa (e=%d) ===\n\n",i+1);
        printf("Calculo para multiplicadores\n");
        for(k=i+1;k<LIN; k++)
        {
            /*encontrar multiplicadores*/
            mult[k][i] = matriz00[k][i]/matriz[i][i];
            printf("m%d, %d - %f\n",k,i,mult[k][i]);
        }
        printf("\n\n");

        for(x=i; x<LIN-1; x++)
        {
            printf("Linha L%d(%d)\n", x+1,i+1);
            for(y=0; y<COL; y++)
            {
                matriz00[x+1][y] = matriz[x+1][y]-(mult[x+1][i]*matriz[i][y]);
                printf("a%d,%d(k=%d)(%f) = a%d,%d(k=%d)(%f)-m%d,%d(%f)*a%d,%d(k=%d)(%f)\n",x+1,y,i+1,matriz00[x+1][y],x+1,y,i,matriz[x+1][y],x+1,i,mult[x+1][i],x,y,i,matriz[x][y]);
            }
            printf("\n");
        }
        /*igualar a matriz00 a original*/
        for(x=0;x<LIN; x++)
        {
            for(y=0;y<COL;y++)
            {
                matriz[x][y]= matriz00[x][y];
            }
        }
        for(w=0;w<LIN;w++)
        {
            for(z=0;z<COL;z++)
            {
                if(w<=i+1)
                    printf("\t%0.4f(%d)\t", matriz[w][z], w);
                else
                    printf("\t%0.4f(%d)\t", matriz[w][z], i+1);
            }
            printf("\n");
        }

        printf("\n\n\n\n");

    }
    //igualando a diagonal principal a 1 na matriz L
    printf("\nMatriz para multiplicadores\n");
	for(i=0;i<LIN;i++)
    {
        for(j=0;j<COL-1; j++)
		{
			if(j==i)
			{
				mult[i][j]=1;
			}
		}
    }
    for(i=0;i<LIN;i++)
    {
        for(j=0;j<COL-1; j++)
            printf("\t%0.4f\t", mult[i][j]);
        printf("\n");
    }
    
    /*
	printf("\nMatriz final\n");
    for(i=0; i<LIN; i++)
	{
        for(j=0; j<COL-1; j++)
        {
            matriz00[i][j]=0;
            for(k=0; k<COL-1; k++)
            {
            	aux += mult[i][k] * matriz[k][j];
            }
            matriz00[i][j]=aux;
            aux=0;
        }
    }*/
   /* for(i=0;i<LIN;i++)
    {
        for(j=0;j<COL-1; j++)
            printf("\t%0.4f\t", matriz00[i][j]);
        printf("\n");
    }*/
    printf("\nMatriz para multiplicadores\n");
    for(i=0;i<LIN; i++)
    {
    	for(j=0;j<COL-1; j++)
    	{
    		if(j<i)
    		matriz00[i][j]=mult[i][j];
		}
	}
	printf("-\-\-\-\\-\-\-\-\-\-\-\-\ \n-\-\-\-\-\-\-\-\--\\-\--\\\n");
	printmat(matriz00);

    //Calculo xi^[k], onde i = 1,2,3,4
	
	for(i=0;i<LIN;i++)
	{
		for(j=0; j<COL; j++)
		{
			
		}
	}
    for(k=0; k < NITMAX; k++)
    {
        s[k+1][LIN-1] = s[k][LIN-1] + (matriz[LIN-1][LIN] / matriz[LIN-1][LIN-1]);
        for(i=LIN-2; i > -1; i--)
        {
            soma=0.0;
            for(j=i+1; j < LIN; j++)
                soma = soma + matriz[i][j]*s[k][j];
            s[k+1][i] = s[k][i] + (matriz[i][LIN] - soma)/matriz[i][i] ;
        }

    }

    for(k=0; k < NITMAX; k++)
    {
        printf("\n");
        for(i=0; i < LIN; i++)
            printf("%f\t", s[k][i]);
    }
    
    printf("\n-------------------------------------------------------------------------------------------------------------\n");

   return 0;
}
void printmat(float matriz[][COL])
{
    int i, j;
    for(i=0;i<LIN;i++)
    {
        for(j=0;j<COL; j++)
            printf("\t%0.4f\t", matriz[i][j]);
        printf("\n");
    }
}
