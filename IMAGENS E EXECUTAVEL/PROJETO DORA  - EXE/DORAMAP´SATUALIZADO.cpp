#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include "dora.h"
//REGISTRO CRIADO
typedef struct
{
    //
    char populacao[200];
    char destinos[200];
    char curiosidades[200];

} continente;

void botao(int x1, int y1, int x2, int y2, char rotulo[30]);
void botaoPressionado(int x1, int y1, int x2, int y2, char rotulo[30]);

int main()
{
    //VETORES PARA GUARDAR AS INFORMAÇOES
    continente C[6]=
    {
        //INFORMAÇÕES EUROPEU
        "751,6M (2023)","Torre Eiffel – França, Coliseu de Roma – Itália, Atenas – Grécia","Mais de 60 línguas são faladas no continente europeu",
        //INFROMAÇÕES OCEANIA
        "37,1M (2023)","Pontos turisticos mais visitados: Sidney (Austrália), Grande Barreira de Corais (Austrália), Ilha Kangaroo (Austrália)"," A Oceania é o menor continente do mundo e também o mais novo, Austrália não faz fronteira com nenhum outro país",
        //INFORMAÇÕES AMERICA
        "America do SUL - 444,6M / America do NORTE - 609,5M / America CENTRAL - 75,3M / TOTAL - 1,129,556,948B ","Paises mais visitados da America são: México, Estados Unidos, Argentina"," Os oceanos Pacífico, Glacial Ártico e Atlântico banham o continente, que é o segundo maior e mais comprido do mundo",
        //INFROMAÇÕES ANTARTIDA
        "4 mil pessoas durante o verão e 800 pessoas durante o inverno","Ilha de Ross, Peter I island","É o continente mais frio, seco, com a maior média de altitude e de maior índice de ventos fortes do planeta",
        //INFORMAÇÕES ASIA
        "4,794,705,221B (2023)"," 5 destinos mais visitados da Asia, Tóquio - (Japão), Pequim - (China), Dubai - (Emirados Árabes), Ilhas Maldivas, Bangkok - (Tailândia)","O maior continente do mundo, o maior número de bilionários do mundo, as maiores montanhas do mundo",
        //INFORMAÇÕES AFRICA
        "1,445,067,147B (2023)","5 paises mais visitados da Africa: África do Sul, Moçambique, Zimbabwe,  Marrocos, Egito","Dos 30 países mais pobres do mundo, 21 são africanos"
    };

//------------------------------------------------------------------------------------------------------------------------------------------------

    // FOI DECLARADO PARA CONSEGUIR REDESENHAR, E CONTROLAR A POSIÇÃO DE CADA TELA
    int redesenharx = 0, i, c=0;
    int controle=0;
    int indice=0;

    // CRIA E ABRE UMA JANELA GRAFICA DE 1280x680 (LARGURAxALTURA)
    initwindow(1920, 1080, "PROJETO DORA AVENTUREIRA", 0,0);
    readimagefile("mapa.jpg",0,0,1920,1080);

    //  MOSTRA AS CORDENADAS DO MOUSE NA TELA DE EXIBIÇÃO, E NAO DA GRAFICA
    printf("Largura Maxima da Tela = %d\n", getmaxwidth());
    printf("Altura Maxima da Tela = %d\n", getmaxheight());
    printf("Largura Maxima da Janela = %d\n", getmaxx());
    printf("Altura Maxima da Janela = %d\n", getmaxy());

    // CRIADO UM MODO DE REPETIÇÃO PARA AS TELAS
    while(!kbhit())
    {
        printf("\nX=%d, Y=%d",mousex(),mousey());

        if (mousex() >= 780 && mousex() <= 1145 &&
                mousey() >= 330 && mousey() <= 1000 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)
            // AQUI FAZ O BOTAO DAR A ARTE DE CLICAR, COM UM DELAY DE (200) E REDESENHA A PAGINA DA EUROPA
        {

            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            Continente();

            // BOTOES QUE IRÁ APAFRECER NA TELA INICIAL
            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");
            controle = 0;
        }

//------------------------------------------------------------------------------------------------------------------------------------------------
// EUROPA
// VE SE O MOUSE ESTA NA POSIÇAO ESPECIICADA, E SE O BOTAO ESQUERDO DO MOUSE FOI CLICKADO, O CONTROLE == 0 DIZ QUE VOCE ESTA NA PAGINA 0

        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 850 && mousey() <= 875 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)

            // AQUI FAZ O BOTAO DAR A ARTE DE CLICAR, COM UM DELAY DE (200) E REDESENHA A PAGINA DA EUROPA
        {
            indice =0;
            botaoPressionado(20,850,130,875,"EUROPA");
            delay(200);
            botao(20,850,130,875,"EUROPA");
            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("europeu.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            sobreEuropa();

            //AQUI ELE MOSTRA A OS OPÇOES QUE VAI APARECER AO CLICAR EM EUROPA E APARECER NA PAGINA DA EUROPA
            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");
            controle = 1;
        }


        //COMANDO QUE FAZ CLICAR NA POPULAÇÃO E MOSTRAR A POSIÇÃO 0 DO VETOR POPULAÇÃOO
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 510 && mousey() <= 535 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 1)

        {
            botaoPressionado(20,510,130,535,"POPULAÇÃO");
            delay(200);
            botao(20,510,130,535,"POPULAÇÃO");

            outtextxy(1290,140,C[indice].populacao);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA DESTINOS E MOSTRAR A POSIÇÃO 0 DO VETOR DESTINOS
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 535 && mousey() <= 560 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 1)

        {
            botaoPressionado(20,535,130,560,"DESTINOS");
            delay(200);
            botao(20,535,130,560,"DESTINOS");

            outtextxy(1290,165,C[indice].destinos);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA CURIOSIDADES E MOSTRAR A POSIÇÃO 0 DO VETOR CURIOSIDADE
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 560 && mousey() <= 585 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 1)

        {
            botaoPressionado(20,560,130,585,"CURIOSIDADES");
            delay(200);
            botao(20,560,130,585,"CURIOSIDADES");

            outtextxy(1290,190,C[indice].curiosidades);

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 600 && mousey() <= 625 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 1)

        {
            botaoPressionado(20,600,130,625,"VOLTAR");
            delay(200);
            botao(20,600,130,625,"VOLTAR");

            if (redesenharx > 0)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            controle = 0;

            Continente();

            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");

        }

//------------------------------------------------------------------------------------------------------------------------------------------------
// OCEANIA

        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 875 && mousey() <= 900 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)
        {
            indice = 1 ;
            botaoPressionado(20,875,130,900,"OCEANIA");
            delay(200);
            botao(20,875,130,900,"OCEANIA");

            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("oceania.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            sobreOceania();

            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");

            controle = 2;

        }
        //COMANDO QUE FAZ CLICAR NA POPULAÇÃO E MOSTRAR A POSIÇÃO 0 DO VETOR POPULAÇÃOO
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 510 && mousey() <= 535 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 2)

        {
            botaoPressionado(20,510,130,535,"POPULAÇÃO");
            delay(200);
            botao(20,510,130,535,"POPULAÇÃO");

            outtextxy(1130,140,C[indice].populacao);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA DESTINOS E MOSTRAR A POSIÇÃO 0 DO VETOR DESTINOS
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 535 && mousey() <= 560 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 2)

        {
            botaoPressionado(20,535,130,560,"DESTINOS");
            delay(200);
            botao(20,535,130,560,"DESTINOS");

            outtextxy(1130,165,C[indice].destinos);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA CURIOSIDADES E MOSTRAR A POSIÇÃO 0 DO VETOR CURIOSIDADE
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 560 && mousey() <= 585 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 2)

        {
            botaoPressionado(20,560,130,585,"CURIOSIDADES");
            delay(200);
            botao(20,560,130,585,"CURIOSIDADES");

            outtextxy(1130,190,C[indice].curiosidades);

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 600 && mousey() <= 625 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 2)

        {
            botaoPressionado(20,600,130,625,"VOLTAR");
            delay(200);
            botao(20,600,130,625,"VOLTAR");

            if (redesenharx > 0)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            controle = 0;

            Continente();

            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");
        }

