#include "teardrop.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#define PI 3.14159265

using namespace std;

Teardrop::Teardrop(int x, int y, double angulo){

    vector<int> aux;
    int aux_x;
    int aux_y;

    mouse_point.push_back(x);
    mouse_point.push_back(y);

    centro_arco.push_back(100*cos(angulo * PI / 180.0 )+x);
    centro_arco.push_back(100*sin(angulo * PI / 180.0 )+y);


    aux.push_back(64);
    points.push_back(aux);
    points.push_back(mouse_point);
    //points.push_back(centro_arco);
    aux.clear();

    for(int i = 0; i <= 183; i+=3){
        aux_x = 30*cos((i-90+angulo)*PI / 180.0)+centro_arco.at(0);
        aux_y = 30*sin((i-90+angulo)*PI / 180.0)+centro_arco.at(1);
        aux.push_back(aux_x);
        aux.push_back(aux_y);
        points.push_back(aux);
        aux.clear();
    }
    points.push_back(mouse_point);



}

vector< vector<int> > Teardrop::retornaPontos(){
    return points;
}

void Teardrop::printaPontos(){
    for(int i = 0; i < points.size(); i++){
        if(points.at(i).size() == 2){
            cout << "x: " << points.at(i).at(0) << "  y: " << points.at(i).at(1) << endl;
        }else
            cout << points.at(i).at(0) << endl;
    }
}


