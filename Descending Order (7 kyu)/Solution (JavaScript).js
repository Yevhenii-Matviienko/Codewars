function descendingOrder(n) {
  return Number(String(n).split('').sort((digit_1, digit_2) => digit_2 - digit_1).join(''));
}