// #include "main_game_lib.h"
// #include "main_library.h"
#include "gamelib2.h"
namespace GOS
{
    Game_two::Game_two()
    :BoardGAME2D()
    {
        set_gamer_type(1);
        resize_game_board();
        set_game_board();
       // file=new fstream;
        file->open("klotski.txt",ios::out);
    }

    Game_two ::Game_two(int gamer_type_)
    :BoardGAME2D()
    {
        set_gamer_type(gamer_type_);
        resize_game_board();
        set_game_board();
        //file=new fstream;
        // cout<<"2"<<endl;
        file->open("klotski.txt",ios::out);
        // cout<<"2"<<endl;
    }
    
    void Game_two::resize_game_board()
    {
        game_board= new char*[5];
        for(int i=0;i<5;i++)
            game_board[i]=new char[4];   
    }
    
    void Game_two::set_game_board()
    {
        game_board[0][0]='B';
        game_board[0][1]='A';
        game_board[0][2]='A';
        game_board[0][3]='C';
        game_board[1][0]='B';
        game_board[1][1]='A';
        game_board[1][2]='A';
        game_board[1][3]='C';
        game_board[2][0]='D';
        game_board[2][1]='F';
        game_board[2][2]='F';
        game_board[2][3]='E';
        game_board[3][0]='D';
        game_board[3][1]='G';
        game_board[3][2]='H';
        game_board[3][3]='E';
        game_board[4][0]='K';
        game_board[4][1]=' ';
        game_board[4][2]=' ';
        game_board[4][3]='L';/*5388535411-ayşenur hanım*/      
    }

    bool Game_two::is_define_value(string move)
    {
        if(move.length()>=4)
        {
            if(move.at(0)>='A'&&move.at(0)<='L')
            {
               // cout<<move<<" "<<move.length()<<endl;
                if(move.substr(2,move.length())=="UP"||move.substr(2,move.length())=="DOWN"
                ||move.substr(2,move.length())=="RIGHT"||move.substr(2,move.length())=="LEFT")
                    return true;
                else
                    return false;
            }
        }
        return false;
    }

