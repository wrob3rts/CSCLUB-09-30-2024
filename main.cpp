#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

int problemTwo(const char* inputFileName, const char* outputFileName, int multiple) {
    std::ifstream inputFile(inputFileName, std::ifstream::in);
    std::ofstream outputFile(outputFileName, std::ofstream::out | std::ofstream::app);

    int totalNumCow;
    inputFile >> totalNumCow;

    int longestPhoto = 0;
    std::vector<int> possibleRemainders(multiple, -1);

    int remainder;
    for(int i = 1; i <= totalNumCow; i++){
        int currentCow;
        inputFile >> currentCow;

        remainder = (remainder+currentCow) % multiple;
        if(possibleRemainders[remainder] == -1) possibleRemainders[remainder] = i;
        else if(longestPhoto < (i - possibleRemainders[remainder])) longestPhoto = i - possibleRemainders[remainder];
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

    std::cout << problemOne(1000) << std::endl;
    std::cout << problemTwo("div.in", "div.out", 7) << std::endl;

	return 0;
}
