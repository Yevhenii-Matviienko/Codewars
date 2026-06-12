var uniqueInOrder = function(iterable) {
  return [...iterable].filter((element, index, array) => element !== array[index - 1]);
}