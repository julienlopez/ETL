#ifndef KALMANFILTER_HPP
#define KALMANFILTER_HPP

#include <etl/maths/matrixhelper.hpp>

namespace etl {

namespace maths {

namespace kalman_filter {

template<std::size_t S, std::size_t C, std::size_t M> class KalmanFilter
{
public:
    void predict(const Matrix<C, 1>& control){
        m_state = m_transitionModel*m_state + m_controlModel*control;
        m_estimateCovariance = m_transitionModel*m_estimateCovariance*m_transitionModel.transpose() + m_processCovariance;
    }

    void update(const Matrix<M, 1>& measurement)
    {
        Matrix<M, 1> measurementResidual = measurement - m_observationModel * m_state; //Y
        Matrix<M, M> residualCovariance = m_observationModel*m_estimateCovariance*m_observationModel.transpose() + m_measurementNoiseCovariance; //S
        Matrix<S, M> gain = m_estimateCovariance*m_observationModel.transpose()*MatrixHelper::invert(residualCovariance); //K
        m_state = m_state + gain*measurementResidual;
        m_estimateCovariance = (identity<S>() - gain*m_observationModel)*m_estimateCovariance;
    }

    const Matrix<S, 1>& state() const
    {
        return m_state;
    }

protected:
    void setTransitionModel(const Matrix<S, S>& m)
    {
        m_transitionModel = m; //F
    }

    void setControlModel(const Matrix<S, C>& m)
    {
        m_controlModel = m; //B
    }

    void setEstimateCovariance(const Matrix<S, S>& m)
    {
        m_estimateCovariance = m; //P
    }

    void setProcessCovariance(const Matrix<S, S>& m)
    {
        m_processCovariance = m; //Q
    }

    void setObservationModel(const Matrix<M, S>& m)
    {
        m_observationModel = m; //H
    }

    void setMeasurementNoiseCovariance(const Matrix<M, M>& m)
    {
        m_measurementNoiseCovariance = m; //R
    }

private:
    Matrix<S, 1> m_state; //X
    Matrix<S, S> m_transitionModel; //F
    Matrix<S, C> m_controlModel; //B
    Matrix<S, S> m_estimateCovariance; //P
    Matrix<S, S> m_processCovariance; //Q
    Matrix<M, S> m_observationModel; //H
    Matrix<M, M> m_measurementNoiseCovariance; //R
};

}
}
}

#endif // KALMANFILTER_HPP
