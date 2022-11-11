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


bool PegSolitare::start_take()
{
    return taking_command();
}

PegSolitare::Cell::Cell(int _row, char _column, cellType _cell): row(_row), column(_column), cell(_cell)
{}
PegSolitare::Cell::Cell()
{}

void PegSolitare::Cell::setCell(cellType newCell)
{
    cell = newCell;
}
void PegSolitare::Cell::setRow(int newRow)
{
    row = newRow;
}
void PegSolitare::Cell::setColumn(char newColumn)
{
    column = newColumn;
}
PegSolitare ::PegSolitare()
:gamer_type(2)
{}

PegSolitare::PegSolitare(int gamer)
:gamer_type(gamer)
{
    if(gamer==1||gamer==2)
    {
        int number_of_board_temp;
        while(true)
        {
            cout<<"Please select board type (1-6) : ";
            cin>>number_of_board_temp;
            if(set_board_number(number_of_board_temp))
                break;
            else 
                cout<<"Plase correct input !! >:( "<<endl;
        }
        initialize_creater_of_board_vec();
        // Initialize_board();
        // print_game();
    }
    else 
    {
        cout<<"Invalid gamer type !!! Game will terminating !!!";
        exit(-1);
    }
    return ;
        
}

bool PegSolitare::set_board_number(int number)
{
    if(number>0&&number<7)
    {
        board_number=number;
        return true;
    }
    return false;
}

void PegSolitare::initialize_creater_of_board_vec()
{
    
    creater[0]=&PegSolitare::first_table;
    creater[1]=&PegSolitare::second_table;
    creater[2]=&PegSolitare::third_table;
    creater[3]=&PegSolitare::fourth_table;
    creater[4]=&PegSolitare::fifth_table;
    creater[5]=&PegSolitare::sixth_table;
    return;
}
board PegSolitare::fourth_table() /* Initiliaze the game as the 'fourth' table that is showed in PDF */
{
    vector <vector<PegSolitare::Cell>> board1 = {
            {PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'B',cellType::none), PegSolitare::Cell(1,'C',cellType::peg),PegSolitare::Cell(1,'D',cellType::peg),PegSolitare::Cell(1,'E',cellType::peg),PegSolitare::Cell(1,'F',cellType::none),PegSolitare::Cell(1,'G',cellType::none)}, 
            {PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'B',cellType::none), PegSolitare::Cell(2,'C',cellType::peg),PegSolitare::Cell(2,'D',cellType::peg),PegSolitare::Cell(2,'E',cellType::peg),PegSolitare::Cell(2,'F',cellType::none),PegSolitare::Cell(2,'G',cellType::none)}, 
            {PegSolitare::Cell(3,'A',cellType::peg), PegSolitare::Cell(3,'B',cellType::peg), PegSolitare::Cell(3,'C',cellType::peg),PegSolitare::Cell(3,'D',cellType::peg),PegSolitare::Cell(3,'E',cellType::peg),PegSolitare::Cell(3,'F',cellType::peg),PegSolitare::Cell(3,'G',cellType::peg)}, 
            {PegSolitare::Cell(4,'A',cellType::peg), PegSolitare::Cell(4,'B',cellType::peg), PegSolitare::Cell(4,'C',cellType::peg),PegSolitare::Cell(4,'D',cellType::empty),PegSolitare::Cell(4,'E',cellType::peg),PegSolitare::Cell(4,'F',cellType::peg),PegSolitare::Cell(4,'G',cellType::peg)},
            {PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'B',cellType::peg), PegSolitare::Cell(5,'C',cellType::peg),PegSolitare::Cell(5,'D',cellType::peg),PegSolitare::Cell(5,'E',cellType::peg),PegSolitare::Cell(5,'F',cellType::peg),PegSolitare::Cell(5,'G',cellType::peg)}, 
            {PegSolitare::Cell(6,'A',cellType::none), PegSolitare::Cell(6,'B',cellType::none), PegSolitare::Cell(6,'C',cellType::peg),PegSolitare::Cell(6,'D',cellType::peg),PegSolitare::Cell(6,'E',cellType::peg),PegSolitare::Cell(6,'F',cellType::none),PegSolitare::Cell(6,'G',cellType::none)}, 
            {PegSolitare::Cell(7,'A',cellType::none), PegSolitare::Cell(7,'B',cellType::none), PegSolitare::Cell(7,'C',cellType::peg),PegSolitare::Cell(7,'D',cellType::peg),PegSolitare::Cell(7,'E',cellType::peg),PegSolitare::Cell(7,'F',cellType::none),PegSolitare::Cell(7,'G',cellType::none)}
            };
   return board1;
}

