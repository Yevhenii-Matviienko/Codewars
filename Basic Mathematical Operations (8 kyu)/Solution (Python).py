def basic_op(operator, value1, value2):
    operators = {
        "+": lambda value_1, value_2: value_1 + value_2,
        "-": lambda value_1, value_2: value_1 - value_2,
        "*": lambda value_1, value_2: value_1 * value_2,
        "/": lambda value_1, value_2: value_1 / value_2,
    }
    return operators[operator](value1, value2)