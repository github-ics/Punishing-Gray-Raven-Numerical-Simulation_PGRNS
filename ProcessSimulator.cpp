#include <iostream>
#include <vector>
#include <cmath>
#include "SubFunction.h"
#include "DataClass.h"

int main() {
    Member player(100);
    //player.initializeFromExcel("member_parameters.xlsx");
    player.initializeFromTxt("Qiming_parameters.txt");

	//{multiplier,cost,{buffs}} 
    std::vector<Skill> skills = {
        {30000*35/34, 2, {59.76, 250.0, 71.76, -12.0, 62.59, 23.53, -70.0}},
        {1.5, 2, {10.2, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0}},
        {2.0, 3, {0.0, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0}}
    };

    const int maxSkills = skills.size();
    std::vector<int> Damage(maxSkills, 0);

    Damcounter(player, skills, maxSkills, Damage);

    for (int i = 0; i < maxSkills; ++i) {
        std::cout << "Skill " << i + 1 << " Damage: " << Damage[i] << std::endl;
    }

    return 0;
}
