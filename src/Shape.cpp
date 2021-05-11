//
// Created by Данило Бойко on 06.05.2021.
//

#include "Shape.h"

void Shape::moveLeft() const {
    for (int &i : current) {
        i--;
    }
};

void Shape::moveRight() const {
    for (int &i : current) {
        i++;
    }
};

void Shape::moveDown() const {
    for (int &i : current) {
        i += 10;
    }
};

void Shape::rotate() {
    state++;
}

O::O() {
    current = {4, 5, 14, 15};
}

array<int, 4> O::isTurnPossible() {

    return current;
};

I::I() {
    current = {4, 14, 24, 34};
}

array<int, 4> I::isTurnPossible() {
    array<int, 4> r{};
    switch (state % 4) {
        case 0:
            if (current.at(0) % 10 < 2 || current.at(1) % 10 < 1 || current.at(3) % 10 > 8) {
                return
                        current;
            }
            r = {current.at(0) + 18, current.at(1) + 9, current.at(2), current.at(3) - 9};
            break;
        case 1:
            if (current.at(0) % 10 == 9 || current.at(1) < 10 || current.at(2) % 10 == 0 ||
                current.at(3) % 10 < 2) {
                return
                        current;
            }
            r = {current.at(0) - 19, current.at(1) - 10, current.at(2) - 1, current.at(3) + 8};
            break;
        case 2:
            if (current.at(0) % 10 == 0 || current.at(2) % 10 == 9 || current.at(3) % 10 > 7) {
                return
                        current;
            }
            r = {current.at(0) + 9, current.at(1), current.at(2) - 9, current.at(3) - 18};
            break;
        case 3:
            if (current.at(0) % 10 > 7 || current.at(1) == 9 || current.at(3) % 10 == 0) {
                return
                        current;
            }
            r = {current.at(0) - 8, current.at(1) + 1, current.at(2) + 10, current.at(3) + 19};
            break;
        default:
            r = {};
            break;
    }
    return
            r;
};

L::L() {
    current = {5, 15, 14, 13};

}

array<int, 4> L::isTurnPossible() {
    array<int, 4> r{};
    switch (state % 4) {
        case 0:
            if (current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) + 20, current.at(1) + 9, current.at(2), current.at(3) - 9};
            break;
        case 1:
            if (current.at(0) % 10 < 2 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 2, current.at(1) - 11, current.at(2), current.at(3) + 11};
            break;
        case 2:
            if (current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) - 20, current.at(1) - 9, current.at(2), current.at(3) + 9};
            break;
        case 3:
            if (current.at(0) % 10 > 7 || current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 2, current.at(1) + 11, current.at(2), current.at(3) - 11};
            break;
        default:
            r = {};
            break;
    }
    return r;
};

J::J() {

    current = {3, 13, 14, 15};
}

array<int, 4> J::isTurnPossible() {
    array<int, 4> r{};
    switch (state % 4) {
        case 0:
            if (current.at(0) % 10 > 7 || current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 2, current.at(1) - 9, current.at(2), current.at(3) + 9};
            break;
        case 1:
            if (current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 20, current.at(1) + 11, current.at(2), current.at(3) - 11};
            break;
        case 2:
            if (current.at(0) % 10 < 2 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 2, current.at(1) + 9, current.at(2), current.at(3) - 9};
            break;
        case 3:
            if (current.at(0) < 20 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 20, current.at(1) - 11, current.at(2), current.at(3) + 11};
            break;
        default:
            r = {};
            break;
    }
    return r;
};

S::S() {
    current = {5, 4, 14, 13};
}

array<int, 4> S::isTurnPossible() {
    array<int, 4> r{};
    switch (state % 4) {
        case 0:
            if (current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) + 20, current.at(1) + 11, current.at(2), current.at(3) - 9};
            break;
        case 1:
            if (current.at(0) % 10 < 2 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 2, current.at(1) + 9, current.at(2), current.at(3) + 11};
            break;
        case 2:
            if (current.at(0) < 20 || current.at(1) % 10 == 0 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) - 20, current.at(1) - 11, current.at(2), current.at(3) + 9};
            break;
        case 3:
            if (current.at(0) % 10 > 7 || current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 2, current.at(1) - 9, current.at(2), current.at(3) - 11};
            break;
        default:
            r = {};
            break;
    }
    return r;
};

Z::Z() {
    current = {4, 5, 15, 16};
}

array<int, 4> Z::isTurnPossible() {
    array<int, 4> r = {};
    switch (state % 4) {
        case 0:
            if (current.at(0) % 10 > 7 || current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 2, current.at(1) + 11, current.at(2), current.at(3) + 9};
            break;
        case 1:
            if (current.at(1) % 10 == 0 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 20, current.at(1) + 9, current.at(2), current.at(3) - 11};
            break;
        case 2:
            if (current.at(0) % 10 < 2 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 2, current.at(1) - 11, current.at(2), current.at(3) - 9};
            break;
        case 3:
            if (current.at(0) < 20 || current.at(1) % 10 == 9 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 20, current.at(1) - 9, current.at(2), current.at(3) + 11};
            break;
        default:
            r = {};
            break;
    }
    return r;
};

T::T() {
    current = {4, 13, 14, 15};
}

array<int, 4> T::isTurnPossible() {
    array<int, 4> r = {};
    switch (state % 4) {
        case 0:
            if (current.at(0) % 10 == 9 || current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 11, current.at(1) - 9, current.at(2), current.at(3) + 9};
            break;
        case 1:
            if (current.at(0) % 10 == 0 || current.at(1) % 10 == 9 || current.at(3) % 10 == 0) {
                return current;
            }
            r = {current.at(0) + 9, current.at(1) + 11, current.at(2), current.at(3) - 11};
            break;
        case 2:
            if (current.at(0) % 10 == 0 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 11, current.at(1) + 9, current.at(2), current.at(3) - 9};
            break;
        case 3:
            if (current.at(0) % 10 == 9 || current.at(1) % 10 == 0 || current.at(3) % 10 == 9) {
                return current;
            }
            r = {current.at(0) - 9, current.at(1) - 11, current.at(2), current.at(3) + 11};
            break;
        default:
            r = {};
            break;
    }
    return r;
};