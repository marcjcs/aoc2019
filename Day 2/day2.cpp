#include <bits/stdc++.h>

std::vector<int> partI(std::vector<int> tok) {
    bool continueCalc = true;
    int i = 0;
    int calculation = 0;

    while (continueCalc) {
        int resultIndex = tok.at(i + 3);
        int index1 = tok.at(i + 1);
        int index2 = tok.at(i + 2);

        if (tok.at(i) == 99) {
            continueCalc = false;
        }
        
        if (tok.at(i) == 1) {
            tok.at(resultIndex) = tok.at(index1) + tok.at(index2);
        }

        if (tok.at(i) == 2) {
            tok.at(resultIndex) = tok.at(index1) * tok.at(index2);
        }

        i += 4;
    }

    return tok;
}

int main() {
    std::ifstream file("input.txt");
    std::string input;
    
    file >> input;
    
    std::vector<int> tokens;
    std::stringstream check1(input);
    std::string intermediate;
    
    while (getline(check1, intermediate, ',')) {
        int num = stoi(intermediate);
        tokens.push_back(num);
    }

    tokens.at(1) = 12;
    tokens.at(2) = 2;

    tokens = partI(tokens);
    
    std::cout << tokens.at(0);

    return 0;
}