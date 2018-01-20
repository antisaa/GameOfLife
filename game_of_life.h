#ifndef __GAME_OF_LIFE_H_INCLUDED__
#define __GAME_OF_LIFE_H_INCLUDED__

#include <ostream>
#include <string>

#include "table.h"

class GameOL{
  public:
    GameOL(): n_rows(0), n_cols(0) {};

    void init(std::string const & file_name);
    void print() const;
    void print(std::string const &  file_name) const;
    void update();

    Table const & getTable() const { return table; }
    
  private:
    // broj živih susjeda danog elementa (i,j)
    int  br_susjeda(int i, int j) const;
     // broj redaka polja
    int n_rows;
    // broj stupaca polja
    int n_cols;
    // polje implementirano kao niz vrijednosti
    Table table;
};

#endif
