def tribonacci(signature, n):
    sequence = list(signature[ : n])
    while len(sequence) < n:
        sequence.append(sum(sequence[-3 : ]))
    return sequence