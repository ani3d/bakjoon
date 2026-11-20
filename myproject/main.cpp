#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character;

class Skill {
public:
    string name;
    int cost;
    double multiplier;

    Skill(string n, int c, double m) : name(n), cost(c), multiplier(m) {}

    void use(Character& user, Character& target);
};

class Weapon {
public:
    string name;
    int bonusAtk;
    int price;

    Weapon(string n, int b, int p) : name(n), bonusAtk(b), price(p) {}
};

class Character {
public:
    string name;
    int maxHp;
    int hp;
    int maxEnergy;
    int energy;
    int attack;
    bool isDefending = false;
    vector<Skill> skills;

    Character(string n, int hp, int energy, int atk)
        : name(n), maxHp(hp), hp(hp), maxEnergy(energy), energy(energy), attack(atk) {}

    virtual void takeTurn(Character& target) = 0;

    void restoreEnergy(int amount) {
        energy += amount;
        if (energy > maxEnergy) energy = maxEnergy;
    }

    bool isAlive() { return hp > 0; }

    void takeDamage(int dmg) {
        if (isDefending) {
            dmg /= 2;
            cout << name << " blocked part of the damage!\n";
        }
        hp -= dmg;
        if (hp < 0) hp = 0;
    }
};

void Skill::use(Character& user, Character& target) {
    if (user.energy < cost) {
        cout << user.name << " tried to use " << name << ", but didn't have enough energy!\n";
        return;
    }
    int damage = static_cast<int>((user.attack) * multiplier);
    cout << user.name << " uses " << name << " on " << target.name << " for " << damage << " damage!\n";
    target.takeDamage(damage);
    user.energy -= cost;
}

class Player : public Character {
public:
    ~Player(){
        for(Weapon* w:inventory) delete w;
    }
    Weapon* equippedWeapon = nullptr;
    vector<Weapon*> inventory;
    int level = 1;
    int exp = 0;
    int expToNext = 100;

    Player(string n, int hp, int energy, int atk) : Character(n, hp, energy, atk) {}

    int getTotalAttack() const {
        return attack + (equippedWeapon ? equippedWeapon->bonusAtk : 0);
    }

    void checkLevelUp() {
        while (exp >= expToNext) {
            exp -= expToNext;
            level++;
            expToNext += 50;
            maxHp += 10;
            attack += 2;
            hp = maxHp;
            cout << "You leveled up! Now level " << level << "! HP and ATK increased.\n";

            if (level == 3) {
                skills.push_back(Skill("Power Thrust", 3, 2.5));
                cout << "New skill unlocked: Power Thrust!\n";
            } else if (level == 5) {
                skills.push_back(Skill("Whirlwind", 5, 3.0));
                cout << "New skill unlocked: Whirlwind!\n";
            }
        }
    }

    void takeTurn(Character& target) override {
        cout << "\nYour turn! (Lv." << level << ") (" << hp << "/" << maxHp << " HP, " << energy << "/" << maxEnergy << " Energy)\n";
        cout << "Equipped Weapon: " << (equippedWeapon ? equippedWeapon->name + " (Atk +" + to_string(equippedWeapon->bonusAtk) + ")" : "None") << "\n";
        for (int i = 0; i < skills.size(); ++i) {
            cout << i + 1 << ". " << skills[i].name
                 << " (Cost: " << skills[i].cost
                 << ", Multiplier: " << skills[i].multiplier << ")\n";
        }
        cout << skills.size() + 1 << ". Defend (No energy, take 50% damage)\n";

        cout << "Choose an action: ";
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= skills.size()) {
            isDefending = false;
            Skill& chosen = skills[choice - 1];
            if(energy>=chosen.cost){
                int dmg = static_cast<int>(getTotalAttack() * chosen.multiplier);
                cout << name << " uses " << chosen.name << " for " << dmg << " damage!\n";
                target.takeDamage(dmg);
                energy -= chosen.cost;
            }
            else cout<<"Not enoght energy"<<chosen.name<<"!\n";
        } else if (choice == skills.size() + 1) {
            isDefending = true;
            cout << name << " takes a defensive stance!\n";
        } else {
            cout << "Invalid choice. Turn skipped.\n";
        }
    }
};

class Monster : public Character {
public:
    Monster(string n, int hp, int energy, int atk) : Character(n, hp, energy, atk) {}

    void takeTurn(Character& target) override {
        if (!skills.empty()) {
            Skill& skill = skills[rand() % skills.size()];
            cout << "\n" << name << "'s turn!\n";
            int dmg = static_cast<int>(attack * skill.multiplier);
            cout << name << " uses " << skill.name << " for " << dmg << " damage!\n";
            target.takeDamage(dmg);
            energy -= skill.cost;
        }
    }
};

