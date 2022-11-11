#include "lib.h"
int PegSolitare::peg_number=0;
gaming main_obj;
int main()
{
    int game_type,menu;
   // total_number_boards=0;
    main_obj.set_zero_to_total();
    //vector<PegSolitare> games;
    while(true)
    {
        cout<<"WELCOME PEGSOLITARE GAME : "<<endl;
        cout<<"1 -> Select board and watch and finish automatically "<<endl;
        cout<<"2-> Select board and help us "<<endl;
        cout<<"3-> compare all boards alread creating  "<<endl;
        cout<<"0->EXIT "<<endl;
        cin>>menu;
        if(menu==1)
        {
            PegSolitare temp(2);
            main_obj.vector_pushing(temp);
            main_obj.set_number_board();
            main_obj.get_board(main_obj.get_total_number_()-1).set_game_number(main_obj.get_total_number_());
            main_obj.get_board(main_obj.get_total_number_()-1).Initialize_board();
            main_obj.get_board(main_obj.get_total_number_()-1).set_play_yoursef(false);
            main_obj.get_board(main_obj.get_total_number_()-1).resize_numberOfElements();
            main_obj.get_board(main_obj.get_total_number_()-1).computer_game();
        }
        else if(menu==2)
        {
            PegSolitare temp(1);
            main_obj.vector_pushing(temp);
            main_obj.set_number_board();
            main_obj.get_board(main_obj.get_total_number_()-1).set_game_number(main_obj.get_total_number_());
            main_obj.get_board(main_obj.get_total_number_()-1).Initialize_board();
            main_obj.get_board(main_obj.get_total_number_()-1).set_play_yoursef(true);
            main_obj.get_board(main_obj.get_total_number_()-1).resize_numberOfElements();
            main_obj.get_board(main_obj.get_total_number_()-1).computer_game();
        }
        else if(menu==3)
        {
            int peg=0;
            for(int i=0;i<main_obj.get_total_number_();i++)
            {
                cout<<endl<<endl<<"For gamer "<<i+1<<endl;
                cout<<"Gamer type is "<<main_obj.get_board(i).get_gamertype()<<endl;
                cout<<"Board number  is "<<main_obj.get_board(i).get_board_number()<<endl;
                cout<<"Total movement number is "<<main_obj.get_board(i).get_movemnt()<<endl;
                cout<<"Total empty cell number is "<<main_obj.get_board(i).get_empty()<<endl;
                cout<<"Total peg cell number is "<<main_obj.get_board(i).get_peg()<<endl<<endl;
                peg+=main_obj.get_board(i).get_peg();

            }
            PegSolitare::set_pec_number(peg);
            cout<<"Total Peg number is "<<PegSolitare::get_pec_number()<<endl;
        }
        else if(menu==0)
            break;
    }
   
    return 0;
}


