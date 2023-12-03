#include "SubFunction.h"

int SkillDam(Member& member, Skill skill) {
    double sum, a[8] = {0}, Rate, Rate2, Gra, Gra2, BRA, c, x, Double;
    int i = 0;

    Rate2 = round(skill.multiplier);//Specific level magnification, or multiplier displayed in game's skill interface
    Double = 1;//Multiplication changing for times,usually is 1 or 2
    BRA = 2.5;//Basic damage bonus zone
    c = floor(Rate2 * BRA * Double);//10000 times magnification

    a[1] = 1.0000+member.buff[0]/100;//Attack power percentage bonus 
    x = member.buff[1];//Attack power value bonus
    a[2] = c / 10000;//Final magnification related to value of ATK
    a[3] = 1.0000+member.buff[2]/100;//Attribute damage bonus Zone
    a[4] = 1.0000+member.buff[3]/100;//Attribute Resistance Ride Zone, Trial Zone a[4]=0.7605
    a[5] = 1.0000+member.buff[4]/100;//Additional damage bonus Zone
    a[6] = 1.0000+member.buff[5]/100;//Additional Damage Reduction Ride Zone, Trial Zone a[6]0.9605
    a[7] = 1.0000+member.buff[6]/100;//Weakness increases damage in the passenger Zone, such as fragile and flammable

    sum = member.ATK;
    for (i = 1; i < 7; i++) {
        sum = floor(sum * a[i]);
        if (i == 1) {
            sum = sum + x;
        }
    }
    sum = ceil(sum * a[7]);

    return static_cast<int>(sum);
}

void Damcounter(Member& member, std::vector<Skill>& process, const int steps, std::vector<int>& Damage) {
    for (int i = 0; i < steps; ++i) {
    	//applys buffs on character
    	Member case_now=process[i].applyBuff(member);//this version does not consider about lifetime of buffs
        Damage[i] = SkillDam(case_now, process[i]);
    }
}
