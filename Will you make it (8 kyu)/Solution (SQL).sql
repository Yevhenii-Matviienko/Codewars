SELECT distance_to_pump, mpg, fuel_left, mpg * fuel_left >= distance_to_pump AS res
FROM zerofuel;