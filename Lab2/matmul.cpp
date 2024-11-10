#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<double>> random_matrix(int m, int n) {
    std::vector<std::vector<double>> out;
    for (int row = 0; row < m; ++row) {
        std::vector<double> rowVec;
        for (int col = 0; col < n; ++col) {
            rowVec.push_back(static_cast<double>(rand()) / RAND_MAX);
        }
        out.push_back(rowVec);
    }
    return out;
}

std::vector<std::vector<double>> matmul(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    int rows_out = A.size();
    int cols = A[0].size();
    int rows = B.size();
    int cols_out = B[0].size();

    if (!(cols == rows)) {
        throw std::runtime_error("MY ERROR: wrong matrix multiplication");
    }

    std::vector<std::vector<double>> out(rows_out, std::vector<double>(cols_out, 0.0));

    for (int i = 0; i < rows_out; ++i) {
        for (int j = 0; j < cols_out; ++j) {
            for (int k = 0; k < B.size(); ++k) {
                out[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return out;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double time_sum = 0;

    for (int i = 0; i < 10; ++i) {
        clock_t start_time = clock();
        std::vector<std::vector<double>> randa = random_matrix(600, 100);
        std::vector<std::vector<double>> randb = random_matrix(100, 600);
        std::vector<std::vector<double>> mult = matmul(randa, randb);
        clock_t end_time = clock();
        time_sum += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    }

    double average_time_cpp = time_sum / 10;
    std::cout << average_time_cpp << std::endl;
    return 0;
}
