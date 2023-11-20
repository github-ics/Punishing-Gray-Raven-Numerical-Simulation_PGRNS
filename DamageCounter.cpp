#include "SubFunction.h"

int SkillDam(Member& member, Skill skill) {
    double sum, a[8] = {0}, Rate, Rate2, Gra, Gra2, BRA, c, x, Double;
    int i = 0;

    Rate2 = round(skill.multiplier);//Specific level magnification, or multiplier displayed in game's skill interface
    Double = 1;//Multiplication changing for times,usually is 1 or 2
    BRA = 2.5;//Basic damage bonus zone
    c = floor(Rate2 * BRA * Double);//10000 times magnification

    a[1] = member.buff[0];//Attack power percentage bonus 
    x = member.buff[1];//Attack power value bonus
    a[2] = c / 10000;//Final magnification related to ATK
    a[3] = member.buff[2];//Attribute damage bonus zone
    a[4] = member.buff[3];//Attribute Resistance Ride Zone Trial Zone 0.7605
    a[5] = member.buff[4];//Additional damage bonus zone
    a[6] = member.buff[5];//Additional Damage Reduction Ride Zone Trial Zone 0.9605
    a[7] = member.buff[6];//Weakness increases damage in the passenger area, such as fragile and flammable

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
        process[i].applyBuff(member);
        Damage[i] = SkillDam(member, process[i]);
    }
}
