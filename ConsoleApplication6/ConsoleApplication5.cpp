#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream> 
#include <vector>

using namespace std;


class A2_Error {
    string str = "A2_Error";
public:
    A2_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};

bool m_n = false;
bool m_n1 = false;
bool m_o = false;

bool err = false;


double T(double x1) throw (A2_Error, double) {
    double term;
    string name;

    ofstream file1("dat1.dat");
    if (file1.is_open()) {
        string str = "-5,-4.5,-4,-3.5,-3,-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5";
        file1 << str << endl;
        str = "0.2801,0.2093,0.6190,0.8811,1.0422,1.1463,1.2560,1.1998,1.1209,1.0039,0.8198,0.5187,0.0707,0.4054,0.7487,0.9603,1.0926,1.180,1.2418,1.2338";
        file1 << str << endl;
    }
    file1.close();

    name = "dat1.dat"; //t


    float x[30], t[30], u[30];
    string xs, ys, zs;

    string line;

    string dat[100];

    string str;
    string s[2];

    ifstream file(name);
    if (file.is_open()) {
        for (int i = 0; i < 2; i++) {
            file >> s[i];
        }
    }
    else {
        throw A2_Error("A2");   //  Wnk
    }

    if (err != true) {
        if (x1 <= 5 && x1 >= -5) {
            throw A2_Error("A2");   //  Gnk
        }
    }


    string ch;
    str = s[0];
    int j = 0;
    float p = 0;
    int w = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            x[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }

    str = s[1];
    j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            t[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }
    str = s[1];
    j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            u[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }

    int te = 0, ue;
    int bo = 0;
    int k = 0,
        k1 = x1 * 1000;
    for (int i = 0; i < (sizeof(x) / sizeof(float)); i++) {
        k = x[i] * 1000;

        if (k == k1) {
            te = t[i];
            bo = 1;
        }
    }

    int we = 0, we1 = 0;
    if (bo == 0) {
        for (int i = 0; i < ((sizeof(x) / sizeof(float)) - 1); i++) {
            if ((x[i] < x1) && (x1 < x[i + 1])) {
                we = x[i];
                we1 = x[i + 1];
                te = T(we) + (T(we1) - T(we1)) * (x1 - we) / (we1 - we);
            }
        }
    }

    file.close();

    term = te;

    return term;
}

double U(double x1) throw (A2_Error, double) {
    double term;
    string name;

    ofstream file2("dat2.dat");
    if (file2.is_open()) {
        string str = "-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10";
        file2 << str << endl;
        str = "0.7832,1.1063,1.2486,1.1587,0.9105,0.2801,0.6190,1.0422,1.2176,1.1998,1.0039,0.5187,0.4054,0.9603,1.1803,1.2338,1.0761,0.7068,0.1450,0.8533,1.1347";
        file2 << str << endl;
    }
    file2.close();


    name = "dat2.dat";  //u


    float x[20], t[30], u[30];
    string xs, ys, zs;

    string line;

    string dat[100];

    string str;
    string s[2];
    ifstream file(name);

    if (file.is_open()) {
        for (int i = 0; i < 2; i++) {
            file >> s[i];
        }
    }
    else {
        throw A2_Error("A2");
    }

    //if (err != true) {
        if (x1 <= 10 && x1 >= -10) {
            throw A2_Error("A2");
        }
    //}


    string ch;
    str = s[0];
    int j = 0;
    float p = 0;
    int w = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            x[j] = stod(ch);
            //x[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }

    str = s[1];
    j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            t[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }
    str = s[1];
    j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            u[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }

    int te = 0, ue;
    int bo = 0;
    int k = 0,
        k1 = x1 * 1000;
    for (int i = 0; i < (sizeof(x) / sizeof(float)); i++) {
        k = x[i] * 1000;

        if (k == k1) {
            te = t[i];
            //ue = u[i];
            bo = 1;
        }
    }

    int we = 0, we1 = 0;
    if (bo == 0) {
        for (int i = 0; i < ((sizeof(x) / sizeof(float)) - 1); i++) {
            if ((x[i] < x1) && (x1 < x[i + 1])) {
                we = x[i];
                we1 = x[i + 1];
                te = U(we) + (U(we1) - U(we1)) * (x1 - we) / (we1 - we);
            }
        }
    }

    file.close();

    term = te;

    return term;

}


double Y(double x) throw (double) {

    double term;
    if (100 - x * x<0) {
        m_n = true;
        return 0;
    }
    else if (x * sqrt(100 - x * x)<1) {
        m_o = true;
        return 0;
    }
    else {
        term = log(x*sqrt(100-x*x));
    }
    return term;
}

double Ysm(double x, double y) throw (double) {
    double term;
    term = Y(x)*y+0.7*Y(y);
    return term;
}

double Tsm(double x, double y) throw (double) {

    double term;
    if (4 * y * y * y * y - x * x<0) {
        m_n1 = true;
        return 0;
    }
    else if(5 * x * x * x * x - 3 * x * x + 2 * sqrt(4 * y * y * y * y - x * x)){
        m_n = true;
        return 0;
    }
    else {
        term = log2(5 * x * x * x * x - 3 * x * x + 2 * sqrt(4 * y * y * y * y - x * x)) * Ysm(y, x);
    }

    return term;
}

double Mts(double x, double y) throw (double) {

    double term;
    term = x * Tsm(x, y) - y * Tsm(x, x);
    if (m_n1 == true) {
        m_n1 = false;
        return 0;
    }
    return term;
}

