def points(games):
    total_points = 0
    for game in games:
        our_team_goals, their_team_goals = map(int, game.split(':'))
        if our_team_goals > their_team_goals:
            total_points += 3
        elif our_team_goals == their_team_goals:
            total_points += 1
    return total_points