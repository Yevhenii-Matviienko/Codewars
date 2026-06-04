def justify(text, width):
    words, lines, line = text.split(), [], []
    for word in words:
        if len(' '.join(line + [word])) <= width:
            line.append(word)
        else:
            lines.append(line)
            line = [word]
    lines.append(line)
    for i, line in enumerate(lines[: -1]):
        if len(line) == 1:
            lines[i] = line[0]
        else:
            spaces = width - sum(map(len, line))
            gaps = len(line) - 1
            lines[i] = ''.join(
                word + ' ' * (spaces // gaps + (j < spaces % gaps))
                for j, word in enumerate(line[: -1])
            ) + line[-1]
    lines[-1] = ' '.join(lines[-1])
    return '\n'.join(lines)