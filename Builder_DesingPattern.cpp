/**
 * @brief Builder design pattern, when an object is too complex to construct, we use the builder 
 * we need the product that we are going to build 
 * a builder interface that incorparate all the methods that sets the product
 * We can have many builder implementation , depending on how we want to configure the product
 * we have a director class that calls the builder methods 
 */

#include <iostream>
#include <string>

using namespace std;

class House 
{
    private :
        string basement;
        string structure;
        string roof;
        string interior;

    public :
        void SetBasement(string b)
        {
            basement = b;
        }

        void SetStructure(string b)
        {
            structure = b;
        }
        void SetInterior(string b)
        {
            interior = b;
        }
        void SetRoof(string b)
        {
            roof = b;
        }

        void DisplayInfo()
        {
            cout << " Basement " << basement << endl;
            cout << " Structure " << structure << endl;
            cout << " Interior " << roof << endl;
            cout << " Roof " << interior << endl;
        }
        
};


class Builder 
{

    public :
    virtual void BuildBasement() = 0;
    virtual void BuildRoof() = 0 ;
    virtual void BuildInterior() = 0 ;
    virtual void BuildStructure() = 0;
    virtual House* GetHouse() = 0;

    virtual ~Builder() {}

};


class IgloHouseBuilder : public Builder 
{
    public:
    IgloHouseBuilder() { house = new House(); }
    ~IgloHouseBuilder() { delete house; }
     

    void BuildBasement() override { house->SetBasement("Iglo Basement");}
    void BuildRoof() override { house->SetRoof("Ice Cubes");}
    void BuildInterior() override { house->SetInterior("snow floor");}
    void BuildStructure() override { house->SetStructure(" ICe Structure");}
    House* GetHouse() override {return this->house; }

    private :
    House *house;

};


class TipiHouseBuilder : public Builder 
{
    public :
        TipiHouseBuilder() { house = new House(); }
        ~TipiHouseBuilder() { delete house ; }

        void BuildBasement() override { house->SetBasement("Wood pillars");}
        void BuildRoof() override { house->SetRoof("straws and branches");}
        void BuildInterior() override { house->SetInterior("Red wood");}
        void BuildStructure() override { house->SetStructure("wood pillars");}
        House* GetHouse() override {return this->house; }

    private :
        House *house;
};


class Engineer_Director
{
    private:
        Builder* builder;
    public:

        Engineer_Director(Builder* b) : builder(b){}

        void CreateHouse()
        {
            builder->BuildBasement();
            builder->BuildRoof();
            builder->BuildInterior();
            builder->BuildStructure();
        }

        House* GetHouse()
        {
            return builder->GetHouse();
        }    
};



int main()
{
    // want to creat an iglo house
    Builder* houseConfig = new IgloHouseBuilder();
    Engineer_Director *director = new Engineer_Director(houseConfig);
    
    director->CreateHouse();
    House* house = director->GetHouse();
    house->DisplayInfo();
    
    delete houseConfig;
    delete director;
    // want to creat an TipiHouse
    houseConfig = new TipiHouseBuilder();
    director = new Engineer_Director(houseConfig);
    director->CreateHouse();
    house = director->GetHouse();
    house->DisplayInfo();
    
    delete houseConfig;
    
    return 0;
}



