#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#define AMARILLO_T "\x1b[33m"
#define RESET_COLOR "\x1b[0m"
#define MAGENTA_T "\x1b[35m"
#define LONGITUD 20
#define ROJO_T     "\x1b[31m"
#define  VERDE_T     "\x1B[32m"
void gotoxy(int x,int y);
void maquina();
void mostrar();
void animacion();
void menu() ;
void margen() ;
void q0(char cadena1[],char cadena2[],char cadena3[],char cadena4[],int cab1,int cab2,int cab3,int cab4);
void q1 (char cadena1[], char cadena2[], char cadena3[], char cadena4[], int cab1, int cab2, int cab3, int cab4);
void cuadritos(int x, int y);
main()
{
menu();

}

void margen() 
{
	int c=1,f=1;
    int i, a = 25;

    gotoxy(c, f);
    printf(AMARILLO_T"%c", 218);

    // Cuadro pequeño
    gotoxy(a + 18, f + 1);
    printf("%c", 218);

    gotoxy(a + 18, f + 2);
    printf("%c", 179);

    gotoxy(a + 57, f + 2);
    printf("%c", 179);

    for (i = 0; i < 38; i++) {
        // -
        gotoxy((a + 18) + (i * 1) + 1, 2);
        printf("%c", 196);

        // -
        gotoxy((a + 18) + (i * 1) + 1, 4);
        printf("%c", 196);
    }

    gotoxy((a + 18) + (i * 1) + 1, 2);
    printf("%c", 191);

    gotoxy((a + 18) + (i * 1) + 1, 4);
    printf("%c", 217);

    gotoxy(a + 18, f + 3);
    printf("%c", 192);

    // Cuadro grande
    for (i = 0; i < 117; i++) {
        // -
        gotoxy(c + (i * 1) + 1, f);
        printf("%c", 196);

        // -
        gotoxy(c + (i * 1) + 1, 28);
        printf("%c", 196);
    }

    gotoxy(c + (i * 1) + 1, f);
    printf("%c", 191);

    for (i = 0; i < 26; i++) {
        // |
        gotoxy(c, f + (i * 1) + 1);
        printf("%c", 179);

        gotoxy(119, f + (i * 1) + 1);
        printf("%c", 179);
    }

    gotoxy(c, f + (i * 1) + 1);
    printf("%c", 192);

    gotoxy(119, f + (i * 1) + 1);
    printf("%c"RESET_COLOR, 217);
}
void menu()
{
	
	int i;
    margen();
    gotoxy(46,3);printf("M a q u i n a   d e   T u r i n g");
    gotoxy(10,8);printf("Q = {q0,q1,q2}");
   	gotoxy(10,10);printf("Alfabeto = {0, 1}");
	gotoxy(10,12);printf("Alfabeto de la maquina = {0, 1, -}");
	gotoxy(10,14);printf("F = {q2}");
	gotoxy(10,16);printf("s = q0");
	gotoxy(10,18);printf("Transiciones");
	gotoxy(10,20);printf("(q0(0,0,-,-))->(q0(0,0,0,-)(L,L,L,S))");
	gotoxy(10,21);printf("(q0(0,1,-,-))->(q0(0,1,1,-)(L,L,L,S))");
	gotoxy(10,22);printf("(q0(1,1,-,-))->(q1(1,1,0,1)(L,L,L,S))");
	gotoxy(10,23);printf("(q0(1,0,-,-))->(q0(1,0,1,-)(L,L,L,S))");
	gotoxy(10,24);printf("(q0(-,-,-,-))->(q2(-,-,-,-)(L,L,L,S))");
	//q2
	gotoxy(50,20);printf("(q1(0,0,-,1))->(q0(0,0,1,-)(L,L,L,S))");
	gotoxy(50,21);printf("(q1(0,1,-,1))->(q1(0,1,0,1)(L,L,L,S))");
	gotoxy(50,22);printf("(q1(1,1,-,1))->(q1(1,1,1,1)(L,L,L,S))");
	gotoxy(50,23);printf("(q1(1,0,-,1))->(q1(1,0,0,1)(L,L,L,S))");
	gotoxy(50,24);printf("(q1(-,-,-,1))->(q2(-,-,1,-)(L,L,L,S))");
	mostrar();
   gotoxy(74,6); system("pause");system("cls");
    int seguir;
   do
   {
   	maquina();
   	system("cls");
   	printf("Para hacer otra suma digite 1, salir 0....... [1/0]");scanf("%d",&seguir);
   		system("cls");	
   }while(seguir);
    		
 


	
	
}