vector <vector<PegSolitare::Cell>>  PegSolitare::second_table() /* Initiliaze the game as the 'second' table that is showed in PDF */
{
    vector <vector<PegSolitare::Cell>> board1 = {
            {PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'B',cellType::none), PegSolitare::Cell(1,'C',cellType::none), PegSolitare::Cell(1,'D',cellType::peg),PegSolitare::Cell(1,'E',cellType::peg),PegSolitare::Cell(1,'F',cellType::peg),PegSolitare::Cell(1,'G',cellType::none),PegSolitare::Cell(1,'H',cellType::none), PegSolitare::Cell(1,'I',cellType::none)}, 
            {PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'B',cellType::none), PegSolitare::Cell(2,'C',cellType::none), PegSolitare::Cell(2,'D',cellType::peg),PegSolitare::Cell(2,'E',cellType::peg),PegSolitare::Cell(2,'F',cellType::peg),PegSolitare::Cell(2,'G',cellType::none),PegSolitare::Cell(2,'H',cellType::none), PegSolitare::Cell(2,'I',cellType::none)}, 
            {PegSolitare::Cell(3,'A',cellType::none), PegSolitare::Cell(3,'B',cellType::none), PegSolitare::Cell(3,'C',cellType::none), PegSolitare::Cell(3,'D',cellType::peg),PegSolitare::Cell(3,'E',cellType::peg),PegSolitare::Cell(3,'F',cellType::peg),PegSolitare::Cell(3,'G',cellType::none),PegSolitare::Cell(3,'H',cellType::none), PegSolitare::Cell(3,'I',cellType::none)},
            {PegSolitare::Cell(4,'A',cellType::peg), PegSolitare::Cell(4,'B',cellType::peg), PegSolitare::Cell(4,'C',cellType::peg),PegSolitare::Cell(4,'D',cellType::peg),PegSolitare::Cell(4,'E',cellType::peg),PegSolitare::Cell(4,'F',cellType::peg),PegSolitare::Cell(4,'G',cellType::peg), PegSolitare::Cell(4,'H',cellType::peg), PegSolitare::Cell(4,'I',cellType::peg)}, 
            {PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'B',cellType::peg), PegSolitare::Cell(5,'C',cellType::peg),PegSolitare::Cell(5,'D',cellType::peg),PegSolitare::Cell(5,'E',cellType::empty),PegSolitare::Cell(5,'F',cellType::peg),PegSolitare::Cell(5,'G',cellType::peg), PegSolitare::Cell(5,'H',cellType::peg), PegSolitare::Cell(5,'I',cellType::peg)}, 
            {PegSolitare::Cell(6,'A',cellType::peg), PegSolitare::Cell(6,'B',cellType::peg), PegSolitare::Cell(6,'C',cellType::peg),PegSolitare::Cell(6,'D',cellType::peg),PegSolitare::Cell(6,'E',cellType::peg),PegSolitare::Cell(6,'F',cellType::peg),PegSolitare::Cell(6,'G',cellType::peg), PegSolitare::Cell(6,'H',cellType::peg), PegSolitare::Cell(6,'I',cellType::peg)}, 
            {PegSolitare::Cell(7,'A',cellType::none), PegSolitare::Cell(7,'B',cellType::none), PegSolitare::Cell(7,'C',cellType::none), PegSolitare::Cell(7,'D',cellType::peg),PegSolitare::Cell(7,'E',cellType::peg),PegSolitare::Cell(7,'F',cellType::peg),PegSolitare::Cell(7,'G',cellType::none),PegSolitare::Cell(7,'H',cellType::none), PegSolitare::Cell(7,'I',cellType::none)}, 
            {PegSolitare::Cell(8,'A',cellType::none), PegSolitare::Cell(8,'B',cellType::none), PegSolitare::Cell(8,'C',cellType::none) ,PegSolitare::Cell(8,'D',cellType::peg),PegSolitare::Cell(8,'E',cellType::peg),PegSolitare::Cell(8,'F',cellType::peg),PegSolitare::Cell(8,'G',cellType::none),PegSolitare::Cell(8,'H',cellType::none), PegSolitare::Cell(8,'I',cellType::none)}, 
            {PegSolitare::Cell(9,'A',cellType::none), PegSolitare::Cell(9,'B',cellType::none), PegSolitare::Cell(9,'C',cellType::none), PegSolitare::Cell(9,'D',cellType::peg),PegSolitare::Cell(9,'E',cellType::peg),PegSolitare::Cell(9,'F',cellType::peg),PegSolitare::Cell(9,'G',cellType::none),PegSolitare::Cell(9,'H',cellType::none), PegSolitare::Cell(9,'I',cellType::none)}
            };

    return board1;
}

vector <vector<PegSolitare::Cell>> PegSolitare::first_table() /* Initiliaze the game as the 'first' table that is showed in PDF */
{
    vector <vector<PegSolitare::Cell>> board1 = {
            {PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'B',cellType::none), PegSolitare::Cell(1,'C',cellType::peg),PegSolitare::Cell(1,'D',cellType::peg),PegSolitare::Cell(1,'E',cellType::peg),PegSolitare::Cell(1,'F',cellType::none),PegSolitare::Cell(1,'G',cellType::none)}, 
            {PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'B',cellType::peg), PegSolitare::Cell(2,'C',cellType::peg),PegSolitare::Cell(2,'D',cellType::peg),PegSolitare::Cell(2,'E',cellType::peg),PegSolitare::Cell(2,'F',cellType::peg),PegSolitare::Cell(2,'G',cellType::none)}, 
            {PegSolitare::Cell(3,'A',cellType::peg), PegSolitare::Cell(3,'B',cellType::peg), PegSolitare::Cell(3,'C',cellType::peg),PegSolitare::Cell(3,'D',cellType::empty),PegSolitare::Cell(3,'E',cellType::peg),PegSolitare::Cell(3,'F',cellType::peg),PegSolitare::Cell(3,'G',cellType::peg)}, 
            {PegSolitare::Cell(4,'A',cellType::peg), PegSolitare::Cell(4,'B',cellType::peg), PegSolitare::Cell(4,'C',cellType::peg),PegSolitare::Cell(4,'D',cellType::peg),PegSolitare::Cell(4,'E',cellType::peg),PegSolitare::Cell(4,'F',cellType::peg),PegSolitare::Cell(4,'G',cellType::peg)}, 
            {PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'B',cellType::peg), PegSolitare::Cell(5,'C',cellType::peg),PegSolitare::Cell(5,'D',cellType::peg),PegSolitare::Cell(5,'E',cellType::peg),PegSolitare::Cell(5,'F',cellType::peg),PegSolitare::Cell(5,'G',cellType::peg)}, 
            {PegSolitare::Cell(6,'A',cellType::none), PegSolitare::Cell(6,'B',cellType::peg), PegSolitare::Cell(6,'C',cellType::peg),PegSolitare::Cell(6,'D',cellType::peg),PegSolitare::Cell(6,'E',cellType::peg),PegSolitare::Cell(6,'F',cellType::peg),PegSolitare::Cell(6,'G',cellType::none)}, 
            {PegSolitare::Cell(7,'A',cellType::none), PegSolitare::Cell(7,'B',cellType::none), PegSolitare::Cell(7,'C',cellType::peg),PegSolitare::Cell(7,'D',cellType::peg),PegSolitare::Cell(7,'E',cellType::peg),PegSolitare::Cell(7,'F',cellType::none),PegSolitare::Cell(7,'G',cellType::none)}
            };
    return board1;
}

