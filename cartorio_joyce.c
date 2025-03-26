#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{    // Inicio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string 
    
    strcpy(arquivo, cpf);  // Respons�vel por copiar os valores das string
    
    FILE *file;  // cria o arquivo
    file = fopen(arquivo, "w");  // cria/abre o arquivo na pasta e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // cria/abre o arquivo e o "a" significa atualizar
    fprintf(file,","); // salva o valor da vari�vel 
    fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s",nome); // %s refere-se a string
	
	file = fopen (arquivo, "a"); // cria/abre o arquivo e o "a" significa atualizar
	fprintf(file,nome);  // salva o valor da vari�vel
	fclose(file);    // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria/abre o arquivo e o "a" significa atualizar
    fprintf(file,","); // salva o valor da vari�vel
    fclose(file);    // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s",sobrenome); // %s refere-se a string
	
	file = fopen (arquivo, "a"); // cria/abre o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); // salva o valor da vari�vel
	fclose(file);   // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria/abre o arquivo e o "a" significa atualizar
	fprintf(file,","); // salva o valor da vari�vel
	fclose(file);  // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // cria/abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); // salva o valor da vari�vel
	fclose(file);   // fecha o arquivo
	
	system("pause"); // congela a tela para dar tempo do usu�rio visualizar
}

int consulta() // Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possiv�l abrir o arquivo, n�o localizado!\n");
    }
    
    while(fgets(conteudo,200,file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    
    system("pause");
		
}

int deletar() // Fun��o respons�vel por deletar os usu�rios no sistema
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
	}
}



int main()
{
	int opcao=0;  //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //comando de limpar tela
	    
	    setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");  //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: ");  //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	    
	    system("cls"); //comando de limpar tela
	
	
	    switch(opcao) //Inicio da sele��o do menu
	    {
	    	case 1:
	        registro(); //chamada de fun��es
            break;
            
            case 2:
            consulta(); 
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        default:
	        printf("Essa op��o n�o est� dispon�vel!\n");
	        system("pause");
	        break; //Fim da sele��o
        }
      
	}


}
