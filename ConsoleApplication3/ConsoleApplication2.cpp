#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream> 
#include <vector>

using namespace std;


class ErrorDevideByZero {
    string str = "DevideByZero";
public:
    ErrorDevideByZero(string s) : str(s) { }
    void Message()
    {
        cout << "DevideByZero " << str << endl;
    }
};
class ErrorOpenFile {
    string str = "ErrorOpenFile";
public:
    ErrorOpenFile(string s) : str(s) { }
    void Message()
    {
        cout << "ErrorOpenFile " << str << endl;
    }
};
class ErrorSqrt {
    string str = "ErrorSqrt";
public:
    ErrorSqrt(string s) : str(s) { }
    void Message()
    {
        cout << "ErrorSqrt " << str << endl;
    }
};

class ErrorA2 {
    string str = "ErrorA2";
public:
    ErrorA2(string s) : str(s) { }
    void Message()
    {
        cout << "ErrorA2 " << str << endl;
    }
};
class ErrorA3 {
    string str = "ErrorA3";
public:
    ErrorA3(string s) : str(s) { }
    void Message()
    {
        cout << "ErrorA3 " << str << endl;
    }
};
class ErrorA4 {
    string str = "ErrorA3";
public:
    ErrorA4(string s) : str(s) { }
    void Message()
    {
        cout << "ErrorA3 " << str << endl;
    }
};


double Gold(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    //try {
        if (x > y && y != 0) {
            term = x / y;
        }
        if (y > x && x != 0) {
            term = y / x;
        }
    /* }

    catch (ErrorDevideByZero& e) {      ///  !!!
        e.Message();
        return 0;
        //term=fun2(x, y, z)
    }
    */

    return term;
}
double Glr(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    //try {
        if (x < 1 || (x * -1) < 1) {
            term = x;
        }
        if ((x >= 1 || (x * -1) >= 1) && (y < 1 || (y * -1) < 1)) {
            term = y;
        }
        if ((x >= 1 || (x * -1) >= 1) && (y >= 1 || (y * -1) >= 1) && (sqrt(x * x + y * y - 4) > 0.1)) {
            term = y / sqrt(x * x + y * y - 4);
        }
    /* }
    catch (ErrorSqrt& e) {      ///  !!!
        e.Message();
        return 0;
    }
    /*
        catch (ErrorDevideByZero){      ///  !!!
            term=fun2(x, y, z)
        }
    */

    return term;
}

double T(double x1) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    string name;
    //try {

        ofstream file1("dat_X_1_1.dat");
        if (file1.is_open()) {
            string str = "-1,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1";
            file1 << str << endl;
            str = "-4.935,-3.013,-2.316,-1.819,-1.425,-1.097,-0.816,-0.571,-0.357,-0.167,0,0.147,0.276,0.386,0.477,0.548,0.597,0.617,0.597,0.505,0";
            file1 << str << endl;
            str = "1.935,0.464,1.327,1.976,2.502,2.951,3.344,3.695,4.013,4.303,4.571,4.618,4.645,4.652,4.636,4.596,4.524,4.412,4.240,3.956,0";
            file1 << str << endl;
        }
        file1.close();
        ofstream file2("dat_X_00_1.dat");
        if (file2.is_open()) {
            string str = "0,-0.05,-0.1,-0.15,-0.2,-0.25,-0.3,-0.35,-0.4,-0.45,-0.5,-0.55,-0.6,-0.65,-0.7,-0.75,-0.8,-0.85,-0.9,-0.95,-1";
            file2 << str << endl;
            str = "-4.935,-4.435,-3.936,-3.440,-2.948,-2.461,-1.98,-1.506,-1.041,-0.585,-0.141,0.292,0.712,1.117,1.507,1.882,2.239,2.578,2.898,3.199,3.48";
            file2 << str << endl;
            str = "1.935,1.835,1.735,1.636,1.537,1.44,1.344,1.249,1.156,1.065,0.976,0.889,0.806,0.724,0.646,0.572,0.5,0.432,0.368,0.308,0.252";
            file2 << str << endl;
        }
        file2.close();
        ofstream file3("dat_X1_00.dat");
        if (file3.is_open()) {
            string str = "0,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,1";
            file3 << str << endl;
            str = "-4.935,-2.663,-1.618,-0.773,-0.034,0.635,1.253,1.829,2.369,2.877,3.356,3.806,4.228,4.622,4.987,5.32,5.618,5.876,6.08,6.199,5.89";
            file3 << str << endl;
            str = "1.935,1.885,1.834,1.784,1.732,1.679,1.625,1.57,1.512,1.452,1.388,1.322,1.251,1.175,1.093,1.003,0.905,0.796,0.675,0.536,0.377";
            file3 << str << endl;
        }
        file3.close();


        if (x1 <= 1 && (x1 * -1) <= 1) {
            name = "dat_X_1_1.dat";
        }
        if (x1 < -1) {
            x1 = 1 / x1;
            name = "dat_X_00_1.dat";

        }
        if (x1 > 1) {
            x1 = 1 / x1;
            name = "dat_X_1_00.dat";
        }
        float x[30], t[30], u[30];
        string xs, ys, zs;

        string line;

        string dat[100];

        string str;
        ifstream file(name);
        string s[3];

        for (int i = 0; i < 3; i++) {
            file >> s[i];
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
        str = s[2];
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
    /*}

    catch (ErrorOpenFile& e) {
        e.Message();
        return 0;
    }
    */

}

