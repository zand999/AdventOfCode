#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


long getMapping(long dest, long src, long range, long val){

    long distFromSrc = val - src;

    if(val >= src && val < (src + range) && val != 0){

        return dest + distFromSrc;
    }


    return -1;
}

void printSeeds(long *seeds){

    cout << "Printing Seeds: ";

    for(int i = 0; i < 20; i++){
        cout << *(seeds+i) << " ";
    }
    cout << endl;
}


long* importSeeds(string seednums){


    long *seeds = new long[20];
    string temp;
    cout << "S-Importing: " << seednums << endl;

    seednums.erase(0,seednums.find(':') + 2);
    //cout << endl << "\""<< seednums<< "\"" << endl << endl;
    stringstream s(seednums);
    long inttemp;
    for(int i = 0; i < 20;i++){
        s >> seeds[i];
    }
    cout << "S-Imported: ";
    printSeeds(seeds);

    return seeds;

}

void resetArray(long *array){

    for(int i = 0; i < 20;i++){
                    
        array[i] = -1;
        
    }
}


int main(){

    ifstream input;
    string stringinput;
   
    long *seeds;
    long *valuetracker = new long[20];
    long *temp;
    
    resetArray(valuetracker);
    cout << "valuetracker: ";
    printSeeds(valuetracker);

    input.open("input.txt");

    if(input.is_open()){

		getline(input,stringinput);
        cout << stringinput << endl;
        seeds = importSeeds(stringinput);
        
		
        while(!input.eof() /*&& gamenum <  10*/){
            
            getline(input,stringinput);
            if(stringinput.size() < 2){
                cout << "blank" << endl << endl;
                for(int i = 0; i < 20;i++){
                    if(valuetracker[i] == -1){
                        valuetracker[i] = seeds[i];
                    }
                }
                printSeeds(seeds);
                temp = seeds;
                seeds = valuetracker;
                valuetracker = temp;
                resetArray(valuetracker);
                
                getline(input,stringinput);
                cout << stringinput << endl;

            }else{
                long calculation;
                stringstream s(stringinput);
                //cout << "Input: " << stringinput << " Vals:" << endl;
                long dest,src,range;
                s >> dest;
                s >> src;
                s >> range;
                cout << "d: " << dest << " s: " << src << " r: " << range << "      Nums: ";
                for(int i = 0; i < 20;i++){

                    if(valuetracker[i] == -1){
                        long mapval = getMapping(dest,src,range,seeds[i]);
                        if(mapval > -1){
                            valuetracker[i] = mapval;
                            cout << "(" << seeds[i] << "," << mapval << "), ";
                        }
                         
                
                    }
                    
                }
                cout << endl;
                
            }
            
            

            /*if(stringinput.size() != 0){
                total += getWinnings(stringinput);
                
            }*/


        }

        
	}else{
		cout << "file did not open";
	}

    long lowest = seeds[0];
    for(int i = 1 ; i < 20;i++){
        if(lowest > seeds[i]) lowest = seeds[i];

    }
     
     cout << "Lowest: " << lowest << endl;

    //printSeeds(seeds);

	input.close();

}