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


double Gold(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    try {
    if (x > y && y != 0) {
        term = x / y;
    }
    if (y > x && x != 0) {
        term = y / x;
    }
    }

    catch (ErrorDevideByZero& e) {      ///  !!!
        e.Message();
        return 0;
        //term=fun2(x, y, z)
    }

    return term;
}

double Glr(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    try {
    if (x < 1 || (x * -1) < 1) {
        term = x;
    }
    if ((x >= 1 || (x * -1) >= 1) && (y < 1 || (y * -1) < 1)) {
        term = y;
    }
    if ((x >= 1 || (x * -1) >= 1) && (y >= 1 || (y * -1) >= 1) && (sqrt(x * x + y * y - 4) > 0.1)) {
        term = y / sqrt(x * x + y * y - 4);
    }
}
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
    try {

        ofstream file1("dat_X_1_1.txt");
        if (file1.is_open()) {
            string str = "-1,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1";
            file1 << str << endl;
            str = "-4.935,-3.013,-2.316,-1.819,-1.425,-1.097,-0.816,-0.571,-0.357,-0.167,0,0.147,0.276,0.386,0.477,0.548,0.597,0.617,0.597,0.505,0";
            file1 << str << endl;
            str = "1.935,0.464,1.327,1.976,2.502,2.951,3.344,3.695,4.013,4.303,4.571,4.618,4.645,4.652,4.636,4.596,4.524,4.412,4.240,3.956,0";
            file1 << str << endl;
        }
        file1.close();
        ofstream file2("dat_X_00_1.txt");
        if (file2.is_open()) {
            string str = "0,-0.05,-0.1,-0.15,-0.2,-0.25,-0.3,-0.35,-0.4,-0.45,-0.5,-0.55,-0.6,-0.65,-0.7,-0.75,-0.8,-0.85,-0.9,-0.95,-1";
            file2 << str << endl;
            str = "-4.935,-4.435,-3.936,-3.440,-2.948,-2.461,-1.98,-1.506,-1.041,-0.585,-0.141,0.292,0.712,1.117,1.507,1.882,2.239,2.578,2.898,3.199,3.48";
            file2 << str << endl;
            str = "1.935,1.835,1.735,1.636,1.537,1.44,1.344,1.249,1.156,1.065,0.976,0.889,0.806,0.724,0.646,0.572,0.5,0.432,0.368,0.308,0.252";
            file2 << str << endl;
        }
        file2.close();
        ofstream file3("dat_X1_00.txt");
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

        int te = 0, ue;

        int k = 0,
            k1=x1 * 1000;
        for (int i = 0; i < (sizeof(x) / sizeof(float)); i++) {
            k = x[i] * 1000;

            if (k == k1) {
                te = t[i];
                ue = u[i];
            }
        }

        for (int i = 0; i < ((sizeof(x) / sizeof(float)) - 1); i++) {
            if ((x[i] < x1) && (x1 < x[i + 1])) {
                te = T(x[i]) + (T(x[i + 1]) - T(x[i + 1])) * (x1 - x[i]) / (x[i + 1] - x[i]);
                //ue = U(x[i]) + (U(x[i + 1]) - U(x[i + 1])) * (x1 - x[i]) / (x[i + 1] - x[i]);
            }
        }

        file.close();

        term = te;

        return term;
    }

    catch (ErrorOpenFile& e) {
        e.Message();
        return 0;
    }

}


