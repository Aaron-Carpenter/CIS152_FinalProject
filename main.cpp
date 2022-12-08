#include <iostream>
#include <limits>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class inputPrompt { // Class input prompt is essentially responsible for all user input, validation of that input, and sorting
private:
    int flavorChoice = 1; // Default flavorChoice is 1 **This does not mean that it automatically adds a flavor to the order**
    stack<int> order;

    string firstName;
    string lastName;
    string phoneNumber;

    priority_queue<string> customerInfo;
public:
    inputPrompt(string inFirstName, string inLastName, string inPhoneNumber) { // Constructor that accepts beginning user details
            firstName = inFirstName;
            lastName = inLastName;
            phoneNumber = inPhoneNumber;

            customerInfo.push(firstName); // Pushing details into priority queue
            customerInfo.push(lastName);
            customerInfo.push(phoneNumber);

            flavorChoice = 1; // Condition so that upon re-execution of function, while loop below will run

            while (flavorChoice != 4 && flavorChoice > 0 && flavorChoice < 4) { // Re-confirming valid input was entered
            cout << "1 - Chocolate Blueberry Swirl" << endl;
            cout << "2 - Rainbow Sherbert Deluxe" << endl;
            cout << "3 - Peaches and Cream" << endl;
            cout << "4 - End Order" << endl;

            cout << "Enter flavor to add to order: " << endl;
            cin >> flavorChoice;
            if (!cin.fail() && flavorChoice > 0 && flavorChoice < 4) {
                order.push(flavorChoice);
            }

            else if (flavorChoice == 4) { // End order
                cout << "Order ended..." << endl;
            }

            while((flavorChoice > 4 || flavorChoice < 1) && flavorChoice != 4) { // If wrong number is entered re-enter input
                cout << "Wrong number inputted, please re-enter number: " << endl;
                cin >> flavorChoice;
                if (flavorChoice > 0 && flavorChoice < 4) {
                    order.push(flavorChoice);
                }
            }
        }
    }



    void printOrder() { // Prints the order
        while (!order.empty()) {
            cout << order.top() << " ";
            order.pop();
        }
        cout << endl; // Just a separator
    }

    void printStack(stack<int> userStack) { // Method for printing stacks
        while (!userStack.empty()) {
            cout << userStack.top() << " ";
            userStack.pop();
        }
    }

    stack<int> sortScoop() { // Sort scoop is a specially made sort method that is instrumental in displaying exactly how many scoops of each flavor is on the cone
        stack<int> sortedOrder;
        stack<int> burnerStack1 = order; // Burner stacks are necessary so that each individual variable can sort through its own seperate stack, looking for its specific number
        stack<int> burnerStack2 = order;
        stack<int> burnerStack3 = order;

        while (!burnerStack1.empty()) {
            if (burnerStack1.top() == 1) {
                sortedOrder.push(1);
            }
            burnerStack1.pop();
        }

        while (!burnerStack2.empty()) {
            if (burnerStack2.top() == 2) {
                sortedOrder.push(2);
            }
            burnerStack2.pop();
        }

        while (!burnerStack3.empty()) {
            if (burnerStack3.top() == 3) {
                sortedOrder.push(3);
            }
            burnerStack3.pop();
        }


        return sortedOrder; // The sort scoop function returns a stack instead of directly printing output
    }

    string getFullName() { // Get method for full name
        return firstName + " " + lastName;
    }

    string getPhoneNumber() { // Get method for phone number
        return phoneNumber;
    }

    void showQueue() // Show queue shows prioritized information usually in this form, Last Name, First Name, Phone Number
    {
        priority_queue<string> g = customerInfo;
        while (!g.empty()) {
            cout << ' ' << g.top();
            g.pop();
        }
        cout << '\n';
    }
};

int main() { // Input creates the essential driver of this whole program, including assigning the beginning user details
    inputPrompt jordan("Jordan", "Smith", "515-333-4444"); // Assigning the default user details to a priority queue

    cout << "Full Name: " << jordan.getFullName() << endl; // Demonstrating my get method for the name
    cout << "Phone Number: " << jordan.getPhoneNumber() << endl; // Demonstrating my get method for the phone number
    cout << "Sorted Order: ";
    jordan.printStack(jordan.sortScoop()); // Sorted order

    cout << endl; // Splitter
    cout << endl; // Divider
    cout << "Prioritized Customer Information (In-order): " << endl;
    jordan.showQueue(); // Show

}
