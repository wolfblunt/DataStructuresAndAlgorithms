# Python Sorting: `sort()` and `sorted()`

This report provides a detailed overview of Python's `sort()` method and `sorted()` function, including definitions, syntax, examples ranging from easy to hard, and explanations. It is designed for easy revision, with clear sections and code snippets. At the end, it addresses the specific example list `[[5, 11], [2,4], [5,6], [5, 7]]`, including how to sort it in ascending/descending order and by custom criteria (e.g., first element ascending and second descending, or vice versa).

---

## Introduction to Sorting in Python

Python provides two primary ways to sort data:
- **`sorted()`**: A built-in function that returns a new sorted list from an iterable (e.g., list, tuple, string) without modifying the original.
- **`sort()`**: A list method that sorts the list in place (modifies the original list) and returns `None`.

Both support sorting in ascending (default) or descending order and allow custom sorting via the `key` parameter (often used with lambda functions) and `reverse` parameter.

### Key Features
- **Stable Sort**: Both use Timsort, which is stable (preserves the relative order of equal elements).
- **In-Place vs. New List**: `sort()` modifies the original; `sorted()` creates a copy.
- **Custom Sorting**: Use `key` to specify a function that returns a sort key for each element.
- **Reverse**: Set `reverse=True` for descending order.

---

## `sorted()` Function

### Definition
The `sorted()` function returns a new sorted list from the elements of any iterable. It does not modify the original iterable.

### Syntax
```python
sorted(iterable, *, key=None, reverse=False)
```
- **`iterable`**: The sequence to sort (e.g., list, tuple, set, string).
- **`key`** (optional): A function that takes one argument and returns a key for comparison (e.g., `lambda x: x[1]`).
- **`reverse`** (optional): If `True`, sorts in descending order.
- **Returns**: A new sorted list.

### Easy Example: Sorting a Simple List
```python
numbers = [5, 3, 8, 1, 9]
sorted_numbers = sorted(numbers)
print(sorted_numbers)  # Output: [1, 3, 5, 8, 9]
print(numbers)        # Output: [5, 3, 8, 1, 9] (original unchanged)
```
- **Explanation**: Sorts the list in ascending order by default. A new list is returned.

### Medium Example: Sorting Strings (Case-Insensitive)
```python
words = ["Banana", "apple", "Cherry"]
sorted_words = sorted(words, key=str.lower)
print(sorted_words)  # Output: ['apple', 'Banana', 'Cherry']
```
- **Explanation**: The `key=str.lower` converts each string to lowercase for comparison, so sorting is case-insensitive. Note: Uppercase letters come before lowercase by default ASCII values.

