#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream> 
#include <vector>

using namespace std;


class A2_OpenFile {
    string str = "A2_Error";
public:
    A2_OpenFile(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};
class A3_OpenFile {
    string str = "A3_Error";
public:
    A3_OpenFile(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};

class A4_OpenFile {
    string str = "A4_Error";
public:
    A4_OpenFile(string s) : str(s) { }
    void Message()
    {
        cout << "Error: " << str << endl;
    }
};


double Y(double x) throw (double) {

    double term;
    if (sqrt(100 - x * x) < 0) {
        term = 0;
    }
    if (x * sqrt(100 - x * x) < 1) {
        term = 0;
    }
    else {
        term = log(x * sqrt(100 - x * x));
    }

    return term;
}
double Yrr(double f, double r) throw (double) {

    double term;
    term = Y(f) * r + 0.5 * Y(r);
    return term;
}
double Trr(double f, double r) throw (double) {

    double term;
    if (sqrt(4 * f * f - r) < 0) {
        term = 0;
    }
    else {
        term = sqrt(4 * f * f - r) + 0.5 * Yrr(r, f);
    }
    return term;
}
double k(double f, double r) throw (double) {

    double term;
    term = f * Trr(f, r) + r * Trr(f, 2 * r);
    return term;
}

double Gtext(string text) throw (A4_OpenFile, double) {
    double term;
    string name;
    //try {

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
    double te = -1;
    string xs, ys, zs;

    string line;

    string dat[100];


    ifstream file(name);
    string s[2];
    string str = s[0];

    for (int i = 0; i < 2; i++) {
        file >> s[i];
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
            te = x[i];
        }
    }

    if (te == -1) {
        te = 0;
    }

    file.close();

    term = te;

    return term;
    /* }

    //End program
    catch (A4_OpenFile& e) {
        e.Message();
        return 0;
    }
    */
}

//CText
double f(double x, string text) throw (double) {

    double term;

    if (x > 0) {
        term = Gtext(text) + x;
    }
    if (text == "") {
        term = Gtext("set") + Gtext("get") - x;
    }
    else if (x <= 0) {
        term = Gtext("set") + Gtext(text);
    }

    return term;

}


double Max(double x, double y, double z, double u) throw (double) {

    double term, term1;
    term = max(x, y);
    term1 = max(z, u);
    term = max(term, term1);
    return term;

}
//k
double Rtext(double x, double y, double z, string text) throw (double) {

    double term;
    term = f(Max(x, y, x + z, y + z), text);
    return term;

}

double T(double x1) throw (A2_OpenFile, A3_OpenFile, double) {
    double term;
    string name;
    //try {

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
    ifstream file(name);
    string s[2];

    for (int i = 0; i < 2; i++) {
        file >> s[i];
    }

    if (x1 <= 5 && x1 >= -5) {
        throw A2_OpenFile("A2");

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
    /*
    }

    //A2
    catch (A2_OpenFile& e) {
        e.Message();
        return 0;
    }
    */

}

double U(double x1) throw (A2_OpenFile, A3_OpenFile, double) {
    double term;
    string name;
    //try {
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
    ifstream file(name);
    string s[2];

    for (int i = 0; i < 2; i++) {
        file >> s[i];
    }

    if (x1 <= 10 && x1 >= -10) {

        throw A3_OpenFile("A3");
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
    //}

    /*
    //A3
    catch (A3_OpenFile& e) {
        e.Message();
        return 0;
    }
    */

}

double Qqn(double x, double y, double z) throw (double) {
    double term;

    term = x / U(x) + y * T(y) - U(z) * T(z);

    return term;
}
double Qnk(double x, double y) throw (double) {
    double term;

    term = x * Qqn(x, y, x + y) - Qqn(y, x, x - y);

    return term;
}
double Rnk(double x, double y) throw (double) {
    double term;

    term = x * Qnk(x, y) + y * Qnk(y, x);

    return term;
}
//r
double func(double x, double y, double z) throw (double) {

    double term;
    term = Rnk(x, y) + Rnk(y, z) * Rnk(x, y);
    return term;

}

double Variant(double r, double k) throw (double) {
    double temp;

    temp = 0, 8973 * r + 0.1027 * k;

    return temp;
}



double T1(double x1) throw (double) {
    double term;
    term = atan(acos(sin(2 * x1)));
    return term;
}
double U1(double x1) throw (double) {
    double term;
    term = atan(asin(sin(3 * x1)));
    return term;
}

double Qqn1(double x, double y, double z) throw (double) {
    double term;
    term = x / U1(x) + y * T1(y) - U1(z) * T1(z);

    return term;
}
double Qnk1(double x, double y) throw (double) {
    double term;
    term = 1.1 * Qqn(x, y, x + y) - 0.9 * Qqn(y, x, x - y);

    return term;
}
double Rnk1(double x, double y) throw (double) {
    double term;

    term = x * Qnk1(x, y) + y * Qnk1(y, x) - 0.03 * Qnk1(x, y) * Qnk1(y, x);

    return term;
}
double r1(double x, double y, double z) throw (double) {

    double term;
    term = Rnk1(x, y) + Rnk1(y, z) * Rnk1(x, y);
    return term;

}

double Variant1(double r, double k) throw (double) {
    double temp;

    temp = 0.8973 * r + 0.1027 * k;

    return temp;
}


double Qqn2(double x, double y, double z) throw (double) {
    double term;
    term = x / U1(x) + y * T1(y) - 0.9 * U1(z) * T1(z);

    return term;
}
double Qnk2(double x, double y) throw (double) {
    double term;
    term = 1.3 * Qqn2(x, y, x) - 0.7 * Qqn2(y, x, x);

    return term;
}

double Variant2(double x, double y, double z) throw (double) {
    double temp;

    temp = 1.75 * x * Qnk2(x, y) + 1.25 * y * Qnk2(y, x) - 1.5 * Qnk2(x, y) * Qnk2(y, x);

    return temp;
}




int main() {
    double x, y, z, f;
    double r, k;
    string text;
    cout << " Input x y z text ";
    cin >> x >> y >> z >> text;
    try {
        r = func(x, y, z);
        k = Rtext(x, y, z, text);

        f = Variant(r, k);
    }
    catch (A2_OpenFile& e) {
        e.Message();

        r = r1(x, y, z);
        k = Rtext(x, y, z, text);

        f = Variant1(r, k);
    }
    catch (A3_OpenFile& e) {
        e.Message();

        f = Variant2(x, y, z);
    }
    catch (A4_OpenFile& e) {
        e.Message();
        return 0;
    }

    cout << "\n fun = " << f << endl;
    return 0;
}