double U(double x1) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    string name;

    double te, ue;
    if (x1 <= 1 && (x1 * -1) <= 1) {
        name = "dat_X_1_1.txt";
    }
    if (x1 < -1) {
        x1 = 1 / x1;
        name = "dat_X_00_1.txt";

    }
    if (x1 > 1) {
        x1 = 1 / x1;
        name = "dat_X_1_00.txt";
    }
    float x[30], t[30], u[30];
    string xs, ys, zs;

    string line;

    string dat[100];

    string str;
    ifstream file(name);
    string s[3];

    for (int i = 0; i < 3; i++) {
        file >> s[i];
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
    str = s[2];
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

    int ue1 = 0;
    int bo = 0;
    int k = 0,
        k1 = x1 * 1000;
    for (int i = 0; i < (sizeof(x) / sizeof(float)); i++) {
        k = x[i] * 1000;

        if (k == k1) {
            //te = t[i];
            ue1 = u[i];
            bo = 1;
        }
    }

    int we = 0, we1 = 0;
    if (bo == 0) {
        for (int i = 0; i < ((sizeof(x) / sizeof(float)) - 1); i++) {
            if ((x[i] < x1) && (x1 < x[i + 1])) {
                we = x[i];
                we1 = x[i + 1];
                //te = T(we) + (T(we1) - T(we1)) * (x1 - we) / (we1 - we);
                ue1 = U(we) + (U(we1) - U(we1)) * (x1 - we) / (we1 - we);
            }
        }
    }

    file.close();

    term = ue1;

    return term;
}

double Srz(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x > y) {
        term = T(x) + U(z) - T(y);
    }
    else {
        term = T(y) + U(y) - U(z);
    }
    return term;
}

double Srs1(double x, double y, double z) throw (ErrorA2, ErrorA3, double) {
    double term;
    //try {
        if (z > y && (z * z + x * y) > 0) {
            term = Srz(x, y, z) + y * log(z * z + x * y);
        }
        else if (z <= y && (x * x + z * y) > 0) {
            term = y + Srz(z, x, y) * sqrt(x * x + z * y);
        }
        else if ((z * z + x * y) <= 0) {
            throw ErrorA2("A2");
        }
        else if ((x * x + z * y) <= 0) {
            throw ErrorA4("A4");
        }
    /* }
    catch (ErrorA2& e) {
        e.Message();
        return 0;
    }
    catch (ErrorA4& e) {    //Krn - 4
        e.Message();
        return 0;
    }
    */
    return term;
}

double Srs(double x, double y, double z) throw (ErrorA2, ErrorA3, double) {
    double term;
    try {
        if (z > y && (z * z + x * y) > 0) {
            term = Srz(x, y, z) + y * sqrt(z * z + x * y);
        }
        else if (z <= y && (x * x + z * y) > 0) {
            term = y + Srz(z, x, y) * sqrt(x * x + z * y);
        }
        else if ((z * z + x * y) <= 0) {
            throw ErrorA2("A2");
        }
        else if ((x * x + z * y) <= 0) {
            throw ErrorA3("A3");
        }
    }
    catch (ErrorA2& e) {
        e.Message();
        return 0;
    }
    catch (ErrorA3& e) {
        e.Message();
        return 0;
    }
    return term;
}

