#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<fstream>
#include<algorithm>
#include<stdio.h>

using namespace std;

enum class cell{
    empty,peg,none,
};
using board = std::vector<std::vector<cell>>;
void print_game(vector<vector<cell>> boardl );
void play_game(vector<vector<cell>> boardl ,string input);
void computer_game(vector<vector<cell>> boardl,int gamer_type,int board_number);
 int player_game(board boardl,vector<int> &control,int board_size);
int control_board(board boardl ,int dir);
int control_board6(board boardl ,int dir);
void save_file(string filename,board boardl,string gametype,int movement_size,int board_number);
void return_random(board boardl,int *ver,int *hor);
bool for_command();
string file_name_command(string &input,string &file_name,string &command);
board load_from_file(string &filename,int &board_number,int &game_number);
bool for_txt(string &file);
bool for_command(string &file_name,string &command);
board first_table();
board second_table();
board third_table();
board fourth_table();
board fifth_table();
board sixth_table();
