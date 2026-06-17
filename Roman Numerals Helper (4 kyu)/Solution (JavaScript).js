class RomanNumerals {
  static decimal_roman_numbers = [
    [1000, "M"],
    [900, "CM"],
    [500, "D"],
    [400, "CD"],
    [100, "C"],
    [90, "XC"],
    [50, "L"],
    [40, "XL"],
    [10, "X"],
    [9, "IX"],
    [5, "V"],
    [4, "IV"],
    [1, "I"],
  ];

  static toRoman(num) {
    let result = "";
    for (const [decimal_number, roman_number] of RomanNumerals.decimal_roman_numbers) {
      while (num >= decimal_number) {
        result += roman_number;
        num -= decimal_number;
      }
    }
    return result;
  }

  static fromRoman(str) {
    let result = 0;
    let index = 0;
    for (const [decimal_number, roman_number] of RomanNumerals.decimal_roman_numbers) {
      while (str.slice(index, index + roman_number.length) === roman_number) {
        result += decimal_number;
        index += roman_number.length;
      }
    }
    return result;
  }
}