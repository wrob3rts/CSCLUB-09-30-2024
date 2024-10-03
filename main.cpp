#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

int problemThree(int numFlowers, vector<int>& flowerPetals){
    int count = 0;

    for(int i = 0; i < numFlowers; i++){
        for(int j = i; j < numFlowers; j++){
            float avgPetals = 0;
            for(int l = i; l <= j; l++){
                avgPetals += flowerPetals[l];
            }
            avgPetals /= (j-i+1);

            for(int l = i; l <= j; l++){
                if(flowerPetals[l] == avgPetals){
                    count++;
                    break;
                }
            }

        }
    }


    return count;
}

int problemTwo(const char* inputFileName, const char* outputFileName, int multiple) {

    ifstream inputFile(inputFileName, ifstream::in);
    if(!inputFile) return cout << "[ERROR] Input File could not be found or could not be opened!" << endl, -1;
    ofstream outputFile(outputFileName, ofstream::out);
    if(!outputFile) return cout << "[ERROR] Output File could not be found or could not be created!" << endl, -1;

    int totalNumCow;
    inputFile >> totalNumCow;

    int longestPhoto = 0;
    vector<int> possibleRemainders(multiple, -1);
    possibleRemainders[0] = 0;

    int remainder = 0;
    for(int i = 1; i <= totalNumCow; i++){
        int currentCow;
        inputFile >> currentCow;

        remainder = (remainder + currentCow) % multiple;
        if(possibleRemainders[remainder] == -1)
            possibleRemainders[remainder] = i;
        else if(longestPhoto < (i - possibleRemainders[remainder])) 
            longestPhoto = i - possibleRemainders[remainder];
    }
    outputFile << longestPhoto;
    return longestPhoto;
}

int problemOne(int starting_num){
    vector<int> values;
    for(int i = starting_num - 1; i > 0; i--){
        if(i % 3 == 0 || i % 5 == 0) values.push_back(i);
    }
    int sum = 0;
    for(int i = 0; i < values.size(); i++){
        sum += values[i];
    }
    return sum;
}


int main() {

    string inputName, outputName;
    int divNum, startingNum;

    cout << "Enter Starting Number: ";
    cin >> startingNum;
    cout << endl << problemOne(startingNum) << endl;

    cout << "\nEnter Input File Name: ";
    cin >> inputName;
    cout << "Enter Output File Name: ";
    cin >> outputName;
    cout << "Divisible Number: ";
    cin >> divNum;
    cout << endl << problemTwo(inputName.c_str(), outputName.c_str(), divNum) << endl;

    int numFlowers;
    cout << endl << "Number of Flowers?: ";
    cin >> numFlowers;
    vector<int> flowerPetals(numFlowers);
    cout << "Flower Petals: ";
    for(int &n : flowerPetals) {cin >> n;}
    cout << endl << problemThree(numFlowers, flowerPetals);


    cout << endl << "Goodbye!" << endl;
	return 0;
}
