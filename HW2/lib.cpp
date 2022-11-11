#include "lib.h"
vector<vector<cell> > first_table()
{
    vector<vector<cell>> board=
    {
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    {cell::none,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::none},
    {cell::peg,cell::peg,cell::peg,cell::empty,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::none,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none}};
    return board;

}
vector<vector<cell> > second_table()
{
    vector<vector<cell>> board=
    {
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::empty,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none}};
    return board;

}
vector<vector<cell> > third_table()
{
    vector<vector<cell>> board=
    {
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::empty,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none}};
    return board;


}
vector<vector<cell> > fourth_table()
{
    vector<vector<cell>> board=
    {
    
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::empty,cell::peg,cell::peg,cell::peg},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    };
    return board;


}
vector<vector<cell> > fifth_table()
{
    vector<vector<cell>> board=
    {
    {cell::none,cell::none,cell::none,cell::none,cell::peg,cell::none,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    {cell::none,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::none},
    {cell::peg,cell::peg,cell::peg,cell::peg,cell::empty,cell::peg,cell::peg,cell::peg,cell::peg},
    {cell::none,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::none},
    {cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::peg,cell::peg,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::peg,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::none,cell::peg,cell::none,cell::none,cell::none,cell::none}};
    return board;


}
vector<vector<cell> > sixth_table()
{
    vector<vector<cell>> board=
    {
    {cell::none,cell::none,cell::none,cell::none,cell::empty,cell::none,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::none,cell::none},
    {cell::none,cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::none},
    {cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::peg,cell::none},
    {cell::peg,cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::peg,cell::none,cell::peg},};
    return board;
} 

void print_game(vector<vector<cell>> boardl )
{
    for (vector<cell> vect1D : boardl)
    {
        for (cell x : vect1D)
        {
            if(x==cell::none)
                cout<<"  ";
            if(x==cell::peg)
                cout<<"P ";
            if(x==cell::empty)
                cout<<". ";
        }    
        cout << endl;
    }
}

void computer_game(vector<vector<cell>> boardl,int gamer_type,int board_number)
{
	int hor,ver,dir;
    bool load_controller=false;
    board new_board;
    string gamer;
    if(gamer_type==1)
        gamer="HUMAN";
    else if(gamer_type==2)
        gamer="COMPUTER";
	vector<int> control={1,-1,1,-1};
	vector<vector<int>> control1={{-1,1},{1,-1},{-1,-1},{1,1}};
    string file_name,command;
    int size1,size2;
    bool controlling_command;
    if(board_number!=6)
    {
        size1=boardl.size();
        size2=boardl[0].size();
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
        if(gamer_type==2)
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
                hor=rand()%boardl.size();
                ver=rand()%boardl[0].size();
                dir=rand()%4;
            }
        }
        else if(player_game(boardl,input,board_number))
        {
            ver=input[0];
            hor=input[1];
            dir=input[2];
            input.clear();
        }
        else
        {
            cout<<"Invalid choosing . Please try again"<<endl;
            computer_game(boardl,gamer_type,board_number);
        }
		if(boardl[hor][ver]==cell::peg)
		{
			if(dir<2)
            {
                
            	if(((ver+2*control[dir]+2*control1[dir][1]>=0))&&(ver+2*control1[dir][1]+2*control[dir]<size2)&&((hor+2*control1[dir][0]>=0))&&(hor+2*control1[dir][0]<size1))
                {
                    if((boardl[hor+control1[dir][0]][ver+control1[dir][1]+control[dir]]==cell::peg)
                    &&(boardl[hor+2*control1[dir][0]][ver+2*control[dir]+2*control1[dir][1]]==cell::empty))
                    {
                        controlling_command=for_command(file_name,command);
                        if(controlling_command==true)
                        {
                            if(command=="SAVE")
                            {
                                string continue_game;
                                save_file(file_name,boardl,gamer,number_step,board_number);
                                cout<<"Game has saved file succesfully !!!"<<endl;
                                cout<<"If you want contunie game , please press --> ENTER <-- . Or press another thing :";
                                getline(cin,continue_game);
                                if(continue_game !="")
                                    exit(0);
                            }
                            else if(command=="LOAD")
                            {
                                new_board=load_from_file(file_name,board_number,gamer_type);
                                load_controller=true;
                                cout<<"yaaaa"<<endl;
                                //computer_game(new_board,gamer_type,board_number);
                                //return;
                            }
                        }
                        else
                        {
                            boardl[hor+control1[dir][0]][ver+control1[dir][1]+control[dir]]=cell::empty;
                            boardl[hor+2*control1[dir][0]][ver+2*control[dir]+2*control1[dir][1]]=cell::peg;
                            boardl[hor][ver]=cell::empty;
                            print_game(boardl);
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
                    if((boardl[hor+control[dir]+control1[dir][0]][ver+control1[dir][1]]==cell::peg)&&(boardl[hor+2*control[dir]+2*control1[dir][0]][ver+2*control1[dir][1]]==cell::empty))
                    {
                        controlling_command=for_command(file_name,command);
                        if(controlling_command==true)
                        {
                            if(command=="SAVE")
                            {
                                string continue_game;
                                save_file(file_name,boardl,gamer,number_step,board_number);
                                cout<<"Game has saved file succesfully !!!"<<endl;
                                cout<<"If you want contunie game , please press --> ENTER <-- . Or press another thing :";
                                getline(cin,continue_game);
                                if(continue_game !="")
                                    exit(0);   
                            }
                            else if(command=="LOAD")
                            {
                                new_board=load_from_file(file_name,board_number,gamer_type);
                                cout<<"yaaaa"<<endl;
                                load_controller=true;
                               // computer_game(new_board,gamer_type,board_number);
                               // return ;
                            }
                        }
                        else
                        {
                            boardl[hor+control[dir]+control1[dir][0]][ver+control1[dir][1]]=cell::empty;
                            boardl[hor+2*control[dir]+2*control1[dir][0]][ver+2*control1[dir][1]]=cell::peg;
                            boardl[hor][ver]=cell::empty;
                            print_game(boardl);
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
                    if((boardl[hor][ver+4*control[dir-4]]==cell::empty)&&boardl[hor][ver+2*control[dir-4]]==cell::peg)
                    {
                        controlling_command=for_command(file_name,command);
                        if(controlling_command==true)
                        {
                            if(command=="SAVE") 
                            {
                                string continue_game;
                                save_file(file_name,boardl,gamer,number_step,board_number);
                                cout<<"Game has saved file succesfully !!!"<<endl;
                                cout<<"If you want contunie game , please press --> ENTER <-- . Or press another thing :";
                                getline(cin,continue_game);
                                if(continue_game !="")
                                    exit(0);
                            }
                            else if(command=="LOAD")
                            {
                                new_board=load_from_file(file_name,board_number,gamer_type);
                                cout<<"yaaaa"<<endl;
                                load_controller=true;
                               // computer_game(new_board,gamer_type,board_number);
                               // return;
                            }
                        }
                        else
                        {
                            boardl[hor][ver+4*control[dir-4]]=cell::peg;   
                            boardl[hor][ver+2*control[dir-4]]=cell::empty;   
                            boardl[hor][ver]=cell::empty;   
                            cout<<endl<<endl;
                            print_game(boardl);
                        }
                    }

                }
            }
            if(load_controller==true)
                break;
            if(board_number<6&&control_board(boardl,dir))
                break;
            if(board_number==6&&control_board6(boardl,dir))
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
        cout<<new_board.size()<<" "<<new_board[0].size()<<endl;
        print_game(new_board);
        cout<<gamer_type<<" "<<board_number<<" "<<endl;
        computer_game(new_board,gamer_type,board_number);

    }
    else
        cout<<"YOU WON THE GAME!!!"<<endl;
	
}
int control_board(board boardl,int dir)
 {
    for(auto itr=0;itr<boardl.size();itr++)
    {
        for(auto imr=0;imr<boardl[0].size();imr++)
        {
            if(boardl[itr][imr]==cell::empty)
            {
                if(!(itr-2<0||imr-2<0))
                    if(boardl[itr-2][imr]==cell::peg&&boardl[itr-1][imr]==cell::peg)
                        return 0;
                    else if(boardl[itr][imr-2]==cell::peg&&boardl[itr][imr-1]==cell::peg)
                        return 0;       
                else if(!(itr+2>=boardl.size()||imr+1>=boardl[0].size()))
                    if(boardl[itr+2][imr]==cell::peg&&boardl[itr+1][imr]==cell::peg)
                        return 0;
                    else if(boardl[itr][imr+2]==cell::peg&&boardl[itr][imr+1]==cell::peg)
                        return 0;       
            }
        }
    }
    return 1;
 }


 int player_game(board boardl,vector<int> &control,int board_size)
 {
    string in;
    cout<<endl<<"Give location and direction for play"<<endl;
    getline(cin,in);
  vector<int> new_in;
  string new_in1;
		control.push_back(in[0]-65);
		control.push_back(in[1]-49);
		new_in1.push_back(in[3]);
		if(in.length()==5)
			new_in1.push_back(in[4]);
        cout<<"new_in1    "<<new_in1<<endl;
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
    if(control[2]>3||control[0]>boardl.size()||control[1]>boardl[0].size())
        return 0;
    else 
    {
        cout<<"hamza "<<endl;
        return 1;
    }
 }

 int control_board6(board boardl,int dir)
 {
    for(auto a=0;a<5;a++)
    {
        for(auto b=0;b<9;b++)
        {
            if(boardl[a][b]==cell::empty)
            {
                if((!(a-2<0||b-2<0)))         
                    if(boardl[a-2][b-2]==cell::peg&&boardl[a-1][b-1]==cell::peg)
                        return 0;
                if((!(a-2<0||b+2>8)))
                    if(boardl[a-2][b+2]==cell::peg&&boardl[a-1][b+1]==cell::peg)
                        return 0;         
                if((!(a+2>4||b-2<0)))         
                    if(boardl[a+2][b-2]==cell::peg&&boardl[a+1][b-1]==cell::peg)
                        return 0;
                if((!(a+2>4||b+2>8)))         
                    if(boardl[a+2][b+2]==cell::peg&&boardl[a+1][b+1]==cell::peg)
                        return 0;
                if((!(b+4>8)))         
                    if(boardl[a][b+4]==cell::peg&&boardl[a][b+2]==cell::peg)
                        return 0;
                if((!(b-4<0)))         
                    if(boardl[a][b-4]==cell::peg&&boardl[a][b-2]==cell::peg)
                        return 0;
            }
        }
    }
    return 1;
 }

void save_file(string filename,board boardl,string gametype,int movement_size,int board_number)
{
    fstream fio(filename,ios::out|ios::trunc);
    fio<<"Game Type:"<<endl;
    fio<<gametype<<endl;
    fio<<"Board Number:"<<endl;
    fio<<board_number<<endl;
    fio<<"Movement Number:"<<endl;
    fio<<movement_size<<endl;
    fio<<"GAME :"<<endl;
    
    for(auto &x:boardl)
    {
        for(auto & y: x )
        {
            if(y==cell::empty)
                fio<<'.';
            else if(y==cell::peg)
                fio<<'P';
            else if(y==cell::none)
                fio<<' ';
        }
        fio<<'\n';
    }
    // fio.seekg(0, ios::beg);
    fio.close();
    //exit(0);
}

bool for_txt(string &file)
{
    string control;
    cout<<"for_txt--> "<<file<<endl;
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
string file_name_command(string &input,string &file_name,string &command)
{
    int i=0,control=0;
    command=input.substr(0,4);
    transform(command.begin(),command.end(),command.begin(),::toupper);
    if(command=="SAVE"||command=="LOAD")
    {
        control=input.find(command);
        file_name=input.substr(5);
        if(for_txt(file_name))
            return "OK";
        else
            return "ERROR1";
        
    }
    return "ERROR";
}

bool for_command(string &file_name,string &command)
{
    string for_game;
    cout<<"Please enter command or press Enter"<<endl;
    getline(cin,for_game);
    if(for_game=="")
        return false;
    else
    {   
        string control, for_error=file_name_command(for_game,file_name,command);
        cout<<file_name<<"----"<<command<<"----"<<endl;
        if(for_error=="ERROR")
        {
            cerr<<"ERROR !! Invalid command "<<endl; 
            bool again=for_command(file_name,command);
        }
        else if(for_error=="ERROR1")
        {
            cerr<<"Invlaid file name"<<endl;
            bool again=for_command(file_name,command);
        }
        else if(for_error=="OK")
            return true;
    }
    return true;
}

board load_from_file(string &filename,int &board_number,int &game_number)
{
    fstream fin;
    fin.open(filename, ios::in);
    string buff,game_type;
    int movement_number,control=0;
    int flag=0;
    vector<cell> one;
    vector<vector<cell>>two;
    fin.seekg(0,ios::beg);
    while(!fin.eof())
    {
        getline(fin,buff);
        //cout<<buff<<"-----"<<endl;
        //cout<<buff<<endl;
        if(control==0&&buff=="Game Type:")
        {
            getline(fin,buff);
            //cout<<"denemee"<<endl;
            game_type=buff;
            if(game_type=="COMPUTER")
                game_number=2;
            else
                game_number=1;
        }
        else if(control==0&&buff=="Board Number:")
        {
            getline(fin,buff);
            board_number=stoi(buff);
        }
        else if(control==0&&buff=="Movement Number:")
        {
            getline(fin,buff);
            movement_number=stoi(buff);
        }
        else if(control==0&&buff=="GAME :")
            control++;
        else if(control==1)
        {
            for(int i=0;i<buff.size();i++)
            {
                if(buff.at(i)=='P')
                    one.push_back(cell::peg);
                else if(buff.at(i)=='.')
                    one.push_back(cell::empty);
                else if(buff.at(i)==' ')
                    one.push_back(cell::none);
            }
            two.push_back(one);
            one.clear();
        }
        
    }
    two.pop_back();
    fin.close();
    cout<<"BOARD HAS  BEEN LOAD FROM FILE SUCCESFULL!!"<<endl<<"Game type is : "<<game_type<<endl<<"Board number is : "<<board_number<<endl<<"movement of this borad is : "<<movement_number<<endl;
    return two;
}