### Hard Example: Sorting a List of Dictionaries by Multiple Keys
```python
people = [
    {"name": "Alice", "age": 30, "score": 85},
    {"name": "Bob", "age": 25, "score": 90},
    {"name": "Charlie", "age": 30, "score": 80}
]
sorted_people = sorted(people, key=lambda x: (x["age"], -x["score"]))
print(sorted_people)
# Output: [{'name': 'Bob', 'age': 25, 'score': 90}, {'name': 'Charlie', 'age': 30, 'score': 80}, {'name': 'Alice', 'age': 30, 'score': 85}]
```
- **Explanation**: Sorts first by "age" ascending, then by "score" descending (using `-x["score"]` to invert the order). For ties in age (Alice and Charlie), Charlie comes first because 80 > 85 when negated (-80 > -85? Wait, no: -80 is greater than -85 in numerical order, but since higher score should come first in descending, actually for descending higher score, use - to invert. Wait, let's clarify: To sort descending on score, `-x["score"]` makes higher scores have smaller (more negative) keys, so they come first in ascending sort.

---

## `sort()` Method

### Definition
The `sort()` method sorts a list in place (modifies the original list) and returns `None`. It can only be called on lists.

### Syntax
```python
list.sort(*, key=None, reverse=False)
```
- **`key`** (optional): Same as in `sorted()`.
- **`reverse`** (optional): Same as in `sorted()`.
- **Returns**: `None` (modifies the list in place).

### Easy Example: Sorting a Simple List In-Place
```python
numbers = [5, 3, 8, 1, 9]
numbers.sort()
print(numbers)  # Output: [1, 3, 5, 8, 9] (original modified)
```
- **Explanation**: Sorts the list ascending in place. No new list is created.

### Medium Example: Sorting in Descending Order
```python
numbers = [5, 3, 8, 1, 9]
numbers.sort(reverse=True)
print(numbers)  # Output: [9, 8, 5, 3, 1]
```
- **Explanation**: The `reverse=True` sorts in descending order.

### Hard Example: Custom Sorting a List of Tuples
```python
pairs = [(1, 'one'), (3, 'three'), (2, 'two'), (2, 'two-again')]
pairs.sort(key=lambda x: (x[0], x[1]))
print(pairs)  # Output: [(1, 'one'), (2, 'two'), (2, 'two-again'), (3, 'three')]
```
- **Explanation**: Sorts by first element ascending, then by second element (string) ascending. Stable sort preserves order of equal elements (the two (2, ...) tuples).

---

## Key Differences Between `sort()` and `sorted()`

| Feature              | `sorted()`                          | `sort()`                           |
|----------------------|-------------------------------------|------------------------------------|
| **Modifies Original**| No (returns new list)              | Yes (in-place)                     |
| **Applicable To**    | Any iterable (list, tuple, etc.)   | Lists only                         |
| **Return Value**     | New sorted list                    | `None`                             |
| **Use Case**         | When you need the original intact  | When memory efficiency matters     |

- **When to Use**: Use `sorted()` for flexibility or immutability; use `sort()` for performance on large lists (avoids copying).

---

## Examples from Easy to Hard

### Easy: Sorting Numbers
```python
# Ascending
nums = [4, 2, 1, 3]
print(sorted(nums))  # [1, 2, 3, 4]

# Descending
nums.sort(reverse=True)
print(nums)  # [4, 3, 2, 1]
```

### Easy: Sorting Strings
```python
fruits = ["banana", "apple", "cherry"]
print(sorted(fruits))  # ['apple', 'banana', 'cherry']
```

### Medium: Sorting by Length
```python
words = ["python", "is", "awesome"]
words.sort(key=len)
print(words)  # ['is', 'python', 'awesome'] (shortest to longest)
```

### Medium: Sorting Tuples by Second Element
```python
tuples = [(1, 3), (4, 1), (2, 2)]
sorted_tuples = sorted(tuples, key=lambda x: x[1])
print(sorted_tuples)  # [(4, 1), (2, 2), (1, 3)]
```

### Hard: Sorting Mixed Types (with Custom Key)
```python
mixed = [5, "apple", 3, "banana", 1]
# Error if no key: TypeError (can't compare int and str)
# But with key (e.g., convert to str):
sorted_mixed = sorted(mixed, key=str)
print(sorted_mixed)  # [1, 3, 5, 'apple', 'banana']
```
- **Explanation**: Converts everything to string for comparison.

### Hard: Sorting Objects (Custom Class)
```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

people = [Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35)]
people.sort(key=lambda p: p.age)
print([p.name for p in people])  # ['Bob', 'Alice', 'Charlie']
```
- **Explanation**: Sorts instances by the `age` attribute using a lambda key.

### Hard: Multi-Level Sorting with Reverse on Specific Keys
See the dictionary example in `sorted()` section.

---

## Specific Example: Sorting `[[5, 11], [2,4], [5,6], [5, 7]]`

This is a list of sublists (treated as tuples for sorting purposes). By default, Python sorts lexicographically (first element, then second, etc.).

### 1. Sort in Ascending Order (Default: Lexicographical)
```python
data = [[5, 11], [2, 4], [5, 6], [5, 7]]
sorted_data = sorted(data)
print(sorted_data)  # [[2, 4], [5, 6], [5, 7], [5, 11]]
```
- **Explanation**: Sorts by first element asc (2 before 5s), then by second element asc for ties (6 < 7 < 11).

Using `sort()`:
```python
data.sort()
print(data)  # [[2, 4], [5, 6], [5, 7], [5, 11]] (modified in place)
```

### 2. Sort in Descending Order
```python
sorted_data = sorted(data, reverse=True)
print(sorted_data)  # [[5, 11], [5, 7], [5, 6], [2, 4]]
```
- **Explanation**: Reverse lexicographical (highest first element first, then highest second for ties).

### 3. Sort First Index Ascending, Second Descending
```python
sorted_data = sorted(data, key=lambda x: (x[0], -x[1]))
print(sorted_data)  # [[2, 4], [5, 11], [5, 7], [5, 6]]
```
- **Explanation**: `key=lambda x: (x[0], -x[1])` sorts by first element asc, then second desc (negating inverts order: higher x[1] gets smaller key, comes first).

### 4. Sort First Index Descending, Second Ascending
```python
sorted_data = sorted(data, key=lambda x: (-x[0], x[1]))
print(sorted_data)  # [[5, 6], [5, 7], [5, 11], [2, 4]]
```
- **Explanation**: `key=lambda x: (-x[0], x[1])` sorts by first element desc (negating inverts), then second asc for ties.

### Tips for Custom Sorting
- Use tuples in `key` for multi-criteria sorting.
- Negate numerical values (`-x`) to reverse order for that key.
- For strings, use a custom function if needed (e.g., `key=lambda x: (x[0], x[1].lower())` for case-insensitive).

This report is self-contained for revision. Save as a .md file and refer back anytime!