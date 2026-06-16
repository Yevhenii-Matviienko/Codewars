function countSmileys(arr) {
  return arr.filter(smiley => /^[:;][-~]?[)D]$/.test(smiley)).length;
}