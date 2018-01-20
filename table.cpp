#include <cassert>
#include <iostream>
#include "table.h"

Table::Table(unsigned int n, unsigned int m){
    data = new int[n*m];
    for(int i=0;i<n*m;++i) data[i]=0;
    N = n;    M = m;
}


int & Table::operator()(unsigned int i, unsigned int j){
    assert( i<N && j<M );
    return data[i*M+j];
}

const int & Table::operator()(unsigned int i, unsigned int j) const{
    assert( i<N && j<M );
    return data[i*M+j];
}


Table::Table(Table const &rhs){
    N = rhs.N;    M = rhs.M;
    data = new int[N*M];
    for(int i=0;i<N*M;++i)
        data[i]=rhs.data[i];
}


Table & Table::operator=(Table const & rhs){
    int t=1;
    if(N == rhs.N && M == rhs.M) {
        for(int i=0;i<rhs.N*rhs.M;++i)
            if(data[i]!=rhs.data[i]) { t=0;     break; }
    }
    else t=0;

    if( t ) return *this;

    delete [] data;
    N = rhs.N;    M = rhs.M;
    data = new int[N*M];
    for(int i=0;i<N*M;++i)
        data[i]=rhs.data[i];

    return *this;
}


void Table::resize(unsigned int n, unsigned int m){
    delete [] data;
    data = new int[n*m];
    for(int i=0;i<n*m;++i) data[i]=0;
    N = n;    M = m;
}


void Table::print(){
    for(int i=0;i<M*N;++i){
        if( i%M==0 ) { std::cout << std::endl; }
        std::cout << data[i] << " ";
    }
    std::cout << std::endl  << std::endl;
}
