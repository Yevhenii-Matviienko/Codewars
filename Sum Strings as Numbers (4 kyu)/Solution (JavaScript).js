function sumStrings(a, b) {
  let i = a.length - 1;
  let j = b.length - 1;
  let carry = 0;
  const result = [];
  while (i >= 0 || j >= 0 || carry) {
    const digit_a = i >= 0 ? a.charCodeAt(i) - '0'.charCodeAt(0) : 0;
    const digit_b = j >= 0 ? b.charCodeAt(j) - '0'.charCodeAt(0) : 0;
    const total_digits_sum  = digit_a + digit_b + carry;
    result.push(String(total_digits_sum % 10));
    carry = Math.floor(total_digits_sum / 10);
    i--;
    j--;
  }
  const answer = result.reverse().join('').replace(/^0+/, '');
  return answer || '0';
}