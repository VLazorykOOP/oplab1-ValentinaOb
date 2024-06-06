#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream> 
#include <vector>

using namespace std;
class Format_Error {
    string str = "Format_Error";
public:
    Format_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};
class H_Error {
    string str = "H_Error";
public:
    H_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};
class M_Error {
    string str = "M_Error";
public:
    M_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};

class Zero {
    string str = "Zero";
public:
    Zero(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};
class Sq {
    string str = "Sq";
public:
    Sq(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};


void one(){

    cout << "Input time (hour: min): ";

    double h, m;
    string inp;

    cin >> inp;

    try {
        if (inp[1] != ':') {
            throw Format_Error("F_E");
        }

        h = double(inp[0]);
        m = double(inp[2]);

        if (h < 0 && h>23) {
            throw H_Error("H_E");
        }
        if (m < 0 && m>60) {
            throw M_Error("M_E");
        }

        cout << "Yes!"<<endl;
    }
    catch (Format_Error& e) {
        e.Message();
    }
    catch (H_Error& e) {
        e.Message();
    }
    catch (M_Error& e) {
        e.Message();
    }
}

void two() {

    int n, m;
    double f, g, fun;

    cout << "Input n, m, f, g: ";

    cin >> n>>m >> f >> g;

    try {
        if (n==0||m==0) {
            if (n == 0) {
                throw Zero("N");
            }
            else {
                throw Zero("M");
            }            
        }
        if(f - 200 < 0 || 2 * g < 0){
            if (f - 200 < 0) {
                throw Sq("f - 200");
            }
            else {
                throw Sq("2 * g");
            }
        }
        else {
            fun = 100 / n + 130 / m + sqrt(f - 200) + sin(2 * g);
        }        

        cout << "fun: "<<fun<<endl;
    }
    catch (Zero& e) {
        e.Message();
    }
    catch (Sq& e) {
        e.Message();
    }
}

void three() {

    int n, m;
    double f, g, fun;

    cout << "Input n, m, f, g: ";

    cin >> n >> m >> f >> g;

    try {
        if (n == 0 || m == 0) {
            if (n == 0) {
                throw Zero("N");
            }
            else {
                throw Zero("M");
            }
        }
        if (f - 200 < 0 || 2 * g < 0) {
            if (f - 200 < 0) {
                throw Sq("f - 200");
            }
            else {
                throw Sq("2 * g");
            }
        }
        else {
            fun = 100 / n + 130 / m + sqrt(f - 200) + sin(2 * g);
        }

        cout << "fun: " << fun << endl;
    }
    catch (Zero& e) {
        e.Message();
        terminate();
    }
    catch (Sq& e) {
        e.Message();
        terminate();
    }
}

int main()
{
    cout << "Task: ";

    int a;
    cin >> a;

    switch (a) {
    case 1:
        one();
        break;
    case 2:
        two();
        break;
    case 3:
        three();
        break;

    default:
        break;
    }

    return 0;
}
