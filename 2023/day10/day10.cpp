#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;




struct locationInfo{
    int line;
    int col;
    char pipe;
    char entryPoint;
};





struct locationInfo move(struct locationInfo location){

    if(location.entryPoint == 'B'){
        switch(location.pipe){
            case '|':
                location.line--;
                location.entryPoint = 'B';
                break;
                break;
            case '7':
                location.col--;
                location.entryPoint = 'R';
                break;
            case 'F':
                location.col++;
                location.entryPoint = 'L';
                break;
        }
    }else if(location.entryPoint == 'T'){
        switch(location.pipe){
            case '|':
                location.line++;
                location.entryPoint = 'T';
                break;
            case 'L':
                location.col++;
                location.entryPoint = 'L';
                break;
            case 'J':
                location.col--;
                location.entryPoint = 'R';
                break;
        }
    }else if(location.entryPoint == 'R'){
        switch(location.pipe){
            case '-':
               location.col--;
                location.entryPoint = 'R';
                break;
            case 'L':
                location.line--;
                location.entryPoint = 'B';
                break;
            case 'F':
                location.line++;
                location.entryPoint = 'T';
                break;
        }
        
    }else if(location.entryPoint == 'L'){
        switch(location.pipe){
            case '-':
                location.col++;
                location.entryPoint = 'L';
                break;
            case 'J':
                location.line--;
                location.entryPoint = 'B';
                break;
            case '7':
                location.line++;
                location.entryPoint = 'T';
                break;
        }
        
    }

    return location;

}


int main(){

    ifstream input;
    string stringinput;
    int startline,startycol;
    int distFromStart = 1;

    char pipes[140][140];

    input.open("input.txt");

    struct locationInfo location;
    

    if(input.is_open()){
        
        for(int i = 0; i < 140;i++){
            for(int j = 0;j < 140;j++){
                input >> pipes[i][j];
                if(pipes[i][j] == 'S'){
                    location.line = i;
                    location.col = j; 
                    
    
    

                }
            }
        }

        cout << "Starting Position: (" << location.line << "," << location.col <<")\n";

    }else{
        cout << "Failed to open file\n";
    }
    location.line--;
    location.pipe = 'F';
    location.entryPoint = 'B';
    
    
    while(location.pipe != 'S' ){
        cout << location.line << "," << location.col << "," << location.pipe << "," << location.entryPoint << "->";
        location = move(location);
        location.pipe = pipes[location.line][location.col];
        cout << location.line << "," << location.col << "," << location.pipe << "," << location.entryPoint << endl;
        distFromStart++;
    }


    cout << endl << "Dist: "<< distFromStart / 2 << endl;
}