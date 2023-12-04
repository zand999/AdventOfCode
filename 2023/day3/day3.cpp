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

    if(a >= 48 && a <= 57 ){
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
            //cout << "\n";
        }



        //printgrid(grid);
        

        
	}else{
		cout << "file did not open";
	}
    
    

    for(int i = 1;i< 141;i++){
        
        for(int j=1;j<141;j++){
            
            
            string num = "";
            int offset = 0;
            if(isSymbol(grid[i][j])){
                cout << grid[i][j] << ": ";
                //top
                if(isNum(grid[i-1][j])){
                    //cout << grid[i-1][j] << " "<<isNum(grid[i-1][j]) << endl;
                    while(isNum(grid[i-1][j-offset])){
                        if(j-offset+1 < 0){
                            offset++;
                            break;
                        }
                        offset++;
                        
                    }
                    offset--;

                    //cout << grid[i-1][j-offset] << endl;
                    while(isNum(grid[i-1][j-offset])){
                        //cout << grid[i-1][j-offset];
                        num += grid[i-1][j-offset];
                        if(j-offset+1 > 141)break;
                        offset--;
                    }
                    //cout << endl;
                    if(num.size() != 0) {
                        cout <<" tt-num:" << num;
                        total += stoi(num);
                    }


                }else{
                    //topleft
                    offset = 0;
                    while(isNum(grid[i-1][j-offset-1])){
                        if(j-offset-2 < 0){
                            offset++;
                            break;
                        }
                        offset++;
                    }
                    offset--;
                    
                    while(isNum(grid[i-1][j-offset-1])){
                        num += grid[i-1][j-offset-1];
                        if(j-offset+1 > 141)break;
                        offset--;
                    }
                    //cout << " off: "<< offset;
                    
                    if(num.size() != 0) {
                        cout <<" tl-num:" << num;
                        total += stoi(num);
                    }

                    //topright
                    offset = 0;
                    num = "";
                    while(isNum(grid[i-1][j-offset+1])){
                        num += grid[i-1][j-offset+1];
                        if(j-offset+1 > 141)break;
                        offset--;
                    }
                    //cout << " off: "<< offset;
                    
                    if(num.size() != 0) {
                        cout <<" tr-num:" << num;
                        total += stoi(num);
                    }

                }
                
                num = "";
                offset = 0;

                //left
                offset = 0;
                while(isNum(grid[i][j-offset-1])){
                    if(j-offset-2 < 0){
                        offset++;
                        break;
                    }
                    offset++;
                }
                offset--;
                
                while(isNum(grid[i][j-offset-1])){
                    num += grid[i][j-offset-1];
                    if(j-offset+1 > 141)break;
                    offset--;
                }
                //cout << " off: "<< offset;
                
                if(num.size() != 0) {
                    cout <<" ll-num:" << num;
                    total += stoi(num);
                }

                //right
                offset = 0;
                num = "";
                while(isNum(grid[i][j-offset+1])){
                    num += grid[i][j-offset+1];
                    if(j-offset+1 > 141)break;
                    offset--;
                }
                //cout << " off: "<< offset;
                
                if(num.size() != 0) {
                    cout <<" rr-num:" << num;
                    total += stoi(num);
                }

                //bottom
                num = "";
                if(isNum(grid[i+1][j])){
                    //cout << grid[i-1][j] << " "<<isNum(grid[i-1][j]) << endl;
                    while(isNum(grid[i+1][j-offset])){
                        if(j-offset+1 < 0){
                            offset++;
                            break;
                        }
                        offset++;
                        
                    }
                    offset--;

                    //cout << grid[i-1][j-offset] << endl;
                    while(isNum(grid[i+1][j-offset])){
                        //cout << grid[i-1][j-offset];
                        num += grid[i+1][j-offset];
                        if(j-offset+1 > 141)break;
                        offset--;
                    }
                    //cout << endl;
                    if(num.size() != 0) {
                        cout <<" bb-num:" << num;
                        total += stoi(num);
                    }


                }else{
                    //bottomleft
                    num = "";
                    offset = 0;
                    while(isNum(grid[i+1][j-offset-1])){
                        
                        if(j-offset-2 < 0){
                            offset++;
                            break;
                        }
                        offset++;
                    }
                    offset--;
                    
                    while(isNum(grid[i+1][j-offset-1])){
                        
                        num += grid[i+1][j-offset-1];
                        if(j-offset+1 > 141)break;
                        offset--;
                    }
                    //cout << " off: "<< offset;
                    
                    if(num.size() != 0) {
                        cout << " here";
                        cout <<" bl-num:" << num;
                        total += stoi(num);
                    }

                    //bottom right
                    offset = 0;
                    num = "";
                    while(isNum(grid[i+1][j-offset+1])){
                        num += grid[i+1][j-offset+1];
                        if(j-offset+1 > 141)break;
                        offset--;
                    }
                    //cout << " off: "<< offset;
                    
                    if(num.size() != 0) {
                        cout <<" br-num:" << num;
                        total += stoi(num);
                    }

                }
                cout << endl;
            }
        }
        
    }
    


    cout << "Total: " <<  total << "\n";

	input.close();

}