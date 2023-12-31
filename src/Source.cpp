#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Upgrader {
    string name;
    double value;
    double multiplier;
    double mpu;
};

bool compareMultiplier(const Upgrader& a, const Upgrader& b) {
    return a.multiplier > b.multiplier;
}

bool compareMPU(const Upgrader& a, const Upgrader& b) {
    return a.mpu > b.mpu;
}

void generateCombinations(map<string, Upgrader>& upgraders, int totalInput, const string& selection) {
    vector<Upgrader> availableUpgraders;
    for (auto& pair : upgraders) {
        availableUpgraders.push_back(pair.second);
    }

    if (selection == "1") {
        sort(availableUpgraders.begin(), availableUpgraders.end(), compareMPU);
    }
    else if (selection == "2") {
        sort(availableUpgraders.begin(), availableUpgraders.end(), compareMultiplier);
    }

    vector<string> selectedUpgraders;
    int currentValue = 0;
    double currentMPU = 0.0;
    double currentMultiplier = 0.0;

    for (const auto& upgrader : availableUpgraders) {
        if (currentValue + upgrader.value <= totalInput) {
            selectedUpgraders.push_back(upgrader.name);
            currentValue += upgrader.value;
            currentMPU += upgrader.mpu;
            currentMultiplier += upgrader.multiplier;
        }
    }

    if (selectedUpgraders.empty()) {
        cout << "No combination found.\n";
        return;
    }

    cout << "Best combination:\n";
    if (selection == "1") {
        cout << "Units: " << currentValue << ", MPU: " << currentMPU << endl;
    }
    else if (selection == "2") {
        cout << "Units: " << currentValue << ", Multi: " << currentMultiplier << endl;
    }
    cout << "Upgraders used:\n";
    for (const auto& upgrader : selectedUpgraders) {
        cout << upgrader << ", U: " << upgraders[upgrader].value << ", MPU: " << upgraders[upgrader].mpu
            << ", Multi: " << upgraders[upgrader].multiplier << endl;
    }
}

