
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


void doubleIt(int &var){
    if(var == 0){
        var  = 1;
    }else{
        var *= 2;
    }
}

int getWinnings(string game){

    //cout << game << "\n";
    int total = 0;
    int possiblenums[100] = {0};
    int num;



    string cardnum = game.substr(0,game.find(':') + 1);
    game.erase(0,game.find(':') + 1);
    string winningNums = game.substr(0, game.find('|'));
    //cout << winningNums << endl;
    game.erase(0, game.find('|') + 1);
    string playerNums = game;

    stringstream s(winningNums);

    for(int i = 0; i < 10; i++){
        s >> num;
        possiblenums[num] = 1;
        cout << num << " ";
    }
    cout << "|";
    s.str(playerNums);
    for(int i = 0; i < 25; i++){
        s >> num;
        if(possiblenums[num] == 1){
            doubleIt(total);
            cout << "!";
        }
        cout << num << " ";
    }
    
    cout << endl;




    //cout << cardnum << "<>" << winningNums << endl;
    cout << cardnum << winningNums << "|" << playerNums <<  endl;
    cout << "T:" <<  total << endl;



    cout << endl;
    return total;

}

int main(){

    ifstream input;
    string stringinput;
    int total = 0;
    int card = 1;
    

    input.open("input.txt");

    if(input.is_open()){

		
        
		
        while(!input.eof() /*&& gamenum <  10*/){
            

            getline(input,stringinput);
            if(stringinput.size() != 0){
                total += getWinnings(stringinput);
                
            }
            card++;
        }

        
	}else{
		cout << "file did not open";
	}

    cout << "Total: " <<  total << "\n";

	input.close();

}