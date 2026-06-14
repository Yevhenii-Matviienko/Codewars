function solution(start, finish) {
  const shelves_difference = finish - start;
  return Math.floor(shelves_difference / 3) + shelves_difference % 3;
}