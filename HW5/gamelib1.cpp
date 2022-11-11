//#include "main_library.h"
#include "gamelib1.h"
namespace GOS
{  
    Game_one::Game_one()
    :BoardGAME2D(),row(0),column(0)
    {
        set_gamer_type(1);
        resize_game_board();
        set_game_board();
        //file=new fstream;
        file->open("3x3puzzle.txt",ios::out);
    } 
    Game_one::Game_one(int gamer_type_)
    :BoardGAME2D(),row(0),column(0)
    {
        set_gamer_type(gamer_type_);
        resize_game_board();
        set_game_board();
       // file=new fstream;
        cout<<"amk1"<<endl;
        file->open("puzzle.txt",ios::out);
        cout<<"amk2"<<endl;
        
    }
    

    void Game_one::set_game_board()
    {
            srand(time(NULL));
        int control,count=0,control2;
        int number_control_array[9]={};
        while (1)
        {
            control=rand()%9;
            if(number_control_array[control]==0)
            {
                number_control_array[control]=1;
                count++;
                control2=count;
                if(count==9)
                    break;
                if(add_number(control,count))
                    break;
                if(control2==count+1)
                    number_control_array[control]=0;
            }
        }
        // for(int i=0;i<3;i++)       
        //     for(int j=0;j<3;j++)
        //         cout<<" "<<game_board[i][j];       
    }

    bool Game_one::add_number(int number,int &count)
    {
        if(number==0)
        {
            count--;
            return false;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(game_board[i][j]==0)
                {
                    game_board[i][j]=number;
                    return false;
                }
                
            }        
        }
        return true;
    }

    void Game_one::resize_game_board()
    {
        game_board=new int*[3];
        int i,j;
        for( i=0;i<3;i++)
            game_board[i]=new int[3];
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                game_board[i][j]=0;
        
        //cout<<this;
    }

    bool Game_one::is_define_value(string move) 
    {
        if(move.length()>=5)
        {
            if((move.at(0)<='3'&&move.at(0)>='1')&&(move.at(1)<='C'&&move.at(1)>='A'))
            {
                if(move.substr(3,move.length())=="UP"||move.substr(3,move.length())=="DOWN"||
                    move.substr(3,move.length())=="RIGHT"||move.substr(3,move.length())=="LEFT")
                        return true;
                else
                    return false;
            }
            else 
                return false;
        }
        else
            return false;
    }

    bool Game_one::playUser(string move)
    {
        if(move.substr(3,move.length())=="UP")
        {
            cout<<"y "<<get_column()<<" x "<<get_row()<<endl;
            if((get_column()-1)>=0 && game_board[get_column()-1][get_row()]==0)
            {
                game_board[get_column()-1][get_row()]=game_board[get_column()-1][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;
            }
        }
        else if(move.substr(3,move.length())=="DOWN")
        {
            if((get_column()+1)<=2 && game_board[get_column()+1][get_row()]==0)
            {
            cout<<"y "<<get_column()<<" x "<<get_row()<<endl;

                game_board[get_column()+1][get_row()]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;

            }
        }
        else if(move.substr(3,move.length())=="RIGHT")
        {
            if((get_row()+1)<=2 && game_board[get_column()][get_row()+1]==0)
            {
                game_board[get_column()][get_row()+1]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;

            }
        }
        else if(move.substr(3,move.length())=="LEFT")
        {
            if((get_row()-1)>=0 && game_board[get_column()][get_row()-1]==0)
            {
                game_board[get_column()][get_row()-1]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;
            }
        }
        return false;
    }

    void Game_one::take_input(string move)
    {
        
            set_column(move.at(0)-'1');
            set_row(move.at(1)-'A');
    }

    bool Game_one::endgame()
    {
        int count=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if((i==2&&j==2))
                    return false;
                if(count!=game_board[i][j])
                    return true;
                count++;
            }
        }
        return false;
    }
    
    bool Game_one::playAuto(string move)
    {
       if(move.substr(3,move.length())=="UP")
        {
            if((get_column()-1)>=0 && game_board[get_column()-1][get_row()]==0)
            {
                game_board[get_column()-1][get_row()]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;
            }
        }
        else if(move.substr(3,move.length())=="DOWN")
        {
            if((get_column()+1)<=2 && game_board[get_column()+1][get_row()]==0)
            {
                game_board[get_column()+1][get_row()]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;
            }
        }
        else if(move.substr(3,move.length())=="RIGHT")
        {
            if((get_row()+1)<=2 && game_board[get_column()][get_row()+1]==0)
            {
                game_board[get_column()][get_row()+1]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;
            }
        }
        else if(move.substr(3,move.length())=="LEFT")
        {
            if((get_row()-1)>=0 && game_board[get_column()][get_row()-1]==0)
            {
                game_board[get_column()][get_row()-1]=game_board[get_column()][get_row()];
                game_board[get_column()][get_row()]=0;
                return true;
            }
        } 
        return false;
    }

    void Game_one::print() const
    {
        char m='A';
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i==0&&j>0)
                {
                    cout<<m<<" ";
                    *file<<m<<" "; 
                    m+=1;
                }
                else if(j==0&&i>0)
                {
                    cout<<i<<"| ";
                    *file<<i<<"| ";
                }
                else if(i>0&&j>0)
                {
                    cout<<game_board[i-1][j-1]<<" " ;            
                    *file<<game_board[i-1][j-1]<<" " ;
                }
            }
            cout<<endl;
            *file<<endl;
        }
    
    }
   
    void Game_one::start_game()
    {
        cout<<"Welcome 3x3 Puzzle\n"<<endl;
        *file<<"Welcome 3x3 Puzzle\n"<<endl;
        if(get_gamer_type()==1)
        {
            cout<<"GAME WILL PLAYED BY USER\n"
                <<"GOOD LUCK:))"<<endl;
            *file<<"GAME WILL PLAYED BY USER\n"
                <<"GOOD LUCK:))"<<endl;
            BoardGAME2D:: playUser();
        }   
        else
        {
            cout<<"GAME WILL PLAYED BY USER\n"
                <<"GOOD LUCK:))"<<endl;
            *file<<"GAME WILL PLAYED BY USER\n"
                <<"GOOD LUCK:))"<<endl;
            BoardGAME2D:: playAutoall();
        }
    }
    string Game_one::random_command()
    {
        vector<string> direction{"UP","DOWN","RIGHT","LEFT"};
        vector<string> x_{"A","B","C","D","E","F","G","H"};
        vector<string> y_{"1","2","3","4","5","6","7","8"};
        string space =" "; 
        string move,play;
        int r,c,d;
        r=rand()%3;
        c=rand()%3;
        d=rand()%4;
        return move=y_.at(c)+x_.at(r)+space+direction.at(d);
    }

}
