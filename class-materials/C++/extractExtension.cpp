# include <iostream>

using namespace std;

int main(){
    cout << "Input file name:" << endl;
    string file;
    cin >> file;
    int print = 0;
    for (int i = 0; i < file.size(); i++ ){
        if (file[i] == '.'){
            print = 1;
            continue;
        }
        if (print){
            cout << file[i];
        }
    }
    return 0;
}