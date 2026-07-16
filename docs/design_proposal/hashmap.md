# HashMap Design Proposal

## Overview

This document describes the design of a generic `HashMap<K, V>` implemented using C++ templates. The implementation stores key-value pairs using **separate chaining**, where each bucket is represented as a linked list. Buckets are managed using a custom `Vector` class containing `Linkedlist<HashNode<K,V>>` objects. Hash values are generated through the `Hashcode` class, making the implementation generic for multiple key types.

---

## Class Structure

### Hashcode

```cpp
class Hashcode
{
public:
    Hashcode();

    int hash(const int s, int size);
    int hash(const string s, int size);
    int hash(const char a, int size);

    template<typename T>
    int hash(const T& obj, int size);
};
```

The `Hashcode` class computes bucket indices for different key types.

- Supports integer keys.
- Supports character keys.
- Supports string keys.
- Supports generic user-defined types through templates.

---

### HashNode

```cpp
template<typename K, typename V>
class HashNode
{
public:
    K Key;
    V Value;

    HashNode(const K& key,const V& value);

    bool operator==(const HashNode& hs) const;
    bool operator!=(const HashNode& hs) const;
};
```

Each node stores:

- **Key** : Unique identifier.
- **Value** : Associated value.
- Comparison operators for equality and inequality.

---

### HashMap Members

```cpp
Vector<Linkedlist<HashNode<K,V>>> v;
int count;
float load_factor;
```

- `v` : Vector containing linked-list buckets.
- `count` : Number of stored key-value pairs.
- `load_factor` : Ratio of elements to buckets used for rehashing.

---

## Memory Layout

```
Bucket Vector

0 -> NULL
1 -> NULL
2 -> NULL
3 -> NULL
...
```

Collision example:

```
Bucket 2

↓

(Key1, Value1)

↓

(Key2, Value2)

↓

(Key3, Value3)

↓

NULL
```

---

## Constructor

```cpp
HashMap();
```

Responsibilities:

- Create the initial bucket vector.
- Initialize all buckets as empty linked lists.
- Initialize `count` to `0`.
- Initialize the load factor.

---

### MEMMORY DIAGRAM

![memory diagram](/docs/design_proposal/images/images/ChatGPT%20Image%20Jul%208,%202026,%2005_08_16%20PM.png)

---

## Hash Functions

```cpp
int hash(const int s,int size);
int hash(const string s,int size);
int hash(const char s,int size);

template<typename T>
int hash(const T& obj,int size);
```

The `Hashcode` class provides overloaded hash functions for different key types.

Example:

```
Key = 27
Buckets = 10

27 % 10 = 7
```

---

## Insertion (push)

```cpp
void push(const K& key,const V& val);
```

Algorithm:

1. Compute the current load factor.
2. If the load factor exceeds **0.75**, call `rehash()`.
3. Compute the bucket index using the hash function.
4. Create a new `HashNode`.
5. Insert the node into the appropriate linked list.
6. Increment the element count.

Average complexity: **O(1)**

Worst case: **O(n)**

---

## Searching

```cpp
HashNode<K,V>* find(const K& key);
```

Searches the appropriate bucket for the specified key.

Returns:

- Pointer to the matching node if found.
- `nullptr` otherwise.

Average complexity: **O(1)**

Worst case: **O(n)**

---

## Deletion

```cpp
void pop(const K& key);
```

Algorithm:

1. Compute bucket index.
2. Traverse the linked list.
3. Remove the matching node.
4. Update the element count.

Average complexity: **O(1)**

Worst case: **O(n)**

---

## Collision Resolution

Separate chaining stores multiple elements in the same bucket.

```
Bucket 5

↓

(Key1, Value1)

↓

(Key2, Value2)

↓

(Key3, Value3)

↓

NULL
```

---

## Load Factor

```
Load Factor = Number of Elements / Number of Buckets
```

When the load factor exceeds **0.75**, the table is resized by calling `rehash()`.

---

## Rehashing

```cpp
void rehash();
```

Steps:

1. Store the current bucket vector.
2. Increase the number of buckets.
3. Allocate a new bucket vector.
4. Traverse every linked list.
5. Recompute bucket indices.
6. Reinsert every element.
7. Replace the old bucket vector.

Complexity: **O(n)**

---

## Copy Constructor

```cpp
HashMap(const HashMap& hs);
```

Creates a deep copy of another hash map by copying all buckets and key-value pairs.

---

## Assignment Operator

```cpp
HashMap& operator=(const HashMap& hs);
```

Assigns one hash map to another while handling self-assignment and copying all stored elements.

---

## Subscript Operator

```cpp
V& operator[](const K& key);
```

Provides array-style access to stored values.

If the key exists, its value is returned.

If the key does not exist, a default value is inserted and returned.

Example:

```cpp
HashMap<string,int> mp;

mp["Age"] = 20;

cout << mp["Age"];
```

Average complexity: **O(1)**

---

## Keys

```cpp
void keys() const;
```

Traverses every bucket and prints all stored keys.

Useful for debugging and verifying the contents of the hash map.

Complexity: **O(n)**

---

## Time Complexity

| Operation | Average | Worst |
|-----------|---------|--------|
| push | O(1) | O(n) |
| find | O(1) | O(n) |
| pop | O(1) | O(n) |
| operator[] | O(1) | O(n) |
| rehash | O(n) | O(n) |

---

## Design Decisions

- Generic implementation using C++ templates.
- Separate chaining for collision handling.
- Buckets implemented using custom `Linkedlist`.
- Bucket storage managed through a custom `Vector`.
- Generic hashing through the `Hashcode` class.
- Dynamic resizing using `rehash()`.
- Support for copy construction and assignment.
- Overloaded `operator[]` for convenient access.
- `keys()` utility function for displaying stored keys.