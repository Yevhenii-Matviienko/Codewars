def bmi(weight, height):
    bmi_value = weight / height ** 2
    if bmi_value <= 18.5:
        return "Underweight"
    if bmi_value <= 25.0:
        return "Normal"
    if bmi_value <= 30.0:
        return "Overweight"
    return "Obese"