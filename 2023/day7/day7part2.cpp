
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
        case 'J': return 1; break;
        case 'Q': return 12; break;
        case 'K': return 13; break;
        case 'A': return 14; break;
        default: return 99999;
    }
}

uint *convertCardsToInt(string hand){

    uint *ret = new uint(hand.size());
    cout << " (";
    for(int i = 0; i < hand.size();i++){

        ret[i] = convertCardToInt(hand.at(i));
        cout << hand.at(i) << ",";
    }
    cout << ")";
    return ret;
}

uint getHandStrength(uint *hand){

    uint cardTypes[CARDS_IN_HAND] = {0};
    uint amountOfCardTypes[CARDS_IN_HAND] = {0};
    uint addatend = 0;

    for(int i = 0; i < CARDS_IN_HAND;i++){
        if(hand[i]== 1){
            
            addatend++;

        
        }else{
            for(int j = 0; j < CARDS_IN_HAND;j++){
                if(cardTypes[j] == 0){
                    cardTypes[j] = hand[i];
                    amountOfCardTypes[j]++;
                    break;
                }else if(cardTypes[j] == hand[i]){
                    amountOfCardTypes[j]++;
                    break;
                }

            }

        }
    
        

    }
    
    sort(amountOfCardTypes,amountOfCardTypes+5,greater<int>());
    cout << " (" << amountOfCardTypes[0] << ","<< amountOfCardTypes[1]<< ","<< amountOfCardTypes[2]<< ","<< amountOfCardTypes[3]<< ","<< amountOfCardTypes[4] << ")";
   

    if(amountOfCardTypes[0]+addatend ==5){
        return 7;
    }else if(amountOfCardTypes[0]+addatend==4){
        return 6;
    }else if((amountOfCardTypes[0] == 3 && amountOfCardTypes[1] == 2 )|| amountOfCardTypes[0]+addatend == 3 && amountOfCardTypes[1]==2){
        return 5;
    }else if(amountOfCardTypes[0]+addatend == 3){
        return 4;
    }else if(amountOfCardTypes[0] == 2 && amountOfCardTypes[1]+addatend == 2 || addatend == 2){
        return 3;
    }else if(amountOfCardTypes[0] == 2 || addatend == 1){
        return 2;
    }else{
        return 1;
    }
    

}


int main(){

    ifstream input;
    string stringinput;
    stringstream s;

    string hand = "";
    //struct HandData hands[1000];
    unsigned long long hands[1000];
    unsigned long long total = 0;
    uint *handnums;
    
    uint bid;
    uint handStrength;
    unsigned long long rank;

    



   
    input.open("input.txt");

    if(input.is_open()){

		int index = 0;
        
        while(!input.eof()){

            hand = "";
            getline(input,stringinput,'\r');input.ignore(256,'\n');
            
            cout << ":" << stringinput << ":";
            s.clear();
            s.str(stringinput);
            s >> hand;
            cout << " hand: " << hand;
            handnums = convertCardsToInt(hand);
            //handStrength = getHand(handnums);
            //s >> hands[index].bid;
            bid = 0;
            s >> bid;
            

            uint handStrength = getHandStrength(handnums);
            hands[index] = 0;
            cout << " ("<< handStrength << ") ";
            hands[index] = hands[index]^ handStrength;
            hands[index] = (hands[index]  << 4) ^ handnums[0];
            cout << handnums[0] <<",";
            hands[index] = (hands[index]  << 4) ^ handnums[1];
            cout << handnums[1] <<",";
            hands[index] = (hands[index]  << 4) ^ handnums[2];
            cout << handnums[2] <<",";
            hands[index] = (hands[index]  << 4) ^ handnums[3];
            cout << handnums[3] <<",";
            hands[index] = (hands[index]  << 4) ^ handnums[4];
            cout << handnums[4] <<",";
            hands[index] = (hands[index]  << 12) ^ bid;
            cout << bid << ",";
            cout << "(" << hex << hands[index] << dec << ")";
            //cout << ":" << stringinput << " -> " << endl;
            //cout << hands[index] << endl;
            index++;
            free(handnums);
            cout << endl;
        }

        sort(hands, hands+1000);

        for(uint i = 0, startRank = 1000; i < 1000; i++,startRank--){
            
            cout << i+1 << ":"<< hex << hands[i] << ":" << (hands[i] & 0x0000000FFF) << dec << endl;
            bid = (hands[i] & 0x0000000FFF);

            cout << bid  << endl;
            total += (bid * (i+1));
        }

        cout << "Total: " << total;


    }else{
        cout << "File did not open\n";
    }



}