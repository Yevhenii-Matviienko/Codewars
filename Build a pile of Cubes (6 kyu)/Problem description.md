# **Build a pile of Cubes (6 kyu)**

### **Description:**
Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n³, the cube above will have volume of (n − 1)³ and so on until the top which will have a volume of 1³.

You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?

The parameter of the function findNb `(find_nb, find-nb, findNb, ...)` will be an integer m and you have to return the integer n such as n³ + (n − 1)³ + (n − 2)³ + … + 1³ = m if such a n exists or -1 if there is no such n.

**Examples:**

findNb(1071225) --> 45

findNb(91716553919377) --> -1

### **Tags:**
- Mathematics
- Algorithms