#ifndef MAIN_GAME_LIB_H
#define MAIN_GAME_LIB_H

#include "main_library.h"

namespace GOS
{
    class BoardGAME2D
    {
    public:
        
        BoardGAME2D();
        fstream *file;
        virtual bool playUser(string move)=0;
        virtual bool playUser() final;
        virtual bool endgame()=0;
        virtual void take_input(string move)=0;
        virtual bool is_define_value(string move)=0;
        virtual void set_game_board()=0;
        virtual void print()const=0;
        virtual bool playAuto(string move)=0;
        virtual bool playAutoall() final;
        virtual void resize_game_board()=0;
        virtual string random_command()=0;
        virtual inline const int get_score()final{ return score;};
        virtual inline void increase_score()final{ score++;};
        virtual inline void set_gamer_type(int gamer_type_)final{gamer_type=gamer_type_;};
        virtual void start_game()=0;
        virtual inline int get_gamer_type()final{ return gamer_type;};
        friend ostream &operator<<(ostream &outputStream,const BoardGAME2D *obj);/*print game board*/
        static void playVector(vector<BoardGAME2D *> games_);
    private:
        vector<BoardGAME2D *>games;
        int score;
        int gamer_type;

    };
}
#endif