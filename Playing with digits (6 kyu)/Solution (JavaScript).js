function digPow(n, p) {
  let sum = 0;
  for (let digit of String(n)) {
    sum += Number(digit) ** p;
    p++;
  }
  return sum % n === 0 ? sum / n : -1;
}