function findOutlier(integers) {
  const evens_numbers = integers.filter(integer => integer % 2 === 0);
  const odds_numbers = integers.filter(integer => integer % 2 !== 0);
  return evens_numbers.length === 1 ? evens_numbers[0] : odds_numbers[0];
}