vector <vector<PegSolitare::Cell>> PegSolitare::third_table() /* Initiliaze the game as the 'third' table that is showed in PDF */
{
    vector <vector<Cell>> board1 = {
            {PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'B',cellType::none), PegSolitare::Cell(1,'C',cellType::peg),PegSolitare::Cell(1,'D',cellType::peg),PegSolitare::Cell(1,'E',cellType::peg),PegSolitare::Cell(1,'F',cellType::none),PegSolitare::Cell(1,'G',cellType::none), PegSolitare::Cell(1,'H',cellType::none)}, 
            {PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'B',cellType::none), PegSolitare::Cell(2,'C',cellType::peg),PegSolitare::Cell(2,'D',cellType::peg),PegSolitare::Cell(2,'E',cellType::peg),PegSolitare::Cell(2,'F',cellType::none),PegSolitare::Cell(2,'G',cellType::none), PegSolitare::Cell(2,'H',cellType::none)}, 
            {PegSolitare::Cell(3,'A',cellType::none), PegSolitare::Cell(3,'B',cellType::none), PegSolitare::Cell(3,'C',cellType::peg),PegSolitare::Cell(3,'D',cellType::peg),PegSolitare::Cell(3,'E',cellType::peg),PegSolitare::Cell(3,'F',cellType::none),PegSolitare::Cell(3,'G',cellType::none), PegSolitare::Cell(3,'H',cellType::none)},
            {PegSolitare::Cell(4,'A',cellType::peg), PegSolitare::Cell(4,'B',cellType::peg), PegSolitare::Cell(4,'C',cellType::peg),PegSolitare::Cell(4,'D',cellType::peg),PegSolitare::Cell(4,'E',cellType::peg),PegSolitare::Cell(4,'F',cellType::peg),PegSolitare::Cell(4,'G',cellType::peg), PegSolitare::Cell(4,'H',cellType::peg)}, 
            {PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'B',cellType::peg), PegSolitare::Cell(5,'C',cellType::peg),PegSolitare::Cell(5,'D',cellType::empty),PegSolitare::Cell(5,'E',cellType::peg),PegSolitare::Cell(5,'F',cellType::peg),PegSolitare::Cell(5,'G',cellType::peg), PegSolitare::Cell(5,'H',cellType::peg)}, 
            {PegSolitare::Cell(6,'A',cellType::peg), PegSolitare::Cell(6,'B',cellType::peg), PegSolitare::Cell(6,'C',cellType::peg),PegSolitare::Cell(6,'D',cellType::peg),PegSolitare::Cell(6,'E',cellType::peg),PegSolitare::Cell(6,'F',cellType::peg),PegSolitare::Cell(6,'G',cellType::peg), PegSolitare::Cell(6,'H',cellType::peg)}, 
            {PegSolitare::Cell(7,'A',cellType::none), PegSolitare::Cell(7,'B',cellType::none), PegSolitare::Cell(7,'C',cellType::peg),PegSolitare::Cell(7,'D',cellType::peg),PegSolitare::Cell(7,'E',cellType::peg),PegSolitare::Cell(7,'F',cellType::none),PegSolitare::Cell(7,'G',cellType::none), PegSolitare::Cell(7,'H',cellType::none)}, 
            {PegSolitare::Cell(8,'A',cellType::none), PegSolitare::Cell(8,'B',cellType::none), PegSolitare::Cell(8,'C',cellType::peg),PegSolitare::Cell(8,'D',cellType::peg),PegSolitare::Cell(8,'E',cellType::peg),PegSolitare::Cell(8,'F',cellType::none),PegSolitare::Cell(8,'G',cellType::none), PegSolitare::Cell(8,'H',cellType::none)}
            };
    return board1;
}

