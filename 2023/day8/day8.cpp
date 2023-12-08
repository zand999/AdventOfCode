#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;


struct direction{

    string location;
    string l;
    string r;

};


int findDirection(string location,direction *directions){
    cout << location<< ",";
    
    for(int i = 0; i<762;i++){
         //cout << "," << directions[i].location;
        if(location == directions[i].location){
            //cout << ",ii:" << i << ",";
            return i;
        }
    }
    cout << "DID NOT FIND;";
    return -1;

}


int main(){

    ifstream input;
    string stringinput;
    string turns;
    string location;
    //stringstream s;
    //regex e("[A-Z]{3}");
    
    int turncount = 0;
    

    struct direction *directions = new direction[762];



   
    input.open("input.txt");

    if(input.is_open()){
        /*s.clear();
        s.str(stringinput);
        s >> hand;*/
        int index = 0;

        getline(input,turns,'\r');input.ignore(256,'\n');
        cout << ">" << stringinput << "<";
        getline(input,stringinput,'\r');input.ignore(256,'\n');
        cout << ">" << stringinput << "<";

        while(!input.eof()){
            getline(input,stringinput,'\r');input.ignore(256,'\n');
            cout << ">" << stringinput << "<";
            
            directions[index].location = stringinput.substr(0,3);
            directions[index].l = stringinput.substr(7,3);
            directions[index].r = stringinput.substr(12,3);
            cout << "(" << directions[index].location << "," << directions[index].l << "," << directions[index].r << ")";
            
            index++;
            
            cout << endl;

        }

        cout << "HERE---";
        
        

    }else{
        cout << "Error opening file\n";

    }

    cout << "here";
    string retfromdir;
    location = "AAA";
    for(int i = 0; location != "ZZZ" ;i++){
        
        if(i==turns.size()){
            i=0;
        }
        cout << "(" << turns.at(i) << "," ;
        if(turns.at(i) == 'L'){
            cout << findDirection(location,directions)<< ",";
            retfromdir = directions[findDirection(location,directions)].l;
            location = retfromdir;
            cout << retfromdir << ",";
        }else{
            
            retfromdir = directions[findDirection(location,directions)].r;
            location = retfromdir;
            cout <<retfromdir << ",";
        }
        turncount++;
        cout << ")\n";
        //location = "ZZZ";

    }
    
    cout << "\nTurns: " << turncount << endl;

}