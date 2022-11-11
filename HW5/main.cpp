//# include "main_library.h"
#include "gamelib1.h"
#include "gamelib2.h"
using namespace GOS;
int main()
{
    int temp_gamer_type,game;
    vector<BoardGAME2D *> games;
    while(true)
    {
        cout<<"\t\t\tWELCOME GAME SELECTION MENU\n"
                <<"Which game do ypu want to play\n"
                <<"1->3x3 PUZZLE\n"
                <<"2->KLOTSKI PUZZLE\n"
                <<"3->EXIT\n"
                <<"Please Select"<<endl;
        cin>>game;
        if(game==1)
        {
            cout<<"Do you want to automatically or manually\n"
            <<"1->you will play\n "
            <<"2->computer will play\n"
            <<"Please Select ";
            cin>>temp_gamer_type;
            BoardGAME2D *temp=new Game_one(temp_gamer_type);
            games.push_back(temp);
            temp->start_game();

        }

        else if(game==2)
        {
            cout<<"Do you want to automatically or manually\n"
            <<"1->you will play\n "
            <<"2->computer will play\n"
            <<"Please Select ";
            cin>>temp_gamer_type;
            BoardGAME2D *temp=new Game_two(temp_gamer_type);
            games.push_back(temp);
            temp->start_game();
        }
        else if(game==3)
            break;
        else
            cout<<"Invalid input!!Try Again :<(("<<endl;
    }
    BoardGAME2D::playVector(games);
    return 0;

}