vector <vector<PegSolitare::Cell>> PegSolitare::fifth_table() /* Initiliaze the game as the 'fifth' table that is showed in PDF */
{
    vector <vector<Cell>> board1 = {
            {PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'B',cellType::none), PegSolitare::Cell(1,'C',cellType::none),PegSolitare::Cell(1,'D',cellType::none), PegSolitare::Cell(1,'E',cellType::peg), PegSolitare::Cell(1,'F',cellType::none), PegSolitare::Cell(1,'G',cellType::none), PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'A',cellType::none)}, 
            {PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'B',cellType::none), PegSolitare::Cell(2,'C',cellType::none),PegSolitare::Cell(2,'D',cellType::peg), PegSolitare::Cell(2,'E',cellType::peg), PegSolitare::Cell(2,'F',cellType::peg), PegSolitare::Cell(2,'G',cellType::none), PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'A',cellType::none)}, 
            {PegSolitare::Cell(3,'A',cellType::none), PegSolitare::Cell(3,'B',cellType::none), PegSolitare::Cell(3,'C',cellType::peg),PegSolitare::Cell(3,'D',cellType::peg), PegSolitare::Cell(3,'E',cellType::peg), PegSolitare::Cell(3,'F',cellType::peg), PegSolitare::Cell(3,'G',cellType::peg), PegSolitare::Cell(3,'A',cellType::none), PegSolitare::Cell(3,'A',cellType::none)}, 
            {PegSolitare::Cell(4,'A',cellType::none), PegSolitare::Cell(4,'B',cellType::peg), PegSolitare::Cell(4,'C',cellType::peg),PegSolitare::Cell(4,'D',cellType::peg), PegSolitare::Cell(4,'E',cellType::peg), PegSolitare::Cell(4,'F',cellType::peg), PegSolitare::Cell(4,'G',cellType::peg), PegSolitare::Cell(4,'A',cellType::peg), PegSolitare::Cell(1,'A',cellType::none)}, 
            {PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'B',cellType::peg), PegSolitare::Cell(5,'C',cellType::peg),PegSolitare::Cell(5,'D',cellType::peg), PegSolitare::Cell(5,'E',cellType::empty), PegSolitare::Cell(5,'F',cellType::peg), PegSolitare::Cell(5,'G',cellType::peg), PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'A',cellType::peg)},
            {PegSolitare::Cell(6,'A',cellType::none), PegSolitare::Cell(6,'B',cellType::peg), PegSolitare::Cell(6,'C',cellType::peg),PegSolitare::Cell(6,'D',cellType::peg), PegSolitare::Cell(6,'E',cellType::peg), PegSolitare::Cell(6,'F',cellType::peg), PegSolitare::Cell(6,'G',cellType::peg), PegSolitare::Cell(6,'A',cellType::peg), PegSolitare::Cell(6,'A',cellType::none)}, 
            {PegSolitare::Cell(7,'A',cellType::none), PegSolitare::Cell(7,'B',cellType::none), PegSolitare::Cell(7,'C',cellType::peg),PegSolitare::Cell(7,'D',cellType::peg), PegSolitare::Cell(7,'E',cellType::peg), PegSolitare::Cell(7,'F',cellType::peg), PegSolitare::Cell(7,'G',cellType::peg), PegSolitare::Cell(7,'A',cellType::none), PegSolitare::Cell(7,'A',cellType::none)}, 
            {PegSolitare::Cell(8,'A',cellType::none), PegSolitare::Cell(8,'B',cellType::none), PegSolitare::Cell(8,'C',cellType::none),PegSolitare::Cell(8,'D',cellType::peg), PegSolitare::Cell(8,'E',cellType::peg), PegSolitare::Cell(8,'F',cellType::peg), PegSolitare::Cell(8,'G',cellType::none), PegSolitare::Cell(8,'A',cellType::none), PegSolitare::Cell(8,'A',cellType::none)}, 
            {PegSolitare::Cell(9,'A',cellType::none), PegSolitare::Cell(9,'B',cellType::none), PegSolitare::Cell(9,'C',cellType::none),PegSolitare::Cell(9,'D',cellType::none), PegSolitare::Cell(5,'D',cellType::peg), PegSolitare::Cell(9,'F',cellType::none), PegSolitare::Cell(9,'G',cellType::none), PegSolitare::Cell(9,'A',cellType::none), PegSolitare::Cell(9,'A',cellType::none)}
            };
    return board1;
}

vector <vector<PegSolitare::Cell>> PegSolitare::sixth_table() /* Initiliaze the game as the 'sixth' table that is showed in PDF */
{
    vector <vector<Cell>> board1 = {
                {PegSolitare::Cell(1,'A',cellType::none), PegSolitare::Cell(1,'B',cellType::none), PegSolitare::Cell(1,'C',cellType::none), PegSolitare::Cell(1,'D',cellType::none), PegSolitare::Cell(1,'E',cellType::empty), PegSolitare::Cell(1,'F',cellType::none), PegSolitare::Cell(1,'G',cellType::none), PegSolitare::Cell(1,'H',cellType::none), PegSolitare::Cell(1,'I',cellType::none)},
                {PegSolitare::Cell(2,'A',cellType::none), PegSolitare::Cell(2,'B',cellType::none), PegSolitare::Cell(2,'C',cellType::none), PegSolitare::Cell(2,'D',cellType::peg), PegSolitare::Cell(2,'E',cellType::none), PegSolitare::Cell(2,'F',cellType::peg), PegSolitare::Cell(2,'G',cellType::none), PegSolitare::Cell(2,'H',cellType::none), PegSolitare::Cell(2,'I',cellType::none)},
                {PegSolitare::Cell(3,'A',cellType::none), PegSolitare::Cell(3,'B',cellType::none), PegSolitare::Cell(3,'C',cellType::peg), PegSolitare::Cell(3,'D',cellType::none), PegSolitare::Cell(3,'E',cellType::peg), PegSolitare::Cell(3,'F',cellType::none), PegSolitare::Cell(3,'G',cellType::peg), PegSolitare::Cell(3,'H',cellType::none), PegSolitare::Cell(3,'I',cellType::none)},
                {PegSolitare::Cell(4,'A',cellType::none), PegSolitare::Cell(4,'B',cellType::peg), PegSolitare::Cell(4,'C',cellType::none), PegSolitare::Cell(4,'D',cellType::peg), PegSolitare::Cell(4,'E',cellType::none), PegSolitare::Cell(4,'F',cellType::peg), PegSolitare::Cell(4,'G',cellType::none), PegSolitare::Cell(4,'H',cellType::peg), PegSolitare::Cell(4,'I',cellType::none)},
                {PegSolitare::Cell(5,'A',cellType::peg), PegSolitare::Cell(5,'B',cellType::none), PegSolitare::Cell(5,'C',cellType::peg), PegSolitare::Cell(5,'D',cellType::none), PegSolitare::Cell(5,'E',cellType::peg), PegSolitare::Cell(5,'F',cellType::none), PegSolitare::Cell(5,'G',cellType::peg), PegSolitare::Cell(5,'H',cellType::none), PegSolitare::Cell(5,'I',cellType::peg)},
            };
    return board1;
}

