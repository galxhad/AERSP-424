# Homework 02 - AERSP-424

Welcome to my AERSP-424 repository for my homework assignment!

For the Grader:

## Accessing the Repository

To access Homework 02, you need to clone the repository and follow the instructions below:

1. **Clone the repository**:
   - Run the following command to clone the homework repository:
     ```bash
     git clone https://github.com/galxhad/AERSP-424.git
     ```
2. **Going to the Branch repository**:
   - Once the homework repository is cloned run the following command to go to the branch repository:
     ```bash
     cd AERSP-424
     git checkout feature/homework02
     ```     
2. **Cloning MatPlot++**:
   - Once you are in the branch homework repository, you will need to clone MatPlot++ to run the build.sh, run the following command to colne MatPlot++ in the branch repository:
     ```bash
     git submodule update --init --recursive
     ```  
3. **Build the project**:
   - Omce the MatPlot++ is cloned, run the following command to build the project:
     ```bash
     bash build.sh
     ```
   - This will start the build process and automatically generate the output till **Question 4 - Part 1**.
   - After the graph for **Question 4 - Part 1** is displayed, the program will ask you to press `Enter` to move to **Part 2** of Question 4.

3. **Manual Build Option**:
   - If the build command does not work as expected, you can manually configure and build the project using Visual Studio Code:
     - Open the folder in VS Code where the repository is cloned.
     - Manually configure, build, and run the executable from the IDE.

---

## Folder Structure

The Homework 02 repository contains the following folder structure:

- **`include/`**: Contains all the header files.
- **`src/`**: Contains all the source files.
- **`third_party/`**: Contains plotting and CSV data files for **Question 4**.
- **`build.sh`**: Script to automate the build process.
- **`CMakeLists.txt`**: Configuration file for CMake build system.

---

## File Details for Each Question

Here’s a breakdown of the relevant files for each question:

### **Question 1**:
- **Header Files**: 
  - `AerospaceControlSystem.h`
  - `AltitudeSensor.h`
  - `PressureSensor.h`
  - `TemperatureSensor.h`
  - `SensorFactory.h`
  - `Sensor.h`
- **Source Files**:
  - `src/AerospaceControlSystem.cpp`
  - `src/AltitudeSensor.cpp`
  - `src/PressureSensor.cpp`
  - `src/TemperatureSensor.cpp`
  - `src/SensorFactory.cpp`
  - `src/Question1main.cpp`

### **Question 2**:
- **Header File**:
  - `robot.h`
- **Source File**:
  - `src/Question2main.cpp`

### **Question 3**:
- **Header File**:
  - `airport_simulator.h`
- **Source Files**:
  - `src/airport_simulator.cpp`
  - `src/Question3main.cpp`

### **Question 4**:
- **Source Files**:
  - `src/Question4part1.cpp`
  - `src/Question4part2.cpp`

Note: There are no header files for Question 4.

---

## Additional Notes

- After running the build script, ensure you have the required dependencies (such as libraries for plotting and CSV reading) as indicated in the **third_party/** folder for Question 4.
- For any issues with the build process, you may check the build logs or configure manually via VS Code.

## Declaration

I would like to acknowledge the use of Generative AI in the creation of several files in this repository. Specifically, I used AI assistance to help with the following:

- **CMakeLists.txt**: The configuration for the build system was generated with the help of Generative AI.
- **build.sh**: The build script for automating the project compilation was assisted by AI.
- **README.md**: The structure and content of the README file were generated with the aid of Generative AI to ensure clarity and completeness.

While I reviewed and tailored the output to meet the specific requirements of this project, I wanted to explicitly state the use of AI as a tool in the development process.
