fun incrementString(str: String): String {
    var index = str.length - 1
    while (index >= 0 && str[index] in '0'..'9') {
        index--
    }
    if (index == str.length - 1) {
        return str + "1"
    }
    val text = str.substring(0, index + 1)
    val number = StringBuilder(str.substring(index + 1))
    var carry = 1
    for (digit_index in number.length - 1 downTo 0) {
        if (number[digit_index] == '9') {
            number[digit_index] = '0'
        } 
        else {
            number[digit_index]++
            carry = 0
            break
        }
    }
    if (carry == 1) {
        number.insert(0, '1')
    }
    return text + number
}