def multi_table(number):
    return "\n".join(f"{multiplier} * {number} = {multiplier * number}" for multiplier in range(1, 11))