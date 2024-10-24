#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Plane; // Predefining Class 

// Question 2. 
// Flight struct to hold route information
struct FlightMaps 
{
    string from, to;
    int distance;
    FlightMaps(const string & from, const string & to, int distance) : from(from), to(to), distance(distance) {}
};

// Question 3 & 4
// Creating class plane and initalising the class
class Plane 
{
private:
    double pos, vel, distance;
    string origin, destination;
    bool at_SCE;
    vector<FlightMaps> flight_distance; // Changed to vector for multiple flights

public:
    // Constructor
    Plane(const string& from, const string& to) : pos(0.0), vel(0.0), distance(0), origin(from), destination(to), at_SCE(true) {cout << "Plane created at: " << this << endl;}

    // Destructor
    ~Plane() {cout << "Plane destroyed" << endl;}

    // Getter functions
    double getPos() const { return pos; }
    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    bool isAtSCE() const { return at_SCE; }
    double getVel() const { return vel; }

    void get_distance() 
    {
        for (const auto& flight : flight_distance) 
        {
            if (flight.from == origin && flight.to == destination) 
            {
                distance = flight.distance;
                return;
            }
            else if (flight.from == destination && flight.to == origin) 
            {
                distance = flight.distance;
                return;
            } 
        }
        distance = 0; // If no flight matches, set distance to 0
    }

    // Setter function
    void setVel(double newVel) { vel = newVel; }

    // Function to operate the plane
    void operate(double dt) 
    {
        get_distance();
        if (pos < distance)
        {
            pos += vel / 3600 * dt; // Update position based on velocity and time
            at_SCE = 0; // Not at SCE yet
        }
        else 
        {
            if (destination == "SCE")
            {
                at_SCE = true; // Arrived at SCE
                cout << "The plane " << this << " has arrived at SCE." << endl;
            }

            else {}
            swap(origin, destination);
            cout << "Flight from " << origin << " to " << destination << " finished. On to the next leg" << endl;
            pos = 0.0;
            return;
        }
    }

    void setFlightDistances(const vector<FlightMaps>& flights) {
        flight_distance = flights; // Set flight distances
    }
};


// Main Function
int main() 
{
    // Initialising Origin and Destination
    string Origin, Destination;
    Origin = "SCE";
    Destination = "PHL";
    Plane plane(Origin, Destination);

    // Storing flight details from the given data in Question 2 
    vector<FlightMaps> flights = {FlightMaps("SCE", "PHL", 160), FlightMaps("SCE", "ORD", 640), FlightMaps("SCE", "EWR", 220)};
    
    // Getting flight distance
    plane.setFlightDistances(flights); 

    // Question 5. 
    // Initialization
    double vel = 420;
    plane.setVel(vel);
    double tspan = 69;

    int maxiters = 1500, iter = 0;
    
    while (iter <= maxiters)
    {
        cout << "Time = " << tspan * iter << "seconds.  Position = " << plane.getPos() << "miles. \n";
        plane.operate(tspan);
        iter++;
    }
    return 0;
}
