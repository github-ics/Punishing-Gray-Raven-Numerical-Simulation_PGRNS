#     Punishing-Gray-Raven-Numerical-Simulation_PGRNS

[![license](http://www.apache.org/licenses/LICENSE-2.0)](http://www.apache.org/licenses/LICENSE-2.0)


## About The Project

It is used to compute the damage for Punish:Gray Raven. Now it based on cpp, and allows input the data about the game with txt file.


### Built With

Built Using Languages and Libraries Listed Below 
* [C++](https://c-cpp.com/)
  
Ps:Add "-std=c++11" when you compile project.

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

Here I must Thank you to 圈儿 also, for providing the C code for accurately calculating damage values.

## Install

Now it only depends on C++11.

## Usage

If you are not good at coding, you can input the value of ATK and other parameters of buffs by txt file, which has the same format with "member_parameters.txt". 
Sothat, you needn't edit any C++ code.

## Contributing
Welcome for players who is into the PGR and good at coding simulation programs.

Note: If editing the projrct, please push your improvement of program to testBranch!!!

>small note:
> 1. main() function is in "ProcessSimulator.cpp"
> 2. Declarate all functions in "SubFunction.h" please
> 3. The declaration of classes are in the "DataClass.h"
> 4. New function had better to be placed in a single ".cpp" file, just like "DamageCounter.cpp"


## License

[apache](http://www.apache.org/licenses/LICENSE-2.0)

Note: read the detials by the link if you want to know how "open" it is.