void maquina()
{
	int in;
char cadena1[20],cadena2[20];
char cadena3[22] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-','\0'};  // '\0' es el carácter nulo que indica el final de la cadena
char cadena4[22] = {'-', '-', '-', '-', '-', '-', '-', '-', '-','-', '-', '-', '-', '-', '-', '-','-','\0'};
	int cabezal1=0,cabezal2=0,cabezal3=0,cabezal4=0;
	int i,j,k,l;
	gotoxy(44,2);printf(AMARILLO_T"S  u  m  a       B   i   n  a  r  i  a"RESET_COLOR);
	gotoxy(4,4);printf("Ingrese la primera cadena: ");scanf("%s",cadena1);
	cuadritos(4, 8);
		for(i=0;i<21;i++)
	{
		gotoxy(6+(i*4)+1,9);
		printf("-");
	}
	for(i=0;i<cadena1[i]!='\0';i++)
	{
		gotoxy(42+(i*4)+1,9);
		printf("%c",cadena1[i]);
		cabezal1++;
	}
	
	gotoxy(42 + (cabezal1 - 1) * 4 + 1,11);
	printf("^");
	gotoxy(42 + (cabezal1 - 1) * 4 + 1,12);
	printf("q0");
	
	gotoxy(4,6);printf("Ingrese la segunda cadena: ");scanf("%s",cadena2);
		cuadritos(4, 13);
		for(j=0;j<21;j++)
	{
		gotoxy(6+(j*4)+1,14);
		printf("-");
	}
	for(j=0;j<cadena2[j]!='\0';j++)
	{
		gotoxy(42+(j*4)+1,14);
		printf("%c",cadena2[j]);
		cabezal2++;
	}
	
	gotoxy(42 + (cabezal2 - 1) * 4 + 1,16);
	printf("^");
	gotoxy(42 + (cabezal2 - 1) * 4 + 1,17);
	printf("q0");
	//acarreo
	cuadritos(4, 18);
	for(k=0;k<10;k++)
	{
		gotoxy(50+(k*4)+1,19);
		printf("-");
	}
	
	for(k=0;k<cadena3[k]!='\0';k++)
	{
		gotoxy(6+(k*4)+1,19);
		printf("%c",cadena3[k]);
		cabezal3++;
	}
	gotoxy(6 + (cabezal3 - 1) * 4 + 1,21);
	printf("^");
	gotoxy(6 + (cabezal3 - 1) * 4 + 1,22);
	printf("q0");
	//resultado
		cuadritos(4, 23);gotoxy(90,19);printf(AMARILLO_T"Resultado"RESET_COLOR);
		gotoxy(90,24);printf(AMARILLO_T"Acarreo"RESET_COLOR);
	for(l=0;l<10;l++)
	{
		gotoxy(50+(l*4)+1,24);
		printf("-");
	}
	
	for(l=0;l<cadena4[l]!='\0';l++)
	{
	
		gotoxy(6+(l*4)+1,24);
		printf("%c",cadena4[l]);
		cabezal4++;
	}
	
	gotoxy(6 + (cabezal4- 1) * 4 + 1,26);
	printf("^");
	gotoxy(6 + (cabezal4- 1) * 4 + 1,27);
	printf("q0");
    q0( cadena1, cadena2, cadena3, cadena4, cabezal1, cabezal2, cabezal3, cabezal4);
    
    gotoxy(10,28);system("pause");

}

