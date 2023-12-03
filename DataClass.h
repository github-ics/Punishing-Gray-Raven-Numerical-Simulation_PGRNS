#ifndef DATACLASS_H
#define DATACLASS_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>

class Member {
public:
    int ATK;
    std::vector<double> buff;

    Member(int initialATK) : ATK(initialATK) {
        buff = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    }

    //void initializeFromExcel(const std::string& filename);
    
    void initializeFromTxt(const std::string& filename) {
	    std::ifstream file(filename);
	    if (!file.is_open()) {
	        throw std::runtime_error("Unable to open TXT file: " + filename);
	    }
	
	    // Read ATK from the first line
	    if (!(file >> ATK)) {
	        file.close();
	        throw std::runtime_error("Error reading ATK from TXT file: " + filename);
	    }
	
	    // Read buffs from the next 7 lines
	    for (int i = 0; i < 7; ++i) {
	        if (!(file >> buff[i])) {
	            file.close();
	            throw std::runtime_error("Error reading buff from TXT file: " + filename);
	        }
	    }
	
	    file.close();
	}

	// Use this function to display member parameters
	void displayParameters() const {
	    std::cout << "ATK: " << ATK << std::endl;
	    std::cout << "Buffs:";
	    for (double buffValue : buff) {
	        std::cout << " " << buffValue;
	    }
	    std::cout << std::endl;
	}
};

/*
void Member::initializeFromExcel(const std::string& filename) {
    xlsxioreader xlsio;
    xlsxioreadersheet sheet;

    if ((xlsio = xlsxioread_open(filename.c_str())) == NULL) {
        throw std::runtime_error("Unable to open Excel file: " + filename);
    }

    sheet = xlsxioread_sheet_open(xlsio, NULL, XLSXIOREAD_SKIP_EMPTY_ROWS);
    if (sheet == NULL) {
        xlsxioread_close(xlsio);
        throw std::runtime_error("Unable to open sheet in Excel file: " + filename);
    }

    int numColumns = xlsxioread_sheet_cols(sheet);
    if (numColumns < 2) {
        xlsxioread_sheet_close(sheet);
        xlsxioread_close(xlsio);
        throw std::runtime_error("Excel file structure is invalid: Expected at least 2 columns");
    }

    // Check if there are enough columns for buffs
    int expectedNumBuffs = 8; // Assuming there should be 8 buffs
    if (numColumns - 1 < expectedNumBuffs) {
        xlsxioread_sheet_close(sheet);
        xlsxioread_close(xlsio);
        throw std::runtime_error("Excel file structure is invalid: Not enough columns for buffs");
    }

    // Read buffs from subsequent cells (assuming they are in columns C to I)
        for (std::size_t i = 0; i < buff.size(); ++i) {
            if (xlsxioread_next_col(xls_sheet) == nullptr) {
                std::cerr << "Excel file structure is invalid: Not enough columns for buffs" << std::endl;
                xlsxioread_sheet_close(xls_sheet);
                xlsxioread_close(xlsread);
                return;
            }
            buff[i] = xlsxioread_read_num(xls_sheet, nullptr);
        }

        xlsxioread_sheet_close(xls_sheet);
        xlsxioread_close(xlsread);
}
*/



class Skill {
public:
    double multiplier;
    int timeCost;
    std::vector<double> buffChange;

	//the reason I dont't provide the Constructor for skill: For non aggregates (non aggregate objects), initialization lists cannot be used
    //Skill(double multi, int cost, std::vector<double>& buffChange) : multiplier(multi), timeCost(cost), buffChange(buffChange) {}

    Member applyBuff(Member& member) {
    	Member Now(member.ATK);
	    // Apply buff changes from the skill to the member
	    for (std::size_t i = 0; i < buffChange.size(); ++i) {
	        Now.buff[i] = member.buff[i]+buffChange[i];
	    }
	    return Now;
	} 
};


#endif // DATACLASS_H

/*
About the buff meaning:
    buff[0];//Attack power percentage bonus 
    buff[1];//Attack power value bonus
    buff[2];//Attribute damage bonus zone
    buff[3];//Attribute Resistance Ride Zone Trial Zone 0.7605
    buff[4];//Additional damage bonus zone
    buff[5];//Additional Damage Reduction Ride Zone Trial Zone 0.9605
    buff[6];//Weakness increases damage in the passenger area, such as fragile and flammable
*/
