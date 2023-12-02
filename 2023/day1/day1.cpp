
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){

    ifstream input;
    string stringinput;
    int total = 0;
    int subtotal = 0;
    int num2;

    input.open("day1input.txt");

    if(input.is_open()){

		

		//input.ignore(256,'\n');
        while(!input.eof()){
            subtotal = 0;
            getline(input,stringinput);

            cout << stringinput;// << "\n";
            if(stringinput.size() > 0){
                int i = 0;
                while(i <  stringinput.size() && (stringinput.at(i) < 48 || stringinput.at(i) > 57)){
                    i++;

                }
                subtotal = 10 * (stringinput.at(i) - 48);
                cout   << ": " ;//<< stringinput.at(i);

                total += 10 * (stringinput.at(i) - 48);

                for(;i < stringinput.size(); i++){
                    if(stringinput.at(i) > 47 && stringinput.at(i) < 58){
                        num2 = stringinput.at(i) - 48;
                    }

                }
                total += num2;
                subtotal += num2;
                cout << subtotal << "\n";
            }
        }

        
	}else{
		cout << "file did not open";
	}

    cout << "Total: " <<  total << "\n";

	input.close();

}