int main() {
    map<string, Upgrader> upgraders;

    upgraders["Quantum Clockwork"] = { "Quantum Clockwork", 4, 120, 3.31 };
    upgraders["Astral Setter"] = { "Astral Setter", 4, 114, 3.27 };
    upgraders["Dreamer's life"] = { "Dreamer's life", 6, 525, 2.84 };
    upgraders["Tropical Breeze"] = { "Tropical Breeze", 2, 6, 2.45 };
    upgraders["The Cornucopia [Fully Powered]"] = { "The Cornucopia [Fully Powered]", 6, 150, 2.59 };
    upgraders["Vulcan's wrath [Charged]"] = { "Vulcan's wrath [Charged]", 6, 300, 2.59 };
    upgraders["Vulcan's wrath [UNCharged]"] = { "Vulcan's wrath [UNCharged]", 6, 300, 2.01 };
    upgraders["Swag City"] = { "Swag City", 6, 185193, 2.39 };
    upgraders["Executive Pillars"] = { "Executive Pillars", 2, 5.5, 2.35 };
    upgraders["Big Fungus [TOP]"] = { "Big Fungus [TOP]", 6, 150, 2.31 };
    upgraders["Temporal Armageddon"] = { "Temporal Armageddon", 4, 48, 2.45 };
    upgraders["The Pizzalyst"] = { "The Pizzalyst", 5, 59.7, 2.27 };
    upgraders["Vulcan's Destiny"] = { "Vulcan's Destiny", 6, 120, 2.22 };
    upgraders["Meralin's Sorcery"] = { "Meralin's Sorcery", 7, 220, 2.16 };
    upgraders["Delta Phantom"] = { "Delta Phantom", 6, 100, 2.15 };
    upgraders["Ruby Crystallizer"] = { "Ruby Crystallizer", 3, 10, 2.15 };
    upgraders["Virtual Gearwork [Max]"] = { "Virtual Gearwork [Max]", 5, 35, 2.04 };
    upgraders["Meatball Sandwich"] = { "Meatball Sandwich", 3, 10, 2.15 };
    upgraders["Legendary Peppermint"] = { "Legendary Peppermint", 3, 10, 2.15 };
    upgraders["The Hourglass [Max]"] = { "The Hourglass [Max]", 8, 290, 2.03 };
    upgraders["Alien Relic"] = { "Alien Relic", 2, 4, 2.00 };
    upgraders["Eggcelent Upgrader"] = { "Eggcelent Upgrader", 1, 2, 2.00 };
    upgraders["Glass Butterfly"] = { "Glass Butterfly", 3, 8, 2.00 };
    upgraders["Rainbow Refiner"] = { "Rainbow Refiner", 2, 4, 2.00 };
    upgraders["One Million Upgrader"] = { "One Million Upgrader", 3, 10, 2.15 };
    upgraders["Son Of Poison [Alone]"] = { "Son Of Poison [Alone]", 6, 12, 1.51 };
    upgraders["Garden of Gaia"] = { "Garden of Gaia", 7, 90, 1.90 };
    upgraders["Fractured Reality [AB]"] = { "Fractured Reality [AB]", 4, 13, 1.90 };
    upgraders["Cosmic Device"] = { "Cosmic Device", 4, 13, 1.90 };
    upgraders["Optic Origin [Max]"] = { "Optic Origin [Max]", 9, 301, 1.89 };
    upgraders["The Beehive"] = { "The Beehive", 2, 3.5, 1.87 };
    upgraders["Deluxe Beehive"] = { "Deluxe Beehive", 2, 3.5, 1.87 };
    upgraders["The Death Cap [Min]"] = { "The Death Cap [Min]", 8, 130, 1.84 };
    upgraders["Vampire Spore"] = { "Vampire Spore", 4, 11, 1.82 };
    upgraders["Cooling Chamber"] = { "Cooling Chamber", 4, 11, 1.82 };
    upgraders["Universal Collapse [Min]"] = { "Universal Collapse [Min]", 6, 48, 1.81 };
    upgraders["Frosted Refiner"] = { "Frosted Refiner", 1, 1.75, 1.75 };
    upgraders["Devil's Spore"] = { "Devil's Spore", 6, 26, 1.72 };
    upgraders["Methane Sky Fleet [Max]"] = { "Methane Sky Fleet [Max]", 3, 5, 1.71 };
    upgraders["Big Alberto [top]"] = { "Big Alberto [top]", 6, 25, 1.71 };
    upgraders["Azure Spore"] = { "Azure Spore", 6, 25, 1.71 };
    upgraders["Clockwork"] = { "Clockwork", 3, 5, 1.71 };
    upgraders["Frozen Eclipse"] = { "Frozen Eclipse", 7, 40, 1.60 };
    upgraders["Son Of Poison + Stratospheric"] = { "Son Of Poison + Stratospheric", 7, 40, 1.69 };
    upgraders["Gingerbread Mansion"] = { "Gingerbread Mansion", 4, 8, 1.68 };
    upgraders["Winter Snowflake"] = { "Winter Snowflake", 3, 5, 1.68 };
    upgraders["Moai God"] = { "Moai God", 4, 8, 1.68 };
    upgraders["Desert Monument"] = { "Desert Monument", 5, 13, 1.67 };
    upgraders["Turbine Chamber"] = { "Turbine Chamber", 6, 21, 1.66 };
    upgraders["Mighty Sugar Cookie"] = { "Mighty Sugar Cookie", 5, 10.2, 1.59 };
    upgraders["Vaporwave Vibe Visualiser"] = { "Vaporwave Vibe Visualiser", 4, 7, 1.63 };
    upgraders["Brimstone Spires"] = { "Brimstone Spires", 8, 50, 1.63 };
    upgraders["Newtonic Corroder"] = { "Newtonic Corroder", 4, 7, 1.63 };
    upgraders["Tsar Bomba"] = { "Tsar Bomba", 8, 50, 1.63 };
    upgraders["Deadly Spore"] = { "Deadly Spore", 4, 7, 1.63 };
    upgraders["Pillars of Creation"] = { "Pillars of Creation", 6, 13, 1.60 };
    upgraders["The Holy Cheese"] = { "The Holy Cheese", 3, 4, 1.59 };
    upgraders["Azure Refiner"] = { "Azure Refiner", 3, 4, 1.59 };
    upgraders["Diamond Egg"] = { "Diamond Egg", 2, 2.5, 1.58 };
    upgraders["Ancient Coliseum"] = { "Ancient Coliseum", 5, 10, 1.58 };
    upgraders["Auroral Metropolis [Frozen ores]"] = { "Auroral Metropolis [Frozen ores]", 7, 25, 1.58 };
    upgraders["Vitamin C-Coater"] = { "Vitamin C-Coater", 4, 6, 1.57 };
    upgraders["Mineral Wheel"] = { "Mineral Wheel", 4, 6, 1.57 };
    upgraders["Phase Bombarder"] = { "Phase Bombarder", 6, 15, 1.57 };
    upgraders["Demon Core"] = { "Demon Core", 6, 11, 1.55 };
    upgraders["Atlantic Monument"] = { "Atlantic Monument", 6, 13, 1.53 };
    upgraders["Firecrystallized System"] = { "Firecrystallized System", 6, 12.75, 1.53 };
    upgraders["Hades' Palace"] = { "Hades' Palace", 8, 30, 1.53 };
    upgraders["Banana Split Upgrader"] = { "Banana Split Upgrader", 4, 5.5, 1.53 };
    upgraders["The Sporest"] = { "The Sporest", 5, 8, 1.52 };
    upgraders["Quantum Ore Polisher"] = { "Quantum Ore Polisher", 5, 8, 1.52 };
    upgraders["Searing Heat"] = { "Searing Heat", 6, 11, 1.49 };
    upgraders["CONTRALAND"] = { "CONTRALAND", 6, 11, 1.49 };
    upgraders["Crystallized Engine"] = { "Crystallized Engine", 11, 6, 1.49 };
    upgraders["Shard City"] = { "Shard City", 7, 16, 1.49 };
    upgraders["Blazing Agriculture"] = { "Blazing Agriculture", 6, 6, 1.23 };
    upgraders["Illusions of Void"] = { "Illusions of Void", 5, 5, 1.40 };
    upgraders["Overlord Device"] = { "Overlord Device", 6, 10, 1.47 };
    upgraders["Aromatic Holidays"] = { "Aromatic Holidays", 3, 3, 1.44 };
    upgraders["Ore Memer"] = { "Ore Memer", 4, 4.2, 1.43 };
    upgraders["Crystallized System"] = { "Crystallized System", 5, 6, 1.43 };
    upgraders["Ice Crusher"] = { "Ice Crusher", 5, 6, 1.43 };
    upgraders["Abominable Screaming Tree"] = { "Abominable Screaming Tree", 7, 9, 1.34 };
    upgraders["Big Candy Cane"] = { "Big Candy Cane", 2, 2, 1.41 };
    upgraders["Snowflake Wheel"] = { "Snowflake Wheel", 4, 4, 1.41 };
    upgraders["Stratospheric Refiner"] = { "Stratospheric Refiner", 4, 4, 1.41 };
    upgraders["100M Upgrader"] = { "100M Upgrader", 2, 2, 1.41 };
    upgraders["Nuclear Chamber"] = { "Nuclear Chamber", 4, 4, 1.41 };
    upgraders["Phase Refiner"] = { "Phase Refiner", 4, 4, 1.41 };
    upgraders["Auroral Wings"] = { "Auroral Wings", 2, 2, 1.41 };
    upgraders["Scorching Heat"] = { "Scorching Heat", 5, 5, 1.38 };
    upgraders["Citrus Enhancer"] = { "Citrus Enhancer", 5, 4.75, 1.37 };
    upgraders["Plasma Scanner"] = { "Plasma Scanner", 6, 6, 1.35 };
    upgraders["Pizza Bombarder"] = { "Pizza Bombarder", 8, 10, 1.33 };
    upgraders["Ore Gielder"] = { "Ore Gielder", 4, 3, 1.32 };
    upgraders["Permafrost Refiner"] = { "Permafrost Refiner", 4, 3, 1.32 };
    upgraders["Behemoth Snowflake"] = { "Behemoth Snowflake", 5, 4, 1.32 };
    upgraders["Ancient Temple"] = { "Ancient Temple", 5, 4, 1.32 };

    while (true) {
        int totalInput;
        cout << "Enter total units: ";
        cin >> totalInput;

        if (totalInput == 0) {
            break;
        }

        int choice;
        cout << "Enter '1' for MPU or '2' for Multiplier: ";
        cin >> choice;

        string selection;
        if (choice == 1) {
            selection = "1";
        }
        else if (choice == 2) {
            selection = "2";
        }
        else {
            cout << "Invalid selection. Please enter '1' or '2'." << endl;
            continue;
        }

        generateCombinations(upgraders, totalInput, selection);
    }

    return 0;
}