void PegSolitare::Initialize_board()
{
    set_board(std::invoke(creater[get_board_number()-1],*own_obj));
    print_game();
}

void  PegSolitare:: print_game( )
{
    for (vector<Cell> vect1D : game_board)
    {
        for (Cell x : vect1D)
        {
            if(x.getCell()==cellType::none)
                cout<<"  ";
            if(x.getCell()==cellType::peg)
                cout<<"P ";
            if(x.getCell()==cellType::empty)
                cout<<". ";
        }    
        cout << endl;
    }
}

bool PegSolitare::taking_command()
{
    string for_game;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Please enter command or press Enter"<<endl;
    getline(cin,for_game);
    if(for_game=="")
        return false;
    else
    {   
        string control, for_error=file_name_command(for_game);
        if(for_error=="ERROR")
        {
            cerr<<"ERROR !! Invalid command "<<endl; 
            bool again=taking_command();
        }
        else if(for_error=="ERROR1")
        {
            cerr<<"Invlaid file name"<<endl;
            bool again=taking_command();
        }
        else if(for_error=="OK")
            return true;
    }
    return true;
}

string PegSolitare:: file_name_command(string &input)
{
    int i=0,control=0;
    string command_temp=input.substr(0,4);
    transform(command.begin(),command.end(),command.begin(),::toupper);
    if(control_commnad(command_temp))
    {
        set_command(command_temp);
        control=input.find(command);
        string temp_of_file=input.substr(5);
        if(control_file_name(temp_of_file))
        {
            set_filename(temp_of_file);
            return "OK";
        }
         else
             return "ERROR1";  
    }
    return "ERROR";
}

bool PegSolitare::control_commnad(string name_command)
{
    if(name_command=="LOAD"||name_command=="SAVE")
        return true;
    return false;
}

bool PegSolitare:: for_txt(string &file)
{
    string control;
    int i=file.size();
    if(i>4)
    {
        for(int m=0;m<4;m++)
            control+=file.at(i-1-m);
        if(control=="txt.")
            return true;
        else 
            return false;
    }
    return false;
}

void PegSolitare::set_command(string name_of_command)
{
    command=name_of_command;
}

bool PegSolitare:: control_file_name(string name_file)
{
    if(for_txt(name_file))
        return true;
    else 
        return false;
}

void PegSolitare::set_filename(string name_of_file)
{
    file_name=name_of_file;
}

void PegSolitare::set_board(vector<std::vector<Cell>> temp)
{
    game_board=temp;
}

int PegSolitare::countNumberofpeg()
{
    int counter=0;
    for(auto x:game_board)
        for(auto y:x)
            if(y.getCell()==cellType::peg)
                counter++;
    return counter;
}       
       
void PegSolitare:: resize_numberOfElements()
{
    numberofElements[0]=countNumberofpeg();
    numberofElements[1]=1;
    numberofElements[2]=0;
}
 

