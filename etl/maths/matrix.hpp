#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <etl/type_traits/parameter_trait.hpp>

namespace etl {

namespace maths {

/**
  * \brief Static matrix class.
  *
  *
  * M being the height of the matrix
  * N being the width of the matrix
  */
template<std::size_t M, std::size_t N, typename T = double> class Matrix
{
public:
    Matrix(): m_datas()
    {}

    Matrix(typename etl::type_traits::const_parameter_trait<T>::type d): m_datas(d)
    {}

    typename etl::type_traits::const_parameter_trait<T>::type operator()(std::size_t i, std::size_t j) const
    {
        if(i >= M || j >= N)
        {
            std::ostringstream oss;
            oss << i << " >= " << M << " or " << j << " >= " << N;
            std::string str = oss.str();
            throw std::out_of_range(str);
        }
        return m_datas[i*N+j];
    }

    typename etl::type_traits::parameter_trait<T>::type operator()(std::size_t i, std::size_t j)
    {
        return m_datas[i*N+j];
    }

    std::size_t height() const
    {
        return M;
    }

    std::size_t width() const
    {
        return N;
    }

    Matrix<N, M, T> transpose() const
    {
        Matrix<N, M, T> res;
        for(size_t i = 0; i < N; i++)
            for(size_t j = 0; j < M; j++)
                res(i,j) = (*this)(j,i);
        return res;
    }

    void swapLines(std::size_t i, std::size_t j)
    {
        for(std::size_t k = 0; k < N; k++)
            std::swap((*this)(i, k), (*this)(j, k));
    }

    Matrix<M, N, T> operator+(const Matrix<M, N, T>& m) const
    {
        Matrix<M, N, T> res;
        for(size_t i = 0; i < M*N; i++)
            res.m_datas[i] = m_datas[i] + m.m_datas[i];
        return res;
    }

    Matrix<M, N, T> operator-(const Matrix<M, N, T>& m) const
    {
        Matrix<M, N, T> res;
        for(size_t i = 0; i < M*N; i++)
            res.m_datas[i] = m_datas[i] - m.m_datas[i];
        return res;
    }

    Matrix<M, N, T> operator*(typename etl::type_traits::const_parameter_trait<T>::type d) const
    {
        Matrix<M, N, T> res;
        for(size_t i = 0; i < M*N; i++)
            res.m_datas[i] = m_datas[i] * d;
        return res;
    }

    friend Matrix<M, N, T> operator*(double d, const Matrix<M, N, T>& m)
    {
        return m*d;
    }

    template<std::size_t O> Matrix<M, O, T> operator*(const Matrix<N, O, T>& m) const
    {
        Matrix<M, O, T> res;
        for(size_t i = 0; i < M; i++)
            for(size_t j = 0; j < O; j++)
            {
                T sum = 0;
                for(size_t k = 0; k < N; k++)
                    sum += (*this)(i, k) * m(k, j);
                res(i, j) = sum;
            }
        return res;
    }

private:
    std::array<T, M*N> m_datas;
};

template<std::size_t M, typename T = double> Matrix<M, M, T> identity()
{
    Matrix<M, M, T> res(0);
    for(std::size_t i = 0; i < M; i++)
        res(i, i) = 1;
    return res;
}

template<std::size_t M, typename T = double> using Vector = Matrix<M, 1, T>;
template<std::size_t N, typename T = double> using ColumnVector = Matrix<1, N, T>;

}
}

#endif // MATRIX_HPP
