Array.prototype.sameStructureAs = function(other) {
  const arrays_with_same_structure = (original, other) => {
    return (isArray(original) === isArray(other) &&
      (!isArray(original) ||
      original.length === other.length &&
      original.every((sub_original, index) =>
        arrays_with_same_structure(sub_original, other[index]))
      )
    );
  };
  return arrays_with_same_structure(this, other);
};