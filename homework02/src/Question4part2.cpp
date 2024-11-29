#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <matplot/matplot.h>

int main() 
{
    // Initializing vectors to hold the data
    std::vector<double> time, x, y;

    // Openinng the CSV file
    std::ifstream file("../../third_party/data.csv");
    if (!file.is_open()) 
    {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    // Reading the data from the CSV file
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string cell;
        double t, xi, yi;

        std::getline(ss, cell, ','); // Read time
        t = std::stod(cell);
        time.push_back(t);

        std::getline(ss, cell, ','); // Read x
        xi = std::stod(cell);
        x.push_back(xi);

        std::getline(ss, cell, ','); // Read y
        yi = std::stod(cell);
        y.push_back(yi);
    }

    // Close the file
    file.close();

    //Printing the data to verify it's being read
    std::cout << "Time\tX\tY\n";
    for (size_t i = 0; i < time.size(); ++i) 
    {
        std::cout << time[i] << "\t" << x[i] << "\t" << y[i] << std::endl;
    }

    // Plot the data 
    matplot::figure();  // Create a new figure
    matplot::plot(x, y);  // Plot 'x' vs 'y'
    matplot::xlabel("X");
    matplot::ylabel("Y");
    matplot::title("2D Plot of Y vs X");
    matplot::show();

    return 0;
}
