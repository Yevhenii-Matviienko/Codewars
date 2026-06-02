def same_structure_as(original, other):
    return (
        isinstance(original, list) == isinstance(other, list)
        and (
            not isinstance(original, list)
            or len(original) == len(other)
            and all(same_structure_as(sublist_original, sublist_other) 
                for sublist_original, sublist_other in zip(original, other))
        )
    )