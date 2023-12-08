#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;



int main(){

    ifstream f;
    string stringinput;
    

    



   
    f.open("input.txt");

    if(f.is_open()){

		int index = 0;
        

            getline(f,stringinput);
            
            cout << stringinput << "\n";
        

    }else{
        cout << "File did not open\n";
    }



}