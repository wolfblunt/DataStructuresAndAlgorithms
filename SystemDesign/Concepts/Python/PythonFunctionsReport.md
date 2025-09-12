# Python Functional Programming: `lambda`, `map()`, `filter()`, and `reduce()`

This report provides a concise overview of Python’s `lambda`, `map()`, `filter()`, and `reduce()` functions, which are key tools for functional programming. Each function is explained with its definition, syntax, examples, and key points to facilitate revision.

---

## 1. `lambda` Function

### Definition
A `lambda` function is an anonymous, inline function defined using the `lambda` keyword. It is used for creating small, one-off functions without formally defining them using `def`. Lambda functions are often used with `map()`, `filter()`, and `reduce()` for concise code.

### Syntax
```python
lambda arguments: expression
```
- **arguments**: A comma-separated list of input parameters (e.g., `x`, `x, y`).
- **expression**: A single expression evaluated and returned. No statements (e.g., `print`, `if`) are allowed.
- **Returns**: A function object that can be called or passed to other functions.

### Example
```python
# Lambda function to double a number
double = lambda x: x * 2
print(double(5))  # Output: 10
```
- **Explanation**: Defines a function that takes `x` and returns `x * 2`.

### Example with Multiple Arguments
```python
# Lambda function to add two numbers
add = lambda x, y: x + y
print(add(3, 4))  # Output: 7
```

### Example with `map()`
```python
nums = [1, 2, 3]
doubled = list(map(lambda x: x * 2, nums))
print(doubled)  # Output: [2, 4, 6]
```
- **Explanation**: The lambda function `lambda x: x * 2` is applied to each element in `nums`.

### Key Points
- Lambda functions are limited to a single expression and cannot contain statements or multiple lines.
- Best for short, simple operations; use `def` for complex logic to improve readability.
- Commonly used with `map()`, `filter()`, and `reduce()` for inline function definitions.
- Can take multiple arguments but return only one expression’s result.

---

## 2. `map()` Function

### Definition
The `map()` function applies a given function to each item in an iterable (e.g., list, tuple) and returns an iterator of the transformed results. It is used to transform or process all elements without explicit loops.

### Syntax
```python
map(function, iterable, ...)
```
- **function**: A function (e.g., lambda or named function) that takes one or more arguments and returns a transformed value.
- **iterable**: One or more iterables whose elements are processed.
- **Returns**: A map object (iterator). Convert到一个列表使用`list()`。

### Example
```python
nums = [1, 2, 3, 4, 5]
doubled = list(map(lambda x: x * 2, nums))
print(doubled)  # Output: [2, 4, 6, 8, 10]
```
- **Explanation**: Multiplies each element by 2, resulting in `[2, 4, 6, 8, 10]`.

### Example with Multiple Iterables
```python
nums1 = [1, 2, 3]
nums2 = [4, 5, 6]
sums = list(map(lambda x, y: x + y, nums1, nums2))
print(sums)  # Output: [5, 7, 9]
```
- **Explanation**: Adds corresponding elements from two lists.

### Example with Named Function
```python
def square(n):
    return n * n
nums = [1, 2, 3]
squared = list(map(square, nums))
print(squared)  # Output: [1, 4, 9]
```

### Key Points
- Returns an iterator, so convert to a list/tuple to view results.
- Processes all elements, transforming each one.
- Supports multiple iterables (function must accept multiple arguments).
- Similar to list comprehensions (e.g., `[x * 2 for x in nums]`), but can be more efficient for large datasets.
- Stops when the shortest iterable is exhausted (if multiple iterables are used).

---

## 3. `filter()` Function

### Definition
The `filter()` function applies a function to each item in an iterable and returns an iterator containing only the elements for which the function returns `True`. It is used to select elements based on a condition.

### Syntax
```python
filter(function, iterable)
```
- **function**: A function that returns `True` or `False` for each element. If `None`, filters out falsy values (e.g., `0`, `None`, `False`).
- **iterable**: The iterable to filter.
- **Returns**: A filter object (iterator). Convert to a list using `list()`.

### Example
```python
nums = [1, 2, 3, 4, 5, 6]
evens = list(filter(lambda x: x % 2 == 0, nums))
print(evens)  # Output: [2, 4, 6]
```
- **Explanation**: Selects even numbers by checking if `x % 2 == 0`.

### Example with Strings
```python
words = ["cat", "dog", "elephant", "rat"]
short_words = list(filter(lambda x: len(x) <= 3, words))
print(short_words)  # Output: ['cat', 'dog', 'rat']
```
- **Explanation**: Selects words with 3 or fewer characters.

