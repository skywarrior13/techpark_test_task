//
// Created by Данила Наконечный on 22.02.2020.
//

#ifndef TASK_21_02_2020_TABLE_H
#define TASK_21_02_2020_TABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Table {
 private:
    std::vector<std::vector<std::string>> m_table;

    static void write_instructions();

    void write_table();

    bool parse_command();   // возвращает, надо ли продолжать выполнение программы

 public:
    Table();

    bool edit();
};


#endif //TASK_21_02_2020_TABLE_H
