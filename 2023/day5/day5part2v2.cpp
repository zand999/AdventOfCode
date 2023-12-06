#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;


long getMapping(long dest, long src, long range, long val){

    long distFromSrc = val - src;

    if(val >= src && val < (src + range)){

        return dest + distFromSrc;
    }


    return -1;
}


void percentDone(long num){
    switch(num){

        case 175324466: cout << "10%\n";break;
        case 175324466 * 2: cout << "20%\n";break;
        case 175324466 * 3: cout << "30%\n";break;
        case 175324466 * 4: cout << "40%\n";break;
        case 175324466 * 5: cout << "50%\n";break;
        case 175324466 * 6: cout << "60%\n";break;
        case 175324466 * 7: cout << "70%\n";break;
        case 175324466 * 8: cout << "80%\n";break;
        case 175324466 * 9: cout << "90%\n";break;
        case 175324466 * 10: cout << "100%\n";break;

    }
}

long* importSeeds(string seednums, int &length){

    seednums.erase(0,seednums.find(':') + 2);


    long *seeds = new long[1753244662];
    string temp;
    cout << "S-Importing: " << seednums << endl;
    long start = 0;
    long range = 0;
    long total = 0;
    
    //cout << endl << "\""<< seednums<< "\"" << endl << endl;
    stringstream s(seednums);
    long inttemp;
    for(int i = 0; i < 10;i++){
        switch(i){
            case 0: cout << "00%\n";break;
            case 1: cout << "10%\n";break;
            case 2: cout << "20%\n";break;
            case 3: cout << "30%\n";break;
            case 4: cout << "40%\n";break;
            case 5: cout << "50%\n";break;
            case 6: cout << "60%\n";break;
            case 7: cout << "70%\n";break;
            case 8: cout << "80%\n";break;
            case 9: cout << "90%\n";break;
        }
        //cout << "(" << total << ",";
        s >> start;
        s >> range;
        for(long j = 0;j < range;j++){
            seeds[total + j] = start + j;
            if(j==0){
                cout << "(" << seeds[total + j-1] << "," << seeds[total + j] << ",";
            }
            if(j == range-1){
                //cout << total + j <<"),";
                cout << seeds[total + j] <<"),";

            }
        }
        total += range;
        cout << "Total: " << total << endl;
        
        
    }
    //cout << "S-Imported: ";
    //printSeeds(seeds);

    return seeds;

}