//------------------------------------------------------------------------------------------------------------------------------------------------
// AMERICA

        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 900 && mousey() <= 925 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)
        {
            indice = 2;
            botaoPressionado(20,900,130,925,"AMERICA");
            delay(200);
            botao(20,900,130,925,"AMERICA");

            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("americano.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            sobreAmerica();

            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");
            controle = 3;
        }

        //COMANDO QUE FAZ CLICAR NA POPULAÇÃO E MOSTRAR A POSIÇÃO 0 DO VETOR POPULAÇÃOO
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 510 && mousey() <= 535 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 3)

        {
            botaoPressionado(20,510,130,535,"POPULAÇÃO");
            delay(200);
            botao(20,510,130,535,"POPULAÇÃO");

            outtextxy(1130,140,C[indice].populacao);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA DESTINOS E MOSTRAR A POSIÇÃO 0 DO VETOR DESTINOS
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 535 && mousey() <= 560 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 3)

        {
            botaoPressionado(20,535,130,560,"DESTINOS");
            delay(200);
            botao(20,535,130,560,"DESTINOS");

            outtextxy(1130,165,C[indice].destinos);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA CURIOSIDADES E MOSTRAR A POSIÇÃO 0 DO VETOR CURIOSIDADE
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 560 && mousey() <= 585 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 3)

        {
            botaoPressionado(20,560,130,585,"CURIOSIDADES");
            delay(200);
            botao(20,560,130,585,"CURIOSIDADES");

            outtextxy(1130,190,C[indice].curiosidades);

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 600 && mousey() <= 625 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle ==3)
        {
            botaoPressionado(20,600,130,625,"VOLTAR");
            delay(200);
            botao(20,600,130,625,"VOLTAR");

            if (redesenharx > 0)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 0;

            Continente();

            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");
        }

