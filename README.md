
## 🚀 42 C++ Common Core: Modules 00 - 09

Welcome to the complete collection of my C++ modules. This repository documents the journey from basic C-like syntax and fundamental Object-Oriented Programming concepts to the mastery of templates and the Standard Template Library (STL). All projects are strictly written and compiled under the **C++98 standard**.

---

### 📚 Curriculum Breakdown

The curriculum is divided into 10 modules, each unlocking a new layer of the C++ language.

| Module | Focus Area | Core Concepts Explored |
| --- | --- | --- |
| **CPP 00** | Basics & Encapsulation | Namespaces, classes, member functions, standard I/O streams. |
| **CPP 01** | Memory & References | `new`/`delete`, pointers to members, references, file streams. |
| **CPP 02** | Polymorphism & Forms | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form. |
| **CPP 03** | Inheritance | Base classes, derived classes, access specifiers (`protected`). |
| **CPP 04** | Subtype Polymorphism | Virtual functions, abstract classes, interfaces. |
| **CPP 05** | Exceptions | `try`/`catch` blocks, standard and custom exception handling. |
| **CPP 06** | Type Casting | `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`. |
| **CPP 07** | Templates | Function templates, class templates, generic programming. |
| **CPP 08** | STL Fundamentals | Templated containers, iterators, and the `<algorithm>` header.

 |
| **CPP 09** | STL Advanced | Complex data processing and algorithmic efficiency using the STL. |

---

### 🛠️ Global Rules & Guidelines

Throughout the repository, specific programming constraints are strictly observed:

* All code is compiled using the `c++` compiler.
* Mandatory compilation flags are `-Wall -Wextra -Werror` and `-std=c++98`.
* External libraries (like Boost) and modern C++ features (C++11 onwards) are strictly forbidden.
* Memory leaks are rigorously checked; every `new` has a corresponding `delete`.
* From Module 02 onwards, all classes strictly implement the **Orthodox Canonical Form** (Default Constructor, Copy Constructor, Assignment Operator, Destructor).
* From Module 08 onwards, manual loops for searching or sorting are replaced by the `<algorithm>` library to ensure efficiency.



---

### 💻 Usage

Navigate into any exercise directory and use the provided Makefiles to compile the executable.

```bash
cd cpp04/ex00
make
./<executable_name>

```
