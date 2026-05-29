def score(dice):
    total_score = 0
    for n in range(1, 7):
        n_count = dice.count(n)
        if n_count >= 3:
            total_score += 1000 if n == 1 else n * 100
            n_count -= 3
        if n == 1:
            total_score += n_count * 100
        if n == 5:
            total_score += n_count * 50
    return total_score