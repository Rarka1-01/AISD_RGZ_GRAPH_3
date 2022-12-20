#include "./lib/headers.h"
#include "./lib/QuestG.h"

Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> createGraphFirst(){

    vector<Vertex<int, int>*> v;

    for(int i = 0; i < 5; i++)
        v.push_back(new Vertex(i, -1));

    vector<Edge<int, int, Vertex<int, int>>*> e;

    e.push_back(new Edge<int, int, Vertex<int, int>>(-1, 1));
    e[0]->setInAndOut(v[1], v[0]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(4, 1));
    e[1]->setInAndOut(v[4], v[0]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(3, 1));
    e[2]->setInAndOut(v[4], v[1]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(5, 1));
    e[3]->setInAndOut(v[4], v[3]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(1, 1));
    e[4]->setInAndOut(v[3], v[1]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(2, 1));
    e[5]->setInAndOut(v[1], v[3]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(2, 1));
    e[6]->setInAndOut(v[2], v[1]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(-3, 1));
    e[7]->setInAndOut(v[3], v[2]);

    Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> gr;

    gr.setEdges(e);
    gr.setVertexes(v);

    return gr;
}

Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> createGraphSecond(){

    vector<Vertex<int, int>*> v;

    for(int i = 0; i < 4; i++)
        v.push_back(new Vertex(i, -1));

    vector<Edge<int, int, Vertex<int, int>>*> e;

    e.push_back(new Edge<int, int, Vertex<int, int>>(-2, 1));
    e[0]->setInAndOut(v[1], v[0]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(5, 1));
    e[1]->setInAndOut(v[2], v[0]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(-1, 1));
    e[2]->setInAndOut(v[0], v[2]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(1, 1));
    e[3]->setInAndOut(v[2], v[2]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(3, 1));
    e[4]->setInAndOut(v[2], v[3]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(4, 1));
    e[5]->setInAndOut(v[0], v[3]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(2, 1));
    e[6]->setInAndOut(v[3], v[1]);

    e.push_back(new Edge<int, int, Vertex<int, int>>(-2, 1));
    e[7]->setInAndOut(v[1], v[3]);

    Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> gr;

    gr.setEdges(e);
    gr.setVertexes(v);

    return gr;
}

int main() {

    auto gr1 = createGraphFirst();
    auto gr2 = createGraphSecond();

    QuestG<Edge<int,int,Vertex<int, int>>, Vertex<int, int>, int> q(gr1, 0);

    q.result();

    cout << "\n\n";

    q.setGraph(gr2, 3);
    q.result();

    return 0;
}
