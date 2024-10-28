#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include "RpgHeader.h"
#include "gamble.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#pragma warning(disable:4996)
#pragma warning(disable:4244)
using namespace std;

void printLoss(treeLoss* root)
{
    if (root == NULL)
    {
        return;
    }
    printLoss(root->left);
    cout << RED "-" << root->money << RESET << endl;
    printLoss(root->right);
}

void printWin(treeWin* root)
{
    if (root == NULL)
    {
        return;
    }
    printWin(root->left);
    cout << GREEN "+" << root->money << RESET << endl;
    printWin(root->right);
}

void biggestWin(treeWin* root)
{
    if (root == NULL)
    {
        cout << "No wins recorded." << endl;
        return;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << "Biggest win: " << root->money << endl;
}

void biggestLoss(treeLoss* root)
{
    if (root == NULL)
    {
        cout << "No losses recorded." << endl;
        return;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << "Biggest loss: " << root->money << endl;
}

int calculateWinSum(treeWin* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->money + calculateWinSum(node->left) + calculateWinSum(node->right);
}

int calculateLossSum(treeLoss* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->money + calculateLossSum(node->left) + calculateLossSum(node->right);
}

int totalProfit(treeWin* winRoot, treeLoss* lossRoot)
{
    int totalWin = calculateWinSum(winRoot);
    int totalLoss = calculateLossSum(lossRoot);
    return totalWin - totalLoss;
}


void gambleMenu(Player& mainCharacter)
{
    int choice;
    int profit = 0;
    int deposits = 0;
    treeLoss* lossRoot = NULL;
    treeWin* winRoot = NULL;
    char continuePlaying;
    while (true)
    {
        system("cls");
        cout << "Welcome to the Gambling Game" << endl;
        cout << "Please choose an option" << endl;
        cout << "1. Play" << endl;
        cout << "2. Check balance" << endl;
        cout << "3. Check biggest win" << endl;
        cout << "4. Check biggest loss" << endl;
        cout << "5. Check total profit" << endl;
        cout << "6. Check all bets" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        int scan = scanf("%d", &choice);
        while (scan == 0 || (choice < 1 || choice > 8))
        {
            cout << "Invalid choice. Please enter a valid choice: ";
            while (getchar() != '\n'); // clear invalid input
            scan = scanf("%d", &choice);
        }

        switch (choice)
        {
        case 1:
            gambleGamesOptions(mainCharacter, lossRoot, winRoot);
            break;

        case 2:
            system("cls");
            cout << "Your balance is: " << mainCharacter.getGold() << endl;
            cout << "Press any key to continue" << endl;
            continuePlaying = _getch();
            break;
        case 3:
            system("cls");
            biggestWin(winRoot);
            cout << "Press any key to continue" << endl;
            continuePlaying = _getch();
            break;
        case 4:
            system("cls");
            biggestLoss(lossRoot);
            cout << "Press any key to continue" << endl;
            continuePlaying = _getch();
            break;
        case 5:
            profit = totalProfit(winRoot, lossRoot);
            system("cls");
            cout << "Total profit: ";
            if (profit > 0)
            {
                cout << GREEN "+" << profit << RESET << endl;
            }
            else
            {
                cout << RED << profit << RESET << endl;
            }
            cout << RED << "Total deposits: $" << deposits << RESET << endl;
            cout << "Press any key to continue" << endl;
            continuePlaying = _getch();
            break;
        case 6:
            system("cls");
            printLoss(lossRoot);
            printWin(winRoot);
            cout << "Press any key to continue" << endl;
            continuePlaying = _getch();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void gambleGamesOptions(Player mainCharacter, treeLoss*& loss, treeWin*& win)
{
    system("cls");
    int choice;
    cout << "Please choose a game to play" << endl;
    cout << "1. Higher or Lower" << endl;
    cout << "2. Black Jack" << endl;
    cout << "3. Slot Machine" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    int scan = scanf("%d", &choice);
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "Invalid choice. Please enter a valid choice: ";
        scan = scanf("%d", &choice);
        if (scan == 0)
        {
            cout << "Invalid choice. Please enter a valid choice: ";
            while (getchar() != '\n');
            scan = scanf("%d", &choice);
        }
    }
    switch (choice)
    {
    case 1:
        higherOrLower(mainCharacter, loss, win);
        break;
    case 2:
        blackJack(mainCharacter, loss, win);
        break;
    case 3:
        runSlotMachine(mainCharacter, loss, win);
        break;
    case 4:
        break;
    }
}

void higherOrLower(Player mainCharacter, treeLoss*& loss, treeWin*& win)
{
    system("cls");
    cout << "Your balance is: " << mainCharacter.getGold() << endl;
    int howMuch;
    cout << "How much would you like to bet: ";
    int scan = scanf("%d", &howMuch);
    if (scan == 0)
    {
        cout << "Invalid amount. Please enter a valid amount: ";
        while (getchar() != '\n');
        scan = scanf("%d", &howMuch);
    }
    while (howMuch > mainCharacter.getGold())
    {
        cout << "You do not have enough money to bet that amount. Please enter a valid amount: ";
        scan = scanf("%d", &howMuch);
    }
    cout << "Select Red or Black" << endl;
    cout << "1. Red" << endl;
    cout << "2. Black" << endl;
    srand(time(NULL));
    int randomBlack = rand() % 1000 + 1;
    int choice;
    scan = scanf("%d", &choice);
    while (choice != 1 && choice != 2)
    {
        cout << "Invalid choice. Please enter a valid choice: ";
        scan = scanf("%d", &choice);
        if (scan == 0)
        {
            cout << "Invalid choice. Please enter a valid choice: ";
            while (getchar() != '\n');
            scan = scanf("%d", &choice);
        }
    }
    int randomRed = rand() % 1000 + 1;
    cout << randomRed << " People have chosen Red" << endl;
    cout << randomBlack << " People have chosen Black" << endl;
    if (choice == 1)
    {
        if (randomRed > randomBlack)
        {
            cout << "You have won: " << howMuch * 2 << endl;
            win = insertWinNode(win, howMuch);
            mainCharacter.setGold(mainCharacter.getGold() + howMuch);
        }
        else
        {
            cout << "You have lost " << howMuch << endl;
            loss = insertLossNode(loss, howMuch);
            mainCharacter.setGold(mainCharacter.getGold() - howMuch);
        }
    }
    else if (choice == 2)
    {
        if (randomBlack > randomRed)
        {
            cout << "You have won: " << howMuch * 2 << endl;
            win = insertWinNode(win, howMuch);
            mainCharacter.setGold(mainCharacter.getGold() + howMuch);
        }
        else
        {
            cout << "You have lost " << howMuch << endl;
            loss = insertLossNode(loss, howMuch);
            mainCharacter.setGold(mainCharacter.getGold() - howMuch);
        }
    }
    char continuePlaying;
    cout << "Press any key to continue" << endl;
    continuePlaying = _getch();
}

int getCardValue()
{
    int card = rand() % 13 + 1;
    return card;
}

int calculateHandValue(const std::vector<int>& hand)
{
    int value = 0;
    int aces = 0;
    for (int card : hand)
    {
        if (card == 1)
        {
            aces++;
            value += 11;  // Assume ace is worth 11 initially
        }
        else if (card > 10)
        {
            value += 10;  // Face cards are worth 10
        }
        else
        {
            value += card;
        }
    }

    // Adjust for aces if the value exceeds 21
    while (value > 21 && aces > 0)
    {
        value -= 10;
        aces--;
    }

    return value;
}

void printHand(const std::vector<int>& hand, bool hideCard)
{
    for (size_t i = 0; i < hand.size(); i++)
    {
        if (hideCard)
        {
            cout << "[Hidden] ";
        }
        else
        {
            if (hand[i] == 1)
            {
                cout << "[A] ";
            }
            else if (hand[i] == 11)
            {
                cout << "[J] ";
            }
            else if (hand[i] == 12)
            {
                cout << "[Q] ";
            }
            else if (hand[i] == 13)
            {
                cout << "[K] ";
            }
            else
            {
                cout << "[" << hand[i] << "] ";
            }
        }
    }
    cout << endl;
}

void blackJack(Player mainCharacter, treeLoss*& loss, treeWin*& win)
{
    system("cls");
    cout << "Your balance is: " << mainCharacter.getGold() << endl;
    int bet;
    cout << "Enter your bet: ";
    int scan = scanf("%d", &bet);
    while (scan == 0 || bet > mainCharacter.getGold() || bet <= 0)
    {
        cout << "Invalid bet. Please enter a valid amount: ";
        while (getchar() != '\n');
        scan = scanf("%d", &bet);
    }

    std::vector<int> playerHand;
    std::vector<int> dealerHand;

    playerHand.push_back(getCardValue());
    playerHand.push_back(getCardValue());
    dealerHand.push_back(getCardValue());
    dealerHand.push_back(getCardValue());

    bool playerStand = false;

    while (!playerStand)
    {
        system("cls");
        cout << "Dealer's hand: ";
        printHand(dealerHand, true);
        cout << "Your hand: ";
        printHand(playerHand, false);
        cout << "Your hand value: " << calculateHandValue(playerHand) << endl;

        cout << "Do you want to hit or stand? (h/s): ";
        char choice;
        cin >> choice;
        if (choice == 'h' || choice == 'H')
        {
            playerHand.push_back(getCardValue());
            if (calculateHandValue(playerHand) > 21)
            {
                break;
            }
        }
        else if (choice == 's' || choice == 'S')
        {
            playerStand = true;
        }
    }

    while (calculateHandValue(dealerHand) < 17 || (calculateHandValue(dealerHand) <= calculateHandValue(playerHand) && calculateHandValue(dealerHand) <= 21))
    {
        dealerHand.push_back(getCardValue());
    }

    int playerValue = calculateHandValue(playerHand);
    int dealerValue = calculateHandValue(dealerHand);

    system("cls");
    cout << "Dealer's hand: ";
    printHand(dealerHand, false);
    cout << "Dealer's hand value: " << dealerValue << endl;
    cout << "Your hand: ";
    printHand(playerHand, false);
    cout << "Your hand value: " << playerValue << endl;

    if (playerValue > 21)
    {
        cout << "You bust! You lose " << bet << "." << endl;
        loss = insertLossNode(loss, bet);
        mainCharacter.setGold(mainCharacter.getGold() - bet);
    }
    else if (dealerValue > 21 || playerValue > dealerValue)
    {
        cout << "You win! You gain " << bet << "." << endl;
        win = insertWinNode(win, bet);
        mainCharacter.setGold(mainCharacter.getGold() + bet);
    }
    else if (playerValue < dealerValue)
    {
        cout << "Dealer wins! You lose " << bet << "." << endl;
        loss = insertLossNode(loss, bet);
        mainCharacter.setGold(mainCharacter.getGold() - bet);
    }
    else
    {
        cout << "It's a tie! You get your bet back." << endl;
    }

    char continuePlaying;
    cout << "Press any key to continue...";
    continuePlaying = _getch();
}

void rollAnimation(char& slot1, char& slot2, char& slot3)
{
    const char symbols[] = { '7', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    int duration = 50; // number of iterations for the animation

    for (int i = 0; i < duration; ++i)
    {
        slot1 = symbols[rand() % 8];
        std::cout << "\r[" << slot1 << "] [ ] [ ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        slot2 = symbols[rand() % 8];
        std::cout << "\r[" << slot1 << "] [" << slot2 << "] [ ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        slot3 = symbols[rand() % 8];
        std::cout << "\r[" << slot1 << "] [" << slot2 << "] [" << slot3 << "]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// Function to run the slot machine
void runSlotMachine(Player mainCharacter, treeLoss*& loss, treeWin*& win)
{
    srand(time(0)); // Seed for random number generation
    int continuePlaying;
    char slot1, slot2, slot3;

    cout << "Welcome to the Slot Machine!" << endl;
    cout << "Your balance is: " << mainCharacter.getGold() << endl;
    cout << "Enter your bet: ";
    int bet;
    int scan = scanf("%d", &bet);

    while (scan == 0 || bet > mainCharacter.getGold() || bet < 0)
    {
        cout << "Invalid bet. Please enter a valid amount: ";
        while (getchar() != '\n');
        scan = scanf("%d", &bet);
    }
    cout << "Press Enter to roll the slots...";
    continuePlaying = _getch();

    // Roll each slot with animation
    cout << "\nRolling...\n";
    rollAnimation(slot1, slot2, slot3);
    cout << endl;

    // Display final result
    cout << "Result: " << slot1 << " " << slot2 << " " << slot3 << endl;

    // Check if the player wins
    if (slot1 == slot2 && slot2 == slot3)
    {
        cout << "Congratulations! You win!" << endl;
        mainCharacter.setGold(mainCharacter.getGold() + bet * 77);
        win = insertWinNode(win, bet * 10);
    }
    else
    {
        cout << "Sorry, you lose. Better luck next time!" << endl;
        mainCharacter.setGold(mainCharacter.getGold() - bet);
        loss = insertLossNode(loss, bet);
    }

    cout << "Press any key to continue...";
    continuePlaying = _getch();
}