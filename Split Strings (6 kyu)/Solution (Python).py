def solution(s):
    s += '_' if len(s) % 2 else ''
    return [s[index : index + 2] for index in range(0, len(s), 2)]