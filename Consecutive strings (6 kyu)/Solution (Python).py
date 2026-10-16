def longest_consec(strarr, k):
    if k <= 0 or k > len(strarr):
        return ""
    concatenated_strings = []
    for index in range(len(strarr) - k + 1):
        concatenated_strings.append("".join(strarr[index : index + k]))
    return max(concatenated_strings, key=len)