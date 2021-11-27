#include "Score2.h"

Score2::Score2(std::string name, unsigned long score) {

    this->name = name;
    this->score = score;
}

/**
 * เซ็ตชื่อ
 *
 * @param string
 */
void Score2::setName(std::string name) {

    this->name = name;
}

/**
 * ดึงชื่อ
 *
 * @return string
 */
std::string Score2::getName() {

    return this->name;
}

/**
 * เซ็ตคะแนน
 *
 * @param int
 */
void Score2::setScore(unsigned long score) {

    this->score = score;
}

/**
 * ดึงคะแนน
 *
 * @return int
 */
unsigned long Score2::getScore() {

    return this->score;
}