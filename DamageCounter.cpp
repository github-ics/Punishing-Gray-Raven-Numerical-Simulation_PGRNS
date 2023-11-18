#include<stdio.h>
#include<math.h>

#include "SubFunction.h"

using namespace std;

int SkillDam(Member& member, Skill skill);

void Damcounter(Member& member, Skill* process,const int steps, int* Damage)
{
	int currentDamage = member.ATK;

    for (int i = 0; i<steps; ++i) 
	{
        // Apply buff changes from the skill
        printf("%d\n",i);
        process[i].applyBuff(member);

        // Calculate damage and store in Damage array
        printf("%lf\n",process[i].buffChange[0]);
        Damage[i] = SkillDam(member,process[i]);
    }
}

//In this vertion i only use skill.multiplier,but more parameter may be used in following vertions.~(*.^)'~
//So I do give the function whole object
int SkillDam(Member& member, Skill skill)
{
	
	double sum,a[8]={0},Rate,Rate2,Gra,Gra2,BRA,c,x,Double;
	int i=0;
	
	//Rate=66.666666;//18级倍率完整数据，33，67结尾要666666, played in percentile units,XX.XX here means XX.XX%
	//Gra=19;//技能等级
	//Gra2=Gra+16;//basic muliplier for level 1?
	Rate2=round(skill.multiplier);//特定等级倍率, or mutiplier played in game's skill interface
	Double=1;//倍率翻倍乘区
	BRA=2.5;//基础伤害加成乘区
	c=floor(Rate2*BRA*Double);//万倍倍率，不填
	//a[0]=member.ATK; //面板攻击力, now won't use a[0], assign the ATK value to sum directly
	a[1]=member.buff[0];//攻击力百分比加成
	x=member.buff[1];//攻击力数值加成
	a[2]=c/10000;//最终倍率，不填
	a[3]=member.buff[2];//属性伤害加成乘区
	a[4]=member.buff[3];//属性抗性乘区 试玩区0.7605
	a[5]=member.buff[4];//额外伤害加成乘区
	a[6]=member.buff[5];//额外伤害减免乘区 试玩区0.9605
	a[7]=member.buff[6];//弱点增伤乘区，脆弱易燃……
	
	sum=member.ATK; //面板攻击力
	for(i=1;i<7;i++)//apply a[1] to a[6]
	{
		sum=floor(sum*a[i]);
		if(i==1)
		{
			sum=sum+x;
		}
		printf("a%lf\n",a[i]);
	}
	sum=ceil(sum*a[7]);
	printf("sum:%lf\n",sum);
	
	return (int)sum;
}

