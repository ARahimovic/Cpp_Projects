#include <iostream>

using namespace std;

class AbstractChair {
public:
    virtual ~AbstractChair() {};
    virtual void SitOn() const = 0;
};

class VictorianChair : public AbstractChair {
public:
    void SitOn() const override { cout << " Sitting on Victorian Chair\n"; }
};

class ModernChair : public AbstractChair {
public:
    void SitOn() const override { cout << " Sitting on Modern Chair\n"; }
};

class ArtDecoChair : public AbstractChair {
public:
    void SitOn() const override { cout << " Sitting on ArtDeco Chair\n"; }
};

class AbstractTable {
public:
    virtual ~AbstractTable() {};
    virtual void EatOnIt() const = 0;
};

class VictorianTable : public AbstractTable {
public:
    void EatOnIt() const override { cout << "eating on a victorian table\n"; }
};

class ModernTable : public AbstractTable {
public:
    void EatOnIt() const override { cout << "eating on a Modern table\n"; }
};

class ArtDecoTable : public AbstractTable {
public:
    void EatOnIt() const override { cout << "eating on a ArtDeco table\n"; }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() {};
    virtual AbstractChair* CreateChair() const = 0;
    virtual AbstractTable* CreateTable() const = 0;
};

class VictorianFactory : public AbstractFactory {
public:
    AbstractChair* CreateChair() const override { return new VictorianChair(); }
    AbstractTable* CreateTable() const override { return new VictorianTable(); }
};

class ModernFactory : public AbstractFactory {
public:
    AbstractChair* CreateChair() const override { return new ModernChair(); }
    AbstractTable* CreateTable() const override { return new ModernTable(); }
};

class ArtDecoFactory : public AbstractFactory {
public:
    AbstractChair* CreateChair() const override { return new ArtDecoChair(); }
    AbstractTable* CreateTable() const override { return new ArtDecoTable(); }
};

void ClientCode(const AbstractFactory& factory) {
    AbstractChair* chair = factory.CreateChair();
    AbstractTable* table = factory.CreateTable();
    chair->SitOn();
    table->EatOnIt();

    delete chair;
    delete table;
}

int main() {
    cout << " creating A victorian set\n";
    VictorianFactory Vfactory;
    ClientCode(Vfactory);

    cout << " creating A Modern set\n";
    ModernFactory Mfactory;
    ClientCode(Mfactory);

    return 0;
}
