namespace utils {
    bool compare_floats(float first, float second) {
        return std::abs(first - second) <= 1e-6;
    }
}

