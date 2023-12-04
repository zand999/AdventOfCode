#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void printgrid(char grid[142][142]){

    for(int i = 0;i< 142;i++){
        for(int j=0;j<142;j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }

}

bool isSymbol(char a){

    if(a != '.' && (a < 48 || a > 57 )){
        return true;
    }else{
        return false;
    }

}

bool isNum(char a){

    if(a >= 48 || a <= 57 ){
        return true;
    }else{
        return false;
    }

}



int main(){

    ifstream input;
    string stringinput;
    int total = 0;
    
    char grid[142][142];

    for(int i = 0;i< 142;i++){
        for(int j=0;j<142;j++){
            grid[i][j] = '.';
        }
    }


    input.open("input.txt");

    if(input.is_open()){

		
        
		
        for(int i = 1;i< 141 && !input.eof() ;i++){
            getline(input,stringinput);
            for(int j=1;j<141;j++){
                //cout << stringinput.at(j-1);
                grid[i][j] = (char)stringinput.at(j-1);

            }
            cout << "\n";
        }



        //printgrid(grid);
        

        
	}else{
		cout << "file did not open";
	}

    int top[3] = {0,0,0};
    int bottom[3] = {0,0,0};

    for(int i = 1;i< 141;i++){
        
        for(int j=1;j<141;j++){
            int numdata[3] = {0,0,0};
            
            //top
            int offset = 0;
            while(isNum(grid[i+1][j+1-offset])){
                offset--;
                if(offset > -1){
                    numdata[2-offset] = 1;
                }
                
            }


            //left

            //right


            //bottom

        }
        
    }



    cout << "Total: " <<  total << "\n";

	input.close();

}