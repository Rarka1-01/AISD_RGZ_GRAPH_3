#ifndef AISD_RGR_3_EDGE_H
#define AISD_RGR_3_EDGE_H

#include "headers.h"
#include "Vertex.h"

template<typename W, typename V, class Vertex>
class Edge{
public:

    Edge(W weight, V value){
        this->weight = weight;
        this->value = value;

        this->outVer = nullptr;
        this->inVer = nullptr;
    }

    ~Edge(){
        if(this->outVer != nullptr)
            delete this->outVer;

        if(this->inVer != nullptr)
            delete this->inVer;
    }


    void setIn(Vertex *inVertex){
        if(this->inVer != nullptr)
        {
            delete this->inVer;
            this->inVer = nullptr;
        }

        this->inVer = inVertex;
    }

    void setOut(Vertex *outVertex){
        if(this->outVer != nullptr)
        {
            delete this->outVer;
            this->outVer = nullptr;
        }

        this->outVer = outVertex;
    }

    void setInAndOut(Vertex *inVertex, Vertex *outVertex){
        this->setIn(inVertex);
        this->setOut(outVertex);
    }

    W getWeight(){
        return this->weight;
    }

    Vertex* getOut(){
        return this->outVer;
    }

    Vertex* getIn() {
        return this->inVer;
    }

private:
    W weight;
    V value;

    Vertex* outVer;
    Vertex* inVer;
};

#endif //AISD_RGR_3_EDGE_H
