#include "game_of_life.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

void GameOL::init(std::string const & file_name){
    
    std::ifstream file(file_name);
    if(not file){
        throw std::runtime_error("File not found.");
    }
    
    std::vector<int> vec;
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), back_inserter(vec));
    
    n_rows=vec[0];  n_cols=vec[1];
    table.resize(n_rows+2, n_cols+2);
    std::vector<int>::iterator it=vec.begin();  ++it;   ++it;
    int pom=1,x,y;

    for(; it != vec.end(); ++it){
        if(pom==1) { x=*it; pom=0; }
        else  { y=*it;  pom=1;  table(x+1,y+1)=1; }
    }
        
}

void GameOL::print() const{

    for(int i=0;i<n_rows;++i){
        for(int j=0;j<n_cols;++j)
            {
            if(table(i+1,j+1)==1) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void GameOL::print(std::string const &  file_name) const{

    std::ofstream f("zavrsno_stanje.txt");
    f << n_rows << " " << n_cols <<std::endl;

    for(int i=1;i<n_rows+1;++i)
        for(int j=1;j<n_cols;++j)
            if(table(i,j)==1) f << i-1 << " " << j-1 << std::endl;
}

void GameOL::update(){

    Table t_temp=table;

    for(int i=1;i<n_rows+1;++i)
        for(int j=1;j<n_cols+1;++j){
            if( table(i,j)==1 ){
                if( br_susjeda(i,j)!=2 && br_susjeda(i,j)!=3 ) t_temp(i,j)=0;
            }
            else
                if( br_susjeda(i,j)==3 ) t_temp(i,j)=1;
        }
    table=t_temp;    
}

int GameOL::br_susjeda(int i, int j) const{

    return table(i-1,j-1)+table(i-1,j)+table(i-1,j+1)+table(i,j+1)+table(i+1,j+1)+table(i+1,j)+table(i+1,j-1)+table(i,j-1);
}
