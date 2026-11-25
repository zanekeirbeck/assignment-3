// CSCI 2350 - Assignment 3
// Name: Zane Keirbeck
// All four classes go in this file. Write each member function inside its class.
#ifndef GRADE_ITEM_H
#define GRADE_ITEM_H

#include <iomanip>
#include <iostream>
#include <string>

// ---------- Task A: GradeItem ----------
// Replace each stub body. Keep the public function headers and the private data members.
class GradeItem
{
private:
    std::string name;
    double earned;
    int possible;
public:
    GradeItem(std::string n, double e, int p) : name(n), earned(e), possible(p)
    {
        // Write this constructor. Use a member initializer list.
        if (earned < 0)
        earned = 0;
        if (earned > possible)
        earned = possible;
    }
    std::string getName() const { return name; }
    double getEarned() const { return earned; }
    int getPossible() const { return possible; }
    virtual double finalPoints() const { return earned; }
    virtual void print() const 
    {
        std::cout << name << ": " << std:: fixed << std::setprecision(1)
                    <<finalPoints() << " / " << possible << "\n";
    }
};

// ---------- Task B ----------

class Lab : public GradeItem
{
    private:
    int lateDays;
    public: 
    Lab(std::string n , double e, int p, int days) : GradeItem(n, e, p), lateDays(days)
    {
        if (lateDays < 0)
        lateDays= 0;
    }
    double finalPoints() const override
    {
        if (lateDays >= 10)
        return 0;
        return getEarned() * (10 - lateDays) / 10;
    
    }
    void print() const override
    {
        std::cout << getName() << ": " << std::fixed << std::setprecision(1)
                  << finalPoints() << " / " << getPossible();
        if (lateDays == 0)
            std::cout << " (on time)\n";
        else if (lateDays == 1)
            std::cout << " (1 day late)\n";
        else
            std::cout << " (" << lateDays << " days late)\n";
    }
};
class Exam : public GradeItem
{
    private:
    int curve;
    public:
    Exam(std::string n, double e, int p, int c) : GradeItem(n, e, p), curve(c)
    {
        if (curve < 0)
        curve = 0;
    }
    double finalPoints() const override
    {
        double points = getEarned() + curve;
        if (points > getPossible())
        points = getPossible();
        return points;
    }
    void print() const override
    {
        std::cout << getName()<< ": " << std::fixed << std::setprecision(1) << finalPoints() << " / " << getPossible();
        if (curve == 0)
        std::cout << " (no curve)\n";
        else
        std::cout << " (curve " << curve << ")\n";
    }
};

// ---------- Task C ----------
// Write class Quiz here.
class Quiz : public GradeItem 
{
    private:
    double retake;
    public:
    Quiz(std::string n, double first, double second, int p) : GradeItem(n, first, p), retake(second)
    {
        if (retake < 0)
        retake = 0;
        if (retake > p)
        retake = p;
    }
    double finalPoints() const override
    {
        if (retake > getEarned())
        return retake;
        return getEarned();
    }
    void print() const override
    {
        std::cout << getName() << ": " << std::fixed << std::setprecision(1)
                  << finalPoints() << " / " << getPossible()
                  << " (best of " << getEarned() << " and " << retake << ")\n";
    }
   
};
#endif