void q0(char cadena1[], char cadena2[], char cadena3[], char cadena4[], int cab1, int cab2, int cab3, int cab4)
{int band;
	do
	{
	band=0;
	 Sleep(800);
	 ////////////////////////////////111111111111111111111111111
    if (cadena1[cab1-1] =='0'&&cadena2[cab2-1] == '0'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '-')
    { 
        //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q0");
        
        /////////////////////////////////////////////////////
        //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q0");
        //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='0';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
       printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q0");
		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("  ");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("^");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("q0");
	band=1;
    }
    /////////////////////////////2
    else if(cadena1[cab1-1] =='0'&&cadena2[cab2-1] == '1'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '-')
    {
    	
    	
    	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q0");
        
        /////////////////////////////////////////////////////
        //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q0");
        //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='1';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q0");
		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("  ");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("  ");
		
		
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		
			gotoxy(6 + (cab4- 1) * 4 + 1,26);
    	printf("^");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("q0");
    	band=1;
	}
	else if(cadena1[cab1-1] =='1'&&cadena2[cab2-1] == '1'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '-')
	{
		
		  	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q1");
        
       
        /////////////////////////////////////////////////////
        //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q1");
        //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='0';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q1");
		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
     	printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		cadena4[cab4-1]='1';
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
			gotoxy(6 + (cab4- 1) * 4 + 1,26);
    	printf("^");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("q1");
	q1 ( cadena1,  cadena2,  cadena3,  cadena4,  cab1,  cab2,  cab3,  cab4);	
	}
	//4
	else if(cadena1[cab1-1] =='1'&&cadena2[cab2-1] == '0'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '-')
	{
			  	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q0");
		 //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q0");
		
		  //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='1';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
       	printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q0");
		
				////////cadena4
					gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("  ");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("  ");
	
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("^");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("q0");
	band=1;
		
	}
	else if (cadena1[cab1-1] =='\0'&&cadena2[cab2-1] == '\0'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '-')
	{
				  	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
			cadena1[cab1-1]='\0';
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("-");
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q2");
		
				 //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
			cadena2[cab1-2]='\0';
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("-");
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q2");
	    	  //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='-';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        	printf("%c", cadena3[cab3-1]);
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q2");
	    				////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("  ");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		cadena4[cab4-1]='-';
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
	printf("^");
	gotoxy(6 + (cab4- 1) * 4 + 1,27);
	printf("q2");
	gotoxy(80,4);	printf(VERDE_T"Suma completada."RESET_COLOR);
		
	}
	
	
		else 
		{
			gotoxy(60,4);printf(ROJO_T"Cadena no valida"RESET_COLOR);
		}
    
    
}while(band!=0);
}

