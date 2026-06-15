function score(dice) {
  let total_score = 0;
  for (let n = 1; n <= 6; n++) {
    let n_count = dice.filter(die => die === n).length;
    if (n_count >= 3) {
      total_score += n === 1 ? 1000 : n * 100;
      n_count -= 3;
    }
    if (n === 1) {
      total_score += n_count * 100;
    }
    if (n === 5) {
      total_score += n_count * 50;
    }
  }
  return total_score;
}