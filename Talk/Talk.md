---
marp: true
theme: uncover
_class: invert
_paginate: skip
---

# **Embedded TDD**

_For Cambridge Software Crafters_
_13 March 2024_

Brice Fernandes 
brice@fractallambda.com

[![width:200px](assets/by-sa.png)](https://creativecommons.org/licenses/by-sa/4.0/)

---
<!-- paginate: true -->

# Logistics and Wifi

🚽 Behind the main screen to the right of the corridor.

🛜 Wifi is **The Bradfield Centre** password is **Ca3Br1d5e**

🚨 We do not expect alarms. Assume a fire alarm is real and make your way to the car park.

---

# Plan for this evening

1. Intro
2. What is "Embedded"
3. Embedded craftsmanship
4. Using Replit
5. The Katas
    1. LED Driver Kata 
    2. Interrupt Kata
6. Recap

---

<!-- _class: invert -->

# Intro

---

## Why this talk?

---

# TDD Loop

![bg left width:100%](assets/r-g-r.png)


<span style="color: red; font-weight:bold">Write a failing test</span>

<span style="color: green; font-weight:bold">Make the test pass</span>

<span style="color: orange; font-weight:bold">Refactor the code</span>

--- 
<!-- _class: invert -->

![bg fit](assets/arrange-act-assert.png)

---

# Ping Pong TDD
![bg right](assets/ping-pong-tdd.png)

---
<!-- _class: invert -->

# What is "Embedded"

---

# Embedded constraints

- Resource constraints (RAM, CPU)
- Lack of standard libraries
- No or limited filesystem
- Limited Interface (serial? UART, SWI)
- No Operating System
- No standard library
- Direct hardware access
- Lack of MMU/PMMU

--- 

# Special pains

- Late hardware delivery
- Hardware scarcity
- Hardware bugs
- Long target compile times
- Long target setup and upload time
- Compiler licenses

---
<!-- _class: invert -->

# Embedded Craftsmanship

---

# Dual targeting

- Dual targeting
  - Simulate hard-to-duplicate conditions
  - Target bottleneck
  - Running the test suite on the target

---

# Embedded TDD Cycles

![width:1080px](./assets/tdd-cycles.png)

---

# CI and automated HW tests

  
---

# Advanced Mocking

Advanced Mocking
    1. Mock the clock
    2. Test doubles
      1. Code structure & Link time substitution
      2. Function pointer substitution
      3. Syntactic substitution (preprocessor)
      
---

# Simulators

---

# SOLID

  1. Single Responsibility Principle
  2. Open Closed Principle
  3. Liskov Substitution Principle
  4. Interface Segregation Principle
  5. Dependency Inversion Priciple


---
<!-- _class: invert -->

# Using Replit

Create a [replit.com](https://replit.com/) account 

(use a throwaway email if you'd like)

---

![bg cover](assets/replit-home.png)

---
<style scoped>
h1{
  margin-top: 500px;
  color: white;
}
</style>
![bg cover](assets/replit-create.png)
# 1. Create a new Repl

---

![bg cover](assets/replit-create-2.png)
<style scoped>
h1{
  margin-top: 500px;
  color: white;
}
</style>
# 2. Import from Github
---

![bg cover](assets/replit-create-3.png)
<style scoped>
h1{
  margin-top: 0px;
  color: white;
}
pre {
  font-size: xxx-large;
  margin-top:450px;
}
</style>
# 3. Choose "From URL"

```
https://github.com/bricef/embedded-tdd-katas.git
```
---

![bg cover](assets/replit-create-4.png)
<style scoped>
h1{
  margin-top: 0px;
  color: white;
}
pre {
  margin-top:450px;
  font-size: xxx-large;
}
</style>
# 4. Choose 'C' as a language

```
https://github.com/bricef/embedded-tdd-katas.git
```

---

<!-- project page -->
![bg cover](assets/replit-c-project.png)

---

<!-- clone repo -->
# Local alternative
If you're confident in your local toolchain

Clone the repository locally:
```shell
$ git clone https://github.com/bricef/embedded-tdd-katas.git
```

---

<style scoped>
h1{
  margin-top: 0px;
  color: white;
  text-align:left;
}
h2 {
  margin-top:450px;
  color:white;
  text-align:right;
  font-size: xxxx-large;
}
</style>
# KEEP CALM
## IT'S DEMO TIME
![bg cover](assets/demo-time.jpg)



---

<!-- _class: invert -->

# The Katas

---

# LED Driver Kata 

---

# Interrupt Kata

---
<!-- _class: invert -->

# Recap

---

# What we learnt

--- 

### Further Reading

![bg right width:80%](assets/tdd-book-cover.jpg)

- [TDD for Embedded C](https://pragprog.com/titles/jgade/test-driven-development-for-embedded-c/)
- [ThrowTheSwitch.org](https://www.throwtheswitch.org/)
- [Unity Test Framework](https://github.com/ThrowTheSwitch/Unity)


---
<!-- _class: invert -->

# Thank you

# 🙏

## Q&A

# ❓
