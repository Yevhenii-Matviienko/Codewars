function primeFactors(n) {
  let result = '';
  let divisor = 2;
  while (divisor * divisor <= n) {
    let count_divisions = 0;
    while (n % divisor === 0) {
      count_divisions++;
      n = Math.floor(n / divisor);
    }
    if (count_divisions === 1) {
      result += `(${divisor})`;
    } else if (count_divisions > 1) {
      result += `(${divisor}**${count_divisions})`;
    }
    divisor++;
  }
  if (n > 1) {
    result += `(${n})`;
  }
  return result;
}