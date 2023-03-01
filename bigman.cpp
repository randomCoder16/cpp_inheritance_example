// this might require more code but this is the most i can do rn
#include <iostream>
using std::cout;

// START OF BASE CLASS
class Enemy {
private:
    // ALL THE VARIABLES BELOW CAN BE INTEGERS SO I SEE NO NEED FOR STRINGS
    // IF NOT SET RETURN 0
    int health;
    int attackPower;
    int attackRange;
    int XP;
    int level;

public:
    Enemy(int a, int b, int c, int d = 0, int e = 1) {
        health = a;
        attackPower = b;
        attackRange = c;
        XP = d;
        level = e;
    }

    // Setters
    void setHealth(int x) {
        health = x;
    }

    void setAttackPower(int x) {
        attackPower = x;
    }

    void setAttackRange(int x) {
        attackRange = x;
    }

    void setXP(int x) {
        XP = x;
    }

    void setLevel(int x) {
        level = x;
    }

    // Getters
    int getHealth() {
        return health;
    }

    int getAttackPower() {
        return attackPower;
    }

    int getAttackRange() {
        return attackRange;
    }

    int getXP() {
        return XP;
    }

    int getLevel() {
        return level;
    }

    void Show() {
        cout << "Attack Power: " << attackPower << std::endl;
    }

    virtual void InheritMe() {
        cout << "Base class!" << std::endl;
    }
};

// Flyingenemy class inheriting from Enemy class
class FlyingEnemy : public Enemy {
private:
    int flyingRadius;
public:
    FlyingEnemy(int a, int b, int c, int d, int e, int x) : Enemy(a, b, c, d, e) {
        flyingRadius = x;
    }

    void Fly() {
        printf("Fly!\n");
    }

    void Show() {
        cout << "Attack Power (Flying enemy): " << getAttackPower() << std::endl;
    }

    void setFlyingEnemyHealth(int x) {
        setHealth(x);
    }
};

// GroundEnemy class inheriting from Enemy class
// I think another way of doing this second class is to inherit
// from the flying enemy class (i don't konw if this would work)
// since i never had time to try it
class GroundEnemy : public Enemy {
private:
    int patrollingRadius;
public:
    GroundEnemy(int a, int b, int c, int d, int e, int y) : Enemy(a, b, c, d, e) {
        patrollingRadius = y;
    }

    void Show() {
        cout << "Attack Power (Ground enemy): " << getAttackPower() << std::endl;
    }

    void InheritMe() {
        cout << "Ground enemy!" << std::endl;
    }
};

int main() {
    Enemy instance1 = Enemy(100, 10, 10);
    cout << "Health: " << instance1.getHealth() << std::endl;
    instance1.setHealth(34);
    cout << "Set new health (Enemy): " << instance1.getHealth() << std::endl;
    printf("\n");

    // Example with a derived class
    FlyingEnemy instance2 = FlyingEnemy(100, 10, 10, 0, 1, 20);
    cout << "FlyingEnemy Health: " << instance2.getHealth() << std::endl;
    instance2.setFlyingEnemyHealth(56);
    cout << "FlyingEnemy Health: " << instance2.getHealth() << std::endl;
    printf("\n");

    // just to prove the health set belongs to the flying enemy class and not the Enemy base class
    // print out the enemy health and it should still be the same
    cout << "Get current health (Enemy): " << instance1.getHealth() << std::endl;

    // example of a virtual function for runtime polymophism
    // fuck pointers
    GroundEnemy instance3 = GroundEnemy(100, 10, 10, 0, 1, 20);
    Enemy* ptr;
    ptr = &instance3;
    ptr->InheritMe();
    return 0;
}