#include<bits/stdc++.h>
#include<time.h>
#include <cmath>
#define N 1000000
#define MAX 10
#define pi 3.14159265
#define R 6.0
using namespace std;

int qtd_nodos = 10;

int tam_genes = 100;
int tam_pop = 10;
int tam_torneio = 50; // qtd de cruzamentos
int geracoes = 100;
double prob_mut = 0.3f;
double prob_cruz = 0.7f;
vector<vector<vector<int> > > populacao;

vector<int> graph[N];
bool visited[N];
int CC = 0;

double point_area(vector<vector<int> > ind);
int Conecteds_componets(vector<vector<int> > ind);
void inicializa_populacao();
void imprimir();
void clear_graph();
void dfs(int v);
void mutation(vector<int>& ind);
bool comp(vector<vector<int> > a, vector<vector<int> > b);
void cruzamento(vector<vector<int> > pai1, vector<vector<int> > pai2, vector<vector<int> >& filho);

void inicializa_populacao(){
    for(int i=0; i<tam_pop; i++){
        vector<vector<int> > individuo;
        for(int k=0; k<MAX; k++){
            vector<int> line;
            for(int j=0; j<MAX; j++) line.push_back(0);
            individuo.push_back(line);
        }
        int A = 1;
        for(int j=0; j<qtd_nodos; j++){
            int idx_i = abs(rand()%MAX);
            int idx_j = abs(rand()%MAX);
            individuo[idx_i][idx_j] = A++;
        }
        populacao.push_back(individuo);
    }
}

void imprimir(){
    for(auto w: populacao){
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++) cout<<w[i][j]<<" ";
            cout<<endl;
        }
        cout<<point_area(w)<<endl;
        cout<<Conecteds_componets(w)<<endl;
        cout<<"#################\n";
    }
}

double point_area(vector<vector<int> > ind){
    double area = 0.0f;
    double interseccao = 0.0f;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
        if(ind[i][j] != 0){
            for(int l=0; l<MAX; l++){
                for(int k=0; k<MAX; k++){
                    if(ind[l][k] != 0 && ind[i][j] != ind[l][k]){
                        double dist = sqrt(abs(pow(abs(l-i), 2) + pow(abs(k-j), 2)));
                        //cout<<dist<<endl;
                        if(dist < 2*R){
                            double d_2 = sqrt((R*R)-((dist*dist)/4));
                            double set_circular = R*R*(asin(d_2/R)); //trocar X
                            double triangulo = (sqrt(abs((4*R*R) - (d_2*d_2)) / 4)); //trocar X
                            interseccao += abs(set_circular - triangulo);
                        }
                    }
                }
            }
        }
        }
    }
    int elem = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //o pai de um nó é ele mesmo
            if(ind[i][j] != 0){
                graph[ind[i][j]].push_back(ind[i][j]);
                elem++;
            }
        }
    }
    //cout<<"FINAL INTERSECCAO: "<<interseccao<<endl;
    return (pi*R*R*elem) - (interseccao);
}

void clear_graph(){
    for(int i=0; i<MAX; i++) graph[i].clear();
    memset(visited, false, sizeof visited);
    CC = 0;
}

void dfs(int v){
    visited[v] = true;
    for(auto &w: graph[v]){
        if(!visited[w]) dfs(w);
    }
}

