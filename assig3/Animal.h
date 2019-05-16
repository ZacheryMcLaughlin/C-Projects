#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    protected:
        int age;
        int num_animal;
        int cost;
        int babies;

    public:
        Animal();

        Animal(const Animal &);

        Animal &operator=(const Animal &);

        void set_age(int);
        int get_age();
        void set_num_animal(int);
        int get_num_animal();
        void set_cost(int);
        int get_cost();
        void set_num_babies(int);
        int get_num_babies();
        void increment_age();
    
};
#endif