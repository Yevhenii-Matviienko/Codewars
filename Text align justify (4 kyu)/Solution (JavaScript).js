function justify(text, width) {
  const words = text.split(/\s+/);
  const lines = [];
  let line = [];
  for (const word of words) {
    if ([line, word].join(' ').length <= width) {
      line.push(word);
    } 
    else {
      lines.push(line);
      line = [word];
    }
  }
  if (line.length) {
    lines.push(line);
  }
  for (let i = 0; i < lines.length - 1; i++) {
    const line = lines[i];
    if (line.length === 1) {
      lines[i] = line[0];
    } 
    else {
      const spaces = width - line.reduce((sum, word) => sum + word.length, 0);
      const gaps = line.length - 1;
      lines[i] = line.slice(0, -1)
        .map((word, j) => {
          return word + ' '.repeat(Math.floor(spaces / gaps) + (j < spaces % gaps ? 1 : 0));
        })
        .join('') + line[line.length - 1];
    }
  }
  if (lines.length) {
    lines[lines.length - 1] = lines[lines.length - 1].join(' ');
  }
  return lines.join('\n');
}