Monster createRandomMonster(int day) {
    vector<string> names = {"Goblin", "Orc", "Lizard", "Skeleton"};
    string name = names[rand() % names.size()];

    int baseHp = 60 + (day / 10) * 10;
    int energy = 4 + rand() % 3;
    int atk = 8 + (day / 20) * 2;

    bool isBoss = (day % 30 == 0);
    if (isBoss) {
        name = "Champion";
        baseHp += 50;
        atk += 5;
    }

    Monster m(name, baseHp, energy, atk);

    for (int i = 0; i < 2; ++i) {
        int cost = 2 + rand() % 3;
        double mult = 1.0 + (rand() % 11) / 10.0;
        string skillName = (isBoss ? "Crush " : "Strike ") + to_string(i + 1);
        m.skills.push_back(Skill(skillName, cost, mult));
    }
    return m;
}

void battle(Player& player, Monster& monster) {
    while (player.isAlive() && monster.isAlive()) {
        player.takeTurn(monster);
        if (!monster.isAlive()) break;

        monster.takeTurn(player);

        player.restoreEnergy(2);
        monster.restoreEnergy(2);

        player.isDefending = false;
        monster.isDefending = false;

        cout << "\n[Status] " << player.name << ": " << player.hp << " HP | " << monster.name << ": " << monster.hp << " HP\n";
    }
}

void openShop(Player& player, int& gold) {
    vector<Weapon> shopItems = {
        Weapon("Rusty Sword", 3, 30),
        Weapon("Iron Axe", 5, 50),
        Weapon("Steel Blade", 8, 80)
    };

    cout << "\n-- Shop --\n";
    for (int i = 0; i < shopItems.size(); ++i) {
        cout << i + 1 << ". " << shopItems[i].name << " (+" << shopItems[i].bonusAtk << " Atk) - " << shopItems[i].price << " gold\n";
    }
    cout << "Current Gold: " << gold << "\n";
    cout << "Enter item number to buy (0 to skip): ";
    int choice;
    cin >> choice;

    if (choice >= 1 && choice <= shopItems.size()) {
        Weapon *purchased=new Weapon(shopItems[choice-1]);
        if (gold >= purchased->price) {
            gold -= purchased->price;
            player.inventory.push_back(purchased);
            player.equippedWeapon = purchased;
            cout << "You purchased and equipped: " << purchased->name << "!\n";
        } else {
            cout << "Not enough gold.\n";
        }
    } else {
        cout << "You left the shop.\n";
    }
}

int main() {
    srand(time(nullptr));

    Player player("Gladiator", 100, 5, 10);
    player.skills.push_back(Skill("Slash", 2, 1.2));
    player.skills.push_back(Skill("Heavy Strike", 4, 2.0));

    int currentDay = 1;
    int gold = 0;

    while (player.isAlive()) {
        cout << "\n==============================\n";
        cout << "Day " << currentDay << " - A new battle begins!\n";

        Monster monster = createRandomMonster(currentDay);

        if (monster.name == "Champion") {
            cout << "⚔️  A powerful " << monster.name << " has entered the arena! Prepare yourself! ⚔️\n";
        } else {
            cout << "A wild " << monster.name << " has entered the arena!\n";
        }

        battle(player, monster);

        if (!player.isAlive()) break;

        cout << "\nYou won the battle!\n";

        int baseGold = 30 + rand() % 21;
        int expGain = 40 + rand() % 21;
        gold += baseGold;
        player.exp += expGain;
        cout << "You earned " << baseGold << " gold and " << expGain << " EXP from the battle!\n";

        player.checkLevelUp();

        int restDays = rand() % 7 + 1;
        cout << "You are offered " << restDays << " days of rest.\n";
        cout << "1. Take the rest and recover (shop available)\n2. Skip rest and earn bonus gold\nChoose: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int heal = 10 + rand() % 11;
            player.hp += heal;
            if (player.hp > player.maxHp) player.hp = player.maxHp;
            cout << "You rested and recovered " << heal << " HP.\n";
            openShop(player, gold);
            currentDay += restDays + 1;
        } else {
            int bonusGold = 30 + rand() % 21;
            gold += bonusGold;
            cout << "You push forward without rest. Earned bonus gold: " << bonusGold << "\n";
            currentDay += 1;
        }

        cout << "Current Gold: " << gold << ", EXP: " << player.exp << "/" << player.expToNext << "\n";
    }

    cout << "\nGame Over. Final Day: " << currentDay << ", Total Gold: " << gold << ", Level: " << player.level << "\n";
    return 0;
}