double Qrz(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x < 1 && x>-1) {
        term = x * Srs(x, y, x);
    }
    else {
        term = y * Srs1(y, x, y);
    }
    return term;
}
double Rrz(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x > y) {
        term = x * z * Qrz(y, z);
    }
    else {
        term = y * x * Qrz(x, y);
    }
    return term;
}
double Krn(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {

    double term;
    term = 73.1389 * Rrz(x, y, y) + 14.8389 * Rrz(x - y, z, y);

    return term;

}

double fun(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;
    temp = x * Krn (x, y, z) + y * Krn(x, z, y);
    return temp;
}


double Srs11(double x, double y, double z) throw (ErrorA2, ErrorA3, double) {
    double term;
    try {
        if (z > y) {
            term = Srz(x, y, z) + 1.44* y * z;
        }
        else {
            term = y + 1.44 * Srz(z, x, y);
        }
    }
    catch (ErrorA2& e) {
        e.Message();
        return 0;
    }
    catch (ErrorA3& e) {
        e.Message();
        return 0;
    }
    return term;
}
double Qrz1(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (y < 1 && y>-1) {
        term = x * Srs11(x, y, x);
    }
    else {
        term = y * Srs11(y, x, y);
    }
    return term;
}
double Rrz1(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x > y) {
        term = x * y * Qrz1(y, z);
    }
    else {
        term = x * z * Qrz1(x, y);
    }
    return term;
}
double Krn1(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {

    double term;
    term = 73.1389 * Rrz1(x, y, y) + 14.8389 * Rrz1(x - y, z, y);

    return term;

}

double fun1(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;
    temp = x * Krn1(x, y, z) + y * Krn1(x, z, y);
    return temp;
}



double Srs2(double x, double y, double z) throw (ErrorA2, ErrorA3, double) {
    double term;
    try {
        if (z > y) {
            term = Srz(x, y, z) + y * x;
        }
        else {
            term = y * z + Srz(z, x, y);
        }
    }
    catch (ErrorA2& e) {
        e.Message();
        return 0;
    }
    catch (ErrorA3& e) {
        e.Message();
        return 0;
    }
    return term;
}
double Qrz2(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (y < 1 && y>-1) {
        term = x * Srs2(x, y, x);
    }
    else {
        term = y * Srs2(y, x, y);
    }
    return term;
}
double Rrz2(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x > y) {
        term = x * y * Qrz2(y, z);
    }
    else {
        term = x * z * Qrz2(x, y);
    }
    return term;
}
double Krn2(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {

    double term;
    term = 73.1389 * Rrz2(x, y, y) + 14.8389 * Rrz2(x - y, z, y);

    return term;

}
double fun2(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;
    temp = x * Krn2(x, y, z) + y * Krn2(x, z, y);
    return temp;
}


double Srs3(double x, double y, double z) throw (ErrorA2, ErrorA3, double) {
    double term;
    try {
        if (z > y) {
            term = Srz(x, y, z) + y * x;
        }
        else {
            term = y * z + Srz(z, x, y);
        }
    }
    catch (ErrorA2& e) {
        e.Message();
        return 0;
    }
    catch (ErrorA3& e) {
        e.Message();
        return 0;
    }
    return term;
}
double Qrz3(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (y < 1 && y>-1) {
        term = x * Srs3(x, y, x);
    }
    else {
        term = x * Srs3(y, x, y);
    }
    return term;
}
double Rrz3(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x > y) {
        term = y * Qrz3(y, z);
    }
    else {
        term = z * Qrz3(x, y);
    }
    return term;
}
double Krn3(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {

    double term;
    term = 83.1389 * Rrz2(x, y, z) + 4.8389 * Rrz2(x, z, y);

    return term;

}
double fun3(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;
    temp = x * Krn3(x, y, z) + y * Krn3(x, z, y);
    return temp;
}

double fun4(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;
    temp = 4.349*x*z+23.23*y-2.348*x*y*z;
    return temp;
}



int main() {
    double x, y, z, f;
    cout << " Input x y z ";
    cin >> x >> y >> z;
    try {
        f = fun(x, y, z);
    }
    catch (ErrorA2& e) {
        cout << " \n Error: ";
        e.Message();
        f = fun1(x, y, z);
    }
    catch (ErrorA3& e) {
        cout << " \n Error: ";
        e.Message();
        f = fun2(x, y, z);
    }
    catch (ErrorA4& e) {
        cout << " \n Error: ";
        e.Message();
        f = fun3(x, y, z);
    }
    catch (ErrorOpenFile& e) {  //A5
        cout << " \n Error: ";
        e.Message();
        f = fun4(x, y, z);
    }
    catch (...) {
        cout << " \n This is a catch ...";
    }

    cout << "\n fun =" << f << endl;
    return 0;
}