int main(){

    ifstream input;
    string stringinput;
   
    long *seeds;
    //long *valuetracker = new long[1753244662];

    //cout << valuetracker.size();
    long *temp;

    int seedln = 0;
    stringstream s;
    long lowest = LLONG_MAX;
    
    //cout << "valuetracker: ";
    //printSeeds(valuetracker);

    input.open("input.txt");

    if(input.is_open()){

		getline(input,stringinput);
        //cout << stringinput << endl;
        seeds = importSeeds(stringinput,seedln);
        
		
    //while(!input.eof() /*&& gamenum <  10*/){
        getline(input,stringinput);
        getline(input,stringinput);
        cout << "seed-to-soil map\n";
        
        long seed2soil[3][17];
        for(int i = 0; i <17;i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> seed2soil[0][i];
            s >> seed2soil[1][i];
            s >> seed2soil[2][i];
            //cout << seed2soil[0][i] << ", " << seed2soil[1][i] << "," << seed2soil[2][i] << endl;
        }

        getline(input,stringinput);
        getline(input,stringinput);
        cout << "soil-to-fert map\n";
        long soil2fertilizer[3][14];
        for(int i = 0; i <14; i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> soil2fertilizer[0][i];
            s >> soil2fertilizer[1][i];
            s >> soil2fertilizer[2][i];
            //cout << soil2fertilizer[0][i] << ", " << soil2fertilizer[1][i] << "," << soil2fertilizer[2][i] << endl;
        }

        getline(input,stringinput);
        getline(input,stringinput);
        cout << "fert-to-water map\n";
        long fertilizer2water[3][31];
        for(int i = 0; i <31; i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> fertilizer2water[0][i];
            s >> fertilizer2water[1][i];
            s >> fertilizer2water[2][i];
            //cout << fertilizer2water[0][i] << ", " << fertilizer2water[1][i] << "," << fertilizer2water[2][i] << endl;
        }

        getline(input,stringinput);
        getline(input,stringinput);
        cout << "water-to-light map\n";
        long water2light[3][18];
        for(int i = 0; i <18; i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> water2light[0][i];
            s >> water2light[1][i];
            s >> water2light[2][i];
            //cout << water2light[0][i] << ", " << water2light[1][i] << "," << water2light[2][i] << endl;
        }

        getline(input,stringinput);
        getline(input,stringinput);
        cout << "light-to-temp map\n";
        long light2temp[3][45];
        for(int i = 0; i <45 ;i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> light2temp[0][i];
            s >> light2temp[1][i];
            s >> light2temp[2][i];
            //cout << light2temp[0][i] << ", " << light2temp[1][i] << "," << light2temp[2][i] << endl;
        }

        getline(input,stringinput);
        getline(input,stringinput);
        cout << "temp-to-humidity map\n";
        long temp2humidity[3][38];
        for(int i = 0; i <38; i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> temp2humidity[0][i];
            s >> temp2humidity[1][i];
            s >> temp2humidity[2][i];
            //cout << temp2humidity[0][i] << ", " << temp2humidity[1][i] << "," << temp2humidity[2][i] << endl;
        }

        getline(input,stringinput);
        getline(input,stringinput);
        cout << "humidity-to-location map\n";
        long humitiy2location[3][9];
        for(int i = 0; i <9;i++){
            getline(input,stringinput);
            s.str(stringinput);
            s >> humitiy2location[0][i];
            s >> humitiy2location[1][i];
            s >> humitiy2location[2][i];
            //cout << humitiy2location[0][i] << ", " << humitiy2location[1][i] << "," << humitiy2location[2][i] << endl;
        }


        
        for(long i = 0; i < 1753244662;i++){
            
            long map;
            //cout << seeds[i] << endl;
            for(int j = 0; j < 17; j++){
                map = getMapping(seed2soil[0][j],seed2soil[1][j],seed2soil[2][j],seeds[i]);
                if(map != -1){
                    //cout << seed2soil[1][j]<< "->"<< seeds[i]<< "->" << seed2soil[1][j] + seed2soil[2][j]<< endl;
                    seeds[i] = map;
                    break;
                }
            }
            
            for(int j = 0; j < 14; j++){
                map = getMapping(soil2fertilizer[0][j],soil2fertilizer[1][j],soil2fertilizer[2][j],seeds[i]);
                if(map != -1){
                    //cout << soil2fertilizer[1][j]<< "->"<< seeds[i]<< "->" << soil2fertilizer[1][j] + soil2fertilizer[2][j] << endl;
                    seeds[i] = map;
                    break;
                }
            }
            
            for(int j = 0; j < 31; j++){
                map = getMapping(fertilizer2water[0][j],fertilizer2water[1][j],fertilizer2water[2][j],seeds[i]);
                if(map != -1){
                    //cout << fertilizer2water[1][j]<< "->"<< seeds[i]<< "->" << fertilizer2water[1][j] + fertilizer2water[2][j] << endl;
                    seeds[i] = map;
                    break;
                }
            }
            //cout << seeds[i] << endl;
            for(int j = 0; j < 18; j++){
                map = getMapping(water2light[0][j],water2light[1][j],water2light[2][j],seeds[i]);
                if(map != -1){
                    //cout << water2light[1][j]<< "->"<< seeds[i]<< "->" << water2light[1][j] + water2light[2][j] << endl;
                    seeds[i] = map;
                    break;
                }
            }
            //cout << seeds[i] << endl;
            for(int j = 0; j < 45; j++){
                map = getMapping(light2temp[0][j],light2temp[1][j],light2temp[2][j],seeds[i]);
                if(map != -1){
                    //cout << light2temp[1][j]<< "->"<< seeds[i] << "->" << light2temp[1][j] + light2temp[2][j]<< endl;
                    seeds[i] = map;
                    break;
                }
            }
            //cout << seeds[i] << endl;
            for(int j = 0; j < 38; j++){
                map = getMapping(temp2humidity[0][j],temp2humidity[1][j],temp2humidity[2][j],seeds[i]);
                if(map != -1){
                    
                    seeds[i] = map;
                    //cout << temp2humidity[1][j] << "->" << seeds[i]<< "->" << temp2humidity[1][j] + temp2humidity[2][j] << endl;
                    break;
                }
            }
            for(int j = 0; j < 9; j++){
                map = getMapping(humitiy2location[0][j],humitiy2location[1][j],humitiy2location[2][j],seeds[i]);
                if(map != -1){
                    //cout << humitiy2location[1][j]<< "->"<< seeds[i]<< "->" << humitiy2location[1][j] + humitiy2location[2][j] << endl;
                    seeds[i] = map;
                    
                    break;
                }
            }
            
            if(seeds[i] < lowest){
                        
                lowest = seeds[i];
                cout << "Found Lower: " << lowest << endl;
            }



            percentDone(i);

        }

            
            
            

        
	}else{
		cout << "file did not open";
	}
     
     cout << "Lowest: " << lowest << endl;

    //printSeeds(seeds);

	input.close();

}