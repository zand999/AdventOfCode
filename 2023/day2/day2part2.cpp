
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
    //cout << blocks << endl;
    /*for(int k = 0; k < blocks.size(); k++){

        cout << blocks.at(k);

    }*/
    //cout << blocks << "\n";

    string chunksleft = blocks;

    
    int i = 0;
    while(i < blocks.size()){
        
        

        int lowestln[3] = {-1,-1,-1};
        int closest = -1, closestindex = 0;
        int power = 0;

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
        //cout << ">" << block << ">" << block.find("red");
        //string temp = ""; 
        int temp = 0;

        if(block.find("red") < 18446744073709551615){
            //cout << "\""<< block.substr(0,block.find(" "))<< "\""<< endl;
            //temp = ;
            
            temp = stoi(block.substr(0,block.find(" ")));
            cout << ">" << r << ": ";
            if(r < temp){
                r = temp;
            }

        }else if(block.find("green") < 18446744073709551615){
            //temp = block.substr(0,block.find(" "));
            //cout << block.substr(0,block.find(" "))<< endl;
            temp = stoi(block.substr(0,block.find(" ")));
            cout << g << ": ";
            if(g < temp){
                g = temp;
            }

        }else if(block.find("blue") < 18446744073709551615){
            //temp = block.substr(0,block.find(" "));
            //cout << block.substr(0,block.find(" ")) << endl;
            temp = stoi(block.substr(0,block.find(" ")));
            cout << b << ": ";
            if(b < temp){
                b = temp;
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

    
    
    

    cout << "r:" << r << " g: "<< g << " b:" << b << "\n";

    return (r*g*b);

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
            if(stringinput.size() != 0) total += isPossible(stringinput);
            
                
            
            gamenum++;
        }

        
	}else{
		cout << "file did not open";
	}

    cout << "Total: " <<  total << "\n";

	input.close();

}