void q1 (char cadena1[], char cadena2[], char cadena3[], char cadena4[], int cab1, int cab2, int cab3, int cab4)
{
	int band;
	do
	{
		
		Sleep(800);
		band=0;
	//////////////////////////////////////////////111111111111111111111111111
if(cadena1[cab1-1] =='0'&&cadena2[cab2-1] == '0'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '1')

	{
	
	 	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q0");
          //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q0");
	
	           //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='1';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q0");
	    		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
			cadena4[cab4-1]='-';
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("^");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("q0");
	
		q0 ( cadena1,  cadena2,  cadena3,  cadena4,  cab1,  cab2,  cab3,  cab4);
		
}
	////////////////////////////////////////22222222222222222222222222222	
	else if(cadena1[cab1-1] =='0'&&cadena2[cab2-1] == '1'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '1')
	{
	
		 	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q1");
      //cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q1");
		           //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='0';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q1");
			    		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		cadena4[cab4-1]='1';
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("^");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("q1");
		band=1;
	}
	
	////////////////////////333333333333333333333
	
	else if (cadena1[cab1-1] =='1'&&cadena2[cab2-1] == '1'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '1')	

	{
			
		 	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q1");
		//cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q1");
				           //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
			cadena3[cab3-1]='1';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q1");
				    		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("^");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("q1");
		band=1;
	}
	///////////////4
	else if (cadena1[cab1-1] =='1'&&cadena2[cab2-1] == '0'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '1')			
	{
			 	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
        printf("%c", cadena1[cab1-1]);
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q1");
		//cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
        printf("%c", cadena2[cab2-1]);
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q1");
				           //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
	
        	cadena3[cab3-1]='0';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        	printf("%c", cadena3[cab3-1]);

        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q1");
				    		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		cadena4[cab4-1]='1';
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("^");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("q1");
		band=1;
		}	
		else if(cadena1[cab1-1] =='\0'&&cadena2[cab2-1] == '\0'&&cadena3[cab3-1] == '-'&&cadena4[cab4-1] == '1')	
		{
				 	    //cadena1
    	gotoxy(41 + (cab1-1) * 4 + 1,9);
    	printf("  ");
    	//q0
    	gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("  ");
		//^
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("  ");
		cadena1[cab1-1]='\0';
    	gotoxy(41 + (cab1 - 1) * 4 + 1,9);
         printf("-");
        cab1--;
        gotoxy(42 + (cab1 - 1) * 4 + 1,11);
		printf("^");
		gotoxy(42 + (cab1 - 1) * 4 + 1,12);
		printf("q2");
		//cadena2
        gotoxy(41 + (cab2-1) * 4 + 1,14);
    	printf("  ");
    	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("  ");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("   ");
		cadena2[cab2-1]='\0';
    	gotoxy(41 + (cab2 - 1) * 4 + 1,14);
           printf("-");
        cab2--;
     	gotoxy(42 + (cab2 - 1) * 4 + 1,16);
		printf("^");
		gotoxy(42 + (cab2 - 1) * 4 + 1,17);
		printf("q2");
				           //////////cadena3
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
        printf("  ");
        gotoxy(5 + (cab3 - 1) * 4 + 1,21);
		printf("   ");
		gotoxy(5 + (cab3 - 1) * 4 + 1,22);
		printf("   ");
		cadena3[cab3-1]='1';
        gotoxy(5 + (cab3 - 1) * 4 + 1,19);
           printf("%c", cadena3[cab3-1]);
        cab3--;
        gotoxy(6 + (cab3 - 1) * 4 + 1,21);
		printf("^");
		gotoxy(6 + (cab3 - 1) * 4 + 1,22);
		printf("q2");
				    		////////cadena4
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("  ");
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf(" ");
		cadena4[cab4-1]='-';
		gotoxy(6 + (cab4- 1) * 4 + 1,24);
		printf("%c", cadena4[cab4-1]);
		gotoxy(6 + (cab4- 1) * 4 + 1,26);
		printf("^");
		gotoxy(6 + (cab4- 1) * 4 + 1,27);
		printf("q2");	
			gotoxy(80,4);	printf(VERDE_T"->Suma completada."RESET_COLOR);
		
		}
		else 
		{
			gotoxy(60,4);printf(ROJO_T"Cadena no valida"RESET_COLOR);
		}
		
		
		
}while(band!=0);
		
		
	}
	
