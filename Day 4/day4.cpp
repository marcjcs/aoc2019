#include <bits/stdc++.h>

// PART I
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

// PART II
bool validate2(int n) {
    std::stringstream ss;
    ss << n;
    std::string numStr = ss.str();
    bool adjacentDouble = false;
    bool neverDecrease = true;
    bool moreThanTwice = false;

    int depth = 0;

    for (int i = 0; i < numStr.size() - 1; i++) {
        if (((int)numStr.at(i) - 48) > ((int)numStr.at(i + 1) - 48)) {
            neverDecrease = false;
        }
    }

    for (int i = 0; i < numStr.size(); i += depth + 1) {
        depth = 0;
        for (int j = i + 1; j < numStr.size(); j++) {
            if (((int)numStr.at(i) - 48) == ((int)numStr.at(j) - 48)) {
                depth++;
            } else {
                break;
            }
        }
        if (depth > 1) {
            moreThanTwice = true;
        } else if (depth == 1) {
            adjacentDouble = true;
        }
    }
    if (moreThanTwice && !adjacentDouble) {
        return false;
    }
    return neverDecrease && adjacentDouble;
}

int main() {
    std::set<int> partI;
    std::set<int> partII;

    for (int i = 197487; i <= 673251; i++) {
        if (validate(i)) {
            partI.insert(i);
        }

        if (validate2(i)) {
            partII.insert(i);
        }
    }

    std::cout << "Part I: " << partI.size() << std::endl;
    std::cout << "Part II: " << partII.size() << std::endl;

    return 0;
}