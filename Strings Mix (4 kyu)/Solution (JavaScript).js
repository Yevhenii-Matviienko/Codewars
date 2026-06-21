function mix(s1, s2) {
  const count_symbols = string => [...string].reduce((amount, char) => {
    if (char >= 'a' && char <= 'z') {
      amount[char] = (amount[char] || 0) + 1;
    }
    return amount;
  }, {});
  
  const count_symbols_1 = count_symbols(s1);
  const count_symbols_2 = count_symbols(s2);
  return [...'abcdefghijklmnopqrstuvwxyz']
    .map(char => {
      const number_symbol_s1 = count_symbols_1[char] || 0;
      const number_symbol_s2 = count_symbols_2[char] || 0;
      const max_number_symbol = Math.max(number_symbol_s1, number_symbol_s2);
      if (max_number_symbol <= 1) return '';
      return (number_symbol_s1 > number_symbol_s2 ? '1:' : 
        number_symbol_s2 > number_symbol_s1 ? '2:' : '=:') + char.repeat(max_number_symbol);
    })
    .filter(Boolean)
    .sort((element_1, element_2) => element_2.length - element_1.length || (element_1 < element_2 ? -1 : 1))
    .join('/');
}