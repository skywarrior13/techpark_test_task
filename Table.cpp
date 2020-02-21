//
// Created by Данила Наконечный on 22.02.2020.
//

#include "Table.h"

Table::Table() {
    std::cout << "Вводите строки с полями, разделенными знаками табуляции" << std::endl << std::endl;

    std::string temp;

    for (int i = 0; std::getline(std::cin, temp) && !temp.empty(); i++) {
        m_table.resize(i + 1);
        std::istringstream iss(temp);
        while (std::getline(iss, temp, '\t'))
            m_table[i].push_back(temp);
    }
}

void Table::write_instructions() {
    std::cout << "Введите команду, индекс строки и индекс поля в виде: <command> <str_i> <field_i> [<new_field>]"
              << std::endl;
    std::cout << "Виды команд: i - вставка поля по индекс поля, e - редактировать поле по инедксу поля,";
    std::cout << "d - удаление поля по индексу, q - выход из программы" << std::endl;
    std::cout << "<new_field> - это новое значение поля, указывается только при командах i или e" << std::endl;
}

void Table::write_table() {
    std::cout << "Текущий список строк: " << std::endl;

    int i = 0;
    for (auto &str : m_table) {
        std::cout << i++ << ") ";
        for (auto &field : str)
            std::cout << "\"" << field << "\" ";
        std::cout << std::endl;
    }
}

bool Table::parse_command() {
    int str_i, field_i;
    char command;
    std::string new_field;

    std::cin.exceptions(std::ios_base::failbit);
    try {
        std::cin >> command;
        if (command == 'q')
            return false;
        std::cin >> str_i >> field_i;

        if ((str_i < 0) || (str_i >= m_table.size()) || (field_i < 0) || (field_i) >= m_table[str_i].size()) {
            std::cout << "Индекс вне границ массива. Попробуйте еще раз" << std::endl;
            return true;
        }
    }
    catch (std::ios_base::failure &f) {  // если мы ввели неверную команду
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Вы ввели неверные данные. Попробуйте еще раз" << std::endl;
        return true;    // программа продолжает работать
    }

    switch (command) {
        case 'i':   // вставка нового поля
            std::cin >> new_field;
            m_table[str_i].insert(m_table[str_i].begin() + field_i, new_field);
            break;
        case 'e':   // редактирование поля
            std::cin >> new_field;
            m_table[str_i][field_i] = new_field;
            break;
        case 'd':   // удаление поля
            m_table[str_i].erase(m_table[str_i].begin() + field_i);
            break;
        default:
            break;
    }

    return true;
}

bool Table::edit() {
    write_table();
    write_instructions();
    return parse_command();
}
