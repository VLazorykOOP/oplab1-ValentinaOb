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
class A3_Error {
    string str = "A3_Error";
public:
    A3_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};

class A4_Error {
    string str = "A4_Error";
public:
    A4_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};
class Restart_Error {
    string str = "Restart_Error";
public:
    Restart_Error(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};

bool rest = false;
bool err = false;


double Tfun(double u, double v, string text) throw (double) {
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


    float x[30];
    double r = -1;
    string xs, ys, zs;

    string line;

    string dat[100];

    string s[2];
    string str = s[0];

    ifstream file(name);
    if (file.is_open()) {
        for (int i = 0; i < 2; i++) {
            file >> s[i];
        }
    }
    else {
        r = 0;
    }
    
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
            r = x[i];
        }
    }

    if (r == -1) {
        r = 0;
    }

    file.close();

    term = u*u+v*v-r*(u+v)+r*r;

    return term;

}

double func(double u, double v, string text) throw (double) {

    double term=0;
    if (u <= 0.5 && u >= -0.5) {
        term = Tfun(0,v,text);
    }
    else if (u > 0.5 && u < -0.5 && u<v) {
        term = Tfun(u, v, text);
    }
    else if (u > 0.5 && u < -0.5 && u > v) {
        term = Tfun(u, 0, text) - Tfun(0, v, "set");
    }
    
    return term;

}


double T(double x1) throw (A3_Error, A4_Error, double) {
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

    /*
    ofstream file2("dat2.dat");
    if (file2.is_open()) {
        string str = "-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10";
        file2 << str << endl;
        str = "0.7832,1.1063,1.2486,1.1587,0.9105,0.2801,0.6190,1.0422,1.2176,1.1998,1.0039,0.5187,0.4054,0.9603,1.1803,1.2338,1.0761,0.7068,0.1450,0.8533,1.1347";
        file2 << str << endl;
    }
    file2.close();
    ofstream file3("dat3.dat");
    if (file3.is_open()) {
        string str = "aet,bet,cet,set,get,ret,het,met,net,qet,tet,wet,ywt,iet,oet,pet,det,fet,let,zet,vet";
        file3 << str << endl;
        str = "1.175,1.278,1.381,1.484,1.587,1.69,1.793,1.896,1.999,2.102,2.205,2.308,2.411,2.514,2.617,2.72,2.823,2.926,3.029,3.132,3.235";
        file3 << str << endl;
    }
    file3.close();
    */

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
        throw A3_Error("A3");   //  Wnk
    }
       
    if (err != true) {
        if (x1 <= 5 && x1 >= -5) {
            throw A4_Error("A4");   //  Gnk
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
                te = T(we) + (T(we1) - T(we1)) * (x1 - we) / (we1 - we);
            }
        }
    }

    file.close();

    term = te;

    return term;
}

