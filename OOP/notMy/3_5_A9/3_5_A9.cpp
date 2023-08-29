#include <iostream>
#include <vector>

using namespace std;

bool ScalarMultiply(const vector<vector<int>> &matrix, const int &iBase, const int &iCheck, const int &order) {
    int result = 0;
    for(auto j = 0; j < order; j++) {
        result += matrix[iBase][j] * matrix[iCheck][j];
    }

    return result == 0 || (iBase == iCheck && result == 1);
}

bool CheckForOrthonormality(const vector<vector<int>> &matrix, const int &order) {
    for(auto iBase = 0; iBase < order; iBase++) {
        for(auto iCheck = 0; iCheck < order; iCheck++) {
            if(!ScalarMultiply(matrix, iBase, iCheck, order))
                return false;
        }
    }

    return true;
}

void FillByKeyboard(vector<vector<int>> &matrix, const int &order) {
    cout << "Enter the numbers: " << endl;
    for(auto i = 0; i < order; i++) {
        for(auto j = 0; j < order; j++) {
            int number;
            cin >> number;
            matrix[i][j] = number;
        }
    }
}

void FillRandomly(vector<vector<int>> &matrix, const int &order) {
    for(auto i = 0; i < order; i++) {
        for(auto j = 0; j < order; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void PrintTheMatrix(const vector<vector<int>> &matrix, const int &order) {
    for(auto i = 0; i < order; i++) {
        for(auto j = 0; j < order; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    srand(time(nullptr));

    int order;
    cout << "Enter the order of the matrix: " << endl;
    cin >> order;

    vector<vector<int>> matrix(order, vector<int>(order));

    cout << "Fill the matrix:\n"
        << "1 - By keyboard\n"
        << "2 - By random" << endl;

    int choice;
    cin >> choice;

    choice == 1 ? FillByKeyboard(matrix, order) : FillRandomly(matrix, order);

    PrintTheMatrix(matrix, order);

    cout << "Result: ";
    (CheckForOrthonormality(matrix, order) ? cout << "true" << endl : cout << "false") << endl;

    return 0;
}