    vector<int> Game_two:: find_location(char m)
    {
        vector<int> a;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(game_board[i][j]==m)
                {
                    a.push_back(i);
                    a.push_back(j);
                    return a;
                }
            }
        }
        return a;
    }

    bool Game_two::playUser(string move)
    {
        char dest_char=move[0];
        vector<int> location=find_location(dest_char);
        int x= location.at(0);
        int y=location.at(1);
        if(dest_char=='A')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(location.at(0)-1>=0&&game_board[location.at(0)-1][location.at(1)]==' '&&game_board[location.at(0)-1][location.at(1)+1]==' ')
                {
                    game_board[x-1][y]=game_board[x-1][y+1]=game_board[x][y];
                    game_board[x+1][y]=game_board[x+1][y+1]=' ';
                    return true;
                }
                else 
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+2<=4&&game_board[x+2][y]==' '&&game_board[x+2][y+1]==' ')
                {
                    game_board[x+2][y]=game_board[x+2][y+1]=game_board[x+1][y];
                    game_board[x][y]=game_board[x][y+1]=' ';  
                    return true;
                }
                else
                    return true;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+2<=3&&game_board[x][y+2]==' '&&game_board[x+1][y+2]==' ')
                {
                    game_board[x][y+2]=game_board[x+1][y+2]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';   
                    return true;
                }
                else 
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' '&&game_board[x+1][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x+1][y-1]=game_board[x][y];
                    game_board[x][y+1]=game_board[x+1][y+1]=' ';
                    return true;
                }
                else 
                    return false;
            }
        }
        else if(dest_char=='B')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+2<=4&&game_board[x+2][y]==' ')
                {
                    game_board[x+2][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' '&&game_board[x+1][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x+1][y+1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' '&&game_board[x+1][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x+1][y-1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false; 
            }
        }
        else if(dest_char=='C')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+2<=4&&game_board[x+2][y]==' ')
                {
                    game_board[x+2][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' '&&game_board[x+1][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x+1][y+1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' '&&game_board[x+1][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x+1][y-1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false; 
            }
        }
        else if(dest_char=='D')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+2<=4&&game_board[x+2][y]==' ')
                {
                    game_board[x+2][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' '&&game_board[x+1][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x+1][y+1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' '&&game_board[x+1][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x+1][y-1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false; 
            }
        }
        else if(dest_char=='E')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+2<=4&&game_board[x+2][y]==' ')
                {
                    game_board[x+2][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' '&&game_board[x+1][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x+1][y+1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' '&&game_board[x+1][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x+1][y-1]=game_board[x][y];
                    game_board[x][y]=game_board[x+1][y]=' ';
                    return true;
                }
                else 
                    return false; 
            }
        }
        else if(dest_char=='F')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' '&&game_board[x-1][y+1]==' ')
                {
                    game_board[x-1][y]=game_board[x-1][y+1]=game_board[x][y];
                    game_board[x][y]=game_board[x-1][y]=' ';
                    return true;
                }
                else
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+1<=4&&game_board[x+1][y]==' '&&game_board[x+1][y+1]==' ')
                {
                    game_board[x+1][y]=game_board[x+1][y+1]=game_board[x][y];
                    game_board[x][y]=game_board[x][y+1]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+2<=3&&game_board[x][y+2]==' ')
                {
                    game_board[x][y+2]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=03&&game_board[x][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x][y];
                    game_board[x][y+1]=' ';
                    return true;
                }
                else
                    return false;
            }
        }
        else if(dest_char=='H')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+1<=4&&game_board[x+1][y]==' ')
                {
                    game_board[x+1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
        }
        else if(dest_char=='K')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+1<=4&&game_board[x+1][y]==' ')
                {
                    game_board[x+1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
        }
        else if(dest_char=='L')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+1<=4&&game_board[x+1][y]==' ')
                {
                    game_board[x+1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
        }
        else if(dest_char=='G')
        {
            if(move.substr(2,move.length())=="UP")
            {
                if(x-1>=0&&game_board[x-1][y]==' ')
                {
                    game_board[x-1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
            else if(move.substr(2,move.length())=="DOWN")
            {
                if(x+1<=4&&game_board[x+1][y]==' ')
                {
                    game_board[x+1][y]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }          
            else if(move.substr(2,move.length())=="RIGHT")
            {
                if(y+1<=3&&game_board[x][y+1]==' ')
                {
                    game_board[x][y+1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }                                    
            else if(move.substr(2,move.length())=="LEFT")
            {
                if(y-1>=0&&game_board[x][y-1]==' ')
                {
                    game_board[x][y-1]=game_board[x][y];
                    game_board[x][y]=' ';
                    return true;
                }
                else
                    return false;
            }
        }
        return false;
    }

    string Game_two::random_command()
    {
        vector<string> direction{"UP","DOWN","RIGHT","LEFT"};
        vector<string> row_{"A","B","C","D","E","F","G","H","K","L"};
        //vector<string> column_{"1","2","3","4","5","6","7","8"};
        string space =" "; 
        string move;
        int r,c,d;
        r=rand()%10;
        //c=rand()%;
        d=rand()%4;
        return move=row_.at(r)+space+direction.at(d);
    }

    bool Game_two::playAuto(string move)
    {
        if(is_define_value(move))
            return playUser(move);
        return false;
    }
    
    void Game_two::take_input(string move)
    {
        string a=move;
    }

    bool Game_two::endgame()
    {
        cout<<"kontrol noktası"<<endl;
        cout<<" "<<game_board[4][2]<<" "<<game_board[4][2]<<endl;
        if(game_board[4][2]=='A'&&game_board[4][1]=='A')
            return false;
        return true;
    }

    void Game_two::print()const
    {
        char a='A';
        int m=0;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(!(i==0&&j==0))
                {

                    if(i==0&&j>0)
                    {
                        cout<<"\033[1;43m"<<a<<"\033[0m"<<" ";
                        *file<<a<<" ";
                        a+=1; 
                    }
                    else if(i>0&&j==0)
                    {
                        cout<<"\033[1;43m"<<++m<<"\033[0m"<<" ";
                        *file<<m<<" ";
                    }

                    else if(game_board [i-1][j-1]=='A')
                    {
                        cout << "\033[1;31m"<<game_board[i-1][j-1]<<" "<<"\033[0m";
                        *file<<game_board[i-1][j-1]<<" ";
                    }
                    else if(game_board [i-1][j-1]==' ')
                    {
                        cout << "\033[1;35m"<<"  "<<"\033[0m";
                        *file<<" ";
                    }
                    else
                    {
                        cout<<game_board[i-1][j-1]<<" ";
                        *file<<game_board[i-1][j-1]<<" ";
                    }
                }
                else 
                    cout<<"  ";
                    *file<<"  ";
            }
            cout<<"\n";
            *file<<"\n";
        }
    }

    void Game_two::start_game()
    {
        cout<<"Welcome KLOTSKI Puzzle\n"<<endl;
        *file<<"Welcome KLOTSKI Puzzle\n"<<endl;
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
}