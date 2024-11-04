#include <iostream>
#include <limits>

int main() {
    const int numStudents = 5;
    int scores[numStudents];
    int sum = 0;
    int highest = std::numeric_limits<int>::min();
    int lowest = std::numeric_limits<int>::max();

    // Input scores using a loop
    std::cout << "Enter the scores for " << numStudents << " students:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter score for student " << i + 1 << ": ";
        std::cin >> scores[i];

        // Add the current score to the sum
        sum += scores[i];

        // Check if the current score is the highest
        if (scores[i] > highest) {
            highest = scores[i];
        }

        // Check if the current score is the lowest
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    // Calculate average
    double average = static_cast<double>(sum) / numStudents;

    // Display scores in the order they were entered
    std::cout << "\nScores entered:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Student " << i + 1 << ": " << scores[i] << "\n";
    }

    // Display average, highest, and lowest scores
    std::cout << "\nAverage score: " << average << "\n";
    std::cout << "Highest score: " << highest << "\n";
    std::cout << "Lowest score: " << lowest << "\n";

    return 0;
}