
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;


double* quadraicFormula(double a, double b,double c){

    //-b ± squr(b^2-4ac)
    //-------------
    //2a


    double *ret = new double[2];

    ret[0] = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
    ret[1] = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
    cout << "("<<ret[0]<<", " << ret[1] <<")" << endl;

    return ret;

    
}


int main(){

    //int test[3] = {7,15,10}; 
    double raceLn [4] = {44,80,65,72};
    //double raceLn[4] = {7,15,30,72};

    double recordInput[4] = {208,1581,1050,1102};
    //double recordInput[4] = {9,40,200,1102};

    double *points;

    int total = 1;

    for(int i = 0; i < 4; i++){

        points = quadraicFormula(-1,raceLn[i],-1*(recordInput[i]));
        int possibilities = (int)(floor(points[1]) - ceil(points[0]));
        possibilities++;
        if(floor(points[0]) == ceil(points[0]) && floor(points[1]) == ceil(points[1])){
            possibilities-=2;
            //cout << "here";
        }
        //cout << (floor(points[1]) - ceil(points[0])) << endl;
        cout << possibilities << endl;

        total *= possibilities;

        free(points);

    }

    cout << "total: " << total << endl;




}