function count(string) {
  const result = {};
  for (const char of string) {
    if (result[char]) {
      result[char]++;
    } else {
      result[char] = 1;
    }
  }
  return result;
}