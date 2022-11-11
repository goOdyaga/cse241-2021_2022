#include "main_library.h"
#include "main_game_lib.h"
#include<limits>
namespace GOS
{    
    BoardGAME2D::BoardGAME2D():
        score(0)
    {   
        cout<<"1"<<endl;
        file=new fstream;
        cout<<"yuh"<<endl;

    }
    bool BoardGAME2D::playUser()
    {
        string move;
        bool is_finish=true;
        cout<<this<<endl;
        while(endgame())
        {
            cout<<this<<endl;
            *file<<this<<endl;
            cout<<"Please write your movement , for finish game type EXIT:\n";
            *file<<"Please write your movement , for finish game type EXIT:\n";
            getline(cin,move);
            if(move=="EXIT")
            {
                cout<<"Game has finished"<<endl;
                *file<<"Game has finished"<<endl;
                cout<<"Your score is "<<get_score()<<endl;
                *file<<"Your score is "<<get_score()<<endl;
                file->close();
                is_finish=false;
                break;
            }
            if(is_define_value(move))
            {
                take_input(move);
                if(playUser(move))
                {
                    cout<<"Succesfull movement"<<endl;
                    *file<<"Succesfull movement"<<endl;
                    increase_score();
                }
                else
                {
                    cout<<"unsuccesful movement"<<endl;
                    *file<<"unsuccesful movement"<<endl;

                }
            }
            else
            {
                cout<<"Undefine input for playing game:\n";
                *file<<"Undefine input for playing game:\n";

            }
        }    
        if(is_finish)
        {
            cout<<"Game has finished succesfully\n"
                <<"Your score is "<<get_score()<<endl;
            *file<<"Game has finished succesfully\n"
                <<"Your score is "<<get_score()<<endl;
        }
        return true;
    }

    bool BoardGAME2D:: playAutoall()
    {
        // vector<string> direction{"UP","DOWN","RIGHT","LEFT"};
        // vector<string> x_{"A","B","C","D","E","F","G","H"};
        // vector<string> y_{"1","2","3","4","5","6","7","8"};
        // string space =" "; 
        string move,play;
        bool is_win=true;
        // int r,c,d;
        // move=x_.at(0)+y_.at(0)+space+direction.at(0);
        while(endgame())
        {
           cout<<this;
            cout<<"\n\n\n";
            move=random_command();
            // r=rand()%get_direction_for_game_x();
            // c=rand()%get_direction_for_game_y();
            // d=rand()%4;
            // move=y_.at(c)+x_.at(r)+space+direction.at(d);
            cout<<"Game will contuine automatically please press Enter or for finish game please press END"<<endl;
            *file<<"Game will contuine automatically please press Enter or for finish game please press END"<<endl;
            getline(cin,play);
            if(play=="END")
            {
                cout<<"Game has been finished"<<endl;
                *file<<"Game has been finished"<<endl;
                is_win=false;
                break;
            }
            take_input(move);
            if(playAuto(move))
            {
                cout<<"succesfull movement"<<endl;
                *file<<"succesfull movement"<<endl;
                increase_score();
            }
        }
        if(is_win)
        {
            cout<<"!! YOU WON !!"<<endl;
            *file<<"!! YOU WON !!"<<endl;
            return true;
        }
        return false;
    }

    ostream& operator <<(ostream &outputStream,const BoardGAME2D *obj)
    {
        obj->print();
        return outputStream;
    }

        void BoardGAME2D::playVector(vector<BoardGAME2D *> games_)
        {
            for(auto x:games_)
                x->playAutoall();
            cout<<"ALL GAMES HAS PLAYED İN THE VECTOR \n";
        }
    
}