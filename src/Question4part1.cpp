#include <iostream>
#include <vector>
#include <matplot/matplot.h>  // Include the Matplot++ header

// Constants for the lift equation
const float rho = 1.225;  // Air density in kg/m^3 (at sea level)
const float S = 30.0;     // Wing surface area in m^2
const float C_L = 1.5;    // Coefficient of lift (constant for simplicity)

float liftForce(double velocity) 
{
    return C_L * 0.5 * rho * velocity * velocity * S;  // Lift equation
}

int main() 
{
    // Vectors to hold velocity and corresponding lift values
    std::vector<double> velocities;
    std::vector<double> lifts;

    // Initialize the vectors with velocity values and their corresponding lift forces
    for (double v = 0; v <= 300; v += 0.5) 
    {
        velocities.push_back(v);
        lifts.push_back(liftForce(v));
    }

    // Plot the data
    matplot::plot(velocities, lifts);

    // Set title and labels
    matplot::title("Lift Force vs. Velocity");
    matplot::xlabel("Velocity (m/s)");
    matplot::ylabel("Lift Force (N)");

    // Show the plot
    matplot::show();

    return 0;
}
