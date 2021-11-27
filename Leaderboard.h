/*
    สามารถบันทึกข้อมูลคะแนนลงไฟล์ และโหลดจากไฟล์ได้อย่างง่ายดาย

    ผู้พัฒนา : นาย กร โรจน์รัตนปัญญา
    เขียนเมื่อ : 13-11-2021
*/

#pragma once

#define CLEAR   "\033[0m"
#define ERROR   "\033[1;31m"
#define SUCCESS "\033[1;32m"
#define WARN    "\033[1;33m"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "score2.h"

/**
 * สำหรับเก็บข้อมูลแล้วบันทึกลงไฟล์หรือโหลดจากไฟล์
 *
 * @param string ชื่อไฟล์ที่ต้องการบันทึก / โหลด
 */
class LeaderBoard {
private:

    std::string file_name;
    std::vector <Score2> score_list;

    bool addScoreEntry(Score2 player);

public:

    LeaderBoard(std::string file_name);

    bool loadFile();
    void saveFile();

    bool addEntry(Score2 player);
    bool addEntry(std::string, unsigned long score);
    void removeEntry(unsigned long index);
    Score2 getEntry(unsigned long index);

    void printEntry(unsigned long max_entry = 0);

    std::string getFileName();

    std::vector <Score2> get();
    void set(std::vector <Score2> score_list);
    unsigned long clear();
};