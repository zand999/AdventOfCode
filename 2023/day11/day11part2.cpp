
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

void printArray(char array[140][140]){
    
    for(int i = 0;i<140;i++){
        for(int j = 0;j<140;j++){
            cout << array[i][j];
        }
        cout << endl;
    }
    
}

void findEmptyRowsAndCol(char array[140][140],int rowbuff[140],int colbuff[140]){

    int index = 0;
    for(int i = 0;i<140;i++){
        
        for(int j = 0;j<140;j++){
            
            if(array[i][j] != '.'){
                goto skipRow;
            }

        }
        rowbuff[index] = i;
        index++;
        skipRow:;

    }
    rowbuff[139] = index;
    index = 0;
    for(int i = 0;i<140;i++){
        
        for(int j = 0;j<140;j++){
            if(array[j][i] != '.'){
                goto skipCol;
            }

        }
        colbuff[index] = i;
        index++;
        skipCol:;
    }
    colbuff[139] = index;
}

int distOffset(int buff[140], int num){
    
    int i = 0;
    while(i < 140 && num >= buff[i] && buff[i] != 0){
        i++;
    }
    return i;
}

struct locationInfo{
    long row;
    long col;
};

int main(){

    ifstream input;
    string stringinput;
    long sum = 0;
    
    int galaxynum = 0;
   

    input.open("input.txt");

    
    
    char initspace[140][140];
    char *newspace;

    int emptyspaceColBuff[140];
    int emptyspaceRowBuff[140];

    if(input.is_open()){
        
        for(int i = 0;i<140;i++){
            for(int j = 0;j<140;j++){
                input >> initspace[i][j];
                if(initspace[i][j] == '#'){
                    galaxynum++;

                }
                //cout << initspace[i][j];
            }
        }

    }else{
        cout << "Failed to open file\n";
    }



    

    //printArray(initspace);

    findEmptyRowsAndCol(initspace, emptyspaceRowBuff, emptyspaceColBuff);
    //print
    cout << endl;
    for(int i = 0; i < 140;i++){
        cout << emptyspaceRowBuff[i] << ",";
    }
    cout << endl;
    for(int i = 0; i < 140;i++){
        cout << emptyspaceColBuff[i] << ",";
    }
    cout << endl;

    
    struct locationInfo *galaxylocation = new locationInfo[galaxynum];
    int galaxylocationindex = 0;
    
    for(int i = 0;i<140;i++){
        for(int j = 0;j<140;j++){
            if(initspace[i][j] == '#'){
                galaxylocation[galaxylocationindex].row = (i )  + (distOffset(emptyspaceRowBuff,i) * 999999);
                galaxylocation[galaxylocationindex].col = (j ) + (distOffset(emptyspaceColBuff,j) * 999999);
                cout << galaxylocation[galaxylocationindex].row  << "," << galaxylocation[galaxylocationindex].col << endl;
                galaxylocationindex++;
            }
            //cout << initspace[i][j];
        }
    }

    int temp;
    for(int i = 0;i<galaxynum;i++){
        //cout << galaxylocation[i].row << "," << galaxylocation[i].col << ":";
        for(int j = i+1;j<galaxynum;j++){
            if(galaxylocation[j].row < galaxylocation[i].row){
                temp = galaxylocation[i].row - galaxylocation[j].row;
            }else{
                temp = galaxylocation[j].row - galaxylocation[i].row;
            }
            if(galaxylocation[j].col < galaxylocation[i].col){
                temp += galaxylocation[i].col - galaxylocation[j].col;
            }else{
                temp += galaxylocation[j].col - galaxylocation[i].col;
            }
            //temp = (galaxylocation[j].row - galaxylocation[i].row)+(galaxylocation[j].col - galaxylocation[i].col);
            cout << temp << ',';
            sum += temp;
        }
        cout << endl;
    }

    cout << endl << "Sum: " << sum << endl;
    //High: 1927505026240
    //High:  779033026240
}