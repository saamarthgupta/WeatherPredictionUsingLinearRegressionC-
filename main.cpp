#include <iostream>
#include "LinearRegression.h"

using namespace std;

void days_vs_temp()
{
    double days[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    double temperatures[] = {29, 22, 33, 34, 29, 35, 40, 32, 29, 33, 30, 43, 39, 34, 36};

    LinearRegression weatherpred(days,temperatures, 15);

    cout << "Enter learning rate alpha (default: 0.01): ";
    double alpha;
    cin>>alpha;

    cout << "Enter number of iterations (default: 1500): ";
    int iterations;
    cin >> iterations;

    cout << "Training model..." << endl;
    weatherpred.train(alpha, iterations);

    cout << "Model has been trained, enter Day :  ";
    double x;
    cin >> x;

    double temperature = weatherpred.predict(x);
    cout << "Estimated temperature: " << temperature << " C" << endl;
}


int main()
{
        days_vs_temp();

        cout << endl << endl;


    return 0;
}
