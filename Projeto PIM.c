/******************************************************************************

Comente sempre que alterar.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 50

char nome[SIZE][200],senha[8][200];
char funcio[60], clint[60], date[60];
char*nome_comp=NULL;
char*tipo_serv=NULL;
float valor;

void cadastro();
void servico();
void cliente();

int main()
{
 int cont = 0;
 int op2 = 0;
 FILE *file;

    while (op2 == 0)
    {
        printf("\n\tAIRcoDe\n\n");
        printf("Digite 1 para cadastrar um usuario:\n");
        printf("Digite 2 se já tem cadastro:\n");
        scanf("%d", &cont);
        system("cls");

        switch (cont)
        {

         /*Tela de cadastro*/
         case 1:
         file = fopen("Usuarios", "a");
            if(file == NULL){
             printf("não deu mermão");
             return 1;
            } 
   
         cadastro(file);//Chama a função de cadastro de usuário 
        
         fclose(file);
         break; 
     
         //Tela de login
         case 2:
         file = fopen("Usuarios", "r");
            if(file == NULL){
             printf("não deu mermão");
             return 1;
            }
         char login[50];
         char login2[20];
         char senha1[20];
         char senha2[20];
         char *retorno;
         int sair = 6;
            
         int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

            printf("Digite o Login:\n");
            scanf("%s", login);
            printf("Digite a Senha:\n");
            scanf("%s", senha1); 
            system("cls");

            while ((fscanf(file, "%s ; %s\n", login2, senha2)) != EOF)//Comparando dados do arquivo "Usuarios.txt" com os dados de entrada
            {
                if (strcmp(login, login2) == 0 && strcmp(senha1, senha2)== 0 && sair == 6){
                 printf("\n\n\t%s LOGADO!\n\n", login2);
                 login_efetuado = 1;
                 
                    do
                    {
                        printf("\n\tMENU INICIAL\n\n");
                        printf("Cadastrar cliente (digite 1)\n");//Lucas
                        printf("Cadastrar funcionario (digite 2)\n");//Kaue
                        printf("Nova ordem de serviço (digite 3)\n");//Samuel
                        printf("Relatorios(digite 4)\n");//Samuel e Vieira
                        printf("Para retornar a tela de login(digite 0)\n");
                        scanf("%d", &sair);
                        system("cls");

                        switch (sair)
                        {
                         case 1:

                            //ABERTURA DO ARQUIVO PARA GRAVACAO
                            file = fopen("clientes.txt","a");
                            if(file == NULL){
                            printf ("ERROR !! CONTATE O ADIM");
                            return 1;
                            }
                            
                            cliente(file);

                            fclose(file);

                            break;
                         case 2:
                            //Kaue
                            break;
                         case 3:

                            file = fopen("serviço.txt", "a");
                            if(file == NULL)
                            {
                                printf("não deu mermão");
                                return 1;
                            } 

                                gets(funcio);
                                printf("\nFuncionário responsável pela OS: \n");
                                gets(funcio);
                                fprintf(file, "%s;", funcio);
                                //Necessaria base de funcionarios                              

                                servico(file);

                            
                            fclose(file);

                            char linha[9999];
                            char*resultado;
                            int contador = 0;


                            file = fopen("serviço.txt","r");

                            while(!feof(file))
                            {
                                resultado = fgets(linha, 9999, file);
                                if(resultado)
                                {
                                    contador = contador + 1;
                                }
                            }
                            fclose(file);

                                printf("Numero da OS: %d\n", contador);
                                printf("Nome do funcionário: %s\n", funcio);
                                printf("Nome do cliente: %s\n", clint);
                                printf("Componente a ser revisado: %s\n", nome_comp);
                                printf("Tipo de revisao: %s\n", tipo_serv);
                                printf("Data de abertura da ORDEM DE SERVIÇO: %s\n", date);
                                printf("Valor final a ser pago: %.3f", valor);
                                
                            break;
                         case 4:
                            //Samuel e Vieira
                            break;
                        
                         default:
                            break;
                        }
                    } while (sair != 0);
                    
                 /*O restante do codigo será desenvolvido dentro deste IF, pois somente dentro dele
                 é possivel a validação dos dados de login*/
                }   
            }

            if (login_efetuado != 1){
             printf("\n\n\tDADOS INVALIDOS!\n");
             printf("CADASTRE-SE OU TENTE NOVAMENTE\n\n");
            }
        
         fclose(file);
         break;
        }
    }
 return 0;
}
//Função para cadastro de usuário
void cadastro(FILE *fi)
{
    int opcao;
 
    do
    {
     gets(nome);
     printf("Escolha um nome de usuario:\n");
     gets(nome);
     fprintf(fi, "%s;", nome);
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Crie uma senha(com 8 digitos):\n");
     gets(senha);
     fprintf(fi, "%s\n", senha);
     system("cls");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Cadastro executado com sucesso...\n");
     printf("*----------------------------------------------------------------------------------------*\n");
     printf("Digite 1 para ver seus dados de cadastro.\nDigite 2 para sair.\n");
     scanf("%d", &opcao);
     system("cls");
        if (opcao == 1){
            while (opcao == 1)
            {
                printf("Nome de usuario: %s\n", nome);
                printf("Senha: %s\n", senha);
                printf("*----------------------------------------------------------------------------------------*\n");
                printf(".\nDigite 1 para ver seu cadastro.\nDigite 2 para sair.\n");
                scanf("%d", &opcao);
                system("cls");
            }
        }
    } while (opcao == 0);
}

