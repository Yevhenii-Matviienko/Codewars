def to_csv_text(array):
    return "\n".join(",".join(map(str, list)) for list in array)