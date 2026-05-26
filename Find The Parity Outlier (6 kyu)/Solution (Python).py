def find_outlier(integers):
    evens_numbers = [number for number in integers if number % 2 == 0]
    odds_numbers = [number for number in integers if number % 2 != 0]
    return evens_numbers[0] if len(evens_numbers) == 1 else odds_numbers[0]