//------------------------------------------------------------------------------------------------------------------------------------------------
//ANTARDIA

        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 925 && mousey() <= 950 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)
        {
            indice = 3;
            botaoPressionado(20,925,130,950,"ANTARTIDA");
            delay(200);
            botao(20,925,130,950,"ANTARTIDA");

            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("antartida.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 4;

            sobreAntartida();

            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");
        }

//COMANDO QUE FAZ CLICAR NA POPULAÇÃO E MOSTRAR A POSIÇÃO 0 DO VETOR POPULAÇÃOO
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 510 && mousey() <= 535 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 4)

        {
            botaoPressionado(20,510,130,535,"POPULAÇÃO");
            delay(200);
            botao(20,510,130,535,"POPULAÇÃO");

            outtextxy(1130,140,C[indice].populacao);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA DESTINOS E MOSTRAR A POSIÇÃO 0 DO VETOR DESTINOS
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 535 && mousey() <= 560 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 4)

        {
            botaoPressionado(20,535,130,560,"DESTINOS");
            delay(200);
            botao(20,535,130,560,"DESTINOS");

            outtextxy(1130,165,C[indice].destinos);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA CURIOSIDADES E MOSTRAR A POSIÇÃO 0 DO VETOR CURIOSIDADE
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 560 && mousey() <= 585 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 4)

        {

            botaoPressionado(20,560,130,585,"CURIOSIDADES");
            delay(200);
            botao(20,560,130,585,"CURIOSIDADES");

            outtextxy(1130,190,C[indice].curiosidades);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        // BOTAO INVISIVEL EASTEREGG
        if (mousex() >= 1880 && mousex() <= 1920 &&
                mousey() >= 1030 && mousey() <= 1053 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 4)

        {
            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("esteregg.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            botaoPressionado(20,920,130,955,"VOLTAR");
            delay(200);
            botao(20,920,130,955,"VOLTAR");

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 5;
        }

        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 920 && mousey() <= 955 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 5)
        {
            botaoPressionado(20,920,130,955,"VOLTAR");
            delay(200);
            botao(20,920,130,955,"VOLTAR");

            if (redesenharx > 50)
                redesenharx = redesenharx;
            readimagefile("antartida.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 4;

            setbkcolor(15); // Define o fundo como branco
            setcolor(0);   // Define a cor da escrita como preto
            outtextxy(20,485,"SOBRE ANTARTIDA");

            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");
        }


        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 600 && mousey() <= 625 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 4)

        {
            botaoPressionado(20,600,130,625,"VOLTAR");
            delay(200);
            botao(20,600,130,625,"VOLTAR");

            if (redesenharx > 0)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 0;

            Continente();

            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");
        }

//------------------------------------------------------------------------------------------------------------------------------------------------
// ASIA
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 950 && mousey() <= 975 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)

            // AQUI FAZ O BOTAO DAR A ARTE DE CLICAR, COM UM DELAY DE (200) E REDESENHA A PAGINA DA EUROPA
        {
            indice =4;
            botaoPressionado(20,950,130,975,"ASIA");
            delay(200);
            botao(20,950,130,975,"ASIA");

            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("asia.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            sobreAsia();

            //AQUI ELE MOSTRA A OS OPÇOES QUE VAI APARECER AO CLICAR EM EUROPA E APARECER NA PAGINA DA EUROPA
            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");
            controle = 6;
        }


        //COMANDO QUE FAZ CLICAR NA POPULAÇÃO E MOSTRAR A POSIÇÃO 0 DO VETOR POPULAÇÃOO
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 510 && mousey() <= 535 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 6)

        {
            botaoPressionado(20,510,130,535,"POPULAÇÃO");
            delay(200);
            botao(20,510,130,535,"POPULAÇÃO");

            outtextxy(1040,625,C[indice].populacao);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA DESTINOS E MOSTRAR A POSIÇÃO 0 DO VETOR DESTINOS
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 535 && mousey() <= 560 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 6)

        {
            botaoPressionado(20,535,130,560,"DESTINOS");
            delay(200);
            botao(20,535,130,560,"DESTINOS");

            outtextxy(1040,650,C[indice].destinos);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA CURIOSIDADES E MOSTRAR A POSIÇÃO 0 DO VETOR CURIOSIDADE
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 560 && mousey() <= 585 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 6)

        {
            botaoPressionado(20,560,130,585,"CURIOSIDADES");
            delay(200);
            botao(20,560,130,585,"CURIOSIDADES");

            outtextxy(1040,675,C[indice].curiosidades );

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 600 && mousey() <= 625 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 6)
        {
            botaoPressionado(20,600,130,625,"VOLTAR");
            delay(200);
            botao(20,600,130,625,"VOLTAR");

            if (redesenharx > 0)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 0;

            Continente();

            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");
        }
