// write a program that takes in a array of students and 
// update the ui with max, min, avg across the class for each subject
// student{
//     name,
//     english,
//     maths,
//     physics
// }
// use the value_array to create bindings.

#include <emscripten/bind.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace emscripten;

struct Student {
  std::string name;
  double english;
  double maths;
  double physics;
};


Student getAverages(const std::vector<Student> &students) {
    Student rslt = { "AVERAGE", 0., 0., 0. };
        
    for(auto &s: students) {
        rslt.english += s.english;
        rslt.maths += s.maths;
        rslt.physics += s.physics;
    }

    rslt.english /= static_cast<double>(students.size());
    rslt.maths /= static_cast<double>(students.size());
    rslt.physics /= static_cast<double>(students.size());

    return rslt;
}

std::vector<Student> newStudentVector() {
    return std::vector<Student>();
}


EMSCRIPTEN_BINDINGS(my_array) {
    value_array<Student>("Student")
    .element(&Student::name)
    .element(&Student::english)
    .element(&Student::maths)
    .element(&Student::physics);    

    register_vector<Student>("vector<Student>");

    function("getAverages", &getAverages);
    function("newStudentVector", &newStudentVector);
}
