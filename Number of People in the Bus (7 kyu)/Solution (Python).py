def number(bus_stops):
    return sum(number_get_on - number_get_off for number_get_on, number_get_off in bus_stops)