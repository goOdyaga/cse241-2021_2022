#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<functional>
#include "lib.h"

int main()
{
	srand(time(NULL));
    int chose,board_type;
    std:: vector<std::function<board()>> functions;
	functions.push_back(first_table);
    functions.push_back(second_table);
    functions.push_back(third_table);
    functions.push_back(fourth_table);
    functions.push_back(fifth_table);
    functions.push_back(sixth_table);
    cout<<"Please chose board type"<<endl;
    cin>>board_type;
    board b=functions[board_type-1]();
    print_game(b);   
    cout<<"welcome Game"<<endl;
    int game_type;
    cout<<"1.Personal game "<<endl<<"2.Computer game"<<endl;
    cin>>game_type;
    vector<vector<int >>a;
    computer_game(b,game_type,board_type);
}


