#ifndef AISD_RGR_3_VERTEX_H
#define AISD_RGR_3_VERTEX_H

#include "headers.h"

template<typename K, typename V>
class Vertex{
public:

    Vertex(K key, V val){
        this->key = key;
        this->val = val;
        this->visit = false;
    }

    K getKey(){
        return this->key;
    }

    void setVisit(bool visit){
        this->visit = visit;
    }

    bool getVisit(){
        return this->visit;
    }

private:
    K key;
    V val;
    bool visit;
};

#endif //AISD_RGR_3_VERTEX_H