double U(double x1) throw (A3_Error, A4_Error, double) {
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
        throw A3_Error("A3");   //  Wnk
    }

    if (err != true) {
        if (x1 <= 10 && x1 >= -10) {
            throw A4_Error("A4");   //  Gnk
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


double Wnr(double x, double y) throw (double) {
    double term;
    if (x>y) {
        term = T(x)-U(x)* U(y);
    }
    else {
        term = T(x) * T(y) - U(x);
    }

    return term;
}
double Wnk(double x, double y) throw (double) {
    double term;

    term = 10.5 * Wnr(2 * x, y) - 3.75 * Wnr(x, 2 * y);

    return term;
}

double Gnk(double x, double y, double z) throw (double) {
    double term;

    term = x * Wnk(x, y) + y * Wnk(y, x) + z * Wnk(z, x);

    return term;
}

double gold(double x, double y, double z) throw (double) {

    double term;
    term = x * Gnk(x, y, z) + Gnk(y, z, x) * Gnk(z, x, y);
    return term;

}


double Qnr(double x, double y) throw (A2_Error, A3_Error, A4_Error, Restart_Error, double) {
    double term=0;
    if (y == 0) {
        term = 1;
    }
    else if (x>y && (10*y*y*y*y-x>=0)&&(y!=0)) {
        term = x*x*sqrt(10 * y * y * y * y - x);
    }
    else if (x <= y && (3*x > y)&&(10*x*x*x*x-y>=0) && (y != 0)) {
        term = x * x * x * log(10 * x * x * x * x - y);
    }
    else if (x <= y && (3 * x <= y)&&(y * y * y * y - 2*x >= 0) && (y != 0)) {
        term = y * y * sqrt(y * y * y * y - 2*x);
    }
    else {
        if (10*y*y-x<0) {
            //z = 1.25;   //  !!!    Rnk
            throw A2_Error("A2");
        }
        else if (y * y - 2*x < 0) {
            //z = 1.5;   //  !!!    Rnk
            throw A2_Error("A2");
        }
        else if (10 * x * x - y < 0) {
            //y = 0;   //  !!!   Qnk    ?Er
            throw Restart_Error("Rest");
        }
    }

    return term;
}

double Qnk(double x, double y) throw (double) {
    double term;

    term = 10.5 * Qnr(2*x, y) - 3.75* Qnr(x, 2* y);

    return term;
}
double Rnk(double x, double y, double z) throw (double) {
    double term;
    if (rest == true) {
        y = 0;
    }
    term = x * Qnk(x, y) + y * Qnk(y, x)+z*Qnk(z,x);

    return term;
}

double func(double x, double y, double z) throw (double) {

    double term;
    term = x*Rnk(x, y,z) + Rnk(y, z,x) * Rnk(z,x, y);
    return term;

}




double Qnr1(double x, double y) throw (double) {
    double term=0;
    if (y == 0) {
        term = 1;
    }
    else if (x > y && (10 * y * y - x / 2 >= 0) && (y != 0)) {
        term = x * x * sqrt(10 * y * y - x / 2);
    }
    else if (x <= y && (3 * x > y) && (y != 0)) {
        term = x * x * x * x * y;
    }
    else if (x <= y && (3 * x <= y) && (y != 0)) {
        term = y * y *y* y * x;
    }

    return term;
}
double Qnk1(double x, double y) throw (double) {
    double term;

    term = 12 * Qnr1(2.5 * x, y) - 3 * Qnr1(x, 1.5 * y);

    return term;
}
double Rnk1(double x, double y, double z) throw (double) {
    double term;

    term = 1.15 * x * Qnk1(x, y) + 0.95 * y * Qnk1(y, x) + 0.9 * z * Qnk1(z, x);

    return term;
}

double func1(double x, double y, double z) throw (double) {

    double term;
    term = x * Rnk1(x, y, z) + Rnk1(y, z, x) * Rnk1(z, x, y);
    return term;

}



double T1(double x1) {
    double term;
    term = atan(acos(sin(2 * x1)));
        return term;
}
double U1(double x1) {
    double term;
    term = atan(asin(sin(3 * x1)));
    return term;
}

double Wnr1(double x, double y) throw (double) {
    double term;
    if (x > y) {
        term = T1(x) - 0.9*U1(x) * U1(y);
    }
    else {
        term = 0.9*T1(x) * T1(y) - U1(x);
    }

    return term;
}
double Wnk1(double x, double y) throw (double) {
    double term;

    term = 10 * Wnr1(2.5 * x, y) - 4 * Wnr1(x, 2.5 * y);

    return term;
}

double Gnk1(double x, double y, double z) throw (double) {
    double term;

    term = x * Wnk1(x, y) + y * Wnk1(y, x) + z * Wnk1(z, x);

    return term;
}
double gold1(double x, double y, double z) throw (double) {

    double term;
    term = x * Gnk1(x, y, z) + Gnk1(y, z, x) * Gnk1(z, x, y);
    return term;

}



double T2(double x1) throw (double) {
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
        return 0;
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
                te = T2(we) + (T2(we1) - T2(we1)) * (x1 - we) / (we1 - we);
            }
        }
    }

    file.close();

    term = te;

    return term;
}
double U2(double x1) throw (double) {
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
        return 0; 
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
                te = U2(we) + (U2(we1) - U2(we1)) * (x1 - we) / (we1 - we);
            }
        }
    }

    file.close();

    term = te;

    return term;

}


double Wnr2(double x, double y) throw (double) {
    double term;
    if (x > y) {
        term = 0.9*T2(x) - U2(x) * U2(y);
    }
    else {
        term = T2(x) * 2*T2(y) -0.9* U2(x);
    }

    return term;
}
double Wnk2(double x, double y) throw (double) {
    double term;

    term = 10 * Wnr2(x, y) - 3 * Wnr2(x, y);

    return term;
}

double Gnk2(double x, double y, double z) throw (double) {
    double term;

    if (x * x + y * y + z * z >= 0.001) {
        term = x* Wnk2((x / (sqrt(x * x + y * y + z * z))),(x / (sqrt(x * x + y * y + z * z)))) + 
            y* Wnk2((y / (sqrt(x * x + y * y + z * z))), (x / (sqrt(x * x + y * y + z * z))))+ 
            z * Wnk2((z / (sqrt(x * x + y * y + z * z))), (x / (sqrt(x * x + y * y + z * z))));
    }
    else {
        term = 0;
    }
    

    return term;
}
double gold2(double x, double y, double z) throw (double) {

    double term;
    term = x * Gnk2(x, y, z) + Gnk2(y, z, x) * Gnk2(z, x, y);
    return term;

}





int main() {
    double x, y, z;
    double u,v, result;
    string text;
    cout << " Input x y z text ";
    cin >> x >> y >> z >> text;
    try {
        u = func(x, y, z);
        v = gold(x, y, 2 * z);

        result = func(u, v, text);
    }
    catch (A2_Error& e) {
        cout << " \n Error: ";
        e.Message();
        err = true;
        u = func1(x, y, z);
        v = gold(x, y, 2 * z);

        result = func(u, v, text);
    }
    catch (A3_Error& e) {
        cout << " \n Error: ";
        e.Message();
        err = true;
        u = func(x, y, z);
        v = gold1(x, y, 2 * z);

        result = func(u, v, text);
    }
    catch (A4_Error& e) {
        e.Message();

        err = true;
        u = func(x, y, z);
        v = gold2(x, y, 2 * z);

        result = func(u, v, text);      
    }
    catch (Restart_Error& e) {
        cout << " \n Error: ";
        e.Message();

        err = true;
        u = func(x, y, z);
        v = gold(x, y, 2 * z);

        result = func(u, v, text);
    }

    cout << "\n Res = " << result << endl;
    return 0;
}