//------------------------------------------------------------------------------------------------------------------------------------------------
// AFRICA
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 975 && mousey() <= 1000 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 0)

            // AQUI FAZ O BOTAO DAR A ARTE DE CLICAR, COM UM DELAY DE (200) E REDESENHA A PAGINA DA EUROPA
        {
            indice =5;
            botaoPressionado(20,975,130,1000,"AFRICA");
            delay(200);
            botao(20,975,130,1000,"AFRICA");
            if (redesenharx < 50)
                redesenharx = redesenharx;
            readimagefile("africa.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);

            sobreAfrica();

            //AQUI ELE MOSTRA A OS OPÇOES QUE VAI APARECER AO CLICAR EM EUROPA E APARECER NA PAGINA DA EUROPA
            botao(20,510,130,535,"POPULAÇÃO");
            botao(20,535,130,560,"DESTINOS");
            botao(20,560,130,585,"CURIOSIDADES");
            botao(20,600,130,625,"VOLTAR");
            controle = 7;
        }

        //COMANDO QUE FAZ CLICAR NA POPULAÇÃO E MOSTRAR A POSIÇÃO 0 DO VETOR POPULAÇÃOO
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 510 && mousey() <= 535 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle ==7)

        {
            botaoPressionado(20,510,130,535,"POPULAÇÃO");
            delay(200);
            botao(20,510,130,535,"POPULAÇÃO");

            outtextxy(1130,140,C[indice].populacao);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA DESTINOS E MOSTRAR A POSIÇÃO 0 DO VETOR DESTINOS
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 535 && mousey() <= 560 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 7)

        {
            botaoPressionado(20,535,130,560,"DESTINOS");
            delay(200);
            botao(20,535,130,560,"DESTINOS");

            outtextxy(1130,165,C[indice].destinos);

            clearmouseclick(WM_LBUTTONDOWN);
        }

        //COMANDO QUE FAZ CLICAR NA CURIOSIDADES E MOSTRAR A POSIÇÃO 0 DO VETOR CURIOSIDADE
        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 560 && mousey() <= 585 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 7)

        {
            botaoPressionado(20,560,130,585,"CURIOSIDADES");
            delay(200);
            botao(20,560,130,585,"CURIOSIDADES");

            outtextxy(1130,190,C[indice].curiosidades);

            clearmouseclick(WM_LBUTTONDOWN);
        }


        if (mousex() >= 20 && mousex() <= 130 &&
                mousey() >= 600 && mousey() <= 625 &&
                ismouseclick(WM_LBUTTONDOWN)&& controle == 7)
        {
            botaoPressionado(20,600,130,625,"VOLTAR");
            delay(200);
            botao(20,600,130,625,"VOLTAR");

            if (redesenharx > 0)
                redesenharx = redesenharx;
            readimagefile("telainicial.jpg",-redesenharx,0,
                          1920-redesenharx,1080);

            clearmouseclick(WM_LBUTTONDOWN);
            controle = 0;

            Continente();

            botao(20,850,130,875,"EUROPA");
            botao(20,875,130,900,"OCEANIA");
            botao(20,900,130,925,"AMERICA");
            botao(20,925,130,950,"ANTARTIDA");
            botao(20,950,130,975,"ASIA");
            botao(20,975,130,1000,"AFRICA");
        }
    }

    getchar();

