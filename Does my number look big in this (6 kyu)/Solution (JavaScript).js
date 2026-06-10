function narcissistic(value) {
  let sum = 0;
  let digits = String(value);
  for (let digit of digits) {
    sum += digit ** digits.length;
  }
  return sum === value;
}