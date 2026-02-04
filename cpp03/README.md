
# CPP03 Module: Inheritance and Polymorphism

This module demonstrates C++ inheritance through a robot combat system with three progressive exercises.

## Overview

The module implements a class hierarchy where `ClapTrap` serves as the base class, with `ScavTrap` and `FragTrap` as derived classes.

Each robot has hit points (HP), energy points (EP), and attack damage (AD), with actions consuming energy.

---

## Exercise 00: ClapTrap Base Class

### Objective

Implement the base robot class with Orthodox Canonical Form.

### Class Structure

The `ClapTrap` class includes:

**Attributes**

* `_name`
* `_hitPoints` (10)
* `_energyPoints` (10)
* `_attackDamage` (0)

**Methods**

* `attack()`
* `takeDamage()`
* `beRepaired()`
* `status()`

---

### Combat Mechanics

Actions require both energy and health to execute:

* **attack():** Costs 1 EP, deals damage to target
* **takeDamage():** Reduces HP, handles fatal damage
* **beRepaired():** Costs 1 EP, restores HP

---

### Orthodox Canonical Form

All five required constructors/operators are implemented:

* Default constructor
* Parameterized constructor
* Copy constructor
* Copy assignment operator
* Destructor

```cpp
ClapTrap();
```

Default constructor. Initializes robot with name `_default`, HP = 10, EP = 10, AD = 0.

```cpp
ClapTrap(std::string name);
```

Parameterized constructor. Initializes robot with custom name and default stats.

```cpp
ClapTrap(const ClapTrap& copy);
```

Copy constructor. Creates a new robot by copying all attributes.

```cpp
ClapTrap& operator=(const ClapTrap& copy);
```

Copy assignment operator. Assigns all attributes with self-assignment protection.

```cpp
~ClapTrap();
```

Destructor. Cleans up the robot instance and displays `"GAME OVER"`.

---

### Common Methods

```cpp
void attack(const std::string& target);
```

Costs 1 EP. Requires EP > 0 and HP > 0.

```cpp
void takeDamage(unsigned int amount);
```

Reduces HP by damage amount. Sets HP to 0 if damage is fatal.

```cpp
void beRepaired(unsigned int amount);
```

Restores HP by amount. Costs 1 EP. Requires EP > 0 and HP > 0.

```cpp
void status() const;
```

Displays current robot status (name, HP, EP, AD) with color-coded output.

---

### Notes

* The same OCF methods are inherited and properly implemented in both `ScavTrap` and `FragTrap`.
* Common methods are inherited by derived classes.
* `attack()` is overridden in both derived classes to provide class-specific output.

### Testing

The main demonstrates energy depletion through repeated attacks until failure.

---

## Exercise 01: ScavTrap Inheritance

### Objective

Create a derived class demonstrating public inheritance and constructor chaining.

### Enhanced Stats

ScavTrap overrides base stats:

* HP: 100 (10× base)
* EP: 50 (5× base)
* AD: 20

---

### Constructor Chaining

The parameterized constructor calls the base class constructor via initialization list:

```cpp
ScavTrap::ScavTrap() : ClapTrap()
```

This ensures proper initialization before setting derived-class-specific values.

---

### Why Constructor Chaining Matters

* **Base class construction happens first**
* **Protected member access** allows direct modification in derived classes
* **Two-phase initialization**

  * Base sets defaults (HP=10, EP=10, AD=0)
  * Derived overrides with specialized values

---

### Method Overriding

ScavTrap overrides `attack()` with identical logic but class-specific output.

---

### Special Ability

```cpp
void guardGate();
```

Activates **Gate keeper mode**.

---

### Testing

The main tests all constructors and demonstrates the special ability.

---

## Exercise 02: FragTrap Inheritance

### Objective

Add a second derived class with different specialization.

### Maximum Stats

FragTrap has the highest stats:

* HP: 100
* EP: 100 (highest)
* AD: 30 (highest)

---

### Special Ability

```cpp
void highFivesGuys();
```

Provides a friendly interaction unique to FragTrap.

---

### Virtual Functions

In ex02, the base class uses `virtual` for:

* Destructor
* `attack()`

This enables proper polymorphism.

---

### Testing

The main includes both `ScavTrap` and `FragTrap`, demonstrating multiple derived classes coexisting.

---

## Build System

Each exercise has its own Makefile with progressive source inclusion:

* **ex00:** `main.cpp`, `ClapTrap.cpp`
* **ex01:** Adds `ScavTrap.cpp`
* **ex02:** Adds `FragTrap.cpp`

All enforce C++98 standard compliance.

---

## Summary Notes

The module progressively teaches:

* Orthodox Canonical Form (ex00)
* Single inheritance with constructor chaining (ex01)
* Multiple derived classes with virtual functions (ex02)

The combat system provides practical context for understanding resource management and polymorphic behavior. The `protected` access specifier allows derived classes to directly modify inherited attributes.