void PegSolitare::computer_game( )
{
    PegSolitare temp;
	int hor,ver,dir,new_input,a=1;
    bool load_controller=false,is_play=true,is_auto=false;
    board new_board;
    string gamer;
    if(gamer_type==1)
        gamer="HUMAN";
    else if(gamer_type==2)
        gamer="COMPUTER";
	vector<int> control={1,-1,1,-1};
	vector<vector<int>> control1={{-1,1},{1,-1},{-1,-1},{1,1}};
    int size1,size2;
    bool controlling_command;
    if(board_number!=6)
    {
        size1=game_board.size();
        size2=game_board[0].size();
    }
    else
    {
        size1=5;
        size2=9;
    }
    if(board_number==6)
        control={0,0,0,0};
    else
        control1={{0,0},{0,0},{0,0},{0,0}};
    vector<int>input;
    int number_step=0;
    int i=0;
	while(1)
	{
        i++;
        if(gamer_type==2||is_auto)
        {
            if(board_number==6)
            {
                control1={{-1,1},{1,-1},{-1,-1},{1,1}};
                ver=rand()%9;
                hor=rand()%5;
	            dir=rand()%6;
                if(dir>3)
                {
                    control={1,-1,0,0};
                    control1={{0,0},{0,0},{0,0},{0,0}};

                }
                  
            }
            else
            {
                hor=rand()%game_board.size();
                ver=rand()%game_board[0].size();
                dir=rand()%4;
            }
        }
        else if(gamer_type==1&&is_play)
        {
            cout<<"1-> Random Moving : "<<endl;
            cout<<"2-> Play yourself : "<<endl;
            cout<<"3-> Finish automatically : "<<endl;
            cin>>new_input;
            if(new_input==1)
            {
                 cout<<new_input<<"<----"<<endl;
                is_play=false;
                if(board_number==6)
                {
                    control1={{-1,1},{1,-1},{-1,-1},{1,1}};
                    ver=rand()%9;
                    hor=rand()%5;
	                dir=rand()%6;
                    if(dir>3)
                    {
                        control={1,-1,0,0};
                        control1={{0,0},{0,0},{0,0},{0,0}};

                    }

                }
                else
                {
                    hor=rand()%game_board.size();
                    ver=rand()%game_board[0].size();
                    dir=rand()%4;
                }
            }
            else if(new_input==2)
            {
                is_play=false;
                int a =player_game(input);
                ver=input[0];
                hor=input[1];
                dir=input[2];
                input.clear();
            }
            
            else if(new_input==3)
            {
                is_play=false;
                play_yourself=false;
                is_auto=true;
            }
           
        }
        else if(is_play==false)
        {
            if(board_number==6)
            {
                control1={{-1,1},{1,-1},{-1,-1},{1,1}};
                ver=rand()%9;
                hor=rand()%5;
                dir=rand()%6;
                if(dir>3)
                {
                    control={1,-1,0,0};
                    control1={{0,0},{0,0},{0,0},{0,0}};

                }

            }
            else
            {
                hor=rand()%game_board.size();
                ver=rand()%game_board[0].size();
                dir=rand()%4;
            }   
        }
        else if(a==0)
        {
            cout<<"Invalid choosing . Please try again"<<endl;
            computer_game();
        }
		if(game_board[hor][ver].getCell()==cellType::peg)
		{
			if(dir<2)
            {
                
            	if(((ver+2*control[dir]+2*control1[dir][1]>=0))&&(ver+2*control1[dir][1]+2*control[dir]<size2)&&((hor+2*control1[dir][0]>=0))&&(hor+2*control1[dir][0]<size1))
                {
                    if((game_board[hor+control1[dir][0]][ver+control1[dir][1]+control[dir]].getCell()==cellType::peg)
                    &&(game_board[hor+2*control1[dir][0]][ver+2*control[dir]+2*control1[dir][1]].getCell()==cellType::empty))
                    {
                        //controlling_command=for_command(file_name,command);
                        is_play=true;
                        if(play_yourself==true)
                        {
                            if(temp.start_take())
                            {
                                if(temp.command=="SAVE")
                                {
                                    string continue_game;
                                    set_filename(temp.get_file_name());
                                    save_file();
                                    cout<<"Game has saved file succesfully !!!"<<endl;
                                    cout<<"If you want contunie game , please press --> ENTER <-- . Or press another thing :";
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    getline(cin,continue_game);
                                    if(continue_game !="")
                                        break;;
                                }
                                else if(temp.command=="LOAD")
                                {
                                    
                                    //temp.set_game_number(game_number+1);
                                    temp.set_board(temp.load_from_file());
                                    temp.play_yourself=false;
                                    temp.set_board_number(temp.board_number);
                                    temp.print_game();
                                    //push_object_to_vec(games,temp);
                                   // game_number=temp.game_number-1;
                                    main_obj.vector_pushing(temp);
                                    // new_board=
                                    load_controller=true;
                                    //computer_game(new_board,gamer_type,board_number);
                                    //return;
                                }
                            }
                            else
                            {
                                game_board[hor+control1[dir][0]][ver+control1[dir][1]+control[dir]].setCell(cellType::empty);
                                game_board[hor+2*control1[dir][0]][ver+2*control[dir]+2*control1[dir][1]].setCell(cellType::peg);
                                game_board[hor][ver].setCell(cellType::empty);
                                print_game();
                                cout<<endl;
                                calculate_elements();
                                number_step++;
                            }
                        }
                        else
                        {
                            calculate_elements();
                            game_board[hor+control1[dir][0]][ver+control1[dir][1]+control[dir]].setCell(cellType::empty);
                                game_board[hor+2*control1[dir][0]][ver+2*control[dir]+2*control1[dir][1]].setCell(cellType::peg);
                                game_board[hor][ver].setCell(cellType::empty);
                            print_game();
                            cout<<endl;
                            number_step++;

                        }
                        
                    }
                }
            }           
            	
			else if(dir<4&&dir>=2)
            {
                
				if(((hor+2*control1[dir][0]+2*control[dir]>=0)&&(hor+2*control1[dir][0]+2*control[dir]<size1))&&((ver+2*control1[dir][1]>=0)&&(ver+2*control1[dir][1]<size2)))
                {
                    if((game_board[hor+control[dir]+control1[dir][0]][ver+control1[dir][1]].getCell()==cellType::peg)
                    &&(game_board[hor+2*control[dir]+2*control1[dir][0]][ver+2*control1[dir][1]].getCell()==cellType::empty))
                    {
                        // controlling_command=for_command(file_name,command);
                        is_play=true;
                        if(play_yourself==true)
                        {
                            if(temp.start_take())
                            {
                                if(temp.command=="SAVE")
                                {
                                    string continue_game;
                                    set_filename(temp.get_file_name());
                                    save_file();
                                    cout<<"Game has saved file succesfully !!!"<<endl;
                                    cout<<"If you want contunie game , please press --> ENTER <-- . Or press another thing :";
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    getline(cin,continue_game);
                                    if(continue_game !="")
                                        break;;
                                }
                                else if(temp.command=="LOAD")
                                {
                                    
                                    temp.set_board(temp.load_from_file());
                                    temp.play_yourself=false;
                                    temp.set_board_number(temp.board_number);
                                    temp.print_game();
                                    //push_object_to_vec(games,temp);
                                   // game_number=temp.game_number-1;
                                    main_obj.vector_pushing(temp);
                                    // new_board=
                                    load_controller=true;
                                // computer_game(new_board,gamer_type,board_number);
                                // return ;
                                }
                            }
                            else
                            {
                                game_board[hor+control[dir]+control1[dir][0]][ver+control1[dir][1]].setCell(cellType::empty);
                                game_board[hor+2*control[dir]+2*control1[dir][0]][ver+2*control1[dir][1]].setCell(cellType::peg);
                                game_board[hor][ver].setCell( cellType::empty);
                                print_game();
                                cout<<endl;
                                number_step++;
                                calculate_elements();
                            }

                        }
                        else
                        {
                            calculate_elements();
                            game_board[hor+control[dir]+control1[dir][0]][ver+control1[dir][1]].setCell(cellType::empty);
                            game_board[hor+2*control[dir]+2*control1[dir][0]][ver+2*control1[dir][1]].setCell(cellType::peg);
                            game_board[hor][ver].setCell( cellType::empty);
                            print_game();
                            cout<<endl;
                            number_step++;
                        }

                    }
                }
                
            }
            else if(dir >=4)
            {
                if(ver+4*control[dir-4]>=0&&(ver+4*control[dir-4]<9))
                {
                    if((game_board[hor][ver+4*control[dir-4]].getCell()==cellType::empty)&&game_board[hor][ver+2*control[dir-4]].getCell()==cellType::peg)
                    {
                        // controlling_command=for_command(file_name,command);
                        is_play=true;
                        if(true==play_yourself)
                        {
                            if(temp.start_take())
                            {
                                if(temp.command=="SAVE") 
                                {
                                    string continue_game;
                                    set_filename(temp.get_file_name());
                                    save_file();
                                    cout<<"Game has saved file succesfully !!!"<<endl;
                                    cout<<"If you want contunie game , please press --> ENTER <-- . Or press another thing :";
                                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    getline(cin,continue_game);
                                    if(continue_game !="")
                                        break;;
                                }
                                else if(temp.command=="LOAD")
                                {
                                    
                                    temp.set_board(temp.load_from_file());
                                    temp.play_yourself=false;
                                    temp.set_board_number(temp.board_number);
                                    temp.print_game();
                                    //push_object_to_vec(games,temp);
                                   // game_number=temp.game_number-1;
                                    main_obj.vector_pushing(temp);
                                    // new_board=
                                    load_controller=true;
                                // computer_game(new_board,gamer_type,board_number);
                                // return;
                                }
                            }
                            else
                            {
                                calculate_elements();
                                game_board[hor][ver+4*control[dir-4]].setCell( cellType::peg);   
                                game_board[hor][ver+2*control[dir-4]].setCell( cellType::empty);   
                                game_board[hor][ver].setCell(cellType::empty);   
                                cout<<endl<<endl;
                                print_game();
                            }
                        }
                        else
                        {
                            calculate_elements();
                            game_board[hor][ver+4*control[dir-4]].setCell( cellType::peg);   
                            game_board[hor][ver+2*control[dir-4]].setCell( cellType::empty);   
                            game_board[hor][ver].setCell(cellType::empty);      
                            cout<<endl<<endl;
                            print_game();
                        }
                    }

                }
            }
            if(load_controller==true)
                break;
            if(board_number<6&&control_board(dir))
                break;
            if(board_number==6&&control_board6(dir))
                break;

		}
        if(dir>3)
        {
                control={0,0,0,0};
                control1={{0,0},{0,0},{0,0},{0,0}};

        }
	}

    if(load_controller==true)
    {
        cout<<"Game is loading..."<<endl;
        //cout<<"-------"<< games.size() <<" KONTROL NOKTASIIIII "<<game_number<<" ----------------"<<endl;
       // temp.print_game();
        //cout<<new_board.s"ize()<<" "<<new_board[0].size()<<endl;
        //game_number=temp.game_number-1;
        //cout<<game_number<<" " <<games.size()<<endl;
        main_obj.set_number_board();
        main_obj.get_board(main_obj.get_total_number_()-1).print_game();
        main_obj.get_board(main_obj.get_total_number_()-1).resize_numberOfElements();
        main_obj.get_board(main_obj.get_total_number_()-1).update_cell_();
        main_obj.get_board(main_obj.get_total_number_()-1).computer_game();
        
        //games.at(game_number+1).computer_game();

    }
    else
    {
        cout<<"YOU WON THE GAME!!!"<<endl;
        return;
    }
	
}

