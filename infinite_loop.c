#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Espresso constants definition
#define e_coffeebeans 8          
#define e_water 30          
#define e_milk 0             
#define e_chocolatesyrup 0       
float e_price = 3.5;   
// Cappuccino constants definition
#define c_coffeebeans 8          
#define c_water 30            
#define c_milk 70            
#define c_chocolatesyrup 0       
float c_price = 4.5;     
// Mocha constants definition
#define m_coffeebeans 8          
#define m_water 39       
#define m_milk 160      
#define m_chocolatesyrup 30      
float m_price = 5.5;
// Threshold values
float threshold_coffee = 30;    
float threshold_water = 120;
float threshold_milk = 300;
float threshold_choco = 40;     

#define admin_pass "coffee123"   // Admin password
float total = 0;                 // Initialize total sales to 0

// Function prototypes 
int order();
int payment(float to_pay);
int admin();
// Main function 
int main() {
  int choice;  // Variable to store the user's menu choice
  while (1) {  // Infinite loop to keep the program running until user chooses to exit
    // Main menu options
    printf("\n\n** MENU **\n");
    printf("1. Coffee Order\n");
    printf("2. Admin Mode\n");
    printf("3. Exit\n");
    printf("Enter your choice(1/2/3): ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        order(); // Calls the order function for customer ordering coffee 
        break;
      case 2:
        admin(); // Calls the admin function for accessing admin options
        break;
      case 3:
        printf("Thank you for using the machine!\n"); // Exit message
        return 0; // End program
      default:
        printf("Please enter choice from menu(1/2/3)!\n"); // Invalid choice message
        break;
    }
  }
  return 0;
}

// Coffee order function
int order() {
    int order_ch;  // Variable to store coffee choice

    // Coffee options and prices menu
    printf("\n\n** MENU **\n");
    printf("1. Espresso %.1f\n", e_price);
    printf("2. Cappuccino %.1f\n", c_price);
    printf("3. Mocha %.1f\n", m_price);
    printf("4. Exit\n");
    printf("Enter your choice(1/2/3/4): ");
    scanf("%d", &order_ch);
    
    // Process the selected coffee order
    switch(order_ch) {
      case 1:
        printf("\nEspresso cost: %.2f dhs\n", e_price);
        // Checks if ingredients are sufficient for Espresso
        if (e_coffeebeans <= threshold_coffee && e_water <= threshold_water) {
          printf("Espresso in making!\n\n");
          payment(e_price); // Processes payment using payment function

          // Deducts ingredient quantities
          threshold_coffee -= e_coffeebeans;
          threshold_water -= e_water;
        } else {
          printf("Espresso is currently unavailable due to insufficient ingredients!\n\n");
        }
        break;

      case 2: 
        printf("\nCappuccino cost: %.2f dhs\n", c_price);
        // Checks if ingredients are sufficient for Cappuccino
        if (c_coffeebeans <= threshold_coffee && c_water <= threshold_water && c_milk <= threshold_milk) {
          printf("Cappuccino in making!\n\n");
          payment(c_price); // Processes payment using payment function

          // Deduct ingredient quantities
          threshold_coffee -= c_coffeebeans;
          threshold_water -= c_water;
          threshold_milk -= c_milk;
        } else {
          printf("Cappuccino is currently unavailable due to insufficient ingredients!\n\n");
        }
        break;

      case 3:
        printf("\nMocha cost: %.2f dhs\n", m_price);
        // Check if ingredients are sufficient for Mocha
        if (m_coffeebeans <= threshold_coffee && m_water <= threshold_water && m_milk <= threshold_milk && m_chocolatesyrup <= threshold_choco) {
          printf("Mocha in making!\n\n");
          payment(m_price); // Processes payment using payment function

          // Deduct ingredient quantities 
          threshold_coffee -= m_coffeebeans;
          threshold_water -= m_water;
          threshold_milk -= m_milk;
          threshold_choco -= m_chocolatesyrup;
        } else {
          printf("Mocha is currently unavailable due to insufficient ingredients!\n\n");
        }
        break;

      case 4:
        printf("Exit!\nThank you!"); // Exits order mode
        break;
             
      default:
        printf("Invalid choice\n"); // Displays if there is an invalid order selection
        break;
    }
    return 0;
}

// Payment Function
int payment(float to_pay) {
  float pay = 0;  // Initialize amount paid by the customer to 0
  float amount;   // Variable to store each coin inserted

  // Prompt customer to pay with coins (1 dhs or 0.5 dhs coins)
  printf("\nPay in coins. Enter 1 for 1 dhs and 0.5 for 0.5 dhs.\n\n");
  while (pay < to_pay) {  // Loop continues until the customer pays the required amount
    printf("Enter 1 to insert 1 dhs and 0.5 to insert 0.5 dhs: ");
    scanf("%f", &amount);
    if (amount == 1) {
      pay += 1;
    } else if (amount == 0.5) {
      pay += 0.5;
    } else {
      printf("Invalid coin!\n\n"); // Informs customer of invalid input
    }
  }

  // Returns any change if the customer overpays
  if (pay > to_pay) {
    float change = pay - to_pay;
    printf("\nYour change is %.1f\n", change);
  }
  
  total += to_pay; // Adds to the total sales
  printf("Payment Completed! \nThank you!\n\n"); // Payment success
  return 0;
}

