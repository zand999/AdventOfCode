
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

bool inArray(int buff[140], int num){
    for(int i = 0 ; i < 140 && buff[i] != 0; i++){
        if(buff[i] == num){
            return true;
        }
    }
    return false;
}
struct locationInfo{
    int row;
    int col;
};

int main(){

    ifstream input;
    string stringinput;
    int sum = 0;
    
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

    struct locationInfo *galaxylocation = new locationInfo[galaxynum];
    int galaxylocationindex = 0;
    
    printArray(initspace);

    findEmptyRowsAndCol(initspace, emptyspaceRowBuff, emptyspaceColBuff);
    cout << endl;
    for(int i = 0; i < 140;i++){
        cout << emptyspaceRowBuff[i] << ",";
    }
    cout << endl;
    for(int i = 0; i < 140;i++){
        cout << emptyspaceColBuff[i] << ",";
    }
    cout << endl;

    int rownum = 140+ emptyspaceColBuff[139] ;
    int colnum = 140+ emptyspaceRowBuff[139] ;

    newspace = new char[rownum * colnum];

    

    for(int i = 0, ioffset = 0;i<140;i++,ioffset++){

        if(inArray(emptyspaceRowBuff,i)){

            for(int j = 0;j < colnum;j++){
                newspace[(rownum * ioffset) + j] = '.';
            }
            ioffset++;
            for(int j = 0;j < colnum;j++){
                newspace[(rownum * ioffset) + j] = '+';
            }
            continue;
        }

        for(int j = 0,joffset = 0;j < 140;j++,joffset++){
            newspace[(rownum * ioffset) + joffset] = initspace[i][j];
            if(initspace[i][j] == '#'){
                galaxylocation[galaxylocationindex].row = ioffset;
                galaxylocation[galaxylocationindex].col = joffset;
                galaxylocationindex++;
            }

            if(inArray(emptyspaceColBuff,j)){
                joffset++;
                newspace[(rownum * ioffset) + joffset] = '+';
            }
        }

        
        
    }
    bool twice = false;
    for(int i = 0,i2 = 0;i<rownum;i++){
        cout << i-i2 << ": ";
        if(inArray(emptyspaceRowBuff,i-i2) && twice == false){
           i2++;
           twice = true;
        }else{
            twice = false;
        }

        
        for(int j = 0;j<colnum+2;j++){
            cout << newspace[i * rownum + j];
        }
        
        cout << endl;
    }
    

    int temp;
    for(int i = 0;i<galaxynum;i++){
        cout << galaxylocation[i].row << "," << galaxylocation[i].col << ":";
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

}