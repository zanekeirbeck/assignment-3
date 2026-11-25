// CSCI 2350 - Assignment 3 - Task C
// Name: Zane Keirbeck
// Report functions. Keep these function headers. Do not add main to this file.
#include <iomanip>
#include <iostream>
#include <string>
#include "grade_item.h"

double totalPoints(const GradeItem* items[], int count)
{
    // Replace this stub.
    if (items == nullptr || count <= 0)
    return 0;
    double total = 0;
    for (int i= 0; i < count; i++)
    total += items[i]->finalPoints();
    return total;
}

int totalPossible(const GradeItem* items[], int count)
{
    // Replace this stub.
    if (items == nullptr || count <= 0)
        return 0;
    int total = 0;
    for (int i = 0; i < count; ++i)
        total += items[i]->getPossible();
    return total;
}

char letterGrade(double percent)
{
    // Replace this stub.
    if (percent < 0)
        return '?';
    if (percent >= 90)
        return 'A';
    if (percent >= 80)
        return 'B';
    if (percent >= 70)
        return 'C';
    if (percent >= 60)
        return 'D';
    return 'F';
}

void printReport(const std::string& title, const GradeItem* items[], int count)
{
    // Replace this stub.
    std::cout << title << "\n";
    if (items == nullptr || count <= 0)
    {
        std::cout << "No grade items\n";
        return;
    }
    for (int i = 0; i < count; ++i)
        items[i]->print();
    double points = totalPoints(items, count);
    int possible = totalPossible(items, count);
    double percent = 100 * points / possible;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Total: " << points << " / " << possible << "\n";
    std::cout << "Percent: " << percent << "\n";
    std::cout << "Letter: " << letterGrade(percent) << "\n";
}
