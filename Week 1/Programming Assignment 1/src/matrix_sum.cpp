#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
private:
	int num_col;
	int num_row;
	vector<vector<int>> elements;
public:
	Matrix() {
		num_col = 0;
		num_row = 0;
	}
	Matrix(int rows, int cols) {
		Reset(rows, cols);
	}
	void Reset(int new_rows, int new_cols) {
		if(new_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (new_cols < 0) {
			throw out_of_range("num_cols must be >= 0");
		}
		if(new_rows == 0 || new_cols == 0) {
			new_rows = new_cols = 0;
		}
		num_col = new_cols;
		num_row = new_rows;

		elements.assign(new_rows, vector<int>(new_cols));
	}

	int At(const int& row, const int& col) const {
		return elements.at(row).at(col);
	}

	int& At(const int& row, const int& col) {
		return elements.at(row).at(col);
	}

	int GetNumRows() const {
		return num_row;
	}

	int GetNumColumns() const {
		return num_col;
	}


};

Matrix operator + (const Matrix& one, const Matrix& two) {
	if(one.GetNumRows() != two.GetNumRows()){
		throw invalid_argument("Mismatched number of rows");
	}
	if (one.GetNumColumns() != two.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}
	int r = one.GetNumRows();
	int n = one.GetNumColumns();
	Matrix m = Matrix(r, n);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < n; j++) {
			m.At(i, j) = one.At(i, j) + two.At(i, j);
		}
	}
	return m;

}

istream& operator >> (istream& stream, Matrix& m) {
	int r, n;
	stream >> r >> n;

	m.Reset(r, n);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < n; j++) {
			stream >> m.At(i, j);
		}
	}
	return stream;
}

ostream& operator << (ostream& stream, const Matrix& m) {
	int r = m.GetNumRows();
	int n = m.GetNumColumns();

	stream << r << " " << n << endl;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < n; j++) {
			if(j > 0) {
				stream << " ";
			}
			stream << m.At(i, j);
		}
		stream << endl;
	}
	return stream;
}

bool operator == (const Matrix& one, const Matrix& two) {
	if(one.GetNumRows() != two.GetNumRows() || one.GetNumColumns() != two.GetNumColumns()) {
		return false;
	}
	int n = one.GetNumColumns();
	int r = one.GetNumRows();

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < n; j++) {
			if(one.At(i, j) != two.At(i, j)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
