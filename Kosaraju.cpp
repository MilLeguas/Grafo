#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge (vector<vector<int>>& grafo, vector<vector<int>>& grafoT, int u, int v){
    grafo[u].push_back(v);        
    grafoT[v].push_back(u);
}

void Dfs(vector<vector<int>> &grafo, stack<int>& pilha, vector<bool>& visita, int u){
    visita[u] = true;
    for(int v : grafo[u]) if(!visita[v]) Dfs (grafo, pilha, visita, v);
    pilha.push(u);
}

void DfsTransposto(vector<vector<int>> &grafoT, vector<bool>& visita, int u){
    visita[u] = true;
    for(int v: grafoT[u]) if(!visita[v]) DfsTransposto(grafoT,visita, v);
}

int Kosaraju (vector<vector<int>> grafoT, stack<int>& pilha, vector<bool>& visita){
    int cfc = 0;
    while(!pilha.empty()){
        int vAtual = pilha.top();
        pilha.pop();
       if(!visita[vAtual]){
            DfsTransposto(grafoT, visita, vAtual);      
            cfc++;
    }        
    }
    return cfc;
}

int main (){
    int numero_vertice = 8;
    vector<vector<int>> grafo, grafoT;
    grafo.resize(numero_vertice); grafoT.resize(numero_vertice);
    vector<bool> visita(numero_vertice, false), visitaT(numero_vertice, false);
    stack<int> pilha;
    int u = 0, cfc = 0;

    addEdge(grafo, grafoT, 0, 1);
    addEdge(grafo, grafoT, 1, 2);
    addEdge(grafo, grafoT, 2, 0); // Componente {0, 1, 2}
    
    addEdge(grafo, grafoT, 2, 3); // Aresta ligando componentes

    addEdge(grafo, grafoT, 3, 4);
    addEdge(grafo, grafoT, 4, 3); // Componente {3, 4}

    addEdge(grafo, grafoT, 4, 5); // Aresta ligando componentes

    addEdge(grafo, grafoT, 5, 6);
    addEdge(grafo, grafoT, 6, 5); // Componente {5, 6}
    
    addEdge(grafo, grafoT, 6, 7);
    
    for(u = 0; u < visita.size(); u++){
        if(!visita[u]) Dfs (grafo, pilha, visita, u);
    }

    for(u = 0; u < visita.size(); u++)visita[u] = false;
    
    cfc = Kosaraju(grafoT, pilha, visita);
    cout << "\nTotal de Componentes Fortemente Conexos: " << cfc << endl;

    return 0;
}
