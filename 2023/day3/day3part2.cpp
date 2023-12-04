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

    if(a == '*'){
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
                int subtotal = 0,numfound = 0;
                bool dontadd = false;
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
                        
                        switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;

                        
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
                        switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
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
                        switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
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
                    
                    switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
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
                    
                    switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
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
                        
                        
                        switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
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
                        
                        cout <<" bl-num:" << num;
                        
                        
                        switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
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
                        
                        
                        switch (numfound){
                        case 0:
                            subtotal = stoi(num);
                            break;
                        case 1:
                            subtotal *= stoi(num);
                            break;
                        
                        default:
                            dontadd = true;
                            break;
                        }
                        numfound++;
                    }

                    

                }

                cout << " numfound: "<< numfound;
                if(!dontadd && numfound == 2) {
                    total += subtotal;
                    cout << " ADDING";

                }
                dontadd = false;
                subtotal = 0;
                
                cout << endl;
                numfound = 0;
            }
        }
        
    }
    


    cout << "Total: " <<  total << "\n";

	input.close();

}