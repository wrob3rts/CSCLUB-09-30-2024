#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>

int problemTwo(const char* inputFileName, const char* outputFileName, int multiple) {

    std::ifstream inputFile(inputFileName, std::ifstream::in);
    if(!inputFile) return std::cout << "[ERROR] Input File could not be found or could not be opened!" << std::endl, -1;
    std::ofstream outputFile(outputFileName, std::ofstream::out);
    if(!outputFile) return std::cout << "[ERROR] Output File could not be found or could not be created!" << std::endl, -1;

    int totalNumCow;
    inputFile >> totalNumCow;

    int longestPhoto = 0;
    std::vector<int> possibleRemainders(multiple, -1);
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

int usaco2020DecQ2(){


    return 0;
}

int problemOne(int starting_num){
    std::vector<int> values;
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

    std::string inputName, outputName;
    int divNum, startingNum;

    std::cout << "Enter Starting Number: ";
    std::cin >> startingNum;
    std::cout << std::endl << problemOne(startingNum) << std::endl;

    std::cout << "\nEnter Input File Name: ";
    std::cin >> inputName;
    std::cout << "Enter Output File Name: ";
    std::cin >> outputName;
    std::cout << "Divisible Number: ";
    std::cin >> divNum;
    std::cout << std::endl << problemTwo(inputName.c_str(), outputName.c_str(), divNum) << std::endl;

	return 0;
}
