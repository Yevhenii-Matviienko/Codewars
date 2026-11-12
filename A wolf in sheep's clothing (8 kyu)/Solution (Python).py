def warn_the_sheep(queue):
    іndex_sheep_risk = queue[ : : -1].index("wolf")
    if іndex_sheep_risk == 0:
        return "Pls go away and stop eating my sheep"
    return f"Oi! Sheep number {іndex_sheep_risk}! You are about to be eaten by a wolf!"