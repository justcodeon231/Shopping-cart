# Step 2: Initialize Variables
items = {
    "Apple": 1.50,
    "Banana": 0.75,
    "Milk": 2.00,
    "Bread": 1.25,
    "Eggs": 3.00
}

total_cost = 0.0
discount = 0.0

# Step 3: Welcome message and user name input
print("Welcome to the Shopping Cart Program!")
user_name = input("Please enter your name: ")

# Display available items
print("Available items for selection:")
for item, price in items.items():
    print(f"- {item}: ${price:.2f}")

# Step 4: Input Number of Items
while True:
    try:
        number_of_items = int(input("Enter the number of different items you want to purchase: "))
        if number_of_items < 1:
            print("Error: Please enter a valid number of items.")
        else:
            break
    except ValueError:
        print("Error: Please enter a valid integer.")

# Step 5: Loop Through Each Item
for i in range(number_of_items):
    # Step 5a: Input Item Selection
    while True:
        selected_item = input("Select an item by name: ")
        if selected_item not in items:
            print("Error: Item not found. Please select a valid item.")
        else:
            break

    # Step 5b: Input Quantity
    while True:
        try:
            quantity = int(input(f"Enter the quantity for {selected_item}: "))
            if quantity <= 0:
                print("Error: Please enter a positive integer for quantity.")
            else:
                break
        except ValueError:
            print("Error: Please enter a valid integer.")

    # Step 5c: Calculate Cost for Current Item
    item_cost = items[selected_item] * quantity
    total_cost += item_cost

# Step 6: Calculate Total Cost
if total_cost > 100:
    discount = total_cost * 0.05
    total_cost -= discount

# Step 7: Display Final Bill
print("Final Bill:")
print(f"Total Cost: ${total_cost:.2f}")
if discount > 0:
    print(f"Discount Applied: ${discount:.2f}")

# Step 8: Write Final Output to a Text File
try:
    with open("bill.txt", "w") as file:
        file.write(f"Customer Name: {user_name}\n")
        file.write(f"Total Cost: ${total_cost:.2f}\n")
        if discount > 0:
            file.write(f"Discount Applied: ${discount:.2f}\n")
except IOError:
    print("Error: Unable to write to file.")
