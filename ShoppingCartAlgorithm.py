# Constants
num_students = 5
scores = []

# Input scores using a loop
print(f"Enter the scores for {num_students} students:")
for i in range(num_students):
    score = int(input(f"Enter score for student {i + 1}: "))
    scores.append(score)

# Calculate the average, highest, and lowest scores
total = sum(scores)
average = total / num_students
highest = max(scores)
lowest = min(scores)

# Display scores in the order they were entered
print("\nScores entered:")
for i, score in enumerate(scores):
    print(f"Student {i + 1}: {score}")

# Display average, highest, and lowest scores
print(f"\nAverage score: {average:.2f}")
print(f"Highest score: {highest}")
print(f"Lowest score: {lowest}")