double Mlt(double x, double y, double z) throw (double) {

    double term;
    term = x * Mts(x,y)+z*Mts(z,y);
    if (m_n == true) {
        m_n = false;
        return 0;
    }
    if (m_o == true) {
        m_o = false;
        return 1;
    }
    return term;
}


double GetFrom(string text) throw (double) {
    double term;
    string name;

    ofstream file3("dat3.dat");
    if (file3.is_open()) {
        string str = "aet,bet,cet,set,get,ret,het,met,net,qet,tet,wet,ywt,iet,oet,pet,det,fet,let,zet,vet";
        file3 << str << endl;
        str = "1.175,1.278,1.381,1.484,1.587,1.69,1.793,1.896,1.999,2.102,2.205,2.308,2.411,2.514,2.617,2.72,2.823,2.926,3.029,3.132,3.235";
        file3 << str << endl;
    }
    file3.close();


    name = "dat3.dat";


    double x[30];
    double te = -1;
    string xs, ys, zs;

    string line;

    string dat[100];


    ifstream file(name);
    string s[2];

    if (file.is_open()) {
        for (int i = 0; i < 2; i++) {
            file >> s[i];
        }
    }
    else {
        return 0;
    }


    string str = s[0];
    string words[21];
    string ch;
    int j = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            words[j] = ch;
            ch = ' ';
            j++;
        }
    }

    ch="";
    str = s[1];
    j = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ',') {
            ch += str[i];
        }
        else {
            x[j] = stod(ch);
            ch = ' ';
            j++;
        }
    }

    for (int i = 0; i < (sizeof(x) / sizeof(float)); i++) {
        if (text == words[i]) {
            te = x[i];
        }
    }

    if (te == -1) {
        te = 0;
    }

    file.close();

    term = te;

    return term;
}

double Stext(double x, double y, double z, string text) throw (double) {
    double term;
    if (x > 0) {
        term = GetFrom(text) + x;
    }
    else if (text == "") {
        term = GetFrom("tet") + GetFrom("set") - x;
    }
    else if (x <= 0) {
        term = GetFrom("get") + GetFrom(text);
    }
    return term;
}

double Min(double x, double y, double z, double u) throw (double) {

    double term, term1;
    term = min(x, y);
    term1 = min(z, u);
    term = min(term, term1);
    return term;

}

double Stext(double x, string text) throw (double) {
    double term;
    if (x>0) {
        term = GetFrom(text)+x;
    }
    else if (text =="") {
        term = GetFrom("tet") + GetFrom("set") - x;
    }
    else if (x<=0) {
        term = GetFrom("get") + GetFrom(text);
    }
    return term;
}

double Ktext(double x, double y, double z, string text) throw (double) {
    double term;

    if(z>0){
        term = Stext(Min(x, y, x - z, y - z), text);
    }
    else if (z <= 0) {
        term = Stext(Min(x, y, z - x, z - y), text);
    }

    return term;

}



double T1(double x) throw (double) {
    double term;
    term = atan(acos(sin(2 * x)));
    return term;
}

double U1(double x) throw (double) {
    double term;
    term = atan(asin(sin(3*x)));
    return term;
}

double Qqn1(double x, double y, double z) throw (double) {
    double term;
    term = x/U1(x)+y*T1(y)-U1(z)*T1(z);
    return term;
}

double Qnk1(double x, double y) throw (double) {
    double term;
    term = 1.15 * Qqn1(x, y,x+y) - 0.95 * Qqn1(y, x,x-y);   
    return term;
}



double Qkn(double x, double y) throw (double) {
    
    double term;
    term = x / U(x) + y * T(y);
    cout << "\nU:" << U(x) << endl << "T:" << T(x);
    return term;
}

double Qnk(double x, double y) throw (double) {
    double term;

    if (err != true) {
        term = Qkn(x, y) + x* Qkn(y,x);
    }
    else {
        term = x* Qnk1(x, y) + y * Qnk1(y, x)-0.05*Qnk1(x,y)* Qnk1(y,x);
    }

    return term;
}

double Rsv(double x, double y, double z) throw (double) {
    double term;
    if (z >x &&z>y) {
        term = z*Qnk(x,y)-x*y;
    }
    if (x > y && x > z) {
        term = x * Qnk(z, y) + y * z;
    }
    if (y > x && y > z) {
        term = y * Qnk(x, z) + x * z;
    }
    if (z == x || y == z || x==y) {
        term = z * Qnk(y,z) - Qnk(z,x);
    }
    

    return term;
}

double func(double x, double y, double z) throw (double) {
    double term;
    term = Rsv(x,y,z)+0.5* Rsv(y,z,x)* Rsv(z,x,y);
    return term;
}

double func_regr(double r, double k, double m) throw (double) {
    double term;
    term = 10*k*r*r-m*r;
    return term;
}




int main() {
    double x, y, z;
    double r, k, m, result;
    string text;
    cout << " Input x y z text ";
    cin >> x >> y >> z >> text;
    try {
        r = func(x, y, z);
        k = Ktext(x, y, z, text);
        m = Mlt(x, y, z);

        result = func_regr(r, k, m);
    }
    catch (A2_Error& e) {
        e.Message();
        err = true;

        r = func(x, y, z);
        k = Ktext(x, y, z, text);
        m = Mlt(x, y, z);

        result = func_regr(r, k, m);
        
        err = false;
    }

    cout << "\n Res = " << result << endl;
    return 0;
}
