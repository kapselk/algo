// Matrix exponentation

template<typename T, int M>
struct Matrix {
    array<array<T, M>, M> val;
    Matrix() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) val[i][j] = 0;
        }
    }
    Matrix operator*(const Matrix &rhs) const {
        Matrix ret;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    ret.val[i][j] += val[i][k] * rhs.val[k][j];
                }
            }
        }
        return ret;
    }
};