function isValidWalk(walk) {
  return walk.length === 10 &&
    walk.filter(element => element === 'n').length === walk.filter(element => element === 's').length &&
    walk.filter(element => element === 'w').length === walk.filter(element => element === 'e').length;
}