def sum_strings(x, y):
    i, j = len(x) - 1, len(y) - 1
    carry = 0
    result = []
    while i >= 0 or j >= 0 or carry:
        a = ord(x[i]) - ord('0') if i >= 0 else 0
        b = ord(y[j]) - ord('0') if j >= 0 else 0
        total_digits_sum = a + b + carry
        result.append(str(total_digits_sum % 10))
        carry = total_digits_sum // 10
        i -= 1
        j -= 1
    answer = ''.join(reversed(result)).lstrip('0')
    return answer or '0'