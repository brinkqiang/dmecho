//
// Created by jorgen on 16.10.18.
//

#include "NumberTask.h"
#include <sstream>
#include <algorithm>

void NumberTask::processClientMessage(const AbstractServerClient &client, std::string message) {
    this->extractNumbers(message);

    this->numbers.sort(std::greater<>());

    if (this->numbers.empty()) {
        std::cout << "[Numbers] No numbers in user message" << std::endl;
        return;
    }

    std::cout << "[Numbers] Numbers (desc): ";

    int sum = 0;
    for (const auto &number : this->numbers) {
        std::cout << number << " ";
        sum += number;
    }

    std::cout << std::endl;

    std::cout << "[Numbers] Sum of all numbers: " << sum << std::endl;

    auto min = std::min_element(this->numbers.begin(), this->numbers.end());
    auto max = std::max_element(this->numbers.begin(), this->numbers.end());

    std::cout << "[Numbers] Min element: " << *min << ". Max element: " << *max << std::endl;
}

void NumberTask::extractNumbers(std::string message) {
    std::stringstream ss(message);

    std::string word;

    while (ss >> word) {
        try {
            int number = std::stoi(word);

            if (number >= 0 && number <= 9) {
                this->numbers.push_back(number);
            }
        } catch (const std::exception &e) {
            // Can't convert to number
            continue;
        }
    }
}
