def solution(start, finish):
    shelves_difference = finish - start
    return shelves_difference // 3 + shelves_difference % 3