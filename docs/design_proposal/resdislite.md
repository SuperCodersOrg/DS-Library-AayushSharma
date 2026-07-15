# RedisLite Design Proposal

**Project Name:** RedisLite  
**Version:** 1.0  
**Language:** C++20  
**Author:** Aayush Sharma

---

# 1. Introduction

RedisLite is a lightweight, in-memory key-value database implemented completely from scratch using custom C++ data structures. The project is inspired by Redis and aims to provide a simplified command-line interface (CLI) for storing, retrieving, deleting, and managing key-value pairs efficiently.

Unlike Redis, which is implemented in C and contains numerous advanced features such as persistence, networking, transactions, replication, clustering, and pub/sub, RedisLite focuses on understanding the core concepts behind an in-memory database by implementing every major component manually.

The project does not rely on STL containers such as `std::unordered_map`, `std::vector`, or `std::list`. Instead, custom implementations of Vector, Linked List, and Hash Map are used throughout the system.

---

# 2. Objectives

The primary objectives of RedisLite are:

- Learn the internal working of an in-memory database.
- Understand hashing and collision resolution.
- Design reusable generic data structures.
- Implement an interactive command-line interface.
- Develop modular and maintainable C++ code.
- Practice template programming.
- Understand memory management without relying on STL containers.
- Build a scalable foundation for future Redis-like features.

---

# 3. Problem Statement

Traditional databases require disk I/O for every operation which introduces latency.

Redis solves this by storing data entirely in memory.

RedisLite attempts to recreate this concept by storing key-value pairs inside a custom hash map built completely from scratch.

The system should provide:

- Fast insertion
- Fast searching
- Fast deletion
- Efficient collision handling
- Interactive terminal interface

---

# 4. Functional Requirements

The system shall support the following commands.

## SET

Stores a key-value pair.

```
SET name Aayush
```

Output

```
Successful
```

---

## GET

Returns the value associated with a key.

```
GET name
```

Output

```
Aayush
```

---

## DEL

Deletes a key from the database.

```
DEL name
```

---

## EXISTS

Checks whether a key exists.

```
EXISTS name
```

Output

```
1
```

or

```
0
```

---

## KEYS

Displays all keys currently present inside the database.

```
KEYS
```

Output

```
name
age
city
```

---

## SIZE

Displays the number of stored key-value pairs.

```
SIZE
```

Output

```
3
```

---

## EXIT

Terminates the application.

```
EXIT
```

---

# 5. System Architecture

```
                 User

                  │

                  ▼

        Command Line Interface

                  │

                  ▼

        Command Parser (stringstream)

                  │

                  ▼

            RedisLite Class

                  │

                  ▼

      HashMap<string,string>

                  │

          ┌───────┴────────┐

          ▼                ▼

     Custom Vector     Custom Linked List

                  │

                  ▼

             Dynamic Memory
```

---

# 6. Project Structure

```
RedisLite

│

├── include
│      Vector.h
│      List.h
│      HashMap.h
│
├── src
│      Vector.tpp
│      List.tpp
│      HashMap.tpp
│
├── tests
│      Google Test Files
│
├── main.cpp
│
├── CMakeLists.txt
│
└── build
```

---

# 7. Major Components

## 7.1 Vector

A custom dynamic array implementation.

Responsibilities

- Dynamic memory allocation
- Automatic resizing
- Random access
- Copy constructor
- Assignment operator
- Bounds checking

Important Functions

```
push_back()

pop_back()

operator[]

Size()

Capacity()

isempty()
```

---

## 7.2 Linked List

Used for collision handling.

Responsibilities

- Store hash nodes
- Insert node
- Delete node
- Search node
- Sequential traversal

Important Functions

```
push()

pop()

delete_any()

operator[]

Size()

isempty()
```

---

## 7.3 Hash Function

Responsible for converting keys into bucket indices.

Implemented for

```
int

char

string

user defined objects
```

For user-defined classes,

```
formhash()
```

is used.

Example

```cpp
class Student
{
public:

    int roll;

    int formhash() const
    {
        return roll;
    }
};
```

---

# 8. HashMap Design

The HashMap is the core data structure.

Template

```cpp
HashMap<Key,Value>
```

