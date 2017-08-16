//
// Created by lioth on 8/7/2017.
//

#ifndef GAMEENGINE_MATIX_H
#define GAMEENGINE_MATIX_H

#include <exception>

namespace privy{

template <class TYPE, int I, int J>
class Matrix {
public:
//  using MatrixType = TYPE[I][J];
  using MatrixType = std::array<std::array<TYPE, I>, J>;

  Matrix(TYPE value = 0):matrix_{value} { }
  Matrix(MatrixType init): matrix_(init) {};
  Matrix(MatrixType &list):matrix_(list) { }
  Matrix(MatrixType &&list):matrix_(std::move(list)) { }

  TYPE* begin() const {
    return &matrix_;
  }

  TYPE* end() const {
    return &matrix_ + (I * J);
  }

  TYPE& operator[](int i){
    return *matrix_[i];
  }

  const TYPE& operator[](int i) const{
    return *matrix_[i];
  }

  Matrix<TYPE, 1, J> operator*(const Matrix<Matrix, J, 1> &b) const {
    Matrix<TYPE, 1, J> v;

    for(int i = 0; i < I; ++i) {
      for(int j = 0; j < J; ++j) {
        v[0][j] = b[j][0] * matrix_[i][j];
      }
    }

    return v;
  }

  Matrix<TYPE, J, I> transpose() const {
    Matrix<TYPE, J, I> m;
    for(int i = 0; i < I; ++i) {
      for(int j = 0; j < J; ++j) {
        m[j][i] = matrix_[i][j];
      }
    }

    return m;
  };

  Matrix operator+(const Matrix &b) const {
    Matrix a = *this;
    for(auto a_it = a.begin(), b_it = b.begin() ; a_it < a.end(); ++a_it, ++b_it) {
      *a_it = *b_it;
    }

    return a;
  }

  Matrix operator+(TYPE i) const {
    Matrix m = *this;
    for(auto &x : m.matrix_)
      for(auto &y : x)
        y += i;

    return m;
  }

//protected:
  MatrixType matrix_;
};

template<class TYPE, int SIZE = 2>
class Vector : public Matrix<TYPE, SIZE, 1>{
public:
  using VectorType = std::array<TYPE, SIZE>;
  using MatrixType = std::array<std::array<TYPE, SIZE>, 1>;

  Vector(TYPE i = 0): Matrix<TYPE, SIZE, 1>::Matrix(i) {}
//  Vector(VectorType &init): Matrix<TYPE, SIZE, 1>::Matrix(reinterpret_cast<MatrixType&>(init)) {}
//  Vector(VectorType init): Matrix<TYPE, SIZE, 1>::Matrix({init}) {}
  Vector(VectorType &init): Matrix<TYPE, SIZE, 1>::Matrix({init}) {}
  Vector(VectorType &&init): Matrix<TYPE, SIZE, 1>::Matrix({init}) {}

  TYPE& x(){
    return this->operator[](0);
  }

  TYPE& y(){
    return this->operator[](1);
  }

  const TYPE& x() const{
    return this->operator[](0);
  }

  const TYPE& y() const{
    return this->operator[](1);
  }
};

using dVector2 = Vector<double>;
using iVector2 = Vector<int>;

template <class TYPE>
class Matrix2x2 : public Matrix<TYPE, 2, 2> {
public:
  operator SDL_Rect*() {
    return reinterpret_cast<SDL_Rect*>(&this->matrix_);
  }
};

}

#endif //GAMEENGINE_MATIX_H
