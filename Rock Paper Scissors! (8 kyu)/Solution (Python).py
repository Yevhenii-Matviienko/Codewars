def rps(p1, p2):
    beat_pairs = {"rock": "scissors", "scissors": "paper", "paper": "rock"}
    if p1 == p2:
        return "Draw!"
    return "Player 1 won!" if beat_pairs[p1] == p2 else "Player 2 won!"