int Conecteds_componets(vector<vector<int> > ind){
    //inicializa para que possa ser construido outro teste
    clear_graph();
    int elem = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //o pai de um nó é ele mesmo
            if(ind[i][j] != 0){
                graph[ind[i][j]].push_back(ind[i][j]);
                elem++;
            }
        }
    }
    //procuro por outros nós que estão dentro da área de comunicação individual de cada um
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
        if(ind[i][j] != 0){
            for(int l=0; l<MAX; l++){
                for(int k=0; k<MAX; k++){
                    if(ind[l][k] != 0 && ind[i][j] != ind[l][k]){
                        double dist = sqrt(abs(pow(abs(l-i), 2) + pow(abs(k-j), 2)));
                        //se está na área
                        if(dist < 2*R){
                            //grafo bidirecional
                            //graph[ind[l][k]].push_back(ind[i][j]);
                            graph[ind[i][j]].push_back(ind[l][k]);
                            //cout<<l<<" "<<k<<"-->>"<<i<<" "<<j<<endl;
                            //cout<<i<<" "<<j<<"-->>"<<l<<" "<<k<<endl;
                        }
                    }
                }
            }
        }
        }
    }
    //roda um DFS procurando a qauntidade de componentes conexos
    for(int i=1; i<elem; i++){
        if(!visited[i]){
            dfs(i);
            CC++;
            //cout<<CC<<" ";
        }
    }
    //cout<<endl;
    return CC;
}

int Conecteds_componets2(vector<vector<int> > ind){
    //inicializa para que possa ser construido outro teste
    clear_graph();
    int elem = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //o pai de um nó é ele mesmo
            if(ind[i][j] != 0){
                graph[ind[i][j]].push_back(ind[i][j]);
                elem++;
            }
        }
    }
    //procuro por outros nós que estão dentro da área de comunicação individual de cada um
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
        if(ind[i][j] != 0){
            for(int l=0; l<MAX; l++){
                for(int k=0; k<MAX; k++){
                    if(ind[l][k] != 0 && ind[i][j] != ind[l][k]){
                        double dist = sqrt(abs(pow(abs(l-i), 2) + pow(abs(k-j), 2)));
                        cout<<dist<<endl;
                        //cout<<ind[i][j]<<" "<<ind[l][k]<<" "<<dist<<endl;
                        //se está na área
                        if(dist < 2*R){
                            //grafo bidirecional
                            //graph[ind[l][k]].push_back(ind[i][j]);
                            graph[ind[i][j]].push_back(ind[l][k]);
                           // cout<<l<<" "<<k<<"-->>"<<i<<" "<<j<<endl;
                            cout<<ind[i][j]<<"-->>"<<ind[l][k]<<endl;
                        }
                    }
                }
            }
        }
        }
    }
    //roda um DFS procurando a qauntidade de componentes conexos
    for(int i=1; i<elem; i++){
        if(!visited[i]){
            dfs(i);
            CC++;
            cout<<CC<<" ";
        }
    }
    //cout<<endl;
    return CC;
}

double point_area2(vector<vector<int> > ind){
    double area = 0.0f;
    double interseccao = 0.0f;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
        if(ind[i][j] != 0){
            for(int l=0; l<MAX; l++){
                for(int k=0; k<MAX; k++){
                    if(ind[l][k] != 0 && ind[i][j] != ind[l][k]){
                        double dist = sqrt(abs(pow(abs(l-i), 2) + pow(abs(k-j), 2)));
                        //cout<<dist<<endl;
                        if(dist < 2*R){
                            double d_2 = sqrt((R*R)-((dist*dist)/4));
                            double set_circular = R*R*(asin(d_2/R)); //trocar X
                            double triangulo = (sqrt(abs((4*R*R) - (d_2*d_2)) / 4)); //trocar X
                            interseccao += abs(set_circular - triangulo);
                            cout<<ind[i][j]<<" "<<ind[l][k]<<" "<<endl<<"distancia: "<<dist<<endl;
                            cout<<"d_2: "<<d_2<<endl;
                            cout<<"setor circular: "<<set_circular<<endl;
                            cout<<"triangulo: "<<triangulo<<endl;
                            cout<<"interseccao: "<<interseccao<<endl<<endl;
                        }
                    }
                }
            }
        }
        }
    }
    int elem = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //o pai de um nó é ele mesmo
            if(ind[i][j] != 0){
                graph[ind[i][j]].push_back(ind[i][j]);
                elem++;
            }
        }
    }
    cout<<pi*R*R*elem<<endl;
    cout<<"FINAL INTERSECCAO: "<<(interseccao)<<endl;
    return (pi*R*R*elem) - (interseccao);
}

