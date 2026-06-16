function duplicateEncode(word) {
  const word_lowercase = word.toLowerCase();
  return [...word_lowercase]
    .map(char => word_lowercase.indexOf(char) === word_lowercase.lastIndexOf(char) ? '(' : ')')
    .join('');
}