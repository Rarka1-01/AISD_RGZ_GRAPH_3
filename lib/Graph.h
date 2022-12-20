#ifndef AISD_RGR_3_GRAPH_H
#define AISD_RGR_3_GRAPH_H

#include "headers.h"
#include "Vertex.h"
#include "Edge.h"
#include <vector>

template<class E, class V>
class Graph{
public:

    Graph(){

    }

    Graph(Graph<E, V> &g){
        this->vertexes.clear();
        this->vertexes = g.vertexes;
        this->edges.clear();
        this->edges = g.edges;
    }

    Graph(int cVer, int cEdg){
        if(cEdg > cVer){

            vector<V*> v;
            vector<E*> e;

            for(int i = 0; i < cVer; i++)
                v.push_back(new V(i, rand() % 10));

            for(int i = 0; i < cEdg; i++){
                e.push_back(new E(rand() % 50 - 25, -1));
                e[i]->setInAndOut(v[int(rand() % cVer)], v[int(rand() % cVer)]);
            }

            this->setEdges(e);
            this->setVertexes(v);
        }
    }

    ~Graph(){
        this->edges.clear();
        this->vertexes.clear();
    }

    vector<V*> getVertexes(){
        return this->vertexes;
    }

    vector<E*> getEdges(){
        return this->edges;
    }

    void setVertexes(vector<V*> ver){
        this->vertexes.clear();
        this->vertexes = ver;
    }

    void setEdges(vector<E*> ed){
        this->edges.clear();
        this->edges = ed;
    }

private:
    vector<V*> vertexes;
    vector<E*> edges;
};

#endif //AISD_RGR_3_GRAPH_H
