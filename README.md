# Learning Sandbox

Daily practice in C++ and Python, organised by topic. The aim is a solid base in programming and data structures before moving on to AI/ML engineering.

## What's inside

| File | What it does |
|---|---|
| `cpp/basics/sum_of_digits.cpp` | Sums the digits of a number using a loop and modulo |
| `cpp/oop/execution_engine.cpp` | Menu-driven task pipeline: abstract base class, polymorphism, `unique_ptr`, file logging |
| `cpp/stl/text_processor.cpp` | Word-frequency counter using `unordered_map`, `vector` and a custom sort |
| `python/raw_python/intent_parser.py` | Keyword-based intent parser written without external libraries |
| `python/pythonic_implementation_of_cpp_code/text_analyzer.py` | The same word-frequency task as the C++ version, using `re` and `Counter` |

## Run

C++ (needs `g++` with C++17):

```bash
g++ -std=c++17 cpp/stl/text_processor.cpp -o text_processor
./text_processor
```

Python (3.8+, standard library only):

```bash
python3 python/raw_python/intent_parser.py
python3 python/pythonic_implementation_of_cpp_code/text_analyzer.py
```

## Current focus

- C++ fundamentals, then data structures and algorithms
- Python foundations for data analysis and ML

## Author

Bhavishya Katare · B.Tech AI & Analytics, Medi-Caps University
[LinkedIn](https://www.linkedin.com/in/bhavishyakatare)