void mutation(vector<vector<int> >& ind){
    int k = 0;
    for(int i=0; i<MAX; i++) for(int j=0; j<MAX; j++) if(ind[i][j] != 0) k = ind[i][j];
    int geneI = rand()%MAX;
    int geneJ = rand()%MAX;
    //acrescenta ou decrementa um nodo do grid
    (ind[geneI][geneJ] != 0) ? ind[geneI][geneJ] = 0 : ind[geneI][geneJ] = ++k;
}

void cruzamento(vector<vector<int> > pai1, vector<vector<int> > pai2, vector<vector<int> >& filho){
    int pontoI = rand()%MAX;
    for(int i=0; i<=pontoI; i++) filho.push_back(pai1[i]);
    for(int i=pontoI+1; i<MAX; i++) filho.push_back(pai2[i]);
    int A = 1;
    //enumera os nodos da forma correta
    for(int i=0; i<MAX; i++) for(int j=0; j<MAX; j++) if(filho[i][j] != 0) filho[i][j] = A++;
}

bool comp(vector<vector<int> > a, vector<vector<int> > b){
    if(Conecteds_componets(a) < Conecteds_componets(b)) return false;
    else if(Conecteds_componets(a) == Conecteds_componets(b)){
        if(point_area(a) >= point_area(b)) return false;
    }
    return true;
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    //inicializa população
    inicializa_populacao();
    //for para cada geração
    for(int i=0; i<geracoes; i++){
        //quantidade de cruzamentos
        for(int j=0; j<tam_torneio; j++){
            double prob = abs((double) rand() / ((double) RAND_MAX + 1));
            //se a probabilidade de mutação for possivel, ela é realizada
            if(prob < prob_cruz){
                int indice_pai1 = abs(rand() % tam_pop);
                int indice_pai2;
                do{
                    indice_pai2 = abs(rand() % tam_pop);
                }while(indice_pai1 == indice_pai2);
                vector<vector<int> > filho;
                cruzamento(populacao[indice_pai1], populacao[indice_pai2], filho);
                double prob = abs((double) rand() / ((double) RAND_MAX + 1));
                //se a probabilidade for possivel, faço a mutação
                if(prob <prob_mut) mutation(filho);
                //se o filho for melhor que o pai, faço um swap
                if(point_area(populacao[indice_pai1]) < point_area(filho) && Conecteds_componets(populacao[indice_pai1]) <= Conecteds_componets(filho)){
                    populacao[indice_pai1].swap(filho);
                }
            }
        }
    }
        cout<<"Melhor: \n";
        //obter melhor
        sort(populacao.begin(), populacao.end(), comp);
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++) cout<<populacao[0][i][j]<<" ";
            cout<<endl;
        }
        cout<<"Area: "<<point_area2(populacao[0])<<endl;
        cout<<"Componentes Conexos: "<<Conecteds_componets2(populacao[0])<<endl;
        
        FILE *arq;
        arq = fopen("ArqGrav.txt", "wt");
        
        if (arq == NULL){
            printf("Problemas na CRIACAO do arquivo\n");
            return 0;
        }
        
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                if(populacao[0][i][j] != 0){
                    fprintf(arq,"%d,%d\n", j, i);
                }
            }
        }
        fclose(arq);
        std::vector<int> I, J;
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                if(populacao[0][i][j] != 0){
                    I.push_back(i);
                    J.push_back(j);
                }
            }
        }
        cout<<"[";
        for(auto x: I) cout<<x<<",";
        cout<<"]"<<endl<<"[";
        for(auto x: J) cout<<x<<",";
        cout<<"]"<<endl;
    return 0;
}
