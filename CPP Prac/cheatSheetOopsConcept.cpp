

// /*
// ====================================================
// 🧠 C++ OOP CHEAT SHEET — Complete Revision
// ====================================================

// ✅ OOP = Object-Oriented Programming
// 4 Pillars of OOP in C++:
// ------------------------------------------
// | Pillar          | Meaning               |
// |-----------------|------------------------|
// | Encapsulation   | Hiding data + methods |
// | Abstraction     | Show only what’s needed |
// | Inheritance     | Reuse base class      |
// | Polymorphism    | One interface, many forms |

// ====================================================
// 🛡️ 1. ENCAPSULATION — Data Protection
// ====================================================

// - Keep data members private
// - Provide public getter/setter functions

// Example:
// */

// class BankAccount {
// private:
//     int balance;

// public:
//     void deposit(int amount) {
//         if (amount > 0) balance += amount;
//     }

//     int getBalance() {
//         return balance;
//     }
// };

// /*
// ====================================================
// 🧱 2. INHERITANCE — Code Reuse
// ====================================================

// | Type         | Syntax                  |
// |--------------|--------------------------|
// | Single       | class B : public A       |
// | Multilevel   | A → B → C                |
// | Multiple     | class C : public A, B    |
// | Hierarchical | A → B, A → C             |

// Example:
// */

// class Vehicle {
// public:
//     void start() { cout << "Vehicle started\n"; }
// };

// class Car : public Vehicle {
// public:
//     void honk() { cout << "Beep Beep!\n"; }
// };

// /*
// ====================================================
// 🔁 3. POLYMORPHISM — One Interface, Many Forms
// ====================================================

// 📌 Types:
// - Compile-time: Function Overloading, Constructor Overloading
// - Run-time: Function Overriding (with virtual)

// === Compile-Time ===
// */

// class Math {
// public:
//     int add(int a, int b) { return a + b; }
//     double add(double a, double b) { return a + b; }
// };

// /*
// === Constructor Overloading ===
// */

// class Person {
// public:
//     string name;
//     int age;

//     Person() { name = "Unknown"; age = 0; }
//     Person(string n) { name = n; age = 0; }
//     Person(string n, int a) { name = n; age = a; }
// };

// /*
// === Run-Time (Virtual Functions) ===
// */

// class Shape {
// public:
//     virtual void draw() { cout << "Drawing Shape\n"; }
// };

// class Circle : public Shape {
// public:
//     void draw() override { cout << "Drawing Circle\n"; }
// };

// /*
// ✅ Polymorphism needs base class pointers/references:
// */

// Shape* s = new Circle();  // Runtime decision
// s->draw();                // Calls Circle::draw()

// /*
// ====================================================
// 🧠 ABSTRACT CLASSES & PURE VIRTUAL FUNCTIONS
// ====================================================

// Used for ABSTRACTION.

// - Cannot instantiate
// - Must be inherited
// - Forces derived class to override methods
// */

// class Animal {
// public:
//     virtual void makeSound() = 0; // Pure virtual
// };

// class Dog : public Animal {
// public:
//     void makeSound() override { cout << "Woof!\n"; }
// };

// /*
// ====================================================
// 💣 DESTRUCTORS — Clean-up
// ====================================================

// Called when object goes out of scope or is deleted

// Use when:
// - Using `new`
// - Opening files
// - Holding sockets, DB, GPU handles

// */

// class Buffer {
//     int* data;
// public:
//     Buffer(int size) {
//         data = new int[size];
//     }

//     ~Buffer() {
//         delete[] data;  // Prevent memory leaks
//     }
// };

// /*
// ====================================================
// 📌 COMPILE-TIME vs RUN-TIME
// ====================================================

// | Feature            | Compile-Time        | Run-Time               |
// |--------------------|---------------------|------------------------|
// | Happens when?      | Before execution    | During program run     |
// | Catches errors     | Syntax errors       | Crashes, logic errors  |
// | Polymorphism type  | Overloading         | Overriding + virtual   |
// | Tools involved     | Compiler            | CPU, OS                |

// ====================================================
// 🧠 FINAL NOTES
// ====================================================

// - Classes = blueprint, Objects = real entities
// - Use `public` to expose members
// - Use `private` to protect them (Encapsulation)
// - Use `virtual` and `override` for polymorphism
// - Use `= 0` for pure virtual → abstraction
// - Use `: public Base` for inheritance
// - Use `new` carefully → must `delete` or use smart pointers

// */


