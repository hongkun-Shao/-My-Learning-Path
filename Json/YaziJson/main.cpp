#include <iostream>
#include "json.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace shk::json;

int main (){

    ifstream fin("./main.json");
    stringstream ss;
    ss << fin.rdbuf();
    const string & str = ss.str();
    Json v;
    v.parse(str);

    cout << v.str() << endl;
    
    return 0;
}

