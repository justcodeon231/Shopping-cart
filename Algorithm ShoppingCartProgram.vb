Algorithm ShoppingCartProgram

    // Step 1: Start
    Start

    // Step 2: Initialize Variables
    Declare items as Dictionary
    Set items = {"Item1": price1, "Item2": price2, ...}
    Declare total_cost as Float
    Set total_cost = 0.0
    Declare discount as Float
    Set discount = 0.0

    // Step 3: Prompt User for Input
    Display "Welcome to the Shopping Cart Program!"
    Declare userName as String
    Display "Please enter your name:"
    Input userName
    Display "Available items for selection:"
    Display items

    // Step 4: Input Number of Items
    Declare numberOfItems as Integer
    Repeat
        Display "Enter the number of different items you want to purchase:"
        Input numberOfItems
        If numberOfItems < 1 Then
            Display "Error: Please enter a valid number of items."
        End If
    Until numberOfItems >= 1

    // Step 5: Loop Through Each Item
    For i from 1 to numberOfItems Do
        // Step 5a: Input Item Selection
        Declare selectedItem as String
        Repeat
            Display "Select an item by name:"
            Input selectedItem
            If selectedItem not in items Then
                Display "Error: Item not found. Please select a valid item."
            End If
        Until selectedItem in items

        // Step 5b: Input Quantity
        Declare quantity as Integer
        Repeat
            Display "Enter the quantity for " + selectedItem + ":"
            Input quantity
            If quantity <= 0 Then
                Display "Error: Please enter a positive integer for quantity."
            End If
        Until quantity > 0

        // Step 5c: Calculate Cost for Current Item
        Declare itemCost as Float
        Set itemCost = items[selectedItem] * quantity
        Set total_cost = total_cost + itemCost
    End For

    // Step 6: Calculate Total Cost
    If total_cost > 100 Then
        Set discount = total_cost * 0.05
        Set total_cost = total_cost - discount
    End If

    // Step 7: Display Final Bill
    Display "Final Bill:"
    Display "Total Cost: " + total_cost
    If discount > 0 Then
        Display "Discount Applied: " + discount
    End If

    // Step 8: Write Final Output to a Text File
    Declare file as File
    Try
        Open file for Writing as "bill.txt"
        Write "Customer Name: " + userName to file
        Write "Total Cost: " + total_cost to file
        If discount > 0 Then
            Write "Discount Applied: " + discount to file
        End If
        Close file
    Catch
        Display "Error: Unable to write to file."
    End Try

    // Step 9: End
    End
