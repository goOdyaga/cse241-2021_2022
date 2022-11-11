#ifndef GAMELIB2_H
#define GAMELIB2_H

#include "main_library.h"
#include "main_game_lib.h"
namespace GOS
{
    class Game_two: public BoardGAME2D 
    {
     public:
        //fstream *file;
        Game_two(int gamer_type_);
        Game_two();
        virtual string random_command();
        virtual bool playUser(string move);
        virtual bool endgame();
        virtual void take_input(string move);
        virtual bool is_define_value(string move);
        virtual void set_game_board();
        virtual void print()const;
        virtual bool playAuto(string move);
        virtual void start_game();
        char **  get_game_board(){ return game_board;};/*return game board*/
        virtual void resize_game_board();/* memory allocation for gae-me board*/
       // void set_game_board();/*craeting game board for playing*/
        bool add_number(int number,int &count);/*add number for gaem_board . this function help set_game_board() funciton*/
        virtual inline int get_direction_for_game_column(){ return 3;};
        virtual inline int get_direction_for_game_row(){ return 3;};
        vector<int> find_location(char m); 
        //void move_direct();
        //int get_row();
        //int get_direction();
        //char get_column();
     private:
        char **game_board;  
    };

}

#endif