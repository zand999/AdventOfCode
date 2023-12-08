
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const uint CARDS_IN_HAND = 5;
const uint gamesPlayed = 1000;

struct HandData{

    unsigned long long cards;
    uint bid;

};

uint convertCardToInt(char val){
    switch(val){
        case '2': return 2; break;
        case '3': return 3; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 7; break;
        case '8': return 8; break;
        case '9': return 9; break;
        case 'T': return 10; break;
        case 'J': return 11; break;
        case 'Q': return 12; break;
        case 'K': return 13; break;
        default: return 0;
    }
}

uint *convertCardsToInt(string hand){

    uint *ret = new uint(hand.size());
    for(int i = 0; i < hand.size();i++){

        ret[i] = convertCardToInt(hand.at(i));

    }
    return ret;
}

uint getHandStrength(uint *hand){

    uint cardTypes[CARDS_IN_HAND] = {0};
    uint amountOfCardTypes[CARDS_IN_HAND] = {0};

    for(int i = 0; i < CARDS_IN_HAND;i++){
        for(int j = 0; j < CARDS_IN_HAND;j++){
            if(cardTypes[i] == 0){
                cardTypes[i] = hand[j];
                amountOfCardTypes[i]++;
                break;
            }else if(cardTypes[i] == hand[j]){
                amountOfCardTypes[i]++;
                break;
            }

        }

    }

    sort(amountOfCardTypes,amountOfCardTypes+5);
    cout << "(" << amountOfCardTypes[0] << ","<< amountOfCardTypes[1]<< ","<< amountOfCardTypes[2]<< ","<< amountOfCardTypes[3]<< ","<< amountOfCardTypes[4] << ")";

    if(amountOfCardTypes[0]==5){
        return 7;
    }else if(amountOfCardTypes[0]==4){
        return 6;
    }else if(amountOfCardTypes[0] == 3 && amountOfCardTypes[1] == 2){
        return 5;
    }else if(amountOfCardTypes[0] == 3){
        return 4;
    }else if(amountOfCardTypes[0] == 2 && amountOfCardTypes[1] == 2){
        return 3;
    }else if(amountOfCardTypes[0] == 2){
        return 2;
    }else{
        return 1;
    }
    

}


int main(){

    ifstream f;
    string stringinput;
    //stringstream s;

    string hand = "";
    //struct HandData hands[1000];
    unsigned long long hands[1000];
    unsigned long long total = 0;
    uint *handnums;
    
    uint bid;
    uint handStrength;
    uint rank;

    



   
    f.open("input.txt");

    if(f.is_open()){

		int index = 0;
        //while(!f.eof()){

            getline(f,stringinput);
            
            cout << stringinput << endl;
            /*s.str(stringinput);
            s >> hand;

            handnums = convertCardsToInt(hand);
            //handStrength = getHand(handnums);
            //s >> hands[index].bid;
            s >> hands[index];

            uint handStrength = getHandStrength(handnums);
            cout << handStrength << ",";
            hands[index] = hands[index]^ handStrength;
            cout << hands[index] << ",";
            hands[index] = (hands[index]  << 4) ^ handnums[0];
            cout << (hands[index] &  0x0000000000000FFF) << ",";
            hands[index] = (hands[index]  << 4) ^ handnums[1];
            hands[index] = (hands[index]  << 4) ^ handnums[2];
            hands[index] = (hands[index]  << 4) ^ handnums[3];
            hands[index] = (hands[index]  << 4) ^ handnums[4];
            hands[index] = (hands[index]  << 12) ^ bid;
            
            //cout << ":" << stringinput << " -> " << endl;
            //cout << hands[index] << endl;
            index++;
            free(handnums);
            cout << endl;
        }

        sort(hands, hands+1000);

        for(uint i = 0, startRank = 1000; i < 1000; i++,startRank--){
            cout << (hand[index] & 0x0000000000000FFF) << endl;
            total += ((hand[index] & 0x0000000000000FFF) * startRank);

        }

        cout << "Total: " << total;*/
        //}

    }else{
        cout << "File did not open\n";
    }



}