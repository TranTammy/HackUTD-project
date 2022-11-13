#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("readFile.txt");
    outFile.open("outputFile.txt");

    string line, name;
    vector<string> tokens;

    long double penetrationRate = 0, startDepth, tempDepth, counter = 1;
    int pastID = 1;

    if (inFile.is_open())
    {
        while (getline(inFile, line, '\n'))
        {
            vector<string> tokens;
            stringstream check1(line);
            string token;

            while (getline(check1, token, ','))
            {
                if (!token.empty())
                    tokens.push_back(token);
                else
                {
                    tokens.push_back("0");
                }
            }

            if (counter == 0 && !(tokens.empty()))
                startDepth = stod(tokens.at(0));

            if (!tokens.empty() && pastID != stoi(tokens.at(5)))
            {
                outFile << "Name: " << name << endl;
                outFile << "ID: " << pastID << endl;
                outFile << "Pen Rate Average: " << penetrationRate / counter << endl;
                outFile << "Starting Depth: " << startDepth << " End Depth: " << tempDepth << endl;
                outFile << "Distance is: " << tempDepth << " - " << startDepth << " = " << tempDepth - startDepth << endl;
                outFile << "Current Counter: " << counter << endl;
                pastID = stoi(tokens.at(5));
                counter = 0;
            }
            if (counter == 0 && !(tokens.empty()))
                startDepth = stod(tokens.at(0));
            counter++;
            tempDepth = stod(tokens.at(0));
            penetrationRate += stod(tokens.at(1));
            name = tokens.at(6);
        }
    }
    outFile << "Name: " << name << endl;
    outFile << "ID: " << pastID << endl;
    outFile << "Pen Rate Average: " << penetrationRate / counter << endl;
    outFile << "Starting Depth: " << startDepth << " End Depth: " << tempDepth << endl;
    outFile << "Distance is: " << tempDepth << " - " << startDepth << " = " << tempDepth - startDepth << endl;
    outFile << "Current Counter: " << counter << endl;

    inFile.close();
    outFile.close();

    return 0;
}