int PegSolitare::control_board(int dir)
 {
    for(auto itr=0;itr<game_board.size();itr++)
    {
        for(auto imr=0;imr<game_board[0].size();imr++)
        {
            if(game_board[itr][imr].getCell()==cellType::empty)
            {
                if(!(itr-2<0||imr-2<0))
                    if(game_board[itr-2][imr].getCell()==cellType::peg&&game_board[itr-1][imr].getCell()==cellType::peg)
                        return 0;
                    else if(game_board[itr][imr-2].getCell()==cellType::peg&&game_board[itr][imr-1].getCell()==cellType::peg)
                        return 0;       
                else if(!(itr+2>=game_board.size()||imr+1>=game_board[0].size()))
                    if(game_board[itr+2][imr].getCell()==cellType::peg&&game_board[itr+1][imr].getCell()==cellType::peg)
                        return 0;
                    else if(game_board[itr][imr+2].getCell()==cellType::peg&&game_board[itr][imr+1].getCell()==cellType::peg)
                        return 0;       
            }
        }
    }
    return 1;
 }


 int PegSolitare::player_game(vector<int> &control)
 {
    string in;
    cout<<endl<<"Give location and direction for play"<<endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,in);
  vector<int> new_in;
  string new_in1;
		control.push_back(in[0]-65);
		control.push_back(in[1]-49);
		new_in1.push_back(in[3]);
		if(in.length()==5)
			new_in1.push_back(in[4]);
		if(new_in1=="UR")
			control.push_back(0);
		if(new_in1=="UL")
			control.push_back(2);
		if(new_in1=="DR")
			control.push_back(3);
		if(new_in1=="DL")
			control.push_back(1);
		if(new_in1=="R")
			control.push_back(0);
		if(new_in1=="L")
			control.push_back(1);
		if(new_in1=="D")
			control.push_back(3);
		if(new_in1=="U")
			control.push_back(2);
    if(control[2]>3||control[0]>game_board.size()||control[1]>game_board[0].size())
        return 0;
    else 
        return 1;
 }

 int PegSolitare:: control_board6(int dir)
 {
    for(auto a=0;a<5;a++)
    {
        for(auto b=0;b<9;b++)
        {
            if(game_board[a][b].getCell()==cellType::empty)
            {
                if((!(a-2<0||b-2<0)))         
                    if(game_board[a-2][b-2].getCell()==cellType::peg&&game_board[a-1][b-1].getCell()==cellType::peg)
                        return 0;
                if((!(a-2<0||b+2>8)))
                    if(game_board[a-2][b+2].getCell()==cellType::peg&&game_board[a-1][b+1].getCell()==cellType::peg)
                        return 0;         
                if((!(a+2>4||b-2<0)))         
                    if(game_board[a+2][b-2].getCell()==cellType::peg&&game_board[a+1][b-1].getCell()==cellType::peg)
                        return 0;
                if((!(a+2>4||b+2>8)))         
                    if(game_board[a+2][b+2].getCell()==cellType::peg&&game_board[a+1][b+1].getCell()==cellType::peg)
                        return 0;
                if((!(b+4>8)))         
                    if(game_board[a][b+4].getCell()==cellType::peg&&game_board[a][b+2].getCell()==cellType::peg)
                        return 0;
                if((!(b-4<0)))         
                    if(game_board[a][b-4].getCell()==cellType::peg&&game_board[a][b-2].getCell()==cellType::peg)
                        return 0;
            }
        }
    }
    return 1;
 }

