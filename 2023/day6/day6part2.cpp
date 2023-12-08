
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;


double* quadraicFormula(double a, double b,double c){

    double *ret = new double[2];

    ret[0] = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
    ret[1] = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
    cout << "("<<ret[0]<<", " << ret[1] <<")" << endl;

    return ret;

}

int main(){

    double raceLn = 44806572;
    double recordInput = 208158110501102;

    double *points;

    int total = 1;

    points = quadraicFormula(-1,raceLn,-1*(recordInput));
    int possibilities = (int)(floor(points[1]) - ceil(points[0]));
    possibilities++;
    if(floor(points[0]) == ceil(points[0]) && floor(points[1]) == ceil(points[1])){
        possibilities-=2;
        //cout << "here";
    }
    //cout << (floor(points[1]) - ceil(points[0])) << endl;
    cout << possibilities << endl;

    total = possibilities;

    free(points);


    cout << "total: " << total << endl;


}