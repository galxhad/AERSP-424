// QUESTION 1.

#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    // Initialization of Airplane design limits
    const double MAX_GROSS_WEIGHT = 2950.0;
    const double FORWARD_CG_LIMIT = 82.1;
    const double AFT_CG_LIMIT = 84.7;

    // Variable declaration for user input of plane data
    double emptyWeight, emptyWeightMoment, frontSeatMomentArm, rearSeatMomentArm, fuelGallons, fuelWeightPerGallon, fuelMomentArm, baggageWeight, baggageMomentArm;
    int frontSeatOccupants, rearSeatOccupants;

    // Taking user input
    cout << "Enter airplane empty weight (pounds): ";
    cin >> emptyWeight;

    cout << "Enter airplane empty-weight moment (pounds-inches): ";
    cin >> emptyWeightMoment;

    cout << "Enter number of front seat occupants: ";
    cin >> frontSeatOccupants;

    // User input for front seat passenger weights
    vector<double> frontSeatWeights(frontSeatOccupants);
    for (int i = 1; i <= frontSeatOccupants; ++i)
    {
        cout << "Enter weight of front seat occupant " << (i) << " (pounds): ";
        cin >> frontSeatWeights[i - 1];
    }

    cout << "Enter front seat moment arm (inches): ";
    cin >> frontSeatMomentArm;

    cout << "Enter number of rear seat occupants: ";
    cin >> rearSeatOccupants;

    // User input for rear seat passenger weights
    vector<double> rearSeatWeights(rearSeatOccupants);
    for (int i = 0; i < rearSeatOccupants; ++i)
    {
        cout << "Enter weight of rear seat occupant " << (i + 1) << " (pounds): ";
        cin >> rearSeatWeights[i];
    }

    cout << "Enter rear seat moment arm (inches): ";
    cin >> rearSeatMomentArm;

    cout << "Enter number of gallons of usable fuel: ";
    cin >> fuelGallons;

    cout << "Enter usable fuel weight per gallon (pounds): ";
    cin >> fuelWeightPerGallon;

    cout << "Enter fuel tank moment arm (inches): ";
    cin >> fuelMomentArm;

    cout << "Enter baggage weight (pounds): ";
    cin >> baggageWeight;

    cout << "Enter baggage moment arm (inches): ";
    cin >> baggageMomentArm;

    // Calculating total front and rear seat weight
    double frontSeatTotalWeight = accumulate(frontSeatWeights.begin(), frontSeatWeights.end(), 0.0);
    double rearSeatTotalWeight = accumulate(rearSeatWeights.begin(), rearSeatWeights.end(), 0.0);

    double fuelWeight = fuelGallons * fuelWeightPerGallon;

    double totalWeight = emptyWeight + frontSeatTotalWeight + rearSeatTotalWeight + fuelWeight + baggageWeight;
    double totalMoment = emptyWeightMoment + (frontSeatTotalWeight * frontSeatMomentArm) + (rearSeatTotalWeight * rearSeatMomentArm) + (fuelWeight * fuelMomentArm) + (baggageWeight * baggageMomentArm);

    // Calculating CG
    double CG = totalMoment / totalWeight;
    cout << fixed << setprecision(2);
    cout << "Gross Weight: " << totalWeight << " lbs" << endl;
    cout << "Center of Gravity (CG): " << CG << " inches" << endl;

    // Checking necessary CG conditions
    if (totalWeight > MAX_GROSS_WEIGHT || CG < FORWARD_CG_LIMIT || CG > AFT_CG_LIMIT)
    {
        cout << "WARNING: Limits exceeded!" << endl;

        // Adjusting fuel to meet limits
        double fuelAdjustment = 0.0;

        if (totalWeight > MAX_GROSS_WEIGHT)
        {
            fuelAdjustment = (totalWeight - MAX_GROSS_WEIGHT) / fuelWeightPerGallon;
            cout << "Fuel to drain: " << fuelAdjustment << " gallons" << endl;
        }
        else if (CG < FORWARD_CG_LIMIT)
        {
            fuelAdjustment = (CG - FORWARD_CG_LIMIT) * totalWeight / fuelWeightPerGallon; // simplified approach
            cout << "Fuel to add: " << fuelAdjustment << " gallons" << endl;
        }
        else if (CG > AFT_CG_LIMIT)
        {
            fuelAdjustment = (CG - AFT_CG_LIMIT) * totalWeight / fuelWeightPerGallon; // simplified approach
            cout << "Fuel to drain: " << fuelAdjustment << " gallons" << endl;
        }

        // Update fuel weight and recalculate total weight and CG
        fuelGallons = fuelGallons - fuelAdjustment;
        fuelWeight = fuelGallons * fuelWeightPerGallon;
        totalWeight = emptyWeight + frontSeatTotalWeight + rearSeatTotalWeight + fuelWeight + baggageWeight;

        totalMoment = emptyWeightMoment + (frontSeatTotalWeight * frontSeatMomentArm) + (rearSeatTotalWeight * rearSeatMomentArm) + (fuelWeight * fuelMomentArm) + (baggageWeight * baggageMomentArm);
        CG = totalMoment / totalWeight;

        // Output updated gross weight and CG
        cout << "Updated Gross Weight: " << totalWeight << " lbs" << endl;
        cout << "Updated Center of Gravity (CG): " << CG << " inches" << endl;
    }
    else
    {
        cout << "Weights and CG are within limits." << endl;
    }
}