void servico(FILE *fl)
{
    int comp, tserv;

        

        printf("\nCliente: \n");
        gets(clint);
        fprintf(fl, "%s;", clint);
        //Necessaria base de clientes

        while (comp<1 || comp>7)
        {

            printf ("\n--------------------------------------------------------------------------------\n");
            printf("Componente a ser revisado:\n1-Distribuidora\n2-Bomba de combustivel\n3-Dosadora\n4-Carburador\n5-Magneto\n6-Alternador\n7-Motor de partida\n");
            scanf("%d", &comp);
            printf ("\n--------------------------------------------------------------------------------\n");
            system("cls");

            switch (comp)
            {
            case 1:
                nome_comp = "Distribuidora";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi uma %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 2:
        
                nome_comp = "Bomba de combustivel";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi uma %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 3:
        
                nome_comp = "Dosadora";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi uma %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 4:
        
                nome_comp = "Carburador";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 5:
        
                nome_comp = "Magneto";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 6:
        
                nome_comp = "Alternador";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break; 
            case 7:
        
                nome_comp = "Motor de partida";
                fprintf(fl, "%s;", nome_comp);
                printf("O componente escolido foi um %s.", nome_comp);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;       
            default:
                printf("!Componente inválido!");
                printf ("\n--------------------------------------------------------------------------------\n");
            }
            system("cls");
        }

        while (tserv<1 || tserv>4)
        {
            printf("Tipo de revisao:\n1-Revisão geral\n2-Revisao de 500 horas\n3-Revisao 100 horas\n4-Revisao parcial\n");
            scanf("%d", &tserv);
            printf ("\n--------------------------------------------------------------------------------\n");
            system("cls");

            switch (tserv)
            {
            case 1:
                tipo_serv = "Revisão geral";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 1.800;
                            }
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 1.800;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.800;
                    }
                fprintf(fl, "%s;", tipo_serv);
                fprintf(fl, "%.3f\n", valor);         
                printf("O tipo de revisão escolida foi uma %s, no valor de %.3f", tipo_serv, valor);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 2:
        
                tipo_serv = "Revisao_de_500 horas";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 1.800;
                            }   
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 1.800;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.800;
                    } 
                fprintf(fl, "%s;", tipo_serv);
                fprintf(fl, "%.3f\n", valor);    
                printf("O tipo de revisão escolida foi uma %s, no valor de %.3f", tipo_serv , valor);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 3:
        
                tipo_serv = "Revisao_100_horas";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 1.800;
                    }
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 1.800;
                            }
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 1.800;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.800;
                    } 
                fprintf(fl, "%s;", tipo_serv);
                fprintf(fl, "%.3f\n", valor);
                printf("O tipo de revisão escolida foi uma %s, no valor de %.3f", tipo_serv , valor);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            case 4:
        
                tipo_serv = "Revisao_parcial";
                    if (strcmp(nome_comp, "Distribuidora") == 0){
                        valor = 1.800;
                    }   
                        if (strcmp(nome_comp, "Bomba de combustivel") == 0){
                            valor = 1.800;
                        }
                            if (strcmp(nome_comp, "Dosadora") == 0){
                                valor = 1.800;
                            }
                                if (strcmp(nome_comp, "Carburador") == 0){
                                    valor = 1.800;
                                }
                            if (strcmp(nome_comp, "Magneto") == 0){
                                valor = 1.800;
                            }
                        if (strcmp(nome_comp, "Alternador") == 0){
                            valor = 1.800;
                        }
                    if (strcmp(nome_comp, "Motor de partida") == 0){
                        valor = 1.800;
                    } 
                fprintf(fl, "%s;", tipo_serv);
                fprintf(fl, "%.3f\n", valor);
                printf("O tipo de revisão escolida foi uma %s, no valor de %.3f", tipo_serv , valor);
                printf ("\n--------------------------------------------------------------------------------\n");
                break;
            default:
                printf("!tipo de revisão inválida!");
                printf ("\n--------------------------------------------------------------------------------\n");
            }
            system("cls");
        }
            gets(date);       
            printf("Data de abertura da ORDEM DE SERVIÇO(dd/mm/yyyy):\n");
            gets(date);
            printf ("\n--------------------------------------------------------------------------------\n"); 
            system("cls");
                 
}

