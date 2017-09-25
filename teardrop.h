#ifndef TEARDROP_H
#define TEARDROP_H
#include <vector>

using namespace std;

class Teardrop{

private:
    vector<vector<int> > points;
    vector<int> mouse_point;
    vector<int> centro_arco;
    int raio;
    double angulo;
public:
    Teardrop(int x, int y, double angulo);
    vector< vector<int> > retornaPontos();
    void printaPontos();
};


#endif // TEARDROP_H
