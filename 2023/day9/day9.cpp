#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

void printArray(long *array){
    cout << "(";
    for(int i = 0; i < 21; i++){
        cout << array[i] << ",";
    }
    cout << ")\n";
}

long *generateDiff(long *list, int ln){
    long *intdiff = new long[ln-1];
    for(int i = 0;i < ln-1;i++){
        intdiff[i] = list[i+1] - list[i];
    }
    return intdiff;
}

long nextValue(long *list, int ln){

    long find0;

    if(ln == 1){
        return list[0];
    }
    for(int i = 0;i < ln;i++){
        find0 += list[i];
    }
    if(find0 == 0){
        return  0;
    }

    long *intdiff = generateDiff(list, ln);


    long retval = nextValue(intdiff, ln-1);

    free(intdiff);
    

    return list[ln-1]+retval;

}



int main(){

    ifstream input;
    string stringinput;

    long total = 0;;
    long temp = 0;
    long *sequence = new long[21];

    input.open("input.txt");

    if(input.is_open()){
        while(!input.eof()){
            for(int i = 0; i <  21; i++){
                input >> temp;
                //cout << temp;
                sequence[i] = temp;
            }
            printArray(sequence);
            temp = nextValue(sequence,21);
            cout << "->" << temp << "     Total: " << total << endl;
            total += temp;

            

        }

    }else{
        cout << "Failed to open file\n";
    }

    cout << endl << total << endl;
}