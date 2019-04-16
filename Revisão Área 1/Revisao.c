/*
1) -
    A) "estudar ponteiros é pouco divertido"

    B)  aux1: “ponteiros”
        aux2: “é”
        aux3: "pouco"
        aux4: “divertido”
        aux5: NULL
        aux6: “é”
        aux7: “divertido”
        aux8: Lixo
        aux9: Lixo

    C) "estudar ponteiros é muito"
    D)  aux1: “ponteiros”
        aux2: “é”
        aux3: Lixo
        aux4: “divertido”
        aux5: NULL
        aux6: “é”
        aux7: “divertido”
        aux8: “muito”
        aux9: Lixo
    E) "estudar ponteiros é muito divertido"

2) C

3) C

4)
    ptLista* retornaMeio(ptLista* p){
        if(p != NULL){
            ptLista* aux1 = p;
            ptLista* aux2 = p->ant;
            while(aux1 != aux2){
                aux1 = aux1->prox;
                if(aux1 != aux2){
                    aux2 = aux2->ant;
                }
            }
            return aux1;
        }
        return NULL;
    }

5)
    ...
    1) aux1 = letra1->ant;
    2) aux2 = letra2->prox;
    3) aux1->prox = letra2;
    4) aux2->ant = letra1;
    5) letra1->prox->ant = letra2;
    6) letra2->ant->prox = letra1;
    7) letra1->ant = letra2->ant;
    8) letra2->prox = letra1->prox;
    9) letra2->ant = aux1;
    10) letra1->prox = aux2;
    ...

    Ex.: letra1 = C, letra 2 = R, palavra = TROCA
    1) aux1 = O
    2) aux2 = O
    3) O->prox = R
    4) O-ant = C
    5) C->prox(A)->ant(C) = R;
    6) R->ant(T)->prox(R) = C;
    7) C-ant = R->ant (T)
    8) R-prox = C->prox (A)
    9) R->ant = O
    10) C->prox = O
*/
