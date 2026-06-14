function pyramidHeight(n) {
  let height = 0;
  while (n >= (height + 1) ** 2) {
    height++;
    n -= height ** 2;
  }
  return height;
}