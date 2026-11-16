def replace_exclamation(st):
    return st.translate(str.maketrans("aeiouAEIOU", "!" * 10))