// fecha o modo gráfico e retorna ao modo de saída-padrão (texto)

    closegraph();
}

//------------------------------------------------------------------------------------------------------------------------------------------------
// INFORMAÇÕES DO PROGRAMA

void botao(int x1, int y1, int x2, int y2, char rotulo[30])
{
    setfillstyle(1,0);
    bar(x1,y1,x2,y2);

    setlinestyle(0,0,2);
    setcolor(15);
    line(x1,y1,x2,y1);
    line(x1,y1,x1,y2);

    setcolor(15);
    line(x2,y1+2,x2,y2);
    line(x1+2,y2,x2,y2);

    setbkcolor(0);
    setcolor(15);
    outtextxy(x1 + ((x2-x1-(strlen(rotulo)*8))/2) + 2, y1+8, rotulo);
}
void botaoPressionado(int x1, int y1, int x2, int y2, char rotulo[30])
{
    setfillstyle(1,0);
    bar(x1,y1,x2,y2);

    setlinestyle(0,0,2);
    setcolor(12);
    line(x1,y1,x2,y1);
    line(x1,y1,x1,y2);

    setcolor(12);
    line(x2,y1+2,x2,y2);
    line(x1+2,y2,x2,y2);

    setbkcolor(0);
    setcolor(12);
    outtextxy(x1 + ((x2-x1-(strlen(rotulo)*8))/2) + 2, y1+9, rotulo);
}
