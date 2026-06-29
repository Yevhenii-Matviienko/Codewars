unsigned int pyramidHeight(unsigned int n) {
    unsigned int height = 0;
    while (n >= (height + 1) * (height + 1)) {
        height++;
        n -= height * height;
    }
    return height;
}