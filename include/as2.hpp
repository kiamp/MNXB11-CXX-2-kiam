#pragma once

#include <string>
#include <iostream>
#include <random>
#include <memory>
#include <sstream>

namespace homework {

  // Random number generator setup
  inline std::random_device rd;
  inline std::mt19937 gen(rd()); 
  inline std::uniform_real_distribution<double> dist(0.0, 1.0);
  // to generate a random number between 0 and 1, use auto random_number = dist(gen);

  // Base class for entities
  // Has a implemented method getName()
  // Has a pure virtual method attack()
  // Has a pure virtual method clone() to support polymorphic copying
  // TO DO: Nothing, everything is implemented for you
  struct Entity {
      explicit Entity(const std::string name) : name{std::move(name)} {}
      virtual ~Entity() = default;
      virtual void attack() const = 0;
      std::string getName() const {
        return name;
      }

      virtual std::unique_ptr<Entity> clone() const = 0;
    protected:
      std::string name;
  };
  
  // as 2.1
  // Derived class Knight
  // TO DO: implement attack() and clone() and setWeapon()
  // Should have a private member variable for weapon (std::string)
  // Note: use std::make_unique in clone() and the this pointer to copy the object using chatGPT is okay for this purpose
  // The attack should use std::cout to print something like "<name> swings a <weapon>\n"
  // The setWeapon() method should set the weapon variable (the private member variable) 
  class Knight : public Entity {
    public:

      explicit Knight(const std::string name) : Entity(name) {} //code wouldn't compile, Chatgpt said to write constructor
                                                                //that passes to the entity constructor
      void attack() const override {
        std::cout << name << " swings their " << weapon << std::endl;
      }
      std::unique_ptr<Entity> clone() const override {
        return std::make_unique<Knight> (*this);
      }

      void setWeapon(std::string weaponChoice) {
        weapon = weaponChoice;
      }
  
    private:
      std::string weapon;
  };
  // as 2.2
  // Derived class Sorcerer
  // TO DO: implement attack() and clone() and setAbility()
  // Same as the Knight class
  class Sorcerer : public Entity {
    public:

      explicit Sorcerer(const std::string name) : Entity(name) {}

      void attack() const override {
        std::cout << name << " uses " << ability << std::endl;
      }

      std::unique_ptr<Entity> clone() const override {
       return std::make_unique<Sorcerer> (*this);
      }

      void setAbility(std::string abilityChoice) {
        ability = abilityChoice;
      }

    private:
      std::string ability;
  };
  // as 2.3 (This is a stretch goal, hand it in, and if it does not work, you can still pass the assignment)
  // Duel class template
  // TO DO: create a struct/class called Duel that is templated by two types (T1 and T2)
  // The constructor should take two pointers (T1* and T2*)
  // The fight() method should:
  // - call attack() on both entities
  // - randomly select one of the two entities as the winner (use the random number generator above)
  // - print to std::cout "<name> wins the duel!\n"
  // - return a std::unique_ptr<Entity> to the winner (use clone() to copy the object)

  template <typename T1, typename T2> //Chatgpt showed how to template
  class Duel {
    public:
      Duel(T1* ptr_1, T2* ptr_2) : ptr_champ1(ptr_1), ptr_champ2(ptr_2) {}

      std::unique_ptr<Entity> fight() {
        ptr_champ1->attack();
        ptr_champ2->attack();

        auto random_number = dist(gen);

        if (random_number < 0.5) {
          std::cout << ptr_champ1->getName() << " wins the duel!" << std::endl;
          return ptr_champ1->clone();
        } else {
          std::cout << ptr_champ2->getName() << " wins the duel!" << std::endl;
          return ptr_champ2->clone();
        }
        
      }   //Chatgpt showed how to use the pointer to call on functions
  
    private:
      T1* ptr_champ1;
      T2* ptr_champ2;
  };

} // namespace homework

