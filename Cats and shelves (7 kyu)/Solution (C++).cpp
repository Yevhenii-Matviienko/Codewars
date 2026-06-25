unsigned int Cats(unsigned int start, unsigned int finish) {
    unsigned int shelves_difference = finish - start;
    return shelves_difference / 3 + shelves_difference % 3;
}