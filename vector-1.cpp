#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book{
    string name;
    int pages;
    int year;
public:
    Book(string v1,int v2,int v3) : name(v1), pages(v2), year(v3) {}

};
template <typename T>
void show(const vector<T>& vec){
    cout<<"the element of vector is: ";
    for(const auto& v : vec){
        cout<<v<<", ";
    }
    cout<<endl<<endl;
}
int main(){
    vector <int> vec1;
    vector <int> vec2(3);
    cout<<"vec2: ";
    show(vec2);
    vector <int> vec3(3,5);
    cout<<"vec3: ";
    show(vec3);
    vector <int> vec4(vec3);
    cout<<"vec4: ";
    show(vec4);
    vec2.emplace_back(19);
    cout<<"vec2 after adding: ";
    show(vec2);
    vec2.push_back(32);
    vec2.push_back(311);
    vec2.push_back(322);
    vec2[2] = 22;
    cout<<"vec2 the third elemenet change to 22: ";
    show(vec2);
    vec2.insert(vec2.begin()+3,12);
    cout<<"vec2 the forth element change to 12: ";
    show(vec2);
    vec2.erase(vec2.end()-2);
    cout<<"vec2 the element one to the last removed";
    show(vec2);
    vec2.pop_back();
    cout<<"the last element removed";
    show(vec2);
    cout<<"size of vec2 "<<vec2.size()<<endl;
    cout<<"the capacity of vec2: "<<vec2.capacity()<<endl;
    vec2.resize(12);
    cout<<"the size of vec2 after changing "<<vec2.size()<<endl;
    vec2.reserve(50);
    cout<<"the capacity after changing it to 50: "<<vec2.capacity()<<endl;
    vec2.shrink_to_fit();
    cout<<"vec2 size after shrink it "<<vec2.capacity()<<endl;
    cout<<"if the vec2 is empty:(0=false,1=true) "<<vec2.empty()<<endl;
    vec2.swap(vec1);
    cout<<"we swap vec1 and 2 now: vec1: ";
    show(vec1);

    int num = 0;
    for (auto i = vec1.begin(); i != vec1.end(); ) {
        if (*i == 0) {
            i = vec1.erase(i); 
        } else {
            ++i; 
        }
    }
    cout<<"vec1 after removing all zero elements: ";
    show(vec1);




    return 0 ;

}