### Example with `None` as Function
```python
values = [0, 1, "", "hello", None, False, True]
truthy_values = list(filter(None, values))
print(truthy_values)  # Output: [1, 'hello', True]
```
- **Explanation**: Filters out falsy values (`0`, `""`, `None`, `False`).

### Key Points
- Returns an iterator, so convert to a list/tuple to view results.
- Only includes elements where the function returns `True`.
- Useful for subset selection without modifying the original iterable.
- Similar to list comprehensions (e.g., `[x for x in nums if x % 2 == 0]`).
- If `None` is used as the function, removes falsy elements.

---

## 4. `reduce()` Function

### Definition
The `reduce()` function, from the `functools` module, applies a function cumulatively to the items of an iterable, reducing it to a single value. It’s used for operations like summing, multiplying, or combining elements.

### Syntax
```python
from functools import reduce
reduce(function, iterable[, initializer])
```
- **function**: A function that takes two arguments (accumulator, next item) and returns a single value.
- **iterable**: The iterable to reduce.
- **initializer** (optional): A starting value for the accumulator.
- **Returns**: A single value.

### Example
```python
from functools import reduce
nums = [1, 2, 3, 4]
product = reduce(lambda x, y: x * y, nums)
print(product)  # Output: 24
```
- **Explanation**: Multiplies all elements: `1 * 2 * 3 * 4 = 24`.

### Example with Initializer
```python
words = ["hello", "world", "python"]
concat = reduce(lambda x, y: x + "-" + y, words, "start")
print(concat)  # Output: start-hello-world-python
```
- **Explanation**: Concatenates strings with a hyphen, starting with `"start"`.

### Example with Named Function
```python
def max_val(x, y):
    return x if x > y else y
nums = [3, 5, 2, 8, 1]
maximum = reduce(max_val, nums)
print(maximum)  # Output: 8
```
- **Explanation**: Finds the maximum value by comparing pairs.

### Key Points
- Requires `from functools import reduce` in Python 3.
- Reduces an iterable to a single value.
- If no `initializer` is provided, the first element is the initial accumulator.
- Raises `TypeError` for an empty iterable without an `initializer`.
- Can be replaced by loops or built-in functions (e.g., `sum()`), but concise for complex reductions.

---

## Comparison of `lambda`, `map()`, `filter()`, and `reduce()`

| Function   | Purpose                              | Input                     | Output                     | Example Output (for `nums = [1, 2, 3, 4]`) |
|------------|--------------------------------------|---------------------------|----------------------------|-------------------------------------------|
| `lambda`   | Defines an anonymous function         | Arguments, expression     | Function object            | `lambda x: x * 2` (doubles input)         |
| `map()`    | Transforms each element              | Iterable                  | Iterator of same length    | `[2, 4, 6, 8]` (doubles each element)     |
| `filter()` | Selects elements based on condition  | Iterable                  | Iterator of subset         | `[2, 4]` (selects even numbers)           |
| `reduce()` | Combines elements into a single value| Iterable                  | Single value               | `24` (multiplies all elements)            |

### Combined Example
```python
from functools import reduce
nums = [1, 2, 3, 4, 5]
# Lambda function used with map, filter, and reduce
mapped = list(map(lambda x: x * 2, nums))       # [2, 4, 6, 8, 10]
filtered = list(filter(lambda x: x % 2 == 0, nums))  # [2, 4]
reduced = reduce(lambda x, y: x * y, nums)       # 120
print(mapped, filtered, reduced)
```

---

## Practical Tips
- **Use Cases**:
  - Use `lambda` for short, inline functions, especially with `map()`, `filter()`, and `reduce()`.
  - Use `map()` for transformations (e.g., scaling numbers, converting data types).
  - Use `filter()` for selecting subsets (e.g., filtering valid records).
  - Use `reduce()` for aggregations (e.g., product, concatenation).
- **Performance**: These functions are efficient for large datasets as `map()` and `filter()` work with iterators, but list comprehensions or built-in functions (e.g., `sum()`) may be more readable or faster in some cases.
- **Readability**: Lambda functions are concise but can reduce readability for complex logic; use named `def` functions for clarity in such cases.
- **Edge Cases**:
  - `map()` and `filter()` return iterators, so convert to lists for immediate use.
  - `reduce()` requires an `initializer` for empty iterables to avoid errors.
  - For multiple iterables in `map()`, the function must handle multiple arguments.
  - Lambda functions are limited to a single expression, so complex logic may require a named function.

This report serves as a quick reference for revising `lambda`, `map()`, `filter()`, and `reduce()`. Save and revisit as needed!