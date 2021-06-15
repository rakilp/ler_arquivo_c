#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<locale.h>

//raquel alteraçao
const int TAM_MAX_VETOR = 100;

int main()
{
    FILE *arq;
    char linha[100];
    char *result;
    int  i,j, contador,quant,quantdiferente,duracao;
    char delimitadores[] = ";";

    long long no[TAM_MAX_VETOR], nd[TAM_MAX_VETOR];
    int nt[TAM_MAX_VETOR];


    i = 0;


    arq = fopen("teste-ligacoes-2018-01-01.txt", "r");

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n\n");
        return 0;
    }

    fgets(linha, 100, arq);


    while (!feof(arq))
    {
        result = fgets(linha, 100, arq);


        if (result)
        {
            char *str = strtok(linha, delimitadores);


            contador = 1;

            while (str != NULL)
            {
                if (contador == 2)
                {
                    no[i]= strtoll(str, NULL, 10);
                }
                if (contador == 3)
                {
                    nd[i] = strtoll(str, NULL, 10);
                }
                if (contador == 4)
                {
                    nt[i] = atoi(str);
                }
                str = strtok(NULL, delimitadores);
                contador++;
            }

        }
        
        
        if((no[i]/1000000000)<10){
        no[i]= no[i]/100000000;	
		}else{
			no[i]=no[i]/1000000000;
		}
		
		 if((nd[i]/1000000000)<10){
        nd[i]= nd[i]/100000000;	
		}else{
			nd[i]=nd[i]/1000000000;
		}
		
		if(no[i]!= nd[i]){
              	
              	quantdiferente++;
              	
			  }
		
      i++;
    }

    printf("\TOTAL_CLIENTES_LIGARAM %d\n",i, setlocale(LC_ALL,""));
    printf("\Dura��o m�dia :\n");
   
    int l;	
    for(l=10;l<100;l++){
    	
    	quant=0;
    	duracao=0;
    	for(j=0;j<=i;j++){
    	
		
		   if(l == (int)no[j]){
    	
    	    duracao= duracao + nt[j];
            quant++;
          	    	
              }
           
	  }	
	
	if(quant>0){
		
    printf("%d : %d \n",l,(duracao/quant));
	}
	
	
}

printf("TOTAL_CLIENTES_LIGARAM_OUTRO_DDD: %d", quantdiferente);

  

    fclose(arq);
}
