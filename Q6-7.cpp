#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Flight struct to hold route information
struct FlightMaps
{
    string from, to;
    int distance;
    FlightMaps(const string& from, const string& to, int distance) : from(from), to(to), distance(distance) {}
};

// Creating class Pilot
class Pilot
{
private:
    string name;

public:
    // Constructor
    Pilot(const string& name) : name(name) {cout << "Pilot " << name << " with memory address " << this << " is at the gate and ready to board the plane." << endl;}

    // Destructor
    ~Pilot() { cout << "Pilot " << name << " is out of the airplane." << endl; }

    // Getter function
    string getName() const { return name; }

    // Pointer to the Plane object
    class Plane* myPlane;
};

// Creating class Plane
class Plane
{
private:
    double pos, vel, distance;
    string origin, destination;
    bool at_SCE;
    vector<FlightMaps> flight_distance;
    Pilot* pilot;
    Pilot* copilot;

public:
    // Constructor
    Plane(const string& from, const string& to) : pos(0.0), vel(0.0), distance(0), origin(from), destination(to), at_SCE(true), pilot(nullptr), copilot(nullptr) {cout << "Plane created at: " << this << endl;}

    // Destructor
    ~Plane() {cout << "Plane destroyed" << endl;}

    // Getter functions
    double getPos() const { return pos; }
    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    bool isAtSCE() const { return at_SCE; }
    double getVel() const { return vel; }

    void setPilots(Pilot* pilotName, Pilot* copilotName) { pilot = pilotName; copilot = copilotName; }

    void get_distance() 
    {
        for (const auto& flight : flight_distance) {
            if (flight.from == origin && flight.to == destination) {
                distance = flight.distance;
                return;
            }
            else if (flight.from == destination && flight.to == origin) {
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
            at_SCE = false; // Not at SCE yet
        }
        else 
        {
            if (destination == "SCE") 
            {
                at_SCE = true; // Arrived at SCE
                swap(pilot, copilot);

                cout << "The plane " << this << " has arrived at SCE." << endl;

                if (pilot) 
                {
                    cout << "Pilot " << pilot->getName() << " with certificate number " << pilot << " is now in control of the plane: " << this << endl;
                }
                if (copilot) 
                {
                    cout << "Copilot " << copilot->getName() << " with certificate number " << copilot << " is in control of the plane: " << this << endl;
                }
            }

            swap(origin, destination);
            cout << "Flight from " << origin << " to " << destination << " finished. On to the next leg" << endl;
            pos = 0.0;
            return;
        }
    }

    void setFlightDistances(const vector<FlightMaps>& flights) 
    {
        flight_distance = flights; // Set flight distances
    }
};

// Main Function
int main()
{
    // Initializing Origin and Destination
    string Origin = "SCE";
    string Destination = "ORD";
    Plane plane(Origin, Destination);

    // Storing flight details
    vector<FlightMaps> flights = { FlightMaps("SCE", "PHL", 160), FlightMaps("SCE", "ORD", 640), FlightMaps("SCE", "EWR", 220) };

    // Getting flight distance
    plane.setFlightDistances(flights);

    // Pilot initialization
    Pilot pilot("Ice-Man");
    Pilot copilot("Percival");
    plane.setPilots(&pilot, &copilot);
    pilot.myPlane = &plane;
    copilot.myPlane = &plane;

    double vel = 420;
    plane.setVel(vel);
    double tspan = 69;

    int maxiters = 1500, iter = 0;

    while (iter <= maxiters) 
    {
        cout << "Pilot " << pilot.getName() << " with certificate number " << &pilot << " is in control of the plane: " << &plane << endl;
        cout << "Copilot " << copilot.getName() << " with certificate number " << &copilot << " is in control of the plane: 0x0" << '\n' << endl;
        plane.operate(tspan);
        iter++;
    }

    return 0;
}
