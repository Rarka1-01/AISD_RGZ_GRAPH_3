#ifndef AISD_RGR_3_QUESTG_H
#define AISD_RGR_3_QUESTG_H

#include "headers.h"
#include <set>
#include "Graph.h"

#define INF 10000000

template<class E, class V, typename K>
class QuestG{
public:

    QuestG(Graph<E, V> g, K key){
        this->g = g;
        this->solve(key);
        this->key = key;
    }

    QuestG(QuestG& q){
        this->g = q.g;
        this->sl = q.sl;
        this->key = q.key;
    }

    void setGraph(Graph<E, V> g, K key){
        this->g = g;
        this->key = key;
        this->restart();
    }

    void restart(){
        this->solve(this->key);
    }

    void result(){

        cout << "Distance to all vertex:\n";
        for(int i = 0; i < this->sl.size(); i++)
            cout << i << ": " << this->sl[i] << endl;
        cout << endl;
    }

    void setNewKey(K key){
        this->key = key;
    }

private:
    Graph<E, V> g;
    vector<K> sl;

    K key;

    void solve(K key){
        vector<K> d(this->g.getVertexes().size(), INF);

        d[key] = 0;

        for(int u = 0; u < this->g.getVertexes().size() - 1; u++)
            for(auto i: this->g.getEdges())
                if(d[i->getOut()->getKey()] != INF
                && d[i->getOut()->getKey()] + i->getWeight() < d[i->getIn()->getKey()])
                    d[i->getIn()->getKey()] = d[i->getOut()->getKey()] + i->getWeight();


        this->sl = d;
    }
};

#endif //AISD_RGR_3_QUESTG_H
