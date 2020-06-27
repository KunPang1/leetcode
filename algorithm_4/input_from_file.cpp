#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    string filename = argv[1];

    ifstream myfile(filename);

    if (! myfile.is_open())  
    { cout << "Error opening file"; exit (1); }  

    string data;
    getline(myfile, data);

    vector<int> nums;
    int temp;
    for (int i = 0; i < data.length(); ++i) {
        if (!isdigit(data[i])) continue;
        while (isdigit(data[i])) {
            temp = temp * 10 + data[i] - '0';
            i++;
            if (i == data.length()) break;
        }
        nums.push_back(temp);
        temp = 0;
    }
    
    for (int x : nums)
        cout << x << " ";
    cout << endl;
    return 0;
}