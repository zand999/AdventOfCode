#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long int findlcm(long long int a, long long int b) { 
    return (a / gcd(a, b)) * b; 
} 

struct direction{

    string location;
    string l;
    string r;

};


int findDirection(string location,direction *directions){
    //cout << location<< ",";
    
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
    string *nodes;

    int numberofstartnodes = 0;

   
    input.open("input.txt");

    if(input.is_open()){
        /*s.clear();
        s.str(stringinput);
        s >> hand;*/
        int index = 0;

        getline(input,turns,'\r');input.ignore(256,'\n');
        //cout << ">" << stringinput << "<";
        getline(input,stringinput,'\r');input.ignore(256,'\n');
        //cout << ">" << stringinput << "<";

        while(!input.eof()){
            getline(input,stringinput,'\r');input.ignore(256,'\n');
            //cout << ">" << stringinput << "<";
            
            directions[index].location = stringinput.substr(0,3);
            if(directions[index].location.at(2)== 'A') numberofstartnodes++;
            directions[index].l = stringinput.substr(7,3);
            directions[index].r = stringinput.substr(12,3);
            //cout << "(" << directions[index].location << "," << directions[index].l << "," << directions[index].r << ")";
            
            index++;
            
            //cout << endl;

        }



        //cout << "HERE---";
        
        

    }else{
        //cout << "Error opening file\n";

    }

    nodes = new string[numberofstartnodes];
    int *nodesdist = new int[numberofstartnodes];

    for(int i = 0,j=0;i<762;i++){
        if(directions[i].location.at(2) == 'A'){
            
            nodes[j] = directions[i].location;
            //cout << directions[j].location << ",";
            j++;
        }
    }

    cout << "\n";
    string retfromdir;
    location = "AAA";
    bool notcomplete = true;
    //cout << numberofstartnodes;
    numberofstartnodes = 6;

    for(int j = 0;j < numberofstartnodes;j++){
        turncount = 0;
        for(int i = 0; nodes[j].at(2) != 'Z';i++){
            notcomplete = false;
            if(i==turns.size()){
                i=0;
            }
            
            if(turns.at(i) == 'L'){
                //cout << findDirection(location,directions)<< ",";
                retfromdir = directions[findDirection(nodes[j],directions)].l;
                nodes[j] = retfromdir;
                //cout << retfromdir << ",";
            }else{
                
                retfromdir = directions[findDirection(nodes[j],directions)].r;
                nodes[j] = retfromdir;
                //cout <<retfromdir << ",";
            }
            turncount++;
            //cout << ")\n";
            //location = "ZZZ";

        }
        nodesdist[j] = turncount;

    }

    cout << "findLCM of:";

    long long int lcm;

    for(int i = 0; i < numberofstartnodes; i++){
        
        cout << nodesdist[i] << ",";
    }
    lcm = findlcm(nodesdist[0],nodesdist[1]);
    for(int i = 0; i < numberofstartnodes-2; i++){
        lcm = findlcm(lcm ,nodesdist[i+2]);
        
    }

    
    cout << "\nTurns: " << lcm << endl;

}