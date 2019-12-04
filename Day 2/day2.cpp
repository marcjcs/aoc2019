#include <bits/stdc++.h>

std::vector<int> partI(std::vector<int> tok) {
    bool continueCalc = true;
    int i = 0;

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

void run(int opt, std::vector<int> tokens) {
    std::vector<int> answer;

    switch (opt) {
        case 1:
            tokens.at(1) = 12;
            tokens.at(2) = 2;
            answer = partI(tokens);
            std::cout << "Part I: " << answer.at(0) << std::endl;
            break;
        case 2:
            for (int i = 0; i <= 99; i++) {
                for (int j = 0; j <= 99; j++) {
                    tokens.at(1) = i;
                    tokens.at(2) = j;
                    answer = partI(tokens);
                    
                    if (answer.at(0) == 19690720) {
                        std::cout << "Noun: " << i << std::endl;
                        std::cout << "Verb: " << j << std::endl;
                        std::cout << "Part II: " << 100 * i + j << std::endl;
                    }
                }
            }
            break;
        default:
            std::cout << "Provide a valid input (1 for part I, 2 for part II)!" << std::endl;
    }
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

    run(1, tokens);
    run(2, tokens);
    
    return 0;
}