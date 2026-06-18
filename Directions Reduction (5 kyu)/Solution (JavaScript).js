function dirReduc(arr) {
  const opposites_directions = {
    NORTH: "SOUTH",
    SOUTH: "NORTH",
    EAST: "WEST",
    WEST: "EAST"
  };
  const result = [];
  for (const direction of arr) {
    if (result.length && opposites_directions[direction] === result[result.length - 1]) {
      result.pop();
    } else {
      result.push(direction);
    }
  }
  return result;
}