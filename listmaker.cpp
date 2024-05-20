#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int num_files = 10;

    for (int i = 1; i <= num_files; i++) {
        string filename = to_string(i) + ".txt"; // Construct filename
        ofstream file(filename); // Open file with the constructed filename
        if (file.is_open()) {
            // File opened successfully, you can write to it if needed
            cout << "Created file: " << filename << endl;
            file.close(); // Close the file
        } else {
            // Failed to open file
            cerr << "Error: Unable to create file " << filename << endl;
        }
    }

    return 0;
}

