
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct providedbag{ 
  int red = 12; 
  int green = 13;   
  int blue = 14;
};

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
        //cout << num << " ";
    }
    //cout << "|";
    s.str(playerNums);
    for(int i = 0; i < 25; i++){
        s >> num;
        if(possiblenums[num] == 1){
            total++;
            //cout << "!";
        }
        //cout << num << " ";
    }
    
    return total;

}

int main(){

    ifstream input;
    string stringinput;
    int numwins = 0;
    int card = 0;
    int cardtotals[220];

    for(int i = 0; i < 220;i++){
        cardtotals[i] = 1;
    }

    int total = 0;

    input.open("input.txt");

    if(input.is_open()){

		
        
		
        while(!input.eof() /*&& gamenum <  10*/){
            

            getline(input,stringinput);
            if(stringinput.size() != 0){


                numwins = getWinnings(stringinput);
                for(int i = 0; i < numwins;i++){
                    
                    cardtotals[card+1+i] += cardtotals[card]; 

                }
                


            }
            card++;
        }

        
	}else{
		cout << "file did not open";
	}

    for(int i = 0; i < 220;i++){
        total += cardtotals[i];
    }

    cout << "Total: " <<  total << "\n";

	input.close();

}