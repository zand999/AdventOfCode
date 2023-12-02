
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct numberdata{ 
  int num; 
  int numstrlength;   
} ;

numberdata isSpelledNum(string input){

    //not most efficent but readability is nice
    struct numberdata out;

    int strlengths[] = {4,3,3,5,4,4,3,5,5,4};

    int nums[10];
    nums[0] = input.find("zero");
    nums[1] = input.find("one");
    nums[2] = input.find("two");
    nums[3] = input.find("three");
    nums[4] = input.find("four");
    nums[5] = input.find("five");
    nums[6] = input.find("six");
    nums[7] = input.find("seven");
    nums[8] = input.find("eight");
    nums[9] = input.find("nine");

    for(int i = 1; i < 10; i++){
        if(nums[i] == 0){
            out.num = i;
            out.numstrlength = 1;
            return out;
        }
    }
    out.num = -1;
    return out;
    


}


int main(){

    ifstream input;
    string stringinput;
    int total = 0;
    int subtotal = 0;
    int num1;
    int num2;

    input.open("day1input.txt");

    if(input.is_open()){

		

		//input.ignore(256,'\n');
        while(!input.eof()){
            subtotal = 0;
            num1 = 0;
            num2 = 0;
            getline(input,stringinput);

            cout << stringinput;// << "\n";
            if(stringinput.size() > 0){
                int i = 0;
                //first num
                while(i <  stringinput.size()){

                    if(stringinput.at(i) - 48 > -1 && stringinput.at(i) -48 < 10){

                        num1 = stringinput.at(i) - 48;
                        num2 = num1;
                        
                        i++;
                        break;

                    }else{

                        struct numberdata varcheck = isSpelledNum(stringinput.substr(i,stringinput.size()));
                        if(varcheck.num != -1){
                            num1 = varcheck.num;
                            num2 = varcheck.num;
                            //i += varcheck.numstrlength ;

                            i++;
                            break;
                        }else{
                            i++;
                        }

                    }

                    

                }
                
                
                //second num
                while(i < stringinput.size()){
                    if(stringinput.at(i) - 48 > -1 && stringinput.at(i) -48 < 10){

                        num2 = stringinput.at(i) - 48;
                        i++;

                    }else{

                        struct numberdata varcheck = isSpelledNum(stringinput.substr(i,stringinput.size()));
                        
                        if(varcheck.num != -1){
                            num2 = varcheck.num;
                            //cout << ":HERE " << varcheck.num;
                            //i += varcheck.numstrlength ;
                            i++;
                        }else{
                            i++;
                        }

                    }

                }
                subtotal = 10 * num1;
                subtotal += num2;
                total += subtotal;
                cout << ": " << num1 <<": " << num2 <<": " << subtotal << "\n";
            }
        }

        
	}else{
		cout << "file did not open";
	}

    cout << "Total: " <<  total << "\n";

	input.close();

}