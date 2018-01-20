/*
Kompajliranje i pokretanje:
g++ -std=c++11 main.cpp table.cpp table.h game_of_life.cpp game_of_life.h -o prog && ./prog

*/
#include "game_of_life.h"
#include <fstream>
#include <iostream>
#include <random>
#include <fstream>


int main(int argc, char * argv[])
{  

  std::ofstream myfile;
  myfile.open ("randomInput.txt");
  myfile << "20 20\n";
  
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(0, 19);
  Table A(20,20);
  int brojac = 80;
  while(brojac){
    int xCoor, yCoor;
    xCoor = dis(gen);
    yCoor = dis(gen);
    myfile << xCoor << " " << yCoor << "\n";
    A( dis(gen) , dis(gen) ) = 1;
    --brojac;
  }

  myfile.close();
  // učitaj ulazno stanje iz datoteke. Datoteka je pocetno_stanje.txt
  // ili je zadana argumentom komandne linije 

  //std::string input_file("pocetno_stanje.txt");
  std::string input_file("randomInput.txt");
  if(argc > 1)
    input_file = argv[1];

  GameOL gol;  // defaultni konstruktor

  gol.init(input_file);
  gol.print();

  while( 1 )
  {  

    gol.update();  // prijelaz automata u novo stanje
    gol.print();
    std::cout <<std::endl<<std::endl;
    int br = 0;
    while(br<300000000)
      br++;
  }
  // ispiši završno stanje u datoteku
  gol.print("zavrsno_stanje.txt");

}
