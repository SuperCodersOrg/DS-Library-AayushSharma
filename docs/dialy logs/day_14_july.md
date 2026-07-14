# Daily Log
**Date:** 14 July 2026

## Objective

Continue the development of the **C++ Data Structures Library** by strengthening the testing framework, improving project organization, validating template containers using user-defined types, and researching debugging and memory analysis techniques.

---

# Work Completed

## 1. GoogleTest Integration

- Verified project directory structure.
- Configured CMake for GoogleTest.
- Organized the project into separate build and test targets.
- Added automatic GoogleTest discovery.
- Successfully compiled and executed the testing framework.

---

## 2. Vector Testing

Developed a comprehensive unit testing suite for the custom Vector implementation.

### Test modules created

- Constructor
- push_back()
- pop_back()
- Size()
- Capacity()
- isempty()
- operator[]
- Assignment Operator
- Copy Constructor

### Activities

- Implemented multiple test cases for each function.
- Tested normal cases.
- Tested edge cases.
- Tested exception handling.
- Corrected capacity-related expectations according to the implementation.

---

## 3. LinkedList Testing

Designed and implemented a complete testing suite for the custom LinkedList.

### Test modules created

- Constructor
- push()
- pop()
- delete_any()
- Size()
- isempty()
- operator[]
- Assignment Operator
- Copy Constructor

### Activities

- Verified insertion and deletion operations.
- Tested deep copy behaviour.
- Validated assignment operator.
- Checked exception handling.
- Executed complete LinkedList test suite.

---

## 4. User-Defined Template Validation

Created a custom **Student** class to verify template compatibility.

### Vector

Validated

- push_back()
- pop_back()
- operator[]
- Copy Constructor
- Assignment Operator
- Deep Copy
- Exception Handling

### LinkedList

Validated

- push()
- pop()
- delete_any()
- operator[]
- Copy Constructor
- Assignment Operator
- Deep Copy
- Exception Handling

Confirmed that both containers work correctly with user-defined data types.

---

## 5. CMake Improvements

Updated the build configuration by

- Adding all Vector test files.
- Adding all LinkedList test files.
- Improving project organization.
- Verifying automatic test discovery.
- Successfully rebuilding the project.

---

## 6. Debugging and Research

Investigated and resolved issues related to

- GoogleTest include paths
- CMake configuration
- Test execution
- Copy constructor expectations
- Assignment operator behaviour
- Template compilation
- User-defined template support

---

## 7. Memory Analysis Research

Studied

- Address Sanitizer
- Leak detection
- GoogleTest debugging workflow
- Sanitizer integration with CMake
- Memory debugging tools available on macOS

Configured the project to support sanitizer-based debugging for future testing.

---

# Test Execution Summary

Successfully executed the complete GoogleTest suite containing approximately **100 unit tests**.

Verified

- Vector functionality
- LinkedList functionality
- User-defined template support
- Exception handling
- Copy semantics
- Assignment operations

---

# Skills Strengthened

- Modern C++
- Template Programming
- Dynamic Memory Management
- Manual Memory Handling
- GoogleTest Framework
- Unit Testing
- Integration Testing
- CMake Build System
- Debugging Techniques
- Software Testing Best Practices

---

# Challenges Faced

- Capacity-related test failures
- Copy constructor expectations
- GoogleTest include path configuration
- CMake test integration
- Sanitizer configuration
- User-defined template validation

---

# Outcome

Successfully transformed the project into a well-structured, unit-tested C++ Data Structures Library with an organized GoogleTest framework, automated build configuration, comprehensive Vector and LinkedList test coverage, and support for testing user-defined template types. The project is now better prepared for future implementation and testing of additional data structures such as HashMap.