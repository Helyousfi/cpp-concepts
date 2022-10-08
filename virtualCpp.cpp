#include <iostream>

class Base_class{
    protected:
        double attr1;
        double attr2;
    public:
        Base_class(double p_attr1, double p_attr2)
        {
            attr1 = p_attr1;
            attr2 = p_attr2;
        }
        virtual double get_product(){
            std::cout << "Base get_product called" << std::endl;
            return attr1 * attr2;
        }
};

class Derived_class : public Base_class{
    public:
        Derived_class(double p_attr1, double p_attr2) : 
            Base_class(p_attr1, p_attr2) {};
        double get_product(){
            std::cout << "Derived get_product called" << std::endl;
            return 2*attr1*attr2;
        }
};

void showProduct(Base_class* Base){
    std::cout << Base->get_product() << std::endl;
}


int main()
{
    
    Base_class* baseClass = new Base_class(4, 5);
    Derived_class* derivedClass = new Derived_class(4, 5);

    showProduct(baseClass);
    showProduct(derivedClass);

    return 0;
}