// Admin function
int admin() {
    char pass[50];  // stores entered password
    int mode_ch;    // stores admin menu choice
    printf("Enter admin password: ");
    scanf("%s", pass);

    // Checks if the entered password matches the defined admin password
    if (strcmp(pass, admin_pass) == 0) {
      printf("Login is Successful!!\n\n");
      
      // Admin mode menu
      while (1) {
        printf("\nAdmin Mode Menu\n");
        printf("1. Display Quantity and Total Sale\n");
        printf("2. Replenish Ingredients in the machine\n");
        printf("3. Change Coffee Price\n");
        printf("4. Exit Admin Mode\n");
        printf("Enter choice (1/2/3/4): ");
        scanf("%d", &mode_ch);

        switch(mode_ch) {
          case 1:
            // Displays current ingredient levels and total sales
            printf("Displaying Quantity and Total Sale\n\n");
            printf("Current Quantity of Coffee is %.2f g\n", threshold_coffee);
            printf("Current Quantity of Water is %.2f ml\n", threshold_water);
            printf("Current Quantity of Milk is %.2f ml\n", threshold_milk);
            printf("Current Quantity of Chocolate Syrup is %.2f ml\n", threshold_choco);
            printf("The total sales are %.2f dhs\n", total);
            break;
          
          case 2:
            // Replenishes ingredients
            int replenish_ch;
            float quantity_new;
            printf("Replenish Ingredients\n\n");
            printf("1. Coffee Beans\n");
            printf("2. Water\n");
            printf("3. Milk\n");
            printf("4. Chocolate Syrup\n");
            printf("5. Exit\n");
            printf("Select the item to replenish (1/2/3/4/5): ");
            scanf("%d", &replenish_ch);

            // Adds the specified quantity to the selected ingredient
            switch (replenish_ch){
              case 1:
                printf("Enter the quantity to add for Coffee Beans (in g): ");
                scanf("%f", &quantity_new);
                threshold_coffee += quantity_new;
                printf("The quantity of Coffee Beans is now %.2f g\n", threshold_coffee);
                break;
              case 2:
                printf("Enter the quantity to add for Water (in ml): ");
                scanf("%f", &quantity_new);
                threshold_water += quantity_new;
                printf("The quantity of Water is now %.2f ml\n", threshold_water);
                break;
              case 3:
                printf("Enter the quantity to add for Milk (in ml): ");
                scanf("%f", &quantity_new);
                threshold_milk += quantity_new;
                printf("The quantity of Milk is now %.2f ml\n", threshold_milk);
                break;
              case 4:
                printf("Enter the quantity to add for Chocolate Syrup (in ml): ");
                scanf("%f", &quantity_new);
                threshold_choco += quantity_new;
                printf("The quantity of Chocolate Syrup is now %.2f ml\n", threshold_choco);
                break;
              case 5:
                printf("Exit replenishing!\n");
                break;
              default:
                printf("Invalid input!\n");
                break;
            }
            break;
          
          case 3:
            // Changes the prices of coffee items
            int item_change_value;
            float price_change_value;
            printf("Change Coffee Price\n\n");
            printf("1. Espresso %.1f\n", e_price);
            printf("2. Cappuccino %.1f\n", c_price);
            printf("3. Mocha %.1f\n", m_price);
            printf("Select the item to change price (1/2/3): ");
            scanf("%d", &item_change_value);

            // Updates price based on selected coffee type
            switch (item_change_value){
              case 1:
                printf("Enter the new price for Espresso: ");
                scanf("%f", &price_change_value);
                e_price = price_change_value;
                printf("The new price of Espresso is %.2f\n", e_price);
                break;
              case 2:
                printf("Enter the new price for Cappuccino: ");
                scanf("%f", &price_change_value);
                c_price = price_change_value;
                printf("The new price of Cappuccino is %.2f\n", c_price);
                break;
              case 3:
                printf("Enter the new price for Mocha: ");
                scanf("%f", &price_change_value);
                m_price = price_change_value;
                printf("The new price of Mocha is %.2f\n", m_price);
                break;
              default:
                printf("Invalid input!\n");
                break;
            }
            break;
          
          case 4:
            printf("Exiting Admin Mode\n"); // Exits admin mode
            return 0; 
            
          default:
            printf("Invalid choice\n");
            break;
        }
      }
    }
    else {
      printf("Login is unsuccessful\n\n"); // Incorrect password message
    }
    return 0;
}