double U(double x1) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    string name;

    double te, ue;

    if (x1 <= 1 || (x1 * -1) <= 1) {
        name = "D:\\Chnu\\Summer\\ConsoleApplication1\\dat_X_1_1.dat";
    }

    if (x1 < -1) {
        x1 = 1 / x1;
        name = "D:\\Chnu\\Summer\\ConsoleApplication1\\dat_X_00_1.dat";
    }

    if (x1 > 1) {
        x1 = 1 / x1;
        name = "D:\\Chnu\\Summer\\ConsoleApplication1\\dat_X_1_00.dat";
    }

    try {
        ifstream file(name);


        double x[30], t[30], u[30];
        string xs, ys, zs;

        string line;


        short loop = 0;
        int k = 0;

        while (!file.eof()) {
            getline(file, line);
            if (k == 0) xs = line;
            if (k == 1) ys = line;
            if (k == 2) zs = line;
        }


        stringstream st(xs);
        stringstream st1(ys);
        stringstream st2(zs);

        k = 0;
        while (st.good()) {
            string str;
            getline(st, str, ',');
            x[k] = stod(str);
            //x[k] = (double)str;
            k++;
        }
        k = 0;
        while (st1.good()) {
            string str;
            getline(st1, str, ',');
            t[k] = stod(str);
            k++;
        }
        k = 0;
        while (st2.good()) {
            string str;
            getline(st2, str, ',');
            u[k] = stod(str);
            k++;
        }

        for (int i = 0; i < sizeof(x); i++) {
            if (x[i] == x1) {
                te = t[i];
                ue = u[i];
            }
        }

        for (int i = 0; i < sizeof(x) - 1; i++) {
            if ((x[i] < x1) && (x1 < x[i + 1])) {
                te = T(x[i]) + (T(x[i + 1]) - T(x[i + 1])) * (x1 - x[i]) / (x[i + 1] - x[i]);
                ue = U(x[i]) + (U(x[i + 1]) - U(x[i + 1])) * (x1 - x[i]) / (x[i + 1] - x[i]);
            }
        }

        file.close();

        term = ue;
    }

    catch (ErrorOpenFile& e) {
        e.Message();
        return 0;
    }

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
double Grs(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {

    double term;
    term = 0.1389 * Srz(x + y, Gold(x, y), Glr(x, x * y)) + 1.8389 * Srz(x - y, Gold(y, x / 5), Glr(5 * x, x * y)) + 0.83 * Srz(x - 0.9, Glr(y, x / 5), Gold(5 * y, 5));

    return term;

}

double fun(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;

    temp = x * x * Grs(y, z) + y * y * Grs(x, z) + 0.33 * x * y * Grs(x, z);

    return temp;
}





double Gold1(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x > y && (y > 0.1 || -y < 0.1)) {
        term = x / y;
    }
    if (y <= x && (x > 0.1 || -x < 0.1)) {
        term = y / x;
    }
    if (x < y && (x > 0.1 || -x < 0.1)) {
        term = 0.15;
    }

    if (y == 0) term = 0.1;

    return term;
}

double Glr1(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double term;
    if (x < 1 || (x * -1) < 1) {
        term = x;
    }
    if (x >= 1 || (x * -1) >= 1) {
        term = y;
    }

    return term;
}
double Grs1(double x, double y) throw (ErrorDevideByZero, ErrorOpenFile, double) {

    double term;
    term = 0.14 * Srz(x + y, Gold1(x, y), Glr1(x, x * y)) + 1.83 * Srz(x - y, Gold1(y, x / 5), Glr1(5 * x, x * y)) + 0.83 * Srz(x - 0.9, Glr1(y, x / 5), Gold1(5 * y, 5));

    return term;

}
double fun1(double x, double y, double z) throw (ErrorDevideByZero, ErrorOpenFile, double) {
    double temp;

    temp = x * x * Grs1(y, z) + y * y * Grs1(x, z) + 0.33 * x * y * Grs1(x, z);

    return temp;
}


int main() {
    double x, y, z, f;
    cout << " Input x y z ";
    cin >> x >> y >> z;
    try {
        f = fun(x, y, z);
    }
    catch (ErrorDevideByZero& e) {
        cout << " \n Error";
        f = fun1(x, y, z);
    }
    catch (ErrorSqrt& e) {
        cout << " \n Error";
        f = fun1(x, y, z);
    }
    catch (ErrorOpenFile& e) {
        e.Message();
        f = 1.3498 * z + 2.2362 * y - 2.348 * x * y;
    }
    catch (...) {
        cout << " \n This is a catch ...";
        f = 1.3498 * z + 2.2362 * y - 2.348 * x * y;
    }

    cout << "\n fun =" << f << endl;
    return 0;
}
