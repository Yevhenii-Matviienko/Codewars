function solution(text, markers) {
  return text.split('\n')
    .map(string_line => markers.reduce((result, marker) =>
      string_line.includes(marker) && string_line.split(marker)[0].length < result.length
      ? string_line.split(marker)[0]
      : result, string_line)
    .trimEnd())
    .join('\n');
}