void PegSolitare::save_file()
{
    fstream fio(file_name,ios::out|ios::trunc);
    fio<<"Game Type:"<<endl;
    fio<<gamer_type<<endl;
    fio<<"Board Number:"<<endl;
    fio<<board_number<<endl;
    fio<<"Movement Number:"<<endl;
    fio<<numberofElements[2]<<endl;
    fio<<"GAME :"<<endl;
    
    for(auto &x:game_board)
    {
        for(auto & y: x )
        {
            if(y.getCell()==cellType::empty)
                fio<<'.';
            else if(y.getCell()==cellType::peg)
                fio<<'P';
            else if(y.getCell()==cellType::none)
                fio<<' ';
        }
        fio<<'\n';
    }
    // fio.seekg(0, ios::beg);
    fio.close();
    //exit(0);
}


board PegSolitare::load_from_file()
{
    fstream fin;
    fin.open(file_name, ios::in);
    string buff,game_type;
    int control=0;
    int flag=0,movem;
    int temp1,temp2,temp3=1;
    vector<Cell> one;
    vector<vector<Cell>>two;
    fin.seekg(0,ios::beg);
    while(!fin.eof())
    {
        getline(fin,buff);
        if(control==0&&buff=="Game Type:")
        {
            getline(fin,buff);
            game_type=buff;
            if(game_type=="COMPUTER")
                temp1=2;
            else
                temp2=1;
        }
        else if(control==0&&buff=="Board Number:")
        {
            getline(fin,buff);
            board_number=stoi(buff);
        }
        else if(control==0&&buff=="Movement Number:")
        {
            getline(fin,buff);
            movem=stoi(buff);
            set_movement(movem);
        }
        else if(control==0&&buff=="GAME :")
            control++;
        else if(control==1)
        {
            
            for(int i=0;i<buff.size();i++)
            {
                if(buff.at(i)=='P')
                    one.push_back(Cell(temp3,'A'+temp3-1,cellType:: peg));
                else if(buff.at(i)=='.')
                    one.push_back(Cell(temp3,'A'+temp3-1,cellType:: empty));
                else if(buff.at(i)==' ')
                    one.push_back(Cell(temp3,'A'+temp3-1,cellType:: none));
            }
            temp3++;
            two.push_back(one);
            one.clear();
        }
        
    }
    two.pop_back();
    fin.close();
    cout<<"BOARD HAS  BEEN LOAD FROM FILE SUCCESFULL!!"<<endl<<"Game type is : "<<game_type<<endl<<"Board number is : "<<board_number<<endl<<"movement of this borad is : "<<get_movement()<<endl;
    return two;
}

void PegSolitare::set_play_yoursef(bool temp)
{
    play_yourself=temp;
}

void PegSolitare::calculate_elements()
{
    numberofElements[0]--;
    numberofElements[1]++;
    numberofElements[2]++;
}

void PegSolitare::set_game_number(int number)
{
    game_number=number;
}
void PegSolitare::update_cell_()
{
    /*0->peg 1->empty 2-> taken from*/
    numberofElements[0]=countNumberofpeg();
    numberofElements[1]+=movement_number;
    numberofElements[2]=movement_number;
}
