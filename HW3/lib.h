#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<fstream>
#include<algorithm>
#include<ios>
#include<limits>

using namespace std;


enum class cellType {none, empty, peg};

//using board = std::vector<std::vector<cell>>;

class PegSolitare{
    public:
        class Cell
        {
            public:
                Cell(int _row, char _column, cellType _cell);
                Cell();
                void setRow(int row);
                void setColumn(char column);
                void setCell(cellType _cell);
                inline int getRow() const{return row;};
                inline char getColumn() const {return column;};
                inline cellType getCell() const {return cell;};

            private:
                int row;
                char column;
                cellType cell;
        };
        
        void computer_game();
        typedef  vector<std::vector<Cell>> (PegSolitare::*PEgMemptr)();/*typedef for type of pointer to member funct*/
        bool start_take();/*to direct taking command function during execution time*/
        vector<std::vector<Cell>> first_table();
        vector<std::vector<Cell>> second_table();
        vector<std::vector<Cell>> third_table();/*creater of game board*/
        vector<std::vector<Cell>> fourth_table();
        vector<std::vector<Cell>> fifth_table();
        vector<std::vector<Cell>> sixth_table();
        bool for_txt(string &file);/*control extention of file for .txt*/
        string file_name_command(string &input);/*divide to string command and filenae*/
        inline string get_file_name(){ return file_name ;};
        void print_game();/*print game board*/
        PegSolitare(int gamer);/*construction of class*/
        PegSolitare();
        inline int get_board_number(){  return board_number;};/*return board number that choosen by user*/
        bool control_commnad(string name_command);/*control command*/
        bool control_file_name(string name_file);/*control file name*/
        void Initialize_board();/*create board*/
        //void set_obj(PegSolitare *obj);/* assign decleared variable to own_obj*/
        void set_board(vector<std::vector<Cell>> temp);/*set board after controlling*/
        void resize_numberOfElements();/*set the array for count game moving*/
        int countNumberofpeg();
        int control_board6(int dir);
        int player_game(vector<int> &control);
        int control_board(int dir);
        void save_file();
        vector<std::vector<Cell>> load_from_file();
        void set_play_yoursef(bool temp);
        void calculate_elements();
        void set_game_number(int number);
        int get_peg(){return numberofElements[0];};
        int get_movemnt(){return numberofElements[2];};
        int get_empty(){return numberofElements[1];};
       inline int get_gamertype(){return gamer_type;};
        void update_cell_();
       vector<std::vector<Cell>> get_board(){return game_board;};
        //int get_board_number(){return board_number;}; 
        int game_number;
        static int get_pec_number(){return peg_number;};
        inline int get_movement(){return movement_number;};
        static void set_pec_number(int i){ peg_number=i;};
    private:
        int movement_number;
        static int peg_number;
        inline void set_movement(int i){ movement_number=i ;};
        //void push_object_to_vec(vector<PegSolitare> &games,PegSolitare h);
        bool play_yourself;    
        int numberofElements[3];/*0->peg 1->empty 2-> taken from*/
        PegSolitare *own_obj;
        PEgMemptr creater[6] ;/*this array for adding to function for create board*/
        vector<std::vector<Cell>> game_board;
        int gamer_type;
        int board_number;
        string file_name,command;
        bool set_board_number(int number);
        void initialize_creater_of_board_vec();/*function far adding function to array*/
        void set_filename(string name_of_file);
        void set_command(string name_of_command);
        bool taking_command();
};
using board = std::vector<std::vector<PegSolitare::Cell>>;
class gaming{
 public:
    inline PegSolitare &get_board(int i){return games.at(i); };
    inline int get_total_number_(){return total_number_boards;};
    inline void vector_pushing(PegSolitare &obj){games.push_back(obj); };
    inline void set_zero_to_total(){ total_number_boards=0;};
    void set_number_board(){total_number_boards++;};
 private:
    vector<PegSolitare> games;
    int total_number_boards=0;
};
// vector<PegSolitare> games;
// int total_number_boards;

