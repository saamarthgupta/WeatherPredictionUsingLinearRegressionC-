#include <iostream>
#include <fstream>
#include "LinearRegression.h"

using namespace std;

/*class weatherdata
{
public:
	double days[1000];
	double temperatures[1000];
	int count;
	weatherdata()
	{
		count=0;
	}
	void readweatherdata(int choice);
};

void weatherdata::readweatherdata(int choice)
{
	fstream file;
    string filename;
	/*if(choice==1)
        filename="../Database/INDELHI.csv";
	else if(choice == 2)
		filename = "../Database/INMUMBAI.csv";
    else if(choice == 3)
		filename = "../Database/INKOLKATA.csv";
	else
		filename = "../Database/INCHENNAI.csv";
    file.open("../Database/INDELHI.csv", fstream::in);

	if(!file)
		cout<<"File Not Opened.\n";
	else
	{
		int flag;
	    string date;
	    int i=0;
	    int countt,loc=0;

	    while(file.good())
	    {
	        countt=0;
	    	getline ( file, date );

	        int sze=date.size();
	        for(i=0;i<sze;i++)
	        {
	            if(date[i]=='\t')
	                countt++;
	            if(countt==3)
	            {
	                countt=0;
	                break;
	            }
	        }
	        i++;
	        int j;
	        flag=0;
			if(count==50)
				break;
	        for(j=i;j<sze;j++)
	        {
	            if(date[j]=='.')
	            {
	                temperatures[loc]=10*((int)date[i]-'0')+((int)date[i+1]-'0')+((double)date[j+1]-'0')/10;
	                flag=1;
	                break;
	            }
	        }
	        if(flag==0)
	            temperatures[loc]=10*((int)date[i]-'0')+(int)date[i+1]-'0';
	        int ran=loc;
	        days[ran]=++loc;
			count++;

	    }
	}
}
*/
void days_vs_temp()
{
	/*weatherdata l1;*/
	double days[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	double temperatures[] = {29, 22, 33, 34, 29, 35, 40, 32, 29, 33, 30, 43, 39, 34, 36,27.97};
	/*l1.readweatherdata(choice);*/
    LinearRegression weatherpred(days,temperatures, 16);


    cout << "Enter learning rate alpha (default: 0.01): ";
    double alpha;
    cin>>alpha;

    cout << "Enter number of iterations (default: 2000): ";
    int iterations;
    cin >> iterations;

    cout << "Training model..." << endl;
    weatherpred.train(alpha, iterations);
    double x;
  	int day=3;
	
    for(x=1;x<=20;x++)
    {
	    double temperature = weatherpred.predict(x);

	    cout << "Estimated temperature for "<<++day<<"/08/2017 is : " << temperature << " C" << endl;	//Temperature is Read in F
	}
}


int main()
{

    int choice;
    check:											//Goto label JUMP
	cout<<"Welcome to Weather Prediction Wizard.\n";
	
	cout<<"1. Delhi\n";
	cout<<"2. Chennai\n";
	cout<<"3. Mumbai\n";
	cout<<"4. Kolkata\n";
	cout<<"Select The City : \n";
		cin>>choice;
	if(choice==1)
		cout<<"You Have Chosen Delhi.\n";
	else if(choice==2)
		cout<<"You Have Chosen Chennai.\n";
	else if(choice==3)
		cout<<"You Have Chosen Mumbai.\n";
	else if(choice==4)
		cout<<"You Have Chosen Kolkata.\n";
	else
	{
		cout<<"You Have Chosen the Wrong choice. Try Again.\n";
		goto check;
	}

    days_vs_temp();

        cout << endl << endl;


    return 0;
}
