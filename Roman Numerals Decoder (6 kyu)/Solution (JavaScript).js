function solution(roman) {
  const roman_decimal_numbers = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };
  let result = 0;
  for (let index = 0; index < roman.length; index++) {
    const current_decimal_digit = roman_decimal_numbers[roman[index]];
    const next_decimal_digit = roman_decimal_numbers[roman[index + 1]];
    if (current_decimal_digit < next_decimal_digit) {
      result -= current_decimal_digit;
    } else {
      result += current_decimal_digit;
    }
  }
  return result;
}