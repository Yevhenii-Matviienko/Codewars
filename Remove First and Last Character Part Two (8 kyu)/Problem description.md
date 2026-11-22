# **Remove First and Last Character Part Two (8 kyu)**

### **Description:**
This is a spin off of [<u>my first kata</u>](https://www.codewars.com/kata/56bc28ad5bdaeb48760009b0).

You are given a string containing a sequence of character sequences separated by commas.

Write a function which returns a new string containing the same character sequences except the first and the last ones but this time separated by spaces.

If the input string is empty or the removal of the first and last items would cause the resulting string to be empty, return an empty value (represented as a generic value `NULL` in the examples below).

**Examples**
```python
"1,2,3"     => "2"
"1,2,3,4"   => "2 3"
"1,2,3,4,5" => "2 3 4"

""    => None
"1"   => None
"1,2" => None
```

### **Tags:**
- Fundamentals
- Arrays
- Strings