//windows
 void gotoxy(int x,int y)
 {  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
  void cuadritos(int x, int y)
{
	int i;
	gotoxy(x,y);
	printf(MAGENTA_T"%c",218);
	gotoxy(x,y+1);
	printf("%c",179);
	gotoxy(x,y+2);
	printf("%c",192);
	gotoxy(x+4,y+1);
	printf("%c",179);
	
	for(i=0;i<LONGITUD;i++)
	{
		gotoxy(x+(i*4)+1,y);
		printf("%c%c%c%c",196,196,196,194);
		gotoxy(x+(i*4)+4,y+1);
		printf("%c",179);
		gotoxy(x+(i*4)+1,y+2);
		printf("%c%c%c%c",196,196,196,193);
	}
	gotoxy(x+(i*4)+1,y);
	printf("%c%c%c%c",196,196,196,191);
		gotoxy(x+3+(i*4)+1,y+1);
	printf("%c",179);
	gotoxy(x+(i*4)+1,y+2);
	printf("%c%c%c%c"RESET_COLOR,196,196,196,217);
}


void mostrar() {
    
    initwindow(1366, 768);
    
    // Llamar a la función dibujar
    animacion();

    // Esperar una entrada del usuario antes de cerrar la ventana
    getch();

    // Cerrar la ventana
    closegraph();
}

void animacion() {
    int radio = 20;
    
    // Coordenadas de los nodos
    int q1_x = 700, q1_y = 150;
    int q0_x = 400, q0_y = 150;
    int q2_x = 600, q2_y = 550;

    // Dibujar los círculos en las coordenadas especificadas
    circle(q0_x, q0_y, radio);
    circle(q1_x, q1_y, radio);
    circle(q2_x, q2_y, radio);
    circle(q2_x, q2_y, 27);

	line(q0_x+30,q0_y-10,q1_x-30,q1_y-10);
    line(q1_x-30,q1_y+10,q0_x+30,q0_y+10);
    line(q0_x,q0_y+radio,q2_x-10,q2_y-radio);
    line(q1_x,q1_y+radio,q2_x+10,q2_y-radio);
    

	//arcos
	ellipse(q0_x, q0_y-radio, 0, 180, 20, 40);
	ellipse(q1_x, q1_y-radio, 0, 180, 20, 40);


	// Dibujar la flecha q0
    line(q0_x+18, q0_y-radio, q0_x+ 23, q0_y - radio-10);
    line(q0_x+18, q0_y-radio, q0_x+ 13, q0_y - radio-10);

    // Dibujar la flecha q1
    line(q1_x+18, q1_y-radio, q1_x+ 23, q1_y - radio-10);
    line(q1_x+18, q1_y-radio, q1_x+ 13, q1_y - radio-10);
    
    //dibujar la flecha de q0 a q1 
    line(q1_x-radio, q1_y-10, q1_x-radio-10, q1_y - 15);//el ultimo numero es el alto de la flecha
    line(q1_x-radio, q1_y-10, q1_x-radio-10, q1_y-5 );//el ultimo numero es el alto de la flecha
	//dibujar la flecha de q1 a q0
	line(q0_x+radio, q0_y+10, q0_x+radio+10, q0_y +5);//el ultimo numero es el alto de la flecha
	line(q0_x+radio, q0_y+10, q0_x+radio+10, q0_y +15);//el ultimo numero es el alto de la flecha
 
 	//dibujar la flechade q0 a q3
 	line(q2_x-10, q2_y-radio, q2_x-20, q2_y -radio-7);
 	line(q2_x-10, q2_y-radio, q2_x-9, q2_y -radio-11);
 	
 	//de q1 a q3
	line(q2_x+10, q2_y-radio, q2_x+8, q2_y -radio-11);
	line(q2_x+10, q2_y-radio, q2_x+22, q2_y -radio-5);

	//declarando inicio
	line(q0_x-radio, q0_y, q0_x-radio- 13, q0_y +10);
    line(q0_x-radio, q0_y, q0_x-radio- 13, q0_y -10);

    line(q0_x-radio-26,q0_y,q0_x-radio,q0_y);
    
    // Etiquetas para los nodos
    char nombre_q0[] = "q0";
    char nombre_q1[] = "q1";
    char nombre_q2[] = "q2";

	//etquetas de las transiciones
	char t1[]="0;0,L | 0;0,L | -;0,L | -;-,S";
	char t2[]="0;0,L | 1;1,L | -;1,L | -;-,S";
	char t3[]="1;1,L | 1;1,L | -;0,L | -;1,S";
	char t4[]="1;1,L | 0;0,L | -;1,L | -;-,S";
	char t5[]="-;-,S | -;-,S | -;-,S | -;-,S";
	char j1[]="-;-,L | -;-,L | -;1,L | 1;-,S";
	char k1[]="1;1,L | 1;1,L | -;0,L | -;1,S";
	char p1[]="0;0,L | 0;0,L | -;1,L | 1;-,S";
	
	//q1
	char l[]="0;0,L | 1;1,L | -;0,L | 1;1,S";
	char l1[]="1;1,L | 1;1,L | -;1,L | 1;1,S";
	char l2[]="1;1,L | 0;0,L | -;0,L | 1;1,S";
	
		setcolor(YELLOW);
    // Etiquetas para los nodos
    outtextxy(q0_x - 10, q0_y - 10, nombre_q0);
    outtextxy(q1_x - 10, q1_y - 10, nombre_q1);
    outtextxy(q2_x - 10, q2_y - 10, nombre_q2);
    
    //q0
    outtextxy(q0_x-70,q0_y-90,t1);
    outtextxy(q0_x-70,q0_y-107,t2);
    outtextxy(q0_x-70,q0_y-120,t3);
    outtextxy(q0_x-70,q0_y-137,t4);
    outtextxy(300,q0_y+200,t5);
    
    //q1
    outtextxy(q1_x-70,q1_y-90,l);
    outtextxy(q1_x-70,q1_y-107,l1);
    outtextxy(q1_x-70,q1_y-120,l2);
    //q2 conexion
    outtextxy(720,q0_y+200,j1);
    
    //Q1 conexion
	outtextxy(530,q0_y-35,k1);  
	outtextxy(530,q0_y+15,p1);    
    
    
    
    
    
    
    
    
    
    
}

