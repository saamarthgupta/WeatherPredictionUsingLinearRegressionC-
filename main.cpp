#include <iostream>
#include <fstream>
#include "LinearRegression.h"
#include <stdlib.h>

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
        filename="Database/INDELHI.csv";
	else if(choice == 2)
		filename = "Database/INMUMBAI.csv";
    else if(choice == 3)
		filename = "Database/INKOLKATA.csv";
	else
		filename = "Database/INCHENNAI.csv";
    file.open("Database/INDELHI.csv", fstream::in);

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
void days_vs_temp(int choice)
{
    int counta;
	/*weatherdata l1;*/
	double days[400];
	double temperatures[400];
	/*l1.readweatherdata(choice);*/

	fstream file;
    if(choice==1)
	file.open("../Database/INDELHI.csv", fstream::in);
    else if(choice==2)
        file.open("../Database/INCHENNAI.csv", fstream::in);
    else if(choice==3)
        file.open("../Database/INMUMBAI.csv", fstream::in);
    else
        file.open("../Database/INKOLKATA.csv",fstream::in);
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
			if(loc==365)
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
			counta++;

	    }
        file.close();
	}

	int count=19;

    LinearRegression weatherpred(days,temperatures,19);

    /*cout << "Enter learning rate alpha (default: 0.01): ";*/
    double alpha=0.01;
    /*cin>>alpha;*/

    /*cout << "Enter number of iterations (default: 1500): ";*/
    int iterations=1500;
    /*cin >> iterations;*/

    cout << "Training model..." << endl;
    weatherpred.train(alpha, iterations);
    double x=1;
  	int day=3;
    double temperature = weatherpred.predict(x);
    temperatures[count]=temperature;
    days[count]=count+1;
    count++;
    cout << "Estimated temperature for "<<++day<<"/08/2017 is : " << temperature << " F" << endl;
    for(x=2;x<3;x++)
    {
        int loc=20;
        LinearRegression weatherpred1(days,temperatures,loc);
        loc++;
        iterations+=1;
        weatherpred1.train(alpha, iterations);
        temperature = weatherpred1.predict(x);
        temperatures[count]=temperature;
        days[count]=count+1;
        count++;
	    cout << "Estimated temperature for "<<++day<<"/08/2017 is : " << temperature << " F" << endl;	//Temperature is Read in F
	}
}


int main()
{
    int choice,con=1;

    while(con==1)
    {
        check:											//Goto label JUMP
        system("CLS");
        cout << "Welcome to Weather Prediction Wizard.\n";

        cout << "1. Delhi\n";
        cout << "2. Chennai\n";
        cout << "3. Mumbai\n";
        cout << "4. Kolkata\n";
        cout << "Select The City : \n";

            cin >> choice;

        if (choice == 1)
            cout << "You Have Chosen Delhi.\n";
        else if (choice == 2)
            cout << "You Have Chosen Chennai.\n";
        else if (choice == 3)
            cout << "You Have Chosen Mumbai.\n";
        else if (choice == 4)
            cout << "You Have Chosen Kolkata.\n";
        else
        {
            cout << "You Have Chosen the Wrong choice. Try Again.\n";
            goto check;
        }

        days_vs_temp(choice);
         cout<<"Want to Try Again? (Press 1) : ";
            cin>>con;
    }
    cout<<"\nThanks for Using The Program.\n";
    return 0;
}
