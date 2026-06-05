from collections import Counter

def mix(s1, s2):
    count_symbols_1 = Counter(filter(str.islower, s1))
    count_symbols_2 = Counter(filter(str.islower, s2))
    result_parts = [
        ('1:' if count_symbols_1[char] > count_symbols_2[char] else 
        '2:' if count_symbols_2[char] > count_symbols_1[char] else '=:') 
        + char * max(count_symbols_1[char], count_symbols_2[char])
        for char in 'abcdefghijklmnopqrstuvwxyz'
        if max(count_symbols_1[char], count_symbols_2[char]) > 1
    ]
    return '/'.join(sorted(result_parts, key=lambda x: (-len(x), x)))