#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include "SubFunction.h"

using namespace std;

/*
//only for native test
void action(Member& member, Skill* process, int* Damage) 
{
    int currentDamage = member.ATK;

    for (int i = 0; process[i].multiplier != 0.0; ++i) 
	{
        // Apply buff changes from the skill
        process[i].applyBuff(member);

        // Calculate damage and store in Damage array
        Damage[i] = static_cast<int>(currentDamage * process[i].multiplier);

        // Reduce time cost from the member's ATK (just a simple example)
        member.ATK -= process[i].timeCost;
    }
}
*/

int main() 
{
    // Example usage
    Member player(100); // Initialize player with ATK 100

    // Initialize member's parameters from a text file
    player.initializeFromFile("member_parameters.txt");

    // Example skill sequence
    double  b1[8]={10.2, 10.1, 10.3, 10.0, 1.0, 10.0, 0.01, 10.0};
    double  b2[8]={0.0, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double  b3[8]={0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Skill s1(1.5, 2, b1);
	Skill s2(2.0, 3, b2);
	Skill s3(0.1, 1, b3); 
	Skill skills[] = {s1,s2,s3};

    const int maxSkills =  sizeof(skills)/sizeof(skills[0]); //maximum of skills 
    int Damage[maxSkills] = {0};
	
	//compute the total damage
    Damcounter(player, skills, maxSkills, Damage);

    // Print the damage results
    for (int i = 0; i<maxSkills; ++i) 
	{
        std::cout << "Skill " << i + 1 << " Damage: " << Damage[i] << std::endl;
    }

    return 0;
}
