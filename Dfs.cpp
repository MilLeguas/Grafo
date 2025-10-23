#include <iostream>
#include <vector>

using namespace std;
int tempo = 0;

void adicionar_aresta(vector<vector<int>>& adj, int origem, int destino){
    adj[origem].push_back(destino);
}

void DFS(int vertice_inicial, vector<int>& visita, const vector<vector<int>>& adj, vector<int>& pre_ordem, vector<int>& pos_ordem){
    
    pre_ordem[vertice_inicial] = ++tempo;
    
    visita[vertice_inicial] = 1;

    for(int vertice : adj[vertice_inicial]){
        if(visita[vertice] == 0) DFS(vertice, visita, adj, pre_ordem, pos_ordem);
    }
    pos_ordem[vertice_inicial] = ++tempo;
}

void inicializar(vector<int>& v){
    for(int i : v) v[i] = 0;
}

int main(){
    int qtd_vertices = 4; 
    
    vector<vector<int>> adj;
    adj.resize(qtd_vertices);

    adicionar_aresta(adj, 0, 1);
    adicionar_aresta(adj, 0, 2);
    adicionar_aresta(adj, 2, 1);
    adicionar_aresta(adj, 2, 3);

    
    vector<int> visita, pre_ordem, pos_ordem;
    visita.resize(qtd_vertices);
    pre_ordem.resize(qtd_vertices);
    pos_ordem.resize(qtd_vertices);
    inicializar(visita);

    DFS(0, visita, adj, pre_ordem, pos_ordem);

    for(int i = 0 ; i < qtd_vertices; i++){
        printf("Vertice %d foi encontrado na %d / %d\n", i, pre_ordem[i], pos_ordem[i]);
    }
    
    return 0;
}
