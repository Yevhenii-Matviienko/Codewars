function solution(list) {
  const result = [];
  let index = 0;
  while (index < list.length) {
    const start = list[index];
    while (index + 1 < list.length && list[index + 1] === list[index] + 1) {
      index++;
    }
    const end = list[index];
    if (end - start >= 2) {
      result.push(`${start}-${end}`);
    } else if (end - start === 1) {
      result.push(String(start));
      result.push(String(end));
    } else {
      result.push(String(start));
    }
    index++;
  }
  return result.join(',');
}