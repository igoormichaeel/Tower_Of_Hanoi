#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <cmath>
int menu, jogar, dificuldade, melhor, novam, revan;
char usuario1[100], usuario2[100];
int i, t1[100], t2[100], t3[100], discos, origem, destino, aux_troca, cont=0, cont2=0;
int soma_t1=0, soma_t2=0, soma_t3=0, aux_soma, ultimo_t1, ultimo_t2, ultimo_t3; // �ltimos discos e somas dos discos
int ultimo_origem, ultimo_destino, pos_origem, pos_destino; // Auxiliares para saber qual � o valor do �ltimo disco, soma e tamb�m a posi��o para condi��es de troca
using namespace std;
void interface(){ // interface das torres
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "           Jogada perfeita: " << pow(2, discos)-1 << " ";
    cout << endl << "         Contador de jogadas: " << cont << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl;
    for (i=0; i<discos; i++){
        cout << endl << "    |" << t1[i] << "|          |" << t2[i] << "|             |" << t3[i] << "|" ;
    }
    cout << endl << "  Torre 1      Torre 2         Torre 3" << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }

}
void ultimo_e_soma(){ // Saber qual � o �ltimo disco e a soma dos discos das torres. (Utiliza no processo de saber se pode ou n�o mover um disco)
    ultimo_t1=100;
    ultimo_t2=100;
    ultimo_t3=100;
    soma_t1=0;
    soma_t2=0;
    soma_t3=0;
    for (i=0; i<discos; i++){
        soma_t1 += t1[i];
        soma_t2 += t2[i];
        soma_t3 += t3[i];
        if (t1[i]<ultimo_t1 && t1[i]!=0){
            ultimo_t1 = t1[i];
        }
        if (t2[i]<ultimo_t2 && t2[i]!=0){
            ultimo_t2 = t2[i];
        }
        if (t3[i]<ultimo_t3 && t3[i]!=0){
            ultimo_t3 = t3[i];
        }
    }
}
void auxiliar_soma(){ // Auxiliar de soma usado dentro das condi��es da origem. (A soma � usada para saber se a torre est� vazia)Pr�ximos auxiliares s�o dos �ltimos discos das torres de origem e destino. (Utilizado para saber se o disco da origem vai ser maior ou menor que o disco do destino)
    switch (origem){
        case 1:
            aux_soma=soma_t1;
            break;
        case 2:
            aux_soma=soma_t2;
            break;
        case 3:
            aux_soma=soma_t3;
            break;
        default:
            aux_soma=1;
            break;
    }
}
void auxiliar_ultimo_origem(){
    switch (origem){
        case 1:
            ultimo_origem=ultimo_t1;
            break;
        case 2:
            ultimo_origem=ultimo_t2;
            break;
        case 3:
            ultimo_origem=ultimo_t3;
            break;
    }
}
void auxiliar_ultimo_destino(){
    switch (destino){
        case 1:
            ultimo_destino=ultimo_t1;
            break;
        case 2:
            ultimo_destino=ultimo_t2;
            break;
        case 3:
            ultimo_destino=ultimo_t3;
            break;
    }
}
void mover_discos(){
    if (origem==1){
        for(i=0; i<discos; i++){ //Descobrir a posi��o do disco da origem
            if (t1[i]==ultimo_origem){
                pos_origem=i;
            }
        }
        aux_troca=t1[pos_origem];
        //Se o destino for a torre 2:
        if (destino==2){
            for(i=0; i<discos; i++){ // Descobrir a posi��o do disco do destino
                if(t2[i]==0){
                pos_destino=i;
                }
            }
            t1[pos_origem]=0;
            t2[pos_destino]=aux_troca;
            cont++;
        }
        //Se o destino for a torre 3:
        if (destino==3){
            for(i=0; i<discos; i++){ // Descobrir a posi��o do disco do destino
                if (t3[i]==0){
                    pos_destino=i;
                }
            }
            t1[pos_origem]=0;
            t3[pos_destino]=aux_troca;
            cont++;
        }
    }
    if (origem==2){
        for(i=0; i<discos; i++){ //Descobrir a posi��o do disco da origem
            if (t2[i]==ultimo_origem){
                pos_origem=i;
            }
        }
        aux_troca=ultimo_origem;
        //Se o destino for a torre 1:
        if (destino==1){
            for(i=0; i<discos; i++){ // Descobrir a posi��o do disco do destino
                if (t1[i]==0){
                    pos_destino=i;
                }
            }
            t2[pos_origem]=0;
            t1[pos_destino]=aux_troca;
            cont++;
        }
        //Se o destino for a torre 3:
        if (destino==3){
            for(i=0; i<discos; i++){ // Descobrir a posi��o do disco do destino
                if (t3[i]==0){
                    pos_destino=i;
                }
            }
            t2[pos_origem]=0;
            t3[pos_destino]=aux_troca;
            cont++;
        }
    }
    if (origem==3){
        for(i=0; i<discos; i++){ //Descobrir a posi��o do disco da origem
            if (t3[i]==ultimo_origem){
                pos_origem=i;
            }
        }
        aux_troca=ultimo_origem;
        //Se o destino for a torre 1:
        if (destino==1){
            for(i=0; i<discos; i++){ // Descobrir a posi��o do disco do destino
                if (t1[i]==0){
                    pos_destino=i;
                }
            }
            t3[pos_origem]=0;
            t1[pos_destino]=aux_troca;
            cont++;
        }
        //Se o destino for a torre 2:
        if (destino==2){
            for(i=0; i<discos; i++){ // Descobrir a posi��o do disco do destino
                if (t2[i]==0){
                    pos_destino=i;
                }
            }
            t3[pos_origem]=0;
            t2[pos_destino]=aux_troca;
            cont++;
        }
    }
}
void interface_menu(){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "             Menu principal" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl << endl << " 2 - Jogar" << endl << " 1 - Instru��es" << endl << " 0 - Sair" << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " -> Digite sua op��o: ";
    cin >> menu;
    while (menu!=1 && menu!=2 && menu!=0){
            cout << " Op��o inv�lida! Digite uma nova op��o (0, 1 ou 2): ";
            cin >> menu;
    }
}
void interface_instrucoes(){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "              Instru��es" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl;
    cout << "   O jogo tem como objetivo mover" << endl;
    cout << "   todos os discos, da torre 1 para" << endl;
    cout << "   a torre 3, respeitando as seguin-" << endl;
    cout << "   tes regras:" << endl;
    cout << "   - S� pode deslocar um disco de ca-" << endl;
    cout << "   da vez, movendo sempre o disco do" << endl;
    cout << "   topo da torre;" << endl;
    cout << "   - Um disco maior n�o pode ser co-" << endl;
    cout << "   locado sobre um disco menor." << endl;
    cout << "   Para jogar, voc� deve escolher pri-" << endl;
    cout << "   meiro a torre onde o disco se en-" << endl;
    cout << "   contra (torre de origem) e, logo" << endl;
    cout << "   em seguida, escolher a torre para" << endl;
    cout << "   a qual o disco vai (torre de desti-" << endl;
    cout << "   no)." << endl;
    cout << "   Cada n�vel de dificuldade possui" << endl;
    cout << "   uma quantidade de movimentos per-" << endl;
    cout << "   feitos para completar o objetivo," << endl;
    cout << "   ent�o, se voc� conseguir mover os" << endl;
    cout << "   discos nessa quantidade, ter� a" << endl;
    cout << "   melhor pontua��o. No caso do mul-" << endl;
    cout << "   tiplayer, vence o jogador que con-" << endl;
    cout << "   cluir o jogo com menos movimentos." << endl;
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " ";
    system("PAUSE");
    system("cls");
}
void interface_jogar(){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "                Jogar" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl << endl << " 2 - Multiplayer" << endl << " 1 - Individual" << endl << " 0 - Voltar para o menu principal" << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " -> Digite sua op��o: ";
    cin >> jogar;
    while (jogar!=1 && jogar!=2 && jogar!=0){
        cout << " Op��o inv�lida! Digite uma nova op��o (0, 1 ou 2): ";
        cin >> jogar;

}
}
void interface_dificuldade(){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "              Dificuldade" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl << endl << " 3 - Dif�cil (7 discos)" << endl << " 2 - Intermedi�rio (5 discos)" << endl << " 1 - F�cil (3 discos)" << endl << " 0 - Voltar para o menu anterior" << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " -> Digite sua op��o: ";
    cin >> dificuldade;
    while (dificuldade!=1 && dificuldade!=2 && dificuldade!=3 && dificuldade!=0){
        cout << " Op��o inv�lida! Digite uma nova op��o (0, 1 ou 2): ";
        cin >> dificuldade;
    }
}
void pontuacao(char us[]){
    system("cls");
    melhor=pow(2,discos)-1;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl;
    if (cont==melhor){
    cout << endl << "            Parab�ns, " << us << "!" << endl << "     Voc� obteve a melhor pontua��o!" << endl << " ";
    }
    else if (cont>melhor && cont<=melhor+(0.25*melhor)){
        cout << endl<<  "            Mandou bem, " << us << "!" << endl << " Mas voc� obteve uma pontua��o razo�vel." << endl << "           Voc� pode melhorar!" << endl << " ";
    }
    else{
        cout << endl << "      " << us << ", voc� precisa melhorar!" << endl << " ";
    }
    cout << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " ";
    system("PAUSE");
    system("cls");
}
void novamente(){
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "        Deseja jogar novamente?" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl;
    cout << endl << "              2 - Sim" << endl << "              1 - N�o" << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " -> Digite sua op��o: ";
    cin >> novam;
    while (novam!=1 && novam!=2){
        cout << " Op��o inv�lida! Digite uma nova op��o (1 ou 2): ";
        cin >> novam;
    }
}
void vez(char us[]){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << endl;
    cout << endl << "        Essa � a sua vez, " << us << endl << " ";
    cout << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " ";
    system("PAUSE");
}
void pont_mult(char us1[], char us2[]){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << endl;
    cout << endl << "       "<< us1 << ", sua pontua��o foi: " << cont << endl << " ";
    cout << "          Agora � a vez de " << us2 << endl;
    cout << "     Vamos ver quem vai ser melhor!" << endl << " ";
    cout << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " ";
    system("PAUSE");
}
void resultado_mult(char us1[], char us2[]){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl;
    if (cont>cont2){
            cout << endl << "       Parab�ns, " << us1 << ", voc� venceu! " << endl << "  Obteve uma pontua��o melhor que " << us2 << "!";
            cout << endl << "     "<< us2 << ", voc� precisa treinar mais!" << endl << " ";
    }
    else if (cont2>cont){
            cout << endl << "       Parab�ns, " << us2 << ", voc� venceu! " << endl << "  Obteve uma pontua��o melhor que " << us1 << "!";
            cout << endl << "     "<< us1 << ", voc� precisa treinar mais!" << endl << " ";
    }
    else{
        cout << endl << "               Shhh... " << endl << " "<<us1 << " e " << us2 << ", parece que houve um empate!" << endl;
    }
    cout << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout <<endl << " ";
    system("PAUSE");
}
void revanche (char us1[], char us2[]){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "E a�, " << us1 << " e " << us2 << ", v�o querer uma revanche?" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl << endl << " 2 - Sim" << endl << " 1 - N�o" << endl << endl << " ";
    cout << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " -> Digite sua op��o: ";
    cin >> revan;
    while (revan!=1 && revan!=2){
        cout << " Op��o inv�lida! Digite uma nova op��o (1 ou 2): ";
        cin >> revan;
    }
}
void jogo(char us[]){
    system("cls");
    for (i=0; i<discos; i++){
        t1[i]=i+1;
        t2[i]=t3[i]=0;
    }
    ultimo_e_soma();
    interface();
    while (soma_t1!=0 || soma_t2!=0){
    cout << endl << " -> " << us << ", digite a torre de origem (1, 2 ou 3): ";
    cin >> origem;
    auxiliar_soma();
    auxiliar_ultimo_origem();
    while (origem<1 || origem >3 || aux_soma==0){
        if (origem<1 || origem >3){
            cout << " Torre de origem inv�lida! Digite uma torre v�lida (1, 2 ou 3): ";
        }
        if (aux_soma==0){
            cout << " N�o h� discos na torre de origem! Digite uma outra torre: ";
        }
        cin >> origem;
        auxiliar_soma();
        auxiliar_ultimo_origem();
    }
    interface();
    cout << endl << " -> " << us << ", digite a torre de destino (1, 2 ou 3): ";
    cin >> destino;
    auxiliar_ultimo_destino();
    while (destino<1 || destino>3 || destino==origem || ultimo_origem>ultimo_destino){
        if (destino<1 || destino>3) {
            cout << " Torre de destino inv�lida! Digite uma torre v�lida (1, 2 ou 3): " << endl << endl << " ";
        }
        else if (destino==origem){
            cout << " A torre de destino n�o pode ser igual a torre de origem! Digite um outro destino: " << endl << endl << " ";
        }
        else if (ultimo_origem>ultimo_destino){
            cout << " Jogada inv�lida: disco da origem � maior que o disco do destino!" << endl << endl << " ";
        }
        system("PAUSE");
        interface();
        cout << endl << " -> " << us << ", digite a torre de origem (1, 2 ou 3): ";
        cin >> origem;
        auxiliar_soma();
        auxiliar_ultimo_origem();
        while (origem<1 || origem >3 || aux_soma==0){
            if (origem<1 || origem >3){
                cout << " Torre de origem inv�lida! Digite uma torre v�lida (1, 2 ou 3): ";
            }
            if (aux_soma==0){
                cout << " N�o h� discos na torre de origem! Digite uma outra torre: ";
            }
            cin >> origem;
            auxiliar_soma();
            auxiliar_ultimo_origem();
        }
        interface();
        cout << endl << " -> " << us << ", digite a torre de destino (1, 2 ou 3): ";
        cin >> destino;
        auxiliar_ultimo_destino();
    }
    mover_discos();
    ultimo_e_soma();
    interface();
    }
}
void despedida (){
    system("cls");
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "       T O R R E   DE   H A N � I" << endl;
    cout << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << "      Jogo finalizado com sucesso!" << endl << " ";
    for (i=0; i<39; i++){
        cout << "-";
    }
    cout << endl << endl << endl << " Desenvolvido por:" << endl << "           Igor Michael e Adeilze Keilly" << endl << endl << endl << " ";
    for (i=0; i<13; i++){
        cout << "=-=";
    }
    cout << endl << " ";
    system("PAUSE");
}
int main (){
    setlocale (LC_ALL, "Portuguese");
    interface_menu();
    while (menu!=0){
        switch (menu){
            case 2:
                interface_jogar();
                while (jogar!=0){
                    switch (jogar){
                        case 1:
                            cout << " -> Digite o nome do usu�rio: ";
                            cin.ignore();
                            cin.getline(usuario1,100);
                            interface_dificuldade();
                            while (dificuldade!=0){
                                switch (dificuldade){
                                    case 1:
                                        cont=0;
                                        discos=3;
                                        jogo(usuario1);
                                        break;
                                    case 2:
                                        cont=0;
                                        discos=5;
                                        jogo(usuario1);
                                        break;
                                    case 3:
                                        cont=0;
                                        discos=7;
                                        jogo(usuario1);
                                        break;
                                }
                                pontuacao(usuario1);
                                novamente();
                                if (novam==2){
                                    interface_dificuldade();
                                }
                                if (novam==1){
                                    despedida();
                                    return(0);
                                }
                            }
                            break;
                        case 2:
                            cout << " -> Digite o nome do primeiro usu�rio: ";
                            cin.ignore();
                            cin.getline(usuario1,100);
                            cout << " -> Digite o nome do segundo usu�rio: ";
                            cin.getline(usuario2,100);
                            interface_dificuldade();
                            while (dificuldade!=0){
                                switch (dificuldade){
                                    case 1:
                                        cont=0;
                                        discos=3;
                                        vez(usuario1);
                                        interface();
                                        jogo(usuario1);
                                        pont_mult(usuario1, usuario2);
                                        cont2=cont;
                                        cont=0;
                                        jogo(usuario2);
                                        break;
                                    case 2:
                                        cont2=0;
                                        discos=5;
                                        vez(usuario1);
                                        interface();
                                        jogo(usuario1);
                                        pont_mult(usuario1, usuario2);
                                        cont2=cont;
                                        cont=0;
                                        jogo(usuario2);
                                        break;
                                    case 3:
                                        cont2=0;
                                        discos=7;
                                        vez(usuario1);
                                        interface();
                                        jogo(usuario1);
                                        pont_mult(usuario1, usuario2);
                                        cont2=cont;
                                        cont=0;
                                        jogo(usuario2);
                                        break;
                                }
                                resultado_mult(usuario1, usuario2);
                                revanche(usuario1, usuario2);
                                if (revan==2){
                                    interface_dificuldade();
                                    }
                                if (revan==1){
                                    despedida();
                                    return(0);
                                }
                            }
                            break;
                    }
                    interface_jogar();
                }
                break;
            case 1:
                interface_instrucoes();
         }
        interface_menu();
    }
    despedida();
}
