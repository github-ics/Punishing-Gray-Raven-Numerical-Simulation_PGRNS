#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

class Member {
public:
    int ATK;
    double buff[8]; // Updated to 8 buffs

    // Constructor
    Member(int initialATK) : ATK(initialATK) 
	{
        for (int i = 0; i < 8; ++i) 
		{
            buff[i] = 1.0; // Initial buff values set to 1.0
        }
    }
	
    // Function to initialize member's parameters from a text file
    void initializeFromFile(const std::string& filename) 
	{
        std::ifstream file(filename);
        if (file.is_open()) 
		{
            file >> ATK;
            for (int i = 0; i < 8; ++i) 
			{
                file >> buff[i];
            }
            file.close();
        } else 
		{
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
};

class Skill {
public:
    double multiplier;
    int timeCost;
    double buffChange[8]; // Updated to 7 buffs

    Skill(double multi, int cost, double buffChange[]) : multiplier(multi), timeCost(cost) 
	{
        for (int i = 0; i < 8; ++i) 
		{
            this->buffChange[i] = buffChange[i];
        }
    }

    void applyBuff(Member& member) 
	{
        // Apply buff changes from the skill to the member
        for (int i = 0; i < 8; ++i) 
		{
            member.buff[i] = buffChange[i];
        }
    }
};
