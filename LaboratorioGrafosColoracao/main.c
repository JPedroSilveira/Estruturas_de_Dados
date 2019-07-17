#include "caminhamentos.h"
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i,j;
    int grafo[max+1][max+1];
    int vis[max+1];


    //para inicializar o gráfo com 0
    for(i=1; i<=max; i++)
        for(j=1; j<=max; j++)
            grafo[i][j]=0;

    for (i=1; i<=max; i++)
        vis[i]=false; //inicializando vetor de vertices visitados

    grafo[1][2]=1;
    grafo[1][6]=1;

    grafo[2][1]=1;
    grafo[2][3]=1;
    grafo[2][4]=1;

    grafo[3][2]=1;
    grafo[3][4]=1;

    grafo[4][2]=1;
    grafo[4][3]=1;
    grafo[4][6]=1;

    grafo[5][3]=1;
    grafo[5][4]=1;
    grafo[5][6]=1;

    i=1;
    int g = 0;
    int maiorGrau = buscaVerticeDeMaiorGrau(grafo, i, vis, &g);

    for (i=1; i<=max; i++)
        vis[i]=false; //inicializando vetor de vertices visitados

    puts("DFS: Colorido");
    coloreGrafoDFS(grafo, maiorGrau, vis);

    for (i=1; i<=max; i++)
        vis[i]=false; //inicializando vetor de vertices visitados

    puts("\n\nBFS: Colorido");
    coloreGrafoBFS(grafo, maiorGrau, vis);

    puts("\nEh Fonte ou Sumidouro");
    printf("%d", ehFonteOuSumidouro(grafo, 5));
    printf("%d", ehFonteOuSumidouro(grafo, 6));
}

void coloreGrafoDFS(int grafo[max+1][max+1], int v, int vis[max+1]){
    int w;
    vis[v]= escolheCor(grafo, v, vis);

    printf("Vertice: %d, Cor: %d\n",v, vis[v]); //Imprime o vertice e a cor

    for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
        if ((grafo[v][w] == 1) && (vis[w] == 0))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
            coloreGrafoDFS(grafo, w, vis); //chamada recursiva para o vértice adjacente a v
}

void coloreGrafoBFS (int grafo[max+1][max+1], int v, int vis[max+1]){
    int w;
    TipoFila *FV;

    FV = cria_fila();
    FV = insere(FV,v);
    vis[v] = escolheCor(grafo, v, vis);
    while (!vazia(FV))
    {
        v = removeFila(&FV);
        printf("Vertice: %d, Cor: %d\n",v, vis[v]); //Imprime o vertice e a cor
        for(w = 1; w<=max ; w++){//percorre os vértices adjacentes a v
            if ((grafo[v][w]== 1) && (vis[w] == 0))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
            {
                FV = insere(FV,w);
                vis[w] = escolheCor(grafo, w, vis);
            }
        }
    }
}

int escolheCor(int grafo[max+1][max+1], int v, int vis[max+1]){
    int coresUsadas[max+1];
    int count = 1;
    int cor = 1;
    int corAdjascente;
    int w;

    for(w = 1; w<=max ; w++){ //percorre os vértices adjacentes a v
        if ((grafo[v][w]== 1) && (vis[w] > 0)){ //encontra os vértices adjacentes a v que já foram visitados
            coresUsadas[count] = vis[w];
            count ++;
        }
    }

    do{
        corAdjascente = 0;
        for(w = 1; w<=max ; w++){ //percorre os vértices adjacentes a v
            if(cor == coresUsadas[w]){ //Verifica se a cor já foi utilizada
                corAdjascente = 1;
                cor++;
            }
        }
    }while(corAdjascente);

    return cor;
}

//Retorna o maior vertice em questão de grau
int buscaVerticeDeMaiorGrau(int grafo[max+1][max+1], int v, int vis[max+1], int *grau){
    int count = 0;
    int w;
    vis[v]= 1;

    for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
        if ((grafo[v][w] == 1))  //encontra os vértices adjacentes a v
            count++; //adiciona 1 a contagem de vertices

    for(w = 1; w<=max ; w++){//percorre os vértices adjacentes a v
        if ((grafo[v][w]== 1) && (vis[w]==false)){//encontra um vértice adjacente a v que ainda nao tenha sido visitado
            int maiorVerticeAdjascente = buscaVerticeDeMaiorGrau(grafo, w, vis, grau); //Busca o maior grau recursivamente

            if(count > *grau){ //Compara o grau atual com o recursivo para retornar o vertice de maior grau
                *grau = count;
                return v;
            } else {
                return maiorVerticeAdjascente;
            }
        }
    }
}

int ehFonteOuSumidouro(int grafo[max+1][max+1], int v){
    //Percorre a linha do vertice para saber se é sumidouro
    int w;
    int ehSumidouro = 1;
    int ehFonte = 1;

    for(w = 1; w <=max; w++){
        if(grafo[w][v] == 1){
            ehFonte = 0;
        }
        if(grafo[v][w] == 1){
            ehSumidouro = 0;
        }
    }

    if(ehSumidouro){
        return 1;
    } else if(ehFonte){
        return -1;
    } else {
        return 0;
    }
}
