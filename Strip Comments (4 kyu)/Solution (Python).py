def strip_comments(strng, markers):
    return '\n'.join(
        min((string_line.split(marker)[0] for marker in markers if marker in string_line), default=string_line).rstrip()
        for string_line in strng.splitlines()
    )