#     Punishing-Gray-Raven-Numerical-Simulation_PGRNS

[license](http://www.apache.org/licenses/LICENSE-2.0)


## About The Project


It is used to compute the damage for Punish:Gray Raven. Now it based on c++11, and allows input the data about the game with ".txt" file.



### Built With

Built Using Languages and Libraries Listed Below 
* [C++](https://c-cpp.com/)
  
Ps:may need to add "-std=c++11" when you compile project.

Or in tabular form

| environment | version   |
| ----------- | --------- |
| C++         |   C++11   |

Ps:For convenience, I code on DEV C++5.11 with Windows10 ususally.


## Table of Contents

- [Background](#background)
- [Install](#install)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)


## Background
There are many different characters and equipment you can pick for various cases. However, you may not make a good usage of such set of equipments, before you are familiar with the way to engage with the enimies. At this time, a numerical simulation of damage may help you to evaluate if the combination is fitful enough for your expectation. 
Especially, when you wonder the effect of some complex operation that you can not finish in game now, test theoretical process or operation by this project, then you can see the practical damage immediately.


Here I must Thank you for 圈儿 also, who provides the C code for accurately calculating damage values.

## Install

Now it only depends on C++11.

## Usage

This C++ project is a simple game damage simulator that allows users to model and simulate damage calculations based on character attributes, buffs, and skills. The project is organized into three main classes: `Member`, `Skill`, and a set of sub-functions.

### Classes Overview

#### `Member` Class

The `Member` class represents a character in the game. It includes attributes such as Attack (ATK) and an array of buffs that can be modified independently. Buffs play a crucial role in determining damage outcomes.

- **Attributes:**
  - `ATK`: Initial Attack power of the character.
  - `buff`: An array representing different buffs affecting the character.

- **Methods:**
  - `initializeFromFile(filename)`: Initializes member parameters (ATK and buffs) from a text file.
  - `initializeFromExcel(filename)`: Initializes member parameters (ATK and buffs) from an Excel file.

#### `Skill` Class

The `Skill` class represents a character's skill, including properties such as multiplier, time cost, and buff changes. Skills are stored in a linked list, allowing users to define a sequence of skills for simulation.

- **Attributes:**
  - `multiplier`: Damage multiplier of the skill.
  - `timeCost`: Time cost associated with using the skill.
  - `buffChange`: An array representing the changes in buffs caused by the skill.

- **Methods:**
  - `applyBuff(member)`: Applies buff changes from the skill to a `Member` object.

#### Sub-Functions

A set of sub-functions includes `Damcounter` and `SkillDam` for simulating the damage calculation process.

### Getting Started

1. **Member Initialization:**
   - Use the `Member` class to create characters, setting initial Attack power and buffs.

2. **Skill Initialization:**
   - Create skills using the `Skill` class, defining their properties.
   - Store skills in a vector to create a sequence for simulation.

3. **Simulation:**
   - Utilize the `Damcounter` function to simulate the damage calculation process.
   - View the results for each skill's damage output.
4. **Tips:**
   -If you are not good at coding, you can input the value of ATK and other parameters of buffs by txt file, which has the same format with "member_parameters.txt". Sothat, you needn't edit any C++ code.
   
### Customization

- Modify the number of buffs or other attributes in the `Member` class.
- Experiment with different skill properties and sequences.
- Explore alternative methods for initializing member parameters.




## Contributing
Welcome for players who is into the PGR and good at coding simulation programs.

This project accepts using Ai-assisted programming, but if you directly use tools such as GPT to code, it is best to explain the situation when submitting to ensure compatibility and robustness.

Note: If editing the projrct, please push your improvement of program to testBranch!!!

>small note:
> 1. main() function is in "ProcessSimulator.cpp"
> 2. Declarate all functions in "SubFunction.h" please
> 3. The declaration of classes are in the "DataClass.h"
> 4. New function had better to be placed in a single ".cpp" file, just like "DamageCounter.cpp"


## License

[apache](http://www.apache.org/licenses/LICENSE-2.0)

Note: read the details by the link if you want to know how "open" it is.

>After all, make sure you use the project legally.
