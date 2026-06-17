function incrementString(strng) {
  const number = strng.match(/\d*$/)[0];
  const text = number ? strng.slice(0, -number.length) : strng;
  return text + String(Number(number || 0) + 1).padStart(number.length, "0");
}