Internally

```
Vector

↓

LinkedList

↓

HashNode
```

Each bucket contains a linked list.

---

# 9. Collision Resolution

RedisLite uses

## Separate Chaining

Example

```
Bucket 0

Bucket 1

A

↓

B

↓

C

Bucket 2
```

Every bucket stores a linked list of nodes.

Advantages

- Simple implementation
- Efficient insertion
- Efficient deletion
- Easy rehashing

---

# 10. Rehashing

Whenever

```
Load Factor ≥ 0.75
```

the number of buckets doubles.

Old entries are rehashed into the new table.

Benefits

- Reduces collisions
- Improves lookup speed
- Maintains O(1) average complexity

---

# 11. RedisLite Class

RedisLite acts as a wrapper around HashMap.

Members

```cpp
HashMap<string,string> hm;
```

Supported operations

```
set()

get()

del()

exists()

keys()

size()
```

The class hides internal implementation details from the user.

---

# 12. Command Processing

The application continuously waits for user input.

```
getline(cin,input)
```

Entire command

```
SET name Aayush
```

is stored.

Then

```
stringstream
```

splits the command.

```
command

↓

key

↓

value
```

Commands are converted into lowercase using

```
tolower()
```

to provide case-insensitive command execution.

---

# 13. Program Flow

```
Start Program

      │

      ▼

Initialize RedisLite

      │

      ▼

Read Command

      │

      ▼

Convert to Lowercase

      │

      ▼

Parse Command

      │

      ▼

Execute Function

      │

      ▼

Display Output

      │

      ▼

Repeat until EXIT
```

---

# 14. Memory Management

The project manually manages memory using

```
malloc()

free()

placement new

explicit destructor calls
```

No STL containers are used internally.

Every allocated object is properly destroyed.

Google Test along with AddressSanitizer is used to detect

- Memory leaks
- Invalid access
- Double free
- Heap overflow

---

# 15. Testing Strategy

Google Test is used for unit testing.

Components tested

### Vector

- Constructor
- Copy Constructor
- Assignment Operator
- push_back()
- pop_back()
- Capacity
- Size
- Index Operator
- User-defined object

### Linked List

- Constructor
- Push
- Pop
- Delete
- Assignment
- Copy Constructor
- Index Operator
- User-defined object

AddressSanitizer validates memory correctness.

---

# 16. Time Complexity

| Operation | Complexity |
|------------|-----------|
| SET | O(1) Average |
| GET | O(1) Average |
| DEL | O(1) Average |
| EXISTS | O(1) Average |
| SIZE | O(1) |
| KEYS | O(n) |
| Rehash | O(n) |

---

# 17. Advantages

- Generic template implementation.
- Completely STL independent.
- Dynamic resizing.
- Collision handling.
- Modular design.
- Memory efficient.
- Easy to extend.
- Educational implementation of Redis principles.

---

# 18. Current Limitations

- Supports only in-memory storage.
- No persistence.
- No networking.
- Single-threaded.
- No authentication.
- No expiration of keys.
- No transactions.
- No replication.
- No publish-subscribe mechanism.

---

# 19. Future Enhancements

The following features can be incorporated in future versions:

- Persistent storage using files.
- Multi-threading support.
- Socket programming for remote clients.
- Expiry (TTL) support.
- Authentication system.
- Multiple databases.
- Lists.
- Sets.
- Sorted Sets.
- Streams.
- Transactions.
- Publish-Subscribe messaging.
- RDB Snapshot support.
- AOF logging.
- Configuration file parser.
- Benchmarking module.

---

# 20. Conclusion

RedisLite successfully demonstrates the design and implementation of a lightweight in-memory key-value database using completely custom-built data structures. The project emphasizes low-level memory management, generic programming with templates, hashing techniques, collision resolution using separate chaining, and dynamic rehashing. By combining a custom Vector, Linked List, and HashMap with a command-line interface, RedisLite provides efficient operations for storing, retrieving, deleting, and managing key-value pairs. Beyond its educational value, the modular architecture establishes a strong foundation for incorporating advanced Redis-inspired features such as persistence, networking, key expiration, transactions, and distributed capabilities in future releases.