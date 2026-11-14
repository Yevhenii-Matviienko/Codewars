def calculate_age(year_of_birth, current_year):
    years_difference = current_year - year_of_birth
    year_plural_suffix = "s" if abs(years_difference) != 1 else ""
    if years_difference > 0:
        return f"You are {years_difference} year{year_plural_suffix} old."
    if years_difference < 0:
        return f"You will be born in {-years_difference} year{year_plural_suffix}."
    return "You were born this very year!"