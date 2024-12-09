#include <iostream> // для cout, endl
#include <vector> // для vector
#include <tuple> // для tuple и tie
#include <string> // для string
#include <iterator> // для явного указания типа при использовании итераторов
#include <algorithm> // Для большинства STL алгоритмов
#include <iomanip> // для setw, left, right
#include <numeric> // для accumulate
using namespace std;

typedef tuple<string, string, bool, size_t, pair<double, size_t» student_data;

void printGroup(const vector<student_data>& group) {
    for (const auto& [name, surname, gender, zachete_id, score] : group) {
        auto [mean, number] = score;
        cout « setw(10) « left « name « ' ' 
             « setw(10) « left « surname « ' '
             « gender « ' ' « zachete_id « ' '
             « mean « ' ' « number « endl;
    }
}

int main() {
    vector<student_data> group = {
        { "Tikhon", "Kozich",     1, 8434562, {4.92, 12} },
        { "Valentine", "Bratkova", 0, 6349523, {4.81, 13} },
        { "Dmitryi", "Gantelyv",  1, 2456246, {4.55, 8}  },
        { "Gleb", "Koshkarov", 1, 2837491, {4.72, 11} },
        { "Danil", "Swollow" , 1, 4567367, {4.92, 13} },
        { "Irina", "Borrov" , 0, 7836411, {3.97, 10} },
        { "Julia", "Ivanova", 0 , 4563367, {4.8, 13} },
        { "Elena", "Kostromskih", 0, 1989929, {4.0, 10} },
        { "Ilya", "Malyshko", 1, 9873674, {5.0, 10} },
        { "Elina", "Starostovskya", 0, 5485555, {4.9, 12} }
    };

    printGroup(group);
    
    // Вычисление общего среднего балла
    double totalScore = accumulate(group.begin(), group.end(), 0.0,
        [](double sum, const student_data& student) {
            return sum + get<4>(student).first; // добавляем средний балл
        });

    double averageScore = totalScore / group.size();
    
    // Вычисление средней длины имени и фамилии
    double totalNameLength = accumulate(group.begin(), group.end(), 0.0,
        [](double sum, const student_data& student) {
            return sum + get<0>(student).length(); // добавляем длину имени
        });

    double totalSurnameLength = accumulate(group.begin(), group.end(), 0.0,
        [](double sum, const student_data& student) {
            return sum + get<1>(student).length(); // добавляем длину фамилии
        });

    double averageNameLength = totalNameLength / group.size();
    double averageSurnameLength = totalSurnameLength / group.size();

    cout « "Общий средний балл: " « averageScore « endl;
    cout « "Средняя длина имени: " « averageNameLength « endl;
    cout « "Средняя длина фамилии: " « averageSurnameLength « endl;

    return 0;
}