void cliente(FILE*Cadastro_cliente)
{
    //DECLARACAO DE VARIAVEIS           //* A MAIORIA DAS STRING RECEBEM UMA CASA A MAIS POR CONTA DO \0 OU \n *//
    char CPF[12][100],nome_cliente[50][100],Contato1[11][50],Contato[12][50],CEP[50][50],mail[50][50],cnpj[14][50];
    char IES [13][50];
    int dgcnpj; //VARIAVEL PRESENTE DENTRO WHILE CNPJ
    int cont=0; //VARIAVEL SWITCH
    int VCPF =1; //VARIAVEL WHILE CPF
    int VCNPJ =1;//VARIAVEL WHILE CNPJ


     //ENTRADA NO SWITCH E ESCOLHA DE CADASTRO
    printf("*----------------------------------------------------------------------------------------*\n");
    printf("*-----------------------------TELA DE CADASTRO-------------------------------------------*\n");
    printf("*---------------------(CADASTRO CPF = 1)--(CADASTRO CNPJ = 2)----------------------------*\n");
    printf("\nDIGITE A SUA OPCAO...:");
    scanf("%d",&cont);
    system("cls");


    switch(cont)
    {
     case 1:

        
            // CADASTRO DE CLIENTE COM CPF
            while(VCPF ==1){
                printf("*-----------------------------CADASTRO CPF-------------------------------------------*\n");

                gets(CPF);
                printf("\nDIGITE O CPF...:");
                gets(CPF);
                fprintf(Cadastro_cliente,"%s;",CPF);
                fflush(stdin); // LIMPAR BUFFER PARA EVITAR TRANSTORNOS

                printf("\nDIGITE O NOME DO CLIENTE...:");
                scanf("%[^\n]s", &nome_cliente); // "[^\n] PERMITE A LEITURA DO ESPAÇO ENTRE OS NOMES. & APONTAMENTO NA MEMORIA.
                fprintf(Cadastro_cliente,"%s;",nome_cliente);                                 //NAO APRESENTOU FALHAS EU USEI.
                fflush(stdin);

                printf("\nDIGITE O NUMERO DO TELEFONE...:");
                gets(Contato1);
                fprintf(Cadastro_cliente,"%s;",Contato1); //SEPARACAO POR PONTO E VIRUGLA PARA UM USO FUTURO.
                fflush(stdin);

                printf("\nDIGITE O NUMERO DO CELULAR...:");
                gets(Contato);
                fprintf(Cadastro_cliente,"%s;",Contato);
                fflush(stdin);

                printf("\nDIGITE APENAS OS NUMEROS DO CEP...:");
                gets(CEP);
                fprintf(Cadastro_cliente,"%s;",CEP);
                fflush(stdin);

                printf("\nDIGITE O E-MAIL...:");
                gets(mail);
                fprintf(Cadastro_cliente,"%s\n",mail);
                fflush(stdin);

                printf("\nDESEJA CONTINUAR CADASTRANDO ?(SIM -1 / NAO -2) :");//CASO O USUARIO DESEJE CADASTRAR OUTRO CLIENTE
                scanf("%d",&VCPF);
                fflush(stdin);
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("*-------------------------CADASTRO CONCLUIDO COM SUCESSO---------------------------------*\n");
                printf("*----------------------------------------------------------------------------------------*\n");

     break;
        }


     case 2 :
        
            //CADASTRO DE CLIENTE COM CNPJ
           while(VCNPJ==1){
            printf("*-----------------------------CADASTRO CNPJ-------------------------------------------*\n");

            fflush(stdin);
            printf("\nDigite o CNPJ do cliente...:");
            gets(cnpj);
            fprintf(Cadastro_cliente, "%s;" , cnpj);
            fflush(stdin);
            printf("\nCLIENTE POSSUI INSCRICAO ESTADUAL? (SIM -1/ NAO-2) :");
            scanf("%d",&dgcnpj);
            fflush(stdin);
             if(dgcnpj == 1){                                   //A CASOS EM QUE PESSOAS JURIDICAS POSSUEM INSCRICAO ESTADUAL
                 fflush(stdin);
                 printf("\nDigite a inscricao estadual...:");   //DEVIDO A ISSO ESSA CONDICIONAL EXISTE
                 gets(IES);
                 fprintf(Cadastro_cliente,"%s;",IES);
                 fflush(stdin);
                }else if(dgcnpj !=1){
                   strcpy (IES,"000000000000");
                   }
            fflush(stdin);
            printf("\nDIGITE A IDENTIFICACAO DO CLIENTE....:");
            scanf("%[^\n]s",nome_cliente); // "[^\n] PERMITE A LEITURA DO ESPAÇO ENTRE OS NOMES. & APONTAMENTO NA MEMORIA.
            fprintf(Cadastro_cliente,"%s;", nome_cliente);
            fflush(stdin);

            printf("\nDigite o CEP..:");
            gets(CEP);
            fprintf(Cadastro_cliente,"%s;",CEP); //CADASTRO DO CEP
            fflush(stdin);

            printf("\nDIGITE O NUMERO DO TELEFONE...:");
            gets(Contato1);
            fprintf(Cadastro_cliente,"%s;",Contato1); //CADASTRO DO TELEFONE
            fflush(stdin);

            printf("\nDIGITE O NUMERO DO CELULAR...:");
            gets(Contato);
            fprintf(Cadastro_cliente,"%s;",Contato);   //CADASTRO DE CELULAR
            fflush(stdin);

            printf("\nDIGITE O E-MAIL...:");
            gets(mail);
            fprintf(Cadastro_cliente,"%s\n",mail);
            fflush(stdin);

            printf("\nDESEJA CONTINUAR CADASTRANDO ?(SIM -1 / NAO -2) :");//CASO O USUARIO DESEJE CADASTRAR OUTRO CLIENTE
            scanf("%d",&VCNPJ);
                printf("*----------------------------------------------------------------------------------------*\n");
                printf("*-------------------------CADASTRO CONCLUIDO COM SUCESSO---------------------------------*\n");
                printf("*----------------------------------------------------------------------------------------*\n");

      break;
      }
  }

    return 0;
}