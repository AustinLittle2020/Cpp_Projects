#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    //Menu variables
    float initialInv;
    float monthlyDep;
    float AnnualInt;
    int months;
    int years;

    //Variables to store calculations
    float totalAmount;
    float interestAmt;
    float totYearInterest;

    //Display menu
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//Ensures program does not exit before user can press any key
	system("PAUSE");

    //Display menu and ask for user input
    cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: ";
	cin >> initialInv;
	cout << "Monthly Deposit: ";
	cin >> monthlyDep;
	cout << "Annual Interest: ";
	cin >> AnnualInt;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;

	//Ensures program does not exit before user can press any key
	system("PAUSE");

	//Sets the total to the starting investment
	// This is because we have not updated it for monthly deposits yet
	totalAmount = initialInv;

	//Menu without monthly deposits
    cout << endl;
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "==============================================================" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "--------------------------------------------------------------" << endl;

    //Calculates interest and total for first menu
    for (int i = 0; i < years; i++) {

        //Yearly interest
        interestAmt = totalAmount * (AnnualInt / 100);

        // Yearly end total
        totalAmount = totalAmount + interestAmt;

        //Output results into menu without monthly deposits
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << "$" << totalAmount << "\t\t\t" << "$" << interestAmt << endl;

    }

    //Updates total amount
    totalAmount = initialInv;

    //Menu with monthly deposits
	cout << endl;
	cout << endl;
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "==============================================================" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "--------------------------------------------------------------" << endl;

    //Calculates interest and total for second menu
    for (int i = 0; i < years; i++) {

            //Start of year has 0 yearly interest
            totYearInterest = 0;

            for (int j = 0; j < 12; j++) {

                //Monthly interest
                interestAmt = (totalAmount + monthlyDep) * ((AnnualInt / 100) / 12);

                //Interest at end of month
                totYearInterest = totYearInterest + interestAmt;

                //Ending total for month
                totalAmount = totalAmount + monthlyDep + interestAmt;
            }

            //Output results into menu with monthly deposits
            cout << (i + 1) << "\t\t" << fixed << setprecision(2) << "$" << totalAmount << "\t\t\t" << "$" << totYearInterest << endl;
    }


return 0;

}
