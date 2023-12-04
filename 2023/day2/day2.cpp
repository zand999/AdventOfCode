
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct providedbag{ 
  int red = 12; 
  int green = 13;   
  int blue = 14;
};

int isPossible(string game){

    //cout << game << "\n";
    int colenlocation = game.find(":");
    string blocks = game.substr(colenlocation+2,game.size());
    bool isPossible = true;
    struct providedbag bag;
    int r = 0, b = 0, g = 0;  

    string chunksleft = blocks;

    
    int i = 0;
    while(i < blocks.size()){
        
        

        int lowestln[3] = {-1,-1,-1};
        int closest = -1, closestindex = 0;

        lowestln[0] = chunksleft.find(',');
        lowestln[1] = chunksleft.find(';');
        lowestln[2] = chunksleft.size();
        //cout << "array: " << lowestln[0] << " " << lowestln[1] << " " << lowestln[2]<< "\n";

        closest = lowestln[0];
        if(closest > lowestln[1] && lowestln[1] != -1|| closest == -1){
            closest = lowestln[1];
            closestindex = 1;
        }
        if(closest > lowestln[2] && lowestln[1] != -2|| closest == -1){
            closest = lowestln[2];
            closestindex = 2;
        }
        if(closest == -1){
            cout << "HELP";
        }

        string block;
        //cout << closestindex << endl;
        if(closestindex == 0 || closestindex == 1){
            block = chunksleft.substr(0,lowestln[closestindex] +2);

        }else{
            if(chunksleft.size() < 1  ) break; 
            block = chunksleft.substr(0,chunksleft.size());

        }
        cout << ">" << block << ">" << block.find("red");
        string temp = "";   

        if(block.find("red") < 18446744073709551615){
            //cout << "\""<< block.substr(0,block.find(" "))<< "\""<< endl;
            temp = block.substr(0,block.find(" "));
            
            r = stoi(temp);
            cout << ">" << r << ": ";
            if(r > bag.red ){
                return 0;
            }

        }else if(block.find("green") < 18446744073709551615){
            temp = block.substr(0,block.find(" "));
            //cout << block.substr(0,block.find(" "))<< endl;
            g = stoi(temp);
            cout << g << ": ";
            if(g > bag.green){
                return 0;
            }

        }else if(block.find("blue") < 18446744073709551615){
            temp = block.substr(0,block.find(" "));
            //cout << block.substr(0,block.find(" ")) << endl;
            b = stoi(temp);
            cout << b << ": ";
            if(b > bag.blue){
                return 0;
            }

        }
        cout << block  << "\n";


    
        
        chunksleft = chunksleft.substr(block.size(), chunksleft.size());
        
        if(lowestln[closestindex] == 0){
            break;
        }

        i += block.size();

    }
    cout << "\n";


    return 1;

}

int main(){

    ifstream input;
    string stringinput;
    int total = 0;
    

    input.open("input.txt");

    if(input.is_open()){

		
        int gamenum = 1;
		//input.ignore(256,'\n');
        while(!input.eof() /*&& gamenum <  10*/){
            

            getline(input,stringinput);
            if(stringinput.size() != 0){
                if(isPossible(stringinput) == 1){
                    total += gamenum;
                }
                
            }
            gamenum++;
        }

        
	}else{
		cout << "file did not open";
	}

    cout << "Total: " <<  total << "\n";

	input.close();

}