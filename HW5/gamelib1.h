#ifndef GAMELIB1_H
#define GAMELIB1_H

#include "main_library.h"
#include "main_game_lib.h"
namespace GOS
{
    class Game_one: public BoardGAME2D 
    {
     public:
        //fstream *file;
        Game_one(int gamer_type_);
        Game_one();
        virtual string random_command();
        virtual bool playUser(string move);
        virtual bool endgame();
        void take_input(string move);
        virtual bool is_define_value(string move);
        virtual void set_game_board();
        virtual void print()const;
        virtual bool playAuto(string move);
        virtual void start_game();
        int **  get_game_board(){ return game_board;};/*return game board*/
        void resize_game_board();/* memory allocation for gae-me board*/
       // void set_game_board();/*craeting game board for playing*/
        inline const int get_column(){ return column;};
        inline const int get_row(){ return row;};
        inline void set_row(int row_) {row=row_;}
        inline void set_column(int column_) {column=column_;}
        bool add_number(int number,int &count);/*add number for gaem_board . this function help set_game_board() funciton*/
     private:
        int row;
        int column;
        int direction;
        int **game_board;  
    };

}

#endif