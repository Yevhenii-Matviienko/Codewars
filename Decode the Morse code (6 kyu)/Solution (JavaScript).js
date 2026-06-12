decodeMorse = function(morseCode) {
  let result = '';
  const words = morseCode.trim().split('   ');
  for (let word of words) {
    const letters = word.split(' ');
    for (let letter of letters) {
      result += MORSE_CODE[letter];
    }
    result += ' ';
  }
  return result.trim();
}