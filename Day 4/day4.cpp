#include <bits/stdc++.h>

bool validate(int n) {
    std::stringstream ss;
    ss << n;
    std::string numStr = ss.str();
    bool adjacentDouble = false;
    bool neverDecrease = true;

    for (int i = 0; i < numStr.size() - 1; i++) {
        if (((int)numStr.at(i) - 48) > ((int)numStr.at(i + 1) - 48)) {
            neverDecrease = false;
        }
        if (((int)numStr.at(i) - 48) == ((int)numStr.at(i + 1) - 48)) {
            adjacentDouble = true;
        }
    }

    return neverDecrease && adjacentDouble;
}

bool validate2(int n) {
    std::stringstream ss;
    ss << n;
    std::string numStr = ss.str();
    bool adjacentDouble = false;
    bool neverDecrease = true;
    bool checkedPenultime = false;

    for (int i = 0; i < numStr.size() - 1; i++) {
        if (i != numStr.size() - 2) {
            if (i == numStr.size() - 2) {
                checkedPenultime = true;
            }
            if (((int)numStr.at(i) - 48) == ((int)numStr.at(i + 1) - 48) && ((int)numStr.at(i + 1) - 48) != ((int)numStr.at(i + 2) - 48)) {
                adjacentDouble = true;
            }
        } else {
            if (!checkedPenultime) {
                if (((int)numStr.at(i) - 48) == ((int)numStr.at(i + 1) - 48)) {
                    adjacentDouble = true;
                }   
            }
        }
        if (((int)numStr.at(i) - 48) > ((int)numStr.at(i + 1) - 48)) {
            neverDecrease = false;
        }
    }

    return neverDecrease && adjacentDouble;
}

int main() {
    std::set<int> answerContainer;

    // for (int i = 197487; i <= 673251; i++) {
    //     if (validate2(i)) {
    //         answerContainer.insert(i);
    //     }
    // }

    // std::cout << answerContainer.size();
    std::cout << validate2(123444);
    return 0;
}